/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#define DT_DRV_COMPAT st_stm32h7_uart

#include <assert.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <device.h>
#include <pm/device.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/timeout.h>
#include <debug.h>

#include <clk.h>
#include <pinctrl.h>
#include <uart.h>

#include <stm32_uart_regs.h>
#include <stm32_uart.h>

#define UART_CR1_FIELDS \
		(USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | \
		 USART_CR1_RE | USART_CR1_OVER8 | USART_CR1_FIFOEN)

#define USART_CR3_FIELDS \
		(USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_ONEBIT | \
		 USART_CR3_TXFTCFG | USART_CR3_RXFTCFG)

#define UART_ISR_ERRORS	 \
		(USART_ISR_ORE | USART_ISR_NE |  USART_ISR_FE | USART_ISR_PE)

struct stm32_uart_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct pinctrl_dev_config *pcfg;
};

struct stm32_uart_data {
	struct stm32_uart_init_s init;
	struct uart_config uart_config;
	struct clk *clk;
};

static const uint16_t presc_table[UART_PRESCALER_MAX + 1] = {
	1U, 2U, 4U, 6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U
};

/* @brief  BRR division operation to set BRR register in 8-bit oversampling
 * mode.
 * @param  clockfreq: UART clock.
 * @param  baud_rate: Baud rate set by the user.
 * @param  prescaler: UART prescaler value.
 * @retval Division result.
 */
static inline uint32_t _stm32_uart_div_sampling8(unsigned long clockfreq,
						 uint32_t baud_rate,
						 uint32_t prescaler)
{
	uint32_t scaled_freq = clockfreq / presc_table[prescaler];

	return ((scaled_freq * 2) + (baud_rate / 2)) / baud_rate;

}

/* @brief  BRR division operation to set BRR register in 16-bit oversampling
 * mode.
 * @param  clockfreq: UART clock.
 * @param  baud_rate: Baud rate set by the user.
 * @param  prescaler: UART prescaler value.
 * @retval Division result.
 */
static inline uint32_t _stm32_uart_div_sampling16(unsigned long clockfreq,
						  uint32_t baud_rate,
						  uint32_t prescaler)
{
	uint32_t scaled_freq = clockfreq / presc_table[prescaler];

	return (scaled_freq + (baud_rate / 2)) / baud_rate;

}

/******************************************************************************/
/*
 * @brief  Compute RDR register mask depending on word length.
 * @param  huart: UART handle.
 * @retval Mask value.
 */
static unsigned int _stm32_uart_mask_computation(const struct device *dev)
{
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	unsigned int mask;

	switch (drv_data->init.word_length) {
	case UART_WORDLENGTH_9B:
		mask = GENMASK(8, 0);
		break;
	case UART_WORDLENGTH_8B:
		mask = GENMASK(7, 0);
		break;
	case UART_WORDLENGTH_7B:
		mask = GENMASK(6, 0);
		break;
	default:
		return 0U;
	}

	if (drv_data->init.parity != UART_PARITY_NONE) {
		mask >>= 1;
	}

	return mask;
}

/*
 * @brief  Periodically poll an address until a condition is met or a timeout occurs
 * @retval Returns 0 on success and -ETIMEDOUT
 */
static uint32_t _stm32_uart_wait_flag(const struct device *dev, uint32_t flag,
				      uint64_t timeout_us)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	uint32_t value, err;

	err = mmio_read32_poll_timeout(drv_cfg->base + _USART_ISR,
				       value, (value & flag), timeout_us);

	if (err) {
		/*
		 * Disable TXE, frame error, noise error, overrun
		 * error interrupts for the interrupt process.
		 */
		mmio_clrbits_32(drv_cfg->base + _USART_CR1,
				_USART_CR1_RXNEIE | _USART_CR1_PEIE |
				_USART_CR1_TXEIE);
		mmio_clrbits_32(drv_cfg->base + _USART_CR3, _USART_CR3_EIE);
		/* Clear all error flags */
		mmio_write_32(drv_cfg->base + _USART_ICR,
			      _USART_ICR_PECF | _USART_ICR_FECF |
			      _USART_ICR_NCF | _USART_ICR_ORECF);
	}

	return err;
}

static uint32_t _stm32_uart_check_idle_state(const struct device *dev)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);

	/* Check if the transmitter is enabled */
	if (((mmio_read_32(drv_cfg->base + _USART_CR1) & USART_CR1_TE) ==
	     USART_CR1_TE) &&
	    (_stm32_uart_wait_flag(dev,
				   USART_ISR_TEACK,
				   UART_TIMEOUT_US))) {
		return -ETIMEDOUT;
	}

	/* Check if the receiver is enabled */
	if (((mmio_read_32(drv_cfg->base + _USART_CR1) & USART_CR1_RE) ==
	     USART_CR1_RE) &&
	    (_stm32_uart_wait_flag(dev,
				   USART_ISR_REACK,
				   UART_TIMEOUT_US))) {
		return -ETIMEDOUT;
	}

	return 0;
}

/*
 * @brief  Configure the UART peripheral.
 * @param  dev: device reference.
 * @retval UART status.
 */
static int _stm32_uart_set_config(const struct device *dev)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	uint32_t tmpreg;
	unsigned long clockfreq;
	uint16_t brrtemp;

	/*
	 * ---------------------- USART CR1 Configuration --------------------
	 * Clear M, PCE, PS, TE, RE and OVER8 bits and configure
	 * the UART word length, parity, mode and oversampling:
	 * - set the M bits according to drv_data->init.word_length value,
	 * - set PCE and PS bits according to drv_data->init.parity value,
	 * - set TE and RE bits according to drv_data->init.mode value,
	 * - set OVER8 bit according to drv_data->init.over_sampling value.
	 */
	tmpreg = drv_data->init.word_length |
		 drv_data->init.parity |
		 drv_data->init.mode |
		 drv_data->init.over_sampling |
		 drv_data->init.fifo_mode;
	mmio_clrsetbits_32(drv_cfg->base + _USART_CR1, UART_CR1_FIELDS, tmpreg);

	/*
	 * --------------------- USART CR2 Configuration ---------------------
	 * Configure the UART Stop Bits: Set STOP[13:12] bits according
	 * to drv_data->init.stop_bits value.
	 */
	mmio_clrsetbits_32(drv_cfg->base + _USART_CR2, USART_CR2_STOP,
			   drv_data->init.stop_bits);

	/*
	 * --------------------- USART CR3 Configuration ---------------------
	 * Configure:
	 * - UART HardWare Flow Control: set CTSE and RTSE bits according
	 *   to drv_data->init.hw_flow_control value,
	 * - one-bit sampling method versus three samples' majority rule
	 *   according to drv_data->init.one_bit_sampling (not applicable to
	 *   LPUART),
	 * - set TXFTCFG bit according to drv_data->init.tx_fifo_threshold value,
	 * - set RXFTCFG bit according to drv_data->init.rx_fifo_threshold value.
	 */
	tmpreg = drv_data->init.hw_flow_control | drv_data->init.one_bit_sampling;

	if (drv_data->init.fifo_mode == USART_CR1_FIFOEN) {
		tmpreg |= drv_data->init.tx_fifo_threshold |
			  drv_data->init.rx_fifo_threshold;
	}

	mmio_clrsetbits_32(drv_cfg->base + _USART_CR3, USART_CR3_FIELDS, tmpreg);

	/*
	 * --------------------- USART PRESC Configuration -------------------
	 * Configure UART Clock Prescaler : set PRESCALER according to
	 * drv_data->init.prescaler value.
	 */
	_ASSERT(drv_data->init.prescaler <= UART_PRESCALER_MAX);
	mmio_clrsetbits_32(drv_cfg->base + _USART_PRESC, USART_PRESC_PRESCALER,
			   drv_data->init.prescaler);

	/*---------------------- USART BRR configuration --------------------*/
	clockfreq = clk_get_rate(drv_data->clk);
	if (clockfreq == 0UL) {
		return -EINVAL;
	}

	if (drv_data->init.over_sampling == UART_OVERSAMPLING_8) {
		uint16_t usartdiv =
			(uint16_t)_stm32_uart_div_sampling8(clockfreq,
							    drv_data->init.baud_rate,
							    drv_data->init.prescaler);

		brrtemp = (usartdiv & GENMASK(15, 4)) |
			  ((usartdiv & GENMASK(3, 0)) >> 1);
	} else {
		brrtemp = (uint16_t)_stm32_uart_div_sampling16(clockfreq,
							       drv_data->init.baud_rate,
							       drv_data->init.prescaler);
	}

	mmio_write_16(drv_cfg->base + _USART_BRR, brrtemp);

	return 0;
}

static uint32_t _stm32_uart_databits_cfg(const struct device *dev,
					 const struct uart_config *uart_cfg)
{
	struct stm32_uart_data *drv_data = dev_get_data(dev);

	switch (uart_cfg->data_bits) {
	case UART_CFG_DATA_BITS_7:
		drv_data->init.word_length = UART_WORDLENGTH_7B;
		break;

	case UART_CFG_DATA_BITS_8:
		drv_data->init.word_length = UART_WORDLENGTH_8B;
		break;

	case UART_CFG_DATA_BITS_9:
		drv_data->init.word_length = UART_WORDLENGTH_9B;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static uint32_t _stm32_uart_parity_cfg(const struct device *dev,
				       const struct uart_config *uart_cfg)
{
	struct stm32_uart_data *drv_data = dev_get_data(dev);

	switch (uart_cfg->parity) {
	case UART_CFG_PARITY_NONE:
		drv_data->init.parity = UART_PARITY_NONE;
		break;

	case UART_CFG_PARITY_EVEN:
		drv_data->init.parity = UART_PARITY_EVEN;
		break;

	case UART_CFG_PARITY_ODD:
		drv_data->init.parity = UART_PARITY_ODD;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static uint32_t _stm32_uart_stopbits_cfg(const struct device *dev,
					 const struct uart_config *uart_cfg)
{
	struct stm32_uart_data *drv_data = dev_get_data(dev);

	switch (uart_cfg->stop_bits) {
	case UART_CFG_STOP_BITS_0_5:
		drv_data->init.stop_bits = UART_STOPBITS_0_5;
		break;

	case UART_CFG_STOP_BITS_1:
		drv_data->init.stop_bits = UART_STOPBITS_1;
		break;

	case UART_CFG_STOP_BITS_1_5:
		drv_data->init.stop_bits = UART_STOPBITS_1_5;
		break;

	case UART_CFG_STOP_BITS_2:
		drv_data->init.stop_bits = UART_STOPBITS_2;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static uint32_t _stm32_uart_hwcontrol_cfg(const struct device *dev,
					  const struct uart_config *uart_cfg)
{
	struct stm32_uart_data *drv_data = dev_get_data(dev);

	switch (uart_cfg->flow_ctrl) {
	case UART_CFG_FLOW_CTRL_NONE:
		drv_data->init.hw_flow_control = UART_HWCONTROL_NONE;
		break;

	case UART_CFG_FLOW_CTRL_RTS_CTS:
		drv_data->init.hw_flow_control = UART_HWCONTROL_RTS | UART_HWCONTROL_CTS;
		break;
	default:
		return -ENOTSUP;
	}

	return 0;
}

static int stm32_uart_configure(const struct device *dev,
				const struct uart_config *uart_cfg)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	int err;

	/* Disable the peripheral */
	mmio_clrbits_32(drv_cfg->base + _USART_CR1, USART_CR1_UE);

	err = _stm32_uart_databits_cfg(dev, uart_cfg);
	err += _stm32_uart_parity_cfg(dev, uart_cfg);
	err += _stm32_uart_stopbits_cfg(dev, uart_cfg);
	err += _stm32_uart_hwcontrol_cfg(dev, uart_cfg);
	if (err)
		return -ENOTSUP;

	drv_data->init.baud_rate = uart_cfg->baudrate;

	/* FixME:
	 * set dynamicaly, dt... */
	drv_data->init.mode = UART_MODE_TX_RX;
	drv_data->init.over_sampling = UART_OVERSAMPLING_8;
	drv_data->init.one_bit_sampling = UART_ONE_BIT_SAMPLE_DISABLE;
	drv_data->init.prescaler = UART_PRESCALER_DIV1;

	err = _stm32_uart_set_config(dev);
	if (err)
		return err;

	/*
	 * In asynchronous mode, the following bits must be kept cleared:
	 * - LINEN and CLKEN bits in the _USART_CR2 register,
	 * - SCEN, HDSEL and IREN  bits in the _USART_CR3 register.
	 */
	mmio_clrbits_32(drv_cfg->base + _USART_CR2,
			USART_CR2_LINEN | USART_CR2_CLKEN);
	mmio_clrbits_32(drv_cfg->base + _USART_CR3,
			USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);

	/* Clear all error flags before enabling the peripheral */
	mmio_write_32(drv_cfg->base + _USART_ICR,
		      _USART_ICR_PECF | _USART_ICR_FECF |
		      _USART_ICR_NCF | _USART_ICR_ORECF);

	/* Enable the peripheral */
	mmio_setbits_32(drv_cfg->base + _USART_CR1, USART_CR1_UE);

	/* TEACK and/or REACK to check */
	err = _stm32_uart_check_idle_state(dev);
	if (err)
		goto err_check;

	memcpy(&drv_data->uart_config, uart_cfg, sizeof(*uart_cfg));

	return 0;

err_check:
	/* Disable the peripheral */
	mmio_clrbits_32(drv_cfg->base + _USART_CR1, USART_CR1_UE);
	return err;
}

static int stm32_uart_tx(const struct device *dev, const uint8_t *buf,
			 size_t len, uint32_t timeout)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	unsigned int count = 0U;
	int tx_xfer_count = len;

	if ((buf == NULL) || (len == 0U))
		return -EINVAL;

	while (tx_xfer_count > 0U) {
		tx_xfer_count--;
		if (_stm32_uart_wait_flag(dev, _USART_ISR_TXE, timeout))
			return -EBUSY;

		if ((drv_data->init.word_length == UART_WORDLENGTH_9B) &&
		    (drv_data->init.parity == UART_PARITY_NONE)) {
			uint16_t data = (uint16_t)*(buf + count) |
					(uint16_t)(*(buf + count + 1) << 8);

			mmio_write_16(drv_cfg->base + _USART_TDR, data & GENMASK(8, 0));
			count += 2U;
		} else {
			mmio_write_8(drv_cfg->base + _USART_TDR, (*(buf + count) & GENMASK(7, 0)));
			count++;
		}
	}

	if (_stm32_uart_wait_flag(dev, USART_ISR_TC, timeout))
		return -EBUSY;

	return 0;
}

static int stm32_uart_rx(const struct device *dev, uint8_t *buf, size_t len,
			 uint32_t timeout)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	unsigned int count = 0U;
	int rx_xfer_count = len;
	uint16_t uhmask;

	if ((buf == NULL) || (len == 0U))
		return -EINVAL;

	/* Computation of UART mask to apply to RDR register */
	uhmask = _stm32_uart_mask_computation(dev);

	while (rx_xfer_count > 0U) {
		rx_xfer_count--;
		if (_stm32_uart_wait_flag(dev, _USART_ISR_RXNE, timeout))
			return -EBUSY;

		if ((drv_data->init.word_length == UART_WORDLENGTH_9B) &&
		    (drv_data->init.parity == UART_PARITY_NONE)) {
			uint16_t data = mmio_read_16(drv_cfg->base + _USART_RDR) & uhmask;

			*(buf + count) = (uint8_t)data;
			*(buf + count + 1) = (uint8_t)(data >> 8);

			count += 2U;
		} else {
			*(buf + count) = mmio_read_8(drv_cfg->base + _USART_RDR) & (uint8_t)uhmask;
			count++;
		}
	}

	return 0;
}

static bool stm32_uart_rx_available(const struct device *dev, uint32_t timeout_us)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	uint32_t value;
	int err;

	err = mmio_read32_poll_timeout(drv_cfg->base + _USART_ISR, value,
				       (value & _USART_ISR_RXNE), timeout_us);

	return (err == 0);
}

static const struct uart_driver_api uart_stm32_api = {
	.configure = stm32_uart_configure,
	.tx = stm32_uart_tx,
	.rx = stm32_uart_rx,
	.rx_available = stm32_uart_rx_available,
};

int stm32_uart_dt_init(const struct device *dev)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	int err;

	drv_data->clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (!drv_data->clk)
		return -ENODEV;

	err = pinctrl_apply_state(drv_cfg->pcfg, PINCTRL_STATE_DEFAULT);
	if (err)
		return err;

	err = clk_enable(drv_data->clk);
	if (err)
		return err;

	if (IS_ENABLED(STM32_CONSOLE_NO_SUSPEND))
		pm_device_flags_set(dev, PM_DEVICE_F_NO_SUSPEND);

	return stm32_uart_configure(dev, &drv_data->uart_config);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_uart_pm_action(const struct device *dev,
			       enum pm_device_action action, uint32_t pm_hint)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	int err = 0;

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		err = pinctrl_apply_state_optional(drv_cfg->pcfg, PINCTRL_STATE_SLEEP);
		if (err)
			goto out;

		clk_disable(drv_data->clk);
	} else {
		/*
		 * Clock disable to balance the usage counter in clock framework
		 * as clk_disable() was skipped for PM_DEVICE_ACTION_SUSPEND.
		 * Always reapply the pinctrl and execute clock enable
		 * which are lost in Standby.
		 */
		if (IS_ENABLED(STM32_CONSOLE_NO_SUSPEND)) {
			clk_disable(drv_data->clk);
		}

		err = pinctrl_apply_state(drv_cfg->pcfg, PINCTRL_STATE_DEFAULT);
		if (err)
			goto out;

		err = clk_enable(drv_data->clk);
		if (err)
			goto out;


		err = stm32_uart_configure(dev, &drv_data->uart_config);
	}

out:
	return err;
}
#endif

#define _UART_CFG(n)									\
{											\
	.baudrate = DT_INST_PROP_OR(n, current_speed, 0),				\
	.parity = DT_INST_ENUM_IDX_OR(n, parity, UART_CFG_PARITY_NONE),			\
	.stop_bits = DT_INST_ENUM_IDX_OR(n, stop_bits, UART_CFG_STOP_BITS_1),		\
	.data_bits = DT_INST_ENUM_IDX_OR(n, data_bits, UART_CFG_DATA_BITS_8),		\
	.flow_ctrl = DT_INST_PROP_OR(n, hw_flow_control, UART_CFG_FLOW_CTRL_NONE),	\
}

#define STM32_UART_INIT(n)								\
											\
PINCTRL_DT_INST_DEFINE(n);								\
											\
static const struct stm32_uart_config stm32_uart_cfg_##n = {				\
	.base = DT_INST_REG_ADDR(n),							\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),				\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),			\
	.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),					\
};											\
											\
static struct stm32_uart_data stm32_uart_data_##n = {					\
	.uart_config = _UART_CFG(n),							\
};											\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_uart_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n,								\
		      &stm32_uart_dt_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_uart_data_##n,						\
		      &stm32_uart_cfg_##n,						\
		      CORE, 0,								\
		      &uart_stm32_api);

DT_INST_FOREACH_STATUS_OKAY(STM32_UART_INIT)
