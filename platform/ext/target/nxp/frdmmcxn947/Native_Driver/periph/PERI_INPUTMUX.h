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
**         CMSIS Peripheral Access Layer for INPUTMUX
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
 * @file PERI_INPUTMUX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(PERI_INPUTMUX_H_)
#define PERI_INPUTMUX_H_                         /**< Symbol preventing repeated inclusion */

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
   -- INPUTMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Peripheral_Access_Layer INPUTMUX Peripheral Access Layer
 * @{
 */

/** INPUTMUX - Size of Registers Arrays */
#define INPUTMUX_INPUTMUX_SCT0_COUNT              8u
#define INPUTMUX_INPUTMUX_SMARTDMA_COUNT          8u
#define INPUTMUX_INPUTMUX_GPIO_INT_COUNT          8u
#define INPUTMUX_ADC0_TRIGM_COUNT                 4u
#define INPUTMUX_ADC1_TRIGN_COUNT                 4u
#define INPUTMUX_QDCN_COUNT                       2u
#define INPUTMUX_FLEXPWM_SM_EXTSYNC_COUNT         4u
#define INPUTMUX_FLEXPWM_SM_EXT_COUNT             4u
#define INPUTMUX_FLEXPWM_FAULT_COUNT              4u
#define INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_COUNT  4u
#define INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_COUNT     4u
#define INPUTMUX_FLEXPWM1_FAULT_COUNT             4u
#define INPUTMUX_EVTG_TRIGN_COUNT                 16u
#define INPUTMUX_EXT_TRIGN_COUNT                  8u
#define INPUTMUX_SINC_FILTER_CHN_COUNT            5u
#define INPUTMUX_OPAMPN_TRIG_COUNT                3u
#define INPUTMUX_FLEXIO_TRIGN_COUNT               8u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCT0_INMUX[INPUTMUX_INPUTMUX_SCT0_COUNT]; /**< Inputmux Register for SCT0 Input, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CTIMER0CAP0;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x20 */
  __IO uint32_t CTIMER0CAP1;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x24 */
  __IO uint32_t CTIMER0CAP2;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x28 */
  __IO uint32_t CTIMER0CAP3;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x2C */
  __IO uint32_t TIMER0TRIG;                        /**< Trigger Register for CTIMER, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CTIMER1CAP0;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x40 */
  __IO uint32_t CTIMER1CAP1;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x44 */
  __IO uint32_t CTIMER1CAP2;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x48 */
  __IO uint32_t CTIMER1CAP3;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x4C */
  __IO uint32_t TIMER1TRIG;                        /**< Trigger Register for CTIMER, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CTIMER2CAP0;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x60 */
  __IO uint32_t CTIMER2CAP1;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x64 */
  __IO uint32_t CTIMER2CAP2;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x68 */
  __IO uint32_t CTIMER2CAP3;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x6C */
  __IO uint32_t TIMER2TRIG;                        /**< Trigger Register for CTIMER, offset: 0x70 */
       uint8_t RESERVED_2[44];
  __IO uint32_t SMARTDMAARCHB_INMUX[INPUTMUX_INPUTMUX_SMARTDMA_COUNT]; /**< Inputmux Register for SMARTDMA Arch B Inputs, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t PINTSEL[INPUTMUX_INPUTMUX_GPIO_INT_COUNT]; /**< Pin Interrupt Select, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_3[160];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for Frequency Measurement Reference Clock, offset: 0x180 */
  __IO uint32_t FREQMEAS_TAR;                      /**< Selection for Frequency Measurement Target Clock, offset: 0x184 */
       uint8_t RESERVED_4[24];
  __IO uint32_t CTIMER3CAP0;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1A0 */
  __IO uint32_t CTIMER3CAP1;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1A4 */
  __IO uint32_t CTIMER3CAP2;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1A8 */
  __IO uint32_t CTIMER3CAP3;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1AC */
  __IO uint32_t TIMER3TRIG;                        /**< Trigger Register for CTIMER, offset: 0x1B0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t CTIMER4CAP0;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1C0 */
  __IO uint32_t CTIMER4CAP1;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1C4 */
  __IO uint32_t CTIMER4CAP2;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1C8 */
  __IO uint32_t CTIMER4CAP3;                       /**< Capture Select Register for CTIMER Inputs, offset: 0x1CC */
  __IO uint32_t TIMER4TRIG;                        /**< Trigger Register for CTIMER, offset: 0x1D0 */
       uint8_t RESERVED_6[140];
  __IO uint32_t CMP0_TRIG;                         /**< CMP0 Input Connections, offset: 0x260 */
       uint8_t RESERVED_7[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_ADC0_TRIGM_COUNT]; /**< ADC Trigger Input Connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_8[48];
  __IO uint32_t ADC1_TRIG[INPUTMUX_ADC1_TRIGN_COUNT]; /**< ADC Trigger Input Connections, array offset: 0x2C0, array step: 0x4 */
       uint8_t RESERVED_9[48];
  __IO uint32_t DAC0_TRIG;                         /**< DAC0 Trigger Inputs, offset: 0x300 */
       uint8_t RESERVED_10[28];
  __IO uint32_t DAC1_TRIG;                         /**< DAC1 Trigger Inputs, offset: 0x320 */
       uint8_t RESERVED_11[28];
  __IO uint32_t DAC2_TRIG;                         /**< DAC2 Trigger Inputs, offset: 0x340 */
       uint8_t RESERVED_12[28];
  struct {                                         /* offset: 0x360, array step: 0x20 */
    __IO uint32_t QDC_TRIG;                          /**< QDC0 Trigger Input Connections..QDC1 Trigger Input Connections, array offset: 0x360, array step: 0x20 */
    __IO uint32_t QDC_HOME;                          /**< QDC0 Input Connections..QDC1 Input Connections, array offset: 0x364, array step: 0x20 */
    __IO uint32_t QDC_INDEX;                         /**< QDC0 Input Connections..QDC1 Input Connections, array offset: 0x368, array step: 0x20 */
    __IO uint32_t QDC_PHASEB;                        /**< QDC0 Input Connections..QDC1 Input Connections, array offset: 0x36C, array step: 0x20 */
    __IO uint32_t QDC_PHASEA;                        /**< QDC0 Input Connections..QDC1 Input Connections, array offset: 0x370, array step: 0x20 */
         uint8_t RESERVED_0[12];
  } QDCN[INPUTMUX_QDCN_COUNT];
  __IO uint32_t FLEXPWM0_SM_EXTSYNC[INPUTMUX_FLEXPWM_SM_EXTSYNC_COUNT]; /**< PWM0 External Synchronization, array offset: 0x3A0, array step: 0x4 */
  __IO uint32_t FLEXPWM0_SM_EXTA[INPUTMUX_FLEXPWM_SM_EXT_COUNT]; /**< PWM0 Input Trigger Connections, array offset: 0x3B0, array step: 0x4 */
  __IO uint32_t FLEXPWM0_EXTFORCE;                 /**< PWM0 External Force Trigger Connections, offset: 0x3C0 */
  __IO uint32_t FLEXPWM0_FAULT[INPUTMUX_FLEXPWM_FAULT_COUNT]; /**< PWM0 Fault Input Trigger Connections, array offset: 0x3C4, array step: 0x4 */
       uint8_t RESERVED_13[12];
  __IO uint32_t FLEXPWM1_SM_EXTSYNC[INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_COUNT]; /**< PWM1 External Synchronization, array offset: 0x3E0, array step: 0x4 */
  __IO uint32_t FLEXPWM1_SM_EXTA[INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_COUNT]; /**< PWM1 Input EXTA Connections, array offset: 0x3F0, array step: 0x4 */
  __IO uint32_t FLEXPWM1_EXTFORCE;                 /**< PWM1 External Force Trigger Connections, offset: 0x400 */
  __IO uint32_t FLEXPWM1_FAULT[INPUTMUX_FLEXPWM1_FAULT_COUNT]; /**< PWM1 Fault Input Trigger Connections, array offset: 0x404, array step: 0x4 */
       uint8_t RESERVED_14[12];
  __IO uint32_t PWM0_EXT_CLK;                      /**< PWM0 External Clock Trigger, offset: 0x420 */
  __IO uint32_t PWM1_EXT_CLK;                      /**< PWM1 External Clock Trigger, offset: 0x424 */
       uint8_t RESERVED_15[24];
  __IO uint32_t EVTG_TRIG[INPUTMUX_EVTG_TRIGN_COUNT]; /**< EVTG Trigger Input Connections, array offset: 0x440, array step: 0x4 */
  __IO uint32_t USBFS_TRIG;                        /**< USB-FS Trigger Input Connections, offset: 0x480 */
       uint8_t RESERVED_16[28];
  __IO uint32_t TSI_TRIG;                          /**< TSI Trigger Input Connections, offset: 0x4A0 */
       uint8_t RESERVED_17[28];
  __IO uint32_t EXT_TRIG[INPUTMUX_EXT_TRIGN_COUNT]; /**< EXT Trigger Connections, array offset: 0x4C0, array step: 0x4 */
  __IO uint32_t CMP1_TRIG;                         /**< CMP1 Input Connections, offset: 0x4E0 */
       uint8_t RESERVED_18[28];
  __IO uint32_t CMP2_TRIG;                         /**< CMP2 Input Connections, offset: 0x500 */
       uint8_t RESERVED_19[28];
  __IO uint32_t SINC_FILTER_CH[INPUTMUX_SINC_FILTER_CHN_COUNT]; /**< SINC Filter Channel Trigger Input Connections, array offset: 0x520, array step: 0x4 */
       uint8_t RESERVED_20[76];
  __IO uint32_t OPAMP_TRIG[INPUTMUX_OPAMPN_TRIG_COUNT]; /**< OPAMP Trigger Input Connections, array offset: 0x580, array step: 0x4 */
       uint8_t RESERVED_21[20];
  __IO uint32_t FLEXCOMM0_TRIG;                    /**< LP_FLEXCOMM0 Trigger Input Connections, offset: 0x5A0 */
       uint8_t RESERVED_22[28];
  __IO uint32_t FLEXCOMM1_TRIG;                    /**< LP_FLEXCOMM1 Trigger Input Connections, offset: 0x5C0 */
       uint8_t RESERVED_23[28];
  __IO uint32_t FLEXCOMM2_TRIG;                    /**< LP_FLEXCOMM2 Trigger Input Connections, offset: 0x5E0 */
       uint8_t RESERVED_24[28];
  __IO uint32_t FLEXCOMM3_TRIG;                    /**< LP_FLEXCOMM3 Trigger Input Connections, offset: 0x600 */
       uint8_t RESERVED_25[28];
  __IO uint32_t FLEXCOMM4_TRIG;                    /**< LP_FLEXCOMM4 Trigger Input Connections, offset: 0x620 */
       uint8_t RESERVED_26[28];
  __IO uint32_t FLEXCOMM5_TRIG;                    /**< LP_FLEXCOMM5 Trigger Input Connections, offset: 0x640 */
       uint8_t RESERVED_27[28];
  __IO uint32_t FLEXCOMM6_TRIG;                    /**< LP_FLEXCOMM6 Trigger Input Connections, offset: 0x660 */
       uint8_t RESERVED_28[28];
  __IO uint32_t FLEXCOMM7_TRIG;                    /**< LP_FLEXCOMM7 Trigger Input Connections, offset: 0x680 */
       uint8_t RESERVED_29[28];
  __IO uint32_t FLEXCOMM8_TRIG;                    /**< LP_FLEXCOMM8 Trigger Input Connections, offset: 0x6A0 */
       uint8_t RESERVED_30[28];
  __IO uint32_t FLEXCOMM9_TRIG;                    /**< LP_FLEXCOMM9 Trigger Input Connections, offset: 0x6C0 */
       uint8_t RESERVED_31[28];
  __IO uint32_t FLEXIO_TRIG[INPUTMUX_FLEXIO_TRIGN_COUNT]; /**< FlexIO Trigger Input Connections, array offset: 0x6E0, array step: 0x4 */
  __IO uint32_t DMA0_REQ_ENABLE0;                  /**< DMA0 Request Enable0, offset: 0x700 */
  __O  uint32_t DMA0_REQ_ENABLE0_SET;              /**< DMA0 Request Enable0, offset: 0x704 */
  __O  uint32_t DMA0_REQ_ENABLE0_CLR;              /**< DMA0 Request Enable0, offset: 0x708 */
  __O  uint32_t DMA0_REQ_ENABLE0_TOG;              /**< DMA0 Request Enable0, offset: 0x70C */
  __IO uint32_t DMA0_REQ_ENABLE1;                  /**< DMA0 Request Enable1, offset: 0x710 */
  __O  uint32_t DMA0_REQ_ENABLE1_SET;              /**< DMA0 Request Enable1, offset: 0x714 */
  __O  uint32_t DMA0_REQ_ENABLE1_CLR;              /**< DMA0 Request Enable1, offset: 0x718 */
  __O  uint32_t DMA0_REQ_ENABLE1_TOG;              /**< DMA0 Request Enable1, offset: 0x71C */
  __IO uint32_t DMA0_REQ_ENABLE2;                  /**< DMA0 Request Enable2, offset: 0x720 */
  __O  uint32_t DMA0_REQ_ENABLE2_SET;              /**< DMA0 Request Enable2, offset: 0x724 */
  __O  uint32_t DMA0_REQ_ENABLE2_CLR;              /**< DMA0 Request Enable2, offset: 0x728 */
  __O  uint32_t DMA0_REQ_ENABLE2_TOG;              /**< DMA0 Request Enable2, offset: 0x72C */
  __IO uint32_t DMA0_REQ_ENABLE3;                  /**< DMA0 Request Enable3, offset: 0x730 */
  __O  uint32_t DMA0_REQ_ENABLE3_SET;              /**< DMA0 Request Enable3, offset: 0x734 */
  __O  uint32_t DMA0_REQ_ENABLE3_CLR;              /**< DMA0 Request Enable3, offset: 0x738 */
       uint8_t RESERVED_32[68];
  __IO uint32_t DMA1_REQ_ENABLE0;                  /**< DMA1 Request Enable0, offset: 0x780 */
  __O  uint32_t DMA1_REQ_ENABLE0_SET;              /**< DMA1 Request Enable0, offset: 0x784 */
  __O  uint32_t DMA1_REQ_ENABLE0_CLR;              /**< DMA1 Request Enable0, offset: 0x788 */
  __O  uint32_t DMA1_REQ_ENABLE0_TOG;              /**< DMA1 Request Enable0, offset: 0x78C */
  __IO uint32_t DMA1_REQ_ENABLE1;                  /**< DMA1 Request Enable1, offset: 0x790 */
  __O  uint32_t DMA1_REQ_ENABLE1_SET;              /**< DMA1 Request Enable1, offset: 0x794 */
  __O  uint32_t DMA1_REQ_ENABLE1_CLR;              /**< DMA1 Request Enable1, offset: 0x798 */
  __O  uint32_t DMA1_REQ_ENABLE1_TOG;              /**< DMA1 Request Enable1, offset: 0x79C */
  __IO uint32_t DMA1_REQ_ENABLE2;                  /**< DMA1 Request Enable2, offset: 0x7A0 */
  __O  uint32_t DMA1_REQ_ENABLE2_SET;              /**< DMA1 Request Enable2, offset: 0x7A4 */
  __O  uint32_t DMA1_REQ_ENABLE2_CLR;              /**< DMA1 Request Enable2, offset: 0x7A8 */
  __O  uint32_t DMA1_REQ_ENABLE2_TOG;              /**< DMA1 Request Enable2, offset: 0x7AC */
  __IO uint32_t DMA1_REQ_ENABLE3;                  /**< DMA1 Request Enable3, offset: 0x7B0 */
  __O  uint32_t DMA1_REQ_ENABLE3_SET;              /**< DMA1 Request Enable3, offset: 0x7B4 */
  __O  uint32_t DMA1_REQ_ENABLE3_CLR;              /**< DMA1 Request Enable3, offset: 0x7B8 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name INPUTMUX_SCT0_SCT0_INMUX - Inputmux Register for SCT0 Input */
/*! @{ */

#define INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_INP_MASK (0x7FU)
#define INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_INP_SHIFT (0U)
/*! INP - Input number to SCT0 inputs.
 *  0b0000000..SCT0_IN0 input is selected
 *  0b0000001..SCT0_IN1 input is selected
 *  0b0000010..SCT0_IN2 input is selected
 *  0b0000011..SCT0_IN3 input is selected
 *  0b0000100..SCT0_IN4 input is selected
 *  0b0000101..SCT0_IN5 input is selected
 *  0b0000110..SCT0_IN6 input is selected
 *  0b0000111..SCT0_IN7 input is selected
 *  0b0001000..CTIMER0_MAT0 input is selected
 *  0b0001001..CTIMER1_MAT0 input is selected
 *  0b0001010..CTIMER2_MAT0 input is selected
 *  0b0001011..CTIMER3_MAT0 input is selected
 *  0b0001100..CTIMER4_MAT0 input is selected
 *  0b0001101..ADC0 ADC0_IRQ input is selected
 *  0b0001110..PINT GPIO_INT_BMAT input is selected
 *  0b0001111..usb0 start of frame input is selected
 *  0b0010000..usb1 start of frame input is selected
 *  0b0010001..SINC Filter CH0 Conversion Complete input is selected
 *  0b0010010..SINC Filter CH1 Conversion Complete input is selected
 *  0b0010011..SINC Filter CH2 Conversion Complete input is selected
 *  0b0010100..SINC Filter CH3 Conversion Complete input is selected
 *  0b0010101..SINC Filter CH4 Conversion Complete input is selected
 *  0b0010110..Reserved
 *  0b0010111..DEBUG_HALTED input is selected
 *  0b0011000..ADC1_IRQ input is selected
 *  0b0011001..ADC0_tcomp[0] input is selected
 *  0b0011010..ADC0_tcomp[1] input is selected
 *  0b0011011..ADC0_tcomp[2] input is selected
 *  0b0011100..ADC0_tcomp[3] input is selected
 *  0b0011101..ADC1_tcomp[0] input is selected
 *  0b0011110..ADC1_tcomp[1] input is selected
 *  0b0011111..ADC1_tcomp[2] input is selected
 *  0b0100000..ADC1_tcomp[3] input is selected
 *  0b0100001..CMP0_OUT input is selected
 *  0b0100010..CMP1_OUT input is selected
 *  0b0100011..CMP2_OUT input is selected
 *  0b0100100..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0100101..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100110..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100111..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0101000..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0101001..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0101010..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0101011..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0101100..QDC0_CMP/POS_MATCH input is selected
 *  0b0101101..QDC1_CMP/POS_MATCH input is selected
 *  0b0101110..EVTG_OUT0A input is selected
 *  0b0101111..EVTG_OUT0B input is selected
 *  0b0110000..EVTG_OUT1A input is selected
 *  0b0110001..EVTG_OUT1B input is selected
 *  0b0110010..EVTG_OUT2A input is selected
 *  0b0110011..EVTG_OUT2B input is selected
 *  0b0110100..EVTG_OUT3A input is selected
 *  0b0110101..EVTG_OUT3B input is selected
 *  0b0110110..FC3_P0 (SDO, SDA) input is selected
 *  0b0110111..FC3_P1 (SCK, TXD, SCL) input is selected
 *  0b0111000..FC3_P2 (RTS, SCLS, TXD) input is selected
 *  0b0111001..FC3_P3 (PCS[0], CTS, SDAS) input is selected
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..LP_FLEXCOMM0 trig 0 (lpuart_trg_txword) input is selected
 *  0b0111101..LP_FLEXCOMM0 trig 1 (lpuart_trg_rxword) input is selected
 *  0b0111110..LP_FLEXCOMM0 trig 2 (lpuart_trg_rxidle) input is selected
 *  0b0111111..LP_FLEXCOMM1 trig 0 input is selected
 *  0b1000000..LP_FLEXCOMM1 trig 1 input is selected
 *  0b1000001..LP_FLEXCOMM1 trig 2 input is selected
 *  0b1000010..LP_FLEXCOMM2 trig 0 input is selected
 *  0b1000011..LP_FLEXCOMM2 trig 1 input is selected
 *  0b1000100..LP_FLEXCOMM2 trig 2 input is selected
 *  0b1000101..LP_FLEXCOMM3 trig 0 input is selected
 *  0b1000110..LP_FLEXCOMM3 trig 1 input is selected
 *  0b1000111..LP_FLEXCOMM3 trig 2 input is selected
 *  0b1001000..LP_FLEXCOMM3 trig 3 input is selected
 *  0b1001001..SAI0 TX BCLK input is selected
 *  0b1001010..SAI0 RX BCLK input is selected
 *  0b1001011..SAI1 TX BCLK input is selected
 *  0b1001100..SAI1 RX BCLK input is selected
 */
#define INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_INP_SHIFT)) & INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_INP_MASK)
/*! @} */

/* The count of INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX */
#define INPUTMUX_INPUTMUX_SCT0_SCT0_INMUX_COUNT  (8U)

/*! @name CTIMER0CAP0 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER0CAP0_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0CAP0_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER0CAP0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0CAP0_INP_SHIFT)) & INPUTMUX_CTIMER0CAP0_INP_MASK)
/*! @} */

/*! @name CTIMER0CAP1 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER0CAP1_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0CAP1_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER0CAP1_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0CAP1_INP_SHIFT)) & INPUTMUX_CTIMER0CAP1_INP_MASK)
/*! @} */

/*! @name CTIMER0CAP2 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER0CAP2_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0CAP2_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER0CAP2_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0CAP2_INP_SHIFT)) & INPUTMUX_CTIMER0CAP2_INP_MASK)
/*! @} */

/*! @name CTIMER0CAP3 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER0CAP3_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0CAP3_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER0CAP3_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0CAP3_INP_SHIFT)) & INPUTMUX_CTIMER0CAP3_INP_MASK)
/*! @} */

/*! @name TIMER0TRIG - Trigger Register for CTIMER */
/*! @{ */

#define INPUTMUX_TIMER0TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER0TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_TIMER0TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER0TRIG_INP_SHIFT)) & INPUTMUX_TIMER0TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP0 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER1CAP0_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1CAP0_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER1CAP0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1CAP0_INP_SHIFT)) & INPUTMUX_CTIMER1CAP0_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP1 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER1CAP1_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1CAP1_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER1CAP1_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1CAP1_INP_SHIFT)) & INPUTMUX_CTIMER1CAP1_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP2 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER1CAP2_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1CAP2_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER1CAP2_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1CAP2_INP_SHIFT)) & INPUTMUX_CTIMER1CAP2_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP3 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER1CAP3_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1CAP3_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER1CAP3_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1CAP3_INP_SHIFT)) & INPUTMUX_CTIMER1CAP3_INP_MASK)
/*! @} */

/*! @name TIMER1TRIG - Trigger Register for CTIMER */
/*! @{ */

#define INPUTMUX_TIMER1TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER1TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_TIMER1TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER1TRIG_INP_SHIFT)) & INPUTMUX_TIMER1TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP0 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER2CAP0_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER2CAP0_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER2CAP0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2CAP0_INP_SHIFT)) & INPUTMUX_CTIMER2CAP0_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP1 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER2CAP1_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER2CAP1_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER2CAP1_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2CAP1_INP_SHIFT)) & INPUTMUX_CTIMER2CAP1_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP2 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER2CAP2_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER2CAP2_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER2CAP2_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2CAP2_INP_SHIFT)) & INPUTMUX_CTIMER2CAP2_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP3 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER2CAP3_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER2CAP3_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER2CAP3_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2CAP3_INP_SHIFT)) & INPUTMUX_CTIMER2CAP3_INP_MASK)
/*! @} */

/*! @name TIMER2TRIG - Trigger Register for CTIMER */
/*! @{ */

#define INPUTMUX_TIMER2TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER2TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0_IRQ input is selected
 *  0b0011010..ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_TIMER2TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER2TRIG_INP_SHIFT)) & INPUTMUX_TIMER2TRIG_INP_MASK)
/*! @} */

/*! @name INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX - Inputmux Register for SMARTDMA Arch B Inputs */
/*! @{ */

#define INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_INP_MASK (0x7FU)
#define INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_INP_SHIFT (0U)
/*! INP - Input number select to SmartDMA ARCHB input
 *  0b0000000..FlexIO interrupt is selected as input
 *  0b0000001..GPIO P0_1 input is selected
 *  0b0000010..GPIO P0_2 input is selected
 *  0b0000011..GPIO P0_3 input is selected
 *  0b0000100..GPIO P0_4 input is selected
 *  0b0000101..GPIO P0_5 input is selected
 *  0b0000110..GPIO P0_6 input is selected
 *  0b0000111..GPIO P0_7 input is selected
 *  0b0001000..GPIO P0_8 input is selected
 *  0b0001001..GPIO P0_9 input is selected
 *  0b0001010..GPIO P0_10 input is selected
 *  0b0001011..GPIO P0_11 input is selected
 *  0b0001100..GPIO P0_12 input is selected
 *  0b0001101..GPIO P0_13 input is selected
 *  0b0001110..GPIO P0_14 input is selected
 *  0b0001111..GPIO P0_15 input is selected
 *  0b0010000..SCT0 SCT_OUT8 input is selected
 *  0b0010001..SCT0 SCT_OUT9 input is selected
 *  0b0010010..Reserved
 *  0b0010011..Reserved
 *  0b0010100..MRT0 MRT_CH0_IRQ input is selected
 *  0b0010101..MRT0 MRT_CH1_IRQ input is selected
 *  0b0010110..CTIMER4_MAT3 input is selected
 *  0b0010111..CTIMER4_MAT2 input is selected
 *  0b0011000..CTIMER3_MAT3 input is selected
 *  0b0011001..CTIMER3_MAT2 input is selected
 *  0b0011010..CTIMER1_MAT3 input is selected
 *  0b0011011..CTIMER1_MAT2 input is selected
 *  0b0011100..UTICK0 UTICK_IRQ input is selected
 *  0b0011101..WWDT0 WDT0_IRQ input is selected
 *  0b0011110..ADC0 ADC0_IRQ input is selected
 *  0b0011111..CMP0_IRQ input is selected
 *  0b0100000..Reserved
 *  0b0100001..LP_FLEXCOMM7_IRQ input is selected
 *  0b0100010..LP_FLEXCOMM6_IRQ input is selected
 *  0b0100011..LP_FLEXCOMM5_IRQ input is selected
 *  0b0100100..LP_FLEXCOMM4_IRQ input is selected
 *  0b0100101..LP_FLEXCOMM3_IRQ input is selected
 *  0b0100110..LP_FLEXCOMM2_IRQ input is selected
 *  0b0100111..LP_FLEXCOMM1_IRQ input is selected
 *  0b0101000..LP_FLEXCOMM0_IRQ input is selected
 *  0b0101001..DMA0_IRQ input is selected
 *  0b0101010..DMA1_IRQ input is selected
 *  0b0101011..SYS_IRQSYS_IRQ combines the CDOG IRQ, WWDT IRQ, MBC secure violation IRQ, Secure AHB Matrix secure
 *             violation IRQ, GDET IRQ, ELS S50 error IRQ, PKC error IRQ, and VBAT IRQ using the logical OR
 *             operation. input is selected
 *  0b0101100..RTC_COMBO_IRQ input is selected
 *  0b0101101..ARM_TXEV input is selected
 *  0b0101110..PINT0 GPIO_INT_BMATCH input is selected
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CMP0_OUT input is selected
 *  0b0110010..usb0 start of frame input is selected
 *  0b0110011..usb1 start of frame input is selected
 *  0b0110100..OSTIMER0 OS_EVENT_TIMER_IRQ input is selected
 *  0b0110101..ADC1_IRQ input is selected
 *  0b0110110..CMP0_IRQ/CMP1_IRQ/CMP2_IRQ input is selected
 *  0b0110111..DAC0_IRQ input is selected
 *  0b0111000..DAC1_IRQ/DAC2_IRQ input is selected
 *  0b0111001..PWM0_IRQ input is selected
 *  0b0111010..PWM1_IRQ input is selected
 *  0b0111011..QDC0_IRQ input is selected
 *  0b0111100..QDC1_IRQ input is selected
 *  0b0111101..EVTG_OUT0A input is selected
 *  0b0111110..EVTG_OUT1A input is selected
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 *  0b1000001..GPIO1_alias0 GPIO1 Pin Event Trig 0 input is selected
 *  0b1000010..GPIO1_alias1 GPIO1 Pin Event Trig 1 input is selected
 *  0b1000011..GPIO2_alias0 GPIO2 Pin Event Trig 0 input is selected
 *  0b1000100..GPIO2_alias1 GPIO2 Pin Event Trig 1 input is selected
 *  0b1000101..GPIO3_alias0 GPIO3 Pin Event Trig 0 input is selected
 *  0b1000110..GPIO3_alias1 GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_INP_SHIFT)) & INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_INP_MASK)
/*! @} */

/* The count of INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX */
#define INPUTMUX_INPUTMUX_SMARTDMA_SMARTDMAARCHB_INMUX_COUNT (8U)

/*! @name INPUTMUX_GPIO_INT_PINTSEL - Pin Interrupt Select */
/*! @{ */

#define INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_INP_MASK (0x7FU)
#define INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_INP_SHIFT (0U)
/*! INP - Pin number select for pin interrupt or pattern match engine input. For PIOx_y: INP = (x *
 *    32) + y. PIO0_0 to PIO1_31 correspond to numbers 0 to 63.
 *  0b0000000..GPIO P0_0 input is selected
 *  0b0000001..GPIO P0_1 input is selected
 *  0b0000010..GPIO P0_2 input is selected
 *  0b0000011..GPIO P0_3 input is selected
 *  0b0000100..GPIO P0_4 input is selected
 *  0b0000101..GPIO P0_5 input is selected
 *  0b0000110..GPIO P0_6 input is selected
 *  0b0000111..GPIO P0_7 input is selected
 *  0b0001000..GPIO P0_8 input is selected
 *  0b0001001..GPIO P0_9 input is selected
 *  0b0001010..GPIO P0_10 input is selected
 *  0b0001011..GPIO P0_11 input is selected
 *  0b0001100..GPIO P0_12 input is selected
 *  0b0001101..GPIO P0_13 input is selected
 *  0b0001110..GPIO P0_14 input is selected
 *  0b0001111..GPIO P0_15 input is selected
 *  0b0010000..GPIO P0_16 input is selected
 *  0b0010001..GPIO P0_17 input is selected
 *  0b0010010..GPIO P0_18 input is selected
 *  0b0010011..GPIO P0_19 input is selected
 *  0b0010100..GPIO P0_20 input is selected
 *  0b0010101..GPIO P0_21 input is selected
 *  0b0010110..GPIO P0_22 input is selected
 *  0b0010111..GPIO P0_23 input is selected
 *  0b0011000..GPIO P0_24 input is selected
 *  0b0011001..GPIO P0_25 input is selected
 *  0b0011010..GPIO P0_26 input is selected
 *  0b0011011..GPIO P0_27 input is selected
 *  0b0011100..GPIO P0_28 input is selected
 *  0b0011101..GPIO P0_29 input is selected
 *  0b0011110..GPIO P0_30 input is selected
 *  0b0011111..GPIO P0_31 input is selected
 *  0b0100000..GPIO P1_0 input is selected
 *  0b0100001..GPIO P1_1 input is selected
 *  0b0100010..GPIO P1_2 input is selected
 *  0b0100011..GPIO P1_3 input is selected
 *  0b0100100..GPIO P1_4 input is selected
 *  0b0100101..GPIO P1_5 input is selected
 *  0b0100110..GPIO P1_6 input is selected
 *  0b0100111..GPIO P1_7 input is selected
 *  0b0101000..GPIO P1_8 input is selected
 *  0b0101001..GPIO P1_9 input is selected
 *  0b0101010..GPIO P1_10 input is selected
 *  0b0101011..GPIO P1_11 input is selected
 *  0b0101100..GPIO P1_12 input is selected
 *  0b0101101..GPIO P1_13 input is selected
 *  0b0101110..GPIO P1_14 input is selected
 *  0b0101111..GPIO P1_15 input is selected
 *  0b0110000..GPIO P1_16 input is selected
 *  0b0110001..GPIO P1_17 input is selected
 *  0b0110010..GPIO P1_18 input is selected
 *  0b0110011..GPIO P1_19 input is selected
 *  0b0110100..GPIO P1_20 input is selected
 *  0b0110101..GPIO P1_21 input is selected
 *  0b0110110..GPIO P1_22 input is selected
 *  0b0110111..GPIO P1_23 input is selected
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..GPIO P1_30 input is selected
 *  0b0111111..GPIO P1_31 input is selected
 */
#define INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_INP_SHIFT)) & INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_INP_MASK)
/*! @} */

/* The count of INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL */
#define INPUTMUX_INPUTMUX_GPIO_INT_PINTSEL_COUNT (8U)

/*! @name FREQMEAS_REF - Selection for Frequency Measurement Reference Clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_REF_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function reference clock.
 *  0b000000..clk_in (output of clk_in or XTAL mux in Clockgen) input is selected
 *  0b000001..FRO_12M input is selected
 *  0b000010..FRO_144M input is selected
 *  0b000011..Reserved
 *  0b000100..OSC_32K input is selected
 *  0b000101..CPU/system_clk input is selected
 *  0b000110..FREQME_CLK_IN0 input is selected
 *  0b000111..FREQME_CLK_IN1 input is selected
 *  0b001000..EVTG_OUT0A input is selected
 *  0b001001..EVTG_OUT1A input is selected
 */
#define INPUTMUX_FREQMEAS_REF_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_INP_SHIFT)) & INPUTMUX_FREQMEAS_REF_INP_MASK)
/*! @} */

/*! @name FREQMEAS_TAR - Selection for Frequency Measurement Target Clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TAR_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_TAR_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b000000..clk_in (output of clk_in or XTAL mux in Clockgen) input is selected
 *  0b000001..FRO_12M input is selected
 *  0b000010..FRO_144M input is selected
 *  0b000011..Reserved
 *  0b000100..OSC_32K input is selected
 *  0b000101..CPU/system_clk input is selected
 *  0b000110..FREQME_CLK_IN0 input is selected
 *  0b000111..FREQME_CLK_IN1 input is selected
 *  0b001000..EVTG_OUT0A input is selected
 *  0b001001..EVTG_OUT1A input is selected
 */
#define INPUTMUX_FREQMEAS_TAR_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TAR_INP_SHIFT)) & INPUTMUX_FREQMEAS_TAR_INP_MASK)
/*! @} */

/*! @name CTIMER3CAP0 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER3CAP0_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER3CAP0_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER3CAP0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER3CAP0_INP_SHIFT)) & INPUTMUX_CTIMER3CAP0_INP_MASK)
/*! @} */

/*! @name CTIMER3CAP1 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER3CAP1_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER3CAP1_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER3CAP1_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER3CAP1_INP_SHIFT)) & INPUTMUX_CTIMER3CAP1_INP_MASK)
/*! @} */

/*! @name CTIMER3CAP2 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER3CAP2_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER3CAP2_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER3CAP2_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER3CAP2_INP_SHIFT)) & INPUTMUX_CTIMER3CAP2_INP_MASK)
/*! @} */

/*! @name CTIMER3CAP3 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER3CAP3_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER3CAP3_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER3CAP3_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER3CAP3_INP_SHIFT)) & INPUTMUX_CTIMER3CAP3_INP_MASK)
/*! @} */

/*! @name TIMER3TRIG - Trigger Register for CTIMER */
/*! @{ */

#define INPUTMUX_TIMER3TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER3TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_TIMER3TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER3TRIG_INP_SHIFT)) & INPUTMUX_TIMER3TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER4CAP0 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER4CAP0_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER4CAP0_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER4CAP0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER4CAP0_INP_SHIFT)) & INPUTMUX_CTIMER4CAP0_INP_MASK)
/*! @} */

/*! @name CTIMER4CAP1 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER4CAP1_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER4CAP1_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER4CAP1_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER4CAP1_INP_SHIFT)) & INPUTMUX_CTIMER4CAP1_INP_MASK)
/*! @} */

/*! @name CTIMER4CAP2 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER4CAP2_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER4CAP2_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER4CAP2_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER4CAP2_INP_SHIFT)) & INPUTMUX_CTIMER4CAP2_INP_MASK)
/*! @} */

/*! @name CTIMER4CAP3 - Capture Select Register for CTIMER Inputs */
/*! @{ */

#define INPUTMUX_CTIMER4CAP3_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER4CAP3_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_CTIMER4CAP3_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER4CAP3_INP_SHIFT)) & INPUTMUX_CTIMER4CAP3_INP_MASK)
/*! @} */

/*! @name TIMER4TRIG - Trigger Register for CTIMER */
/*! @{ */

#define INPUTMUX_TIMER4TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER4TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER
 *  0b0000000..CT_INP0 input is selected
 *  0b0000001..CT_INP1 input is selected
 *  0b0000010..CT_INP2 input is selected
 *  0b0000011..CT_INP3 input is selected
 *  0b0000100..CT_INP4 input is selected
 *  0b0000101..CT_INP5 input is selected
 *  0b0000110..CT_INP6 input is selected
 *  0b0000111..CT_INP7 input is selected
 *  0b0001000..CT_INP8 input is selected
 *  0b0001001..CT_INP9 input is selected
 *  0b0001010..CT_INP10 input is selected
 *  0b0001011..CT_INP11 input is selected
 *  0b0001100..CT_INP12 input is selected
 *  0b0001101..CT_INP13 input is selected
 *  0b0001110..CT_INP14 input is selected
 *  0b0001111..CT_INP15 input is selected
 *  0b0010000..CT_INP16 input is selected
 *  0b0010001..CT_INP17 input is selected
 *  0b0010010..CT_INP18 input is selected
 *  0b0010011..CT_INP19 input is selected
 *  0b0010100..usb0 start of frame input is selected
 *  0b0010101..usb1 start of frame input is selected
 *  0b0010110..DCDC_BURST_ACTIVE input is selected
 *  0b0010111..sai0_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011000..sai0_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b0011001..ADC0 ADC0_IRQ input is selected
 *  0b0011010..ADC0 ADC1_IRQ input is selected
 *  0b0011011..CMP0_OUT input is selected
 *  0b0011100..CMP1_OUT input is selected
 *  0b0011101..CMP2_OUT input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0100110..QDC0_CMP/POS_MATCH input is selected
 *  0b0100111..QDC1_CMP/POS_MATCH input is selected
 *  0b0101000..EVTG_OUT0A input is selected
 *  0b0101001..EVTG_OUT0B input is selected
 *  0b0101010..EVTG_OUT1A input is selected
 *  0b0101011..EVTG_OUT1B input is selected
 *  0b0101100..EVTG_OUT2A input is selected
 *  0b0101101..EVTG_OUT2B input is selected
 *  0b0101110..EVTG_OUT3A input is selected
 *  0b0101111..EVTG_OUT3B input is selected
 *  0b0110000..Reserved
 *  0b0110001..Reserved
 *  0b0110010..LP_FLEXCOMM0 trig 0 input is selected
 *  0b0110011..LP_FLEXCOMM0 trig 1 input is selected
 *  0b0110100..LP_FLEXCOMM0 trig 2 input is selected
 *  0b0110101..LP_FLEXCOMM1 trig 0 input is selected
 *  0b0110110..LP_FLEXCOMM1 trig 1 input is selected
 *  0b0110111..LP_FLEXCOMM1 trig 2 input is selected
 *  0b0111000..LP_FLEXCOMM2 trig 0 input is selected
 *  0b0111001..LP_FLEXCOMM2 trig 1 input is selected
 *  0b0111010..LP_FLEXCOMM2 trig 2 input is selected
 *  0b0111011..LP_FLEXCOMM3 trig 0 input is selected
 *  0b0111100..LP_FLEXCOMM3 trig 1 input is selected
 *  0b0111101..LP_FLEXCOMM3 trig 2 input is selected
 *  0b0111110..LP_FLEXCOMM3 trig 3 input is selected
 *  0b0111111..sai1_tx_sync_outsai_tx_sync_out is Transmit Frame Sync for multi-SAI synchronous operation. input is selected
 *  0b1000000..sai1_rx_sync_outsai_rx_sync_out is Receive Frame Sync for multi-SAI synchronous operation. input is selected
 */
#define INPUTMUX_TIMER4TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER4TRIG_INP_SHIFT)) & INPUTMUX_TIMER4TRIG_INP_MASK)
/*! @} */

/*! @name CMP0_TRIG - CMP0 Input Connections */
/*! @{ */

#define INPUTMUX_CMP0_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT6 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT6 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER0_MAT0 input is selected
 *  0b001001..CTIMER4_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC1_tcomp[0] input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010010..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010100..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b010101..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b010110..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b010111..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011000..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b011001..QDC0_CMP/POS_MATCH input is selected
 *  0b011010..QDC1_CMP/POS_MATCH input is selected
 *  0b011011..EVTG_OUT0A input is selected
 *  0b011100..EVTG_OUT0B input is selected
 *  0b011101..EVTG_OUT1A input is selected
 *  0b011110..EVTG_OUT1B input is selected
 *  0b011111..EVTG_OUT2A input is selected
 *  0b100000..EVTG_OUT2B input is selected
 *  0b100001..EVTG_OUT3A input is selected
 *  0b100010..EVTG_OUT3B input is selected
 *  0b100011..LPTMR0 input is selected
 *  0b100100..LPTMR1 input is selected
 *  0b100101..GPIO2 Pin Event Trig 0 input is selected
 *  0b100110..GPIO2 Pin Event Trig 1 input is selected
 *  0b100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b101000..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_CMP0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIGM_ADC0_TRIG - ADC Trigger Input Connections */
/*! @{ */

#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK (0xFFU)
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b00000000..PINT PIN_INT0 input is selected
 *  0b00000001..PINT PIN_INT1 input is selected
 *  0b00000010..SCT0 SCT_OUT4 input is selected
 *  0b00000011..SCT0 SCT_OUT5 input is selected
 *  0b00000100..SCT0 SCT_OUT9 input is selected
 *  0b00000101..CTIMER0_MAT3 input is selected
 *  0b00000110..CTIMER1_MAT3 input is selected
 *  0b00000111..CTIMER2_MAT3 input is selected
 *  0b00001000..CTIMER3_MAT3 input is selected
 *  0b00001001..CTIMER4_MAT3 input is selected
 *  0b00001010..DCDC_Burst_Done_Trig input is selected
 *  0b00001011..Reserved
 *  0b00001100..PINT GPIO_INT_BMAT input is selected
 *  0b00001101..ADC0_tcomp[0] input is selected
 *  0b00001110..ADC0_tcomp[1] input is selected
 *  0b00001111..ADC0_tcomp[2] input is selected
 *  0b00010000..ADC0_tcomp[3] input is selected
 *  0b00010001..ADC1_tcomp[0] input is selected
 *  0b00010010..ADC1_tcomp[1] input is selected
 *  0b00010011..ADC1_tcomp[2] input is selected
 *  0b00010100..ADC1_tcomp[3] input is selected
 *  0b00010101..CMP0_OUT input is selected
 *  0b00010110..CMP1_OUT input is selected
 *  0b00010111..CMP2_OUT input is selected
 *  0b00011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b00011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b00011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b00011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b00011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b00011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b00011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b00011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b00100000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b00100001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b00100010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b00100011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b00100100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b00100101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b00100110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b00100111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b00101000..QDC0_CMP/POS_MATCH input is selected
 *  0b00101001..QDC1_CMP/POS_MATCH input is selected
 *  0b00101010..EVTG_OUT0A input is selected
 *  0b00101011..EVTG_OUT0B input is selected
 *  0b00101100..EVTG_OUT1A input is selected
 *  0b00101101..EVTG_OUT1B input is selected
 *  0b00101110..EVTG_OUT2A input is selected
 *  0b00101111..EVTG_OUT2B input is selected
 *  0b00110000..EVTG_OUT3A input is selected
 *  0b00110001..EVTG_OUT3B input is selected
 *  0b00110010..LPTMR0 input is selected
 *  0b00110011..LPTMR1 input is selected
 *  0b00110100..FlexIO CH0 input is selected
 *  0b00110101..FlexIO CH1 input is selected
 *  0b00110110..FlexIO CH2 input is selected
 *  0b00110111..FlexIO CH3 input is selected
 *  0b00111000..SINC Filter CH0 Conversion Complete input is selected
 *  0b00111001..SINC Filter CH1 Conversion Complete input is selected
 *  0b00111010..SINC Filter CH2 Conversion Complete input is selected
 *  0b00111011..SINC Filter CH3 Conversion Complete input is selected
 *  0b00111100..SINC Filter CH4 Conversion Complete input is selected
 *  0b00111101..GPIO2 Pin Event Trig 0 input is selected
 *  0b00111110..GPIO2 Pin Event Trig 1 input is selected
 *  0b00111111..GPIO3 Pin Event Trig 0 input is selected
 *  0b01000000..GPIO3 Pin Event Trig 1 input is selected
 *  0b01000001..WUU input is selected
 */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC0_TRIGM_ADC0_TRIG */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_COUNT      (4U)

/*! @name ADC1_TRIGN_ADC1_TRIG - ADC Trigger Input Connections */
/*! @{ */

#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_MASK (0xFFU)
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC1 trigger inputs
 *  0b00000000..PINT PIN_INT0 input is selected
 *  0b00000001..PINT PIN_INT2 input is selected
 *  0b00000010..SCT0 SCT_OUT4 input is selected
 *  0b00000011..SCT0 SCT_OUT5 input is selected
 *  0b00000100..SCT0 SCT_OUT3 input is selected
 *  0b00000101..CTIMER0_MAT3 input is selected
 *  0b00000110..CTIMER1_MAT3 input is selected
 *  0b00000111..CTIMER2_MAT3 input is selected
 *  0b00001000..CTIMER3_MAT2 input is selected
 *  0b00001001..CTIMER4_MAT1 input is selected
 *  0b00001010..DCDC_Burst_Done_Trig input is selected
 *  0b00001011..Reserved
 *  0b00001100..PINT GPIO_INT_BMAT input is selected
 *  0b00001101..ADC0_tcomp[0] input is selected
 *  0b00001110..ADC0_tcomp[1] input is selected
 *  0b00001111..ADC0_tcomp[2] input is selected
 *  0b00010000..ADC0_tcomp[3] input is selected
 *  0b00010001..ADC1_tcomp[0] input is selected
 *  0b00010010..ADC1_tcomp[1] input is selected
 *  0b00010011..ADC1_tcomp[2] input is selected
 *  0b00010100..ADC1_tcomp[3] input is selected
 *  0b00010101..CMP0_OUT input is selected
 *  0b00010110..CMP1_OUT input is selected
 *  0b00010111..CMP2_OUT input is selected
 *  0b00011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b00011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b00011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b00011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b00011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b00011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b00011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b00011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b00100000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b00100001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b00100010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b00100011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b00100100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b00100101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b00100110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b00100111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b00101000..QDC0_CMP/POS_MATCH input is selected
 *  0b00101001..QDC1_CMP/POS_MATCH input is selected
 *  0b00101010..EVTG_OUT0A input is selected
 *  0b00101011..EVTG_OUT0B input is selected
 *  0b00101100..EVTG_OUT1A input is selected
 *  0b00101101..EVTG_OUT1B input is selected
 *  0b00101110..EVTG_OUT2A input is selected
 *  0b00101111..EVTG_OUT2B input is selected
 *  0b00110000..EVTG_OUT3A input is selected
 *  0b00110001..EVTG_OUT3B input is selected
 *  0b00110010..LPTMR0 input is selected
 *  0b00110011..LPTMR1 input is selected
 *  0b00110100..FlexIO CH0 input is selected
 *  0b00110101..FlexIO CH1 input is selected
 *  0b00110110..FlexIO CH2 input is selected
 *  0b00110111..FlexIO CH3 input is selected
 *  0b00111000..SINC Filter CH0 Conversion Complete input is selected
 *  0b00111001..SINC Filter CH1 Conversion Complete input is selected
 *  0b00111010..SINC Filter CH2 Conversion Complete input is selected
 *  0b00111011..SINC Filter CH3 Conversion Complete input is selected
 *  0b00111100..SINC Filter CH4 Conversion Complete input is selected
 *  0b00111101..GPIO2 Pin Event Trig 0 input is selected
 *  0b00111110..GPIO2 Pin Event Trig 1 input is selected
 *  0b00111111..GPIO3 Pin Event Trig 0 input is selected
 *  0b01000000..GPIO3 Pin Event Trig 1 input is selected
 *  0b01000001..WUU input is selected
 */
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC1_TRIGN_ADC1_TRIG */
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_COUNT      (4U)

/*! @name DAC0_TRIG - DAC0 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC0_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC0 trigger input
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT3 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT0 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC1_tcomp[0] input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..LPTMR0 input is selected
 *  0b011011..LPTMR1 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO2 Pin Event Trig 1 input is selected
 *  0b011110..GPIO3 Pin Event Trig 0 input is selected
 *  0b011111..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_DAC0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name DAC1_TRIG - DAC1 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC1_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_DAC1_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC1 trigger input
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER3_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[1] input is selected
 *  0b001110..ADC1_tcomp[1] input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..LPTMR0 input is selected
 *  0b011011..LPTMR1 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO2 Pin Event Trig 1 input is selected
 *  0b011110..GPIO3 Pin Event Trig 0 input is selected
 *  0b011111..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_DAC1_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name DAC2_TRIG - DAC2 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC2_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_DAC2_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC2 trigger input
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT2 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT2 input is selected
 *  0b001001..CTIMER3_MAT2 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[2] input is selected
 *  0b001110..ADC1_tcomp[2] input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..LPTMR0 input is selected
 *  0b011011..LPTMR1 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO2 Pin Event Trig 1 input is selected
 *  0b011110..GPIO3 Pin Event Trig 0 input is selected
 *  0b011111..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_DAC2_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC2_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name QDCN_QDC_TRIG - QDC0 Trigger Input Connections..QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDCN_QDC_TRIG_INP_MASK          (0x3FU)
#define INPUTMUX_QDCN_QDC_TRIG_INP_SHIFT         (0U)
/*! INP - QDC1 trigger input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER1_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 */
#define INPUTMUX_QDCN_QDC_TRIG_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDCN_QDC_TRIG_INP_SHIFT)) & INPUTMUX_QDCN_QDC_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_QDCN_QDC_TRIG */
#define INPUTMUX_QDCN_QDC_TRIG_COUNT             (2U)

/*! @name QDCN_QDC_HOME - QDC0 Input Connections..QDC1 Input Connections */
/*! @{ */

#define INPUTMUX_QDCN_QDC_HOME_INP_MASK          (0x3FU)
#define INPUTMUX_QDCN_QDC_HOME_INP_SHIFT         (0U)
/*! INP - QDC1 HOME input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER1_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 */
#define INPUTMUX_QDCN_QDC_HOME_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDCN_QDC_HOME_INP_SHIFT)) & INPUTMUX_QDCN_QDC_HOME_INP_MASK)
/*! @} */

/* The count of INPUTMUX_QDCN_QDC_HOME */
#define INPUTMUX_QDCN_QDC_HOME_COUNT             (2U)

/*! @name QDCN_QDC_INDEX - QDC0 Input Connections..QDC1 Input Connections */
/*! @{ */

#define INPUTMUX_QDCN_QDC_INDEX_INP_MASK         (0x3FU)
#define INPUTMUX_QDCN_QDC_INDEX_INP_SHIFT        (0U)
/*! INP - QDC1 INDEX input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER1_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 */
#define INPUTMUX_QDCN_QDC_INDEX_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDCN_QDC_INDEX_INP_SHIFT)) & INPUTMUX_QDCN_QDC_INDEX_INP_MASK)
/*! @} */

/* The count of INPUTMUX_QDCN_QDC_INDEX */
#define INPUTMUX_QDCN_QDC_INDEX_COUNT            (2U)

/*! @name QDCN_QDC_PHASEB - QDC0 Input Connections..QDC1 Input Connections */
/*! @{ */

#define INPUTMUX_QDCN_QDC_PHASEB_INP_MASK        (0x3FU)
#define INPUTMUX_QDCN_QDC_PHASEB_INP_SHIFT       (0U)
/*! INP - QDC1 PHASEB input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER1_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 */
#define INPUTMUX_QDCN_QDC_PHASEB_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDCN_QDC_PHASEB_INP_SHIFT)) & INPUTMUX_QDCN_QDC_PHASEB_INP_MASK)
/*! @} */

/* The count of INPUTMUX_QDCN_QDC_PHASEB */
#define INPUTMUX_QDCN_QDC_PHASEB_COUNT           (2U)

/*! @name QDCN_QDC_PHASEA - QDC0 Input Connections..QDC1 Input Connections */
/*! @{ */

#define INPUTMUX_QDCN_QDC_PHASEA_INP_MASK        (0x3FU)
#define INPUTMUX_QDCN_QDC_PHASEA_INP_SHIFT       (0U)
/*! INP - QDC1 PHASEA input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER1_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 */
#define INPUTMUX_QDCN_QDC_PHASEA_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDCN_QDC_PHASEA_INP_SHIFT)) & INPUTMUX_QDCN_QDC_PHASEA_INP_MASK)
/*! @} */

/* The count of INPUTMUX_QDCN_QDC_PHASEA */
#define INPUTMUX_QDCN_QDC_PHASEA_COUNT           (2U)

/*! @name FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC - PWM0 External Synchronization */
/*! @{ */

#define INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT2 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER4_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC */
#define INPUTMUX_FLEXPWM_SM_EXTSYNC_FLEXPWM0_SM_EXTSYNC_COUNT (4U)

/*! @name FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA - PWM0 Input Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT2 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER4_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA */
#define INPUTMUX_FLEXPWM_SM_EXT_FLEXPWM0_SM_EXTA_COUNT (4U)

/*! @name FLEXPWM0_EXTFORCE - PWM0 External Force Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_EXTFORCE_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_EXTFORCE_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTFORCE input connections for PWM0
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT2 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER4_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM0_EXTFORCE_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_EXTFORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_EXTFORCE_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM_FAULT_FLEXPWM0_FAULT - PWM0 Fault Input Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_TRIGIN_SHIFT (0U)
/*! TRIGIN - FAULT input connections for PWM0
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT2 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER4_MAT0 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT */
#define INPUTMUX_FLEXPWM_FAULT_FLEXPWM0_FAULT_COUNT (4U)

/*! @name FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC - PWM1 External Synchronization */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM1
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT2 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER4_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC */
#define INPUTMUX_FLEXPWM1_SM_EXTSYNC_ARRAY_FLEXPWM1_SM_EXTSYNC_COUNT (4U)

/*! @name FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA - PWM1 Input EXTA Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM1
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT2 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER4_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA */
#define INPUTMUX_FLEXPWM_SM1_EXTA_ARRAY_FLEXPWM1_SM_EXTA_COUNT (4U)

/*! @name FLEXPWM1_EXTFORCE - PWM1 External Force Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_EXTFORCE_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM1_EXTFORCE_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTFORCE input connections for PWM1
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT2 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER4_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM1_EXTFORCE_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_EXTFORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_EXTFORCE_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_FAULT - PWM1 Fault Input Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN_SHIFT     (0U)
/*! TRIGIN - FAULT input connections for PWM1
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT2 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER4_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV input is selected
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100000..QDC0_CMP/POS_MATCH input is selected
 *  0b100001..QDC1_CMP/POS_MATCH input is selected
 *  0b100010..EVTG_OUT0A input is selected
 *  0b100011..EVTG_OUT0B input is selected
 *  0b100100..EVTG_OUT1A input is selected
 *  0b100101..EVTG_OUT1B input is selected
 *  0b100110..EVTG_OUT2A input is selected
 *  0b100111..EVTG_OUT2B input is selected
 *  0b101000..EVTG_OUT3A input is selected
 *  0b101001..EVTG_OUT3B input is selected
 *  0b101010..TRIG_IN0 input is selected
 *  0b101011..TRIG_IN1 input is selected
 *  0b101100..TRIG_IN2 input is selected
 *  0b101101..TRIG_IN3 input is selected
 *  0b101110..TRIG_IN4 input is selected
 *  0b101111..TRIG_IN5 input is selected
 *  0b110000..TRIG_IN6 input is selected
 *  0b110001..TRIG_IN7 input is selected
 *  0b110010..TRIG_IN8 input is selected
 *  0b110011..TRIG_IN9 input is selected
 *  0b110100..SINC Filter CH0 sync Break input is selected
 *  0b110101..SINC Filter CH1 sync Break input is selected
 *  0b110110..SINC Filter CH2 sync Break input is selected
 *  0b110111..SINC Filter CH3 sync Break input is selected
 *  0b111000..SINC Filter CH4 sync Break input is selected
 *  0b111001..GPIO2 Pin Event Trig 0 input is selected
 *  0b111010..GPIO2 Pin Event Trig 1 input is selected
 *  0b111011..GPIO3 Pin Event Trig 0 input is selected
 *  0b111100..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_FAULT_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_FAULT_TRIGIN_MASK)
/*! @} */

/*! @name PWM0_EXT_CLK - PWM0 External Clock Trigger */
/*! @{ */

#define INPUTMUX_PWM0_EXT_CLK_TRIGIN_MASK        (0x7U)
#define INPUTMUX_PWM0_EXT_CLK_TRIGIN_SHIFT       (0U)
/*! TRIGIN - EXT_CLK input connections for PWM0
 *  0b000..FRO16K input is selected
 *  0b001..OSC_32k input is selected
 *  0b010..EVTG_OUT0A input is selected
 *  0b011..EVTG_OUT1A input is selected
 *  0b100..TRIG_IN0 input is selected
 *  0b101..TRIG_IN7 input is selected
 */
#define INPUTMUX_PWM0_EXT_CLK_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXT_CLK_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXT_CLK_TRIGIN_MASK)
/*! @} */

/*! @name PWM1_EXT_CLK - PWM1 External Clock Trigger */
/*! @{ */

#define INPUTMUX_PWM1_EXT_CLK_TRIGIN_MASK        (0xFU)
#define INPUTMUX_PWM1_EXT_CLK_TRIGIN_SHIFT       (0U)
/*! TRIGIN - EXT_CLK input connections for PWM1
 *  0b0000..FRO16K input is selected
 *  0b0001..OSC_32k input is selected
 *  0b0010..EVTG_OUT0A input is selected
 *  0b0011..EVTG_OUT1A input is selected
 *  0b0100..TRIG_IN0 input is selected
 *  0b0101..TRIG_IN7 input is selected
 */
#define INPUTMUX_PWM1_EXT_CLK_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXT_CLK_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXT_CLK_TRIGIN_MASK)
/*! @} */

/*! @name EVTG_TRIGN_EVTG_TRIG - EVTG Trigger Input Connections */
/*! @{ */

#define INPUTMUX_EVTG_TRIGN_EVTG_TRIG_INP_MASK   (0x3FU)
#define INPUTMUX_EVTG_TRIGN_EVTG_TRIG_INP_SHIFT  (0U)
/*! INP - EVTG trigger input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT1 input is selected
 *  0b000010..SCT_OUT0 input is selected
 *  0b000011..SCT_OUT1 input is selected
 *  0b000100..SCT_OUT2 input is selected
 *  0b000101..SCT_OUT3 input is selected
 *  0b000110..CTIMER0_MAT3 input is selected
 *  0b000111..CTIMER1_MAT3 input is selected
 *  0b001000..CTIMER2_MAT3 input is selected
 *  0b001001..CTIMER2_MAT2 input is selected
 *  0b001010..CTIMER3_MAT2 input is selected
 *  0b001011..CTIMER4_MAT2 input is selected
 *  0b001100..Reserved
 *  0b001101..PINT GPIO_INT_BMAT input is selected
 *  0b001110..ADC0_IRQ input is selected
 *  0b001111..ADC1_IRQ input is selected
 *  0b010000..ADC0_tcomp[0] input is selected
 *  0b010001..ADC0_tcomp[1] input is selected
 *  0b010010..ADC0_tcomp[2] input is selected
 *  0b010011..ADC0_tcomp[3] input is selected
 *  0b010100..ADC1_tcomp[0] input is selected
 *  0b010101..ADC1_tcomp[1] input is selected
 *  0b010110..ADC1_tcomp[2] input is selected
 *  0b010111..ADC1_tcomp[3] input is selected
 *  0b011000..CMP0_OUT input is selected
 *  0b011001..CMP1_OUT input is selected
 *  0b011010..CMP2_OUT input is selected
 *  0b011011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b100000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b100001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b100010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100011..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b100100..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b100101..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b100110..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b100111..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b101000..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b101001..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b101010..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b101011..QDC0_CMP/POS_MATCH input is selected
 *  0b101100..QDC1_CMP/POS_MATCH input is selected
 *  0b101101..TRIG_IN0 input is selected
 *  0b101110..TRIG_IN1 input is selected
 *  0b101111..TRIG_IN2 input is selected
 *  0b110000..TRIG_IN3 input is selected
 *  0b110001..LPTMR0 input is selected
 *  0b110010..LPTMR1 input is selected
 *  0b110011..SINC Filter CH0 Break input is selected
 *  0b110100..SINC Filter CH1 Break input is selected
 *  0b110101..SINC Filter CH2 Break input is selected
 *  0b110110..SINC Filter CH3 Break input is selected
 *  0b110111..SINC Filter CH4 Break input is selected
 *  0b111000..Reserved
 *  0b111001..Reserved
 */
#define INPUTMUX_EVTG_TRIGN_EVTG_TRIG_INP(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EVTG_TRIGN_EVTG_TRIG_INP_SHIFT)) & INPUTMUX_EVTG_TRIGN_EVTG_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_EVTG_TRIGN_EVTG_TRIG */
#define INPUTMUX_EVTG_TRIGN_EVTG_TRIG_COUNT      (16U)

/*! @name USBFS_TRIG - USB-FS Trigger Input Connections */
/*! @{ */

#define INPUTMUX_USBFS_TRIG_INP_MASK             (0xFU)
#define INPUTMUX_USBFS_TRIG_INP_SHIFT            (0U)
/*! INP - USB-FS trigger input connections. The trigger output of LP_FLEXCOMM is an input of peripheral INPUTMUX.
 *  0b0000..LP_FLEXCOMM 0 trigger out [3] input is selected
 *  0b0001..LP_FLEXCOMM 1 trigger out [3] input is selected
 *  0b0010..LP_FLEXCOMM 2 trigger out [3] input is selected
 *  0b0011..LP_FLEXCOMM 3 trigger out [3] input is selected
 *  0b0100..LP_FLEXCOMM 4 trigger out [3] input is selected
 *  0b0101..LP_FLEXCOMM 5 trigger out [3] input is selected
 *  0b0110..LP_FLEXCOMM 6 trigger out [3] input is selected
 *  0b0111..LP_FLEXCOMM 7 trigger out [3] input is selected
 *  0b1000..LP_FLEXCOMM 8 trigger out [3] input is selected
 *  0b1001..LP_FLEXCOMM 9 trigger out [3] input is selected
 */
#define INPUTMUX_USBFS_TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_USBFS_TRIG_INP_SHIFT)) & INPUTMUX_USBFS_TRIG_INP_MASK)
/*! @} */

/*! @name TSI_TRIG - TSI Trigger Input Connections */
/*! @{ */

#define INPUTMUX_TSI_TRIG_INP_MASK               (0x3U)
#define INPUTMUX_TSI_TRIG_INP_SHIFT              (0U)
/*! INP - TSI trigger input connections
 *  0b00..LPTMR0 input is selected
 *  0b01..LPTMR1 input is selected
 */
#define INPUTMUX_TSI_TRIG_INP(x)                 (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TSI_TRIG_INP_SHIFT)) & INPUTMUX_TSI_TRIG_INP_MASK)
/*! @} */

/*! @name EXT_TRIGN_EXT_TRIG - EXT Trigger Connections */
/*! @{ */

#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_MASK     (0x3FU)
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_SHIFT    (0U)
/*! INP - TRIG_OUTa pin input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT1 input is selected
 *  0b000010..ADC0_IRQ input is selected
 *  0b000011..ADC1_IRQ input is selected
 *  0b000100..ADC0_tcomp[0] input is selected
 *  0b000101..ADC1_tcomp[0] input is selected
 *  0b000110..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b000111..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b001000..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b001001..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b001010..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b001011..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b001100..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b001101..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b001110..QDC0_CMP/POS_MATCH input is selected
 *  0b001111..QDC1_CMP/POS_MATCH input is selected
 *  0b010000..EVTG_OUT0A input is selected
 *  0b010001..EVTG_OUT0B input is selected
 *  0b010010..EVTG_OUT1A input is selected
 *  0b010011..EVTG_OUT1B input is selected
 *  0b010100..EVTG_OUT2A input is selected
 *  0b010101..EVTG_OUT2B input is selected
 *  0b010110..EVTG_OUT3A input is selected
 *  0b010111..EVTG_OUT3B input is selected
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPTMR0 input is selected
 *  0b011011..LPTMR1 input is selected
 *  0b011100..SCT Out0 input is selected
 *  0b011101..SCT Out1 input is selected
 *  0b011110..SCT Out2 input is selected
 *  0b011111..SCT Out3 input is selected
 *  0b100000..SCT Out4 input is selected
 *  0b100001..SCT Out5 input is selected
 *  0b100010..LP_FLEXCOMM0 trigger output 3 input is selected
 *  0b100011..LP_FLEXCOMM1 trigger output 3 input is selected
 *  0b100100..LP_FLEXCOMM2 trigger output 3 input is selected
 *  0b100101..LP_FLEXCOMM3 trigger output 3 input is selected
 *  0b100110..LP_FLEXCOMM4 trigger output 3 input is selected
 *  0b100111..LP_FLEXCOMM5 trigger output 3 input is selected
 *  0b101000..LP_FLEXCOMM6 trigger output 3 input is selected
 *  0b101001..LP_FLEXCOMM7 trigger output 3 input is selected
 *  0b101010..LP_FLEXCOMM8 trigger output 3 input is selected
 *  0b101011..LP_FLEXCOMM9 trigger output 3 input is selected
 *  0b101100..CMP0_OUT input is selected
 *  0b101101..CMP1_OUT input is selected
 *  0b101110..CMP2_OUT input is selected
 *  0b101111..ENET_PPS_OUT_0 input is selected
 */
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_SHIFT)) & INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_EXT_TRIGN_EXT_TRIG */
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_COUNT        (8U)

/*! @name CMP1_TRIG - CMP1 Input Connections */
/*! @{ */

#define INPUTMUX_CMP1_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP1_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP1 input trigger
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT7 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT7 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER3_MAT1 input is selected
 *  0b001001..CTIMER4_MAT1 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[1] input is selected
 *  0b001110..ADC1_tcomp[1] input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010010..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010100..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b010101..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b010110..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b010111..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011000..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b011001..QDC0_CMP/POS_MATCH input is selected
 *  0b011010..QDC1_CMP/POS_MATCH input is selected
 *  0b011011..EVTG_OUT0A input is selected
 *  0b011100..EVTG_OUT0B input is selected
 *  0b011101..EVTG_OUT1A input is selected
 *  0b011110..EVTG_OUT1B input is selected
 *  0b011111..EVTG_OUT2A input is selected
 *  0b100000..EVTG_OUT2B input is selected
 *  0b100001..EVTG_OUT3A input is selected
 *  0b100010..EVTG_OUT3B input is selected
 *  0b100011..LPTMR0 input is selected
 *  0b100100..LPTMR1 input is selected
 *  0b100101..GPIO2 Pin Event Trig 0 input is selected
 *  0b100110..GPIO2 Pin Event Trig 1 input is selected
 *  0b100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b101000..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_CMP1_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name CMP2_TRIG - CMP2 Input Connections */
/*! @{ */

#define INPUTMUX_CMP2_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP2_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP2 input trigger
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT4 input is selected
 *  0b000010..SCT0 SCT_OUT4 input is selected
 *  0b000011..SCT0 SCT_OUT5 input is selected
 *  0b000100..SCT0 SCT_OUT8 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER3_MAT2 input is selected
 *  0b001001..CTIMER4_MAT2 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[2] input is selected
 *  0b001110..ADC1_tcomp[2] input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0/PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010010..PWM0_SM1_MUX_TRIG0/PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM2_MUX_TRIG0/PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010100..PWM0_SM3_MUX_TRIG0/PWM0_SM3_MUX_TRIG1 input is selected
 *  0b010101..PWM1_SM0_MUX_TRIG0/PWM1_SM0_MUX_TRIG1 input is selected
 *  0b010110..PWM1_SM1_MUX_TRIG0/PWM1_SM1_MUX_TRIG1 input is selected
 *  0b010111..PWM1_SM2_MUX_TRIG0/PWM1_SM2_MUX_TRIG1 input is selected
 *  0b011000..PWM1_SM3_MUX_TRIG0/PWM1_SM3_MUX_TRIG1 input is selected
 *  0b011001..QDC0_CMP/POS_MATCH input is selected
 *  0b011010..QDC1_CMP/POS_MATCH input is selected
 *  0b011011..EVTG_OUT0A input is selected
 *  0b011100..EVTG_OUT0B input is selected
 *  0b011101..EVTG_OUT1A input is selected
 *  0b011110..EVTG_OUT1B input is selected
 *  0b011111..EVTG_OUT2A input is selected
 *  0b100000..EVTG_OUT2B input is selected
 *  0b100001..EVTG_OUT3A input is selected
 *  0b100010..EVTG_OUT3B input is selected
 *  0b100011..LPTMR0 input is selected
 *  0b100100..LPTMR1 input is selected
 *  0b100101..GPIO2 Pin Event Trig 0 input is selected
 *  0b100110..GPIO2 Pin Event Trig 1 input is selected
 *  0b100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b101000..GPIO3 Pin Event Trig 1 input is selected
 */
#define INPUTMUX_CMP2_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP2_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name SINC_FILTER_CHN_SINC_FILTER_CH - SINC Filter Channel Trigger Input Connections */
/*! @{ */

#define INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_INP_MASK (0x3FU)
#define INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_INP_SHIFT (0U)
/*! INP - SINC FILTER trigger input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT1 input is selected
 *  0b000010..SCT_OUT4 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT9 input is selected
 *  0b000101..CTIMER0_MAT3 input is selected
 *  0b000110..CTIMER1_MAT3 input is selected
 *  0b000111..CTIMER2_MAT3 input is selected
 *  0b001000..CTIMER3_MAT3 input is selected
 *  0b001001..CTIMER4_MAT3 input is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..PINT GPIO_INT_BMAT input is selected
 *  0b001101..ADC0_tcomp[0] input is selected
 *  0b001110..ADC0_tcomp[1] input is selected
 *  0b001111..ADC0_tcomp[2] input is selected
 *  0b010000..ADC0_tcomp[3] input is selected
 *  0b010001..ADC1_tcomp[0] input is selected
 *  0b010010..ADC1_tcomp[1] input is selected
 *  0b010011..ADC1_tcomp[2] input is selected
 *  0b010100..ADC1_tcomp[3] input is selected
 *  0b010101..CMP0_OUT input is selected
 *  0b010110..CMP1_OUT input is selected
 *  0b010111..CMP2_OUT input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b100001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b100010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b100011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b100100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b100101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b100110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b100111..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b101000..QDC0_CMP/POS_MATCH input is selected
 *  0b101001..QDC1_CMP/POS_MATCH input is selected
 *  0b101010..EVTG_OUT0A input is selected
 *  0b101011..EVTG_OUT0B input is selected
 *  0b101100..EVTG_OUT1A input is selected
 *  0b101101..EVTG_OUT1B input is selected
 *  0b101110..EVTG_OUT2A input is selected
 *  0b101111..EVTG_OUT2B input is selected
 *  0b110000..EVTG_OUT3A input is selected
 *  0b110001..EVTG_OUT3B input is selected
 *  0b110010..LPTMR0 input is selected
 *  0b110011..LPTMR1 input is selected
 *  0b110100..FlexIO CH0 input is selected
 *  0b110101..FlexIO CH1 input is selected
 *  0b110110..FlexIO CH2 input is selected
 *  0b110111..FlexIO CH3 input is selected
 *  0b111000..WUU input is selected
 */
#define INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_INP_SHIFT)) & INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_INP_MASK)
/*! @} */

/* The count of INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH */
#define INPUTMUX_SINC_FILTER_CHN_SINC_FILTER_CH_COUNT (5U)

/*! @name OPAMPN_TRIG_OPAMP_TRIG - OPAMP Trigger Input Connections */
/*! @{ */

#define INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_INP_MASK (0x3FU)
#define INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_INP_SHIFT (0U)
/*! INP - OPAMP trigger input connections
 *  0b000000..PINT PIN_INT0 input is selected
 *  0b000001..PINT PIN_INT1 input is selected
 *  0b000010..PINT PIN_INT2 input is selected
 *  0b000011..PINT PIN_INT3 input is selected
 *  0b000100..SCT_OUT4 input is selected
 *  0b000101..SCT_OUT5 input is selected
 *  0b000110..SCT_OUT6 input is selected
 *  0b000111..SCT_OUT7 input is selected
 *  0b001000..SCT_OUT8 input is selected
 *  0b001001..CTIMER0_MAT3 input is selected
 *  0b001010..CTIMER1_MAT3 input is selected
 *  0b001011..CTIMER2_MAT3 input is selected
 *  0b001100..CTIMER3_MAT3 input is selected
 *  0b001101..CTIMER4_MAT3 input is selected
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..ADC0_tcomp[0] input is selected
 *  0b010000..ADC0_tcomp[1] input is selected
 *  0b010001..ADC0_tcomp[2] input is selected
 *  0b010010..ADC0_tcomp[3] input is selected
 *  0b010011..ADC1_tcomp[0] input is selected
 *  0b010100..ADC1_tcomp[1] input is selected
 *  0b010101..ADC1_tcomp[2] input is selected
 *  0b010110..ADC1_tcomp[3] input is selected
 *  0b010111..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011000..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011001..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011010..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011011..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b011100..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b011101..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011110..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b011111..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b100000..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b100001..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b100010..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b100011..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b100100..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b100101..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b100110..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b100111..EVTG_OUT0A input is selected
 *  0b101000..EVTG_OUT0B input is selected
 *  0b101001..EVTG_OUT1A input is selected
 *  0b101010..EVTG_OUT1B input is selected
 *  0b101011..EVTG_OUT2A input is selected
 *  0b101100..EVTG_OUT2B input is selected
 *  0b101101..EVTG_OUT3A input is selected
 *  0b101110..EVTG_OUT3B input is selected
 *  0b101111..TRIG_IN0 input is selected
 *  0b110000..TRIG_IN1 input is selected
 *  0b110001..TRIG_IN2 input is selected
 *  0b110010..TRIG_IN3 input is selected
 *  0b110011..FlexIO CH4 input is selected
 *  0b110100..FlexIO CH5 input is selected
 *  0b110101..FlexIO CH6 input is selected
 *  0b110110..FlexIO CH7 input is selected
 */
#define INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_INP(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_INP_SHIFT)) & INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG */
#define INPUTMUX_OPAMPN_TRIG_OPAMP_TRIG_COUNT    (3U)

/*! @name FLEXCOMM0_TRIG - LP_FLEXCOMM0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM0_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM0_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM0 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT6 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT6 input is selected
 *  0b000101..SCT_OUT7 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..CTIMER4_MAT0 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM0_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM0_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM0_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM1_TRIG - LP_FLEXCOMM1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM1_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM1_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM1 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT6 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT6 input is selected
 *  0b000101..SCT_OUT7 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..CTIMER4_MAT0 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM1_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM1_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM1_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM2_TRIG - LP_FLEXCOMM2 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM2_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM2_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM2 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT6 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT8 input is selected
 *  0b000101..SCT_OUT9 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER3_MAT1 input is selected
 *  0b001010..CTIMER4_MAT1 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM2_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM2_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM2_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM3_TRIG - LP_FLEXCOMM3 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM3_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM3_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM3 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT5 input is selected
 *  0b000100..SCT_OUT8 input is selected
 *  0b000101..SCT_OUT9 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT1 input is selected
 *  0b001001..CTIMER3_MAT1 input is selected
 *  0b001010..CTIMER4_MAT1 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM3_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM3_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM3_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM4_TRIG - LP_FLEXCOMM4 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM4_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM4_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM4 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..SCT_OUT2 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT2 input is selected
 *  0b001001..CTIMER3_MAT2 input is selected
 *  0b001010..CTIMER4_MAT2 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM4_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM4_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM4_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM5_TRIG - LP_FLEXCOMM5 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM5_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM5_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM5 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT1 input is selected
 *  0b000101..SCT_OUT2 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT2 input is selected
 *  0b001001..CTIMER3_MAT2 input is selected
 *  0b001010..CTIMER4_MAT2 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM5_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM5_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM5_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM6_TRIG - LP_FLEXCOMM6 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM6_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM6_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM6 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..SCT_OUT4 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT3 input is selected
 *  0b001001..CTIMER3_MAT3 input is selected
 *  0b001010..CTIMER4_MAT3 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM6_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM6_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM6_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM7_TRIG - LP_FLEXCOMM7 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM7_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM7_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM7 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..SCT_OUT4 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT3 input is selected
 *  0b001001..CTIMER3_MAT3 input is selected
 *  0b001010..CTIMER4_MAT3 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM7_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM7_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM7_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM8_TRIG - LP_FLEXCOMM8 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM8_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM8_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM8 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..SCT_OUT4 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT3 input is selected
 *  0b001001..CTIMER3_MAT3 input is selected
 *  0b001010..CTIMER4_MAT3 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM8_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM8_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM8_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXCOMM9_TRIG - LP_FLEXCOMM9 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXCOMM9_TRIG_INP_MASK         (0x3FU)
#define INPUTMUX_FLEXCOMM9_TRIG_INP_SHIFT        (0U)
/*! INP - LP_FLEXCOMM9 trigger input connections
 *  0b000000..PINT PIN_INT4 input is selected
 *  0b000001..PINT PIN_INT5 input is selected
 *  0b000010..PINT PIN_INT7 input is selected
 *  0b000011..SCT_OUT0 input is selected
 *  0b000100..SCT_OUT3 input is selected
 *  0b000101..SCT_OUT4 input is selected
 *  0b000110..CTIMER0_MAT1 input is selected
 *  0b000111..CTIMER1_MAT1 input is selected
 *  0b001000..CTIMER2_MAT0 input is selected
 *  0b001001..CTIMER3_MAT0 input is selected
 *  0b001010..CTIMER4_MAT0 input is selected
 *  0b001011..LPTMR0 input is selected
 *  0b001100..LPTMR1 input is selected
 *  0b001101..Reserved
 *  0b001110..PINT GPIO_INT_BMAT input is selected
 *  0b001111..CMP0_OUT input is selected
 *  0b010000..CMP1_OUT input is selected
 *  0b010001..CMP2_OUT input is selected
 *  0b010010..EVTG_OUT0A input is selected
 *  0b010011..EVTG_OUT0B input is selected
 *  0b010100..EVTG_OUT1A input is selected
 *  0b010101..EVTG_OUT1B input is selected
 *  0b010110..EVTG_OUT2A input is selected
 *  0b010111..EVTG_OUT2B input is selected
 *  0b011000..EVTG_OUT3A input is selected
 *  0b011001..EVTG_OUT3B input is selected
 *  0b011010..TRIG_IN0 input is selected
 *  0b011011..TRIG_IN1 input is selected
 *  0b011100..TRIG_IN2 input is selected
 *  0b011101..TRIG_IN3 input is selected
 *  0b011110..TRIG_IN4 input is selected
 *  0b011111..TRIG_IN10 input is selected
 *  0b100000..TRIG_IN11 input is selected
 *  0b100001..FlexIO CH4 input is selected
 *  0b100010..FlexIO CH5 input is selected
 *  0b100011..FlexIO CH6 input is selected
 *  0b100100..FlexIO CH7 input is selected
 *  0b100101..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b100111..GPIO2 Pin Event Trig 1 input is selected
 *  0b101000..GPIO3 Pin Event Trig 0 input is selected
 *  0b101001..GPIO3 Pin Event Trig 1 input is selected
 *  0b101010..WUU input is selected
 */
#define INPUTMUX_FLEXCOMM9_TRIG_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXCOMM9_TRIG_INP_SHIFT)) & INPUTMUX_FLEXCOMM9_TRIG_INP_MASK)
/*! @} */

/*! @name FLEXIO_TRIGN_FLEXIO_TRIG - FlexIO Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_MASK (0x7FU)
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_SHIFT (0U)
/*! INP - Input number for FlexIO0.
 *  0b0000000..PINT PIN_INT4 input is selected
 *  0b0000001..PINT PIN_INT5 input is selected
 *  0b0000010..PINT PIN_INT6 input is selected
 *  0b0000011..PINT PIN_INT7 input is selected
 *  0b0000100..SCT_OUT5 input is selected
 *  0b0000101..SCT_OUT6 input is selected
 *  0b0000110..SCT_OUT7 input is selected
 *  0b0000111..SCT_OUT8 input is selected
 *  0b0001000..SCT_OUT9 input is selected
 *  0b0001001..T0_MAT1 input is selected
 *  0b0001010..T1_MAT1 input is selected
 *  0b0001011..T2_MAT1 input is selected
 *  0b0001100..T3_MAT1 input is selected
 *  0b0001101..T4_MAT1 input is selected
 *  0b0001110..LPTMR0 input is selected
 *  0b0001111..LPTMR1 input is selected
 *  0b0010000..Reserved
 *  0b0010001..PINT GPIO_INT_BMAT input is selected
 *  0b0010010..ADC0_tcomp[0] input is selected
 *  0b0010011..ADC0_tcomp[1] input is selected
 *  0b0010100..ADC0_tcomp[2] input is selected
 *  0b0010101..ADC0_tcomp[3] input is selected
 *  0b0010110..ADC1_tcomp[0] input is selected
 *  0b0010111..ADC1_tcomp[1] input is selected
 *  0b0011000..ADC1_tcomp[2] input is selected
 *  0b0011001..ADC1_tcomp[3] input is selected
 *  0b0011010..CMP0_OUT input is selected
 *  0b0011011..CMP1_OUT input is selected
 *  0b0011100..CMP2_OUT input is selected
 *  0b0011101..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0011110..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0100000..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0100010..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100011..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0100100..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100101..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b0100110..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100111..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b0101000..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0101001..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b0101010..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0101011..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b0101100..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b0101101..EVTG_OUT0A input is selected
 *  0b0101110..EVTG_OUT0B input is selected
 *  0b0101111..EVTG_OUT1A input is selected
 *  0b0110000..EVTG_OUT1B input is selected
 *  0b0110001..EVTG_OUT2A input is selected
 *  0b0110010..EVTG_OUT2B input is selected
 *  0b0110011..EVTG_OUT3A input is selected
 *  0b0110100..EVTG_OUT3B input is selected
 *  0b0110101..TRIG_IN0 input is selected
 *  0b0110110..TRIG_IN1 input is selected
 *  0b0110111..TRIG_IN2 input is selected
 *  0b0111000..TRIG_IN3 input is selected
 *  0b0111001..TRIG_IN4 input is selected
 *  0b0111010..SINC Filter CH0 Conversion Complete input is selected
 *  0b0111011..SINC Filter CH1 Conversion Complete input is selected
 *  0b0111100..SINC Filter CH2 Conversion Complete input is selected
 *  0b0111101..SINC Filter CH3 Conversion Complete input is selected
 *  0b0111110..SINC Filter CH4 Conversion Complete input is selected
 *  0b0111111..LP_FLEXCOMM0 trig 0 (lpuart_trg_txword) input is selected
 *  0b1000000..LP_FLEXCOMM0 trig 1 (lpuart_trg_rxword) input is selected
 *  0b1000001..LP_FLEXCOMM0 trig 2 (lpuart_trg_rxidle) input is selected
 *  0b1000010..LP_FLEXCOMM1 trig 0 input is selected
 *  0b1000011..LP_FLEXCOMM1 trig 1 input is selected
 *  0b1000100..LP_FLEXCOMM1 trig 2 input is selected
 *  0b1000101..LP_FLEXCOMM2 trig 0 input is selected
 *  0b1000110..LP_FLEXCOMM2 trig 1 input is selected
 *  0b1000111..LP_FLEXCOMM2 trig 2 input is selected
 *  0b1001000..LP_FLEXCOMM3 trig 0 input is selected
 *  0b1001001..LP_FLEXCOMM3 trig 1 input is selected
 *  0b1001010..LP_FLEXCOMM3 trig 2 input is selected
 *  0b1001011..LP_FLEXCOMM3 trig 3 input is selected
 *  0b1001100..WUU input is selected
 */
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_SHIFT)) & INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG */
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_COUNT  (8U)

/*! @name DMA0_REQ_ENABLE0 - DMA0 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ1_EN0_MASK  (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ1_EN0_SHIFT (1U)
/*! REQ1_EN0 - This register is used to enable and disable FLEXSPI0 receive event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ1_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ1_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ1_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ2_EN0_MASK  (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ2_EN0_SHIFT (2U)
/*! REQ2_EN0 - This register is used to enable and disable FLEXSPI0 transmit event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ2_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ2_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ2_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ3_EN0_MASK  (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ3_EN0_SHIFT (3U)
/*! REQ3_EN0 - This register is used to enable and disable PINT0 INT0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ3_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ3_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ3_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ4_EN0_MASK  (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ4_EN0_SHIFT (4U)
/*! REQ4_EN0 - This register is used to enable and disable PINT0 INT1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ4_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ4_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ4_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ5_EN0_MASK  (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ5_EN0_SHIFT (5U)
/*! REQ5_EN0 - This register is used to enable and disable PINT0 INT2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ5_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ5_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ5_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ6_EN0_MASK  (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ6_EN0_SHIFT (6U)
/*! REQ6_EN0 - This register is used to enable and disable PINT0 INT3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ6_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ6_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ6_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ7_EN0_MASK  (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ7_EN0_SHIFT (7U)
/*! REQ7_EN0 - This register is used to enable and disable CTIMER0 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ7_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ7_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ7_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ8_EN0_MASK  (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ8_EN0_SHIFT (8U)
/*! REQ8_EN0 - This register is used to enable and disable CTIMER0 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ8_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ8_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ8_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ9_EN0_MASK  (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ9_EN0_SHIFT (9U)
/*! REQ9_EN0 - This register is used to enable and disable CTIMER1 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ9_EN0(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ9_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ9_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ10_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ10_EN0_SHIFT (10U)
/*! REQ10_EN0 - This register is used to enable and disable CTIMER1 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ10_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ10_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ10_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ11_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ11_EN0_SHIFT (11U)
/*! REQ11_EN0 - This register is used to enable and disable CTIMER2 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ11_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ11_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ11_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ12_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ12_EN0_SHIFT (12U)
/*! REQ12_EN0 - This register is used to enable and disable CTIMER2 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ12_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ12_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ12_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ13_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ13_EN0_SHIFT (13U)
/*! REQ13_EN0 - This register is used to enable and disable CTIMER3 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ13_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ13_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ13_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ14_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ14_EN0_SHIFT (14U)
/*! REQ14_EN0 - This register is used to enable and disable CTIMER3 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ14_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ14_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ14_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ15_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ15_EN0_SHIFT (15U)
/*! REQ15_EN0 - This register is used to enable and disable CTIMER4 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ15_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ15_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ15_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ16_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ16_EN0_SHIFT (16U)
/*! REQ16_EN0 - This register is used to enable and disable CTIMER4 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ16_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ16_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ16_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ17_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ17_EN0_SHIFT (17U)
/*! REQ17_EN0 - This register is used to enable and disable WUU0 wake up event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ17_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ17_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ17_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ18_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ18_EN0_SHIFT (18U)
/*! REQ18_EN0 - This register is used to enable and disable MICFIL0 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ18_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ18_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ18_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ19_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ19_EN0_SHIFT (19U)
/*! REQ19_EN0 - This register is used to enable and disable SCT0 DMA0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ19_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ19_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ19_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ20_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ20_EN0_SHIFT (20U)
/*! REQ20_EN0 - This register is used to enable and disable SCT0 DMA1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ20_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ20_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ20_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ21_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ21_EN0_SHIFT (21U)
/*! REQ21_EN0 - This register is used to enable and disable ADC0 FIFO A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ21_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ21_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ21_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ22_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ22_EN0_SHIFT (22U)
/*! REQ22_EN0 - This register is used to enable and disable ADC0 FIFO B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ22_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ22_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ22_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ23_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ23_EN0_SHIFT (23U)
/*! REQ23_EN0 - This register is used to enable and disable ADC1 FIFO A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ23_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ23_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ23_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ24_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ24_EN0_SHIFT (24U)
/*! REQ24_EN0 - This register is used to enable and disable ADC1 FIFO B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ24_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ24_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ24_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ25_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ25_EN0_SHIFT (25U)
/*! REQ25_EN0 - This register is used to enable and disable DAC0 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ25_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ25_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ25_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ26_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ26_EN0_SHIFT (26U)
/*! REQ26_EN0 - This register is used to enable and disable DAC1 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ26_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ26_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ26_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ27_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ27_EN0_SHIFT (27U)
/*! REQ27_EN0 - This register is used to enable and disable DAC2 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ27_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ27_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ27_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ28_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ28_EN0_SHIFT (28U)
/*! REQ28_EN0 - This register is used to enable and disable CMP0 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ28_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ28_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ28_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ29_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ29_EN0_SHIFT (29U)
/*! REQ29_EN0 - This register is used to enable and disable CMP1 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ29_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ29_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ29_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ30_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ30_EN0_SHIFT (30U)
/*! REQ30_EN0 - This register is used to enable and disable CMP2 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ30_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ30_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ30_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_REQ31_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ31_EN0_SHIFT (31U)
/*! REQ31_EN0 - This register is used to enable and disable EVTG0 OUT0A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE0_REQ31_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_REQ31_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_REQ31_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE0_SET - DMA0 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ1_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ1_EN0_SHIFT (1U)
/*! REQ1_EN0 - Writing a 1 to REQ1_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ1_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ1_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ1_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ2_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ2_EN0_SHIFT (2U)
/*! REQ2_EN0 - Writing a 1 to REQ2_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ2_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ2_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ2_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ3_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ3_EN0_SHIFT (3U)
/*! REQ3_EN0 - Writing a 1 to REQ3_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ3_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ3_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ3_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ4_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ4_EN0_SHIFT (4U)
/*! REQ4_EN0 - Writing a 1 to REQ4_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ4_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ4_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ4_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ5_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ5_EN0_SHIFT (5U)
/*! REQ5_EN0 - Writing a 1 to REQ5_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ5_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ5_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ5_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ6_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ6_EN0_SHIFT (6U)
/*! REQ6_EN0 - Writing a 1 to REQ6_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ6_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ6_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ6_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ7_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ7_EN0_SHIFT (7U)
/*! REQ7_EN0 - Writing a 1 to REQ7_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ7_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ7_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ7_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ8_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ8_EN0_SHIFT (8U)
/*! REQ8_EN0 - Writing a 1 to REQ8_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ8_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ8_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ8_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ9_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ9_EN0_SHIFT (9U)
/*! REQ9_EN0 - Writing a 1 to REQ9_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ9_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ9_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ9_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ10_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ10_EN0_SHIFT (10U)
/*! REQ10_EN0 - Writing a 1 to REQ10_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ10_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ10_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ10_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ11_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ11_EN0_SHIFT (11U)
/*! REQ11_EN0 - Writing a 1 to REQ11_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ11_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ11_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ11_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ12_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ12_EN0_SHIFT (12U)
/*! REQ12_EN0 - Writing a 1 to REQ12_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ12_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ12_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ12_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ13_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ13_EN0_SHIFT (13U)
/*! REQ13_EN0 - Writing a 1 to REQ13_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ13_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ13_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ13_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ14_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ14_EN0_SHIFT (14U)
/*! REQ14_EN0 - Writing a 1 to REQ14_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ14_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ14_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ14_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ15_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ15_EN0_SHIFT (15U)
/*! REQ15_EN0 - Writing a 1 to REQ15_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ15_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ15_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ15_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ16_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ16_EN0_SHIFT (16U)
/*! REQ16_EN0 - Writing a 1 to REQ16_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ16_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ16_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ16_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ17_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ17_EN0_SHIFT (17U)
/*! REQ17_EN0 - Writing a 1 to REQ17_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ17_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ17_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ17_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ18_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ18_EN0_SHIFT (18U)
/*! REQ18_EN0 - Writing a 1 to REQ18_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ18_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ18_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ18_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ19_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ19_EN0_SHIFT (19U)
/*! REQ19_EN0 - Writing a 1 to REQ19_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ19_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ19_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ19_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ20_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ20_EN0_SHIFT (20U)
/*! REQ20_EN0 - Writing a 1 to REQ20_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ20_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ20_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ20_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ21_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ21_EN0_SHIFT (21U)
/*! REQ21_EN0 - Writing a 1 to REQ21_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ21_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ21_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ21_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ22_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ22_EN0_SHIFT (22U)
/*! REQ22_EN0 - Writing a 1 to REQ22_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ22_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ22_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ22_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ23_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ23_EN0_SHIFT (23U)
/*! REQ23_EN0 - Writing a 1 to REQ23_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ23_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ23_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ23_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ24_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ24_EN0_SHIFT (24U)
/*! REQ24_EN0 - Writing a 1 to REQ24_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ24_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ24_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ24_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ25_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ25_EN0_SHIFT (25U)
/*! REQ25_EN0 - Writing a 1 to REQ25_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ25_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ25_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ25_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ26_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ26_EN0_SHIFT (26U)
/*! REQ26_EN0 - Writing a 1 to REQ26_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ26_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ26_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ26_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ27_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ27_EN0_SHIFT (27U)
/*! REQ27_EN0 - Writing a 1 to REQ27_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ27_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ27_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ27_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ28_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ28_EN0_SHIFT (28U)
/*! REQ28_EN0 - Writing a 1 to REQ28_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ28_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ28_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ28_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ29_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ29_EN0_SHIFT (29U)
/*! REQ29_EN0 - Writing a 1 to REQ29_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ29_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ29_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ29_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ30_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ30_EN0_SHIFT (30U)
/*! REQ30_EN0 - Writing a 1 to REQ30_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ30_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ30_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ30_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ31_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ31_EN0_SHIFT (31U)
/*! REQ31_EN0 - Writing a 1 to REQ31_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ31_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ31_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_SET_REQ31_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE0_CLR - DMA0 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ1_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ1_EN0_SHIFT (1U)
/*! REQ1_EN0 - Writing a 1 to REQ1_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ1_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ1_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ1_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ2_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ2_EN0_SHIFT (2U)
/*! REQ2_EN0 - Writing a 1 to REQ2_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ2_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ2_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ2_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ3_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ3_EN0_SHIFT (3U)
/*! REQ3_EN0 - Writing a 1 to REQ3_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ3_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ3_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ3_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ4_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ4_EN0_SHIFT (4U)
/*! REQ4_EN0 - Writing a 1 to REQ4_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ4_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ4_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ4_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ5_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ5_EN0_SHIFT (5U)
/*! REQ5_EN0 - Writing a 1 to REQ5_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ5_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ5_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ5_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ6_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ6_EN0_SHIFT (6U)
/*! REQ6_EN0 - Writing a 1 to REQ6_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ6_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ6_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ6_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ7_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ7_EN0_SHIFT (7U)
/*! REQ7_EN0 - Writing a 1 to REQ7_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ7_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ7_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ7_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ8_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ8_EN0_SHIFT (8U)
/*! REQ8_EN0 - Writing a 1 to REQ8_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ8_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ8_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ8_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ9_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ9_EN0_SHIFT (9U)
/*! REQ9_EN0 - Writing a 1 to REQ9_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ9_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ9_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ9_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ10_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ10_EN0_SHIFT (10U)
/*! REQ10_EN0 - Writing a 1 to REQ10_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ10_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ10_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ10_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ11_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ11_EN0_SHIFT (11U)
/*! REQ11_EN0 - Writing a 1 to REQ11_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ11_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ11_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ11_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ12_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ12_EN0_SHIFT (12U)
/*! REQ12_EN0 - Writing a 1 to REQ12_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ12_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ12_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ12_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ13_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ13_EN0_SHIFT (13U)
/*! REQ13_EN0 - Writing a 1 to REQ13_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ13_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ13_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ13_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ14_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ14_EN0_SHIFT (14U)
/*! REQ14_EN0 - Writing a 1 to REQ14_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ14_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ14_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ14_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ15_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ15_EN0_SHIFT (15U)
/*! REQ15_EN0 - Writing a 1 to REQ15_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ15_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ15_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ15_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ16_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ16_EN0_SHIFT (16U)
/*! REQ16_EN0 - Writing a 1 to REQ16_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ16_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ16_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ16_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ17_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ17_EN0_SHIFT (17U)
/*! REQ17_EN0 - Writing a 1 to REQ17_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ17_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ17_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ17_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ18_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ18_EN0_SHIFT (18U)
/*! REQ18_EN0 - Writing a 1 to REQ18_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ18_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ18_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ18_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ19_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ19_EN0_SHIFT (19U)
/*! REQ19_EN0 - Writing a 1 to REQ19_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ19_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ19_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ19_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ20_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ20_EN0_SHIFT (20U)
/*! REQ20_EN0 - Writing a 1 to REQ20_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ20_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ20_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ20_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ21_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ21_EN0_SHIFT (21U)
/*! REQ21_EN0 - Writing a 1 to REQ21_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ21_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ21_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ21_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ22_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ22_EN0_SHIFT (22U)
/*! REQ22_EN0 - Writing a 1 to REQ22_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ22_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ22_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ22_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ23_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ23_EN0_SHIFT (23U)
/*! REQ23_EN0 - Writing a 1 to REQ23_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ23_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ23_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ23_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ24_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ24_EN0_SHIFT (24U)
/*! REQ24_EN0 - Writing a 1 to REQ24_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ24_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ24_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ24_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ25_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ25_EN0_SHIFT (25U)
/*! REQ25_EN0 - Writing a 1 to REQ25_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ25_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ25_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ25_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ26_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ26_EN0_SHIFT (26U)
/*! REQ26_EN0 - Writing a 1 to REQ26_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ26_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ26_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ26_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ27_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ27_EN0_SHIFT (27U)
/*! REQ27_EN0 - Writing a 1 to REQ27_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ27_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ27_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ27_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ28_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ28_EN0_SHIFT (28U)
/*! REQ28_EN0 - Writing a 1 to REQ28_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ28_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ28_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ28_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ29_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ29_EN0_SHIFT (29U)
/*! REQ29_EN0 - Writing a 1 to REQ29_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ29_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ29_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ29_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ30_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ30_EN0_SHIFT (30U)
/*! REQ30_EN0 - Writing a 1 to REQ30_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ30_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ30_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ30_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ31_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ31_EN0_SHIFT (31U)
/*! REQ31_EN0 - Writing a 1 to REQ31_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ31_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ31_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_CLR_REQ31_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE0_TOG - DMA0 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ1_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ1_EN0_SHIFT (1U)
/*! REQ1_EN0 - Writing a 1 to REQ1_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ1_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ1_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ1_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ2_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ2_EN0_SHIFT (2U)
/*! REQ2_EN0 - Writing a 1 to REQ2_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ2_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ2_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ2_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ3_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ3_EN0_SHIFT (3U)
/*! REQ3_EN0 - Writing a 1 to REQ3_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ3_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ3_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ3_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ4_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ4_EN0_SHIFT (4U)
/*! REQ4_EN0 - Writing a 1 to REQ4_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ4_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ4_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ4_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ5_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ5_EN0_SHIFT (5U)
/*! REQ5_EN0 - Writing a 1 to REQ5_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ5_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ5_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ5_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ6_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ6_EN0_SHIFT (6U)
/*! REQ6_EN0 - Writing a 1 to REQ6_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ6_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ6_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ6_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ7_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ7_EN0_SHIFT (7U)
/*! REQ7_EN0 - Writing a 1 to REQ7_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ7_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ7_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ7_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ8_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ8_EN0_SHIFT (8U)
/*! REQ8_EN0 - Writing a 1 to REQ8_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ8_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ8_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ8_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ9_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ9_EN0_SHIFT (9U)
/*! REQ9_EN0 - Writing a 1 to RE9_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ9_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ9_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ9_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ10_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ10_EN0_SHIFT (10U)
/*! REQ10_EN0 - Writing a 1 to REQ10_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ10_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ10_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ10_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ11_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ11_EN0_SHIFT (11U)
/*! REQ11_EN0 - Writing a 1 to REQ11_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ11_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ11_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ11_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ12_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ12_EN0_SHIFT (12U)
/*! REQ12_EN0 - Writing a 1 to REQ12_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ12_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ12_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ12_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ13_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ13_EN0_SHIFT (13U)
/*! REQ13_EN0 - Writing a 1 to REQ13_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ13_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ13_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ13_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ14_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ14_EN0_SHIFT (14U)
/*! REQ14_EN0 - Writing a 1 to REQ14_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ14_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ14_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ14_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ15_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ15_EN0_SHIFT (15U)
/*! REQ15_EN0 - Writing a 1 to REQ15_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ15_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ15_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ15_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ16_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ16_EN0_SHIFT (16U)
/*! REQ16_EN0 - Writing a 1 to REQ16_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ16_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ16_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ16_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ17_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ17_EN0_SHIFT (17U)
/*! REQ17_EN0 - Writing a 1 to REQ17_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ17_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ17_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ17_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ18_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ18_EN0_SHIFT (18U)
/*! REQ18_EN0 - Writing a 1 to REQ18_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ18_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ18_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ18_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ19_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ19_EN0_SHIFT (19U)
/*! REQ19_EN0 - Writing a 1 to REQ19_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ19_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ19_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ19_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ20_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ20_EN0_SHIFT (20U)
/*! REQ20_EN0 - Writing a 1 to REQ20_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ20_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ20_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ20_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ21_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ21_EN0_SHIFT (21U)
/*! REQ21_EN0 - Writing a 1 to REQ21_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ21_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ21_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ21_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ22_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ22_EN0_SHIFT (22U)
/*! REQ22_EN0 - Writing a 1 to REQ22_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ22_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ22_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ22_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ23_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ23_EN0_SHIFT (23U)
/*! REQ23_EN0 - Writing a 1 to REQ23_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ23_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ23_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ23_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ24_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ24_EN0_SHIFT (24U)
/*! REQ24_EN0 - Writing a 1 to REQ24_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ24_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ24_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ24_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ25_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ25_EN0_SHIFT (25U)
/*! REQ25_EN0 - Writing a 1 to REQ25_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ25_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ25_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ25_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ26_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ26_EN0_SHIFT (26U)
/*! REQ26_EN0 - Writing a 1 to REQ26_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ26_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ26_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ26_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ27_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ27_EN0_SHIFT (27U)
/*! REQ27_EN0 - Writing a 1 to REQ27_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ27_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ27_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ27_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ28_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ28_EN0_SHIFT (28U)
/*! REQ28_EN0 - Writing a 1 to REQ28_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ28_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ28_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ28_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ29_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ29_EN0_SHIFT (29U)
/*! REQ29_EN0 - Writing a 1 to REQ29_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ29_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ29_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ29_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ30_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ30_EN0_SHIFT (30U)
/*! REQ30_EN0 - Writing a 1 to REQ30_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ30_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ30_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ30_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ31_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ31_EN0_SHIFT (31U)
/*! REQ31_EN0 - Writing a 1 to REQ31_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE0. */
#define INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ31_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ31_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE0_TOG_REQ31_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE1 - DMA0 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ32_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ32_EN0_SHIFT (0U)
/*! REQ32_EN0 - This register is used to enable and disable EVTG0 OUT0B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ32_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ32_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ32_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ33_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ33_EN0_SHIFT (1U)
/*! REQ33_EN0 - This register is used to enable and disable EVTG0 OUT1A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ33_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ33_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ33_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ34_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ34_EN0_SHIFT (2U)
/*! REQ34_EN0 - This register is used to enable and disable EVTG0 OUT1B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ34_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ34_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ34_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ35_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ35_EN0_SHIFT (3U)
/*! REQ35_EN0 - This register is used to enable and disable EVTG0 OUT2A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ35_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ35_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ35_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ36_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ36_EN0_SHIFT (4U)
/*! REQ36_EN0 - This register is used to enable and disable EVTG0 OUT2B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ36_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ36_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ36_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ37_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ37_EN0_SHIFT (5U)
/*! REQ37_EN0 - This register is used to enable and disable EVTG0 OUT3A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ37_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ37_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ37_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ38_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ38_EN0_SHIFT (6U)
/*! REQ38_EN0 - This register is used to enable and disable EVTG0 OUT3B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ38_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ38_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ38_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ39_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ39_EN0_SHIFT (7U)
/*! REQ39_EN0 - This register is used to enable and disable PWM0 Req_capt0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ39_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ39_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ39_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ40_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ40_EN0_SHIFT (8U)
/*! REQ40_EN0 - This register is used to enable and disable PWM0 Req_capt1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ40_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ40_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ40_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ41_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ41_EN0_SHIFT (9U)
/*! REQ41_EN0 - This register is used to enable and disable PWM0 Req_capt2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ41_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ41_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ41_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ42_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ42_EN0_SHIFT (10U)
/*! REQ42_EN0 - This register is used to enable and disable PWM0 Req_capt3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ42_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ42_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ42_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ43_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ43_EN0_SHIFT (11U)
/*! REQ43_EN0 - This register is used to enable and disable PWM0 Req_val0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ43_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ43_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ43_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ44_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ44_EN0_SHIFT (12U)
/*! REQ44_EN0 - This register is used to enable and disable PWM0 Req_val1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ44_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ44_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ44_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ45_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ45_EN0_SHIFT (13U)
/*! REQ45_EN0 - This register is used to enable and disable PWM0 Req_val2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ45_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ45_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ45_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ46_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ46_EN0_SHIFT (14U)
/*! REQ46_EN0 - This register is used to enable and disable PWM0 Req_val3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ46_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ46_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ46_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ47_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ47_EN0_SHIFT (15U)
/*! REQ47_EN0 - This register is used to enable and disable PWM1 Req_capt0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ47_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ47_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ47_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ48_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ48_EN0_SHIFT (16U)
/*! REQ48_EN0 - This register is used to enable and disable PWM1 Req_capt1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ48_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ48_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ48_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ49_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ49_EN0_SHIFT (17U)
/*! REQ49_EN0 - This register is used to enable and disable PWM1 Req_capt2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ49_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ49_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ49_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ50_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ50_EN0_SHIFT (18U)
/*! REQ50_EN0 - This register is used to enable and disable PWM1 Req_capt3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ50_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ50_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ50_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ51_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ51_EN0_SHIFT (19U)
/*! REQ51_EN0 - This register is used to enable and disable PWM1 Req_val0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ51_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ51_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ51_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ52_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ52_EN0_SHIFT (20U)
/*! REQ52_EN0 - This register is used to enable and disable PWM1 Req_val1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ52_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ52_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ52_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ53_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ53_EN0_SHIFT (21U)
/*! REQ53_EN0 - This register is used to enable and disable PWM1 Req_val2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ53_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ53_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ53_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ54_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ54_EN0_SHIFT (22U)
/*! REQ54_EN0 - This register is used to enable and disable PWM1 Req_val3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ54_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ54_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ54_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ57_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ57_EN0_SHIFT (25U)
/*! REQ57_EN0 - This register is used to enable and disable LPTMR0 counter match event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ57_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ57_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ57_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ58_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ58_EN0_SHIFT (26U)
/*! REQ58_EN0 - This register is used to enable and disable LPTMR1 counter match event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ58_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ58_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ58_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ59_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ59_EN0_SHIFT (27U)
/*! REQ59_EN0 - This register is used to enable and disable CAN0 DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ59_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ59_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ59_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ60_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ60_EN0_SHIFT (28U)
/*! REQ60_EN0 - This register is used to enable and disable CAN1 DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ60_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ60_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ60_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ61_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ61_EN0_SHIFT (29U)
/*! REQ61_EN0 - This register is used to enable and disable FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ61_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ61_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ61_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ62_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ62_EN0_SHIFT (30U)
/*! REQ62_EN0 - This register is used to enable and disable FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ62_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ62_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ62_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_REQ63_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ63_EN0_SHIFT (31U)
/*! REQ63_EN0 - This register is used to enable and disable FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE1_REQ63_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_REQ63_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_REQ63_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE1_SET - DMA0 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ32_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ32_EN0_SHIFT (0U)
/*! REQ32_EN0 - Writing a 1 to REQ32_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ32_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ32_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ32_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ33_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ33_EN0_SHIFT (1U)
/*! REQ33_EN0 - Writing a 1 to REQ33_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ33_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ33_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ33_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ34_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ34_EN0_SHIFT (2U)
/*! REQ34_EN0 - Writing a 1 to REQ34_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ34_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ34_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ34_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ35_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ35_EN0_SHIFT (3U)
/*! REQ35_EN0 - Writing a 1 to REQ35_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ35_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ35_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ35_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ36_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ36_EN0_SHIFT (4U)
/*! REQ36_EN0 - Writing a 1 to REQ36_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ36_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ36_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ36_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ37_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ37_EN0_SHIFT (5U)
/*! REQ37_EN0 - Writing a 1 to REQ37_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ37_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ37_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ37_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ38_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ38_EN0_SHIFT (6U)
/*! REQ38_EN0 - Writing a 1 to REQ38_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ38_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ38_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ38_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ39_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ39_EN0_SHIFT (7U)
/*! REQ39_EN0 - Writing a 1 to REQ39_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ39_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ39_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ39_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ40_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ40_EN0_SHIFT (8U)
/*! REQ40_EN0 - Writing a 1 to REQ40_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ40_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ40_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ40_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ41_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ41_EN0_SHIFT (9U)
/*! REQ41_EN0 - Writing a 1 to REQ41_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ41_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ41_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ41_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ42_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ42_EN0_SHIFT (10U)
/*! REQ42_EN0 - Writing a 1 to REQ42_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ42_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ42_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ42_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ43_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ43_EN0_SHIFT (11U)
/*! REQ43_EN0 - Writing a 1 to REQ43_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ43_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ43_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ43_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ44_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ44_EN0_SHIFT (12U)
/*! REQ44_EN0 - Writing a 1 to REQ44_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ44_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ44_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ44_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ45_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ45_EN0_SHIFT (13U)
/*! REQ45_EN0 - Writing a 1 to REQ45_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ45_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ45_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ45_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ46_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ46_EN0_SHIFT (14U)
/*! REQ46_EN0 - Writing a 1 to REQ46_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ46_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ46_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ46_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ47_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ47_EN0_SHIFT (15U)
/*! REQ47_EN0 - Writing a 1 to REQ47_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ47_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ47_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ47_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ48_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ48_EN0_SHIFT (16U)
/*! REQ48_EN0 - Writing a 1 to REQ48_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ48_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ48_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ48_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ49_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ49_EN0_SHIFT (17U)
/*! REQ49_EN0 - Writing a 1 to REQ49_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ49_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ49_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ49_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ50_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ50_EN0_SHIFT (18U)
/*! REQ50_EN0 - Writing a 1 to REQ50_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ50_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ50_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ50_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ51_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ51_EN0_SHIFT (19U)
/*! REQ51_EN0 - Writing a 1 to REQ51_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ51_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ51_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ51_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ52_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ52_EN0_SHIFT (20U)
/*! REQ52_EN0 - Writing a 1 to REQ52_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ52_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ52_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ52_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ53_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ53_EN0_SHIFT (21U)
/*! REQ53_EN0 - Writing a 1 to REQ53_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ53_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ53_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ53_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ54_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ54_EN0_SHIFT (22U)
/*! REQ54_EN0 - Writing a 1 to REQ54_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ54_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ54_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ54_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ57_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ57_EN0_SHIFT (25U)
/*! REQ57_EN0 - Writing a 1 to REQ57_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ57_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ57_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ57_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ58_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ58_EN0_SHIFT (26U)
/*! REQ58_EN0 - Writing a 1 to REQ58_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ58_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ58_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ58_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ59_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ59_EN0_SHIFT (27U)
/*! REQ59_EN0 - Writing a 1 to REQ59_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ59_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ59_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ59_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ60_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ60_EN0_SHIFT (28U)
/*! REQ60_EN0 - Writing a 1 to REQ60_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ60_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ60_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ60_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ61_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ61_EN0_SHIFT (29U)
/*! REQ61_EN0 - Writing a 1 to REQ61_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ61_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ61_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ61_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ62_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ62_EN0_SHIFT (30U)
/*! REQ62_EN0 - Writing a 1 to REQ62_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ62_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ62_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ62_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ63_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ63_EN0_SHIFT (31U)
/*! REQ63_EN0 - Writing a 1 to REQ63_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ63_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ63_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_SET_REQ63_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE1_CLR - DMA0 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ32_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ32_EN0_SHIFT (0U)
/*! REQ32_EN0 - Writing a 1 to REQ32_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ32_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ32_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ32_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ33_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ33_EN0_SHIFT (1U)
/*! REQ33_EN0 - Writing a 1 to REQ33_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ33_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ33_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ33_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ34_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ34_EN0_SHIFT (2U)
/*! REQ34_EN0 - Writing a 1 to REQ34_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ34_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ34_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ34_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ35_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ35_EN0_SHIFT (3U)
/*! REQ35_EN0 - Writing a 1 to REQ35_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ35_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ35_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ35_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ36_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ36_EN0_SHIFT (4U)
/*! REQ36_EN0 - Writing a 1 to REQ36_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ36_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ36_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ36_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ37_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ37_EN0_SHIFT (5U)
/*! REQ37_EN0 - Writing a 1 to REQ37_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ37_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ37_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ37_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ38_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ38_EN0_SHIFT (6U)
/*! REQ38_EN0 - Writing a 1 to REQ38_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ38_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ38_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ38_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ39_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ39_EN0_SHIFT (7U)
/*! REQ39_EN0 - Writing a 1 to REQ39_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ39_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ39_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ39_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ40_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ40_EN0_SHIFT (8U)
/*! REQ40_EN0 - Writing a 1 to REQ40_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ40_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ40_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ40_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ41_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ41_EN0_SHIFT (9U)
/*! REQ41_EN0 - Writing a 1 to REQ41_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ41_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ41_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ41_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ42_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ42_EN0_SHIFT (10U)
/*! REQ42_EN0 - Writing a 1 to REQ42_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ42_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ42_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ42_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ43_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ43_EN0_SHIFT (11U)
/*! REQ43_EN0 - Writing a 1 to REQ43_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ43_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ43_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ43_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ44_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ44_EN0_SHIFT (12U)
/*! REQ44_EN0 - Writing a 1 to REQ44_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ44_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ44_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ44_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ45_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ45_EN0_SHIFT (13U)
/*! REQ45_EN0 - Writing a 1 to REQ45_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ45_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ45_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ45_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ46_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ46_EN0_SHIFT (14U)
/*! REQ46_EN0 - Writing a 1 to REQ46_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ46_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ46_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ46_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ47_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ47_EN0_SHIFT (15U)
/*! REQ47_EN0 - Writing a 1 to REQ47_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ47_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ47_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ47_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ48_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ48_EN0_SHIFT (16U)
/*! REQ48_EN0 - Writing a 1 to REQ48_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ48_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ48_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ48_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ49_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ49_EN0_SHIFT (17U)
/*! REQ49_EN0 - Writing a 1 to REQ49_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ49_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ49_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ49_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ50_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ50_EN0_SHIFT (18U)
/*! REQ50_EN0 - Writing a 1 to REQ50_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ50_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ50_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ50_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ51_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ51_EN0_SHIFT (19U)
/*! REQ51_EN0 - Writing a 1 to REQ51_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ51_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ51_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ51_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ52_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ52_EN0_SHIFT (20U)
/*! REQ52_EN0 - Writing a 1 to REQ52_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ52_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ52_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ52_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ53_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ53_EN0_SHIFT (21U)
/*! REQ53_EN0 - Writing a 1 to REQ53_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ53_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ53_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ53_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ54_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ54_EN0_SHIFT (22U)
/*! REQ54_EN0 - Writing a 1 to REQ54_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ54_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ54_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ54_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ57_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ57_EN0_SHIFT (25U)
/*! REQ57_EN0 - Writing a 1 to REQ57_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ57_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ57_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ57_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ58_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ58_EN0_SHIFT (26U)
/*! REQ58_EN0 - Writing a 1 to REQ58_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ58_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ58_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ58_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ59_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ59_EN0_SHIFT (27U)
/*! REQ59_EN0 - Writing a 1 to REQ59_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ59_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ59_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ59_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ60_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ60_EN0_SHIFT (28U)
/*! REQ60_EN0 - Writing a 1 to REQ60_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ60_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ60_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ60_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ61_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ61_EN0_SHIFT (29U)
/*! REQ61_EN0 - Writing a 1 to REQ61_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ61_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ61_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ61_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ62_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ62_EN0_SHIFT (30U)
/*! REQ62_EN0 - Writing a 1 to REQ62_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ62_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ62_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ62_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ63_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ63_EN0_SHIFT (31U)
/*! REQ63_EN0 - Writing a 1 to REQ63_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ63_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ63_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_CLR_REQ63_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE1_TOG - DMA0 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ32_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ32_EN0_SHIFT (0U)
/*! REQ32_EN0 - Writing a 1 to REQ32_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ32_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ32_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ32_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ33_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ33_EN0_SHIFT (1U)
/*! REQ33_EN0 - Writing a 1 to REQ33_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ33_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ33_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ33_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ34_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ34_EN0_SHIFT (2U)
/*! REQ34_EN0 - Writing a 1 to REQ34_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ34_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ34_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ34_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ35_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ35_EN0_SHIFT (3U)
/*! REQ35_EN0 - Writing a 1 to REQ35_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ35_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ35_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ35_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ36_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ36_EN0_SHIFT (4U)
/*! REQ36_EN0 - Writing a 1 to REQ36_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ36_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ36_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ36_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ37_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ37_EN0_SHIFT (5U)
/*! REQ37_EN0 - Writing a 1 to REQ37_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ37_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ37_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ37_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ38_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ38_EN0_SHIFT (6U)
/*! REQ38_EN0 - Writing a 1 to REQ38_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ38_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ38_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ38_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ39_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ39_EN0_SHIFT (7U)
/*! REQ39_EN0 - Writing a 1 to REQ39_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ39_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ39_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ39_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ40_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ40_EN0_SHIFT (8U)
/*! REQ40_EN0 - Writing a 1 to REQ40_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ40_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ40_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ40_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ41_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ41_EN0_SHIFT (9U)
/*! REQ41_EN0 - Writing a 1 to REQ41_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ41_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ41_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ41_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ42_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ42_EN0_SHIFT (10U)
/*! REQ42_EN0 - Writing a 1 to REQ42_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ42_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ42_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ42_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ43_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ43_EN0_SHIFT (11U)
/*! REQ43_EN0 - Writing a 1 to REQ43_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ43_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ43_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ43_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ44_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ44_EN0_SHIFT (12U)
/*! REQ44_EN0 - Writing a 1 to REQ44_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ44_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ44_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ44_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ45_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ45_EN0_SHIFT (13U)
/*! REQ45_EN0 - Writing a 1 to REQ55_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ45_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ45_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ45_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ46_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ46_EN0_SHIFT (14U)
/*! REQ46_EN0 - Writing a 1 to REQ46_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ46_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ46_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ46_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ47_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ47_EN0_SHIFT (15U)
/*! REQ47_EN0 - Writing a 1 to REQ47_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ47_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ47_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ47_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ48_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ48_EN0_SHIFT (16U)
/*! REQ48_EN0 - Writing a 1 to REQ48_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ48_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ48_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ48_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ49_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ49_EN0_SHIFT (17U)
/*! REQ49_EN0 - Writing a 1 to REQ49_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ49_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ49_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ49_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ50_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ50_EN0_SHIFT (18U)
/*! REQ50_EN0 - Writing a 1 to REQ50_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ50_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ50_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ50_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ51_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ51_EN0_SHIFT (19U)
/*! REQ51_EN0 - Writing a 1 to REQ51_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ51_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ51_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ51_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ52_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ52_EN0_SHIFT (20U)
/*! REQ52_EN0 - Writing a 1 to REQ52_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ52_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ52_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ52_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ53_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ53_EN0_SHIFT (21U)
/*! REQ53_EN0 - Writing a 1 to REQ53_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ53_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ53_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ53_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ54_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ54_EN0_SHIFT (22U)
/*! REQ54_EN0 - Writing a 1 to REQ54_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ54_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ54_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ54_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ57_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ57_EN0_SHIFT (25U)
/*! REQ57_EN0 - Writing a 1 to REQ57_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ57_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ57_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ57_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ58_EN0_MASK (0x4000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ58_EN0_SHIFT (26U)
/*! REQ58_EN0 - Writing a 1 to REQ58_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ58_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ58_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ58_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ59_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ59_EN0_SHIFT (27U)
/*! REQ59_EN0 - Writing a 1 to REQ59_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ59_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ59_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ59_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ60_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ60_EN0_SHIFT (28U)
/*! REQ60_EN0 - Writing a 1 to REQ60_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ60_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ60_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ60_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ61_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ61_EN0_SHIFT (29U)
/*! REQ61_EN0 - Writing a 1 to REQ61_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ61_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ61_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ61_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ62_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ62_EN0_SHIFT (30U)
/*! REQ62_EN0 - Writing a 1 to REQ62_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ62_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ62_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ62_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ63_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ63_EN0_SHIFT (31U)
/*! REQ63_EN0 - Writing a 1 to REQ63_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE1. */
#define INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ63_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ63_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE1_TOG_REQ63_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE2 - DMA0 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ64_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ64_EN0_SHIFT (0U)
/*! REQ64_EN0 - This register is used to enable and disable FlexIO0 shift register 3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ64_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ64_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ64_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ65_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ65_EN0_SHIFT (1U)
/*! REQ65_EN0 - This register is used to enable and disable FlexIO0 shift register 4 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ65_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ65_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ65_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ66_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ66_EN0_SHIFT (2U)
/*! REQ66_EN0 - This register is used to enable and disable FlexIO0 shift register 5 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ66_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ66_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ66_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ67_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ67_EN0_SHIFT (3U)
/*! REQ67_EN0 - This register is used to enable and disable FlexIO0 shift register 6 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ67_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ67_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ67_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ68_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ68_EN0_SHIFT (4U)
/*! REQ68_EN0 - This register is used to enable and disable FlexIO0 shift register 7 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ68_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ68_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ68_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ69_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ69_EN0_SHIFT (5U)
/*! REQ69_EN0 - This register is used to enable and disable LP_FLEXCOMM0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ69_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ69_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ69_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ70_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ70_EN0_SHIFT (6U)
/*! REQ70_EN0 - This register is used to enable and disable LP_FLEXCOMM0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ70_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ70_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ70_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ71_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ71_EN0_SHIFT (7U)
/*! REQ71_EN0 - This register is used to enable and disable LP_FLEXCOMM1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ71_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ71_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ71_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ72_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ72_EN0_SHIFT (8U)
/*! REQ72_EN0 - This register is used to enable and disable LP_FLEXCOMM1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ72_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ72_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ72_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ73_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ73_EN0_SHIFT (9U)
/*! REQ73_EN0 - This register is used to enable and disable LP_FLEXCOMM2 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ73_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ73_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ73_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ74_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ74_EN0_SHIFT (10U)
/*! REQ74_EN0 - This register is used to enable and disable LP_FLEXCOMM2 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ74_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ74_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ74_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ75_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ75_EN0_SHIFT (11U)
/*! REQ75_EN0 - This register is used to enable and disable LP_FLEXCOMM3 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ75_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ75_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ75_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ76_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ76_EN0_SHIFT (12U)
/*! REQ76_EN0 - This register is used to enable and disable LP_FLEXCOMM3 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ76_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ76_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ76_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ77_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ77_EN0_SHIFT (13U)
/*! REQ77_EN0 - This register is used to enable and disable LP_FLEXCOMM4 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ77_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ77_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ77_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ78_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ78_EN0_SHIFT (14U)
/*! REQ78_EN0 - This register is used to enable and disable LP_FLEXCOMM4 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ78_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ78_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ78_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ79_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ79_EN0_SHIFT (15U)
/*! REQ79_EN0 - This register is used to enable and disable LP_FLEXCOMM5 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ79_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ79_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ79_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ80_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ80_EN0_SHIFT (16U)
/*! REQ80_EN0 - This register is used to enable and disable LP_FLEXCOMM5 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ80_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ80_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ80_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ81_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ81_EN0_SHIFT (17U)
/*! REQ81_EN0 - This register is used to enable and disable LP_FLEXCOMM6 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ81_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ81_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ81_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ82_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ82_EN0_SHIFT (18U)
/*! REQ82_EN0 - This register is used to enable and disable LP_FLEXCOMM6 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ82_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ82_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ82_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ83_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ83_EN0_SHIFT (19U)
/*! REQ83_EN0 - This register is used to enable and disable LP_FLEXCOMM7 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ83_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ83_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ83_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ84_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ84_EN0_SHIFT (20U)
/*! REQ84_EN0 - This register is used to enable and disable LP_FLEXCOMM7 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ84_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ84_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ84_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ85_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ85_EN0_SHIFT (21U)
/*! REQ85_EN0 - This register is used to enable and disable LP_FLEXCOMM8 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ85_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ85_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ85_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ86_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ86_EN0_SHIFT (22U)
/*! REQ86_EN0 - This register is used to enable and disable LP_FLEXCOMM8 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ86_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ86_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ86_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ87_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ87_EN0_SHIFT (23U)
/*! REQ87_EN0 - This register is used to enable and disable LP_FLEXCOMM9 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ87_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ87_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ87_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ88_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ88_EN0_SHIFT (24U)
/*! REQ88_EN0 - This register is used to enable and disable LP_FLEXCOMM9 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ88_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ88_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ88_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ91_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ91_EN0_SHIFT (27U)
/*! REQ91_EN0 - This register is used to enable and disable EMVSIM0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ91_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ91_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ91_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ92_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ92_EN0_SHIFT (28U)
/*! REQ92_EN0 - This register is used to enable and disable EMVSIM0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ92_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ92_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ92_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ93_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ93_EN0_SHIFT (29U)
/*! REQ93_EN0 - This register is used to enable and disable EMVSIM1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ93_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ93_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ93_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ94_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ94_EN0_SHIFT (30U)
/*! REQ94_EN0 - This register is used to enable and disable EMVSIM1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ94_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ94_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ94_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_REQ95_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ95_EN0_SHIFT (31U)
/*! REQ95_EN0 - This register is used to enable and disable I3C0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE2_REQ95_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_REQ95_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_REQ95_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE2_SET - DMA0 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ64_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ64_EN0_SHIFT (0U)
/*! REQ64_EN0 - Writing a 1 to REQ64_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ64_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ64_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ64_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ65_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ65_EN0_SHIFT (1U)
/*! REQ65_EN0 - Writing a 1 to REQ65_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ65_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ65_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ65_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ66_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ66_EN0_SHIFT (2U)
/*! REQ66_EN0 - Writing a 1 to REQ66_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ66_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ66_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ66_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ67_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ67_EN0_SHIFT (3U)
/*! REQ67_EN0 - Writing a 1 to REQ67_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ67_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ67_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ67_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ68_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ68_EN0_SHIFT (4U)
/*! REQ68_EN0 - Writing a 1 to REQ68_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ68_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ68_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ68_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ69_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ69_EN0_SHIFT (5U)
/*! REQ69_EN0 - Writing a 1 to REQ69_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ69_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ69_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ69_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ70_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ70_EN0_SHIFT (6U)
/*! REQ70_EN0 - Writing a 1 to REQ70_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ70_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ70_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ70_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ71_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ71_EN0_SHIFT (7U)
/*! REQ71_EN0 - Writing a 1 to REQ71_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ71_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ71_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ71_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ72_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ72_EN0_SHIFT (8U)
/*! REQ72_EN0 - Writing a 1 to REQ72_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ72_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ72_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ72_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ73_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ73_EN0_SHIFT (9U)
/*! REQ73_EN0 - Writing a 1 to REQ73_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ73_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ73_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ73_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ74_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ74_EN0_SHIFT (10U)
/*! REQ74_EN0 - Writing a 1 to REQ74_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ74_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ74_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ74_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ75_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ75_EN0_SHIFT (11U)
/*! REQ75_EN0 - Writing a 1 to REQ75_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ75_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ75_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ75_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ76_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ76_EN0_SHIFT (12U)
/*! REQ76_EN0 - Writing a 1 to REQ876_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ76_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ76_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ76_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ77_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ77_EN0_SHIFT (13U)
/*! REQ77_EN0 - Writing a 1 to REQ77_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ77_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ77_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ77_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ78_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ78_EN0_SHIFT (14U)
/*! REQ78_EN0 - Writing a 1 to REQ78_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ78_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ78_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ78_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ79_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ79_EN0_SHIFT (15U)
/*! REQ79_EN0 - Writing a 1 to REQ79_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ79_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ79_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ79_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ80_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ80_EN0_SHIFT (16U)
/*! REQ80_EN0 - Writing a 1 to REQ80_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ80_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ80_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ80_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ81_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ81_EN0_SHIFT (17U)
/*! REQ81_EN0 - Writing a 1 to REQ81_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ81_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ81_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ81_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ82_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ82_EN0_SHIFT (18U)
/*! REQ82_EN0 - Writing a 1 to REQ82_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ82_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ82_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ82_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ83_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ83_EN0_SHIFT (19U)
/*! REQ83_EN0 - Writing a 1 to REQ83_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ83_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ83_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ83_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ84_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ84_EN0_SHIFT (20U)
/*! REQ84_EN0 - Writing a 1 to REQ84_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ84_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ84_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ84_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ85_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ85_EN0_SHIFT (21U)
/*! REQ85_EN0 - Writing a 1 to REQ85_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ85_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ85_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ85_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ86_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ86_EN0_SHIFT (22U)
/*! REQ86_EN0 - Writing a 1 to REQ86_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ86_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ86_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ86_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ87_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ87_EN0_SHIFT (23U)
/*! REQ87_EN0 - Writing a 1 to REQ87_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ87_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ87_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ87_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ88_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ88_EN0_SHIFT (24U)
/*! REQ88_EN0 - Writing a 1 to REQ88_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ88_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ88_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ88_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ91_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ91_EN0_SHIFT (27U)
/*! REQ91_EN0 - Writing a 1 to REQ91_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ91_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ91_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ91_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ92_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ92_EN0_SHIFT (28U)
/*! REQ92_EN0 - Writing a 1 to REQ92_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ92_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ92_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ92_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ93_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ93_EN0_SHIFT (29U)
/*! REQ93_EN0 - Writing a 1 to REQ93_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ93_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ93_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ93_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ94_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ94_EN0_SHIFT (30U)
/*! REQ94_EN0 - Writing a 1 to REQ94_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ94_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ94_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ94_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ95_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ95_EN0_SHIFT (31U)
/*! REQ95_EN0 - Writing a 1 to REQ95_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ95_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ95_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_SET_REQ95_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE2_CLR - DMA0 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ64_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ64_EN0_SHIFT (0U)
/*! REQ64_EN0 - Writing a 1 to REQ64_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ64_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ64_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ64_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ65_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ65_EN0_SHIFT (1U)
/*! REQ65_EN0 - Writing a 1 to REQ65_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ65_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ65_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ65_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ66_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ66_EN0_SHIFT (2U)
/*! REQ66_EN0 - Writing a 1 to REQ66_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ66_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ66_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ66_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ67_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ67_EN0_SHIFT (3U)
/*! REQ67_EN0 - Writing a 1 to REQ67_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ67_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ67_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ67_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ68_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ68_EN0_SHIFT (4U)
/*! REQ68_EN0 - Writing a 1 to REQ68_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ68_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ68_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ68_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ69_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ69_EN0_SHIFT (5U)
/*! REQ69_EN0 - Writing a 1 to REQ69_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ69_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ69_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ69_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ70_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ70_EN0_SHIFT (6U)
/*! REQ70_EN0 - Writing a 1 to REQ70_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ70_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ70_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ70_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ71_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ71_EN0_SHIFT (7U)
/*! REQ71_EN0 - Writing a 1 to REQ71_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ71_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ71_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ71_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ72_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ72_EN0_SHIFT (8U)
/*! REQ72_EN0 - Writing a 1 to REQ72_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ72_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ72_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ72_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ73_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ73_EN0_SHIFT (9U)
/*! REQ73_EN0 - Writing a 1 to REQ73_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ73_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ73_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ73_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ74_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ74_EN0_SHIFT (10U)
/*! REQ74_EN0 - Writing a 1 to REQ74_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ74_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ74_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ74_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ75_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ75_EN0_SHIFT (11U)
/*! REQ75_EN0 - Writing a 1 to REQ75_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ75_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ75_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ75_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ76_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ76_EN0_SHIFT (12U)
/*! REQ76_EN0 - Writing a 1 to REQ76_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ76_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ76_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ76_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ77_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ77_EN0_SHIFT (13U)
/*! REQ77_EN0 - Writing a 1 to REQ77_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ77_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ77_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ77_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ78_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ78_EN0_SHIFT (14U)
/*! REQ78_EN0 - Writing a 1 to REQ78_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ78_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ78_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ78_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ79_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ79_EN0_SHIFT (15U)
/*! REQ79_EN0 - Writing a 1 to REQ79_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ79_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ79_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ79_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ80_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ80_EN0_SHIFT (16U)
/*! REQ80_EN0 - Writing a 1 to REQ80_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ80_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ80_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ80_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ81_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ81_EN0_SHIFT (17U)
/*! REQ81_EN0 - Writing a 1 to REQ81_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ81_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ81_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ81_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ82_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ82_EN0_SHIFT (18U)
/*! REQ82_EN0 - Writing a 1 to REQ82_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ82_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ82_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ82_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ83_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ83_EN0_SHIFT (19U)
/*! REQ83_EN0 - Writing a 1 to REQ83_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ83_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ83_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ83_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ84_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ84_EN0_SHIFT (20U)
/*! REQ84_EN0 - Writing a 1 to REQ84_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ84_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ84_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ84_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ85_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ85_EN0_SHIFT (21U)
/*! REQ85_EN0 - Writing a 1 to REQ85_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ85_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ85_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ85_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ86_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ86_EN0_SHIFT (22U)
/*! REQ86_EN0 - Writing a 1 to REQ86_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ86_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ86_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ86_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ87_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ87_EN0_SHIFT (23U)
/*! REQ87_EN0 - Writing a 1 to REQ87_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ87_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ87_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ87_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ88_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ88_EN0_SHIFT (24U)
/*! REQ88_EN0 - Writing a 1 to REQ88_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ88_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ88_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ88_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ91_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ91_EN0_SHIFT (27U)
/*! REQ91_EN0 - Writing a 1 to REQ91_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ91_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ91_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ91_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ92_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ92_EN0_SHIFT (28U)
/*! REQ92_EN0 - Writing a 1 to REQ92_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ92_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ92_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ92_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ93_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ93_EN0_SHIFT (29U)
/*! REQ93_EN0 - Writing a 1 to REQ93_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ93_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ93_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ93_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ94_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ94_EN0_SHIFT (30U)
/*! REQ94_EN0 - Writing a 1 to REQ94_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ94_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ94_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ94_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ95_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ95_EN0_SHIFT (31U)
/*! REQ95_EN0 - Writing a 1 to REQ95_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ95_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ95_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_CLR_REQ95_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE2_TOG - DMA0 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ64_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ64_EN0_SHIFT (0U)
/*! REQ64_EN0 - Writing a 1 to REQ64_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ64_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ64_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ64_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ65_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ65_EN0_SHIFT (1U)
/*! REQ65_EN0 - Writing a 1 to REQ65_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ65_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ65_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ65_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ66_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ66_EN0_SHIFT (2U)
/*! REQ66_EN0 - Writing a 1 to REQ66_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ66_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ66_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ66_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ67_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ67_EN0_SHIFT (3U)
/*! REQ67_EN0 - Writing a 1 to REQ67_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ67_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ67_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ67_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ68_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ68_EN0_SHIFT (4U)
/*! REQ68_EN0 - Writing a 1 to REQ68_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ68_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ68_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ68_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ69_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ69_EN0_SHIFT (5U)
/*! REQ69_EN0 - Writing a 1 to REQ69_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ69_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ69_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ69_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ70_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ70_EN0_SHIFT (6U)
/*! REQ70_EN0 - Writing a 1 to REQ70_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ70_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ70_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ70_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ71_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ71_EN0_SHIFT (7U)
/*! REQ71_EN0 - Writing a 1 to REQ71_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ71_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ71_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ71_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ72_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ72_EN0_SHIFT (8U)
/*! REQ72_EN0 - Writing a 1 to REQ72_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ72_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ72_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ72_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ73_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ73_EN0_SHIFT (9U)
/*! REQ73_EN0 - Writing a 1 to REQ73_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ73_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ73_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ73_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ74_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ74_EN0_SHIFT (10U)
/*! REQ74_EN0 - Writing a 1 to REQ74_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ74_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ74_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ74_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ75_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ75_EN0_SHIFT (11U)
/*! REQ75_EN0 - Writing a 1 to REQ75_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ75_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ75_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ75_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ76_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ76_EN0_SHIFT (12U)
/*! REQ76_EN0 - Writing a 1 to REQ76_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ76_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ76_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ76_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ77_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ77_EN0_SHIFT (13U)
/*! REQ77_EN0 - Writing a 1 to REQ77_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ77_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ77_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ77_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ78_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ78_EN0_SHIFT (14U)
/*! REQ78_EN0 - Writing a 1 to REQ78_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ78_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ78_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ78_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ79_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ79_EN0_SHIFT (15U)
/*! REQ79_EN0 - Writing a 1 to REQ79_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ79_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ79_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ79_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ80_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ80_EN0_SHIFT (16U)
/*! REQ80_EN0 - Writing a 1 to REQ80_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ80_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ80_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ80_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ81_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ81_EN0_SHIFT (17U)
/*! REQ81_EN0 - Writing a 1 to REQ81_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ81_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ81_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ81_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ82_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ82_EN0_SHIFT (18U)
/*! REQ82_EN0 - Writing a 1 to REQ82_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ82_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ82_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ82_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ83_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ83_EN0_SHIFT (19U)
/*! REQ83_EN0 - Writing a 1 to REQ83_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ83_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ83_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ83_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ84_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ84_EN0_SHIFT (20U)
/*! REQ84_EN0 - Writing a 1 to REQ84_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ84_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ84_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ84_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ85_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ85_EN0_SHIFT (21U)
/*! REQ85_EN0 - Writing a 1 to REQ85_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ85_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ85_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ85_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ86_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ86_EN0_SHIFT (22U)
/*! REQ86_EN0 - Writing a 1 to REQ86_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ86_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ86_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ86_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ87_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ87_EN0_SHIFT (23U)
/*! REQ87_EN0 - Writing a 1 to REQ87_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ87_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ87_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ87_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ88_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ88_EN0_SHIFT (24U)
/*! REQ88_EN0 - Writing a 1 to REQ88_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ88_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ88_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ88_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ91_EN0_MASK (0x8000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ91_EN0_SHIFT (27U)
/*! REQ91_EN0 - Writing a 1 to REQ91_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ91_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ91_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ91_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ92_EN0_MASK (0x10000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ92_EN0_SHIFT (28U)
/*! REQ92_EN0 - Writing a 1 to REQ92_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ92_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ92_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ92_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ93_EN0_MASK (0x20000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ93_EN0_SHIFT (29U)
/*! REQ93_EN0 - Writing a 1 to REQ93_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ93_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ93_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ93_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ94_EN0_MASK (0x40000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ94_EN0_SHIFT (30U)
/*! REQ94_EN0 - Writing a 1 to REQ94_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ94_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ94_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ94_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ95_EN0_MASK (0x80000000U)
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ95_EN0_SHIFT (31U)
/*! REQ95_EN0 - Writing a 1 to REQ95_EN0 in this register toggles the corresponding bit in DMA0_REQ_ENABLE2. */
#define INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ95_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ95_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE2_TOG_REQ95_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE3 - DMA0 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ96_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ96_EN0_SHIFT (0U)
/*! REQ96_EN0 - This register is used to enable and disable I3C0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ96_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ96_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ96_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ97_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ97_EN0_SHIFT (1U)
/*! REQ97_EN0 - This register is used to enable and disable I3C1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ97_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ97_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ97_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ98_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ98_EN0_SHIFT (2U)
/*! REQ98_EN0 - This register is used to enable and disable I3C1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ98_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ98_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ98_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ99_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ99_EN0_SHIFT (3U)
/*! REQ99_EN0 - This register is used to enable and disable SAI0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ99_EN0(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ99_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ99_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ100_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ100_EN0_SHIFT (4U)
/*! REQ100_EN0 - This register is used to enable and disable SAI0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ100_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ100_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ100_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ101_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ101_EN0_SHIFT (5U)
/*! REQ101_EN0 - This register is used to enable and disable SAI1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ101_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ101_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ101_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ102_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ102_EN0_SHIFT (6U)
/*! REQ102_EN0 - This register is used to enable and disable SAI1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ102_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ102_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ102_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ103_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ103_EN0_SHIFT (7U)
/*! REQ103_EN0 - This register is used to enable and disable SINC0 ipd_req_sinc[0] or ipd_req_alt [0] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ103_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ103_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ103_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ104_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ104_EN0_SHIFT (8U)
/*! REQ104_EN0 - This register is used to enable and disable SINC0 ipd_req_sinc[1] or ipd_req_alt [1] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ104_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ104_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ104_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ105_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ105_EN0_SHIFT (9U)
/*! REQ105_EN0 - This register is used to enable and disable SINC0 ipd_req_sinc[2] or ipd_req_alt [2] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ105_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ105_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ105_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ106_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ106_EN0_SHIFT (10U)
/*! REQ106_EN0 - This register is used to enable and disable SINC0 ipd_req_sinc[3] or ipd_req_alt [3] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ106_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ106_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ106_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ107_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ107_EN0_SHIFT (11U)
/*! REQ107_EN0 - This register is used to enable and disable SINC0 ipd_req_sinc[4] or ipd_req_alt [4] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ107_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ107_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ107_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ108_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ108_EN0_SHIFT (12U)
/*! REQ108_EN0 - This register is used to enable and disable GPIO0 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ108_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ108_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ108_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ109_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ109_EN0_SHIFT (13U)
/*! REQ109_EN0 - This register is used to enable and disable GPIO0 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ109_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ109_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ109_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ110_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ110_EN0_SHIFT (14U)
/*! REQ110_EN0 - This register is used to enable and disable GPIO1 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ110_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ110_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ110_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ111_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ111_EN0_SHIFT (15U)
/*! REQ111_EN0 - This register is used to enable and disable GPIO1 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ111_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ111_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ111_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ112_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ112_EN0_SHIFT (16U)
/*! REQ112_EN0 - This register is used to enable and disable GPIO2 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ112_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ112_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ112_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ113_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ113_EN0_SHIFT (17U)
/*! REQ113_EN0 - This register is used to enable and disable GPIO2 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ113_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ113_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ113_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ114_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ114_EN0_SHIFT (18U)
/*! REQ114_EN0 - This register is used to enable and disable GPIO3 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ114_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ114_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ114_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ115_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ115_EN0_SHIFT (19U)
/*! REQ115_EN0 - This register is used to enable and disable GPIO3 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ115_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ115_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ115_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ116_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ116_EN0_SHIFT (20U)
/*! REQ116_EN0 - This register is used to enable and disable GPIO4 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ116_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ116_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ116_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ117_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ117_EN0_SHIFT (21U)
/*! REQ117_EN0 - This register is used to enable and disable GPIO4 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ117_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ117_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ117_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ118_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ118_EN0_SHIFT (22U)
/*! REQ118_EN0 - This register is used to enable and disable GPIO5 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ118_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ118_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ118_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ119_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ119_EN0_SHIFT (23U)
/*! REQ119_EN0 - This register is used to enable and disable GPIO5 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ119_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ119_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ119_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ120_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ120_EN0_SHIFT (24U)
/*! REQ120_EN0 - This register is used to enable and disable TSI0 end of scan request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ120_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ120_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ120_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_REQ121_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ121_EN0_SHIFT (25U)
/*! REQ121_EN0 - This register is used to enable and disable TSI0 out of range request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA0_REQ_ENABLE3_REQ121_EN0(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_REQ121_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_REQ121_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE3_SET - DMA0 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ96_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ96_EN0_SHIFT (0U)
/*! REQ96_EN0 - Writing a 1 to REQ96_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ96_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ96_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ96_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ97_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ97_EN0_SHIFT (1U)
/*! REQ97_EN0 - Writing a 1 to REQ97_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ97_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ97_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ97_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ98_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ98_EN0_SHIFT (2U)
/*! REQ98_EN0 - Writing a 1 to REQ98_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ98_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ98_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ98_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ99_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ99_EN0_SHIFT (3U)
/*! REQ99_EN0 - Writing a 1 to REQ99_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ99_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ99_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ99_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ100_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ100_EN0_SHIFT (4U)
/*! REQ100_EN0 - Writing a 1 to REQ100_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ100_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ100_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ100_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ101_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ101_EN0_SHIFT (5U)
/*! REQ101_EN0 - Writing a 1 to REQ101_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ101_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ101_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ101_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ102_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ102_EN0_SHIFT (6U)
/*! REQ102_EN0 - Writing a 1 to REQ102_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ102_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ102_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ102_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ103_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ103_EN0_SHIFT (7U)
/*! REQ103_EN0 - Writing a 1 to REQ103_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ103_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ103_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ103_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ104_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ104_EN0_SHIFT (8U)
/*! REQ104_EN0 - Writing a 1 to REQ104_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ104_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ104_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ104_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ105_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ105_EN0_SHIFT (9U)
/*! REQ105_EN0 - Writing a 1 to REQ105_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ105_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ105_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ105_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ106_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ106_EN0_SHIFT (10U)
/*! REQ106_EN0 - Writing a 1 to REQ106_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ106_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ106_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ106_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ107_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ107_EN0_SHIFT (11U)
/*! REQ107_EN0 - Writing a 1 to REQ107_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ107_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ107_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ107_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ108_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ108_EN0_SHIFT (12U)
/*! REQ108_EN0 - Writing a 1 to REQ108_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ108_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ108_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ108_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ109_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ109_EN0_SHIFT (13U)
/*! REQ109_EN0 - Writing a 1 to REQ109_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ109_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ109_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ109_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ110_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ110_EN0_SHIFT (14U)
/*! REQ110_EN0 - Writing a 1 to REQ110_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ110_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ110_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ110_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ111_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ111_EN0_SHIFT (15U)
/*! REQ111_EN0 - Writing a 1 to REQ111_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ111_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ111_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ111_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ112_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ112_EN0_SHIFT (16U)
/*! REQ112_EN0 - Writing a 1 to REQ112_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ112_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ112_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ112_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ113_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ113_EN0_SHIFT (17U)
/*! REQ113_EN0 - Writing a 1 to REQ113_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ113_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ113_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ113_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ114_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ114_EN0_SHIFT (18U)
/*! REQ114_EN0 - Writing a 1 to REQ114_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ114_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ114_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ114_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ115_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ115_EN0_SHIFT (19U)
/*! REQ115_EN0 - Writing a 1 to REQ115_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ115_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ115_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ115_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ116_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ116_EN0_SHIFT (20U)
/*! REQ116_EN0 - Writing a 1 to REQ116_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ116_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ116_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ116_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ117_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ117_EN0_SHIFT (21U)
/*! REQ117_EN0 - Writing a 1 to REQ117_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ117_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ117_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ117_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ118_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ118_EN0_SHIFT (22U)
/*! REQ118_EN0 - Writing a 1 to REQ118_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ118_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ118_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ118_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ119_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ119_EN0_SHIFT (23U)
/*! REQ119_EN0 - Writing a 1 to REQ119_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ119_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ119_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ119_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ120_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ120_EN0_SHIFT (24U)
/*! REQ120_EN0 - Writing a 1 to REQ120_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ120_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ120_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ120_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ121_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ121_EN0_SHIFT (25U)
/*! REQ121_EN0 - Writing a 1 to REQ121_EN0 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ121_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ121_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_SET_REQ121_EN0_MASK)
/*! @} */

/*! @name DMA0_REQ_ENABLE3_CLR - DMA0 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ96_EN0_MASK (0x1U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ96_EN0_SHIFT (0U)
/*! REQ96_EN0 - Writing a 1 to REQ96_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ96_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ96_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ96_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ97_EN0_MASK (0x2U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ97_EN0_SHIFT (1U)
/*! REQ97_EN0 - Writing a 1 to REQ97_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ97_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ97_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ97_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ98_EN0_MASK (0x4U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ98_EN0_SHIFT (2U)
/*! REQ98_EN0 - Writing a 1 to REQ98_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ98_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ98_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ98_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ99_EN0_MASK (0x8U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ99_EN0_SHIFT (3U)
/*! REQ99_EN0 - Writing a 1 to REQ99_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ99_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ99_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ99_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ100_EN0_MASK (0x10U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ100_EN0_SHIFT (4U)
/*! REQ100_EN0 - Writing a 1 to REQ100_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ100_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ100_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ100_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ101_EN0_MASK (0x20U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ101_EN0_SHIFT (5U)
/*! REQ101_EN0 - Writing a 1 to REQ101_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ101_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ101_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ101_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ102_EN0_MASK (0x40U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ102_EN0_SHIFT (6U)
/*! REQ102_EN0 - Writing a 1 to REQ102_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ102_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ102_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ102_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ103_EN0_MASK (0x80U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ103_EN0_SHIFT (7U)
/*! REQ103_EN0 - Writing a 1 to REQ103_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ103_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ103_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ103_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ104_EN0_MASK (0x100U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ104_EN0_SHIFT (8U)
/*! REQ104_EN0 - Writing a 1 to REQ104_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ104_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ104_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ104_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ105_EN0_MASK (0x200U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ105_EN0_SHIFT (9U)
/*! REQ105_EN0 - Writing a 1 to REQ105_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ105_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ105_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ105_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ106_EN0_MASK (0x400U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ106_EN0_SHIFT (10U)
/*! REQ106_EN0 - Writing a 1 to REQ106_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ106_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ106_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ106_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ107_EN0_MASK (0x800U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ107_EN0_SHIFT (11U)
/*! REQ107_EN0 - Writing a 1 to REQ107_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ107_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ107_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ107_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ108_EN0_MASK (0x1000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ108_EN0_SHIFT (12U)
/*! REQ108_EN0 - Writing a 1 to REQ108_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ108_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ108_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ108_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ109_EN0_MASK (0x2000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ109_EN0_SHIFT (13U)
/*! REQ109_EN0 - Writing a 1 to REQ109_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ109_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ109_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ109_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ110_EN0_MASK (0x4000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ110_EN0_SHIFT (14U)
/*! REQ110_EN0 - Writing a 1 to REQ110_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ110_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ110_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ110_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ111_EN0_MASK (0x8000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ111_EN0_SHIFT (15U)
/*! REQ111_EN0 - Writing a 1 to REQ111_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ111_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ111_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ111_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ112_EN0_MASK (0x10000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ112_EN0_SHIFT (16U)
/*! REQ112_EN0 - Writing a 1 to REQ112_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ112_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ112_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ112_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ113_EN0_MASK (0x20000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ113_EN0_SHIFT (17U)
/*! REQ113_EN0 - Writing a 1 to REQ113_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ113_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ113_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ113_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ114_EN0_MASK (0x40000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ114_EN0_SHIFT (18U)
/*! REQ114_EN0 - Writing a 1 to REQ114_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ114_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ114_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ114_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ115_EN0_MASK (0x80000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ115_EN0_SHIFT (19U)
/*! REQ115_EN0 - Writing a 1 to REQ115_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ115_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ115_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ115_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ116_EN0_MASK (0x100000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ116_EN0_SHIFT (20U)
/*! REQ116_EN0 - Writing a 1 to REQ116_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ116_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ116_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ116_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ117_EN0_MASK (0x200000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ117_EN0_SHIFT (21U)
/*! REQ117_EN0 - Writing a 1 to REQ117_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ117_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ117_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ117_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ118_EN0_MASK (0x400000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ118_EN0_SHIFT (22U)
/*! REQ118_EN0 - Writing a 1 to REQ118_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ118_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ118_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ118_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ119_EN0_MASK (0x800000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ119_EN0_SHIFT (23U)
/*! REQ119_EN0 - Writing a 1 to REQ119_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ119_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ119_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ119_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ120_EN0_MASK (0x1000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ120_EN0_SHIFT (24U)
/*! REQ120_EN0 - Writing a 1 to REQ120_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ120_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ120_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ120_EN0_MASK)

#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ121_EN0_MASK (0x2000000U)
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ121_EN0_SHIFT (25U)
/*! REQ121_EN0 - Writing a 1 to REQ121_EN0 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ121_EN0(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ121_EN0_SHIFT)) & INPUTMUX_DMA0_REQ_ENABLE3_CLR_REQ121_EN0_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE0 - DMA1 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ1_EN1_MASK  (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ1_EN1_SHIFT (1U)
/*! REQ1_EN1 - This register is used to enable and disable FLEXSPI0 receive event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ1_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ1_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ1_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ2_EN1_MASK  (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ2_EN1_SHIFT (2U)
/*! REQ2_EN1 - This register is used to enable and disable FLEXSPI0 transmit event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ2_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ2_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ2_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ3_EN1_MASK  (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ3_EN1_SHIFT (3U)
/*! REQ3_EN1 - This register is used to enable and disable PINT0 INT0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ3_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ3_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ3_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ4_EN1_MASK  (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ4_EN1_SHIFT (4U)
/*! REQ4_EN1 - This register is used to enable and disable PINT0 INT1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ4_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ4_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ4_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ5_EN1_MASK  (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ5_EN1_SHIFT (5U)
/*! REQ5_EN1 - This register is used to enable and disable PINT0 INT2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ5_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ5_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ5_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ6_EN1_MASK  (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ6_EN1_SHIFT (6U)
/*! REQ6_EN1 - This register is used to enable and disable PINT0 INT3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ6_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ6_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ6_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ7_EN1_MASK  (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ7_EN1_SHIFT (7U)
/*! REQ7_EN1 - This register is used to enable and disable CTIMER0 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ7_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ7_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ7_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ8_EN1_MASK  (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ8_EN1_SHIFT (8U)
/*! REQ8_EN1 - This register is used to enable and disable CTIMER0 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ8_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ8_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ8_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ9_EN1_MASK  (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ9_EN1_SHIFT (9U)
/*! REQ9_EN1 - This register is used to enable and disable CTIMER1 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ9_EN1(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ9_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ9_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ10_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ10_EN1_SHIFT (10U)
/*! REQ10_EN1 - This register is used to enable and disable CTIMER1 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ10_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ10_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ10_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ11_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ11_EN1_SHIFT (11U)
/*! REQ11_EN1 - This register is used to enable and disable CTIMER2 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ11_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ11_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ11_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ12_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ12_EN1_SHIFT (12U)
/*! REQ12_EN1 - This register is used to enable and disable CTIMER2 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ12_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ12_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ12_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ13_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ13_EN1_SHIFT (13U)
/*! REQ13_EN1 - This register is used to enable and disable CTIMER3 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ13_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ13_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ13_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ14_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ14_EN1_SHIFT (14U)
/*! REQ14_EN1 - This register is used to enable and disable CTIMER3 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ14_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ14_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ14_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ15_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ15_EN1_SHIFT (15U)
/*! REQ15_EN1 - This register is used to enable and disable CTIMER4 DMAREQ_M0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ15_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ15_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ15_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ16_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ16_EN1_SHIFT (16U)
/*! REQ16_EN1 - This register is used to enable and disable CTIMER4 DMAREQ_M1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ16_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ16_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ16_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ17_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ17_EN1_SHIFT (17U)
/*! REQ17_EN1 - This register is used to enable and disable WUU0 wake up event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ17_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ17_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ17_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ18_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ18_EN1_SHIFT (18U)
/*! REQ18_EN1 - This register is used to enable and disable MICFIL0 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ18_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ18_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ18_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ19_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ19_EN1_SHIFT (19U)
/*! REQ19_EN1 - This register is used to enable and disable SCT0 DMA0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ19_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ19_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ19_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ20_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ20_EN1_SHIFT (20U)
/*! REQ20_EN1 - This register is used to enable and disable SCT0 DMA1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ20_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ20_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ20_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ21_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ21_EN1_SHIFT (21U)
/*! REQ21_EN1 - This register is used to enable and disable ADC0 FIFO A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ21_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ21_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ21_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ22_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ22_EN1_SHIFT (22U)
/*! REQ22_EN1 - This register is used to enable and disable ADC0 FIFO B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ22_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ22_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ22_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ23_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ23_EN1_SHIFT (23U)
/*! REQ23_EN1 - This register is used to enable and disable ADC1 FIFO A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ23_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ23_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ23_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ24_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ24_EN1_SHIFT (24U)
/*! REQ24_EN1 - This register is used to enable and disable ADC1 FIFO B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ24_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ24_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ24_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ25_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ25_EN1_SHIFT (25U)
/*! REQ25_EN1 - This register is used to enable and disable DAC0 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ25_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ25_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ25_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ26_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ26_EN1_SHIFT (26U)
/*! REQ26_EN1 - This register is used to enable and disable DAC1 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ26_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ26_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ26_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ27_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ27_EN1_SHIFT (27U)
/*! REQ27_EN1 - This register is used to enable and disable DAC2 FIFO_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ27_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ27_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ27_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ28_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ28_EN1_SHIFT (28U)
/*! REQ28_EN1 - This register is used to enable and disable CMP0 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ28_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ28_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ28_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ29_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ29_EN1_SHIFT (29U)
/*! REQ29_EN1 - This register is used to enable and disable CMP1 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ29_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ29_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ29_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ30_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ30_EN1_SHIFT (30U)
/*! REQ30_EN1 - This register is used to enable and disable CMP2 DMA_request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ30_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ30_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ30_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_REQ31_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ31_EN1_SHIFT (31U)
/*! REQ31_EN1 - This register is used to enable and disable EVTG0 OUT0A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE0_REQ31_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_REQ31_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_REQ31_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE0_SET - DMA1 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ1_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ1_EN1_SHIFT (1U)
/*! REQ1_EN1 - Writing a 1 to REQ1_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ1_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ1_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ1_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ2_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ2_EN1_SHIFT (2U)
/*! REQ2_EN1 - Writing a 1 to REQ2_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ2_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ2_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ2_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ3_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ3_EN1_SHIFT (3U)
/*! REQ3_EN1 - Writing a 1 to REQ3_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ3_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ3_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ3_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ4_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ4_EN1_SHIFT (4U)
/*! REQ4_EN1 - Writing a 1 to REQ4_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ4_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ4_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ4_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ5_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ5_EN1_SHIFT (5U)
/*! REQ5_EN1 - Writing a 1 to REQ5_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ5_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ5_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ5_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ6_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ6_EN1_SHIFT (6U)
/*! REQ6_EN1 - Writing a 1 to REQ6_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ6_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ6_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ6_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ7_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ7_EN1_SHIFT (7U)
/*! REQ7_EN1 - Writing a 1 to REQ7_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ7_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ7_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ7_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ8_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ8_EN1_SHIFT (8U)
/*! REQ8_EN1 - Writing a 1 to REQ8_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ8_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ8_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ8_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ9_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ9_EN1_SHIFT (9U)
/*! REQ9_EN1 - Writing a 1 to REQ9_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ9_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ9_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ9_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ10_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ10_EN1_SHIFT (10U)
/*! REQ10_EN1 - Writing a 1 to REQ10_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ10_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ10_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ10_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ11_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ11_EN1_SHIFT (11U)
/*! REQ11_EN1 - Writing a 1 to REQ11_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ11_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ11_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ11_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ12_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ12_EN1_SHIFT (12U)
/*! REQ12_EN1 - Writing a 1 to REQ12_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ12_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ12_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ12_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ13_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ13_EN1_SHIFT (13U)
/*! REQ13_EN1 - Writing a 1 to REQ13_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ13_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ13_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ13_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ14_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ14_EN1_SHIFT (14U)
/*! REQ14_EN1 - Writing a 1 to REQ14_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ14_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ14_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ14_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ15_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ15_EN1_SHIFT (15U)
/*! REQ15_EN1 - Writing a 1 to REQ15_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ15_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ15_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ15_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ16_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ16_EN1_SHIFT (16U)
/*! REQ16_EN1 - Writing a 1 to REQ16_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ16_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ16_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ16_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ17_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ17_EN1_SHIFT (17U)
/*! REQ17_EN1 - Writing a 1 to REQ17_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ17_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ17_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ17_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ18_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ18_EN1_SHIFT (18U)
/*! REQ18_EN1 - Writing a 1 to REQ18_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ18_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ18_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ18_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ19_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ19_EN1_SHIFT (19U)
/*! REQ19_EN1 - Writing a 1 to REQ19_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ19_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ19_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ19_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ20_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ20_EN1_SHIFT (20U)
/*! REQ20_EN1 - Writing a 1 to REQ20_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ20_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ20_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ20_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ21_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ21_EN1_SHIFT (21U)
/*! REQ21_EN1 - Writing a 1 to REQ21_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ21_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ21_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ21_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ22_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ22_EN1_SHIFT (22U)
/*! REQ22_EN1 - Writing a 1 to REQ22_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ22_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ22_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ22_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ23_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ23_EN1_SHIFT (23U)
/*! REQ23_EN1 - Writing a 1 to REQ23_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ23_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ23_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ23_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ24_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ24_EN1_SHIFT (24U)
/*! REQ24_EN1 - Writing a 1 to REQ24_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ24_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ24_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ24_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ25_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ25_EN1_SHIFT (25U)
/*! REQ25_EN1 - Writing a 1 to REQ25_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ25_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ25_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ25_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ26_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ26_EN1_SHIFT (26U)
/*! REQ26_EN1 - Writing a 1 to REQ26_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ26_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ26_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ26_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ27_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ27_EN1_SHIFT (27U)
/*! REQ27_EN1 - Writing a 1 to REQ27_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ27_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ27_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ27_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ28_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ28_EN1_SHIFT (28U)
/*! REQ28_EN1 - Writing a 1 to REQ28_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ28_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ28_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ28_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ29_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ29_EN1_SHIFT (29U)
/*! REQ29_EN1 - Writing a 1 to REQ29_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ29_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ29_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ29_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ30_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ30_EN1_SHIFT (30U)
/*! REQ30_EN1 - Writing a 1 to REQ30_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ30_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ30_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ30_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ31_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ31_EN1_SHIFT (31U)
/*! REQ31_EN1 - Writing a 1 to REQ31_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ31_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ31_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_SET_REQ31_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE0_CLR - DMA1 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ1_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ1_EN1_SHIFT (1U)
/*! REQ1_EN1 - Writing a 1 to REQ1_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ1_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ1_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ1_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ2_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ2_EN1_SHIFT (2U)
/*! REQ2_EN1 - Writing a 1 to REQ2_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ2_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ2_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ2_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ3_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ3_EN1_SHIFT (3U)
/*! REQ3_EN1 - Writing a 1 to REQ3_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ3_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ3_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ3_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ4_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ4_EN1_SHIFT (4U)
/*! REQ4_EN1 - Writing a 1 to REQ4_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ4_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ4_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ4_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ5_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ5_EN1_SHIFT (5U)
/*! REQ5_EN1 - Writing a 1 to REQ5_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ5_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ5_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ5_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ6_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ6_EN1_SHIFT (6U)
/*! REQ6_EN1 - Writing a 1 to REQ6_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ6_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ6_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ6_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ7_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ7_EN1_SHIFT (7U)
/*! REQ7_EN1 - Writing a 1 to REQ7_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ7_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ7_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ7_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ8_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ8_EN1_SHIFT (8U)
/*! REQ8_EN1 - Writing a 1 to REQ8_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ8_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ8_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ8_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ9_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ9_EN1_SHIFT (9U)
/*! REQ9_EN1 - Writing a 1 to REQ9_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ9_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ9_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ9_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ10_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ10_EN1_SHIFT (10U)
/*! REQ10_EN1 - Writing a 1 to REQ10_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ10_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ10_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ10_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ11_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ11_EN1_SHIFT (11U)
/*! REQ11_EN1 - Writing a 1 to REQ11_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ11_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ11_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ11_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ12_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ12_EN1_SHIFT (12U)
/*! REQ12_EN1 - Writing a 1 to REQ12_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ12_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ12_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ12_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ13_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ13_EN1_SHIFT (13U)
/*! REQ13_EN1 - Writing a 1 to REQ13_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ13_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ13_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ13_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ14_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ14_EN1_SHIFT (14U)
/*! REQ14_EN1 - Writing a 1 to REQ14_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ14_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ14_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ14_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ15_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ15_EN1_SHIFT (15U)
/*! REQ15_EN1 - Writing a 1 to REQ15_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ15_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ15_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ15_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ16_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ16_EN1_SHIFT (16U)
/*! REQ16_EN1 - Writing a 1 to REQ16_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ16_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ16_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ16_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ17_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ17_EN1_SHIFT (17U)
/*! REQ17_EN1 - Writing a 1 to REQ17_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ17_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ17_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ17_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ18_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ18_EN1_SHIFT (18U)
/*! REQ18_EN1 - Writing a 1 to REQ18_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ18_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ18_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ18_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ19_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ19_EN1_SHIFT (19U)
/*! REQ19_EN1 - Writing a 1 to REQ19_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ19_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ19_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ19_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ20_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ20_EN1_SHIFT (20U)
/*! REQ20_EN1 - Writing a 1 to REQ20_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ20_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ20_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ20_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ21_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ21_EN1_SHIFT (21U)
/*! REQ21_EN1 - Writing a 1 to REQ21_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ21_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ21_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ21_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ22_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ22_EN1_SHIFT (22U)
/*! REQ22_EN1 - Writing a 1 to REQ22_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ22_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ22_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ22_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ23_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ23_EN1_SHIFT (23U)
/*! REQ23_EN1 - Writing a 1 to REQ23_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ23_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ23_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ23_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ24_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ24_EN1_SHIFT (24U)
/*! REQ24_EN1 - Writing a 1 to REQ24_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ24_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ24_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ24_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ25_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ25_EN1_SHIFT (25U)
/*! REQ25_EN1 - Writing a 1 to REQ25_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ25_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ25_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ25_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ26_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ26_EN1_SHIFT (26U)
/*! REQ26_EN1 - Writing a 1 to REQ26_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ26_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ26_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ26_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ27_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ27_EN1_SHIFT (27U)
/*! REQ27_EN1 - Writing a 1 to REQ27_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ27_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ27_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ27_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ28_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ28_EN1_SHIFT (28U)
/*! REQ28_EN1 - Writing a 1 to REQ28_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ28_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ28_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ28_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ29_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ29_EN1_SHIFT (29U)
/*! REQ29_EN1 - Writing a 1 to REQ29_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ29_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ29_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ29_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ30_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ30_EN1_SHIFT (30U)
/*! REQ30_EN1 - Writing a 1 to REQ30_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ30_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ30_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ30_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ31_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ31_EN1_SHIFT (31U)
/*! REQ31_EN1 - Writing a 1 to REQ31_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ31_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ31_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_CLR_REQ31_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE0_TOG - DMA1 Request Enable0 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ1_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ1_EN1_SHIFT (1U)
/*! REQ1_EN1 - Writing a 1 to REQ1_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ1_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ1_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ1_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ2_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ2_EN1_SHIFT (2U)
/*! REQ2_EN1 - Writing a 1 to REQ2_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ2_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ2_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ2_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ3_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ3_EN1_SHIFT (3U)
/*! REQ3_EN1 - Writing a 1 to REQ3_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ3_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ3_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ3_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ4_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ4_EN1_SHIFT (4U)
/*! REQ4_EN1 - Writing a 1 to REQ4_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ4_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ4_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ4_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ5_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ5_EN1_SHIFT (5U)
/*! REQ5_EN1 - Writing a 1 to REQ5_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ5_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ5_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ5_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ6_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ6_EN1_SHIFT (6U)
/*! REQ6_EN1 - Writing a 1 to REQ6_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ6_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ6_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ6_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ7_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ7_EN1_SHIFT (7U)
/*! REQ7_EN1 - Writing a 1 to REQ7_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ7_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ7_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ7_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ8_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ8_EN1_SHIFT (8U)
/*! REQ8_EN1 - Writing a 1 to REQ8_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ8_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ8_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ8_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ9_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ9_EN1_SHIFT (9U)
/*! REQ9_EN1 - Writing a 1 to RE9_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ9_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ9_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ9_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ10_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ10_EN1_SHIFT (10U)
/*! REQ10_EN1 - Writing a 1 to REQ10_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ10_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ10_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ10_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ11_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ11_EN1_SHIFT (11U)
/*! REQ11_EN1 - Writing a 1 to REQ11_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ11_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ11_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ11_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ12_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ12_EN1_SHIFT (12U)
/*! REQ12_EN1 - Writing a 1 to REQ12_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ12_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ12_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ12_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ13_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ13_EN1_SHIFT (13U)
/*! REQ13_EN1 - Writing a 1 to REQ13_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ13_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ13_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ13_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ14_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ14_EN1_SHIFT (14U)
/*! REQ14_EN1 - Writing a 1 to REQ14_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ14_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ14_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ14_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ15_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ15_EN1_SHIFT (15U)
/*! REQ15_EN1 - Writing a 1 to REQ15_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ15_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ15_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ15_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ16_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ16_EN1_SHIFT (16U)
/*! REQ16_EN1 - Writing a 1 to REQ16_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ16_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ16_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ16_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ17_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ17_EN1_SHIFT (17U)
/*! REQ17_EN1 - Writing a 1 to REQ17_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ17_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ17_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ17_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ18_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ18_EN1_SHIFT (18U)
/*! REQ18_EN1 - Writing a 1 to REQ18_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ18_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ18_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ18_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ19_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ19_EN1_SHIFT (19U)
/*! REQ19_EN1 - Writing a 1 to REQ19_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ19_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ19_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ19_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ20_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ20_EN1_SHIFT (20U)
/*! REQ20_EN1 - Writing a 1 to REQ20_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ20_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ20_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ20_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ21_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ21_EN1_SHIFT (21U)
/*! REQ21_EN1 - Writing a 1 to REQ21_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ21_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ21_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ21_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ22_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ22_EN1_SHIFT (22U)
/*! REQ22_EN1 - Writing a 1 to REQ22_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ22_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ22_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ22_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ23_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ23_EN1_SHIFT (23U)
/*! REQ23_EN1 - Writing a 1 to REQ23_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ23_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ23_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ23_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ24_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ24_EN1_SHIFT (24U)
/*! REQ24_EN1 - Writing a 1 to REQ24_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ24_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ24_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ24_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ25_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ25_EN1_SHIFT (25U)
/*! REQ25_EN1 - Writing a 1 to REQ25_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ25_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ25_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ25_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ26_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ26_EN1_SHIFT (26U)
/*! REQ26_EN1 - Writing a 1 to REQ26_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ26_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ26_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ26_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ27_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ27_EN1_SHIFT (27U)
/*! REQ27_EN1 - Writing a 1 to REQ27_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ27_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ27_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ27_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ28_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ28_EN1_SHIFT (28U)
/*! REQ28_EN1 - Writing a 1 to REQ28_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ28_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ28_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ28_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ29_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ29_EN1_SHIFT (29U)
/*! REQ29_EN1 - Writing a 1 to REQ29_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ29_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ29_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ29_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ30_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ30_EN1_SHIFT (30U)
/*! REQ30_EN1 - Writing a 1 to REQ30_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ30_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ30_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ30_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ31_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ31_EN1_SHIFT (31U)
/*! REQ31_EN1 - Writing a 1 to REQ31_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE0. */
#define INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ31_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ31_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE0_TOG_REQ31_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE1 - DMA1 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ32_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ32_EN1_SHIFT (0U)
/*! REQ32_EN1 - This register is used to enable and disable EVTG0 OUT0B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ32_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ32_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ32_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ33_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ33_EN1_SHIFT (1U)
/*! REQ33_EN1 - This register is used to enable and disable EVTG0 OUT1A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ33_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ33_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ33_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ34_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ34_EN1_SHIFT (2U)
/*! REQ34_EN1 - This register is used to enable and disable EVTG0 OUT1B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ34_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ34_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ34_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ35_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ35_EN1_SHIFT (3U)
/*! REQ35_EN1 - This register is used to enable and disable EVTG0 OUT2A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ35_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ35_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ35_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ36_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ36_EN1_SHIFT (4U)
/*! REQ36_EN1 - This register is used to enable and disable EVTG0 OUT2B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ36_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ36_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ36_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ37_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ37_EN1_SHIFT (5U)
/*! REQ37_EN1 - This register is used to enable and disable EVTG0 OUT3A request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ37_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ37_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ37_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ38_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ38_EN1_SHIFT (6U)
/*! REQ38_EN1 - This register is used to enable and disable EVTG0 OUT3B request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ38_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ38_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ38_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ39_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ39_EN1_SHIFT (7U)
/*! REQ39_EN1 - This register is used to enable and disable PWM0 Req_capt0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ39_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ39_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ39_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ40_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ40_EN1_SHIFT (8U)
/*! REQ40_EN1 - This register is used to enable and disable PWM0 Req_capt1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ40_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ40_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ40_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ41_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ41_EN1_SHIFT (9U)
/*! REQ41_EN1 - This register is used to enable and disable PWM0 Req_capt2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ41_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ41_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ41_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ42_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ42_EN1_SHIFT (10U)
/*! REQ42_EN1 - This register is used to enable and disable PWM0 Req_capt3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ42_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ42_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ42_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ43_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ43_EN1_SHIFT (11U)
/*! REQ43_EN1 - This register is used to enable and disable PWM0 Req_val0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ43_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ43_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ43_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ44_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ44_EN1_SHIFT (12U)
/*! REQ44_EN1 - This register is used to enable and disable PWM0 Req_val1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ44_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ44_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ44_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ45_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ45_EN1_SHIFT (13U)
/*! REQ45_EN1 - This register is used to enable and disable PWM0 Req_val2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ45_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ45_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ45_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ46_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ46_EN1_SHIFT (14U)
/*! REQ46_EN1 - This register is used to enable and disable PWM0 Req_val3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ46_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ46_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ46_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ47_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ47_EN1_SHIFT (15U)
/*! REQ47_EN1 - This register is used to enable and disable PWM1 Req_capt0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ47_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ47_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ47_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ48_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ48_EN1_SHIFT (16U)
/*! REQ48_EN1 - This register is used to enable and disable PWM1 Req_capt1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ48_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ48_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ48_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ49_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ49_EN1_SHIFT (17U)
/*! REQ49_EN1 - This register is used to enable and disable PWM1 Req_capt2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ49_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ49_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ49_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ50_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ50_EN1_SHIFT (18U)
/*! REQ50_EN1 - This register is used to enable and disable PWM1 Req_capt3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ50_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ50_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ50_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ51_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ51_EN1_SHIFT (19U)
/*! REQ51_EN1 - This register is used to enable and disable PWM1 Req_val0 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ51_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ51_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ51_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ52_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ52_EN1_SHIFT (20U)
/*! REQ52_EN1 - This register is used to enable and disable PWM1 Req_val1 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ52_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ52_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ52_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ53_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ53_EN1_SHIFT (21U)
/*! REQ53_EN1 - This register is used to enable and disable PWM1 Req_val2 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ53_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ53_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ53_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ54_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ54_EN1_SHIFT (22U)
/*! REQ54_EN1 - This register is used to enable and disable PWM1 Req_val3 request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ54_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ54_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ54_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ57_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ57_EN1_SHIFT (25U)
/*! REQ57_EN1 - This register is used to enable and disable LPTMR0 counter match event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ57_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ57_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ57_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ58_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ58_EN1_SHIFT (26U)
/*! REQ58_EN1 - This register is used to enable and disable LPTMR1 counter match event request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ58_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ58_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ58_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ59_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ59_EN1_SHIFT (27U)
/*! REQ59_EN1 - This register is used to enable and disable CAN0 DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ59_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ59_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ59_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ60_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ60_EN1_SHIFT (28U)
/*! REQ60_EN1 - This register is used to enable and disable CAN1 DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ60_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ60_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ60_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ61_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ61_EN1_SHIFT (29U)
/*! REQ61_EN1 - This register is used to enable and disable FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ61_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ61_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ61_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ62_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ62_EN1_SHIFT (30U)
/*! REQ62_EN1 - This register is used to enable and disable FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ62_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ62_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ62_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_REQ63_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ63_EN1_SHIFT (31U)
/*! REQ63_EN1 - This register is used to enable and disable FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE1_REQ63_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_REQ63_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_REQ63_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE1_SET - DMA1 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ32_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ32_EN1_SHIFT (0U)
/*! REQ32_EN1 - Writing a 1 to REQ32_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ32_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ32_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ32_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ33_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ33_EN1_SHIFT (1U)
/*! REQ33_EN1 - Writing a 1 to REQ33_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ33_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ33_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ33_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ34_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ34_EN1_SHIFT (2U)
/*! REQ34_EN1 - Writing a 1 to REQ34_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ34_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ34_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ34_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ35_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ35_EN1_SHIFT (3U)
/*! REQ35_EN1 - Writing a 1 to REQ35_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ35_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ35_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ35_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ36_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ36_EN1_SHIFT (4U)
/*! REQ36_EN1 - Writing a 1 to REQ36_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ36_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ36_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ36_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ37_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ37_EN1_SHIFT (5U)
/*! REQ37_EN1 - Writing a 1 to REQ37_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ37_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ37_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ37_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ38_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ38_EN1_SHIFT (6U)
/*! REQ38_EN1 - Writing a 1 to REQ38_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ38_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ38_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ38_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ39_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ39_EN1_SHIFT (7U)
/*! REQ39_EN1 - Writing a 1 to REQ39_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ39_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ39_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ39_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ40_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ40_EN1_SHIFT (8U)
/*! REQ40_EN1 - Writing a 1 to REQ40_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ40_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ40_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ40_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ41_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ41_EN1_SHIFT (9U)
/*! REQ41_EN1 - Writing a 1 to REQ41_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ41_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ41_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ41_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ42_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ42_EN1_SHIFT (10U)
/*! REQ42_EN1 - Writing a 1 to REQ42_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ42_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ42_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ42_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ43_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ43_EN1_SHIFT (11U)
/*! REQ43_EN1 - Writing a 1 to REQ43_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ43_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ43_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ43_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ44_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ44_EN1_SHIFT (12U)
/*! REQ44_EN1 - Writing a 1 to REQ44_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ44_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ44_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ44_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ45_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ45_EN1_SHIFT (13U)
/*! REQ45_EN1 - Writing a 1 to REQ45_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ45_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ45_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ45_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ46_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ46_EN1_SHIFT (14U)
/*! REQ46_EN1 - Writing a 1 to REQ46_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ46_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ46_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ46_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ47_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ47_EN1_SHIFT (15U)
/*! REQ47_EN1 - Writing a 1 to REQ47_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ47_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ47_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ47_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ48_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ48_EN1_SHIFT (16U)
/*! REQ48_EN1 - Writing a 1 to REQ48_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ48_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ48_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ48_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ49_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ49_EN1_SHIFT (17U)
/*! REQ49_EN1 - Writing a 1 to REQ49_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ49_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ49_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ49_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ50_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ50_EN1_SHIFT (18U)
/*! REQ50_EN1 - Writing a 1 to REQ50_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ50_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ50_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ50_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ51_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ51_EN1_SHIFT (19U)
/*! REQ51_EN1 - Writing a 1 to REQ51_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ51_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ51_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ51_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ52_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ52_EN1_SHIFT (20U)
/*! REQ52_EN1 - Writing a 1 to REQ52_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ52_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ52_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ52_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ53_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ53_EN1_SHIFT (21U)
/*! REQ53_EN1 - Writing a 1 to REQ53_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ53_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ53_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ53_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ54_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ54_EN1_SHIFT (22U)
/*! REQ54_EN1 - Writing a 1 to REQ54_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ54_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ54_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ54_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ57_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ57_EN1_SHIFT (25U)
/*! REQ57_EN1 - Writing a 1 to REQ57_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ57_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ57_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ57_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ58_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ58_EN1_SHIFT (26U)
/*! REQ58_EN1 - Writing a 1 to REQ58_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ58_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ58_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ58_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ59_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ59_EN1_SHIFT (27U)
/*! REQ59_EN1 - Writing a 1 to REQ59_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ59_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ59_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ59_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ60_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ60_EN1_SHIFT (28U)
/*! REQ60_EN1 - Writing a 1 to REQ60_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ60_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ60_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ60_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ61_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ61_EN1_SHIFT (29U)
/*! REQ61_EN1 - Writing a 1 to REQ61_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ61_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ61_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ61_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ62_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ62_EN1_SHIFT (30U)
/*! REQ62_EN1 - Writing a 1 to REQ62_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ62_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ62_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ62_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ63_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ63_EN1_SHIFT (31U)
/*! REQ63_EN1 - Writing a 1 to REQ63_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ63_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ63_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_SET_REQ63_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE1_CLR - DMA1 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ32_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ32_EN1_SHIFT (0U)
/*! REQ32_EN1 - Writing a 1 to REQ32_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ32_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ32_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ32_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ33_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ33_EN1_SHIFT (1U)
/*! REQ33_EN1 - Writing a 1 to REQ33_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ33_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ33_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ33_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ34_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ34_EN1_SHIFT (2U)
/*! REQ34_EN1 - Writing a 1 to REQ34_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ34_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ34_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ34_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ35_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ35_EN1_SHIFT (3U)
/*! REQ35_EN1 - Writing a 1 to REQ35_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ35_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ35_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ35_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ36_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ36_EN1_SHIFT (4U)
/*! REQ36_EN1 - Writing a 1 to REQ36_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ36_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ36_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ36_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ37_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ37_EN1_SHIFT (5U)
/*! REQ37_EN1 - Writing a 1 to REQ37_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ37_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ37_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ37_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ38_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ38_EN1_SHIFT (6U)
/*! REQ38_EN1 - Writing a 1 to REQ38_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ38_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ38_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ38_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ39_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ39_EN1_SHIFT (7U)
/*! REQ39_EN1 - Writing a 1 to REQ39_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ39_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ39_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ39_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ40_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ40_EN1_SHIFT (8U)
/*! REQ40_EN1 - Writing a 1 to REQ40_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ40_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ40_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ40_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ41_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ41_EN1_SHIFT (9U)
/*! REQ41_EN1 - Writing a 1 to REQ41_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ41_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ41_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ41_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ42_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ42_EN1_SHIFT (10U)
/*! REQ42_EN1 - Writing a 1 to REQ42_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ42_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ42_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ42_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ43_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ43_EN1_SHIFT (11U)
/*! REQ43_EN1 - Writing a 1 to REQ43_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ43_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ43_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ43_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ44_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ44_EN1_SHIFT (12U)
/*! REQ44_EN1 - Writing a 1 to REQ44_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ44_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ44_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ44_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ45_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ45_EN1_SHIFT (13U)
/*! REQ45_EN1 - Writing a 1 to REQ45_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ45_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ45_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ45_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ46_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ46_EN1_SHIFT (14U)
/*! REQ46_EN1 - Writing a 1 to REQ46_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ46_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ46_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ46_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ47_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ47_EN1_SHIFT (15U)
/*! REQ47_EN1 - Writing a 1 to REQ47_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ47_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ47_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ47_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ48_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ48_EN1_SHIFT (16U)
/*! REQ48_EN1 - Writing a 1 to REQ48_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ48_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ48_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ48_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ49_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ49_EN1_SHIFT (17U)
/*! REQ49_EN1 - Writing a 1 to REQ49_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ49_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ49_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ49_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ50_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ50_EN1_SHIFT (18U)
/*! REQ50_EN1 - Writing a 1 to REQ50_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ50_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ50_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ50_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ51_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ51_EN1_SHIFT (19U)
/*! REQ51_EN1 - Writing a 1 to REQ51_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ51_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ51_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ51_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ52_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ52_EN1_SHIFT (20U)
/*! REQ52_EN1 - Writing a 1 to REQ52_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ52_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ52_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ52_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ53_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ53_EN1_SHIFT (21U)
/*! REQ53_EN1 - Writing a 1 to REQ53_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ53_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ53_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ53_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ54_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ54_EN1_SHIFT (22U)
/*! REQ54_EN1 - Writing a 1 to REQ54_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ54_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ54_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ54_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ57_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ57_EN1_SHIFT (25U)
/*! REQ57_EN1 - Writing a 1 to REQ57_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ57_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ57_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ57_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ58_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ58_EN1_SHIFT (26U)
/*! REQ58_EN1 - Writing a 1 to REQ58_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ58_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ58_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ58_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ59_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ59_EN1_SHIFT (27U)
/*! REQ59_EN1 - Writing a 1 to REQ59_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ59_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ59_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ59_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ60_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ60_EN1_SHIFT (28U)
/*! REQ60_EN1 - Writing a 1 to REQ60_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ60_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ60_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ60_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ61_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ61_EN1_SHIFT (29U)
/*! REQ61_EN1 - Writing a 1 to REQ61_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ61_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ61_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ61_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ62_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ62_EN1_SHIFT (30U)
/*! REQ62_EN1 - Writing a 1 to REQ62_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ62_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ62_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ62_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ63_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ63_EN1_SHIFT (31U)
/*! REQ63_EN1 - Writing a 1 to REQ63_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ63_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ63_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_CLR_REQ63_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE1_TOG - DMA1 Request Enable1 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ32_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ32_EN1_SHIFT (0U)
/*! REQ32_EN1 - Writing a 1 to REQ32_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ32_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ32_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ32_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ33_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ33_EN1_SHIFT (1U)
/*! REQ33_EN1 - Writing a 1 to REQ33_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ33_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ33_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ33_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ34_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ34_EN1_SHIFT (2U)
/*! REQ34_EN1 - Writing a 1 to REQ34_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ34_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ34_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ34_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ35_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ35_EN1_SHIFT (3U)
/*! REQ35_EN1 - Writing a 1 to REQ35_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ35_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ35_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ35_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ36_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ36_EN1_SHIFT (4U)
/*! REQ36_EN1 - Writing a 1 to REQ36_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ36_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ36_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ36_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ37_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ37_EN1_SHIFT (5U)
/*! REQ37_EN1 - Writing a 1 to REQ37_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ37_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ37_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ37_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ38_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ38_EN1_SHIFT (6U)
/*! REQ38_EN1 - Writing a 1 to REQ38_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ38_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ38_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ38_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ39_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ39_EN1_SHIFT (7U)
/*! REQ39_EN1 - Writing a 1 to REQ39_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ39_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ39_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ39_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ40_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ40_EN1_SHIFT (8U)
/*! REQ40_EN1 - Writing a 1 to REQ40_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ40_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ40_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ40_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ41_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ41_EN1_SHIFT (9U)
/*! REQ41_EN1 - Writing a 1 to REQ41_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ41_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ41_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ41_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ42_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ42_EN1_SHIFT (10U)
/*! REQ42_EN1 - Writing a 1 to REQ42_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ42_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ42_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ42_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ43_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ43_EN1_SHIFT (11U)
/*! REQ43_EN1 - Writing a 1 to REQ43_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ43_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ43_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ43_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ44_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ44_EN1_SHIFT (12U)
/*! REQ44_EN1 - Writing a 1 to REQ44_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ44_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ44_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ44_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ45_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ45_EN1_SHIFT (13U)
/*! REQ45_EN1 - Writing a 1 to REQ55_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ45_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ45_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ45_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ46_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ46_EN1_SHIFT (14U)
/*! REQ46_EN1 - Writing a 1 to REQ46_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ46_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ46_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ46_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ47_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ47_EN1_SHIFT (15U)
/*! REQ47_EN1 - Writing a 1 to REQ47_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ47_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ47_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ47_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ48_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ48_EN1_SHIFT (16U)
/*! REQ48_EN1 - Writing a 1 to REQ48_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ48_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ48_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ48_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ49_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ49_EN1_SHIFT (17U)
/*! REQ49_EN1 - Writing a 1 to REQ49_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ49_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ49_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ49_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ50_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ50_EN1_SHIFT (18U)
/*! REQ50_EN1 - Writing a 1 to REQ50_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ50_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ50_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ50_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ51_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ51_EN1_SHIFT (19U)
/*! REQ51_EN1 - Writing a 1 to REQ51_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ51_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ51_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ51_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ52_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ52_EN1_SHIFT (20U)
/*! REQ52_EN1 - Writing a 1 to REQ52_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ52_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ52_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ52_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ53_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ53_EN1_SHIFT (21U)
/*! REQ53_EN1 - Writing a 1 to REQ53_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ53_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ53_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ53_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ54_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ54_EN1_SHIFT (22U)
/*! REQ54_EN1 - Writing a 1 to REQ54_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ54_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ54_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ54_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ57_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ57_EN1_SHIFT (25U)
/*! REQ57_EN1 - Writing a 1 to REQ57_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ57_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ57_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ57_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ58_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ58_EN1_SHIFT (26U)
/*! REQ58_EN1 - Writing a 1 to REQ58_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ58_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ58_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ58_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ59_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ59_EN1_SHIFT (27U)
/*! REQ59_EN1 - Writing a 1 to REQ59_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ59_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ59_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ59_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ60_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ60_EN1_SHIFT (28U)
/*! REQ60_EN1 - Writing a 1 to REQ60_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ60_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ60_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ60_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ61_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ61_EN1_SHIFT (29U)
/*! REQ61_EN1 - Writing a 1 to REQ61_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ61_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ61_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ61_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ62_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ62_EN1_SHIFT (30U)
/*! REQ62_EN1 - Writing a 1 to REQ62_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ62_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ62_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ62_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ63_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ63_EN1_SHIFT (31U)
/*! REQ63_EN1 - Writing a 1 to REQ63_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE1. */
#define INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ63_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ63_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE1_TOG_REQ63_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE2 - DMA1 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ64_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ64_EN1_SHIFT (0U)
/*! REQ64_EN1 - This register is used to enable and disable FlexIO0 Shifter3 Status DMA request OR Timer3 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ64_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ64_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ64_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ65_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ65_EN1_SHIFT (1U)
/*! REQ65_EN1 - This register is used to enable and disable FlexIO0 Shifter4 Status DMA request OR Timer4 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ65_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ65_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ65_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ66_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ66_EN1_SHIFT (2U)
/*! REQ66_EN1 - This register is used to enable and disable FlexIO0 Shifter5 Status DMA request OR Timer5 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ66_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ66_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ66_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ67_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ67_EN1_SHIFT (3U)
/*! REQ67_EN1 - This register is used to enable and disable FlexIO0 Shifter6 Status DMA request OR Timer6 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ67_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ67_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ67_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ68_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ68_EN1_SHIFT (4U)
/*! REQ68_EN1 - This register is used to enable and disable FlexIO0 Shifter7 Status DMA request OR Timer7 Status DMA request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ68_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ68_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ68_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ69_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ69_EN1_SHIFT (5U)
/*! REQ69_EN1 - This register is used to enable and disable LP_FLEXCOMM0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ69_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ69_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ69_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ70_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ70_EN1_SHIFT (6U)
/*! REQ70_EN1 - This register is used to enable and disable LP_FLEXCOMM0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ70_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ70_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ70_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ71_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ71_EN1_SHIFT (7U)
/*! REQ71_EN1 - This register is used to enable and disable LP_FLEXCOMM1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ71_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ71_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ71_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ72_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ72_EN1_SHIFT (8U)
/*! REQ72_EN1 - This register is used to enable and disable LP_FLEXCOMM1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ72_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ72_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ72_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ73_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ73_EN1_SHIFT (9U)
/*! REQ73_EN1 - This register is used to enable and disable LP_FLEXCOMM2 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ73_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ73_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ73_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ74_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ74_EN1_SHIFT (10U)
/*! REQ74_EN1 - This register is used to enable and disable LP_FLEXCOMM2 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ74_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ74_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ74_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ75_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ75_EN1_SHIFT (11U)
/*! REQ75_EN1 - This register is used to enable and disable LP_FLEXCOMM3 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ75_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ75_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ75_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ76_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ76_EN1_SHIFT (12U)
/*! REQ76_EN1 - This register is used to enable and disable LP_FLEXCOMM3 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ76_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ76_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ76_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ77_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ77_EN1_SHIFT (13U)
/*! REQ77_EN1 - This register is used to enable and disable LP_FLEXCOMM4 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ77_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ77_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ77_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ78_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ78_EN1_SHIFT (14U)
/*! REQ78_EN1 - This register is used to enable and disable LP_FLEXCOMM4 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ78_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ78_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ78_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ79_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ79_EN1_SHIFT (15U)
/*! REQ79_EN1 - This register is used to enable and disable LP_FLEXCOMM5 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ79_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ79_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ79_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ80_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ80_EN1_SHIFT (16U)
/*! REQ80_EN1 - This register is used to enable and disable LP_FLEXCOMM5 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ80_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ80_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ80_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ81_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ81_EN1_SHIFT (17U)
/*! REQ81_EN1 - This register is used to enable and disable LP_FLEXCOMM6 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ81_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ81_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ81_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ82_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ82_EN1_SHIFT (18U)
/*! REQ82_EN1 - This register is used to enable and disable LP_FLEXCOMM6 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ82_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ82_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ82_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ83_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ83_EN1_SHIFT (19U)
/*! REQ83_EN1 - This register is used to enable and disable LP_FLEXCOMM7 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ83_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ83_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ83_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ84_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ84_EN1_SHIFT (20U)
/*! REQ84_EN1 - This register is used to enable and disable LP_FLEXCOMM7 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ84_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ84_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ84_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ85_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ85_EN1_SHIFT (21U)
/*! REQ85_EN1 - This register is used to enable and disable LP_FLEXCOMM8 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ85_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ85_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ85_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ86_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ86_EN1_SHIFT (22U)
/*! REQ86_EN1 - This register is used to enable and disable LP_FLEXCOMM8 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ86_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ86_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ86_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ87_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ87_EN1_SHIFT (23U)
/*! REQ87_EN1 - This register is used to enable and disable LP_FLEXCOMM9 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ87_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ87_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ87_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ88_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ88_EN1_SHIFT (24U)
/*! REQ88_EN1 - This register is used to enable and disable LP_FLEXCOMM9 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ88_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ88_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ88_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ91_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ91_EN1_SHIFT (27U)
/*! REQ91_EN1 - This register is used to enable and disable EMVSIM0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ91_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ91_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ91_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ92_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ92_EN1_SHIFT (28U)
/*! REQ92_EN1 - This register is used to enable and disable EMVSIM0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ92_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ92_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ92_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ93_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ93_EN1_SHIFT (29U)
/*! REQ93_EN1 - This register is used to enable and disable EMVSIM1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ93_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ93_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ93_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ94_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ94_EN1_SHIFT (30U)
/*! REQ94_EN1 - This register is used to enable and disable EMVSIM1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ94_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ94_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ94_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_REQ95_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ95_EN1_SHIFT (31U)
/*! REQ95_EN1 - This register is used to enable and disable I3C0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE2_REQ95_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_REQ95_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_REQ95_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE2_SET - DMA1 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ64_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ64_EN1_SHIFT (0U)
/*! REQ64_EN1 - Writing a 1 to REQ64_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ64_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ64_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ64_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ65_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ65_EN1_SHIFT (1U)
/*! REQ65_EN1 - Writing a 1 to REQ65_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ65_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ65_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ65_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ66_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ66_EN1_SHIFT (2U)
/*! REQ66_EN1 - Writing a 1 to REQ66_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ66_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ66_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ66_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ67_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ67_EN1_SHIFT (3U)
/*! REQ67_EN1 - Writing a 1 to REQ67_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ67_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ67_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ67_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ68_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ68_EN1_SHIFT (4U)
/*! REQ68_EN1 - Writing a 1 to REQ68_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ68_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ68_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ68_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ69_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ69_EN1_SHIFT (5U)
/*! REQ69_EN1 - Writing a 1 to REQ69_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ69_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ69_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ69_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ70_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ70_EN1_SHIFT (6U)
/*! REQ70_EN1 - Writing a 1 to REQ70_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ70_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ70_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ70_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ71_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ71_EN1_SHIFT (7U)
/*! REQ71_EN1 - Writing a 1 to REQ71_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ71_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ71_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ71_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ72_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ72_EN1_SHIFT (8U)
/*! REQ72_EN1 - Writing a 1 to REQ72_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ72_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ72_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ72_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ73_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ73_EN1_SHIFT (9U)
/*! REQ73_EN1 - Writing a 1 to REQ73_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ73_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ73_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ73_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ74_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ74_EN1_SHIFT (10U)
/*! REQ74_EN1 - Writing a 1 to REQ74_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ74_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ74_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ74_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ75_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ75_EN1_SHIFT (11U)
/*! REQ75_EN1 - Writing a 1 to REQ75_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ75_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ75_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ75_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ76_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ76_EN1_SHIFT (12U)
/*! REQ76_EN1 - Writing a 1 to REQ876_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ76_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ76_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ76_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ77_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ77_EN1_SHIFT (13U)
/*! REQ77_EN1 - Writing a 1 to REQ77_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ77_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ77_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ77_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ78_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ78_EN1_SHIFT (14U)
/*! REQ78_EN1 - Writing a 1 to REQ78_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ78_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ78_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ78_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ79_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ79_EN1_SHIFT (15U)
/*! REQ79_EN1 - Writing a 1 to REQ79_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ79_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ79_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ79_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ80_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ80_EN1_SHIFT (16U)
/*! REQ80_EN1 - Writing a 1 to REQ80_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ80_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ80_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ80_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ81_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ81_EN1_SHIFT (17U)
/*! REQ81_EN1 - Writing a 1 to REQ81_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ81_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ81_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ81_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ82_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ82_EN1_SHIFT (18U)
/*! REQ82_EN1 - Writing a 1 to REQ82_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ82_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ82_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ82_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ83_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ83_EN1_SHIFT (19U)
/*! REQ83_EN1 - Writing a 1 to REQ83_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ83_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ83_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ83_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ84_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ84_EN1_SHIFT (20U)
/*! REQ84_EN1 - Writing a 1 to REQ84_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ84_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ84_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ84_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ85_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ85_EN1_SHIFT (21U)
/*! REQ85_EN1 - Writing a 1 to REQ85_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ85_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ85_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ85_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ86_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ86_EN1_SHIFT (22U)
/*! REQ86_EN1 - Writing a 1 to REQ86_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ86_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ86_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ86_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ87_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ87_EN1_SHIFT (23U)
/*! REQ87_EN1 - Writing a 1 to REQ87_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ87_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ87_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ87_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ88_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ88_EN1_SHIFT (24U)
/*! REQ88_EN1 - Writing a 1 to REQ88_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ88_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ88_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ88_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ89_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ89_EN1_SHIFT (25U)
/*! REQ89_EN1 - Writing a 1 to REQ89_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ89_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ89_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ89_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ90_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ90_EN1_SHIFT (26U)
/*! REQ90_EN1 - Writing a 1 to REQ90_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ90_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ90_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ90_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ91_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ91_EN1_SHIFT (27U)
/*! REQ91_EN1 - Writing a 1 to REQ91_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ91_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ91_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ91_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ92_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ92_EN1_SHIFT (28U)
/*! REQ92_EN1 - Writing a 1 to REQ92_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ92_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ92_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ92_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ93_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ93_EN1_SHIFT (29U)
/*! REQ93_EN1 - Writing a 1 to REQ93_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ93_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ93_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ93_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ94_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ94_EN1_SHIFT (30U)
/*! REQ94_EN1 - Writing a 1 to REQ94_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ94_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ94_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ94_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ95_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ95_EN1_SHIFT (31U)
/*! REQ95_EN1 - Writing a 1 to REQ95_EN1 in this register sets the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ95_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ95_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_SET_REQ95_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE2_CLR - DMA1 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ64_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ64_EN1_SHIFT (0U)
/*! REQ64_EN1 - Writing a 1 to REQ64_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ64_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ64_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ64_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ65_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ65_EN1_SHIFT (1U)
/*! REQ65_EN1 - Writing a 1 to REQ65_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ65_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ65_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ65_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ66_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ66_EN1_SHIFT (2U)
/*! REQ66_EN1 - Writing a 1 to REQ66_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ66_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ66_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ66_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ67_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ67_EN1_SHIFT (3U)
/*! REQ67_EN1 - Writing a 1 to REQ67_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ67_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ67_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ67_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ68_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ68_EN1_SHIFT (4U)
/*! REQ68_EN1 - Writing a 1 to REQ68_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ68_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ68_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ68_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ69_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ69_EN1_SHIFT (5U)
/*! REQ69_EN1 - Writing a 1 to REQ69_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ69_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ69_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ69_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ70_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ70_EN1_SHIFT (6U)
/*! REQ70_EN1 - Writing a 1 to REQ70_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ70_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ70_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ70_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ71_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ71_EN1_SHIFT (7U)
/*! REQ71_EN1 - Writing a 1 to REQ71_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ71_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ71_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ71_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ72_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ72_EN1_SHIFT (8U)
/*! REQ72_EN1 - Writing a 1 to REQ72_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ72_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ72_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ72_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ73_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ73_EN1_SHIFT (9U)
/*! REQ73_EN1 - Writing a 1 to REQ73_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ73_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ73_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ73_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ74_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ74_EN1_SHIFT (10U)
/*! REQ74_EN1 - Writing a 1 to REQ74_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ74_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ74_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ74_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ75_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ75_EN1_SHIFT (11U)
/*! REQ75_EN1 - Writing a 1 to REQ75_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ75_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ75_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ75_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ76_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ76_EN1_SHIFT (12U)
/*! REQ76_EN1 - Writing a 1 to REQ76_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ76_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ76_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ76_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ77_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ77_EN1_SHIFT (13U)
/*! REQ77_EN1 - Writing a 1 to REQ77_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ77_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ77_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ77_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ78_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ78_EN1_SHIFT (14U)
/*! REQ78_EN1 - Writing a 1 to REQ78_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ78_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ78_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ78_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ79_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ79_EN1_SHIFT (15U)
/*! REQ79_EN1 - Writing a 1 to REQ79_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ79_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ79_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ79_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ80_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ80_EN1_SHIFT (16U)
/*! REQ80_EN1 - Writing a 1 to REQ80_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ80_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ80_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ80_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ81_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ81_EN1_SHIFT (17U)
/*! REQ81_EN1 - Writing a 1 to REQ81_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ81_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ81_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ81_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ82_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ82_EN1_SHIFT (18U)
/*! REQ82_EN1 - Writing a 1 to REQ82_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ82_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ82_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ82_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ83_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ83_EN1_SHIFT (19U)
/*! REQ83_EN1 - Writing a 1 to REQ83_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ83_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ83_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ83_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ84_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ84_EN1_SHIFT (20U)
/*! REQ84_EN1 - Writing a 1 to REQ84_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ84_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ84_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ84_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ85_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ85_EN1_SHIFT (21U)
/*! REQ85_EN1 - Writing a 1 to REQ85_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ85_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ85_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ85_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ86_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ86_EN1_SHIFT (22U)
/*! REQ86_EN1 - Writing a 1 to REQ86_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ86_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ86_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ86_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ87_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ87_EN1_SHIFT (23U)
/*! REQ87_EN1 - Writing a 1 to REQ87_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ87_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ87_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ87_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ88_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ88_EN1_SHIFT (24U)
/*! REQ88_EN1 - Writing a 1 to REQ88_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ88_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ88_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ88_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ89_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ89_EN1_SHIFT (25U)
/*! REQ89_EN1 - Writing a 1 to REQ89_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ89_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ89_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ89_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ90_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ90_EN1_SHIFT (26U)
/*! REQ90_EN1 - Writing a 1 to REQ90_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ90_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ90_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ90_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ91_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ91_EN1_SHIFT (27U)
/*! REQ91_EN1 - Writing a 1 to REQ91_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ91_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ91_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ91_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ92_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ92_EN1_SHIFT (28U)
/*! REQ92_EN1 - Writing a 1 to REQ92_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ92_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ92_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ92_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ93_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ93_EN1_SHIFT (29U)
/*! REQ93_EN1 - Writing a 1 to REQ93_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ93_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ93_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ93_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ94_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ94_EN1_SHIFT (30U)
/*! REQ94_EN1 - Writing a 1 to REQ94_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ94_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ94_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ94_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ95_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ95_EN1_SHIFT (31U)
/*! REQ95_EN1 - Writing a 1 to REQ95_EN1 in this register clears the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ95_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ95_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_CLR_REQ95_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE2_TOG - DMA1 Request Enable2 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ64_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ64_EN1_SHIFT (0U)
/*! REQ64_EN1 - Writing a 1 to REQ64_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ64_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ64_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ64_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ65_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ65_EN1_SHIFT (1U)
/*! REQ65_EN1 - Writing a 1 to REQ65_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ65_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ65_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ65_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ66_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ66_EN1_SHIFT (2U)
/*! REQ66_EN1 - Writing a 1 to REQ66_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ66_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ66_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ66_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ67_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ67_EN1_SHIFT (3U)
/*! REQ67_EN1 - Writing a 1 to REQ67_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ67_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ67_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ67_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ68_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ68_EN1_SHIFT (4U)
/*! REQ68_EN1 - Writing a 1 to REQ68_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ68_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ68_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ68_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ69_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ69_EN1_SHIFT (5U)
/*! REQ69_EN1 - Writing a 1 to REQ69_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ69_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ69_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ69_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ70_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ70_EN1_SHIFT (6U)
/*! REQ70_EN1 - Writing a 1 to REQ70_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ70_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ70_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ70_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ71_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ71_EN1_SHIFT (7U)
/*! REQ71_EN1 - Writing a 1 to REQ71_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ71_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ71_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ71_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ72_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ72_EN1_SHIFT (8U)
/*! REQ72_EN1 - Writing a 1 to REQ72_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ72_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ72_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ72_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ73_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ73_EN1_SHIFT (9U)
/*! REQ73_EN1 - Writing a 1 to REQ73_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ73_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ73_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ73_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ74_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ74_EN1_SHIFT (10U)
/*! REQ74_EN1 - Writing a 1 to REQ74_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ74_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ74_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ74_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ75_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ75_EN1_SHIFT (11U)
/*! REQ75_EN1 - Writing a 1 to REQ75_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ75_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ75_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ75_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ76_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ76_EN1_SHIFT (12U)
/*! REQ76_EN1 - Writing a 1 to REQ76_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ76_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ76_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ76_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ77_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ77_EN1_SHIFT (13U)
/*! REQ77_EN1 - Writing a 1 to REQ77_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ77_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ77_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ77_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ78_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ78_EN1_SHIFT (14U)
/*! REQ78_EN1 - Writing a 1 to REQ78_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ78_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ78_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ78_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ79_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ79_EN1_SHIFT (15U)
/*! REQ79_EN1 - Writing a 1 to REQ79_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ79_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ79_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ79_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ80_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ80_EN1_SHIFT (16U)
/*! REQ80_EN1 - Writing a 1 to REQ80_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ80_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ80_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ80_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ81_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ81_EN1_SHIFT (17U)
/*! REQ81_EN1 - Writing a 1 to REQ81_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ81_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ81_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ81_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ82_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ82_EN1_SHIFT (18U)
/*! REQ82_EN1 - Writing a 1 to REQ82_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ82_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ82_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ82_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ83_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ83_EN1_SHIFT (19U)
/*! REQ83_EN1 - Writing a 1 to REQ83_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ83_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ83_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ83_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ84_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ84_EN1_SHIFT (20U)
/*! REQ84_EN1 - Writing a 1 to REQ84_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ84_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ84_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ84_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ85_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ85_EN1_SHIFT (21U)
/*! REQ85_EN1 - Writing a 1 to REQ85_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ85_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ85_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ85_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ86_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ86_EN1_SHIFT (22U)
/*! REQ86_EN1 - Writing a 1 to REQ86_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ86_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ86_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ86_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ87_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ87_EN1_SHIFT (23U)
/*! REQ87_EN1 - Writing a 1 to REQ87_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ87_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ87_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ87_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ88_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ88_EN1_SHIFT (24U)
/*! REQ88_EN1 - Writing a 1 to REQ88_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ88_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ88_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ88_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ89_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ89_EN1_SHIFT (25U)
/*! REQ89_EN1 - Writing a 1 to REQ89_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ89_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ89_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ89_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ90_EN1_MASK (0x4000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ90_EN1_SHIFT (26U)
/*! REQ90_EN1 - Writing a 1 to REQ90_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ90_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ90_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ90_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ91_EN1_MASK (0x8000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ91_EN1_SHIFT (27U)
/*! REQ91_EN1 - Writing a 1 to REQ91_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ91_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ91_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ91_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ92_EN1_MASK (0x10000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ92_EN1_SHIFT (28U)
/*! REQ92_EN1 - Writing a 1 to REQ92_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ92_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ92_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ92_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ93_EN1_MASK (0x20000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ93_EN1_SHIFT (29U)
/*! REQ93_EN1 - Writing a 1 to REQ93_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ93_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ93_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ93_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ94_EN1_MASK (0x40000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ94_EN1_SHIFT (30U)
/*! REQ94_EN1 - Writing a 1 to REQ94_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ94_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ94_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ94_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ95_EN1_MASK (0x80000000U)
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ95_EN1_SHIFT (31U)
/*! REQ95_EN1 - Writing a 1 to REQ95_EN1 in this register toggles the corresponding bit in DMA1_REQ_ENABLE2. */
#define INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ95_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ95_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE2_TOG_REQ95_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE3 - DMA1 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ96_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ96_EN1_SHIFT (0U)
/*! REQ96_EN1 - This register is used to enable and disable I3C0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ96_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ96_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ96_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ97_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ97_EN1_SHIFT (1U)
/*! REQ97_EN1 - This register is used to enable and disable I3C1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ97_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ97_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ97_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ98_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ98_EN1_SHIFT (2U)
/*! REQ98_EN1 - This register is used to enable and disable I3C1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ98_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ98_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ98_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ99_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ99_EN1_SHIFT (3U)
/*! REQ99_EN1 - This register is used to enable and disable SAI0 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ99_EN1(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ99_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ99_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ100_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ100_EN1_SHIFT (4U)
/*! REQ100_EN1 - This register is used to enable and disable SAI0 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ100_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ100_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ100_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ101_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ101_EN1_SHIFT (5U)
/*! REQ101_EN1 - This register is used to enable and disable SAI1 receive request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ101_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ101_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ101_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ102_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ102_EN1_SHIFT (6U)
/*! REQ102_EN1 - This register is used to enable and disable SAI1 transmit request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ102_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ102_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ102_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ103_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ103_EN1_SHIFT (7U)
/*! REQ103_EN1 - This register is used to enable and disable SINC0 ipd_req_sinc[0] or ipd_req_alt [0] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ103_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ103_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ103_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ104_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ104_EN1_SHIFT (8U)
/*! REQ104_EN1 - This register is used to enable and disable SINC0 ipd_req_sinc[1] or ipd_req_alt [1] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ104_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ104_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ104_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ105_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ105_EN1_SHIFT (9U)
/*! REQ105_EN1 - This register is used to enable and disable SINC0 ipd_req_sinc[2] or ipd_req_alt [2] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ105_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ105_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ105_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ106_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ106_EN1_SHIFT (10U)
/*! REQ106_EN1 - This register is used to enable and disable SINC0 ipd_req_sinc[3] or ipd_req_alt [3] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ106_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ106_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ106_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ107_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ107_EN1_SHIFT (11U)
/*! REQ107_EN1 - This register is used to enable and disable SINC0 ipd_req_sinc[4] or ipd_req_alt [4] request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ107_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ107_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ107_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ108_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ108_EN1_SHIFT (12U)
/*! REQ108_EN1 - This register is used to enable and disable GPIO0 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ108_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ108_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ108_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ109_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ109_EN1_SHIFT (13U)
/*! REQ109_EN1 - This register is used to enable and disable GPIO0 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ109_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ109_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ109_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ110_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ110_EN1_SHIFT (14U)
/*! REQ110_EN1 - This register is used to enable and disable GPIO1 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ110_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ110_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ110_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ111_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ111_EN1_SHIFT (15U)
/*! REQ111_EN1 - This register is used to enable and disable GPIO1 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ111_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ111_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ111_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ112_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ112_EN1_SHIFT (16U)
/*! REQ112_EN1 - This register is used to enable and disable GPIO2 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ112_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ112_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ112_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ113_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ113_EN1_SHIFT (17U)
/*! REQ113_EN1 - This register is used to enable and disable GPIO2 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ113_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ113_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ113_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ114_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ114_EN1_SHIFT (18U)
/*! REQ114_EN1 - This register is used to enable and disable GPIO3 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ114_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ114_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ114_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ115_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ115_EN1_SHIFT (19U)
/*! REQ115_EN1 - This register is used to enable and disable GPIO3 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ115_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ115_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ115_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ116_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ116_EN1_SHIFT (20U)
/*! REQ116_EN1 - This register is used to enable and disable GPIO4 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ116_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ116_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ116_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ117_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ117_EN1_SHIFT (21U)
/*! REQ117_EN1 - This register is used to enable and disable GPIO4 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ117_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ117_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ117_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ118_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ118_EN1_SHIFT (22U)
/*! REQ118_EN1 - This register is used to enable and disable GPIO5 pin event request 0.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ118_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ118_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ118_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ119_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ119_EN1_SHIFT (23U)
/*! REQ119_EN1 - This register is used to enable and disable GPIO5 pin event request 1.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ119_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ119_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ119_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ120_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ120_EN1_SHIFT (24U)
/*! REQ120_EN1 - This register is used to enable and disable TSI0 end of scan request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ120_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ120_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ120_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_REQ121_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ121_EN1_SHIFT (25U)
/*! REQ121_EN1 - This register is used to enable and disable TSI0 out of range request.
 *  0b0..Disable
 *  0b1..Enable
 */
#define INPUTMUX_DMA1_REQ_ENABLE3_REQ121_EN1(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_REQ121_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_REQ121_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE3_SET - DMA1 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ96_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ96_EN1_SHIFT (0U)
/*! REQ96_EN1 - Writing a 1 to REQ96_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ96_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ96_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ96_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ97_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ97_EN1_SHIFT (1U)
/*! REQ97_EN1 - Writing a 1 to REQ97_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ97_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ97_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ97_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ98_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ98_EN1_SHIFT (2U)
/*! REQ98_EN1 - Writing a 1 to REQ98_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ98_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ98_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ98_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ99_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ99_EN1_SHIFT (3U)
/*! REQ99_EN1 - Writing a 1 to REQ99_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ99_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ99_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ99_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ100_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ100_EN1_SHIFT (4U)
/*! REQ100_EN1 - Writing a 1 to REQ100_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ100_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ100_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ100_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ101_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ101_EN1_SHIFT (5U)
/*! REQ101_EN1 - Writing a 1 to REQ101_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ101_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ101_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ101_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ102_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ102_EN1_SHIFT (6U)
/*! REQ102_EN1 - Writing a 1 to REQ102_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ102_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ102_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ102_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ103_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ103_EN1_SHIFT (7U)
/*! REQ103_EN1 - Writing a 1 to REQ103_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ103_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ103_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ103_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ104_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ104_EN1_SHIFT (8U)
/*! REQ104_EN1 - Writing a 1 to REQ104_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ104_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ104_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ104_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ105_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ105_EN1_SHIFT (9U)
/*! REQ105_EN1 - Writing a 1 to REQ105_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ105_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ105_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ105_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ106_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ106_EN1_SHIFT (10U)
/*! REQ106_EN1 - Writing a 1 to REQ106_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ106_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ106_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ106_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ107_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ107_EN1_SHIFT (11U)
/*! REQ107_EN1 - Writing a 1 to REQ107_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ107_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ107_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ107_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ108_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ108_EN1_SHIFT (12U)
/*! REQ108_EN1 - Writing a 1 to REQ108_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ108_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ108_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ108_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ109_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ109_EN1_SHIFT (13U)
/*! REQ109_EN1 - Writing a 1 to REQ109_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ109_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ109_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ109_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ110_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ110_EN1_SHIFT (14U)
/*! REQ110_EN1 - Writing a 1 to REQ110_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ110_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ110_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ110_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ111_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ111_EN1_SHIFT (15U)
/*! REQ111_EN1 - Writing a 1 to REQ111_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ111_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ111_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ111_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ112_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ112_EN1_SHIFT (16U)
/*! REQ112_EN1 - Writing a 1 to REQ112_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ112_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ112_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ112_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ113_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ113_EN1_SHIFT (17U)
/*! REQ113_EN1 - Writing a 1 to REQ113_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ113_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ113_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ113_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ114_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ114_EN1_SHIFT (18U)
/*! REQ114_EN1 - Writing a 1 to REQ114_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ114_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ114_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ114_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ115_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ115_EN1_SHIFT (19U)
/*! REQ115_EN1 - Writing a 1 to REQ115_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ115_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ115_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ115_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ116_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ116_EN1_SHIFT (20U)
/*! REQ116_EN1 - Writing a 1 to REQ116_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ116_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ116_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ116_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ117_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ117_EN1_SHIFT (21U)
/*! REQ117_EN1 - Writing a 1 to REQ117_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ117_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ117_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ117_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ118_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ118_EN1_SHIFT (22U)
/*! REQ118_EN1 - Writing a 1 to REQ118_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ118_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ118_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ118_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ119_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ119_EN1_SHIFT (23U)
/*! REQ119_EN1 - Writing a 1 to REQ119_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ119_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ119_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ119_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ120_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ120_EN1_SHIFT (24U)
/*! REQ120_EN1 - Writing a 1 to REQ120_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ120_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ120_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ120_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ121_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ121_EN1_SHIFT (25U)
/*! REQ121_EN1 - Writing a 1 to REQ121_EN1 in this register sets the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ121_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ121_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_SET_REQ121_EN1_MASK)
/*! @} */

/*! @name DMA1_REQ_ENABLE3_CLR - DMA1 Request Enable3 */
/*! @{ */

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ96_EN1_MASK (0x1U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ96_EN1_SHIFT (0U)
/*! REQ96_EN1 - Writing a 1 to REQ96_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ96_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ96_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ96_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ97_EN1_MASK (0x2U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ97_EN1_SHIFT (1U)
/*! REQ97_EN1 - Writing a 1 to REQ97_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ97_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ97_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ97_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ98_EN1_MASK (0x4U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ98_EN1_SHIFT (2U)
/*! REQ98_EN1 - Writing a 1 to REQ98_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ98_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ98_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ98_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ99_EN1_MASK (0x8U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ99_EN1_SHIFT (3U)
/*! REQ99_EN1 - Writing a 1 to REQ99_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ99_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ99_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ99_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ100_EN1_MASK (0x10U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ100_EN1_SHIFT (4U)
/*! REQ100_EN1 - Writing a 1 to REQ100_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ100_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ100_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ100_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ101_EN1_MASK (0x20U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ101_EN1_SHIFT (5U)
/*! REQ101_EN1 - Writing a 1 to REQ101_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ101_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ101_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ101_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ102_EN1_MASK (0x40U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ102_EN1_SHIFT (6U)
/*! REQ102_EN1 - Writing a 1 to REQ102_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ102_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ102_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ102_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ103_EN1_MASK (0x80U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ103_EN1_SHIFT (7U)
/*! REQ103_EN1 - Writing a 1 to REQ103_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ103_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ103_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ103_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ104_EN1_MASK (0x100U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ104_EN1_SHIFT (8U)
/*! REQ104_EN1 - Writing a 1 to REQ104_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ104_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ104_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ104_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ105_EN1_MASK (0x200U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ105_EN1_SHIFT (9U)
/*! REQ105_EN1 - Writing a 1 to REQ105_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ105_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ105_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ105_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ106_EN1_MASK (0x400U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ106_EN1_SHIFT (10U)
/*! REQ106_EN1 - Writing a 1 to REQ106_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ106_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ106_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ106_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ107_EN1_MASK (0x800U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ107_EN1_SHIFT (11U)
/*! REQ107_EN1 - Writing a 1 to REQ107_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ107_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ107_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ107_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ108_EN1_MASK (0x1000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ108_EN1_SHIFT (12U)
/*! REQ108_EN1 - Writing a 1 to REQ108_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ108_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ108_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ108_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ109_EN1_MASK (0x2000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ109_EN1_SHIFT (13U)
/*! REQ109_EN1 - Writing a 1 to REQ109_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ109_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ109_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ109_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ110_EN1_MASK (0x4000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ110_EN1_SHIFT (14U)
/*! REQ110_EN1 - Writing a 1 to REQ110_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ110_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ110_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ110_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ111_EN1_MASK (0x8000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ111_EN1_SHIFT (15U)
/*! REQ111_EN1 - Writing a 1 to REQ111_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ111_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ111_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ111_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ112_EN1_MASK (0x10000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ112_EN1_SHIFT (16U)
/*! REQ112_EN1 - Writing a 1 to REQ112_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ112_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ112_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ112_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ113_EN1_MASK (0x20000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ113_EN1_SHIFT (17U)
/*! REQ113_EN1 - Writing a 1 to REQ113_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ113_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ113_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ113_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ114_EN1_MASK (0x40000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ114_EN1_SHIFT (18U)
/*! REQ114_EN1 - Writing a 1 to REQ114_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ114_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ114_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ114_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ115_EN1_MASK (0x80000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ115_EN1_SHIFT (19U)
/*! REQ115_EN1 - Writing a 1 to REQ115_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ115_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ115_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ115_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ116_EN1_MASK (0x100000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ116_EN1_SHIFT (20U)
/*! REQ116_EN1 - Writing a 1 to REQ116_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ116_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ116_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ116_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ117_EN1_MASK (0x200000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ117_EN1_SHIFT (21U)
/*! REQ117_EN1 - Writing a 1 to REQ117_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ117_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ117_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ117_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ118_EN1_MASK (0x400000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ118_EN1_SHIFT (22U)
/*! REQ118_EN1 - Writing a 1 to REQ118_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ118_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ118_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ118_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ119_EN1_MASK (0x800000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ119_EN1_SHIFT (23U)
/*! REQ119_EN1 - Writing a 1 to REQ119_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ119_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ119_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ119_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ120_EN1_MASK (0x1000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ120_EN1_SHIFT (24U)
/*! REQ120_EN1 - Writing a 1 to REQ120_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3 */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ120_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ120_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ120_EN1_MASK)

#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ121_EN1_MASK (0x2000000U)
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ121_EN1_SHIFT (25U)
/*! REQ121_EN1 - Writing a 1 to REQ121_EN1 in this register clears the corresponding bit in DMA0_REQ_ENABLE3. */
#define INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ121_EN1(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ121_EN1_SHIFT)) & INPUTMUX_DMA1_REQ_ENABLE3_CLR_REQ121_EN1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX_Register_Masks */

/* Backward compatibility for INPUTMUX */
#define INPUTMUX    INPUTMUX0


/*!
 * @}
 */ /* end of group INPUTMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_INPUTMUX_H_ */

