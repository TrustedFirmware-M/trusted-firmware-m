/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_gpio.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "FRDM-MCXA577"
/*! @brief The manufacturer name */
#define MANUFACTURER_NAME "NXP"

/*! @brief The UART to use for debug messages. */
#define BOARD_DEBUG_UART_TYPE     kSerialPort_Uart
#define BOARD_DEBUG_UART_CLK_FREQ 12000000U

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE 115200U
#endif

#define BOARD_DEBUG_UART_BASEADDR   (uint32_t) LPUART1
#define BOARD_DEBUG_UART_INSTANCE   1U
#define BOARD_DEBUG_UART_CLK_ATTACH kFRO_LF_DIV_to_LPUART1
#define BOARD_DEBUG_UART_RST        kLPUART1_RST_SHIFT_RSTn
#define BOARD_DEBUG_UART_CLKDIV     kCLOCK_DivLPUART1
#define BOARD_DEBUG_UART_CLKDIV_VAL (1U)
#define BOARD_UART_IRQ_HANDLER      LPUART1_IRQHandler
#define BOARD_UART_IRQ              LPUART1_IRQn

/*! @brief Indexes of the TSI channels for on-board electrodes */
#ifndef BOARD_TSI_ELECTRODE_1
#define BOARD_TSI_ELECTRODE_1 0
#endif
#ifndef BOARD_TSI_ELECTRODE_2
#define BOARD_TSI_ELECTRODE_2 2
#endif

#define BOARD_TSI_MUTUAL_TX_ELECTRODE_1 1U
#define BOARD_TSI_MUTUAL_RX_ELECTRODE_1 44 + 8U

/*! @brief GPIO for LED. */
#ifndef BOARD_LED_RED_GPIO
#define BOARD_LED_RED_GPIO GPIO2
#endif
#ifndef BOARD_LED_RED_GPIO_PIN
#define BOARD_LED_RED_GPIO_PIN 14U
#endif

#ifndef BOARD_LED_GREEN_GPIO
#define BOARD_LED_GREEN_GPIO GPIO2
#endif
#ifndef BOARD_LED_GREEN_GPIO_PIN
#define BOARD_LED_GREEN_GPIO_PIN 22U
#endif

#ifndef BOARD_LED_BLUE_GPIO
#define BOARD_LED_BLUE_GPIO GPIO2
#endif
#ifndef BOARD_LED_BLUE_GPIO_PIN
#define BOARD_LED_BLUE_GPIO_PIN 23U
#endif

/*! @brief GPIO for SW. */
#ifndef BOARD_SW2_GPIO
#define BOARD_SW2_GPIO GPIO3
#endif
#ifndef BOARD_SW2_GPIO_PIN
#define BOARD_SW2_GPIO_PIN 17U
#endif
#define BOARD_SW2_NAME        "SW2"
#define BOARD_SW2_IRQ         GPIO3_IRQn
#define BOARD_SW2_IRQ_HANDLER GPIO3_IRQHandler

#ifndef BOARD_SW3_GPIO
#define BOARD_SW3_GPIO GPIO0
#endif
#ifndef BOARD_SW3_GPIO_PIN
#define BOARD_SW3_GPIO_PIN 6U
#endif
#define BOARD_SW3_NAME        "SW3"
#define BOARD_SW3_IRQ         GPIO0_IRQn
#define BOARD_SW3_IRQ_HANDLER GPIO0_IRQHandler

/* USB PHY condfiguration */
#define BOARD_USB_PHY_D_CAL     (0x04U)
#define BOARD_USB_PHY_TXCAL45DP (0x07U)
#define BOARD_USB_PHY_TXCAL45DM (0x07U)

/* Board LED color mapping */
#define LOGIC_LED_ON  0U
#define LOGIC_LED_OFF 1U

#define LED_RED_INIT(output)                                           \
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, output); \
    BOARD_LED_RED_GPIO->PDDR |= (1U << BOARD_LED_RED_GPIO_PIN)               /*!< Enable target LED_RED */
#define LED_RED_ON() \
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, LOGIC_LED_ON)  /*!< Turn on target LED_RED */
#define LED_RED_OFF() \
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, LOGIC_LED_OFF) /*!< Turn off target LED_RED */
#define LED_RED_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN)        /*!< Toggle on target LED_RED */

#define LED_GREEN_INIT(output)                                             \
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, output); \
    BOARD_LED_GREEN_GPIO->PDDR |= (1U << BOARD_LED_GREEN_GPIO_PIN)             /*!< Enable target LED_GREEN */
#define LED_GREEN_ON() \
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, LOGIC_LED_ON)  /*!< Turn on target LED_GREEN */
#define LED_GREEN_OFF() \
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, LOGIC_LED_OFF) /*!< Turn off target LED_GREEN */
#define LED_GREEN_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN)      /*!< Toggle on target LED_GREEN */

#define LED_BLUE_INIT(output)                                            \
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, output); \
    BOARD_LED_BLUE_GPIO->PDDR |= (1U << BOARD_LED_BLUE_GPIO_PIN)              /*!< Enable target LED_BLUE */
#define LED_BLUE_ON() \
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, LOGIC_LED_ON)  /*!< Turn on target LED_BLUE */
#define LED_BLUE_OFF() \
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, LOGIC_LED_OFF) /*!< Turn off target LED_BLUE */
#define LED_BLUE_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN)       /*!< Toggle on target LED_BLUE */

/*!
 * @brief The Ethernet PHY used by network examples.
 * Set to 0 to use external PHY over RMII (default).
 * Set to 1 to use internal digital 10BASE-T1S PHY.
 */
/* Below comment is for test script to easily define which PHY to be used, please don't delete. */
/* @TEST_ANCHOR */
#ifndef BOARD_NETWORK_USE_TENBASET_PHY
#define BOARD_NETWORK_USE_TENBASET_PHY (0U)
#endif

/*! @brief Memory ranges not usable by the ENET DMA. */
#ifndef BOARD_ENET_NON_DMA_MEMORY_ARRAY
#define BOARD_ENET_NON_DMA_MEMORY_ARRAY                         \
    {                                                           \
        {0xC0000000U, 0xFFFFFFFFU}, {0x00000000U, 0x00000000U}, \
    }
#endif /* BOARD_ENET_NON_DMA_MEMORY_ARRAY */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/
void BOARD_InitDebugConsole(void);

#if defined(SDK_I2C_BASED_COMPONENT_USED) && SDK_I2C_BASED_COMPONENT_USED
void BOARD_LPI2C_Init(LPI2C_Type *base, uint32_t clkSrc_Hz);
status_t BOARD_LPI2C_Send(LPI2C_Type *base,
                          uint8_t deviceAddress,
                          uint32_t subAddress,
                          uint8_t subaddressSize,
                          uint8_t *txBuff,
                          uint8_t txBuffSize);
status_t BOARD_LPI2C_Receive(LPI2C_Type *base,
                             uint8_t deviceAddress,
                             uint32_t subAddress,
                             uint8_t subaddressSize,
                             uint8_t *rxBuff,
                             uint8_t rxBuffSize);
#endif /* SDK_I2C_BASED_COMPONENT_USED */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
