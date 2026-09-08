/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include "lib/delay.h"
#include "lib/mmio.h"
#include "lib/mmiopoll.h"
#include "lib/timeout.h"
#include <clk.h>
#include <debug.h>
#include <device.h>
#include <entropy.h>
#include <firewall.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <reset.h>
#include <stdint.h>
#include <string.h>

#define _RNG_CR			0x00U
#define _RNG_SR			0x04U
#define _RNG_DR			0x08U
#define _RNG_NSCR		0x0CU
#define _RNG_HTCR		0x10U

#define _CR_RNGEN		0x4U
#define _CR_CED			0x20U
#define _CR_CR_POWER_OPTIM	0x2000U
#define _CR_CLKDIV		0xF0000U
#define _CR_CLKDIV_Pos		16U
#define _CR_CONDRST		0x40000000U

#define _SR_DRDY		0x1U
#define _SR_SECS		0x4U
#define _SR_SEIS		0x40U

#define RNG_TIMEOUT_US		100000U
#define RNG_TIMEOUT_STEP_US	10U
#define RNG_TIMEOUT_TRIALS 	(RNG_TIMEOUT_US / RNG_TIMEOUT_STEP_US)

#define TIMEOUT_US_1MS		1000U

#define RNG_NIST_CONFIG_MASK	GENMASK(27, 8)

#define RNG_MAX_NOISE_CLK_FREQ	48000000U

struct stm32_rng_config {
	uintptr_t base;
	const struct device *hclk_dev;
	const clk_subsys_t hclk_subsys;
	const struct reset_control rst_ctl;
	const struct firewall_spec *firewall;
	const int n_firewall;
};

struct stm32_rng_variant {
	uint32_t max_noise_clk_freq;
	uint32_t cr;
	uint32_t nscr;
	uint32_t htcr;
};

struct stm32_rng_data {
	const struct stm32_rng_variant *variant;
	struct clk *clk;
	uint32_t pm_cr;
	uint32_t pm_health;
	uint32_t pm_noise_ctrl;
};

static int seed_error_recovery(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);

	/* Recommended by the SoC reference manual */
	mmio_clrbits_32(drv_cfg->base + _RNG_SR, _SR_SEIS);

	if ((mmio_read_32(drv_cfg->base + _RNG_SR) & _SR_SEIS) != 0U) {
		ERROR("[%s] RNG noise\n", dev->name);
		return -EBUSY;
	}

	return 0;
}

static uint32_t stm32_rng_clock_freq_restrain(const struct device *dev)
{
	unsigned long clock_rate;
	uint32_t clock_div = 0U;
	struct stm32_rng_data *drv_data = dev_get_data(dev);

	clock_rate = clk_get_rate(drv_data->clk);

	/*
	 * Get the exponent to apply on the CLKDIV field in _RNG_CR register.
	 * No need to handle the case when clock-div > 0xF as it is physically
	 * impossible.
	 */
	while ((clock_rate >> clock_div) > drv_data->variant->max_noise_clk_freq)
		clock_div++;

	VERBOSE("[%s] RNG clk rate : %lu\n", dev->name, clk_get_rate(drv_data->clk) >> clock_div);

	return clock_div;
}

static int check_data_integrity(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	uint32_t status = mmio_read_32(drv_cfg->base + _RNG_SR);
	int nb_tries, err;
	uint32_t sr;

	if ((status & (_SR_SECS | _SR_SEIS | _SR_DRDY)) != _SR_DRDY) {
		for (nb_tries = RNG_TIMEOUT_TRIALS; nb_tries > 0; nb_tries--) {
			uint32_t status = mmio_read_32(drv_cfg->base + _RNG_SR);

			if ((status & (_SR_SECS | _SR_SEIS)) != 0U) {
				err = seed_error_recovery(dev);
				if (err)
					return err;
			}

			err = mmio_read32_poll_timeout(drv_cfg->base + _RNG_SR,
						       sr,
						       (sr & _SR_DRDY),
						       RNG_TIMEOUT_STEP_US);

			if (!err)
				goto out;
		}

		if (err && nb_tries == 0)
			return -ETIMEDOUT;
	}

out:
	return 0;
}

static void stm32_rng_set_enable(uintptr_t rng_base, uint32_t health, uint32_t noise_ctl)
{
	mmio_write_32(rng_base + _RNG_HTCR, health);
	mmio_write_32(rng_base + _RNG_NSCR, noise_ctl);

	mmio_clrsetbits_32(rng_base + _RNG_CR, _CR_CONDRST, _CR_RNGEN);
}

static int stm32_rng_enable(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	struct stm32_rng_data *drv_data = dev_get_data(dev);
	uint32_t clock_div;

	/* Reset internal block and disable CED bit */
	clock_div = stm32_rng_clock_freq_restrain(dev);

	/* Update configuration fields */
	mmio_clrsetbits_32(drv_cfg->base + _RNG_CR, RNG_NIST_CONFIG_MASK,
			   drv_data->variant->cr | _CR_CONDRST | _CR_CED);

	mmio_clrsetbits_32(drv_cfg->base + _RNG_CR, _CR_CLKDIV,
			   (clock_div << _CR_CLKDIV_Pos));

	stm32_rng_set_enable(drv_cfg->base, drv_data->variant->htcr, drv_data->variant->nscr);

	DMSG("[%s] Init RNG done\r\n", dev->name);

	return check_data_integrity(dev);
}

static int stm32_rng_acquire_sem(const struct stm32_rng_config *drv_cfg)
{
	struct firewall_spec *firewall;
	int err, i;
	uint64_t timeout = timeout_init_us(TIMEOUT_US_1MS);

	/* Fix: In some SoC revision, ROM code may not release the semaphore.
	 * Then Cortex-A must release it as a workaround. We try to acquire the
	 * semaphore for a limited time before returning an error, to give
	 * Cortex‑A a chance to release it.
	 */
	do {
		err = acquire_sem_for_each_firewall(drv_cfg->firewall,
						    firewall,
						    drv_cfg->n_firewall, i);
		if (timeout_elapsed(timeout))
			break;
	} while (err);

	if (err)
		ERROR("%s: Could not acquire firewall access.\n", __func__);

	return err;
}

static int stm32_rng_release_sem(const struct stm32_rng_config *drv_cfg)
{
	struct firewall_spec *firewall;
	int err, i;

	err = release_sem_for_each_firewall(drv_cfg->firewall, firewall, drv_cfg->n_firewall, i);
	if (err)
		ERROR("%s: Could not release firewall access.\n", __func__);

	return err;
}

/*
 * stm32_rng_get_entropy - Read a number of random bytes from RNG
 * out: pointer to the output buffer
 * size: number of bytes to be read
 * Return 0 on success, non-0 on failure
 */
static int stm32_rng_get_entropy(const struct device *dev, uint8_t *out, uint32_t size)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	uint8_t *buf = out;
	size_t len = size;
	uint32_t data32;
	int sem_err = 0;
	int err = 0;
	unsigned int fifo_size;

	/* Check if RNG is open */
	if (!device_is_ready(dev))
		return -ENODEV;

	err = stm32_rng_acquire_sem(drv_cfg);
	if (err)
		return err;

	while (len != 0U) {
		err = check_data_integrity(dev);
		if (err)
			goto bail;

		/* The data output buffer can store up to four 32-bit words.  When four words have
		 * been read from the output FIFO through the RNG_DR register, the content of the
		 * 128-bit conditioning output register is pushed into the output FIFO, and a new
		 * conditioning round is automatically started.  Four new words are added to the
		 * conditioning output register after a specific number of clock cycles.
		 */
		fifo_size = 4U;
		while (len != 0U) {
			if ((mmio_read_32(drv_cfg->base + _RNG_SR) & _SR_DRDY) == 0U) {
				break;
			}

			data32 = mmio_read_32(drv_cfg->base + _RNG_DR);
			if (data32 == 0U)
				break;

			fifo_size--;

			memcpy(buf, &data32, MIN(len, sizeof(uint32_t)));
			buf += MIN(len, sizeof(uint32_t));
			len -= MIN(len, sizeof(uint32_t));

			if (fifo_size == 0U) {
				break;
			}
		}
	}

bail:

	if (err)
		memset(out, 0, buf - out);

	sem_err = stm32_rng_release_sem(drv_cfg);

	return err ? err : sem_err;
}

static const struct entropy_driver_api __maybe_unused stm32_rng_api = {
	.get_entropy = stm32_rng_get_entropy,
};

/*
 * stm32_rng_init: Initialize rng from DT
 * return 0 on success, negative value on failure
 */
static int __maybe_unused stm32_rng_init(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	struct stm32_rng_data *drv_data = dev_get_data(dev);
	int err;

	err = stm32_rng_acquire_sem(drv_cfg);
	if (err)
		return err;

	drv_data->clk = clk_get(drv_cfg->hclk_dev, drv_cfg->hclk_subsys);
	if (!drv_data->clk)
		return -ENODEV;

	err = clk_enable(drv_data->clk);
	if (err)
		return err;

	err = reset_control_reset(&drv_cfg->rst_ctl);
	if (err)
		return err;

	err = stm32_rng_enable(dev);
	if (err)
		return err;

	return stm32_rng_release_sem(drv_cfg);
}

#ifdef CONFIG_PM_DEVICE
int stm32_rng_pm_suspend(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	struct stm32_rng_data *drv_data = dev_get_data(dev);
	uintptr_t rng_base = drv_cfg->base;
	int err = 0;
	uint32_t cr;

	drv_data->pm_cr = mmio_read_32(rng_base + _RNG_CR);
	drv_data->pm_health = mmio_read_32(rng_base + _RNG_HTCR);
	drv_data->pm_noise_ctrl = mmio_read_32(rng_base + _RNG_NSCR);

	/*
	 * As per reference manual, it is recommended to set
	 * RNG_CONFIG2[bit0] when RNG power consumption is critical.
	 */
	mmio_write_32(rng_base + _RNG_CR, _CR_CR_POWER_OPTIM | _CR_CONDRST);
	mmio_clrbits_32(rng_base + _RNG_CR, _CR_CONDRST);

	err = mmio_read32_poll_timeout(drv_cfg->base + _RNG_CR, cr,
				       !(cr & _CR_CONDRST), RNG_TIMEOUT_US);

	return err;
}

int stm32_rng_pm_resume(const struct device *dev)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	struct stm32_rng_data *drv_data = dev_get_data(dev);
	uintptr_t rng_base = drv_cfg->base;
	uint32_t cr;

	mmio_write_32(rng_base + _RNG_SR, 0U);

	/*
	 * Configuration must be set in the same access that sets
	 * RNG_CR_CONDRST bit. Otherwise, the configuration setting is
	 * not taken into account. CONFIGLOCK bit is always cleared in
	 * this configuration.
	 */
	mmio_write_32(rng_base + _RNG_CR, drv_data->pm_cr | _CR_CONDRST);

	stm32_rng_set_enable(rng_base, drv_data->pm_health, drv_data->pm_noise_ctrl);

	return mmio_read32_poll_timeout(rng_base + _RNG_CR, cr,
					!(cr & _CR_CONDRST), RNG_TIMEOUT_US);
}

static int stm32_rng_pm_action(const struct device *dev,
			       enum pm_device_action action, uint32_t pm_hint)
{
	const struct stm32_rng_config *drv_cfg = dev_get_config(dev);
	int err;

	err = stm32_rng_acquire_sem(drv_cfg);
	if (err)
		return err;

	switch (action) {
	case PM_DEVICE_ACTION_SUSPEND:
		err = stm32_rng_pm_suspend(dev);
		break;

	case PM_DEVICE_ACTION_RESUME:
		err = stm32_rng_pm_resume(dev);
		break;

	default:
		err = -EINVAL;
		break;
	}

	stm32_rng_release_sem(drv_cfg);

	return err;
}
#endif

#define STM32_RNG_INIT(n, _variant)							  \
											  \
DT_INST_ACCESS_CTRLS_DEFINE(n);								  \
											  \
static const struct stm32_rng_config stm32_rng_cfg_##n = {				  \
	.base = DT_INST_REG_ADDR(n),							  \
	.hclk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, rng_hclk)),              \
	.hclk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL_BY_NAME(n, rng_hclk, bits),      \
	.rst_ctl = DT_INST_RESET_CONTROL_GET(n),					  \
	.firewall = DT_INST_ACCESS_CTRLS_GET(n),					  \
	.n_firewall = DT_INST_ACCESS_CTRLS_NUM(n),					  \
};											  \
											  \
static struct stm32_rng_data stm32_rng_data_##n = {					  \
	.variant = _variant,								  \
};											  \
											  \
PM_DEVICE_DT_INST_DEFINE(n, stm32_rng_pm_action, PM_DEVICE_F_NONE);			  \
											  \
DEVICE_DT_INST_DEFINE(n,								  \
		 &stm32_rng_init,							  \
		 PM_DEVICE_DT_INST_GET(n),						  \
		 &stm32_rng_data_##n,							  \
		 &stm32_rng_cfg_##n,							  \
		 CORE, 6,								  \
		 &stm32_rng_api);

/* MP21 configuration default values */
static __unused struct stm32_rng_variant variant_stm32mp21 = {
	.max_noise_clk_freq	= 4000000U,
	.cr			= 0x00F01F00U,
	.nscr			= 0x000001FFU,
	.htcr			= 0x0000AAC7U,
};

/* MP23 and MP25 configuration default values */
static __unused struct stm32_rng_variant variant_stm32mp25 = {
	.max_noise_clk_freq	= 48000000U,
	.cr			= 0x08F01E00U,
	.nscr			= 0x0002E649U,
	.htcr			= 0x00006688U,
};

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_rng

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_RNG_INIT, &variant_stm32mp21)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp25_rng

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_RNG_INIT, &variant_stm32mp25)
