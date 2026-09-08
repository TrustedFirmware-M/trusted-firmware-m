/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_i2c

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <lib/timeout.h>
#include <inttypes.h>

#include <device.h>
#include <pm/device.h>
#include <clk.h>
#include <i2c.h>
#include <pinctrl.h>
#include <reset.h>

#include "i2c-priv.h"

/* STM32 I2C registers offsets */
#define _I2C_CR1			0x00U
#define _I2C_CR2			0x04U
#define _I2C_OAR1			0x08U
#define _I2C_OAR2			0x0CU
#define _I2C_TIMINGR			0x10U
#define _I2C_TIMEOUTR			0x14U
#define _I2C_ISR			0x18U
#define _I2C_ICR			0x1CU
#define _I2C_PECR			0x20U
#define _I2C_RXDR			0x24U
#define _I2C_TXDR			0x28U
#define _I2C_SIZE			0x2CU

/* Bit definition for _I2C_CR1 register */
#define _I2C_CR1_PE			BIT(0)
#define _I2C_CR1_TXIE			BIT(1)
#define _I2C_CR1_RXIE			BIT(2)
#define _I2C_CR1_ADDRIE			BIT(3)
#define _I2C_CR1_NACKIE			BIT(4)
#define _I2C_CR1_STOPIE			BIT(5)
#define _I2C_CR1_TCIE			BIT(6)
#define _I2C_CR1_ERRIE			BIT(7)
#define _I2C_CR1_DNF			GENMASK_32(11, 8)
#define _I2C_CR1_ANFOFF			BIT(12)
#define _I2C_CR1_SWRST			BIT(13)
#define _I2C_CR1_TXDMAEN		BIT(14)
#define _I2C_CR1_RXDMAEN		BIT(15)
#define _I2C_CR1_SBC			BIT(16)
#define _I2C_CR1_NOSTRETCH		BIT(17)
#define _I2C_CR1_WUPEN			BIT(18)
#define _I2C_CR1_GCEN			BIT(19)
#define _I2C_CR1_SMBHEN			BIT(22)
#define _I2C_CR1_SMBDEN			BIT(21)
#define _I2C_CR1_ALERTEN		BIT(22)
#define _I2C_CR1_PECEN			BIT(23)

/* Bit definition for _I2C_CR2 register */
#define _I2C_CR2_SADD10_MASK		GENMASK_32(9, 0)
#define _I2C_CR2_SADD10_SHIFT		0
#define _I2C_CR2_SADD7_MASK		GENMASK_32(7, 1)
#define _I2C_CR2_SADD7_SHIFT		1
#define _I2C_CR2_RD_WRN_MASK		BIT(10)
#define _I2C_CR2_RD_WRN_SHIFT		10
#define _I2C_CR2_ADD10_MASK		BIT(11)
#define _I2C_CR2_ADD10_SHIFT		11
#define _I2C_CR2_HEAD10R_MASK		BIT(12)
#define _I2C_CR2_HEAD10R_SHIFT		12
#define _I2C_CR2_START_MASK		BIT(13)
#define _I2C_CR2_START_SHIFT		13
#define _I2C_CR2_STOP_MASK		BIT(14)
#define _I2C_CR2_STOP_SHIFT		14
#define _I2C_CR2_NACK_MASK		BIT(15)
#define _I2C_CR2_NACK_SHIFT		15
#define _I2C_CR2_NBYTES_MASK		GENMASK_32(23, 16)
#define _I2C_CR2_NBYTES_SHIFT		16
#define _I2C_CR2_RELOAD_MASK		BIT(24)
#define _I2C_CR2_RELOAD_SHIFT		24
#define _I2C_CR2_AUTOEND_MASK		BIT(25)
#define _I2C_CR2_AUTOEND_SHIFT		25
#define _I2C_CR2_PECBYTE_MASK		BIT(26)
#define _I2C_CR2_PECBYTE_SHIFT		26


/* Bit definition for _I2C_OAR1 register */
#define _I2C_OAR1_OA1			GENMASK_32(9, 0)
#define _I2C_OAR1_OA1MODE		BIT(10)
#define _I2C_OAR1_OA1EN			BIT(15)

/* Bit definition for _I2C_OAR2 register */
#define _I2C_OAR2_OA2			GENMASK_32(7, 1)
#define _I2C_OAR2_OA2MSK		GENMASK_32(10, 8)
#define _I2C_OAR2_OA2NOMASK		0
#define _I2C_OAR2_OA2MASK01		BIT(8)
#define _I2C_OAR2_OA2MASK02		BIT(9)
#define _I2C_OAR2_OA2MASK03		GENMASK_32(9, 8)
#define _I2C_OAR2_OA2MASK04		BIT(10)
#define _I2C_OAR2_OA2MASK05		(BIT(8) | BIT(10))
#define _I2C_OAR2_OA2MASK06		(BIT(9) | BIT(10))
#define _I2C_OAR2_OA2MASK07		GENMASK_32(10, 8)
#define _I2C_OAR2_OA2EN			BIT(15)

/* Bit definition for _I2C_TIMINGR register */
#define _I2C_TIMINGR_SCLL		GENMASK_32(7, 0)
#define _I2C_TIMINGR_SCLH		GENMASK_32(15, 8)
#define _I2C_TIMINGR_SDADEL		GENMASK_32(19, 16)
#define _I2C_TIMINGR_SCLDEL		GENMASK_32(23, 20)
#define _I2C_TIMINGR_PRESC		GENMASK_32(31, 28)
#define _I2C_TIMINGR_SCLL_MAX		(_I2C_TIMINGR_SCLL + 1)
#define _I2C_TIMINGR_SCLH_MAX		((_I2C_TIMINGR_SCLH >> 8) + 1)
#define _I2C_TIMINGR_SDADEL_MAX		((_I2C_TIMINGR_SDADEL >> 16) + 1)
#define _I2C_TIMINGR_SCLDEL_MAX		((_I2C_TIMINGR_SCLDEL >> 20) + 1)
#define _I2C_TIMINGR_PRESC_MAX		((_I2C_TIMINGR_PRESC >> 28) + 1)
#define _I2C_SET_TIMINGR_SCLL(n)	((n) & \
					 (_I2C_TIMINGR_SCLL_MAX - 1))
#define _I2C_SET_TIMINGR_SCLH(n)	(((n) & \
					  (_I2C_TIMINGR_SCLH_MAX - 1)) << 8)
#define _I2C_SET_TIMINGR_SDADEL(n)	(((n) & \
					  (_I2C_TIMINGR_SDADEL_MAX - 1)) << 16)
#define _I2C_SET_TIMINGR_SCLDEL(n)	(((n) & \
					  (_I2C_TIMINGR_SCLDEL_MAX - 1)) << 20)
#define _I2C_SET_TIMINGR_PRESC(n)	(((n) & \
					  (_I2C_TIMINGR_PRESC_MAX - 1)) << 28)

/* Bit definition for _I2C_TIMEOUTR register */
#define _I2C_TIMEOUTR_TIMEOUTA		GENMASK_32(11, 0)
#define _I2C_TIMEOUTR_TIDLE		BIT(12)
#define _I2C_TIMEOUTR_TIMOUTEN		BIT(15)
#define _I2C_TIMEOUTR_TIMEOUTB		GENMASK_32(27, 16)
#define _I2C_TIMEOUTR_TEXTEN		BIT(31)

/* Bit definition for _I2C_ISR register */
#define _I2C_ISR_TXE			BIT(0)
#define _I2C_ISR_TXIS			BIT(1)
#define _I2C_ISR_RXNE			BIT(2)
#define _I2C_ISR_ADDR			BIT(3)
#define _I2C_ISR_NACKF			BIT(4)
#define _I2C_ISR_STOPF			BIT(5)
#define _I2C_ISR_TC			BIT(6)
#define _I2C_ISR_TCR			BIT(7)
#define _I2C_ISR_BERR			BIT(8)
#define _I2C_ISR_ARLO			BIT(9)
#define _I2C_ISR_OVR			BIT(10)
#define _I2C_ISR_PECERR			BIT(11)
#define _I2C_ISR_TIMEOUT		BIT(12)
#define _I2C_ISR_ALERT			BIT(13)
#define _I2C_ISR_BUSY			BIT(15)
#define _I2C_ISR_DIR			BIT(16)
#define _I2C_ISR_ADDCODE		GENMASK_32(23, 17)

/* Bit definition for _I2C_ICR register */
#define _I2C_ICR_ADDRCF			BIT(3)
#define _I2C_ICR_NACKCF			BIT(4)
#define _I2C_ICR_STOPCF			BIT(5)
#define _I2C_ICR_BERRCF			BIT(8)
#define _I2C_ICR_ARLOCF			BIT(9)
#define _I2C_ICR_OVRCF			BIT(10)
#define _I2C_ICR_PECCF			BIT(11)
#define _I2C_ICR_TIMOUTCF		BIT(12)
#define _I2C_ICR_ALERTCF		BIT(13)

/* Max data size for a single I2C transfer */
#define MAX_NBYTE_SIZE			255U

#define I2C_TIMEOUT_BUSY_MS		25
#define I2C_TIMEOUT_BUSY_US		(I2C_TIMEOUT_BUSY_MS * 1000)
#define I2C_TIMEOUT_RXNE_MS		5

#define TIMINGR_CLEAR_MASK		(_I2C_TIMINGR_SCLL | _I2C_TIMINGR_SCLH | \
					 _I2C_TIMINGR_SDADEL | \
					 _I2C_TIMINGR_SCLDEL | _I2C_TIMINGR_PRESC)

/* Effective rate cannot be lower than 80% target rate */
#define RATE_MIN(rate)			(((rate) * 80U) / 100U)

#define STM32_I2C_ANALOG_FILTER_DELAY_MIN	U(50)	/* ns */
#define STM32_I2C_ANALOG_FILTER_DELAY_MAX	U(260)	/* ns */
#define STM32_I2C_DIGITAL_FILTER_MAX		U(16)
/*
 * struct i2c_spec_s - Private I2C timing specifications.
 * @rate: I2C bus speed (Hz)
 * @fall_max: Max fall time of both SDA and SCL signals (ns)
 * @rise_max: Max rise time of both SDA and SCL signals (ns)
 * @hddat_min: Min data hold time (ns)
 * @vddat_max: Max data valid time (ns)
 * @sudat_min: Min data setup time (ns)
 * @l_min: Min low period of the SCL clock (ns)
 * @h_min: Min high period of the SCL clock (ns)
 */
struct i2c_spec_s {
	uint32_t rate;
	uint32_t fall_max;
	uint32_t rise_max;
	uint32_t hddat_min;
	uint32_t vddat_max;
	uint32_t sudat_min;
	uint32_t l_min;
	uint32_t h_min;
};

/*
 * struct i2c_timing_s - Private I2C output parameters.
 * @scldel: Data setup time
 * @sdadel: Data hold time
 * @sclh: SCL high period (master mode)
 * @sclh: SCL low period (master mode)
 * @is_saved: True if relating to a configuration candidate
 */
struct i2c_timing_s {
	uint8_t scldel;
	uint8_t sdadel;
	uint8_t sclh;
	uint8_t scll;
	bool is_saved;
};

/* This table must be sorted in increasing value for field @rate */
static const struct i2c_spec_s i2c_specs[] = {
	/* Standard - 100KHz */
	{
		.rate = I2C_BITRATE_STANDARD,
		.fall_max = 300,
		.rise_max = 1000,
		.hddat_min = 0,
		.vddat_max = 3450,
		.sudat_min = 250,
		.l_min = 4700,
		.h_min = 4000,
	},
	/* Fast - 400KHz */
	{
		.rate = I2C_BITRATE_FAST,
		.fall_max = 300,
		.rise_max = 300,
		.hddat_min = 0,
		.vddat_max = 900,
		.sudat_min = 100,
		.l_min = 1300,
		.h_min = 600,
	},
	/* FastPlus - 1MHz */
	{
		.rate = I2C_BITRATE_FAST_PLUS,
		.fall_max = 100,
		.rise_max = 120,
		.hddat_min = 0,
		.vddat_max = 450,
		.sudat_min = 50,
		.l_min = 500,
		.h_min = 260,
	},
};

static const struct i2c_spec_s *get_specs(uint32_t rate)
{
	size_t i = 0;

	for (i = 0; i < ARRAY_SIZE(i2c_specs); i++)
		if (rate <= i2c_specs[i].rate)
			return i2c_specs + i;

	return NULL;
}

struct stm32_i2c_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct pinctrl_dev_config *pcfg;
	const struct reset_control rst_ctl;
	uint32_t bitrate;
	uint32_t rise_time;
	uint32_t fall_time;
	bool analog_filter;
};

struct stm32_i2c_data {
	struct clk *clk;
	uint32_t bitrate;
	uint32_t bitrate_saved;
	uint32_t frequency_saved;
	uint32_t timing_saved;
	uint8_t digital_filter_coef;
	uint32_t i2c_config;
};

static uint32_t _stm32_i2c_wait_flag(const struct device *dev, uint32_t flag,
				     uint64_t timeout_us)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	uint32_t value;

	return  mmio_read32_poll_timeout(drv_cfg->base + _I2C_ISR, value,
					 (value & flag), timeout_us);
}

static uint32_t _stm32_i2c_wait_busy(const struct device *dev,
				     uint64_t timeout_us)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	uint32_t value;

	return  mmio_read32_poll_timeout(drv_cfg->base + _I2C_ISR, value,
					 !(value & _I2C_ISR_BUSY), timeout_us);
}

static void _stm32_i2c_msg_init(const struct device *dev, struct i2c_msg *msg,
				uint8_t flags_next_msg, uint16_t addr)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	uint32_t clr_value, set_value = 0;

	if (mmio_read_32(drv_cfg->base + _I2C_CR2) & _I2C_CR2_RELOAD_MASK) {
		clr_value = _I2C_CR2_NBYTES_MASK;
	} else {
		clr_value = (_I2C_CR2_SADD10_MASK | _I2C_CR2_HEAD10R_MASK |
			     _I2C_CR2_RD_WRN_MASK | _I2C_CR2_ADD10_MASK |
			     _I2C_CR2_NBYTES_MASK | _I2C_CR2_RELOAD_MASK |
			     _I2C_CR2_AUTOEND_MASK);

		if (drv_data->i2c_config & I2C_ADDR_10_BITS) {
			set_value = _I2C_CR2_ADD10_MASK;
			set_value |= _FLD_PREP(_I2C_CR2_SADD10, addr);
		} else {
			set_value = _FLD_PREP(_I2C_CR2_SADD7, addr);
		}

		if (!(msg->flags & I2C_MSG_STOP) &&
		    !(flags_next_msg & I2C_MSG_RESTART))
			set_value |= _I2C_CR2_RELOAD_MASK;

		if (msg->flags & I2C_MSG_READ)
			set_value |= _I2C_CR2_RD_WRN_MASK;

		set_value |= _I2C_CR2_START_MASK;
	}

	set_value |= _FLD_PREP(_I2C_CR2_NBYTES, msg->len);

	mmio_clrsetbits_32(drv_cfg->base + _I2C_CR2, clr_value, set_value);
}

static int _stm32_i2c_msg_done(const struct device *dev, struct i2c_msg *msg)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	int err;

	err = _stm32_i2c_wait_flag(dev, (_I2C_ISR_TC | _I2C_ISR_TCR),
				   I2C_TIMEOUT_BUSY_US);
	if (err)
		return err;

	if (msg->flags & I2C_MSG_STOP) {
		mmio_setbits_32(drv_cfg->base + _I2C_CR2, _I2C_CR2_STOP_MASK);

		err = _stm32_i2c_wait_flag(dev, (_I2C_ISR_STOPF),
					   I2C_TIMEOUT_BUSY_US);
		if (err)
			return err;
	}

	return 0;
}

static int _stm32_i2c_xfer_msg(const struct device *dev, struct i2c_msg *msg,
			       uint8_t flags_next_msg, uint16_t addr)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	uint8_t *buf = msg->buf;
	int len = msg->len;
	uint32_t isr_mask;
	int err;

	isr_mask = msg->flags & I2C_MSG_READ ? _I2C_ISR_RXNE :
		_I2C_ISR_TXIS | _I2C_ISR_NACKF;

	_stm32_i2c_msg_init(dev, msg, flags_next_msg, addr);

	for (; len > 0; len--, buf++) {
		err = _stm32_i2c_wait_flag(dev, isr_mask, I2C_TIMEOUT_BUSY_US);
		if (err)
			goto out;

		if (msg->flags & I2C_MSG_READ)
			*buf = mmio_read_8(drv_cfg->base + _I2C_RXDR);
		else
			mmio_write_8(drv_cfg->base + _I2C_TXDR, *buf);
	}

	err = _stm32_i2c_msg_done(dev, msg);
out:
	return err;
}

static int _stm32_i2c_transaction(const struct device *dev, struct i2c_msg *msg,
				  uint8_t flags_next_msg, uint16_t addr)
{
	const uint8_t flags_saved = msg->flags;
	uint8_t flags_next;
	uint32_t rest = msg->len;
	int err = 0;

	while (rest) {
		if (msg->len > MAX_NBYTE_SIZE) {
			msg->len = MAX_NBYTE_SIZE;
			msg->flags &= ~I2C_MSG_STOP;
			flags_next = msg->flags & ~(I2C_MSG_RESTART);
		} else {
			msg->flags = flags_saved;
			flags_next = flags_next_msg;
		}

		err = _stm32_i2c_xfer_msg(dev, msg, flags_next, addr);
		if (err)
			break;

		rest -= msg->len;
		msg->buf += msg->len;
		msg->len = rest;
	}

	return err;
}

/*
 * Compute the I2C device timings
 *
 * @dev: Ref to device structure
 * @clock_src: I2C clock source frequency (Hz)
 * @timing: Pointer to the final computed timing result
 * Return 0 on success or a negative value
 */
static int i2c_compute_timing(const struct device *dev,
			      unsigned long clock_src, uint32_t *timing)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	const struct i2c_spec_s *specs = NULL;
	uint32_t speed_freq, i2cbus, i2cclk;
	uint32_t p_prev = _I2C_TIMINGR_PRESC_MAX;
	uint32_t dnf_delay, tsync;
	uint32_t clk_max, clk_min;
	uint32_t af_delay_min = 0, af_delay_max = 0;
	int sdadel_min, scldel_min, sdadel_max;
	int clk_error_prev = INT_MAX;
	uint32_t sdadel_min_u, sdadel_max_u;
	uint16_t p = 0, l = 0, a = 0, h = 0;
	struct i2c_timing_s solutions[_I2C_TIMINGR_PRESC_MAX];
	int s = -EINVAL;

	specs = get_specs(drv_data->bitrate);
	if (!specs) {
		DMSG("I2C speed out of bound: %dHz\n", drv_data->bitrate);
		return -EINVAL;
	}

	speed_freq = specs->rate;
	i2cbus = div_round_closest(NSEC_PER_SEC, speed_freq);
	i2cclk = div_round_closest(NSEC_PER_SEC, clock_src);

	if (drv_cfg->rise_time > specs->rise_max ||
	    drv_cfg->fall_time > specs->fall_max) {
		DMSG("I2C rise{%d>%d}/fall{%d>%d}\n",
		     drv_cfg->rise_time, specs->rise_max,
		     drv_cfg->fall_time, specs->fall_max);
		return -EINVAL;
	}

	if (drv_data->digital_filter_coef > STM32_I2C_DIGITAL_FILTER_MAX) {
		DMSG("I2C DNF out of bound %d/%d\n",
		     drv_data->digital_filter_coef,
		     STM32_I2C_DIGITAL_FILTER_MAX);
		return -EINVAL;
	}

	/* Analog and Digital Filters */
	if (drv_cfg->analog_filter) {
		af_delay_min = STM32_I2C_ANALOG_FILTER_DELAY_MIN;
		af_delay_max = STM32_I2C_ANALOG_FILTER_DELAY_MAX;
	}

	dnf_delay = drv_data->digital_filter_coef * i2cclk;

	sdadel_min = specs->hddat_min + drv_cfg->fall_time - af_delay_min -
		((drv_data->digital_filter_coef + 3) * i2cclk);

	sdadel_max = specs->vddat_max - drv_cfg->rise_time - af_delay_max -
		((drv_data->digital_filter_coef + 4) * i2cclk);

	scldel_min = drv_cfg->rise_time + specs->sudat_min;

	if (sdadel_min < 0)
		sdadel_min_u = 0;
	else
		sdadel_min_u = (uint32_t)sdadel_min;

	if (sdadel_max < 0)
		sdadel_max_u = 0;
	else
		sdadel_max_u = (uint32_t)sdadel_max;

	DMSG("I2C SDADEL(min/max): %d/%d, SCLDEL(Min): %d\n",
		sdadel_min_u, sdadel_max_u, scldel_min);

	memset(&solutions,0, sizeof(solutions));

	/* Compute possible values for PRESC, SCLDEL and SDADEL */
	for (p = 0; p < _I2C_TIMINGR_PRESC_MAX; p++) {
		for (l = 0; l < _I2C_TIMINGR_SCLDEL_MAX; l++) {
			uint32_t scldel = (l + 1) * (p + 1) * i2cclk;

			if (scldel < scldel_min)
				continue;

			for (a = 0; a < _I2C_TIMINGR_SDADEL_MAX; a++) {
				uint32_t sdadel = (a * (p + 1) + 1) * i2cclk;

				if ((sdadel >= sdadel_min_u) &&
				    (sdadel <= sdadel_max_u) &&
				    (p != p_prev)) {
					solutions[p].scldel = l;
					solutions[p].sdadel = a;
					solutions[p].is_saved = true;
					p_prev = p;
					break;
				}
			}

			if (p_prev == p)
				break;
		}
	}

	if (p_prev == _I2C_TIMINGR_PRESC_MAX) {
		DMSG("I2C no Prescaler solution\n");
		return -EINVAL;
	}

	tsync = af_delay_min + dnf_delay + (2 * i2cclk);
	clk_max = NSEC_PER_SEC / RATE_MIN(specs->rate);
	clk_min = NSEC_PER_SEC / specs->rate;

	/*
	 * Among prescaler possibilities discovered above figures out SCL Low
	 * and High Period. Provided:
	 * - SCL Low Period has to be higher than Low Period of the SCL Clock
	 *   defined by I2C Specification. I2C Clock has to be lower than
	 *   (SCL Low Period - Analog/Digital filters) / 4.
	 * - SCL High Period has to be lower than High Period of the SCL Clock
	 *   defined by I2C Specification.
	 * - I2C Clock has to be lower than SCL High Period.
	 */
	for (p = 0; p < _I2C_TIMINGR_PRESC_MAX; p++) {
		uint32_t prescaler = (p + 1) * i2cclk;

		if (!solutions[p].is_saved)
			continue;

		for (l = 0; l < _I2C_TIMINGR_SCLL_MAX; l++) {
			uint32_t tscl_l = ((l + 1) * prescaler) + tsync;

			if (tscl_l < specs->l_min ||
			    i2cclk >= ((tscl_l - af_delay_min - dnf_delay) / 4))
				continue;

			for (h = 0; h < _I2C_TIMINGR_SCLH_MAX; h++) {
				uint32_t tscl_h = ((h + 1) * prescaler) + tsync;
				uint32_t tscl = tscl_l + tscl_h +
						drv_cfg->rise_time +
						drv_cfg->fall_time;

				if (tscl >= clk_min && tscl <= clk_max &&
				    tscl_h >= specs->h_min && i2cclk < tscl_h) {
					int clk_error = tscl - i2cbus;

					if (clk_error < 0)
						clk_error = -clk_error;

					if (clk_error < clk_error_prev) {
						clk_error_prev = clk_error;
						solutions[p].scll = l;
						solutions[p].sclh = h;
						s = p;
					}
				}
			}
		}
	}

	if (s < 0) {
		DMSG("I2C no solution at all\n");
		return -EINVAL;
	}

	/* Finalize timing settings */
	*timing = _I2C_SET_TIMINGR_PRESC(s) |
		_I2C_SET_TIMINGR_SCLDEL(solutions[s].scldel) |
		_I2C_SET_TIMINGR_SDADEL(solutions[s].sdadel) |
		_I2C_SET_TIMINGR_SCLH(solutions[s].sclh) |
		_I2C_SET_TIMINGR_SCLL(solutions[s].scll);

	DMSG("I2C TIMINGR (PRESC/SCLDEL/SDADEL): %d/%u/%u\n",
	     s, solutions[s].scldel, solutions[s].sdadel);
	DMSG("I2C TIMINGR (SCLH/SCLL): %u/%u\n",
	     solutions[s].sclh, solutions[s].scll);
	DMSG("I2C TIMINGR: 0x%x\n", *timing);

	return 0;
}

/*
 * @brief  From requested rate, get the closest I2C rate without exceeding it,
 *         within I2C specification values defined in @i2c_specs.
 * @param  rate: The requested rate.
 * @retval Found rate, else the lowest value supported by platform.
 */
static uint32_t get_lower_rate(uint32_t rate)
{
	size_t i = 0;

	for (i = ARRAY_SIZE(i2c_specs); i > 0; i--)
		if (rate > i2c_specs[i - 1].rate)
			return i2c_specs[i - 1].rate;

	return i2c_specs[0].rate;
}

static int stm32_i2c_setup_timing(const struct device *dev, uint32_t *timing)
{
	const struct stm32_i2c_config __unused *drv_cfg = dev_get_config(dev);
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	unsigned long clock_src = clk_get_rate(drv_data->clk);
	int err;

	if (clock_src == 0U)
		return -EINVAL;

	/*
	 * If the timing has already been computed, and the frequency is the
	 * same as when it was computed, then use the saved timing.
	 */
	if ((drv_data->frequency_saved == clock_src) &&
	    (drv_data->bitrate_saved == drv_data->bitrate)) {
		*timing = drv_data->timing_saved;
		return 0;
	}

	do {
		err = i2c_compute_timing(dev, clock_src, timing);
		if (err) {
			DMSG("Failed to compute I2C timings\n");
			if (drv_data->bitrate <= I2C_BITRATE_STANDARD)
				break;

			drv_data->bitrate = get_lower_rate(drv_data->bitrate);
			DMSG("Downgrade I2C speed to %uHz\n",
			     drv_data->bitrate);
		}
	} while (err);

	if (err) {
		EMSG("Impossible to compute I2C timings\n");
		return err;
	}

	drv_data->bitrate_saved = drv_data->bitrate;
	drv_data->frequency_saved = clock_src;
	drv_data->timing_saved = *timing;

	DMSG("I2C Freq(%uHz), Clk Source(%lu)\n", drv_data->bitrate, clock_src);
	DMSG("I2C Rise(%d) and Fall(%d) Time\n", drv_cfg->rise_time, drv_cfg->fall_time);
	DMSG("I2C Analog Filter(%s), DNF(%u)\n",
	     drv_cfg->analog_filter ? "On" : "Off",
	     drv_data->digital_filter_coef);

	return 0;
}

static void i2c_config_analog_filter(const struct device *dev)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);

	/* Disable the selected I2C peripheral */
	io_clrbits32(drv_cfg->base + _I2C_CR1, _I2C_CR1_PE);

	/* Reset I2Cx ANOFF bit */
	io_clrbits32(drv_cfg->base + _I2C_CR1, I2C_CR1_ANFOFF);

	/* Set analog filter bit if filter is disabled */
	if (!drv_cfg->analog_filter)
		io_setbits32(drv_cfg->base + _I2C_CR1, I2C_CR1_ANFOFF);

	/* Enable the selected I2C peripheral */
	io_setbits32(drv_cfg->base + _I2C_CR1, _I2C_CR1_PE);
}

static int stm32_i2c_setup(const struct device *dev)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	uint32_t timing = 0;
	int err;

	err = stm32_i2c_setup_timing(dev, &timing);
	if (err)
		return err;

	/* Disable the selected I2C peripheral */
	io_clrbits32(drv_cfg->base + _I2C_CR1, _I2C_CR1_PE);

	/* Configure I2Cx: Frequency range */
	io_write32(drv_cfg->base + _I2C_TIMINGR, timing & TIMINGR_CLEAR_MASK);

	/* Disable Own Address1 before set the Own Address1 configuration */
	io_write32(drv_cfg->base + _I2C_OAR1, 0);

/*        |+ Configure I2Cx: Own Address1 and ack own address1 mode +|*/
/*        |+ I2C_MSG_ADDR_10_BITS not supported+|*/
/*        io_write32(drv_cfg->base + _I2C_OAR1,*/
/*                           _I2C_OAR1_OA1EN | init_data->own_address1);*/

	/* Configure I2Cx: Addressing Master mode */
	io_write32(drv_cfg->base + _I2C_CR2, 0);

	/*
	 * Enable the AUTOEND by default, and enable NACK
	 * (should be disabled only during Slave process).
	 */
/*        mmio_setbits_32(drv_cfg->base + I2C_CR2,*/
/*                        _I2C_CR2_AUTOEND_MASK | _I2C_CR2_NACK_MASK);*/

	/* Disable Own Address2 before set the Own Address2 configuration */
	io_write32(drv_cfg->base + _I2C_OAR2, 0);

	/* Enable the selected I2C peripheral */
	io_setbits32(drv_cfg->base + _I2C_CR1, _I2C_CR1_PE);

	i2c_config_analog_filter(dev);

	return 0;
}

static int stm32_i2c_transfer(const struct device *dev, struct i2c_msg *msgs,
			      uint8_t num_msgs, uint16_t addr)
{
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	int err;

	clk_enable(drv_data->clk);

	err = _stm32_i2c_wait_busy(dev, I2C_TIMEOUT_BUSY_US);
	if (err)
		goto out;

	// Set I2C_MSG_RESTART flag on first message in order to send start condition
	msgs->flags |= I2C_MSG_RESTART;

	for (; num_msgs > 0; num_msgs--, msgs++) {
		uint8_t flags_next = 0;

		if (num_msgs > 1) {
			struct i2c_msg *msg_next = &(msgs[1]);
			flags_next = msg_next->flags;
		}

		err = _stm32_i2c_transaction(dev, msgs, flags_next, addr);
		if (err)
			break;
	}

out:
	clk_disable(drv_data->clk);
	return err;
}

static int stm32_i2c_configure(const struct device *dev, uint32_t config)
{
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	int err = 0;

	if (!(I2C_MODE_CONTROLLER & config))
		return -EINVAL;

	if (I2C_ADDR_10_BITS & config)
		return -EINVAL;

	switch (I2C_SPEED_GET(config)) {
	case I2C_SPEED_STANDARD:
		drv_data->bitrate = I2C_BITRATE_STANDARD;
		break;
	case I2C_SPEED_FAST:
		drv_data->bitrate = I2C_BITRATE_FAST;
		break;
	case I2C_SPEED_FAST_PLUS:
		drv_data->bitrate = I2C_BITRATE_FAST_PLUS;
		break;
	default:
		return -EINVAL;
	}

	drv_data->i2c_config = config;

	clk_enable(drv_data->clk);
	err = stm32_i2c_setup(dev);
	clk_disable(drv_data->clk);

	return err;
}

static const struct i2c_driver_api __maybe_unused stm32_i2c_api = {
	.configure = stm32_i2c_configure,
	.transfer = stm32_i2c_transfer,
};

static int __maybe_unused stm32_i2c_init(const struct device *dev)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	uint32_t i2c_config;
	int err;

	err = pinctrl_apply_state(drv_cfg->pcfg, PINCTRL_STATE_DEFAULT);
	if (err)
		return err;

	drv_data->clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (!drv_data->clk)
		return -ENODEV;

	err = clk_enable(drv_data->clk);
	if (err)
		return err;

	err = reset_control_reset(&drv_cfg->rst_ctl);
	if (err)
		return err;

	drv_data->digital_filter_coef = 0;

	i2c_config = I2C_MODE_CONTROLLER | i2c_map_dt_bitrate(drv_cfg->bitrate);
	err = stm32_i2c_configure(dev, i2c_config);

	clk_disable(drv_data->clk);

	return err;
}

#ifdef CONFIG_PM_DEVICE
static int stm32_i2c_pm_action(const struct device *dev,
			       enum pm_device_action action, uint32_t pm_hint)
{
	const struct stm32_i2c_config *drv_cfg = dev_get_config(dev);
	struct stm32_i2c_data *drv_data = dev_get_data(dev);
	int err = 0;

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		err = pinctrl_apply_state_optional(drv_cfg->pcfg, PINCTRL_STATE_SLEEP);
	} else {
		err = pinctrl_apply_state(drv_cfg->pcfg, PINCTRL_STATE_DEFAULT);
		if (err)
			goto out;

		err = stm32_i2c_configure(dev, drv_data->i2c_config);
	}

out:
       return err;
}
#endif

#define STM32_I2C_INIT(n)							\
										\
PINCTRL_DT_INST_DEFINE(n);							\
										\
static const struct stm32_i2c_config cfg_##n = {				\
	.base = DT_INST_REG_ADDR(n),						\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),			\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),		\
	.rst_ctl = DT_INST_RESET_CONTROL_GET(n),				\
	.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),				\
	.bitrate = DT_INST_PROP_OR(n, clock_frequency, 100000),			\
	.rise_time = DT_INST_PROP_OR(n, i2c_scl_rising_time_ns, 25),		\
	.fall_time = DT_INST_PROP_OR(n, i2c_scl_falling_time_ns, 10),		\
	.analog_filter = DT_INST_PROP_OR(n, i2c_analog_filter, false),		\
};										\
										\
static struct stm32_i2c_data data_##n = {};					\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_i2c_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_INST_DEFINE(n,							\
		      &stm32_i2c_init,						\
		      PM_DEVICE_DT_INST_GET(n),					\
		      &data_##n, &cfg_##n,					\
		      CORE, 5,							\
		      &stm32_i2c_api);

DT_INST_FOREACH_STATUS_OKAY(STM32_I2C_INIT)
