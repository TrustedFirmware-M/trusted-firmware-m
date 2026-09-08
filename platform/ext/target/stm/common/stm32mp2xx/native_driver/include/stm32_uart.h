/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef STM32_UART_H
#define STM32_UART_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/* Return status */
#define UART_OK					0U
#define UART_ERROR				0xFFFFFFFFU
#define UART_BUSY				0xFFFFFFFEU
#define UART_TIMEOUT				0xFFFFFFFDU

/* UART word length */
#define UART_WORDLENGTH_7B			USART_CR1_M1
#define UART_WORDLENGTH_8B			0x00000000U
#define UART_WORDLENGTH_9B			USART_CR1_M0

/* UART number of stop bits */
#define UART_STOPBITS_0_5			USART_CR2_STOP_0
#define UART_STOPBITS_1				0x00000000U
#define UART_STOPBITS_1_5			(USART_CR2_STOP_0 | \
						 USART_CR2_STOP_1)
#define UART_STOPBITS_2				USART_CR2_STOP_1

/* UART parity */
#define UART_PARITY_NONE			0x00000000U
#define UART_PARITY_EVEN			USART_CR1_PCE
#define UART_PARITY_ODD				(USART_CR1_PCE | USART_CR1_PS)

/* UART transfer mode */
#define UART_MODE_RX				USART_CR1_RE
#define UART_MODE_TX				USART_CR1_TE
#define UART_MODE_TX_RX				(USART_CR1_TE | USART_CR1_RE)

/* UART hardware flow control */
#define UART_HWCONTROL_NONE			0x00000000U
#define UART_HWCONTROL_RTS			USART_CR3_RTSE
#define UART_HWCONTROL_CTS			USART_CR3_CTSE
#define UART_HWCONTROL_RTS_CTS			(USART_CR3_RTSE | \
						 USART_CR3_CTSE)

/* UART over sampling */
#define UART_OVERSAMPLING_16			0x00000000U
#define UART_OVERSAMPLING_8			USART_CR1_OVER8

/* UART One Bit Sampling Method */
#define UART_ONE_BIT_SAMPLE_DISABLE         0x00000000U
#define UART_ONE_BIT_SAMPLE_ENABLE          USART_CR3_ONEBIT

/* UART prescaler */
#define UART_PRESCALER_DIV1			0x00000000U
#define UART_PRESCALER_DIV2			0x00000001U
#define UART_PRESCALER_DIV4			0x00000002U
#define UART_PRESCALER_DIV6			0x00000003U
#define UART_PRESCALER_DIV8			0x00000004U
#define UART_PRESCALER_DIV10			0x00000005U
#define UART_PRESCALER_DIV12			0x00000006U
#define UART_PRESCALER_DIV16			0x00000007U
#define UART_PRESCALER_DIV32			0x00000008U
#define UART_PRESCALER_DIV64			0x00000009U
#define UART_PRESCALER_DIV128			0x0000000AU
#define UART_PRESCALER_DIV256			0x0000000BU
#define UART_PRESCALER_MAX			UART_PRESCALER_DIV256

/* UART TXFIFO threshold level */
#define UART_TXFIFO_THRESHOLD_1EIGHTHFULL	0x00000000U
#define UART_TXFIFO_THRESHOLD_1QUARTERFUL	USART_CR3_TXFTCFG_0
#define UART_TXFIFO_THRESHOLD_HALFFULL		USART_CR3_TXFTCFG_1
#define UART_TXFIFO_THRESHOLD_3QUARTERSFULL	(USART_CR3_TXFTCFG_0 | \
						 USART_CR3_TXFTCFG_1)
#define UART_TXFIFO_THRESHOLD_7EIGHTHFULL	USART_CR3_TXFTCFG_2
#define UART_TXFIFO_THRESHOLD_EMPTY		(USART_CR3_TXFTCFG_2 | \
						 USART_CR3_TXFTCFG_0)

/* UART RXFIFO threshold level */
#define UART_RXFIFO_THRESHOLD_1EIGHTHFULL	0x00000000U
#define UART_RXFIFO_THRESHOLD_1QUARTERFULL	USART_CR3_RXFTCFG_0
#define UART_RXFIFO_THRESHOLD_HALFFULL		USART_CR3_RXFTCFG_1
#define UART_RXFIFO_THRESHOLD_3QUARTERSFULL	(USART_CR3_RXFTCFG_0 | \
						 USART_CR3_RXFTCFG_1)
#define UART_RXFIFO_THRESHOLD_7EIGHTHFULL	USART_CR3_RXFTCFG_2
#define UART_RXFIFO_THRESHOLD_FULL		(USART_CR3_RXFTCFG_2 | \
						 USART_CR3_RXFTCFG_0)

/* UART advanced feature initialization type */
#define UART_ADVFEATURE_NO_INIT			0U
#define UART_ADVFEATURE_TXINVERT_INIT		BIT(0)
#define UART_ADVFEATURE_RXINVERT_INIT		BIT(1)
#define UART_ADVFEATURE_DATAINVERT_INIT		BIT(2)
#define UART_ADVFEATURE_SWAP_INIT		BIT(3)
#define UART_ADVFEATURE_RXOVERRUNDISABLE_INIT	BIT(4)
#define UART_ADVFEATURE_DMADISABLEONERROR_INIT	BIT(5)
#define UART_ADVFEATURE_AUTOBAUDRATE_INIT	BIT(6)
#define UART_ADVFEATURE_MSBFIRST_INIT		BIT(7)

/* UART advanced feature autobaud rate mode */
#define UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT		0x00000000U
#define UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE	USART_CR2_ABRMODE_0
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME	USART_CR2_ABRMODE_1
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME	USART_CR2_ABRMODE

/* UART polling-based communications time-out value */
#define UART_TIMEOUT_US				20000U

struct stm32_uart_init_s {
	uint32_t baud_rate;		/*
					 * Configures the UART communication
					 * baud rate.
					 */

	uint32_t word_length;		/*
					 * Specifies the number of data bits
					 * transmitted or received in a frame.
					 * This parameter can be a value of
					 * @ref UART_WORDLENGTH_*.
					 */

	uint32_t stop_bits;		/*
					 * Specifies the number of stop bits
					 * transmitted. This parameter can be
					 * a value of @ref UART_STOPBITS_*.
					 */

	uint32_t parity;		/*
					 * Specifies the parity mode.
					 * This parameter can be a value of
					 * @ref UART_PARITY_*.
					 */

	uint32_t mode;			/*
					 * Specifies whether the receive or
					 * transmit mode is enabled or
					 * disabled. This parameter can be a
					 * value of @ref @ref UART_MODE_*.
					 */

	uint32_t hw_flow_control;	/*
					 * Specifies whether the hardware flow
					 * control mode is enabled or
					 * disabled. This parameter can be a
					 * value of @ref UART_HWCONTROL_*.
					 */

	uint32_t over_sampling;		/*
					 * Specifies whether the over sampling
					 * 8 is enabled or disabled.
					 * This parameter can be a value of
					 * @ref UART_OVERSAMPLING_*.
					 */

	uint32_t one_bit_sampling;	/*
					 * Specifies whether a single sample
					 * or three samples' majority vote is
					 * selected. This parameter can be 0
					 * or UART_ONE_BIT_SAMPLE_*.
					 */

	uint32_t prescaler;		/*
					 * Specifies the prescaler value used
					 * to divide the UART clock source.
					 * This parameter can be a value of
					 * @ref UART_PRESCALER_*.
					 */

	uint32_t fifo_mode;		/*
					 * Specifies if the FIFO mode will be
					 * used. This parameter can be a value
					 * of @ref UART_FIFOMODE_*.
					 */

	uint32_t tx_fifo_threshold;	/*
					 * Specifies the TXFIFO threshold
					 * level. This parameter can be a
					 * value of @ref
					 * UART_TXFIFO_THRESHOLD_*.
					 */

	uint32_t rx_fifo_threshold;	/*
					 * Specifies the RXFIFO threshold
					 * level. This parameter can be a
					 * value of @ref
					 * UART_RXFIFO_THRESHOLD_*.
					 */
};

#endif /* STM32_UART_H */

