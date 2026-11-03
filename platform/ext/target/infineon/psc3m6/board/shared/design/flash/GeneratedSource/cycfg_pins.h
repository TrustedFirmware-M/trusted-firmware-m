/*******************************************************************************
 * File Name: cycfg_pins.h
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.39.0.10988
 * ifx-tf-m 1.0.0.0
 * mtb-dsl-psc3m6 1.0.0.335
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_WCO_OUT (P0_0)
#define CYBSP_WCO_IN (P0_1)
#define CYBSP_ECO_IN (P1_0)
#define CYBSP_ECO_OUT (P1_1)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDCLK_ENABLED 1U
#define CYBSP_SWDCLK_PORT GPIO_PRT1
#define CYBSP_SWDCLK_PORT_NUM 1U
#define CYBSP_SWDCLK_PIN 2U
#define CYBSP_SWDCLK_NUM 2U
#define CYBSP_SWDCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CYBSP_SWDCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCLK_HSIOM ioss_0_port_1_pin_2_HSIOM

#if !defined (COMPONENT_PPCA_DEVICE)
#define CYBSP_SWDCLK_IRQ ioss_interrupts_sec_gpio_1_IRQn
#endif /* !defined (COMPONENT_PPCA_DEVICE) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDCLK_HAL_PORT_PIN P1_2
#define CYBSP_SWDCLK P1_2
#define CYBSP_SWDCLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDCLK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDCLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT1
#define CYBSP_SWDIO_PORT_NUM 1U
#define CYBSP_SWDIO_PIN 3U
#define CYBSP_SWDIO_NUM 3U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_3_HSIOM
    #define ioss_0_port_1_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_1_pin_3_HSIOM

#if !defined (COMPONENT_PPCA_DEVICE)
#define CYBSP_SWDIO_IRQ ioss_interrupts_sec_gpio_1_IRQn
#endif /* !defined (COMPONENT_PPCA_DEVICE) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDIO_HAL_PORT_PIN P1_3
#define CYBSP_SWDIO P1_3
#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#define CYBSP_USER_BTN2 (P2_0)
#define CYBSP_SW3 CYBSP_USER_BTN2
#define CYBSP_D7 (P3_0)
#define CYBSP_UART_RX (P3_2)
#define CYBSP_D0 CYBSP_UART_RX
#define CYBSP_MIKROBUS_UART_RX CYBSP_UART_RX
#define CYBSP_UART_TX (P3_3)
#define CYBSP_D1 CYBSP_UART_TX
#define CYBSP_MIKROBUS_UART_TX CYBSP_UART_TX
#define CYBSP_D3 (P4_0)
#define CYBSP_MIKROBUS_PWM CYBSP_D3
#define CYBSP_D5 (P4_1)
#define CYBSP_D6 (P4_2)
#define CYBSP_D9 (P4_3)
#define CYBSP_CAN_RX (P5_2)
#define CYBSP_CAN_TX (P5_3)
#define CYBSP_D4 (P6_0)
#define CYBSP_D2 (P6_1)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_DEBUG_UART_RX_ENABLED 1U
#define CYBSP_DEBUG_UART_RX_PORT GPIO_PRT6
#define CYBSP_DEBUG_UART_RX_PORT_NUM 6U
#define CYBSP_DEBUG_UART_RX_PIN 2U
#define CYBSP_DEBUG_UART_RX_NUM 2U
#define CYBSP_DEBUG_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define CYBSP_DEBUG_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_2_HSIOM
    #define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_DEBUG_UART_RX_HSIOM ioss_0_port_6_pin_2_HSIOM

#if !defined (COMPONENT_PPCA_DEVICE)
#define CYBSP_DEBUG_UART_RX_IRQ ioss_interrupts_sec_gpio_6_IRQn
#endif /* !defined (COMPONENT_PPCA_DEVICE) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_DEBUG_UART_RX_HAL_PORT_PIN P6_2
#define CYBSP_DEBUG_UART_RX P6_2
#define CYBSP_DEBUG_UART_RX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_DEBUG_UART_RX_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_DEBUG_UART_RX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_DEBUG_UART_TX_ENABLED 1U
#define CYBSP_DEBUG_UART_TX_PORT GPIO_PRT6
#define CYBSP_DEBUG_UART_TX_PORT_NUM 6U
#define CYBSP_DEBUG_UART_TX_PIN 3U
#define CYBSP_DEBUG_UART_TX_NUM 3U
#define CYBSP_DEBUG_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_DEBUG_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_3_HSIOM
    #define ioss_0_port_6_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_DEBUG_UART_TX_HSIOM ioss_0_port_6_pin_3_HSIOM

#if !defined (COMPONENT_PPCA_DEVICE)
#define CYBSP_DEBUG_UART_TX_IRQ ioss_interrupts_sec_gpio_6_IRQn
#endif /* !defined (COMPONENT_PPCA_DEVICE) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_DEBUG_UART_TX_HAL_PORT_PIN P6_3
#define CYBSP_DEBUG_UART_TX P6_3
#define CYBSP_DEBUG_UART_TX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_DEBUG_UART_TX_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define CYBSP_DEBUG_UART_TX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_SPI_CLK (P7_0)
#define CYBSP_D13 CYBSP_SPI_CLK
#define CYBSP_MIKROBUS_SPI_SCK CYBSP_SPI_CLK
#define CYBSP_SPI_MOSI (P7_1)
#define CYBSP_D11 CYBSP_SPI_MOSI
#define CYBSP_MIKROBUS_SPI_MOSI CYBSP_SPI_MOSI
#define CYBSP_SPI_MISO (P7_2)
#define CYBSP_D12 CYBSP_SPI_MISO
#define CYBSP_MIKROBUS_SPI_MISO CYBSP_SPI_MISO
#define CYBSP_SPI_CS (P7_3)
#define CYBSP_D10 CYBSP_SPI_CS
#define CYBSP_MIKROBUS_INT (P7_7)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_USER_LED_ENABLED 1U
#define CYBSP_USER_LED3_ENABLED CYBSP_USER_LED_ENABLED
#define CYBSP_USER_LED1_ENABLED CYBSP_USER_LED_ENABLED
#define CYBSP_USER_LED_PORT GPIO_PRT8
#define CYBSP_USER_LED3_PORT CYBSP_USER_LED_PORT
#define CYBSP_USER_LED1_PORT CYBSP_USER_LED_PORT
#define CYBSP_USER_LED_PORT_NUM 8U
#define CYBSP_USER_LED3_PORT_NUM CYBSP_USER_LED_PORT_NUM
#define CYBSP_USER_LED1_PORT_NUM CYBSP_USER_LED_PORT_NUM
#define CYBSP_USER_LED_PIN 4U
#define CYBSP_USER_LED3_PIN CYBSP_USER_LED_PIN
#define CYBSP_USER_LED1_PIN CYBSP_USER_LED_PIN
#define CYBSP_USER_LED_NUM 4U
#define CYBSP_USER_LED3_NUM CYBSP_USER_LED_NUM
#define CYBSP_USER_LED1_NUM CYBSP_USER_LED_NUM
#define CYBSP_USER_LED_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_USER_LED3_DRIVEMODE CYBSP_USER_LED_DRIVEMODE
#define CYBSP_USER_LED1_DRIVEMODE CYBSP_USER_LED_DRIVEMODE
#define CYBSP_USER_LED_INIT_DRIVESTATE 1
#define CYBSP_USER_LED3_INIT_DRIVESTATE CYBSP_USER_LED_INIT_DRIVESTATE
#define CYBSP_USER_LED1_INIT_DRIVESTATE CYBSP_USER_LED_INIT_DRIVESTATE
#ifndef ioss_0_port_8_pin_4_HSIOM
    #define ioss_0_port_8_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_USER_LED_HSIOM ioss_0_port_8_pin_4_HSIOM
#define CYBSP_USER_LED3_HSIOM CYBSP_USER_LED_HSIOM
#define CYBSP_USER_LED1_HSIOM CYBSP_USER_LED_HSIOM

#if !defined (COMPONENT_PPCA_DEVICE)
#define CYBSP_USER_LED_IRQ ioss_interrupts_gpio_8_IRQn
#define CYBSP_USER_LED3_IRQ CYBSP_USER_LED_IRQ
#define CYBSP_USER_LED1_IRQ CYBSP_USER_LED_IRQ
#endif /* !defined (COMPONENT_PPCA_DEVICE) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_USER_LED_HAL_PORT_PIN P8_4
#define CYBSP_USER_LED3_HAL_PORT_PIN CYBSP_USER_LED_HAL_PORT_PIN
#define CYBSP_USER_LED1_HAL_PORT_PIN CYBSP_USER_LED_HAL_PORT_PIN
#define CYBSP_USER_LED P8_4
#define CYBSP_USER_LED3 CYBSP_USER_LED
#define CYBSP_USER_LED1 CYBSP_USER_LED
#define CYBSP_USER_LED_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_USER_LED3_HAL_IRQ CYBSP_USER_LED_HAL_IRQ
#define CYBSP_USER_LED1_HAL_IRQ CYBSP_USER_LED_HAL_IRQ
#define CYBSP_USER_LED_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define CYBSP_USER_LED3_HAL_DIR CYBSP_USER_LED_HAL_DIR
#define CYBSP_USER_LED1_HAL_DIR CYBSP_USER_LED_HAL_DIR
#define CYBSP_USER_LED_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_USER_LED3_HAL_DRIVEMODE CYBSP_USER_LED_HAL_DRIVEMODE
#define CYBSP_USER_LED1_HAL_DRIVEMODE CYBSP_USER_LED_HAL_DRIVEMODE
#define CYBSP_USER_LED4 (P8_5)
#define CYBSP_I2C_SCL (P9_0)
#define CYBSP_MIKROBUS_I2C_SCL CYBSP_I2C_SCL
#define CYBSP_I2C_SDA (P9_2)
#define CYBSP_MIKROBUS_I2C_SDA CYBSP_I2C_SDA
#define CYBSP_MIKROBUS_SPI_CS (P10_1)
#define CYBSP_USER_BTN (P10_2)
#define CYBSP_USER_BTN1 CYBSP_USER_BTN
#define CYBSP_SW4 CYBSP_USER_BTN
#define CYBSP_USB_DM (P11_0)
#define CYBSP_USB_DP (P11_1)
#define CYBSP_D8 (P12_5)
#define CYBSP_CAN_STB CYBSP_D8
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDCLK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDCLK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_RX_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_DEBUG_UART_RX_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_DEBUG_UART_TX_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_DEBUG_UART_TX_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_USER_LED_config;

#define CYBSP_USER_LED3_config CYBSP_USER_LED_config
#define CYBSP_USER_LED1_config CYBSP_USER_LED_config

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_USER_LED_obj;
#define CYBSP_USER_LED3_obj CYBSP_USER_LED_obj
#define CYBSP_USER_LED1_obj CYBSP_USER_LED_obj
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
