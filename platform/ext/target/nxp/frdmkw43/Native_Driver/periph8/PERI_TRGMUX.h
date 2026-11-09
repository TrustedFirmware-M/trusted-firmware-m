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
**         CMSIS Peripheral Access Layer for TRGMUX
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
 * @file PERI_TRGMUX.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

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
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(TRGMUX_SOURCE_T_)
#define TRGMUX_SOURCE_T_
/*!
 * @addtogroup trgmux_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the TRGMUX source
 *
 * Defines the enumeration for the TRGMUX source collections.
 */
typedef enum _trgmux_source
{
    kTRGMUX_SourceDisabled          = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourceAlwaysHigh        = 1U,          /**< Trigger function is always high */
    kTRGMUX_SourceTrgmux0Input0     = 2U,          /**< TRGMUX0 Input 0 is selected */
    kTRGMUX_SourceTrgmux0Input1     = 3U,          /**< TRGMUX0 Input 1 is selected */
    kTRGMUX_SourceTrgmux0Input2     = 4U,          /**< TRGMUX0 Input 2 is selected */
    kTRGMUX_SourceTrgmux0Input3     = 5U,          /**< TRGMUX0 Input 3 is selected */
    kTRGMUX_SourceWuu0Trigger       = 6U,          /**< WUU0 Trigger Event is selected */
    kTRGMUX_SourceRtcAlarm          = 7U,          /**< RTC Alarm Event is selected */
    kTRGMUX_SourceRtcSeconds        = 8U,          /**< RTC Seconds Match is selected */
    kTRGMUX_SourceLptmr0Trigger     = 9U,          /**< LPTMR0 Counter Match is selected */
    kTRGMUX_SourceLptmr1Trigger     = 10U,         /**< LPTMR1 Counter Match is selected */
    kTRGMUX_SourceLpit0Channel0     = 11U,         /**< LPIT0 Channel 0 is selected */
    kTRGMUX_SourceLpit0Channel1     = 12U,         /**< LPIT0 Channel 1 is selected */
    kTRGMUX_SourceLpit0Channel2     = 13U,         /**< LPIT0 Channel 2 is selected */
    kTRGMUX_SourceLpit0Channel3     = 14U,         /**< LPIT0 Channel 3 is selected */
    kTRGMUX_SourceTpm0Channel0      = 15U,         /**< TPM0 Channel 0 is selected */
    kTRGMUX_SourceTpm0Channel1      = 16U,         /**< TPM0 Channel 1 is selected */
    kTRGMUX_SourceTpm0Channel2      = 17U,         /**< TPM0 Channel 2 is selected */
    kTRGMUX_SourceTpm0Channel3      = 18U,         /**< TPM0 Channel 3 is selected */
    kTRGMUX_SourceTpm0Channel4      = 19U,         /**< TPM0 Channel 4 is selected */
    kTRGMUX_SourceTpm0Channel5      = 20U,         /**< TPM0 Channel 5 is selected */
    kTRGMUX_SourceTpm0Overflow      = 21U,         /**< TPM0 Overflow is selected */
    kTRGMUX_SourceTpm1Channel0      = 22U,         /**< TPM1 Channel 0 is selected */
    kTRGMUX_SourceTpm1Channel1      = 23U,         /**< TPM1 Channel 1 is selected */
    kTRGMUX_SourceTpm1Overflow      = 24U,         /**< TPM1 Overflow is selected */
    kTRGMUX_SourceTpm2Channel0      = 25U,         /**< TPM2 Channel 0 is selected */
    kTRGMUX_SourceTpm2Channel1      = 26U,         /**< TPM2 Channel 1 is selected */
    kTRGMUX_SourceTpm2Overflow      = 27U,         /**< TPM2 Overflow is selected */
    kTRGMUX_SourceTpm3Channel0      = 28U,         /**< TPM3 Channel 0 is selected */
    kTRGMUX_SourceTpm3Channel1      = 29U,         /**< TPM3 Channel 1 is selected */
    kTRGMUX_SourceTpm3Overflow      = 30U,         /**< TPM3 Overflow is selected */
    kTRGMUX_SourceTpm4Channel0      = 31U,         /**< TPM4 Channel 0 is selected */
    kTRGMUX_SourceTpm4Channel1      = 32U,         /**< TPM4 Channel 1 is selected */
    kTRGMUX_SourceTpm4Overflow      = 33U,         /**< TPM4 Overflow is selected */
    kTRGMUX_SourceLpi2c0MasterStop  = 34U,         /**< LPI2C0 Master End of Packet is selected */
    kTRGMUX_SourceLpi2c0SlaveStop   = 35U,         /**< LPI2C0 Slave End of Packet is selected */
    kTRGMUX_SourceLpi2c1MasterStop  = 36U,         /**< LPI2C1 Master End of Packet is selected */
    kTRGMUX_SourceLpi2c1SlaveStop   = 37U,         /**< LPI2C1 Slave End of Packet is selected */
    kTRGMUX_SourceLpspi0Frame       = 38U,         /**< LPSPI0 End of Frame is selected */
    kTRGMUX_SourceLpspi0Rx          = 39U,         /**< LPSPI0 Received Data Word is selected */
    kTRGMUX_SourceLpspi1Frame       = 40U,         /**< LPSPI1 End of Frame is selected */
    kTRGMUX_SourceLpspi1Rx          = 41U,         /**< LPSPI1 Received Data Word is selected */
    kTRGMUX_SourceLpspi2Frame       = 42U,         /**< LPSPI2 End of Frame is selected */
    kTRGMUX_SourceLpspi2Rx          = 43U,         /**< LPSPI2 Received Data Word is selected */
    kTRGMUX_SourceLpuart0RxData     = 44U,         /**< LPUART0 Received Data Word is selected */
    kTRGMUX_SourceLpuart0TxData     = 45U,         /**< LPUART0 Transmitted Data Word is selected */
    kTRGMUX_SourceLpuart0RxIdle     = 46U,         /**< LPUART0 Receive Line Idle is selected */
    kTRGMUX_SourceLpuart1RxData     = 47U,         /**< LPUART1 Received Data Word is selected */
    kTRGMUX_SourceLpuart1TxData     = 48U,         /**< LPUART1 Transmitted Data Word is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 49U,         /**< LPUART1 Receive Line Idle is selected */
    kTRGMUX_SourceGpioAPinTrigger0  = 50U,         /**< GPIOA Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioAPinTrigger1  = 51U,         /**< GPIOA Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioBPinTrigger0  = 52U,         /**< GPIOB Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioBPinTrigger1  = 53U,         /**< GPIOB Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioCPinTrigger0  = 54U,         /**< GPIOC Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioCPinTrigger1  = 55U,         /**< GPIOC Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioDPinTrigger0  = 56U,         /**< GPIOD Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioDPinTrigger1  = 57U,         /**< GPIOD Pin event Trigger 1 is selected */
    kTRGMUX_SourceAdcGp0Output0     = 58U,         /**< ADC-GP0 Trigger Output 0 is selected */
    kTRGMUX_SourceAdcGp0Output1     = 59U,         /**< ADC-GP0 Trigger Output 1 is selected */
    kTRGMUX_SourceAdcGp0Output2     = 60U,         /**< ADC-GP0 Trigger Output 2 is selected */
    kTRGMUX_SourceAdcGp0Output3     = 61U,         /**< ADC-GP0 Trigger Output 3 is selected */
    kTRGMUX_SourceCmpGp0Output      = 62U,         /**< CMP-GP0 Comparator Output is selected */
    kTRGMUX_SourceSpc0DcdcBurst     = 63U,         /**< SPC0 DCDC Burst Trig is selected */
    kTRGMUX_SourceRf2p4gTofTimestamp = 64U,        /**< RF-2.4G TOF TIMESTAMP TRIG is selected */
    kTRGMUX_SourceRf2p4gLantSw      = 65U,         /**< RF-2.4G LANT_SW is selected */
    kTRGMUX_SourceCpu0TxEv          = 66U,         /**< CM33 (Main) */
    kTRGMUX_SourceCpu1TxEv          = 67U,         /**< CM33 (Radio) */
    kTRGMUX_SourcAoiOut0            = 68U,         /**< AOI_OUT0 input is selected */
    kTRGMUX_SourcAoiOut1            = 69U,         /**< AOI_OUT1 input is selected */
    kTRGMUX_SourcAoiOut2            = 70U,         /**< AOI_OUT2 input is selected */
    kTRGMUX_SourcAoiOut3            = 71U,         /**< AOI_OUT3 input is selected */
    kTRGMUX_SourcFlexPwmMux0Trigger0 = 72U,        /**< FLEXPWM MUX0 trigger 0 input is selected */
    kTRGMUX_SourcFlexPwmMux0Trigger1 = 73U,        /**< FLEXPWM MUX0 trigger 1 input is selected */
    kTRGMUX_SourcFlexPwmMux0Trigger2 = 74U,        /**< FLEXPWM MUX0 trigger 2 input is selected */
    kTRGMUX_SourcFlexPwmMux1Trigger0 = 75U,        /**< FLEXPWM MUX1 trigger 0 input is selected */
    kTRGMUX_SourcFlexPwmMux1Trigger1 = 76U,        /**< FLEXPWM MUX1 trigger 1 input is selected */
    kTRGMUX_SourcFlexPwmMux1Trigger2 = 77U,        /**< FLEXPWM MUX1 trigger 2 input is selected */
} trgmux_source_t;

/* @} */
#endif /* TRGMUX_SOURCE_T_ */

#if !defined(TRGMUX_DEVICE_T_)
#define TRGMUX_DEVICE_T_
/*!
 * @brief Enumeration for the TRGMUX device
 *
 * Defines the enumeration for the TRGMUX device collections.
 */
typedef enum _trgmux_device
{
    kTRGMUX_Trgmux0Output0          = 0U,          /**< TRGMUX_OUT0 device trigger input */
    kTRGMUX_Trgmux0Lpit0            = 1U,          /**< LPIT0 device trigger input */
    kTRGMUX_Trgmux0Tpm0             = 2U,          /**< TPM0 device trigger input */
    kTRGMUX_Trgmux0Tpm3             = 3U,          /**< TPM3 device trigger input */
    kTRGMUX_Trgmux0Tpm4             = 4U,          /**< TPM4 device trigger input */
    kTRGMUX_Trgmux0Lpi2c0           = 5U,          /**< LPI2C0 device trigger input */
    kTRGMUX_Trgmux0Lpi2c1           = 6U,          /**< LPI2C1 device trigger input */
    kTRGMUX_Trgmux0Lpspi0           = 7U,          /**< LPSPI0 device trigger input */
    kTRGMUX_Trgmux0Lpspi1           = 8U,          /**< LPSPI1 device trigger input */
    kTRGMUX_Trgmux0Lpspi2           = 9U,          /**< LPSPI2 device trigger input */
    kTRGMUX_Trgmux0Lpuart0          = 10U,         /**< LPUART0 device trigger input */
    kTRGMUX_Trgmux0Lpuart1          = 11U,         /**< LPUART1 device trigger input */
    kTRGMUX_Trgmux0AdcGp0           = 12U,         /**< ADC_GP0 device trigger input */
    kTRGMUX_Trgmux0CmpGp0           = 13U,         /**< CMP_GP0 device trigger input */
    kTRGMUX_Trgmux0Can0             = 14U,         /**< CAN0 device trigger input */
    kTRGMUX_Trgmux0Aoi3             = 15U,         /**< AOI3 device trigger input */
    kTRGMUX_Trgmux0Aoi0             = 16U,         /**< AOI0 device trigger input */
    kTRGMUX_Trgmux0Aoi1             = 17U,         /**< AOI1 device trigger input */
    kTRGMUX_Trgmux0Aoi2             = 18U,         /**< AOI2 device trigger input */
    kTRGMUX_Trgmux0FlexPwm2         = 19U,         /**< FLEXPWM2 device trigger input */
    kTRGMUX_Trgmux0FlexPwm1         = 20U,         /**< FLEXPWM1 device trigger input */
    kTRGMUX_Trgmux0FlexPwm0         = 21U,         /**< FLEXPWM0 device trigger input */
} trgmux_device_t;

/* @} */
#endif /* TRGMUX_DEVICE_T_ */


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
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGCFG_COUNT                       22u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX TRGMUX_OUT0..TRGMUX FLEXPWM0, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX TRGMUX_OUT0..TRGMUX FLEXPWM0 */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - TRGMUX Source Select 0 */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x7F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - TRGMUX Source Select 1 */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x7F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - TRGMUX Source Select 2 */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x7F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - TRGMUX Source Select 3 */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - TRGMUX Register Lock
 *  0b0..Register is writable
 *  0b1..Register is not writable until the next system reset
 */
#define TRGMUX_TRGCFG_LK(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_LK_SHIFT)) & TRGMUX_TRGCFG_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_TRGMUX_H_ */

