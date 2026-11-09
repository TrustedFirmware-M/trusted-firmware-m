/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.0.1. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0U
#endif

/* Definition for delay API in clock driver, users can redefine it to the real
 * application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (240000000U)
#endif

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/
#define CLK_GATE_REG_OFFSET(value) (((uint32_t)(value)) >> 16U)
#define CLK_GATE_BIT_SHIFT(value)  (((uint32_t)(value)) & 0x0000FFFFU)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_GateINPUTMUX0     = ((0x0U << 16U) | (0U)),   /*!< Clock gate name: INPUTMUX0     */
    kCLOCK_GateFREQME        = ((0x0U << 16U) | (1U)),   /*!< Clock gate name: FREQME        */
    kCLOCK_GateCTIMER0       = ((0x0U << 16U) | (2U)),   /*!< Clock gate name: CTIMER0       */
    kCLOCK_GateCTIMER1       = ((0x0U << 16U) | (3U)),   /*!< Clock gate name: CTIMER1       */
    kCLOCK_GateCTIMER2       = ((0x0U << 16U) | (4U)),   /*!< Clock gate name: CTIMER2       */
    kCLOCK_GateCTIMER3       = ((0x0U << 16U) | (5U)),   /*!< Clock gate name: CTIMER3       */
    kCLOCK_GateCTIMER4       = ((0x0U << 16U) | (6U)),   /*!< Clock gate name: CTIMER4       */
    kCLOCK_GateUTICK0        = ((0x0U << 16U) | (7U)),   /*!< Clock gate name: UTICK0        */
    kCLOCK_GateWWDT0         = ((0x0U << 16U) | (8U)),   /*!< Clock gate name: WWDT0         */
    kCLOCK_GateWWDT1         = ((0x0U << 16U) | (9U)),   /*!< Clock gate name: WWDT1         */
    kCLOCK_GateDMA0          = ((0x0U << 16U) | (10U)),  /*!< Clock gate name: DMA0          */
    kCLOCK_GateDMA1          = ((0x0U << 16U) | (11U)),  /*!< Clock gate name: DMA1          */
    kCLOCK_GateAOI0          = ((0x0U << 16U) | (12U)),  /*!< Clock gate name: AOI0          */
    kCLOCK_GateCRC0          = ((0x0U << 16U) | (14U)),  /*!< Clock gate name: CRC0          */
    kCLOCK_GateEIM0          = ((0x0U << 16U) | (15U)),  /*!< Clock gate name: EIM0          */
    kCLOCK_GateERM0          = ((0x0U << 16U) | (16U)),  /*!< Clock gate name: ERM0          */
    kCLOCK_GateFLEXIO0       = ((0x0U << 16U) | (17U)),  /*!< Clock gate name: FLEXIO0       */
    kCLOCK_GateLPI2C0        = ((0x0U << 16U) | (19U)),  /*!< Clock gate name: LPI2C0        */
    kCLOCK_GateLPI2C1        = ((0x0U << 16U) | (20U)),  /*!< Clock gate name: LPI2C1        */
    kCLOCK_GateLPI2C2        = ((0x0U << 16U) | (21U)),  /*!< Clock gate name: LPI2C2        */
    kCLOCK_GateLPI2C3        = ((0x0U << 16U) | (22U)),  /*!< Clock gate name: LPI2C3        */
    kCLOCK_GateLPI2C4        = ((0x0U << 16U) | (23U)),  /*!< Clock gate name: LPI2C4        */
    kCLOCK_GateLPUART0       = ((0x0U << 16U) | (25U)),  /*!< Clock gate name: LPUART0       */
    kCLOCK_GateLPUART1       = ((0x0U << 16U) | (26U)),  /*!< Clock gate name: LPUART1       */
    kCLOCK_GateLPUART2       = ((0x0U << 16U) | (27U)),  /*!< Clock gate name: LPUART2       */
    kCLOCK_GateLPUART3       = ((0x0U << 16U) | (28U)),  /*!< Clock gate name: LPUART3       */
    kCLOCK_GateLPUART4       = ((0x0U << 16U) | (29U)),  /*!< Clock gate name: LPUART4       */
    kCLOCK_GateLPUART5       = ((0x0U << 16U) | (30U)),  /*!< Clock gate name: LPUART5       */
    kCLOCK_GateOSTIMER0      = ((0x0U << 16U) | (31U)),  /*!< Clock gate name: OSTIMER0      */
    kCLOCK_GateLPSPI0        = ((0x10U << 16U) | (4U)),  /*!< Clock gate name: LPSPI0        */
    kCLOCK_GateLPSPI1        = ((0x10U << 16U) | (5U)),  /*!< Clock gate name: LPSPI1        */
    kCLOCK_GateLPSPI2        = ((0x10U << 16U) | (6U)),  /*!< Clock gate name: LPSPI2        */
    kCLOCK_GateLPSPI3        = ((0x10U << 16U) | (7U)),  /*!< Clock gate name: LPSPI3        */
    kCLOCK_GateLPSPI4        = ((0x10U << 16U) | (8U)),  /*!< Clock gate name: LPSPI4        */
    kCLOCK_GateLPSPI5        = ((0x10U << 16U) | (9U)),  /*!< Clock gate name: LPSPI5        */
    kCLOCK_GatePORT0         = ((0x10U << 16U) | (10U)), /*!< Clock gate name: PORT0         */
    kCLOCK_GatePORT1         = ((0x10U << 16U) | (11U)), /*!< Clock gate name: PORT1         */
    kCLOCK_GatePORT2         = ((0x10U << 16U) | (12U)), /*!< Clock gate name: PORT2         */
    kCLOCK_GatePORT3         = ((0x10U << 16U) | (13U)), /*!< Clock gate name: PORT3         */
    kCLOCK_GatePORT4         = ((0x10U << 16U) | (14U)), /*!< Clock gate name: PORT4         */
    kCLOCK_GatePORT5         = ((0x10U << 16U) | (15U)), /*!< Clock gate name: PORT5         */
    kCLOCK_GateADC0          = ((0x10U << 16U) | (16U)), /*!< Clock gate name: ADC0          */
    kCLOCK_GateADC1          = ((0x10U << 16U) | (17U)), /*!< Clock gate name: ADC1          */
    kCLOCK_GateCMP0          = ((0x10U << 16U) | (20U)), /*!< Clock gate name: CMP0          */
    kCLOCK_GateDAC0          = ((0x10U << 16U) | (23U)), /*!< Clock gate name: DAC0          */
    kCLOCK_GateDAC1          = ((0x10U << 16U) | (24U)), /*!< Clock gate name: DAC1          */
    kCLOCK_GateVREF0         = ((0x10U << 16U) | (29U)), /*!< Clock gate name: VREF0         */
    kCLOCK_GateTSI0          = ((0x10U << 16U) | (31U)), /*!< Clock gate name: TSI0          */
    kCLOCK_GateI3C0          = ((0x20U << 16U) | (0U)),  /*!< Clock gate name: I3C0          */
    kCLOCK_GateI3C1          = ((0x20U << 16U) | (1U)),  /*!< Clock gate name: I3C1          */
    kCLOCK_GateI3C2          = ((0x20U << 16U) | (2U)),  /*!< Clock gate name: I3C2          */
    kCLOCK_GateI3C3          = ((0x20U << 16U) | (3U)),  /*!< Clock gate name: I3C3          */
    kCLOCK_GateFLEXCAN0      = ((0x20U << 16U) | (4U)),  /*!< Clock gate name: FLEXCAN0      */
    kCLOCK_GateFLEXCAN1      = ((0x20U << 16U) | (5U)),  /*!< Clock gate name: FLEXCAN1      */
    kCLOCK_GateE1588         = ((0x20U << 16U) | (8U)),  /*!< Clock gate name: E1588         */
    kCLOCK_GateRMII          = ((0x20U << 16U) | (9U)),  /*!< Clock gate name: RMII          */
    kCLOCK_GateENET0         = ((0x20U << 16U) | (10U)), /*!< Clock gate name: ENET0         */
    kCLOCK_GateTENBASET_PHY0 = ((0x20U << 16U) | (11U)), /*!< Clock gate name: TENBASET_PHY0 */
    kCLOCK_GateFLEXSPI0      = ((0x20U << 16U) | (12U)), /*!< Clock gate name: FLEXSPI0      */
    kCLOCK_GateSPIFILTER0    = ((0x20U << 16U) | (13U)), /*!< Clock gate name: SPIFILTER0    */
    kCLOCK_GateESPI0         = ((0x20U << 16U) | (14U)), /*!< Clock gate name: ESPI0         */
    kCLOCK_GateUSBHS         = ((0x20U << 16U) | (18U)), /*!< Clock gate name: USBHS          */
    kCLOCK_GateUSBHS_PHY     = ((0x20U << 16U) | (19U)), /*!< Clock gate name: USBHS_PHY      */
    kCLOCK_GateEWM0          = ((0x20U << 16U) | (20U)), /*!< Clock gate name: EWM0          */
    kCLOCK_GateRAMA          = ((0x30U << 16U) | (16U)), /*!< Clock gate name: RAMA          */
    kCLOCK_GateRAMB          = ((0x30U << 16U) | (17U)), /*!< Clock gate name: RAMB          */
    kCLOCK_GateGPIO0         = ((0x30U << 16U) | (20U)), /*!< Clock gate name: GPIO0         */
    kCLOCK_GateGPIO1         = ((0x30U << 16U) | (21U)), /*!< Clock gate name: GPIO1         */
    kCLOCK_GateGPIO2         = ((0x30U << 16U) | (22U)), /*!< Clock gate name: GPIO2         */
    kCLOCK_GateGPIO3         = ((0x30U << 16U) | (23U)), /*!< Clock gate name: GPIO3         */
    kCLOCK_GateGPIO4         = ((0x30U << 16U) | (24U)), /*!< Clock gate name: GPIO4         */
    kCLOCK_GateGPIO5         = ((0x30U << 16U) | (25U)), /*!< Clock gate name: GPIO5         */
    kCLOCK_GateROMC          = ((0x30U << 16U) | (28U)), /*!< Clock gate name: ROMC          */
    kCLOCK_GateSMARTDMA0     = ((0x30U << 16U) | (29U)), /*!< Clock gate name: SMARTDMA0     */
    kCLOCK_GateSECCON        = ((0x40U << 16U) | (16U)), /*!< Clock gate name: SECCON        */
    kCLOCK_GateGLIKEY0       = ((0x40U << 16U) | (17U)), /*!< Clock gate name: GLIKEY0       */
    kCLOCK_GateTDET0         = ((0x40U << 16U) | (18U)), /*!< Clock gate name: TDET0         */
    kCLOCK_GatePKC0          = ((0x40U << 16U) | (19U)), /*!< Clock gate name: PKC0          */
    kCLOCK_GateSGI0          = ((0x40U << 16U) | (20U)), /*!< Clock gate name: SGI0          */
    kCLOCK_GateTRNG0         = ((0x40U << 16U) | (21U)), /*!< Clock gate name: TRNG0         */
    kCLOCK_GateUDF0          = ((0x40U << 16U) | (22U)), /*!< Clock gate name: UDF0          */
    kCLOCK_GateDGDET0        = ((0x40U << 16U) | (23U)), /*!< Clock gate name: DGDET0        */
    kCLOCK_GateITRC0         = ((0x40U << 16U) | (24U)), /*!< Clock gate name: ITRC0         */
    kCLOCK_GateATX0          = ((0x40U << 16U) | (29U)), /*!< Clock gate name: ATX0          */
    kCLOCK_GateMTR           = ((0x40U << 16U) | (30U)), /*!< Clock gate name: MTR           */
    kCLOCK_GateTCU           = ((0x40U << 16U) | (31U)), /*!< Clock gate name: TCU           */
    kCLOCK_GateNotAvail      = (0xFFFFFFFFU),            /*!< Clock gate name: None          */
} clock_ip_name_t;

#define kCLOCK_Crc0     kCLOCK_GateCRC0
#define kCLOCK_Ewm0     kCLOCK_GateEWM0
#define kCLOCK_InputMux kCLOCK_GateINPUTMUX0
#define kCLOCK_Smartdma kCLOCK_GateSMARTDMA0

/*! @brief Clock ip name array for AOI. */
#define AOI_CLOCKS {kCLOCK_GateAOI0}
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS {kCLOCK_GateCRC0}
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS \
    {kCLOCK_GateCTIMER0, kCLOCK_GateCTIMER1, kCLOCK_GateCTIMER2, kCLOCK_GateCTIMER3, kCLOCK_GateCTIMER4}
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS {kCLOCK_GateDMA0, kCLOCK_GateDMA1}
/*! @brief Clock gate name array for EDMA. */
#define EDMA_CLOCKS {kCLOCK_GateDMA0}
/*! @brief Clock ip name array for ERM. */
#define ERM_CLOCKS {kCLOCK_GateERM0}
/*! @brief Clock ip name array for EIM. */
#define EIM_CLOCKS {kCLOCK_GateEIM0}
/*! @brief Clock gate name array for ESPI. */
#define ESPI_CLOCKS {kCLOCK_GateESPI0}
/*! @brief Clock gate name array for ENET. */
#define ETH_CLOCKS {kCLOCK_GateENET0}
/*! @brief Clock gate name array for E1588. */
#define E1588_CLOCKS {kCLOCK_GateE1588}
/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS {kCLOCK_GateFLEXCAN0, kCLOCK_GateFLEXCAN1}
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS {kCLOCK_GateFREQME}
/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS {kCLOCK_GateFLEXIO0}
/*! @brief Clock ip name array for FLEXSPI. */
#define FLEXSPI_CLOCKS {kCLOCK_GateFLEXSPI0}
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS \
    {kCLOCK_GateGPIO0, kCLOCK_GateGPIO1, kCLOCK_GateGPIO2, kCLOCK_GateGPIO3, kCLOCK_GateGPIO4, kCLOCK_GateGPIO5}
/*! @brief Clock ip name array for GDET. */
#define GDET_CLOCKS {kCLOCK_GateDGDET0}
/*! @brief Clock ip name array for INPUTMUX. */
#define INPUTMUX_CLOCKS {kCLOCK_GateINPUTMUX0}
/*! @brief Clock ip name array for GPIO. */
#define LPCMP_CLOCKS {kCLOCK_GateCMP0}
/*! @brief Clock ip name array for LPADC. */
#define LPADC_CLOCKS {kCLOCK_GateADC0, kCLOCK_GateADC1}
/*! @brief Clock ip name array for LPDAC. */
#define LPDAC_CLOCKS {kCLOCK_GateDAC0, kCLOCK_GateDAC1}
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                            \
    {kCLOCK_GateLPUART0, kCLOCK_GateLPUART1, kCLOCK_GateLPUART2, \
     kCLOCK_GateLPUART3, kCLOCK_GateLPUART4, kCLOCK_GateLPUART5}
/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS {kCLOCK_GateLPI2C0, kCLOCK_GateLPI2C1, kCLOCK_GateLPI2C2, kCLOCK_GateLPI2C3, kCLOCK_GateLPI2C4}
/*! @brief Clock ip name array for LSPI. */
#define LPSPI_CLOCKS \
    {kCLOCK_GateLPSPI0, kCLOCK_GateLPSPI1, kCLOCK_GateLPSPI2, kCLOCK_GateLPSPI3, kCLOCK_GateLPSPI4, kCLOCK_GateLPSPI5}
/*! @brief Clock ip name array for I3C. */
#define I3C_CLOCKS {kCLOCK_GateI3C0, kCLOCK_GateI3C1, kCLOCK_GateI3C2, kCLOCK_GateI3C3}
/*! @brief Clock ip name array for OSTIMER. */
#define OSTIMER_CLOCKS {kCLOCK_GateOSTIMER0}
/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS \
    {kCLOCK_GatePORT0, kCLOCK_GatePORT1, kCLOCK_GatePORT2, kCLOCK_GatePORT3, kCLOCK_GatePORT4, kCLOCK_GatePORT5}
/*! @brief Clock gate name array for RMII. */
#define RMII_CLOCKS {kCLOCK_GateRMII}
/*! @brief Clock ip name array for SPIFILTER. */
#define SPIFILTER_CLOCKS {kCLOCK_GateSPIFILTER0}
/*! @brief Clock ip name array for SMARTDMA. */
#define SMARTDMA_CLOCKS {kCLOCK_GateSMARTDMA0}
/*! @brief Clock ip name array for TRNG. */
#define TRNG_CLOCKS {kCLOCK_GateTRNG0}
/*! @brief Clock ip name array for UTICK. */
#define UTICK_CLOCKS {kCLOCK_GateUTICK0}
/*! @brief Clock ip name array for USBHS. */
#define USB_CLOCKS {kCLOCK_GateUSBHS}
/*! @brief Clock ip name array for USBHSPHY. */
#define USBPHY_CLOCKS {kCLOCK_GateUSBHSPHY}
/*! @brief Clock ip name array for VREF. */
#define VREF_CLOCKS {kCLOCK_GateVREF0}
/*! @brief Clock gate name array for RTC. */
#define RTC_CLOCKS {kCLOCK_GateNotAvail}
/*! @brief Clock gate name array for TSI. */
#define TSI_CLOCKS {kCLOCK_GateTSI0}
/*! @brief Clock gate name array for TENBASET_PHY. */
#define TENBASET_PHY_CLOCKS {kCLOCK_GateTENBASET_PHY0}
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS {kCLOCK_GateWWDT0, kCLOCK_GateWWDT1}
/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_MainClk,    /*!< MAIN_CLK                   */
    kCLOCK_CoreSysClk, /*!< Core/system clock(CPU_CLK) */
    kCLOCK_SYSTEM_CLK, /*!< SYSTEM clock/AHB_BUS       */
    kCLOCK_BusClk,     /*!< SYSTEM clock divided by 2  */
    kCLOCK_SLOW_CLK,   /*!< SYSTEM clock divided by 6  */
    kCLOCK_ExtClk,     /*!< External Clock             */
    kCLOCK_Fro16K,     /*!< FRO16K                     */
    kCLOCK_Fro12M,     /*!< FRO12M                     */
    kCLOCK_Fro12MDiv,  /*!< FRO12MDiv                  */
    kCLOCK_FroHf,      /*!< FROHF                      */
    kCLOCK_FroHfDiv,   /*!< Divided by FROHF           */
    kCLOCK_Clk48M,     /*!< CLK48M                     */
    kCLOCK_Pll1Clk,    /*!< Pll1Clk                    */
    kCLOCK_Pll1ClkDiv, /*!< Pll1CkDiv                  */
    kCLOCK_Clk1M,      /*!< CLK1M                      */
    kCLOCK_UsbPll,     /*!< UsbPll                     */
    kCLOCK_UsbPfdClk,  /*!< UsbPfdClk                  */
    kCLOCK_Clk16K0,    /*!< CLK16K[0]                  */
    kCLOCK_Clk16K1,    /*!< CLK16K[1]                  */
    kCLOCK_Clk16K2,    /*!< CLK16K[2]                  */
    kCLOCK_Osc32K0,    /*!< OSC32K[0]                  */
    kCLOCK_Osc32K1,    /*!< OSC32K[1]                  */
    kCLOCK_Osc32K2,    /*!< OSC32K[2]                  */
    kCLOCK_LpOsc,      /*!< Low Power Oscillator        */
} clock_name_t;

/*! @brief Peripherals clock source definition. */
#define BUS_CLK kCLOCK_BusClk

/*! @brief Clock Mux Switches
 *  The encoding is as follows each connection identified is 32bits wide while
 * 24bits are valuable starting from LSB upwards
 *
 *  [4 bits for choice, 0 means invalid choice] [8 bits mux ID]*
 *
 */
#define CLK_ATTACH_REG_OFFSET(value) (((uint32_t)(value)) >> 16U)
#define CLK_ATTACH_CLK_SEL(value)    (((uint32_t)(value)) & 0x0000FFFFU)
#define CLK_ATTACH_MUX(reg, sel)     ((((uint32_t)(reg)) << 16U) | (sel))

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_select_name
{
    kCLOCK_SelI3C0_FCLK     = (0x100U), /*!< I3C0_FCLK     clock selection */
    kCLOCK_SelI3C1_FCLK     = (0x108U), /*!< I3C1_FCLK     clock selection */
    kCLOCK_SelCTIMER0       = (0x110U), /*!< CTIMER0       clock selection */
    kCLOCK_SelCTIMER1       = (0x118U), /*!< CTIMER1       clock selection */
    kCLOCK_SelCTIMER2       = (0x120U), /*!< CTIMER2       clock selection */
    kCLOCK_SelCTIMER3       = (0x128U), /*!< CTIMER3       clock selection */
    kCLOCK_SelCTIMER4       = (0x130U), /*!< CTIMER4       clock selection */
    kCLOCK_SelWWDT1         = (0x140U), /*!< WWDT1         clock selection */
    kCLOCK_SelE1588         = (0x148U), /*!< E1588         clock selection */
    kCLOCK_SelRMII          = (0x150U), /*!< RMII          clock selection */
    kCLOCK_SelESPI0         = (0x158U), /*!< ESPI0         clock selection */
    kCLOCK_SelFLEXSPI0      = (0x160U), /*!< FLEXSPI0      clock selection */
    kCLOCK_SelLPSPI2        = (0x168U), /*!< LPSPI2        clock selection */
    kCLOCK_SelLPSPI3        = (0x170U), /*!< LPSPI3        clock selection */
    kCLOCK_SelLPSPI4        = (0x178U), /*!< LPSPI4        clock selection */
    kCLOCK_SelLPSPI5        = (0x180U), /*!< LPSPI5        clock selection */
    kCLOCK_SelTENBASET_PHY0 = (0x188U), /*!< TENBASET_PHY0 clock selection */
    kCLOCK_SelUSBHS         = (0x190U), /*!< USBHS          clock selection */
    kCLOCK_SelUSBHS_PHY     = (0x198U), /*!< USBHS_PHY      clock selection */
    kCLOCK_SelFLEXIO0       = (0x1A0U), /*!< FLEXIO0       clock selection */
    kCLOCK_SelLPI2C0        = (0x1A8U), /*!< LPI2C0        clock selection */
    kCLOCK_SelLPI2C1        = (0x1B0U), /*!< LPI2C1        clock selection */
    kCLOCK_SelLPSPI0        = (0x1B8U), /*!< LPSPI0        clock selection */
    kCLOCK_SelLPSPI1        = (0x1C0U), /*!< LPSPI1        clock selection */
    kCLOCK_SelI3C2_FCLK     = (0x1C8U), /*!< I3C2_FCLK     clock selection */
    kCLOCK_SelLPUART0       = (0x1D0U), /*!< LPUART0       clock selection */
    kCLOCK_SelLPUART1       = (0x1D8U), /*!< LPUART1       clock selection */
    kCLOCK_SelLPUART2       = (0x1E0U), /*!< LPUART2       clock selection */
    kCLOCK_SelLPUART3       = (0x1E8U), /*!< LPUART3       clock selection */
    kCLOCK_SelLPUART4       = (0x1F0U), /*!< LPUART4       clock selection */
    kCLOCK_SelLPTMR0        = (0x1F8U), /*!< LPTMR0        clock selection */
    kCLOCK_SelOSTIMER0      = (0x200U), /*!< OSTIMER0      clock selection */
    kCLOCK_SelADC           = (0x208U), /*!< ADCx          clock selection */
    kCLOCK_SelCMP0_RR       = (0x218U), /*!< CMP0_RR       clock selection */
    kCLOCK_SelDAC0          = (0x220U), /*!< DAC0          clock selection */
    kCLOCK_SelDAC1          = (0x228U), /*!< DAC1          clock selection */
    kCLOCK_SelTSI0          = (0x230U), /*!< TSI0          clock selection */
    kCLOCK_SelFLEXCAN0      = (0x238U), /*!< FLEXCAN0      clock selection */
    kCLOCK_SelFLEXCAN1      = (0x240U), /*!< FLEXCAN1      clock selection */
    kCLOCK_SelLPI2C2        = (0x248U), /*!< LPI2C2        clock selection */
    kCLOCK_SelLPI2C3        = (0x250U), /*!< LPI2C3        clock selection */
    kCLOCK_SelLPI2C4        = (0x258U), /*!< LPI2C4        clock selection */
    kCLOCK_SelLPUART5       = (0x260U), /*!< LPUART5       clock selection */
    kCLOCK_SelI3C3_FCLK     = (0x268U), /*!< I3C3_FCLK     clock selection */
    kCLOCK_SelTRACE         = (0x270U), /*!< TRACE         clock selection */
    kCLOCK_SelCLKOUT        = (0x278U), /*!< CLKOUT        clock selection */
    kCLOCK_SelSYSTICK       = (0x280U), /*!< SYSTICK       clock selection */
    kCLOCK_SelSCGSCS        = (0x300U), /*!< SCG SCS       clock selection */
    kCLOCK_SelMax           = (0x300U), /*!< MAX           clock selection */
} clock_select_name_t;

/*!
 * @brief The enumerator of clock attach Id.
 */
typedef enum _clock_attach_id
{
    kCLK_IN_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 1U),            /*!< Attach clk_in to MAIN_CLK.     */
    kFRO12M_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 2U),            /*!< Attach FRO_12M to MAIN_CLK.    */
    kFRO_HF_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 3U),            /*!< Attach FRO_HF to MAIN_CLK.     */
    kOSC_32K_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 4U),            /*!< Attach OSC_32K[1] to MAIN_CLK. */
    kPll1Clk_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 6U),            /*!< Attach Pll1Clk to MAIN_CLK.    */
    kUSB_PFD_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 7U),            /*!< Attach Pll1Clk to MAIN_CLK.    */
    kNONE_to_MAIN_CLK    = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 0U),            /*!< Attach NONE to MAIN_CLK.       */

    kFRO_LF_DIV_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 0U),      /*!< Attach FRO_LF_DIV to I3C0FCLK. */
    kFRO_HF_DIV_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 2U),      /*!< Attach FRO_HF_DIV to I3C0FCLK. */
    kCLK_IN_to_I3C0FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 3U),      /*!< Attach CLK_IN to I3C0FCLK.     */
    kCLK_1M_to_I3C0FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 5U),      /*!< Attach CLK_1M to I3C0FCLK.     */
    kPll1ClkDiv_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 6U),      /*!< Attach Pll1ClkDiv to I3C0FCLK. */
    kNONE_to_I3C0FCLK       = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 7U),      /*!< Attach NONE to I3C0FCLK.       */

    kFRO_LF_DIV_to_I3C1FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 0U),      /*!< Attach FRO_LF_DIV to I3C1FCLK. */
    kFRO_HF_DIV_to_I3C1FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 2U),      /*!< Attach FRO_HF_DIV to I3C1FCLK. */
    kCLK_IN_to_I3C1FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 3U),      /*!< Attach CLK_IN to I3C1FCLK.     */
    kCLK_1M_to_I3C1FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 5U),      /*!< Attach CLK_1M to I3C1FCLK.     */
    kPll1ClkDiv_to_I3C1FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 6U),      /*!< Attach Pll1ClkDiv to I3C1FCLK. */
    kNONE_to_I3C1FCLK       = CLK_ATTACH_MUX(kCLOCK_SelI3C1_FCLK, 7U),      /*!< Attach NONE to I3C1FCLK.       */

    kFRO_LF_DIV_to_I3C2FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 0U),      /*!< Attach FRO_LF_DIV to I3C2FCLK. */
    kFRO_HF_DIV_to_I3C2FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 2U),      /*!< Attach FRO_HF_DIV to I3C2FCLK. */
    kCLK_IN_to_I3C2FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 3U),      /*!< Attach CLK_IN to I3C2FCLK.     */
    kCLK_1M_to_I3C2FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 5U),      /*!< Attach CLK_1M to I3C2FCLK.     */
    kPll1ClkDiv_to_I3C2FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 6U),      /*!< Attach Pll1ClkDiv to I3C2FCLK. */
    kNONE_to_I3C2FCLK       = CLK_ATTACH_MUX(kCLOCK_SelI3C2_FCLK, 7U),      /*!< Attach NONE to I3C2FCLK.       */

    kFRO_LF_DIV_to_I3C3FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 0U),      /*!< Attach FRO_LF_DIV to I3C3FCLK. */
    kFRO_HF_DIV_to_I3C3FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 2U),      /*!< Attach FRO_HF_DIV to I3C3FCLK. */
    kCLK_IN_to_I3C3FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 3U),      /*!< Attach CLK_IN to I3C3FCLK.     */
    kCLK_1M_to_I3C3FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 5U),      /*!< Attach CLK_1M to I3C3FCLK.     */
    kPll1ClkDiv_to_I3C3FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 6U),      /*!< Attach Pll1ClkDiv to I3C3FCLK. */
    kNONE_to_I3C3FCLK       = CLK_ATTACH_MUX(kCLOCK_SelI3C3_FCLK, 7U),      /*!< Attach NONE to I3C3FCLK.       */

    kFRO_LF_DIV_to_CTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 0U),         /*!< Attach FRO_LF_DIV to CTIMER0. */
    kFRO_HF_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 1U),         /*!< Attach FRO_HF to CTIMER0.     */
    kCLK_IN_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 3U),         /*!< Attach CLK_IN to CTIMER0.     */
    kLP_OSC_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 4U),         /*!< Attach LP_OSC to CTIMER0.     */
    kCLK_1M_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 5U),         /*!< Attach CLK_1M to CTIMER0.     */
    kPll1ClkDiv_to_CTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 6U),         /*!< Attach Pll1ClkDiv to CTIMER0. */
    kNONE_to_CTIMER0       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 7U),         /*!< Attach NONE to CTIMER0.       */

    kFRO_LF_DIV_to_CTIMER1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 0U),         /*!< Attach FRO_LF_DIV to CTIMER1. */
    kFRO_HF_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 1U),         /*!< Attach FRO_HF to CTIMER1.     */
    kCLK_IN_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 3U),         /*!< Attach CLK_IN to CTIMER1.     */
    kLP_OSC_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 4U),         /*!< Attach LP_OSC to CTIMER1.     */
    kCLK_1M_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 5U),         /*!< Attach CLK_1M to CTIMER1.     */
    kPll1ClkDiv_to_CTIMER1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 6U),         /*!< Attach Pll1ClkDiv to CTIMER1. */
    kNONE_to_CTIMER1       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 7U),         /*!< Attach NONE to CTIMER1.       */

    kFRO_LF_DIV_to_CTIMER2 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 0U),         /*!< Attach FRO_LF_DIV to CTIMER2. */
    kFRO_HF_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 1U),         /*!< Attach FRO_HF to CTIMER2.     */
    kCLK_IN_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 3U),         /*!< Attach CLK_IN to CTIMER2.     */
    kLP_OSC_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 4U),         /*!< Attach LP_OSC to CTIMER2.     */
    kCLK_1M_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 5U),         /*!< Attach CLK_1M to CTIMER2.     */
    kPll1ClkDiv_to_CTIMER2 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 6U),         /*!< Attach Pll1ClkDiv to CTIMER2. */
    kNONE_to_CTIMER2       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 7U),         /*!< Attach NONE to CTIMER2.       */

    kFRO_LF_DIV_to_CTIMER3 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 0U),         /*!< Attach FRO_LF_DIV to CTIMER3. */
    kFRO_HF_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 1U),         /*!< Attach FRO_HF to CTIMER3.     */
    kCLK_IN_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 3U),         /*!< Attach CLK_IN to CTIMER3.     */
    kLP_OSC_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 4U),         /*!< Attach LP_OSC to CTIMER3.     */
    kCLK_1M_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 5U),         /*!< Attach CLK_1M to CTIMER3.     */
    kPll1ClkDiv_to_CTIMER3 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 6U),         /*!< Attach Pll1ClkDiv to CTIMER3. */
    kNONE_to_CTIMER3       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 7U),         /*!< Attach NONE to CTIMER3.       */

    kFRO_LF_DIV_to_CTIMER4 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 0U),         /*!< Attach FRO_LF_DIV to CTIMER4. */
    kFRO_HF_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 1U),         /*!< Attach FRO_HF to CTIMER4.     */
    kCLK_IN_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 3U),         /*!< Attach CLK_IN to CTIMER4.     */
    kLP_OSC_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 4U),         /*!< Attach LP_OSC to CTIMER4.     */
    kCLK_1M_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 5U),         /*!< Attach CLK_1M to CTIMER4.     */
    kPll1ClkDiv_to_CTIMER4 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 6U),         /*!< Attach Pll1ClkDiv to CTIMER4. */
    kNONE_to_CTIMER4       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 7U),         /*!< Attach NONE to CTIMER4.       */

    kFRO_LF_DIV_to_FLEXIO0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 0U),         /*!< Attach FRO_LF_DIV to FLEXIO0. */
    kFRO_HF_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 1U),         /*!< Attach FRO_HF to FLEXIO0.     */
    kCLK_IN_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 3U),         /*!< Attach CLK_IN to FLEXIO0.     */
    kCLK_1M_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 5U),         /*!< Attach CLK_1M to FLEXIO0.     */
    kPll1ClkDiv_to_FLEXIO0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 6U),         /*!< Attach Pll1ClkDiv to FLEXIO0. */
    kNONE_to_FLEXIO0       = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 7U),         /*!< Attach NONE to FLEXIO0.       */

    kFRO_HF_to_FLEXCAN0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 1U),       /*!< Attach FRO_HF to FLEXCAN0.     */
    kFRO_HF_DIV_to_FLEXCAN0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 2U),       /*!< Attach FRO_HF_DIV to FLEXCAN0. */
    kCLK_IN_to_FLEXCAN0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 3U),       /*!< Attach CLK_IN to FLEXCAN0.     */
    kUSB_PLL_to_FLEXCAN0    = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 4U),       /*!< Attach USB_PLL to FLEXCAN0.    */
    kPll1ClkDiv_to_FLEXCAN0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 6U),       /*!< Attach Pll1ClkDiv to FLEXCAN0. */
    kNONE_to_FLEXCAN0       = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 7U),       /*!< Attach NONE to FLEXCAN0.       */

    kFRO_HF_to_FLEXCAN1     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 1U),       /*!< Attach FRO_HF to FLEXCAN1.     */
    kFRO_HF_DIV_to_FLEXCAN1 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 2U),       /*!< Attach FRO_HF_DIV to FLEXCAN1. */
    kCLK_IN_to_FLEXCAN1     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 3U),       /*!< Attach CLK_IN to FLEXCAN1.     */
    kUSB_PLL_to_FLEXCAN1    = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 4U),       /*!< Attach USB_PLL to FLEXCAN1.    */
    kPll1ClkDiv_to_FLEXCAN1 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 6U),       /*!< Attach Pll1ClkDiv to FLEXCAN1. */
    kNONE_to_FLEXCAN1       = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 7U),       /*!< Attach NONE to FLEXCAN1.       */

    kFRO_LF_DIV_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 0U),               /*!< Attach FRO_LF_DIV to DAC0.  */
    kFRO_HF_DIV_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 2U),               /*!< Attach FRO_HF_DIV to DAC0.  */
    kCLK_IN_to_DAC0     = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 3U),               /*!< Attach CLK_IN to DAC0.      */
    kCLK_1M_to_DAC0     = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 5U),               /*!< Attach CLK_1M to DAC0.      */
    kPll1ClkDiv_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 6U),               /*!< Attach Pll1ClkDiv to DAC0.  */
    kNONE_to_DAC0       = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 7U),               /*!< Attach NONE to DAC0.        */

    kFRO_LF_DIV_to_DAC1 = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 0U),               /*!< Attach FRO_LF_DIV to DAC1.  */
    kFRO_HF_DIV_to_DAC1 = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 2U),               /*!< Attach FRO_HF_DIV to DAC1.  */
    kCLK_IN_to_DAC1     = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 3U),               /*!< Attach CLK_IN to DAC1.      */
    kCLK_1M_to_DAC1     = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 5U),               /*!< Attach CLK_1M to DAC1.      */
    kPll1ClkDiv_to_DAC1 = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 6U),               /*!< Attach Pll1ClkDiv to DAC1.  */
    kNONE_to_DAC1       = CLK_ATTACH_MUX(kCLOCK_SelDAC1, 7U),               /*!< Attach NONE to DAC1.        */

    kFRO_LF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 0U),           /*!< Attach FRO_LF_DIV to LPI2C0. */
    kFRO_HF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 2U),           /*!< Attach FRO_HF_DIV to LPI2C0. */
    kCLK_IN_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 3U),           /*!< Attach CLK_IN to LPI2C0.     */
    kCLK_1M_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 5U),           /*!< Attach CLK_1M to LPI2C0.     */
    kPll1ClkDiv_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 6U),           /*!< Attach Pll1ClkDiv to LPI2C0. */
    kNONE_to_LPI2C0       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 7U),           /*!< Attach NONE to LPI2C0.       */

    kFRO_LF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 0U),           /*!< Attach FRO_LF_DIV to LPI2C1. */
    kFRO_HF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 2U),           /*!< Attach FRO_HF_DIV to LPI2C1. */
    kCLK_IN_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 3U),           /*!< Attach CLK_IN to LPI2C1.     */
    kCLK_1M_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 5U),           /*!< Attach CLK_1M to LPI2C1.     */
    kPll1ClkDiv_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 6U),           /*!< Attach Pll1ClkDiv to LPI2C1. */
    kNONE_to_LPI2C1       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 7U),           /*!< Attach NONE to LPI2C1.       */

    kFRO_LF_DIV_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 0U),           /*!< Attach FRO_LF_DIV to LPI2C2. */
    kFRO_HF_DIV_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 2U),           /*!< Attach FRO_HF_DIV to LPI2C2. */
    kCLK_IN_to_LPI2C2     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 3U),           /*!< Attach CLK_IN to LPI2C2.     */
    kCLK_1M_to_LPI2C2     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 5U),           /*!< Attach CLK_1M to LPI2C2.     */
    kPll1ClkDiv_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 6U),           /*!< Attach Pll1ClkDiv to LPI2C2. */
    kNONE_to_LPI2C2       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 7U),           /*!< Attach NONE to LPI2C2.       */

    kFRO_LF_DIV_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 0U),           /*!< Attach FRO_LF_DIV to LPI2C3. */
    kFRO_HF_DIV_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 2U),           /*!< Attach FRO_HF_DIV to LPI2C3. */
    kCLK_IN_to_LPI2C3     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 3U),           /*!< Attach CLK_IN to LPI2C3.     */
    kCLK_1M_to_LPI2C3     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 5U),           /*!< Attach CLK_1M to LPI2C3.     */
    kPll1ClkDiv_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 6U),           /*!< Attach Pll1ClkDiv to LPI2C3. */
    kNONE_to_LPI2C3       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 7U),           /*!< Attach NONE to LPI2C3.       */

    kFRO_LF_DIV_to_LPI2C4 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 0U),           /*!< Attach FRO_LF_DIV to LPI2C4. */
    kFRO_HF_DIV_to_LPI2C4 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 2U),           /*!< Attach FRO_HF_DIV to LPI2C4. */
    kCLK_IN_to_LPI2C4     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 3U),           /*!< Attach CLK_IN to LPI2C4.     */
    kCLK_1M_to_LPI2C4     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 5U),           /*!< Attach CLK_1M to LPI2C4.     */
    kPll1ClkDiv_to_LPI2C4 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 6U),           /*!< Attach Pll1ClkDiv to LPI2C4. */
    kNONE_to_LPI2C4       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C4, 7U),           /*!< Attach NONE to LPI2C4.       */

    kFRO_LF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 0U),           /*!< Attach FRO_LF_DIV to LPSPI0. */
    kFRO_HF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 2U),           /*!< Attach FRO_HF_DIV to LPSPI0. */
    kCLK_IN_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 3U),           /*!< Attach CLK_IN to LPSPI0.     */
    kCLK_1M_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 5U),           /*!< Attach CLK_1M to LPSPI0.     */
    kPll1ClkDiv_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 6U),           /*!< Attach Pll1ClkDiv to LPSPI0. */
    kNONE_to_LPSPI0       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 7U),           /*!< Attach NONE to LPSPI0.       */

    kFRO_LF_DIV_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 0U),           /*!< Attach FRO_LF_DIV to LPSPI1. */
    kFRO_HF_DIV_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 2U),           /*!< Attach FRO_HF_DIV to LPSPI1. */
    kCLK_IN_to_LPSPI1     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 3U),           /*!< Attach CLK_IN to LPSPI1.     */
    kCLK_1M_to_LPSPI1     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 5U),           /*!< Attach CLK_1M to LPSPI1.     */
    kPll1ClkDiv_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 6U),           /*!< Attach Pll1ClkDiv to LPSPI1. */
    kNONE_to_LPSPI1       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 7U),           /*!< Attach NONE to LPSPI1.       */

    kFRO_LF_DIV_to_LPSPI2 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 0U),           /*!< Attach FRO_LF_DIV to LPSPI2. */
    kFRO_HF_DIV_to_LPSPI2 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 2U),           /*!< Attach FRO_HF_DIV to LPSPI2. */
    kCLK_IN_to_LPSPI2     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 3U),           /*!< Attach CLK_IN to LPSPI2.     */
    kCLK_1M_to_LPSPI2     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 5U),           /*!< Attach CLK_1M to LPSPI2.     */
    kPll1ClkDiv_to_LPSPI2 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 6U),           /*!< Attach Pll1ClkDiv to LPSPI2. */
    kNONE_to_LPSPI2       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI2, 7U),           /*!< Attach NONE to LPSPI2.       */

    kFRO_LF_DIV_to_LPSPI3 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 0U),           /*!< Attach FRO_LF_DIV to LPSPI3. */
    kFRO_HF_DIV_to_LPSPI3 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 2U),           /*!< Attach FRO_HF_DIV to LPSPI3. */
    kCLK_IN_to_LPSPI3     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 3U),           /*!< Attach CLK_IN to LPSPI3.     */
    kCLK_1M_to_LPSPI3     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 5U),           /*!< Attach CLK_1M to LPSPI3.     */
    kPll1ClkDiv_to_LPSPI3 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 6U),           /*!< Attach Pll1ClkDiv to LPSPI3. */
    kNONE_to_LPSPI3       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI3, 7U),           /*!< Attach NONE to LPSPI3.       */

    kFRO_LF_DIV_to_LPSPI4 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 0U),           /*!< Attach FRO_LF_DIV to LPSPI4. */
    kFRO_HF_DIV_to_LPSPI4 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 2U),           /*!< Attach FRO_HF_DIV to LPSPI4. */
    kCLK_IN_to_LPSPI4     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 3U),           /*!< Attach CLK_IN to LPSPI4.     */
    kCLK_1M_to_LPSPI4     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 5U),           /*!< Attach CLK_1M to LPSPI4.     */
    kPll1ClkDiv_to_LPSPI4 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 6U),           /*!< Attach Pll1ClkDiv to LPSPI4. */
    kNONE_to_LPSPI4       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI4, 7U),           /*!< Attach NONE to LPSPI4.       */

    kFRO_LF_DIV_to_LPSPI5 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 0U),           /*!< Attach FRO_LF_DIV to LPSPI5. */
    kFRO_HF_DIV_to_LPSPI5 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 2U),           /*!< Attach FRO_HF_DIV to LPSPI5. */
    kCLK_IN_to_LPSPI5     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 3U),           /*!< Attach CLK_IN to LPSPI5.     */
    kCLK_1M_to_LPSPI5     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 5U),           /*!< Attach CLK_1M to LPSPI5.     */
    kPll1ClkDiv_to_LPSPI5 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 6U),           /*!< Attach Pll1ClkDiv to LPSPI5. */
    kNONE_to_LPSPI5       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI5, 7U),           /*!< Attach NONE to LPSPI5.       */

    kFRO_LF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 0U),         /*!< Attach FRO_LF_DIV to LPUART0. */
    kFRO_HF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 2U),         /*!< Attach FRO_HF_DIV to LPUART0. */
    kCLK_IN_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 3U),         /*!< Attach CLK_IN to LPUART0.     */
    kLP_OSC_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 4U),         /*!< Attach LP_OSC to LPUART0.     */
    kCLK_1M_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 5U),         /*!< Attach CLK_1M to LPUART0.     */
    kPll1ClkDiv_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 6U),         /*!< Attach Pll1ClkDiv to LPUART0. */
    kNONE_to_LPUART0       = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 7U),         /*!< Attach NONE to LPUART0.       */

    kFRO_LF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 0U),         /*!< Attach FRO_LF_DIV to LPUART1. */
    kFRO_HF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 2U),         /*!< Attach FRO_HF_DIV to LPUART1. */
    kCLK_IN_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 3U),         /*!< Attach CLK_IN to LPUART1.     */
    kLP_OSC_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 4U),         /*!< Attach LP_OSC to LPUART1.     */
    kCLK_1M_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 5U),         /*!< Attach CLK_1M to LPUART1.     */
    kPll1ClkDiv_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 6U),         /*!< Attach Pll1ClkDiv to LPUART1. */
    kNONE_to_LPUART1       = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 7U),         /*!< Attach NONE to LPUART1.       */

    kFRO_LF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 0U),         /*!< Attach FRO_LF_DIV to LPUART2. */
    kFRO_HF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 2U),         /*!< Attach FRO_HF_DIV to LPUART2. */
    kCLK_IN_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 3U),         /*!< Attach CLK_IN to LPUART2.     */
    kLP_OSC_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 4U),         /*!< Attach LP_OSC to LPUART2.     */
    kCLK_1M_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 5U),         /*!< Attach CLK_1M to LPUART2.     */
    kPll1ClkDiv_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 6U),         /*!< Attach Pll1ClkDiv to LPUART2. */
    kNONE_to_LPUART2       = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 7U),         /*!< Attach NONE to LPUART2.       */

    kFRO_LF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 0U),         /*!< Attach FRO_LF_DIV to LPUART3. */
    kFRO_HF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 2U),         /*!< Attach FRO_HF_DIV to LPUART3. */
    kCLK_IN_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 3U),         /*!< Attach CLK_IN to LPUART3.     */
    kLP_OSC_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 4U),         /*!< Attach LP_OSC to LPUART3.     */
    kCLK_1M_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 5U),         /*!< Attach CLK_1M to LPUART3.     */
    kPll1ClkDiv_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 6U),         /*!< Attach Pll1ClkDiv to LPUART3. */
    kNONE_to_LPUART3       = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 7U),         /*!< Attach NONE to LPUART3.       */

    kFRO_LF_DIV_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 0U),         /*!< Attach FRO_LF_DIV to LPUART4. */
    kFRO_HF_DIV_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 2U),         /*!< Attach FRO_HF_DIV to LPUART4. */
    kCLK_IN_to_LPUART4     = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 3U),         /*!< Attach CLK_IN to LPUART4.     */
    kLP_OSC_to_LPUART4     = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 4U),         /*!< Attach LP_OSC to LPUART4.     */
    kCLK_1M_to_LPUART4     = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 5U),         /*!< Attach CLK_1M to LPUART4.     */
    kPll1ClkDiv_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 6U),         /*!< Attach Pll1ClkDiv to LPUART4. */
    kNONE_to_LPUART4       = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 7U),         /*!< Attach NONE to LPUART4.       */

    kFRO_LF_DIV_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 0U),         /*!< Attach FRO_LF_DIV to LPUART5. */
    kFRO_HF_DIV_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 2U),         /*!< Attach FRO_HF_DIV to LPUART5. */
    kCLK_IN_to_LPUART5     = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 3U),         /*!< Attach CLK_IN to LPUART5.     */
    kLP_OSC_to_LPUART5     = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 4U),         /*!< Attach LP_OSC to LPUART5.     */
    kCLK_1M_to_LPUART5     = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 5U),         /*!< Attach CLK_1M to LPUART5.     */
    kPll1ClkDiv_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 6U),         /*!< Attach Pll1ClkDiv to LPUART5. */
    kNONE_to_LPUART5       = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 7U),         /*!< Attach NONE to LPUART5.       */

    kCLK_32K_to_USBHS      = CLK_ATTACH_MUX(kCLOCK_SelUSBHS, 0U),           /*!< Attach CLK_32K to USBHS.*/
    kCLK_1M_to_USBHS       = CLK_ATTACH_MUX(kCLOCK_SelUSBHS, 1U),           /*!< Attach CLK_1M to USBHS.*/
    kPHY_CLK_XTAL_to_USBHS = CLK_ATTACH_MUX(kCLOCK_SelUSBHS, 2U),           /*!< Attach CLK_IN to USBHS.*/
    kNONE_to_USBHS         = CLK_ATTACH_MUX(kCLOCK_SelUSBHS, 3U),           /*!< Attach NONE to USBHS.  */

    kFRO_HF_to_USBHS_PHY = CLK_ATTACH_MUX(kCLOCK_SelUSBHS_PHY, 1U),         /*!< Attach FRO_HF to USBHS_PHY.*/
    kCLK_IN_to_USBHS_PHY = CLK_ATTACH_MUX(kCLOCK_SelUSBHS_PHY, 2U),         /*!< Attach CLK_IN to USBHS_PHY.*/
    kNONE_to_USBHS_PHY   = CLK_ATTACH_MUX(kCLOCK_SelUSBHS_PHY, 3U),         /*!< Attach NONE to USBHS_PHY.  */

    kFRO_LF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 0U),           /*!< Attach FRO_LF_DIV to LPTMR0. */
    kFRO_HF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 2U),           /*!< Attach FRO_HF_DIV to LPTMR0. */
    kCLK_IN_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 3U),           /*!< Attach CLK_IN to LPTMR0.     */
    kCLK_1M_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 5U),           /*!< Attach CLK_1M to LPTMR0.     */
    kPll1ClkDiv_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 6U),           /*!< Attach Pll1ClkDiv to LPTMR0. */
    kNONE_to_LPTMR0       = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 7U),           /*!< Attach NONE to LPTMR0.       */

    kCLK_16K_to_OSTIMER = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 0U),           /*!< Attach FRO16K to OSTIMER0.     */
    kCLK_32K_to_OSTIMER = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 1U),           /*!< Attach OSC_32K[1] to OSTIMER0. */
    kCLK_1M_to_OSTIMER  = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 2U),           /*!< Attach CLK_1M to OSTIMER0.     */
    kNONE_to_OSTIMER    = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 3U),           /*!< Attach NONE to OSTIMER0.       */

    kFRO_LF_DIV_to_ADC = CLK_ATTACH_MUX(kCLOCK_SelADC, 0U),                 /*!< Attach FRO_LF_DIV to ADC. */
    kFRO_HF_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 1U),                 /*!< Attach FRO_HF to ADC.     */
    kCLK_IN_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 3U),                 /*!< Attach CLK_IN to ADC.     */
    kUSB_PLL_to_ADC    = CLK_ATTACH_MUX(kCLOCK_SelADC, 4U),                 /*!< Attach USB_PL to ADC.     */
    kCLK_1M_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 5U),                 /*!< Attach CLK_1M to ADC.     */
    kPll1ClkDiv_to_ADC = CLK_ATTACH_MUX(kCLOCK_SelADC, 6U),                 /*!< Attach Pll1ClkDiv to ADC. */
    kNONE_to_ADC       = CLK_ATTACH_MUX(kCLOCK_SelADC, 7U),                 /*!< Attach NONE to ADC.       */

    kFRO_LF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 0U),            /*!< Attach FRO_LF_DIV to CMP0. */
    kFRO_HF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 2U),            /*!< Attach FRO_HF_DIV to CMP0. */
    kCLK_IN_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 3U),            /*!< Attach CLK_IN to CMP0.     */
    kCLK_1M_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 5U),            /*!< Attach CLK_1M to CMP0.     */
    kPll1ClkDiv_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 6U),            /*!< Attach Pll1ClkDiv to CMP0. */
    kNONE_to_CMP0       = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 7U),            /*!< Attach NONE to CMP0.       */

    kCPU_CLK_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 0U),                /*!< Attach CPU_CLK to TRACE. */
    kCLK_1M_to_TRACE  = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 1U),                /*!< Attach CLK_1M to TRACE.  */
    kCLK_16K_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 2U),                /*!< Attach CLK_16K to TRACE. */
    kNONE_to_TRACE    = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 3U),                /*!< Attach NONE to TRACE.    */

    kFRO12M_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 0U),           /*!< Attach FRO_12M to CLKOUT.    */
    kFRO_HF_DIV_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 1U),           /*!< Attach FRO_HF_DIV to CLKOUT. */
    kCLK_IN_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 2U),           /*!< Attach CLK_IN to CLKOUT.     */
    kLP_OSC_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 3U),           /*!< Attach LP_OSC to CLKOUT.     */
    kPll1ClkDiv_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 5U),           /*!< Attach Pll1Clk to CLKOUT.    */
    kSLOW_CLK_to_CLKOUT   = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 6U),           /*!< Attach SLOW_CLK to CLKOUT.   */
    kNONE_to_CLKOUT       = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 7U),           /*!< Attach NONE to CLKOUT.       */

    kCPU_CLK_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 0U),            /*!< Attach CPU_CLK to SYSTICK. */
    kCLK_1M_to_SYSTICK  = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 1U),            /*!< Attach CLK_1M to SYSTICK.  */
    kCLK_16K_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 2U),            /*!< Attach CLK_16K to SYSTICK. */
    kNONE_to_SYSTICK    = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 3U),            /*!< Attach NONE to SYSTICK.    */

    kCLK_16K_to_WWDT1    = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 0U),             /*!< Attach CLK_16K to WWDT1.    */
    kFRO_HF_DIV_to_WWDT1 = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 1U),             /*!< Attach FRO_HF_DIV to WWDT1. */
    kCLK_1M_to_WWDT1     = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 2U),             /*!< Attach CLK_1M to WWDT1.     */

    kCLK_IN_to_TENBASET_PHY  = CLK_ATTACH_MUX(kCLOCK_SelTENBASET_PHY0, 3U), /*!< Attach CLK_IN to TENBASET_PHY.    */
    kPll1Clk_to_TENBASET_PHY = CLK_ATTACH_MUX(kCLOCK_SelTENBASET_PHY0, 6U), /*!< Attach Pll1Clk to TENBASET_PHY. */
    kNONE_to_TENBASET_PHY    = CLK_ATTACH_MUX(kCLOCK_SelTENBASET_PHY0, 7U), /*!< Attach NONE to TENBASET_PHY.     */

    kFRO_HF_to_ESPI     = CLK_ATTACH_MUX(kCLOCK_SelESPI0, 1U),              /*!< Attach FRO_HF to ESPI.     */
    kPll1ClkDiv_to_ESPI = CLK_ATTACH_MUX(kCLOCK_SelESPI0, 6U),              /*!< Attach Pll1ClkDiv to ESPI. */
    kNONE_to_ESPI       = CLK_ATTACH_MUX(kCLOCK_SelESPI0, 7U),              /*!< Attach NONE to ESPI.       */

    kFRO_HF_to_FLEXSPI  = CLK_ATTACH_MUX(kCLOCK_SelFLEXSPI0, 1),            /*!< Attach FRO_HF to FLEXSPI.  */
    kUSB_PFD_to_FLEXSPI = CLK_ATTACH_MUX(kCLOCK_SelFLEXSPI0, 4),            /*!< Attach USB_PFD to FLEXSPI. */
    kPll1Clk_to_FLEXSPI = CLK_ATTACH_MUX(kCLOCK_SelFLEXSPI0, 6),            /*!< Attach Pll1Clk to FLEXSPI. */
    kNONE_to_FLEXSPI    = CLK_ATTACH_MUX(kCLOCK_SelFLEXSPI0, 7),            /*!< Attach NONE to FLEXSPI.    */

    kFRO_LF_DIV_to_TSI0 = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 0U),               /*!< Attach FRO_LF_DIV to TSI0. */
    kFRO_HF_DIV_to_TSI0 = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 2U),               /*!< Attach FRO_HF_DIV to TSI0. */
    kCLK_IN_to_TSI0     = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 3U),               /*!< Attach CLK_IN to TSI0.     */
    kCLK_1M_to_TSI0     = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 5U),               /*!< Attach CLK_1M to TSI0.     */
    kPll1ClkDiv_to_TSI0 = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 6U),               /*!< Attach Pll1ClkDiv to TSI0. */
    kNONE_to_TSI0       = CLK_ATTACH_MUX(kCLOCK_SelTSI0, 7U),               /*!< Attach NONE to TSI0.       */

    kCLK_IN_to_ENETRMII  = CLK_ATTACH_MUX(kCLOCK_SelRMII, 3U),              /*!< Attach CLK_IN to ENETRMII.  */
    kPll1Clk_to_ENETRMII = CLK_ATTACH_MUX(kCLOCK_SelRMII, 6U),              /*!< Attach Pll1Clk to ENETRMII. */
    kNONE_to_ENETRMII    = CLK_ATTACH_MUX(kCLOCK_SelRMII, 7U),              /*!< Attach NONE to ENETRMII.    */

    kCLK_IN_to_ENETPTPREF       = CLK_ATTACH_MUX(kCLOCK_SelE1588, 3U),      /*!< Attach LK_IN to ENETPTPREF.        */
    kENET0_TX_CLK_to_ENETPTPREF = CLK_ATTACH_MUX(kCLOCK_SelE1588, 4U),      /*!< Attach ENET0_TX_CLK to ENETPTPREF. */
    kPll1Clk_to_ENETPTPREF      = CLK_ATTACH_MUX(kCLOCK_SelE1588, 6U),      /*!< Attach Pll1Clk to ENETRMII.        */
    kNONE_to_ENETPTPREF         = CLK_ATTACH_MUX(kCLOCK_SelE1588, 7U),      /*!< Attach NONE to ENETPTPREF.         */

    kNONE_to_NONE = (0xFFFFFFFFU),                                          /*!< Attach NONE to NONE. */

} clock_attach_id_t;

/*! @brief Clock dividers */
typedef enum _clock_div_name
{
    /* CLKDIV in MRCC */
    kCLOCK_DivI3C0_FCLK     = (0x104U + 0x800U), /*!< I3C0_FCLK     clock divider */
    kCLOCK_DivI3C1_FCLK     = (0x10CU + 0x800U), /*!< I3C1_FCLK     clock divider */
    kCLOCK_DivCTIMER0       = (0x114U + 0x800U), /*!< CTIMER0       clock divider */
    kCLOCK_DivCTIMER1       = (0x11CU + 0x800U), /*!< CTIMER1       clock divider */
    kCLOCK_DivCTIMER2       = (0x124U + 0x800U), /*!< CTIMER2       clock divider */
    kCLOCK_DivCTIMER3       = (0x12CU + 0x800U), /*!< CTIMER3       clock divider */
    kCLOCK_DivCTIMER4       = (0x134U + 0x800U), /*!< CTIMER4       clock divider */
    kCLOCK_DivWWDT0         = (0x13CU + 0x800U), /*!< WWDT0         clock divider */
    kCLOCK_DivWWDT1         = (0x144U + 0x800U), /*!< WWDT1         clock divider */
    kCLOCK_DivE1588         = (0x14CU + 0x800U), /*!< E1588         clock divider */
    kCLOCK_DivRMII          = (0x154U + 0x800U), /*!< RMII          clock divider */
    kCLOCK_DivESPI0         = (0x15CU + 0x800U), /*!< ESPI0         clock divider */
    kCLOCK_DivFLEXSPI0      = (0x164U + 0x800U), /*!< FLEXSPI0      clock divider */
    kCLOCK_DivLPSPI2        = (0x16CU + 0x800U), /*!< LPSPI2        clock divider */
    kCLOCK_DivLPSPI3        = (0x174U + 0x800U), /*!< LPSPI3        clock divider */
    kCLOCK_DivLPSPI4        = (0x17CU + 0x800U), /*!< LPSPI4        clock divider */
    kCLOCK_DivLPSPI5        = (0x184U + 0x800U), /*!< LPSPI5        clock divider */
    kCLOCK_DivTENBASET_PHY0 = (0x18CU + 0x800U), /*!< TENBASET_PHY0 clock divider */
    kCLOCK_DivUSBHS_PHY     = (0x19CU + 0x800U), /*!< USBHS_PHY      clock divider */
    kCLOCK_DivFLEXIO0       = (0x1A4U + 0x800U), /*!< FLEXIO0       clock divider */
    kCLOCK_DivLPI2C0        = (0x1ACU + 0x800U), /*!< LPI2C0        clock divider */
    kCLOCK_DivLPI2C1        = (0x1B4U + 0x800U), /*!< LPI2C1        clock divider */
    kCLOCK_DivLPSPI0        = (0x1BCU + 0x800U), /*!< LPSPI0        clock divider */
    kCLOCK_DivLPSPI1        = (0x1C4U + 0x800U), /*!< LPSPI1        clock divider */
    kCLOCK_DivI3C2_FCLK     = (0x1CCU + 0x800U), /*!< I3C2_FCLK     clock divider */
    kCLOCK_DivLPUART0       = (0x1D4U + 0x800U), /*!< LPUART0       clock divider */
    kCLOCK_DivLPUART1       = (0x1DCU + 0x800U), /*!< LPUART1       clock divider */
    kCLOCK_DivLPUART2       = (0x1E4U + 0x800U), /*!< LPUART2       clock divider */
    kCLOCK_DivLPUART3       = (0x1ECU + 0x800U), /*!< LPUART3       clock divider */
    kCLOCK_DivLPUART4       = (0x1F4U + 0x800U), /*!< LPUART4       clock divider */
    kCLOCK_DivLPTMR0        = (0x1FCU + 0x800U), /*!< LPTMR0        clock divider */
    kCLOCK_DivADC           = (0x20CU + 0x800U), /*!< ADCx          clock divider */
    kCLOCK_DivCMP0_FUNC     = (0x214U + 0x800U), /*!< CMP0_FUNC     clock divider */
    kCLOCK_DivCMP0_RR       = (0x21CU + 0x800U), /*!< CMP0_RR       clock divider */
    kCLOCK_DivDAC0          = (0x224U + 0x800U), /*!< DAC0          clock divider */
    kCLOCK_DivDAC1          = (0x22CU + 0x800U), /*!< DAC1          clock divider */
    kCLOCK_DivTSI0          = (0x234U + 0x800U), /*!< TSI0          clock divider */
    kCLOCK_DivFLEXCAN0      = (0x23CU + 0x800U), /*!< FLEXCAN0      clock divider */
    kCLOCK_DivFLEXCAN1      = (0x244U + 0x800U), /*!< FLEXCAN1      clock divider */
    kCLOCK_DivLPI2C2        = (0x24CU + 0x800U), /*!< LPI2C2        clock divider */
    kCLOCK_DivLPI2C3        = (0x254U + 0x800U), /*!< LPI2C3        clock divider */
    kCLOCK_DivLPI2C4        = (0x25CU + 0x800U), /*!< LPI2C4        clock divider */
    kCLOCK_DivLPUART5       = (0x264U + 0x800U), /*!< LPUART5       clock divider */
    kCLOCK_DivI3C3_FCLK     = (0x26CU + 0x800U), /*!< I3C3_FCLK     clock divider */
    kCLOCK_DivTRACE         = (0x274U + 0x800U), /*!< TRACE         clock divider */
    kCLOCK_DivCLKOUT        = (0x27CU + 0x800U), /*!< CLKOUT        clock divider */
    kCLOCK_DivSYSTICK       = (0x284U + 0x800U), /*!< SYSTICK       clock divider */

    /* CLKDIV in SYSCON */
    kCLOCK_DivSLOWCLK = (0x088U + 0x0U), /*!< SLOWCLK clock divider */
    kCLOCK_DivBUSCLK  = (0x084U + 0x0U), /*!< BUSCLK  clock divider */
    kCLOCK_DivAHBCLK  = (0x080U + 0x0U), /*!< AHBCLK  clock divider */
    kCLOCK_DivFRO_HF  = (0x090U + 0x0U), /*!< FROHF   clock divider */
    kCLOCK_DivFRO_LF  = (0x094U + 0x0U), /*!< FROLF   clock divider */
    kCLOCK_DivPLL1CLK = (0x0E4U + 0x0U), /*!< PLL1CLK clock divider */
} clock_div_name_t;

/*!< MAX clock divider */
#define kCLOCK_DivMax kCLOCK_DivSYSTICK

/*!
 * @brief FRO16K connection to each power domain.
 */
typedef enum _clke_16k
{
    kCLKE_16K_SYSTEM   = VBAT_FROCLKE_CLKE(1U), /*!< To VSYS domain.               */
    kCLKE_16K_COREMAIN = VBAT_FROCLKE_CLKE(2U), /*!< To VDD_CORE domain.           */
    kCLKE_16K_VBAT     = VBAT_FROCLKE_CLKE(4U), /*!< To VBAT domain.               */
    kCLKE_16K_ALL      = VBAT_FROCLKE_CLKE(7U)  /*!< To VSYS,VDD_CORE,VBAT domain. */
} clke_16k_t;

/*!
 * @brief SCG status return codes.
 */
enum _scg_status
{
    kStatus_SCG_Busy       = MAKE_STATUS(kStatusGroup_SCG, 1), /*!< Clock is busy.  */
    kStatus_SCG_InvalidSrc = MAKE_STATUS(kStatusGroup_SCG, 2)  /*!< Invalid source. */
};

/*!
 * @brief sirc trim mode.
 */
typedef enum _sirc_trim_mode
{
    kSCG_SircTrimNonUpdate = SCG_SIRCCSR_SIRCTREN_MASK,
    /*!< Trim enable but not enable trim value update. In this mode, the
     trim value is fixed to the initialized value which is defined by
     trimCoar and trimFine in configure structure \ref sirc_trim_mode_t.*/

    kSCG_SircTrimUpdate = SCG_SIRCCSR_SIRCTREN_MASK | SCG_SIRCCSR_SIRCTRUP_MASK
    /*!< Trim enable and trim value update enable. In this mode, the trim
     value is auto update. */

} sirc_trim_mode_t;

/*!
 * @brief sirc trim source.
 */
typedef enum _sirc_trim_src
{
    kNoTrimSrc             = 0, /*!< No external tirm source.    */
    kSCG_SircTrimSrcSysOsc = 2U /*!< System OSC.                 */
} sirc_trim_src_t;

/*!
 * @brief sirc trim configuration.
 */
typedef struct _sirc_trim_config
{
    sirc_trim_mode_t trimMode; /*!< Trim mode.       */
    sirc_trim_src_t trimSrc;   /*!< Trim source.     */
    uint16_t trimDiv;          /*!< Divider of SOSC. */
    uint8_t cltrim;            /*!< Trim coarse value; Irrelevant if trimMode is
                                  kSCG_TrimUpdate. */
    uint8_t ccotrim;           /*!< Trim fine value; Irrelevant if trimMode is
                                  kSCG_TrimUpdate. */
} sirc_trim_config_t;

/*!
 * @brief SCG system OSC monitor mode.
 */
typedef enum _scg_sosc_monitor_mode
{
    kSCG_SysOscMonitorDisable = 0U,                         /*!< Monitor disabled. */
    kSCG_SysOscMonitorInt     = SCG_SOSCCSR_SOSCCM_MASK,    /*!< Interrupt when the SOSC
                                                               error is detected. */
    kSCG_SysOscMonitorReset =
        SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK /*!< Reset when the SOSC error is detected. */
} scg_sosc_monitor_mode_t;

/*!
 * @brief SCG PLL1 monitor mode.
 */
typedef enum _scg_pll1_monitor_mode
{
    kSCG_Pll1MonitorDisable = 0U,                           /*!< Monitor disabled. */
    kSCG_Pll1MonitorInt     = SCG_SPLLCSR_SPLLCM_MASK,      /*!< Interrupt when the PLL1 Clock error is detected. */
    kSCG_Pll1MonitorReset =
        SCG_SPLLCSR_SPLLCM_MASK | SCG_SPLLCSR_SPLLCMRE_MASK /*!< Reset when the PLL1 Clock error is detected. */
} scg_pll1_monitor_mode_t;

/*!
 * @brief The active run mode (voltage level).
 */
typedef enum _run_mode
{
    kMD_Mode, /*!< Middle driver mode, VDD_CORE: 1.0V   */
    kSD_Mode, /*!< Standard driver mode,VDD_CORE: 1.1V  */
    kOD_Mode, /*!< Over drive mode, VDD_CORE: 1.2V      */
} run_mode_t;

/*! @brief OSC32K clock gate */
typedef enum _osc32k_clk_gate_id
{
    kCLOCK_Osc32kToSys  = 0x1, /*!< OSC32K[0] to SYSTEM domain. */
    kCLOCK_Osc32kToCore = 0x2, /*!< OSC32K[1] to CORE domain.   */
    kCLOCK_Osc32kToVbat = 0x4, /*!< OSC32K[2] to VBAT domain.  */
    kCLOCK_Osc32kToAll  = 0x7, /*!< OSC32K to SYSTEM,CORE,VBAT domain. */
} osc32k_clk_gate_id_t;

/*!
 * @brief The enumerator of internal capacitance of OSC's XTAL pin.
 */
typedef enum _vbat_osc_xtal_cap
{
    kVBAT_OscXtal0pFCap  = 0x0U, /*!< The internal capacitance for XTAL pin is 0pF. */
    kVBAT_OscXtal2pFCap  = 0x1U, /*!< The internal capacitance for XTAL pin is 2pF. */
    kVBAT_OscXtal4pFCap  = 0x2U, /*!< The internal capacitance for XTAL pin is 4pF. */
    kVBAT_OscXtal6pFCap  = 0x3U, /*!< The internal capacitance for XTAL pin is 6pF. */
    kVBAT_OscXtal8pFCap  = 0x4U, /*!< The internal capacitance for XTAL pin is 8pF. */
    kVBAT_OscXtal10pFCap = 0x5U, /*!< The internal capacitance for XTAL pin is 10pF. */
    kVBAT_OscXtal12pFCap = 0x6U, /*!< The internal capacitance for XTAL pin is 12pF. */
    kVBAT_OscXtal14pFCap = 0x7U, /*!< The internal capacitance for XTAL pin is 14pF. */
    kVBAT_OscXtal16pFCap = 0x8U, /*!< The internal capacitance for XTAL pin is 16pF. */
    kVBAT_OscXtal18pFCap = 0x9U, /*!< The internal capacitance for XTAL pin is 18pF. */
    kVBAT_OscXtal20pFCap = 0xAU, /*!< The internal capacitance for XTAL pin is 20pF. */
    kVBAT_OscXtal22pFCap = 0xBU, /*!< The internal capacitance for XTAL pin is 22pF. */
    kVBAT_OscXtal24pFCap = 0xCU, /*!< The internal capacitance for XTAL pin is 24pF. */
    kVBAT_OscXtal26pFCap = 0xDU, /*!< The internal capacitance for XTAL pin is 26pF. */
    kVBAT_OscXtal28pFCap = 0xEU, /*!< The internal capacitance for XTAL pin is 28pF. */
    kVBAT_OscXtal30pFCap = 0xFU, /*!< The internal capacitance for XTAL pin is 30pF. */
} vbat_osc_xtal_cap_t;

/*!
 * @brief The enumerator of internal capacitance of OSC's EXTAL pin.
 */
typedef enum _vbat_osc_extal_cap
{
    kVBAT_OscExtal0pFCap  = 0x0U, /*!< The internal capacitance for EXTAL pin is 0pF. */
    kVBAT_OscExtal2pFCap  = 0x1U, /*!< The internal capacitance for EXTAL pin is 2pF. */
    kVBAT_OscExtal4pFCap  = 0x2U, /*!< The internal capacitance for EXTAL pin is 4pF. */
    kVBAT_OscExtal6pFCap  = 0x3U, /*!< The internal capacitance for EXTAL pin is 6pF. */
    kVBAT_OscExtal8pFCap  = 0x4U, /*!< The internal capacitance for EXTAL pin is 8pF. */
    kVBAT_OscExtal10pFCap = 0x5U, /*!< The internal capacitance for EXTAL pin is 10pF. */
    kVBAT_OscExtal12pFCap = 0x6U, /*!< The internal capacitance for EXTAL pin is 12pF. */
    kVBAT_OscExtal14pFCap = 0x7U, /*!< The internal capacitance for EXTAL pin is 14pF. */
    kVBAT_OscExtal16pFCap = 0x8U, /*!< The internal capacitance for EXTAL pin is 16pF. */
    kVBAT_OscExtal18pFCap = 0x9U, /*!< The internal capacitance for EXTAL pin is 18pF. */
    kVBAT_OscExtal20pFCap = 0xAU, /*!< The internal capacitance for EXTAL pin is 20pF. */
    kVBAT_OscExtal22pFCap = 0xBU, /*!< The internal capacitance for EXTAL pin is 22pF. */
    kVBAT_OscExtal24pFCap = 0xCU, /*!< The internal capacitance for EXTAL pin is 24pF. */
    kVBAT_OscExtal26pFCap = 0xDU, /*!< The internal capacitance for EXTAL pin is 26pF. */
    kVBAT_OscExtal28pFCap = 0xEU, /*!< The internal capacitance for EXTAL pin is 28pF. */
    kVBAT_OscExtal30pFCap = 0xFU, /*!< The internal capacitance for EXTAL pin is 30pF. */
} vbat_osc_extal_cap_t;

/*!
 * @brief The enumerator of osc amplifier gain fine adjustment.
 * Changes the oscillator amplitude by modifying the automatic gain control (AGC).
 */
typedef enum _vbat_osc_fine_adjustment_value
{
    kVBAT_OscCoarseAdjustment05 = 0U,
    kVBAT_OscCoarseAdjustment10 = 1U,
    kVBAT_OscCoarseAdjustment18 = 2U,
    kVBAT_OscCoarseAdjustment33 = 3U,
} vbat_osc_coarse_adjustment_value_t;

/*!
 * @brief The structure of oscillator configuration.
 */
typedef struct _vbat_osc_config
{
    bool enableInternalCapBank;         /*!< enable/disable the internal capacitance bank. */

    bool enableCrystalOscillatorBypass; /*!< enable/disable the crystal oscillator bypass. */

    vbat_osc_xtal_cap_t xtalCap;        /*!< The internal capacitance for the OSC XTAL pin from the capacitor bank,
                                                  only useful when the internal capacitance bank is enabled. */
    vbat_osc_extal_cap_t extalCap; /*!< The internal capacitance for the OSC EXTAL pin from the capacitor bank, only
                                      useful when the internal capacitance bank is enabled. */
    vbat_osc_coarse_adjustment_value_t
        coarseAdjustment;          /*!< 32kHz crystal oscillator amplifier coarse adjustment value. */
} vbat_osc_config_t;

/*!
 * @brief The enumerator of Initialization Trim.
 */
typedef enum _vbat_osc_init_trim
{
    kVBAT_OscInitTrim8000ms = 0x0U, /*!< Configures the start-up time of the oscillator to 8s. */
    kVBAT_OscInitTrim4000ms = 0x1U, /*!< Configures the start-up time of the oscillator to 4s. */
    kVBAT_OscInitTrim2000ms = 0x2U, /*!< Configures the start-up time of the oscillator to 2s. */
    kVBAT_OscInitTrim1000ms = 0x3U, /*!< Configures the start-up time of the oscillator to 1s. */
    kVBAT_OscInitTrim500ms  = 0x4U, /*!< Configures the start-up time of the oscillator to 0.5s. */
    kVBAT_OscInitTrim250ms  = 0x5U, /*!< Configures the start-up time of the oscillator to 0.25s. */
    kVBAT_OscInitTrim125ms  = 0x6U, /*!< Configures the start-up time of the oscillator to 0.125s. */
    kVBAT_OscInitTrimHalfms = 0x7U, /*!< Configures the start-up time of the oscillator to 0.5ms. */
} vbat_osc_init_trim_t;

/*!
 * @brief The enumerator of Capacitor Trim.
 */
typedef enum _vbat_osc_cap_trim
{
    kVBAT_OscCapTrimDefault    = 0x0U,
    kVBAT_OscCapTrim1us        = 0x1U,
    kVBAT_OscCapTrim2us        = 0x2U,
    kVBAT_OscCapTrim2andhalfus = 0x3U,
} vbat_osc_cap_trim_t;

/*!
 * @brief The enumerator of Delay Trim.
 */
typedef enum _vbat_osc_dly_trim
{
    kVBAT_OscDlyTrim0 = 0x0U, /*!< P current 9(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim1 = 0x1U, /*!< P current 13(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim3 = 0x3U, /*!< P current 4(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim4 = 0x4U, /*!< P current 9(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim5 = 0x5U, /*!< P current 13(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim6 = 0x6U, /*!< P current 4(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim7 = 0x7U, /*!< P current 9(nA) and N Current 2(nA). */
    kVBAT_OscDlyTrim8 = 0x8U, /*!< P current 13(nA) and N Current 2(nA). */
    kVBAT_OscDlyTrim9 = 0x9U, /*!< P current 4(nA) and N Current 2(nA). */
} vbat_osc_dly_trim_t;

/*!
 * @brief The enumerator of CAP2_TRIM.
 */
typedef enum _vbat_osc_cap2_trim
{
    kVBAT_OscCap2Trim0 = 0x0U,
    kVBAT_OscCap2Trim1 = 0x1U,
} vbat_osc_cap2_trim_t;

/*!
 * @brief The enumerator of Comparator Trim.
 */
typedef enum _vbat_osc_cmp_trim
{
    kVBAT_OscCmpTrim760mv = 0x0U,
    kVBAT_OscCmpTrim770mv = 0x1U,
    kVBAT_OscCmpTrim740mv = 0x3U,
} vbat_osc_cmp_trim_t;

/*!
 * @brief The enumerator of configures Crystal Oscillator mode..
 */
typedef enum _vbat_osc_mode_en
{
    kVBAT_OscNormalModeEnable   = 0x0U,
    kVBAT_OscStartupModeEnable  = 0x1U,
    kVBAT_OscLowpowerModeEnable = 0x3U,
} vbat_osc_mode_en_t;

/*!
 * @brief The structure of oscillator configuration.
 */
typedef struct _osc_32k_config
{
    vbat_osc_init_trim_t initTrim;
    vbat_osc_cap_trim_t capTrim;
    vbat_osc_dly_trim_t dlyTrim;
    vbat_osc_cap2_trim_t cap2Trim;
    vbat_osc_cmp_trim_t cmpTrim;

    vbat_osc_mode_en_t mode;
    vbat_osc_xtal_cap_t xtalCap;
    vbat_osc_extal_cap_t extalCap;
    vbat_osc_coarse_adjustment_value_t ampGain;

    osc32k_clk_gate_id_t id;
    bool updateTrim;
} osc_32k_config_t;

/*! @brief Source of PFD Clock Selection. */
typedef enum _pfd_clkout_selection_t
{
    kPFDOUT_UsbPllRef  = 0,
    kPFDOUT_PfdClkDiv4 = 1,
    kPFDOUT_PfdClkDiv2 = 2,
    kPFDOUT_PfdClk     = 3,
} pfd_clkout_selection_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Enable the clock for specific IP.
 * @param clk : Clock to be enabled.
 * @return  Nothing
 */
static inline void CLOCK_EnableClock(clock_ip_name_t clk)
{
    uint32_t reg_offset         = CLK_GATE_REG_OFFSET(clk);
    uint32_t bit_shift          = CLK_GATE_BIT_SHIFT(clk);
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0_SET)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    *pClkCtrl = (1UL << bit_shift);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/**
 * @brief Disable the clock for specific IP.
 * @param clk : Clock to be Disabled.
 * @return  Nothing
 */
static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
    uint32_t reg_offset         = CLK_GATE_REG_OFFSET(clk);
    uint32_t bit_shift          = CLK_GATE_BIT_SHIFT(clk);
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0_CLR)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    *pClkCtrl = (1UL << bit_shift);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/**
 * @brief   Configure the clock selection muxes.
 * @param   connection  : Clock to be configured.
 */
void CLOCK_AttachClk(clock_attach_id_t connection);

/**
 * @brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual
 * source value in the register and combine the offset to obtain an actual
 * attach id.
 * @param   connection  : Clock attach id to get.
 * @return  Clock source value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t connection);

/**
 * @brief   Set the clock select value.
 * This fuction set the peripheral clock select value.
 * @param   sel_name : Clock select.
 * @param   value    : value to be set.
 */
status_t CLOCK_SetClockSelect(clock_select_name_t sel_name, uint32_t value);

/**
 * @brief   Get the clock select value.
 * This fuction get the peripheral clock select value.
 * @param   sel_name  : Clock select.
 * @return  Clock source value.
 */
uint32_t CLOCK_GetClockSelect(clock_select_name_t sel_name);

/**
 * @brief   Setup peripheral clock dividers.
 * @param   div_name : Clock divider name
 * @param   value    : Value to be divided
 */
void CLOCK_SetClockDiv(clock_div_name_t div_name, uint32_t value);

/**
 * @brief   Get peripheral clock dividers.
 * @param   div_name    : Clock divider name
 * @return  peripheral clock dividers
 */
uint32_t CLOCK_GetClockDiv(clock_div_name_t div_name);

/**
 * @brief   Halt peripheral clock dividers.
 * @param   div_name    : Clock divider name
 */
void CLOCK_HaltClockDiv(clock_div_name_t div_name);

/**
 * @brief   Initialize the FROHF to given frequency (48,64,96,192).
 * This function turns on FIRC and select the given frequency as the source of
 * fro_hf
 * @param   iFreq   : Desired frequency.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq);

/**
 * @brief   Initialize the FRO12M.
 * This function turns on FRO12M.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFRO12MClocking(void);

/**
 * @brief   Initialize the FRO16K.
 * This function turns on FRO16K.
 * @param   clk_16k_enable_mask: 0-7
 *             0: disable, 1: disable
 *             bit0 is for clk_16k0
 *             bit1 is for clk_16k1
 *             bit2 is for clk_16k2
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFRO16KClocking(uint8_t clk_16k_enable_mask);

/**
 * @brief   Initialize the external osc clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq);

/**
 * @brief   Initialize the external reference clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtRefClocking(uint32_t iFreq);

/**
 * @brief   Initialize the XTAL32/EXTAL32 input clock to given frequency.
 * @param   id   : OSC 32 kHz output clock to specified modules, it should use osc32k_clk_gate_id_t value
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClocking(uint32_t id);

/**
 * @brief   Get default XTAL32/EXTAL32 clock configuration structure.
 * This function initializes the osc 32k configuration structure to a default value. The default
 * values are:
 *   config->initTrim = kVBAT_OscInitTrim500ms;
 *   config->capTrim  = kVBAT_OscCapTrimDefault;
 *   config->dlyTrim  = kVBAT_OscDlyTrim5;
 *   config->cap2Trim = kVBAT_OscCap2Trim0;
 *   config->cmpTrim  = kVBAT_OscCmpTrim760mv;
 *   config->mode     = kVBAT_OscNormalModeEnable;
 *   config->xtalCap  = kVBAT_OscXtal24pFCap;
 *   config->extalCap = kVBAT_OscExtal22pFCap;
 *   config->ampGain  = kVBAT_OscCoarseAdjustment05;
 *   config->id       = kCLOCK_Osc32kToVbat;
 * @param   config: Pointer to a configuration structure
 */
void CLOCK_GetDefaultOsc32KConfig(osc_32k_config_t *config);

/**
 * @brief   Initialize the OSC 32K with user-defined settings.
 * @param   config   : OSC 32K configuration structure
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClockingConfig(osc_32k_config_t config);

/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*! @brief  Return Frequency of core
 *  @return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*! @brief  Return Frequency of CTimer functional Clock
 *  @return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPI2C0 functional Clock
 *  @return Frequency of LPI2C0 functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPSPI functional Clock
 *  @return Frequency of LPSPI functional Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPUART functional Clock
 *  @return Frequency of LPUART functional Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id);

/* Get I3C Clk */
/*! @brief  Return Frequency of I3C Clock
 *  @return Frequency of I3C Clock
 */
uint32_t CLOCK_GetI3CFClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPTMR functional Clock
 *  @return Frequency of LPTMR functional Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void);

/*! @brief  Return Frequency of OSTIMER
 *  @return Frequency of OSTIMER Clock
 */
uint32_t CLOCK_GetOstimerClkFreq(void);

/*! @brief  Return Frequency of Adc Clock
 *  @return Frequency of Adc.
 */
uint32_t CLOCK_GetAdcClkFreq(uint32_t id);

/*! @brief  Return Frequency of CMP Function Clock
 *  @return Frequency of CMP Function.
 */
uint32_t CLOCK_GetCmpFClkFreq(void);

/*! @brief  Return Frequency of CMP Round Robin Clock
 *  @return Frequency of CMP Round Robin.
 */
uint32_t CLOCK_GetCmpRRClkFreq(uint32_t id);

/*! @brief  Return Frequency of Trace Clock
 *  @return Frequency of Trace.
 */
uint32_t CLOCK_GetTraceClkFreq(void);

/*! @brief  Return Frequency of CLKOUT Clock
 *  @return Frequency of CLKOUT.
 */
uint32_t CLOCK_GetClkoutClkFreq(void);

/*! @brief  Return Frequency of Systick Clock
 *  @return Frequency of Systick.
 */
uint32_t CLOCK_GetSystickClkFreq(void);

/*! brief  Return Frequency of WWDT0 Clock
 *  return Frequency of WWDT0.
 */
uint32_t CLOCK_GetWwdt0ClkFreq(void);

/*! brief  Return Frequency of WWDT1 Clock
 *  return Frequency of WWDT1.
 */
uint32_t CLOCK_GetWwdt1ClkFreq(void);

/*! @brief  Return Frequency of FlexCAN CLK
 *  @return Frequency of FlexCAN CLK.
 */
uint32_t CLOCK_GetFlexcanClkFreq(uint32_t id);

/*! @brief  Return Frequency of Flexspi CLK
 *  @return Frequency of Flexspi CLK.
 */
uint32_t CLOCK_GetFlexspiClkFreq(void);

/*! @brief  Return Frequency of TSI CLK
 *  @return Frequency of TSI CLK.
 */
uint32_t CLOCK_GetTsiClkFreq(void);

/*! @brief  Return Frequency of ENET MRR CLK
 *  @return Frequency of ENET MRR CLK.
 */
uint32_t CLOCK_GetEnetRmiiClkFreq(void);

/*! @brief  Return Frequency of ENET PTP REF CLK
 *  @return Frequency of ENET PTP REF CLK.
 */
uint32_t CLOCK_GetEnetPtpRefClkFreq(void);

/*! @brief  Return Frequency of TENBASET_PHY CLK
 *  @return Frequency of TENBASET_PHY CLK.
 */
uint32_t CLOCK_GetTenbaset_PhyClkFreq(void);

/*! @brief  Return Frequency of ESPI CLK
 *  @return Frequency of ESPI CLK.
 */
uint32_t CLOCK_GetEspiClkFreq(void);

/*! @brief  Return Frequency of FLEXIO FCLK
 *  @return Frequency of FLEXIO FCLK.
 */
uint32_t CLOCK_GetFlexioClkFreq(void);

/**
 * @brief   Initialize the ENET TX CLK to given frequency.
 * @param   iFreq   : Desired frequency
 * @return  Nothing
 */
void CLOCK_SetupEnetTxClk(uint32_t iFreq);

/**
 * @brief   Return Frequency of ENET TX CLK
 * @return  Frequency of ENET TX CLK
 */
uint32_t CLOCK_GetEnetTxClkFreq(void);

/*!
 * @brief Enable USB HS PHY PLL clock.
 *
 * This function enables the USB HS PHY PLL clock.
 *
 * @param clockSourceFreq Frequency value.
 * @return true if success, false if failure.
 */
bool CLOCK_EnableUsbhsPhyPllClock(uint32_t clockSourceFreq);

/*!
 * @brief Disable USB HS PHY PLL clock.
 *
 * This function disables the USB HS PHY PLL clock.
 */
void CLOCK_DisableUsbhsPhyPllClock(void);

#ifdef USBHS1
/*!
 * @brief Enable USB HS clock.
 *
 * This function enables the USB HS clock.
 *
 * @return true if success, false if failure.
 */
bool CLOCK_EnableUsbhsClock(void);
#endif

/*!
 * @brief Enable USB HS PHY PFD clock.
 *
 * This function enables the USB HS PHY PFD clock.
 *
 * @param pfdDiv PFD fractional divider value.
 * @param pfdClkSel PFD clock output selection.
 * @return true if success, false if failure.
 */
bool CLOCK_EnableUsbhsPhyPfdClock(uint32_t pfdDiv, pfd_clkout_selection_t pfdClkSel);

/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config);

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the
 * error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode);

/*!
 * @brief   Set the additional number of wait-states added to account for the
 * ratio of system clock period to flash access time during full speed power
 * mode.
 * @param   system_freq_hz  : Input frequency
 * @param   mode            : Active run mode (voltage level).
 * @return  success or fail status
 */
status_t CLOCK_SetFLASHAccessCyclesForFreq(uint32_t system_freq_hz, run_mode_t mode);

/*!
 * @brief Sets the PLL1 monitor mode.
 *
 * This function sets the PLL1 monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetPll1MonitorMode(scg_pll1_monitor_mode_t mode);

/*! @brief    Return  PLL1 input clock rate
 *  @return    PLL1 input clock rate
 */
uint32_t CLOCK_GetPLL1InClockRate(void);

/*! @brief  Check if PLL1 is locked or not
 *  @return true if the PLL1 is locked, false if not locked
 */
__STATIC_INLINE bool CLOCK_IsPLL1Locked(void)
{
    return (bool)((SCG0->SPLLCSR & SCG_SPLLCSR_SPLL_LOCK_MASK) != 0UL);
}

/*! @brief PLL configuration structure flags for 'flags' field
 * These flags control how the PLL configuration function sets up the PLL setup structure.<br>
 *
 * When the PLL_CONFIGFLAG_FORCENOFRACT flag is selected, the PLL hardware for the
 * automatic bandwidth selection, Spread Spectrum (SS) support, and fractional M-divider
 * are not used.<br>
 */
#define PLL_CONFIGFLAG_FORCENOFRACT (1U << 2U)
/*!< Force non-fractional output mode, PLL output will not use the fractional, automatic bandwidth, or SS hardware */

/*!
 * @brief PLL clock source.
 */
typedef enum _pll_clk_src
{
    kPll_ClkSrcSysOsc = (0 << 25), /*!< System OSC. */
    kPll_ClkSrcFirc   = (1 << 25), /*!< Fast IRC.   */
    kPll_ClkSrcSirc   = (3 << 25), /*!< Slow IRC. */
} pll_clk_src_t;

/*! @brief PLL Spread Spectrum (SS) Programmable modulation frequency
 * See (MF) field in the PLL0SSCG1 register in the UM.
 */
typedef enum _ss_progmodfm
{
    kSS_MF_512 = (0 << 2), /*!< Nss =  512 (fm ~= 3.9  - 7.8   kHz) */
    kSS_MF_384 = (1 << 2), /*!< Nss ~= 384 (fm ~= 5.2  - 10.4  kHz) */
    kSS_MF_256 = (2 << 2), /*!< Nss =  256 (fm ~= 7.8  - 15.6  kHz) */
    kSS_MF_128 = (3 << 2), /*!< Nss =  128 (fm ~= 15.6 - 31.3  kHz) */
    kSS_MF_64  = (4 << 2), /*!< Nss =  64  (fm ~= 32.3 - 64.5  kHz) */
    kSS_MF_32  = (5 << 2), /*!< Nss =  32  (fm ~= 62.5 - 125   kHz) */
    kSS_MF_24  = (6 << 2), /*!< Nss ~= 24  (fm ~= 83.3 - 166.6 kHz) */
    kSS_MF_16  = (7 << 2)  /*!< Nss =  16  (fm ~= 125  - 250   kHz) */
} ss_progmodfm_t;

/*! @brief PLL Spread Spectrum (SS) Programmable frequency modulation depth
 * See (MR) field in the PLL0SSCG1 register in the UM.
 */
typedef enum _ss_progmoddp
{
    kSS_MR_K0   = (0 << 5), /*!< k =  0 (no spread spectrum) */
    kSS_MR_K1   = (1 << 5), /*!< k ~= 1                      */
    kSS_MR_K1_5 = (2 << 5), /*!< k ~= 1.5                    */
    kSS_MR_K2   = (3 << 5), /*!< k ~= 2                      */
    kSS_MR_K3   = (4 << 5), /*!< k ~= 3                      */
    kSS_MR_K4   = (5 << 5), /*!< k ~= 4                      */
    kSS_MR_K6   = (6 << 5), /*!< k ~= 6                      */
    kSS_MR_K8   = (7 << 5)  /*!< k ~= 8                      */
} ss_progmoddp_t;

/*! @brief PLL Spread Spectrum (SS) Modulation waveform control
 * See (MC) field in the PLL0SSCG1 register in the UM.<br>
 * Compensation for low pass filtering of the PLL to get a triangular
 * modulation at the output of the PLL, giving a flat frequency spectrum.
 */
typedef enum _ss_modwvctrl
{
    kSS_MC_NOC  = (0 << 8), /*!< no compensation */
    kSS_MC_RECC = (2 << 8), /*!< recommended setting */
    kSS_MC_MAXC = (3 << 8), /*!< max. compensation */
} ss_modwvctrl_t;

/*! @brief PLL configuration structure
 *
 * This structure can be used to configure the settings for a PLL
 * setup structure. Fill in the desired configuration for the PLL
 * and call the PLL setup function to fill in a PLL setup structure.
 */
typedef struct _pll_config
{
    uint32_t desiredRate; /*!< Desired PLL rate in Hz */
    uint32_t inputSource; /*!< PLL input source */
    uint32_t flags;       /*!< PLL configuration flags, Or'ed value of PLL_CONFIGFLAG_* definitions */
    ss_progmodfm_t ss_mf; /*!< SS Programmable modulation frequency, only applicable when not using
                             PLL_CONFIGFLAG_FORCENOFRACT flag */
    ss_progmoddp_t ss_mr; /*!< SS Programmable frequency modulation depth, only applicable when not using
                             PLL_CONFIGFLAG_FORCENOFRACT flag */
    ss_modwvctrl_t
        ss_mc;     /*!< SS Modulation waveform control, only applicable when not using PLL_CONFIGFLAG_FORCENOFRACT flag
                    */
    bool mfDither; /*!< false for fixed modulation frequency or true for dithering, only applicable when not using
                      PLL_CONFIGFLAG_FORCENOFRACT flag */

} pll_config_t;

/*! @brief PLL0 setup structure
 * This structure can be used to pre-build a PLL setup configuration
 * at run-time and quickly set the PLL to the configuration. It can be
 * populated with the PLL setup function. If powering up or waiting
 * for PLL lock, the PLL input clock source should be configured prior
 * to PLL setup.
 */
typedef struct _pll_setup
{
    uint32_t pllctrl;    /*!< PLL Control register APLLCTRL */
    uint32_t pllndiv;    /*!< PLL N Divider register APLLNDIV */
    uint32_t pllpdiv;    /*!< PLL P Divider register APLLPDIV */
    uint32_t pllmdiv;    /*!< PLL M Divider register APLLMDIV */
    uint32_t pllsscg[2]; /*!< PLL Spread Spectrum Control registers APLLSSCG*/
    uint32_t pllRate;    /*!< Actual PLL rate */
} pll_setup_t;

/*! @brief PLL status definitions
 */
typedef enum _pll_error
{
    kStatus_PLL_Success         = MAKE_STATUS(kStatusGroup_Generic, 0), /*!< PLL operation was successful */
    kStatus_PLL_OutputTooLow    = MAKE_STATUS(kStatusGroup_Generic, 1), /*!< PLL output rate request was too low */
    kStatus_PLL_OutputTooHigh   = MAKE_STATUS(kStatusGroup_Generic, 2), /*!< PLL output rate request was too high */
    kStatus_PLL_OutputError     = MAKE_STATUS(kStatusGroup_Generic, 3), /*!< PLL output rate error */
    kStatus_PLL_InputTooLow     = MAKE_STATUS(kStatusGroup_Generic, 4), /*!< PLL input rate is too low */
    kStatus_PLL_InputTooHigh    = MAKE_STATUS(kStatusGroup_Generic, 5), /*!< PLL input rate is too high */
    kStatus_PLL_OutsideIntLimit = MAKE_STATUS(kStatusGroup_Generic, 6), /*!< Requested output rate isn't possible */
    kStatus_PLL_CCOTooLow       = MAKE_STATUS(kStatusGroup_Generic, 7), /*!< Requested CCO rate isn't possible */
    kStatus_PLL_CCOTooHigh      = MAKE_STATUS(kStatusGroup_Generic, 8), /*!< Requested CCO rate isn't possible */
    kStatus_PLL_Timeout         = MAKE_STATUS(kStatusGroup_Generic, 9)  /*!< Generic status for timeout */
} pll_error_t;

/*! @brief    Return PLL0 output clock rate from setup structure
 *  @param    pSetup : Pointer to a PLL setup structure
 *  @return   System PLL output clock rate the setup structure will generate
 */
uint32_t CLOCK_GetPLLOutFromSetup(pll_setup_t *pSetup);

/*! @brief    Set PLL output based on the passed PLL setup data
 *  @param    pControl    : Pointer to populated PLL control structure to generate setup with
 *  @param    pSetup      : Pointer to PLL setup structure to be filled
 *  @return   PLL_ERROR_SUCCESS on success, or PLL setup error code
 *  @note Actual frequency for setup may vary from the desired frequency based on the
 *  accuracy of input clocks, rounding, non-fractional PLL mode, etc.
 */
pll_error_t CLOCK_SetupPLLData(pll_config_t *pControl, pll_setup_t *pSetup);

/**
 * @brief Set PLL output from PLL setup structure (precise frequency)
 * @param pSetup  : Pointer to populated PLL setup structure
 * @return    kStatus_PLL_Success on success, or PLL setup error code
 * @note  This function will power off the PLL, setup the PLL with the
 * new setup data, and then optionally powerup the PLL, wait for PLL lock,
 * and adjust system voltages to the new PLL rate. The function will not
 * alter any source clocks (ie, main systen clock) that may use the PLL,
 * so these should be setup prior to and after exiting the function.
 */
pll_error_t CLOCK_SetPLL1Freq(const pll_setup_t *pSetup);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
