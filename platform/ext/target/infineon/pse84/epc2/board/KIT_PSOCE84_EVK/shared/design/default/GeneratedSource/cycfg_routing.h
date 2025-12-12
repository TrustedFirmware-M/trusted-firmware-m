/*******************************************************************************
 * File Name: cycfg_routing.h
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.60.0
 * device-db 4.33.0.9315
 * ifx-mcuboot-pse84 1.1.0.349
 * ifx-tf-m 2.1.400.14138
 * mtb-dsl-pse8xxgp 1.1.1.824
 *
 *******************************************************************************
 * Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#include "cycfg_notices.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define ioss_0_port_0_pin_1_HSIOM P0_1_SMIF1_SMIF0_SPIHB_SELECT2
#define ioss_0_port_1_pin_0_AUX SMIF0_SPIHB_DATA0_SMIF0_SMIF0_SPIHB_DATA0_PAD
#define ioss_0_port_1_pin_1_AUX SMIF0_SPIHB_DATA1_SMIF0_SMIF0_SPIHB_DATA1_PAD
#define ioss_0_port_1_pin_2_AUX SMIF0_SPIHB_DATA2_SMIF0_SMIF0_SPIHB_DATA2_PAD
#define ioss_0_port_1_pin_3_AUX SMIF0_SPIHB_DATA3_SMIF0_SMIF0_SPIHB_DATA3_PAD
#define ioss_0_port_2_pin_0_HSIOM P2_0_SMIF0_SMIF0_SPIHB_SELECT1
#define ioss_0_port_4_pin_0_AUX SMIF1_SPIHB_DATA0_SMIF1_SMIF0_SPIHB_DATA0_PAD
#define ioss_0_port_4_pin_1_AUX SMIF1_SPIHB_DATA1_SMIF1_SMIF0_SPIHB_DATA1_PAD
#define ioss_0_port_4_pin_2_AUX SMIF1_SPIHB_DATA2_SMIF1_SMIF0_SPIHB_DATA2_PAD
#define ioss_0_port_4_pin_3_AUX SMIF1_SPIHB_DATA3_SMIF1_SMIF0_SPIHB_DATA3_PAD
#define ioss_0_port_4_pin_4_AUX SMIF1_SPIHB_DATA4_SMIF1_SMIF0_SPIHB_DATA4_PAD
#define ioss_0_port_4_pin_5_AUX SMIF1_SPIHB_DATA5_SMIF1_SMIF0_SPIHB_DATA5_PAD
#define ioss_0_port_4_pin_6_AUX SMIF1_SPIHB_DATA6_SMIF1_SMIF0_SPIHB_DATA6_PAD
#define ioss_0_port_4_pin_7_AUX SMIF1_SPIHB_DATA7_SMIF1_SMIF0_SPIHB_DATA7_PAD
#define ioss_0_port_6_pin_5_HSIOM P6_5_SCB2_UART_RX
#define ioss_0_port_6_pin_7_HSIOM P6_7_SCB2_UART_TX
#define ioss_0_port_7_pin_0_HSIOM P7_0_SDHC1_CARD_CMD
#define ioss_0_port_7_pin_1_HSIOM P7_1_SDHC1_CLK_CARD
#define ioss_0_port_7_pin_3_HSIOM P7_3_SDHC1_CARD_DAT_3TO00
#define ioss_0_port_7_pin_4_HSIOM P7_4_SRSS_EXT_CLK
#define ioss_0_port_7_pin_5_HSIOM P7_5_SDHC1_CARD_DAT_3TO01
#define ioss_0_port_7_pin_6_HSIOM P7_6_SDHC1_CARD_DAT_3TO02
#define ioss_0_port_7_pin_7_HSIOM P7_7_SDHC1_CARD_DAT_3TO03
#define ioss_0_port_8_pin_0_HSIOM P8_0_SCB0_I2C_SCL
#define ioss_0_port_8_pin_1_HSIOM P8_1_SCB0_I2C_SDA
#define ioss_0_port_8_pin_5_HSIOM P8_5_PDM_PDM_CLK3
#define ioss_0_port_8_pin_6_HSIOM P8_6_PDM_PDM_DATA3
#define ioss_0_port_9_pin_0_HSIOM P9_0_TCPWM0_LINE7
#define ioss_0_port_9_pin_2_HSIOM P9_2_TCPWM0_LINE_COMPL7
#define ioss_0_port_10_pin_0_HSIOM P10_0_SCB4_UART_RX
#define ioss_0_port_10_pin_1_HSIOM P10_1_SCB4_UART_TX
#define ioss_0_port_10_pin_2_HSIOM P10_2_SCB4_UART_CTS
#define ioss_0_port_10_pin_3_HSIOM P10_3_SCB4_UART_RTS
#define ioss_0_port_11_pin_3_HSIOM P11_3_TCPWM0_LINE_COMPL262
#define ioss_0_port_12_pin_0_HSIOM P12_0_SDHC0_CLK_CARD
#define ioss_0_port_12_pin_1_HSIOM P12_1_SDHC0_CARD_DAT_3TO00
#define ioss_0_port_12_pin_2_HSIOM P12_2_SDHC0_CARD_DAT_3TO01
#define ioss_0_port_12_pin_3_HSIOM P12_3_TDM_TDM_TX_FSYNC0
#define ioss_0_port_12_pin_4_HSIOM P12_4_SDHC0_CARD_DAT_3TO02
#define ioss_0_port_12_pin_5_HSIOM P12_5_SDHC0_CARD_DAT_3TO03
#define ioss_0_port_15_pin_1_ANALOG P15_1_IOSS_ADFT1_NET0
#define ioss_0_port_16_pin_0_HSIOM P16_0_SCB10_SPI_CLK
#define ioss_0_port_16_pin_1_HSIOM P16_1_SCB10_SPI_MOSI
#define ioss_0_port_16_pin_2_HSIOM P16_2_SCB10_SPI_MISO
#define ioss_0_port_16_pin_3_HSIOM P16_3_SCB10_SPI_SELECT0
#define ioss_0_port_16_pin_5_HSIOM P16_5_TCPWM0_LINE5
#define ioss_0_port_17_pin_0_HSIOM P17_0_SCB5_I2C_SCL
#define ioss_0_port_17_pin_1_HSIOM P17_1_SCB5_I2C_SDA
#define ioss_0_port_18_pin_0_ANALOG P18_0_SRSS_WCO_OUT
#define ioss_0_port_18_pin_1_ANALOG P18_1_SRSS_WCO_IN
#define ioss_0_port_19_pin_0_ANALOG P19_0_SRSS_ECO_IN
#define ioss_0_port_19_pin_1_ANALOG P19_1_SRSS_ECO_OUT
#define ioss_0_port_21_pin_0_HSIOM P21_0_SDHC0_CARD_CMD
#define ioss_0_port_21_pin_1_HSIOM P21_1_TDM_TDM_TX_SD0
#define ioss_0_port_21_pin_2_HSIOM P21_2_TDM_TDM_TX_SCK0
#define ioss_0_port_21_pin_3_HSIOM P21_3_TDM_TDM_TX_MCK0
#define CYBSP_DMA_TX_SPI_CONTROLLER_tr_in_0_TRIGGER_OUT PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN1
#define CYBSP_SPI_CONTROLLER_tr_tx_req_0_TRIGGER_IN PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT10

void init_cycfg_routing(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_ROUTING_H */
