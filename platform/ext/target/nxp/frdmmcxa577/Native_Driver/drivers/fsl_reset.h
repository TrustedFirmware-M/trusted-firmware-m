/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_RESET_H_
#define _FSL_RESET_H_

#include "fsl_common.h"

/*!
 * @addtogroup reset
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief reset driver version 2.0.0 */
#define FSL_RESET_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief Enumeration for peripheral reset control bits
 *
 * Defines the enumeration for peripheral reset control bits in
 * PRESETCTRL/ASYNCPRESETCTRL registers
 */
typedef enum _SYSCON_RSTn
{
    kINPUTMUX0_RST_SHIFT_RSTn  = ((0U << 8U) | (0U)),  /*!< INPUTMUX0   reset control */
    kFREQME_RST_SHIFT_RSTn     = ((0U << 8U) | (1U)),  /*!< FREQME      reset control */
    kCTIMER0_RST_SHIFT_RSTn    = ((0U << 8U) | (2U)),  /*!< CTIMER0     reset control */
    kCTIMER1_RST_SHIFT_RSTn    = ((0U << 8U) | (3U)),  /*!< CTIMER1     reset control */
    kCTIMER2_RST_SHIFT_RSTn    = ((0U << 8U) | (4U)),  /*!< CTIMER2     reset control */
    kCTIMER3_RST_SHIFT_RSTn    = ((0U << 8U) | (5U)),  /*!< CTIMER3     reset control */
    kCTIMER4_RST_SHIFT_RSTn    = ((0U << 8U) | (6U)),  /*!< CTIMER4     reset control */
    kUTICK0_RST_SHIFT_RSTn     = ((0U << 8U) | (7U)),  /*!< UTICK0      reset control */
    kDMA0_RST_SHIFT_RSTn       = ((0U << 8U) | (10U)), /*!< DMA0        reset control */
    kDMA1_RST_SHIFT_RSTn       = ((0U << 8U) | (11U)), /*!< DMA1        reset control */
    kAOI0_RST_SHIFT_RSTn       = ((0U << 8U) | (12U)), /*!< AOI0        reset control */
    kCRC0_RST_SHIFT_RSTn       = ((0U << 8U) | (14U)), /*!< CRC0        reset control */
    kEIM0_RST_SHIFT_RSTn       = ((0U << 8U) | (15U)), /*!< EIM0        reset control */
    kERM0_RST_SHIFT_RSTn       = ((0U << 8U) | (16U)), /*!< ERM0        reset control */
    kFLEXIO0_RST_SHIFT_RSTn    = ((0U << 8U) | (17U)), /*!< FLEXIO0     reset control */
    kLPI2C0_RST_SHIFT_RSTn     = ((0U << 8U) | (19U)), /*!< LPI2C0      reset control */
    kLPI2C1_RST_SHIFT_RSTn     = ((0U << 8U) | (20U)), /*!< LPI2C1      reset control */
    kLPI2C2_RST_SHIFT_RSTn     = ((0U << 8U) | (21U)), /*!< LPI2C2      reset control */
    kLPI2C3_RST_SHIFT_RSTn     = ((0U << 8U) | (22U)), /*!< LPI2C3      reset control */
    kLPI2C4_RST_SHIFT_RSTn     = ((0U << 8U) | (23U)), /*!< LPI2C4      reset control */
    kLPUART0_RST_SHIFT_RSTn    = ((0U << 8U) | (25U)), /*!< LPUART0     reset control */
    kLPUART1_RST_SHIFT_RSTn    = ((0U << 8U) | (26U)), /*!< LPUART1     reset control */
    kLPUART2_RST_SHIFT_RSTn    = ((0U << 8U) | (27U)), /*!< LPUART2     reset control */
    kLPUART3_RST_SHIFT_RSTn    = ((0U << 8U) | (28U)), /*!< LPUART3     reset control */
    kLPUART4_RST_SHIFT_RSTn    = ((0U << 8U) | (29U)), /*!< LPUART4     reset control */
    kLPUART5_RST_SHIFT_RSTn    = ((0U << 8U) | (30U)), /*!< LPUART5     reset control */
    kOSTIMER0_RST_SHIFT_RSTn   = ((0U << 8U) | (31U)), /*!< OSTIMER0    reset control */
    kLPSPI0_RST_SHIFT_RSTn     = ((1U << 8U) | (4U)),  /*!< LPSPI0      reset control */
    kLPSPI1_RST_SHIFT_RSTn     = ((1U << 8U) | (5U)),  /*!< LPSPI1      reset control */
    kLPSPI2_RST_SHIFT_RSTn     = ((1U << 8U) | (6U)),  /*!< LPSPI2      reset control */
    kLPSPI3_RST_SHIFT_RSTn     = ((1U << 8U) | (7U)),  /*!< LPSPI3      reset control */
    kLPSPI4_RST_SHIFT_RSTn     = ((1U << 8U) | (8U)),  /*!< LPSPI4      reset control */
    kLPSPI5_RST_SHIFT_RSTn     = ((1U << 8U) | (9U)),  /*!< LPSPI5      reset control */
    kPORT0_RST_SHIFT_RSTn      = ((1U << 8U) | (10U)), /*!< PORT0       reset control */
    kPORT1_RST_SHIFT_RSTn      = ((1U << 8U) | (11U)), /*!< PORT1       reset control */
    kPORT2_RST_SHIFT_RSTn      = ((1U << 8U) | (12U)), /*!< PORT2       reset control */
    kPORT3_RST_SHIFT_RSTn      = ((1U << 8U) | (13U)), /*!< PORT3       reset control */
    kPORT4_RST_SHIFT_RSTn      = ((1U << 8U) | (14U)), /*!< PORT4       reset control */
    kADC0_RST_SHIFT_RSTn       = ((1U << 8U) | (16U)), /*!< ADC0        reset control */
    kADC1_RST_SHIFT_RSTn       = ((1U << 8U) | (17U)), /*!< ADC1        reset control */
    kDAC0_RST_SHIFT_RSTn       = ((1U << 8U) | (23U)), /*!< DAC0        reset control */
    kDAC1_RST_SHIFT_RSTn       = ((1U << 8U) | (24U)), /*!< DAC1        reset control */
    kVREF0_RST_SHIFT_RSTn      = ((1U << 8U) | (29U)), /*!< VREF0       reset control */
    kI3C0_RST_SHIFT_RSTn       = ((2U << 8U) | (0U)),  /*!< I3C0        reset control */
    kI3C1_RST_SHIFT_RSTn       = ((2U << 8U) | (1U)),  /*!< I3C1        reset control */
    kI3C2_RST_SHIFT_RSTn       = ((2U << 8U) | (2U)),  /*!< I3C2        reset control */
    kI3C3_RST_SHIFT_RSTn       = ((2U << 8U) | (3U)),  /*!< I3C3        reset control */
    kFLEXCAN0_RST_SHIFT_RSTn   = ((2U << 8U) | (4U)),  /*!< FLEXCAN0    reset control */
    kFLEXCAN1_RST_SHIFT_RSTn   = ((2U << 8U) | (5U)),  /*!< FLEXCAN1    reset control */
    kENET0_RST_SHIFT_RSTn      = ((2U << 8U) | (10U)), /*!< ENET0       reset control */
    kT1S0_RST_SHIFT_RSTn       = ((2U << 8U) | (11U)), /*!< T1S0        reset control */
    kFLEXSPI0_RST_SHIFT_RSTn   = ((2U << 8U) | (12U)), /*!< FLEXSPI0    reset control */
    kSPIFILTER0_RST_SHIFT_RSTn = ((2U << 8U) | (13U)), /*!< SPIFILTER0  reset control */
    kESPI0_RST_SHIFT_RSTn      = ((2U << 8U) | (14U)), /*!< ESPI0       reset control */
    kUSB1_RST_SHIFT_RSTn       = ((2U << 8U) | (18U)), /*!< USB1        reset control */
    kUSB1_PHY_RST_SHIFT_RSTn   = ((2U << 8U) | (19U)), /*!< USB1_PHY    reset control */
    kEWM0_RST_SHIFT_RSTn       = ((2U << 8U) | (20U)), /*!< EWM0        reset control */
    kGPIO0_RST_SHIFT_RSTn      = ((3U << 8U) | (20U)), /*!< GPIO0       reset control */
    kGPIO1_RST_SHIFT_RSTn      = ((3U << 8U) | (21U)), /*!< GPIO1       reset control */
    kGPIO2_RST_SHIFT_RSTn      = ((3U << 8U) | (22U)), /*!< GPIO2       reset control */
    kGPIO3_RST_SHIFT_RSTn      = ((3U << 8U) | (23U)), /*!< GPIO3       reset control */
    kGPIO4_RST_SHIFT_RSTn      = ((3U << 8U) | (24U)), /*!< GPIO4       reset control */
    kSMART_DMA_RST_SHIFT_RSTn  = ((3U << 8U) | (29U)), /*!< SMARTDMA0   reset control */
    kGLIKEY0_RST_SHIFT_RSTn    = ((4U << 8U) | (17U)), /*!< GLIKEY0     reset control */
    kPKC0_RST_SHIFT_RSTn       = ((4U << 8U) | (19U)), /*!< PKC0        reset control */
    kTRNG0_RST_SHIFT_RSTn      = ((4U << 8U) | (21U)), /*!< TRNG0       reset control */
    kDGDET0_RST_SHIFT_RSTn     = ((4U << 8U) | (23U)), /*!< DGDET0      reset control */
    kATX0_RST_SHIFT_RSTn       = ((4U << 8U) | (29U)), /*!< ATX0        reset control */
    NotAvail_RSTn              = (0xFFFFU),            /*!< No        reset control */
} SYSCON_RSTn_t;

/** Array initializers with peripheral reset bits **/
/*! @brief Reset bits for ADC peripheral */
#define ADC_RSTS   {kADC0_RST_SHIFT_RSTn, kADC1_RST_SHIFT_RSTn}
#define ADC_RSTS_N ADC_RSTS

/*! @brief Reset bits for AOI peripheral */
#define AOI_RSTS   {kAOI0_RST_SHIFT_RSTn}
#define AOI_RSTS_N AOI_RSTS

/*! @brief Reset bits for ATX peripheral */
#define ATX_RSTS   {kATX0_RST_SHIFT_RSTn}
#define ATX_RSTS_N ATX_RSTS

/*! @brief Reset bits for CRC peripheral */
#define CRC_RSTS   {kCRC0_RST_SHIFT_RSTn}
#define CRC_RSTS_N CRC_RSTS

/*! @brief Reset bits for CTIMER peripheral */
#define CTIMER_RSTS                                                                                      \
    {kCTIMER0_RST_SHIFT_RSTn, kCTIMER1_RST_SHIFT_RSTn, kCTIMER2_RST_SHIFT_RSTn, kCTIMER3_RST_SHIFT_RSTn, \
     kCTIMER4_RST_SHIFT_RSTn}
#define CTIMER_RSTS_N CTIMER_RSTS

/*! @brief Reset bits for DAC peripheral */
#define DAC_RSTS   {kDAC0_RST_SHIFT_RSTn, kDAC1_RST_SHIFT_RSTn}
#define DAC_RSTS_N DAC_RSTS

/*! @brief Reset bits for DGDET peripheral */
#define DGDET_RSTS   {kDGDET0_RST_SHIFT_RSTn}
#define DGDET_RSTS_N DGDET_RSTS

/*! @brief Reset bits for DMA peripheral */
#define DMA_RSTS   {kDMA0_RST_SHIFT_RSTn, kDMA1_RST_SHIFT_RSTn}
#define DMA_RSTS_N DMA_RSTS

/*! @brief Reset bits for EIM peripheral */
#define EIM_RSTS   {kEIM0_RST_SHIFT_RSTn}
#define EIM_RSTS_N EIM_RSTS

/*! @brief Reset bits for ENET peripheral */
#define ENET_RSTS   {kENET0_RST_SHIFT_RSTn}
#define ENET_RSTS_N ENET_RSTS

/*! @brief Reset bits for ERM peripheral */
#define ERM_RSTS   {kERM0_RST_SHIFT_RSTn}
#define ERM_RSTS_N ERM_RSTS

/*! @brief Reset bits for ESPI peripheral */
#define ESPI_RSTS   {kESPI0_RST_SHIFT_RSTn}
#define ESPI_RSTS_N ESPI_RSTS

/*! @brief Reset bits for EWM peripheral */
#define EWM_RSTS   {kEWM0_RST_SHIFT_RSTn}
#define EWM_RSTS_N EWM_RSTS

/*! @brief Reset bits for FLEXCAN peripheral */
#define FLEXCAN_RSTS   {kFLEXCAN0_RST_SHIFT_RSTn, kFLEXCAN1_RST_SHIFT_RSTn}
#define FLEXCAN_RSTS_N FLEXCAN_RSTS

/*! @brief Reset bits for FLEXIO peripheral */
#define FLEXIO_RSTS   {kFLEXIO0_RST_SHIFT_RSTn}
#define FLEXIO_RSTS_N FLEXIO_RSTS

/*! @brief Reset bits for FLEXSPI peripheral */
#define FLEXSPI_RSTS   {kFLEXSPI0_RST_SHIFT_RSTn}
#define FLEXSPI_RSTS_N FLEXSPI_RSTS

/*! @brief Reset bits for FREQME peripheral */
#define FREQME_RSTS   {kFREQME_RST_SHIFT_RSTn}
#define FREQME_RSTS_N FREQME_RSTS

/*! @brief Reset bits for GLIKEY peripheral */
#define GLIKEY_RSTS   {kGLIKEY0_RST_SHIFT_RSTn}
#define GLIKEY_RSTS_N GLIKEY_RSTS

/*! @brief Reset bits for GPIO peripheral */
#define GPIO_RSTS                                                         \
    {kGPIO0_RST_SHIFT_RSTn, kGPIO1_RST_SHIFT_RSTn, kGPIO2_RST_SHIFT_RSTn, \
     kGPIO3_RST_SHIFT_RSTn, kGPIO4_RST_SHIFT_RSTn, NotAvail_RSTn}
#define GPIO_RSTS_N GPIO_RSTS

/*! @brief Reset bits for I3C peripheral */
#define I3C_RSTS   {kI3C0_RST_SHIFT_RSTn, kI3C1_RST_SHIFT_RSTn, kI3C2_RST_SHIFT_RSTn, kI3C3_RST_SHIFT_RSTn}
#define I3C_RSTS_N I3C_RSTS

/*! @brief Reset bits for INPUTMUX peripheral */
#define INPUTMUX_RSTS   {kINPUTMUX0_RST_SHIFT_RSTn}
#define INPUTMUX_RSTS_N INPUTMUX_RSTS

/*! @brief Reset bits for LPI2C peripheral */
#define LPI2C_RSTS                                                                                   \
    {kLPI2C0_RST_SHIFT_RSTn, kLPI2C1_RST_SHIFT_RSTn, kLPI2C2_RST_SHIFT_RSTn, kLPI2C3_RST_SHIFT_RSTn, \
     kLPI2C4_RST_SHIFT_RSTn}
#define LPI2C_RSTS_N LPI2C_RSTS

/*! @brief Reset bits for LPSPI peripheral */
#define LPSPI_RSTS                                                           \
    {kLPSPI0_RST_SHIFT_RSTn, kLPSPI1_RST_SHIFT_RSTn, kLPSPI2_RST_SHIFT_RSTn, \
     kLPSPI3_RST_SHIFT_RSTn, kLPSPI4_RST_SHIFT_RSTn, kLPSPI5_RST_SHIFT_RSTn}
#define LPSPI_RSTS_N LPSPI_RSTS

/*! @brief Reset bits for LPUART peripheral */
#define LPUART_RSTS                                                             \
    {kLPUART0_RST_SHIFT_RSTn, kLPUART1_RST_SHIFT_RSTn, kLPUART2_RST_SHIFT_RSTn, \
     kLPUART3_RST_SHIFT_RSTn, kLPUART4_RST_SHIFT_RSTn, kLPUART5_RST_SHIFT_RSTn}
#define LPUART_RSTS_N LPUART_RSTS

/*! @brief Reset bits for OSTIMER peripheral */
#define OSTIMER_RSTS   {kOSTIMER0_RST_SHIFT_RSTn}
#define OSTIMER_RSTS_N OSTIMER_RSTS

/*! @brief Reset bits for PKC peripheral */
#define PKC_RSTS   {kPKC0_RST_SHIFT_RSTn}
#define PKC_RSTS_N PKC_RSTS

/*! @brief Reset bits for PORT peripheral */
#define PORT_RSTS                                                         \
    {kPORT0_RST_SHIFT_RSTn, kPORT1_RST_SHIFT_RSTn, kPORT2_RST_SHIFT_RSTn, \
     kPORT3_RST_SHIFT_RSTn, kPORT4_RST_SHIFT_RSTn, NotAvail_RSTn}
#define PORT_RSTS_N PORT_RSTS

/*! @brief Reset bits for SMARTDMA peripheral */
#define SMARTDMA_RSTS   {kSMARTDMA0_RST_SHIFT_RSTn}
#define SMARTDMA_RSTS_N SMARTDMA_RSTS

/*! @brief Reset bits for SPIFILTER peripheral */
#define SPIFILTER_RSTS   {kSPIFILTER0_RST_SHIFT_RSTn}
#define SPIFILTER_RSTS_N SPIFILTER_RSTS

/*! @brief Reset bits for T1S peripheral */
#define T1S_RSTS           {kT1S0_RST_SHIFT_RSTn}
#define T1S_RSTS_N         T1S_RSTS
#define TENBASET_PHY_RST   T1S_RSTS
#define TENBASET_PHY_RST_N T1S_RSTS

/*! @brief Reset bits for TRNG peripheral */
#define TRNG_RSTS   {kTRNG0_RST_SHIFT_RSTn}
#define TRNG_RSTS_N TRNG_RSTS

/*! @brief Reset bits for USB peripheral */
#define USB_RSTS   {kUSB1_RST_SHIFT_RSTn}
#define USB_RSTS_N USB_RSTS

/*! @brief Reset bits for USB PHY peripheral */
#define USB_PHY_RSTS   {kUSB1_PHY_RST_SHIFT_RSTn}
#define USB_PHY_RSTS_N USB_PHY_RSTS

/*! @brief Reset bits for UTICK peripheral */
#define UTICK_RSTS   {kUTICK0_RST_SHIFT_RSTn}
#define UTICK_RSTS_N UTICK_RSTS

/*! @brief Reset bits for VREF peripheral */
#define VREF_RSTS   {kVREF0_RST_SHIFT_RSTn}
#define VREF_RSTS_N VREF_RSTS

typedef SYSCON_RSTn_t reset_ip_name_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * @param peripheral Assert reset to this peripheral. The enum argument contains
 * encoding of reset register and reset bit position in the reset register.
 */
status_t RESET_SetPeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * @param peripheral Clear reset to this peripheral. The enum argument contains
 * encoding of reset register and reset bit position in the reset register.
 */
status_t RESET_ClearPeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * @param peripheral Peripheral to reset. The enum argument contains encoding of
 * reset register and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Release peripheral module.
 *
 * Release peripheral module.
 *
 * @param peripheral Peripheral to release. The enum argument contains encoding
 * of reset register and reset bit position in the reset register.
 */
static inline void RESET_ReleasePeripheralReset(reset_ip_name_t peripheral)
{
    RESET_SetPeripheralReset(peripheral);
}

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_RESET_H_ */
