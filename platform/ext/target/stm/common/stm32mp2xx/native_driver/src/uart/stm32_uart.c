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

/* USART registers offsets */
#define _USART_CR1		0x00U
#define _USART_CR2		0x04U
#define _USART_CR3		0x08U
#define _USART_BRR		0x0CU
#define _USART_ISR		0x1CU
#define _USART_ICR		0x20U
#define _USART_RDR		0x24U
#define _USART_TDR		0x28U
#define _USART_PRESC		0x2CU

/* USART_CR1 register fields */
#define _CR1_UE_MASK		BIT(0)
#define _CR1_UE_SHIFT		0
#define _CR1_RE_MASK		BIT(2)
#define _CR1_RE_SHIFT		2
#define _CR1_TE_MASK		BIT(3)
#define _CR1_TE_SHIFT		3
#define _CR1_RXNEIE_MASK	BIT(5)
#define _CR1_RXNEIE_SHIFT	5
#define _CR1_TXEIE_MASK		BIT(7)
#define _CR1_TXEIE_SHIFT	7
#define _CR1_PEIE_MASK		BIT(8)
#define _CR1_PEIE_SHIFT		8
#define _CR1_PS_MASK		BIT(9)
#define _CR1_PS_SHIFT		9
#define _CR1_PCE_MASK		BIT(10)
#define _CR1_PCE_SHIFT		10
#define _CR1_M0_MASK		BIT(12)
#define _CR1_M0_SHIFT		12
#define _CR1_OVER8_MASK		BIT(15)
#define _CR1_OVER8_SHIFT	15
#define _CR1_M1_MASK		BIT(28)
#define _CR1_M1_SHIFT		28
#define _CR1_FIFOEN_MASK	BIT(29)
#define _CR1_FIFOEN_SHIFT	29

/* USART_CR2 register fields */
#define _CR2_CLKEN_MASK		BIT(11)
#define _CR2_CLKEN_SHIFT	11
#define _CR2_STOP_MASK		GENMASK_32(13, 12)
#define _CR2_STOP_SHIFT		12
#define _CR2_LINEN_MASK		BIT(14)
#define _CR2_LINEN_SHIFT	14

/* USART_CR3 register fields */
#define _CR3_EIE_MASK		BIT(0)
#define _CR3_EIE_SHIFT		0
#define _CR3_IREN_MASK		BIT(1)
#define _CR3_IREN_SHIFT		1
#define _CR3_HDSEL_MASK		BIT(3)
#define _CR3_HDSEL_SHIFT	3
#define _CR3_SCEN_MASK		BIT(5)
#define _CR3_SCEN_SHIFT		5
#define _CR3_RTSE_MASK		BIT(8)
#define _CR3_RTSE_SHIFT		8
#define _CR3_CTSE_MASK		BIT(9)
#define _CR3_CTSE_SHIFT		9
#define _CR3_ONEBIT_MASK	BIT(11)
#define _CR3_ONEBIT_SHIFT	11
#define _CR3_RXFTCFG_MASK	GENMASK_32(27, 25)
#define _CR3_RXFTCFG_SHIFT	25
#define _CR3_TXFTCFG_MASK	GENMASK_32(31, 29)
#define _CR3_TXFTCFG_SHIFT	29

/*
 * USART_BRR register fields. In oversampling by 8 mode, BRR[3] must be kept
 * cleared and DIV_FRACTION[2:0] holds USARTDIV[3:0] shifted right by 1.
 */
#define _BRR_DIV_FRACTION_MASK	GENMASK_32(3, 0)
#define _BRR_DIV_FRACTION_SHIFT	0
#define _BRR_DIV_MANTISSA_MASK	GENMASK_32(15, 4)
#define _BRR_DIV_MANTISSA_SHIFT	4

/* USART_ISR register fields */
#define _ISR_PE_MASK		BIT(0)
#define _ISR_PE_SHIFT		0
#define _ISR_FE_MASK		BIT(1)
#define _ISR_FE_SHIFT		1
#define _ISR_NE_MASK		BIT(2)
#define _ISR_NE_SHIFT		2
#define _ISR_ORE_MASK		BIT(3)
#define _ISR_ORE_SHIFT		3
#define _ISR_IDLE_MASK		BIT(4)
#define _ISR_IDLE_SHIFT		4
#define _ISR_RXNE_MASK		BIT(5)
#define _ISR_RXNE_SHIFT		5
#define _ISR_TC_MASK		BIT(6)
#define _ISR_TC_SHIFT		6
#define _ISR_TXE_MASK		BIT(7)
#define _ISR_TXE_SHIFT		7
#define _ISR_LBDF_MASK		BIT(8)
#define _ISR_LBDF_SHIFT		8
#define _ISR_CTSIF_MASK		BIT(9)
#define _ISR_CTSIF_SHIFT	9
#define _ISR_CTS_MASK		BIT(10)
#define _ISR_CTS_SHIFT		10
#define _ISR_RTOF_MASK		BIT(11)
#define _ISR_RTOF_SHIFT		11
#define _ISR_EOBF_MASK		BIT(12)
#define _ISR_EOBF_SHIFT		12
#define _ISR_UDR_MASK		BIT(13)
#define _ISR_UDR_SHIFT		13
#define _ISR_ABRE_MASK		BIT(14)
#define _ISR_ABRE_SHIFT		14
#define _ISR_ABRF_MASK		BIT(15)
#define _ISR_ABRF_SHIFT		15
#define _ISR_BUSY_MASK		BIT(16)
#define _ISR_BUSY_SHIFT		16
#define _ISR_CMF_MASK		BIT(17)
#define _ISR_CMF_SHIFT		17
#define _ISR_SBKF_MASK		BIT(18)
#define _ISR_SBKF_SHIFT		18
#define _ISR_RWU_MASK		BIT(19)
#define _ISR_RWU_SHIFT		19
#define _ISR_WUF_MASK		BIT(20)
#define _ISR_WUF_SHIFT		20
#define _ISR_TEACK_MASK		BIT(21)
#define _ISR_TEACK_SHIFT	21
#define _ISR_REACK_MASK		BIT(22)
#define _ISR_REACK_SHIFT	22
#define _ISR_TXFE_MASK		BIT(23)
#define _ISR_TXFE_SHIFT		23
#define _ISR_RXFF_MASK		BIT(24)
#define _ISR_RXFF_SHIFT		24
#define _ISR_TCBGT_MASK		BIT(25)
#define _ISR_TCBGT_SHIFT	25
#define _ISR_RXFT_MASK		BIT(26)
#define _ISR_RXFT_SHIFT		26
#define _ISR_TXFT_MASK		BIT(27)
#define _ISR_TXFT_SHIFT		27

/* USART_ICR register fields */
#define _ICR_PECF_MASK		BIT(0)
#define _ICR_PECF_SHIFT		0
#define _ICR_FECF_MASK		BIT(1)
#define _ICR_FECF_SHIFT		1
#define _ICR_NECF_MASK		BIT(2)
#define _ICR_NECF_SHIFT		2
#define _ICR_ORECF_MASK		BIT(3)
#define _ICR_ORECF_SHIFT	3
#define _ICR_IDLECF_MASK	BIT(4)
#define _ICR_IDLECF_SHIFT	4
#define _ICR_TCCF_MASK		BIT(6)
#define _ICR_TCCF_SHIFT		6
#define _ICR_TCBGTCF_MASK	BIT(7)
#define _ICR_TCBGTCF_SHIFT	7
#define _ICR_LBDCF_MASK		BIT(8)
#define _ICR_LBDCF_SHIFT	8
#define _ICR_CTSCF_MASK		BIT(9)
#define _ICR_CTSCF_SHIFT	9
#define _ICR_RTOCF_MASK		BIT(11)
#define _ICR_RTOCF_SHIFT	11
#define _ICR_EOBCF_MASK		BIT(12)
#define _ICR_EOBCF_SHIFT	12
#define _ICR_UDRCF_MASK		BIT(13)
#define _ICR_UDRCF_SHIFT	13
#define _ICR_CMCF_MASK		BIT(17)
#define _ICR_CMCF_SHIFT		17
#define _ICR_WUCF_MASK		BIT(20)
#define _ICR_WUCF_SHIFT		20

/* USART_RDR register fields */
#define _RDR_RDR_MASK		GENMASK_32(8, 0)
#define _RDR_RDR_SHIFT		0

/* USART_TDR register fields */
#define _TDR_TDR_MASK		GENMASK_32(8, 0)
#define _TDR_TDR_SHIFT		0

/* USART_PRESC register fields */
#define _PRESC_PRESCALER_MASK	GENMASK_32(3, 0)
#define _PRESC_PRESCALER_SHIFT	0

#define UART_CR1_FIELDS \
		(_CR1_M0_MASK | _CR1_M1_MASK | _CR1_PCE_MASK | \
		 _CR1_PS_MASK | _CR1_TE_MASK | _CR1_RE_MASK | \
		 _CR1_OVER8_MASK | _CR1_FIFOEN_MASK)

/*
 * LINEN, CLKEN (CR2) and SCEN, HDSEL, IREN (CR3) are part of the fields
 * so that they are kept cleared, as required in asynchronous mode.
 */
#define UART_CR2_FIELDS \
		(_CR2_STOP_MASK | _CR2_LINEN_MASK | _CR2_CLKEN_MASK)

#define UART_CR3_FIELDS \
		(_CR3_RTSE_MASK | _CR3_CTSE_MASK | _CR3_ONEBIT_MASK | \
		 _CR3_TXFTCFG_MASK | _CR3_RXFTCFG_MASK | \
		 _CR3_SCEN_MASK | _CR3_HDSEL_MASK | _CR3_IREN_MASK)

#define UART_ICR_ERRORS	 \
		(_ICR_PECF_MASK | _ICR_FECF_MASK | \
		 _ICR_NECF_MASK | _ICR_ORECF_MASK)

/* UART word length (CR1 M[1:0]) */
#define UART_WORDLENGTH_7B			_CR1_M1_MASK
#define UART_WORDLENGTH_8B			0x00000000U
#define UART_WORDLENGTH_9B			_CR1_M0_MASK

/* UART number of stop bits (CR2 STOP[1:0]) */
#define UART_STOPBITS_0_5			_FLD_PREP(_CR2_STOP, 1U)
#define UART_STOPBITS_1				_FLD_PREP(_CR2_STOP, 0U)
#define UART_STOPBITS_1_5			_FLD_PREP(_CR2_STOP, 3U)
#define UART_STOPBITS_2				_FLD_PREP(_CR2_STOP, 2U)

/* UART parity (CR1 PCE and PS) */
#define UART_PARITY_NONE			0x00000000U
#define UART_PARITY_EVEN			_CR1_PCE_MASK
#define UART_PARITY_ODD				(_CR1_PCE_MASK | _CR1_PS_MASK)

/* UART hardware flow control (CR3 RTSE and CTSE) */
#define UART_HWCONTROL_NONE			0x00000000U
#define UART_HWCONTROL_RTS			_CR3_RTSE_MASK
#define UART_HWCONTROL_CTS			_CR3_CTSE_MASK
#define UART_HWCONTROL_RTS_CTS			(UART_HWCONTROL_RTS | UART_HWCONTROL_CTS)

/* UART prescaler (PRESC PRESCALER[3:0]) */
#define UART_PRESCALER_DIV1			0x0U
#define UART_PRESCALER_DIV256			0xBU
#define UART_PRESCALER_MAX			UART_PRESCALER_DIV256

/* UART One Bit Sampling Method (CR3 ONEBIT) */
#define UART_ONE_BIT_SAMPLE_DISABLE		0x00000000U
#define UART_ONE_BIT_SAMPLE_ENABLE		_CR3_ONEBIT_MASK

/* UART polling-based communications time-out value */
#define UART_TIMEOUT_US				20000U

/*
 * Image of the USART configuration registers. CR1, CR2, CR3 and PRESC are
 * applied on the fields defined by UART_CRx_FIELDS and _PRESC_PRESCALER,
 * BRR is fully written.
 */
struct stm32_reg_config {
	uint32_t cr1;
	uint32_t cr2;
	uint32_t cr3;
	uint32_t presc;
	uint32_t brr;
};

struct stm32_uart_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct pinctrl_dev_config *pcfg;
};

struct stm32_uart_data {
	struct uart_config uart_config;
	struct clk *clk;
};

static const uint16_t presc_table[UART_PRESCALER_MAX + 1] = {
	1U, 2U, 4U, 6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U
};

/******************************************************************************/
/*
 * @brief  Check if the data frame is 9 bits without parity, i.e. if 2 bytes
 *         of the buffer are used per data frame.
 * @param  uart_cfg: UART configuration.
 * @retval true if 9 bits without parity, false otherwise.
 */
static bool _stm32_uart_is_9b_no_parity(const struct uart_config *uart_cfg)
{
	return (uart_cfg->data_bits == UART_CFG_DATA_BITS_9) &&
	       (uart_cfg->parity == UART_CFG_PARITY_NONE);
}

/*
 * @brief  Compute RDR register mask depending on word length.
 * @param  uart_cfg: UART configuration.
 * @retval Mask value.
 */
static unsigned int _stm32_uart_mask_computation(const struct uart_config *uart_cfg)
{
	unsigned int mask;

	switch (uart_cfg->data_bits) {
	case UART_CFG_DATA_BITS_9:
		mask = GENMASK(8, 0);
		break;
	case UART_CFG_DATA_BITS_8:
		mask = GENMASK(7, 0);
		break;
	case UART_CFG_DATA_BITS_7:
		mask = GENMASK(6, 0);
		break;
	default:
		return 0U;
	}

	if (uart_cfg->parity != UART_CFG_PARITY_NONE) {
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
				_CR1_RXNEIE_MASK | _CR1_PEIE_MASK |
				_CR1_TXEIE_MASK);
		mmio_clrbits_32(drv_cfg->base + _USART_CR3, _CR3_EIE_MASK);
		/* Clear all error flags */
		mmio_write_32(drv_cfg->base + _USART_ICR, UART_ICR_ERRORS);
	}

	return err;
}

static uint32_t _stm32_uart_check_idle_state(const struct device *dev)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);

	/* Check if the transmitter is enabled */
	if (_FLD_GET(_CR1_TE, mmio_read_32(drv_cfg->base + _USART_CR1)) &&
	    (_stm32_uart_wait_flag(dev, _ISR_TEACK_MASK, UART_TIMEOUT_US))) {
		return -ETIMEDOUT;
	}

	/* Check if the receiver is enabled */
	if (_FLD_GET(_CR1_RE, mmio_read_32(drv_cfg->base + _USART_CR1)) &&
	    (_stm32_uart_wait_flag(dev, _ISR_REACK_MASK, UART_TIMEOUT_US))) {
		return -ETIMEDOUT;
	}

	return 0;
}

/*
 * @brief  Compute BRR value from the UART kernel clock, the baud rate and
 *         the already computed oversampling (CR1) and prescaler (PRESC).
 * @param  dev: device reference.
 * @param  baud_rate: baud rate.
 * @param  reg_cfg: USART registers configuration to complete.
 * @retval 0 on success, negative errno otherwise.
 */
static int _stm32_uart_brr_cfg(const struct device *dev, uint32_t baud_rate,
			       struct stm32_reg_config *reg_cfg)
{
	uint32_t presc = _FLD_GET(_PRESC_PRESCALER, reg_cfg->presc);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	bool over8 = (reg_cfg->cr1 & _CR1_OVER8_MASK) != 0U;
	unsigned long clockfreq;
	uint32_t scaled_freq;
	uint32_t fraction;
	uint16_t usartdiv;

	_ASSERT(presc <= UART_PRESCALER_MAX);

	clockfreq = clk_get_rate(drv_data->clk);
	if (clockfreq == 0UL)
		return -EINVAL;

	scaled_freq = clockfreq / presc_table[presc];
	scaled_freq *= (over8 ? 2U : 1U);

	usartdiv = (uint16_t)((scaled_freq + (baud_rate / 2U)) / baud_rate);

	fraction = _FLD_GET(_BRR_DIV_FRACTION, usartdiv);
	fraction >>= (over8 ? 1U : 0U);

	reg_cfg->brr = _FLD_PREP(_BRR_DIV_MANTISSA, _FLD_GET(_BRR_DIV_MANTISSA, usartdiv));
	reg_cfg->brr |= _FLD_PREP(_BRR_DIV_FRACTION, fraction);

	return 0;
}

static int _stm32_uart_databits_cfg(const struct uart_config *uart_cfg,
				    struct stm32_reg_config *reg_cfg)
{
	switch (uart_cfg->data_bits) {
	case UART_CFG_DATA_BITS_7:
		reg_cfg->cr1 |= UART_WORDLENGTH_7B;
		break;

	case UART_CFG_DATA_BITS_8:
		reg_cfg->cr1 |= UART_WORDLENGTH_8B;
		break;

	case UART_CFG_DATA_BITS_9:
		reg_cfg->cr1 |= UART_WORDLENGTH_9B;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static int _stm32_uart_parity_cfg(const struct uart_config *uart_cfg,
				  struct stm32_reg_config *reg_cfg)
{
	switch (uart_cfg->parity) {
	case UART_CFG_PARITY_NONE:
		reg_cfg->cr1 |= UART_PARITY_NONE;
		break;

	case UART_CFG_PARITY_EVEN:
		reg_cfg->cr1 |= UART_PARITY_EVEN;
		break;

	case UART_CFG_PARITY_ODD:
		reg_cfg->cr1 |= UART_PARITY_ODD;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static int _stm32_uart_stopbits_cfg(const struct uart_config *uart_cfg,
				    struct stm32_reg_config *reg_cfg)
{
	switch (uart_cfg->stop_bits) {
	case UART_CFG_STOP_BITS_0_5:
		reg_cfg->cr2 |= UART_STOPBITS_0_5;
		break;

	case UART_CFG_STOP_BITS_1:
		reg_cfg->cr2 |= UART_STOPBITS_1;
		break;

	case UART_CFG_STOP_BITS_1_5:
		reg_cfg->cr2 |= UART_STOPBITS_1_5;
		break;

	case UART_CFG_STOP_BITS_2:
		reg_cfg->cr2 |= UART_STOPBITS_2;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

static int _stm32_uart_hwcontrol_cfg(const struct uart_config *uart_cfg,
				     struct stm32_reg_config *reg_cfg)
{
	switch (uart_cfg->flow_ctrl) {
	case UART_CFG_FLOW_CTRL_NONE:
		reg_cfg->cr3 |= UART_HWCONTROL_NONE;
		break;

	case UART_CFG_FLOW_CTRL_RTS_CTS:
		reg_cfg->cr3 |= UART_HWCONTROL_RTS_CTS;
		break;

	default:
		return -ENOTSUP;
	}

	return 0;
}

/*
 * @brief  Compute the USART registers configuration from a UART configuration.
 *         The hardware is not accessed.
 * @param  dev: device reference.
 * @param  uart_cfg: UART configuration.
 * @param  reg_cfg: computed USART registers configuration.
 * @retval 0 on success, negative errno otherwise.
 */
static int _stm32_uart_compute_reg_cfg(const struct device *dev,
				       const struct uart_config *uart_cfg,
				       struct stm32_reg_config *reg_cfg)
{
	/*
	 * Fixme: set dynamicaly by dt...
	 * - CR1: TE and RE enabled, oversampling by 8, FIFO disabled,
	 * - CR3: one-bit sampling disabled, no FIFO thresholds,
	 * - PRESC: kernel clock not divided.
	 */
	reg_cfg->cr1 = _CR1_TE_MASK | _CR1_RE_MASK | _CR1_OVER8_MASK;
	reg_cfg->cr2 = 0U;
	reg_cfg->cr3 = UART_ONE_BIT_SAMPLE_DISABLE;
	reg_cfg->presc = _FLD_PREP(_PRESC_PRESCALER, UART_PRESCALER_DIV1);
	reg_cfg->brr = 0U;

	if (_stm32_uart_databits_cfg(uart_cfg, reg_cfg) ||
	    _stm32_uart_parity_cfg(uart_cfg, reg_cfg) ||
	    _stm32_uart_stopbits_cfg(uart_cfg, reg_cfg) ||
	    _stm32_uart_hwcontrol_cfg(uart_cfg, reg_cfg)) {
		return -ENOTSUP;
	}

	return _stm32_uart_brr_cfg(dev, uart_cfg->baudrate, reg_cfg);
}

/*
 * @brief  Write the USART registers configuration to the peripheral.
 *         The peripheral must be disabled (UE = 0).
 * @param  dev: device reference.
 * @param  reg_cfg: USART registers configuration.
 */
static void _stm32_uart_apply_reg_cfg(const struct device *dev,
				      const struct stm32_reg_config *reg_cfg)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);

	mmio_clrsetbits_32(drv_cfg->base + _USART_CR1, UART_CR1_FIELDS, reg_cfg->cr1);
	mmio_clrsetbits_32(drv_cfg->base + _USART_CR2, UART_CR2_FIELDS, reg_cfg->cr2);
	mmio_clrsetbits_32(drv_cfg->base + _USART_CR3, UART_CR3_FIELDS, reg_cfg->cr3);
	mmio_clrsetbits_32(drv_cfg->base + _USART_PRESC, _PRESC_PRESCALER_MASK, reg_cfg->presc);
	mmio_write_32(drv_cfg->base + _USART_BRR, reg_cfg->brr);
}

static int stm32_uart_configure(const struct device *dev,
				const struct uart_config *uart_cfg)
{
	const struct stm32_uart_config *drv_cfg = dev_get_config(dev);
	struct stm32_uart_data *drv_data = dev_get_data(dev);
	struct stm32_reg_config reg_cfg;
	int err;

	err = _stm32_uart_compute_reg_cfg(dev, uart_cfg, &reg_cfg);
	if (err)
		return err;

	/* Disable and clear all error flags of peripheral */
	mmio_clrbits_32(drv_cfg->base + _USART_CR1, _CR1_UE_MASK);
	mmio_write_32(drv_cfg->base + _USART_ICR, UART_ICR_ERRORS);

	_stm32_uart_apply_reg_cfg(dev, &reg_cfg);

	/* Enable the peripheral */
	mmio_setbits_32(drv_cfg->base + _USART_CR1, _CR1_UE_MASK);

	err = _stm32_uart_check_idle_state(dev);
	if (err)
		goto err_check;

	memcpy(&drv_data->uart_config, uart_cfg, sizeof(*uart_cfg));

	return 0;

err_check:
	/* Disable the peripheral */
	mmio_clrbits_32(drv_cfg->base + _USART_CR1, _CR1_UE_MASK);
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
		if (_stm32_uart_wait_flag(dev, _ISR_TXE_MASK, timeout))
			return -EBUSY;

		if (_stm32_uart_is_9b_no_parity(&drv_data->uart_config)) {
			uint16_t data = (uint16_t)*(buf + count) |
					(uint16_t)(*(buf + count + 1) << 8);

			mmio_write_16(drv_cfg->base + _USART_TDR, _FLD_PREP(_TDR_TDR, data));
			count += 2U;
		} else {
			mmio_write_8(drv_cfg->base + _USART_TDR, (*(buf + count) & GENMASK(7, 0)));
			count++;
		}
	}

	if (_stm32_uart_wait_flag(dev, _ISR_TC_MASK, timeout))
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
	uhmask = _stm32_uart_mask_computation(&drv_data->uart_config);

	while (rx_xfer_count > 0U) {
		rx_xfer_count--;
		if (_stm32_uart_wait_flag(dev, _ISR_RXNE_MASK, timeout))
			return -EBUSY;

		if (_stm32_uart_is_9b_no_parity(&drv_data->uart_config)) {
			uint16_t data = _FLD_GET(_RDR_RDR,
						 mmio_read_16(drv_cfg->base + _USART_RDR)) & uhmask;

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
				       (value & _ISR_RXNE_MASK), timeout_us);

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
