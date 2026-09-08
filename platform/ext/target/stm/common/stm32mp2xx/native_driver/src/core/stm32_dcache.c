/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#define DT_DRV_COMPAT st_stm32mp2_dcache

#include <cmsis.h>
#include <debug.h>
#include <device.h>
#include <errno.h>
#include <inttypes.h>
#include <irq.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <stdbool.h>
#include <stdint.h>
#include <stm32_dcache.h>
#include <string.h>
#include <uart_stdout.h>

/* DCACHE offset register */
#define _DCACHE_CR			U(0x000)
#define _DCACHE_SR			U(0x004)
#define _DCACHE_IER			U(0x008)
#define _DCACHE_FCR			U(0x00C)
#define _DCACHE_RHMONR			U(0x010)
#define _DCACHE_RMMONR			U(0x014)
#define _DCACHE_WHMONR			U(0x020)
#define _DCACHE_WMMONR			U(0x024)
#define _DCACHE_CMDRSADDRR		U(0x028)
#define _DCACHE_CMDREADDRR		U(0x02C)
#define _DCACHE_HWCFGR			U(0x3F0)
#define _DCACHE_VERR			U(0x3F4)
#define _DCACHE_IPIDR			U(0x3F8)
#define _DCACHE_SIDR			U(0x3FC)

/* DCACHE_CR register fields */
#define _DCACHE_CR_EN			BIT(0)
#define _DCACHE_CR_CACHEINV		BIT(1)
#define _DCACHE_CR_CACHECMD_MASK	GENMASK_32(10, 8)
#define _DCACHE_CR_CACHECMD_SHIFT	8
#define _DCACHE_CR_STARTCMD		BIT(11)
#define _DCACHE_CR_RHITMEN		BIT(16)
#define _DCACHE_CR_RMISSMEN		BIT(17)
#define _DCACHE_CR_RHITMRST		BIT(18)
#define _DCACHE_CR_RMISSMRST		BIT(19)
#define _DCACHE_CR_WHITMEN		BIT(20)
#define _DCACHE_CR_WMISSMEN		BIT(21)
#define _DCACHE_CR_WHITMRST		BIT(22)
#define _DCACHE_CR_WMISSMRST		BIT(23)
#define _DCACHE_CR_HBURST		BIT(31)

/* DCACHE_SR register fields */
#define _DCACHE_SR_BUSYF		BIT(0)
#define _DCACHE_SR_BUSYENDF		BIT(1)
#define _DCACHE_SR_ERRF			BIT(2)
#define _DCACHE_SR_BUSYCMDF		BIT(3)
#define _DCACHE_SR_CMDENDF		BIT(4)

/* DCACHE_IER register fields */
#define _DCACHE_IER_BSYENDIE		BIT(1)
#define _DCACHE_IER_ERRIE		BIT(2)
#define _DCACHE_IER_CMDENDIE		BIT(4)

/* DCACHE_FCR register fields */
#define _DCACHE_FCR_CBSYENDF		BIT(1)
#define _DCACHE_FCR_CERRF		BIT(2)
#define _DCACHE_FCR_CCMDENDF		BIT(4)

/* DCACHE_CMDRSADDRR register fields */
#define _DCACHE_CMDRSADDRR_START_MASK	GENMASK_32(31, 5)
#define _DCACHE_CMDRSADDRR_START_SHIFT	5

/* DCACHE_CMDREADDRR register fields */
#define _DCACHE_CMDRSADDRR_END_MASK	GENMASK_32(31, 5)
#define _DCACHE_CMDRSADDRR_END_SHIFT	5

/* DCACHE_HWCFGR register fields */
#define _DCACHE_HWCFGR_WAYS_MASK	GENMASK_32(1, 0)
#define _DCACHE_HWCFGR_WAYS_SHIFT	0
#define _DCACHE_HWCFGR_SIZE_MASK	GENMASK_32(6, 4)
#define _DCACHE_HWCFGR_SIZE_SHIFT	4
#define _DCACHE_HWCFGR_LWIDTH_MASK	GENMASK_32(10, 9)
#define _DCACHE_HWCFGR_LWIDTH_SHIFT	9
#define _DCACHE_HWCFGR_MASTERSIZE_MASK	GENMASK_32(24, 23)
#define _DCACHE_HWCFGR_MASTERSIZE_SHIFT	23

/* _DCACHE_VERR register fields */
#define _DCACHE_VERR_MINREV_MASK	GENMASK_32(3, 0)
#define _DCACHE_VERR_MINREV_SHIFT	0
#define _DCACHE_VERR_MAJREV_MASK	GENMASK_32(7, 4)
#define _DCACHE_VERR_MAJREV_SHIFT	4

#define _DCACHE_FLD_PREP(field, value)	(((uint32_t)(value) << (field ## _SHIFT)) & (field ## _MASK))
#define _DCACHE_FLD_GET(field, value)	(((uint32_t)(value) & (field ## _MASK)) >> (field ## _SHIFT))

#define _DCACHE_BUSY_TIMEOUT_US		10000U

struct dcache_driver_data {
	uint32_t version;
	uint8_t ways;
};

struct stm32_dcache_config {
	uintptr_t base;
	const struct irq_spec *int_spec;
};

static const struct device *dcache_dev;

static void stm32_dcache_get_hwconfig(const struct device *dev)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dev);
	struct dcache_driver_data *dcache_data = dev_get_data(dev);
	uint32_t regval = 0;

	regval = io_read32(dcache_conf->base + _DCACHE_HWCFGR);
	dcache_data->ways = _DCACHE_FLD_GET(_DCACHE_HWCFGR_WAYS, regval);

	regval = io_read32(dcache_conf->base + _DCACHE_VERR);

	DMSG("DCACHE version %"PRIu32".%"PRIu32"\n",
	     _DCACHE_FLD_GET(_DCACHE_VERR_MAJREV, regval),
	     _DCACHE_FLD_GET(_DCACHE_VERR_MINREV, regval));

	DMSG("HW cap: ways:%"PRIu8"\n", dcache_data->ways);
}

static int stm32_dcache_waitforready(int flags)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);
	uint32_t sr;
	int err;

	err = mmio_read32_poll_timeout(dcache_conf->base + _DCACHE_SR,
				       sr, (sr & (flags)),
				       _DCACHE_BUSY_TIMEOUT_US);
	if (err)
		EMSG("%s: busy timeout, SR: %x\n", __func__, sr);

	io_write32(dcache_conf->base + _DCACHE_FCR, flags);

	return err;
}

#define DCACHE_LOG(str) \
	stdio_output_string((const char *)(str), strlen(str))

static irqreturn_t stm32_dcache_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32_dcache_config *dev_cfg = dev_get_config(dev);
	uint32_t sr = io_read32(dev_cfg->base + _DCACHE_SR);
	char tmp[40];

	snprintf(tmp, sizeof(tmp), "\r\ndata cache exceptions: %#08x\r\n", sr);
	DCACHE_LOG(tmp);

	return IRQ_HANDLED;
}

static int stm32_dcache_enable_irq(const struct device *dev)
{
	const struct stm32_dcache_config *dev_cfg = dev_get_config(dev);
	int err;

	err = interrupt_request(dev_cfg->int_spec, (void *)dev, stm32_dcache_isr, IRQF_NONE);
	if (err)
		return err;

	io_write32(dev_cfg->base + _DCACHE_IER, _DCACHE_IER_ERRIE);

	return 0;
}

int stm32_dcache_monitor_reset(void)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);

	if (dcache_conf->base == 0)
		return -ENODEV;

	io_setbits32(dcache_conf->base + _DCACHE_CR,
		     _DCACHE_CR_RHITMRST | _DCACHE_CR_RMISSMRST |
		     _DCACHE_CR_WHITMRST | _DCACHE_CR_WMISSMRST);

	io_clrbits32(dcache_conf->base + _DCACHE_CR,
		     _DCACHE_CR_RHITMRST | _DCACHE_CR_RMISSMRST |
		     _DCACHE_CR_WHITMRST | _DCACHE_CR_WMISSMRST);

	return 0;
}

int stm32_dcache_monitor_start(void)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);

	if (dcache_conf->base == 0)
		return -ENODEV;

	io_setbits32(dcache_conf->base + _DCACHE_CR,
		     _DCACHE_CR_RHITMEN | _DCACHE_CR_RMISSMEN |
		     _DCACHE_CR_WHITMEN	 | _DCACHE_CR_WMISSMEN);

	return 0;
}

int stm32_dcache_monitor_stop(void)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);

	if (dcache_conf->base == 0)
		return -ENODEV;

	io_clrbits32(dcache_conf->base + _DCACHE_CR,
		     _DCACHE_CR_RHITMEN | _DCACHE_CR_RMISSMEN |
		     _DCACHE_CR_WHITMEN	 | _DCACHE_CR_WMISSMEN);

	return 0;
}

int stm32_dcache_monitor_get(struct stm32_dcache_mon *mon)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);

	if (dcache_conf->base == 0)
		return -ENODEV;

	mon->rmiss = io_read32(dcache_conf->base + _DCACHE_RMMONR);
	mon->rhit = io_read32(dcache_conf->base + _DCACHE_RHMONR);
	mon->wmiss = io_read32(dcache_conf->base + _DCACHE_WMMONR);
	mon->whit = io_read32(dcache_conf->base + _DCACHE_WHMONR);

	return 0;
}

int stm32_dcache_enable(bool monitor, bool inv)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);
	uint32_t reg;

	if (dcache_conf->base == 0)
		return -ENODEV;

	reg = io_read32(dcache_conf->base + _DCACHE_SR);
	if (reg & (_DCACHE_SR_BUSYF | _DCACHE_SR_BUSYCMDF))
		return -EBUSY;

	if (monitor) {
		stm32_dcache_monitor_reset();
		stm32_dcache_monitor_start();
	}

	/*
	 * Cache invalidation is not allowed when DCACHE_CR.EN=0.
	 * The cache invalidation is done:
	 *  - on reset
	 *  - after DCACHE_CR.EN=1->0
	 *  - when cacheinv=1 with DCACHE_CR.EN=1
	 * warning: the mpu must be disabled to avoid unpredictable behavior
	 * before the busyendf
	 */
	reg = io_read32(dcache_conf->base + _DCACHE_CR);
	if (reg & (_DCACHE_CR_EN)) {
		if (!inv)
			return 0;

		return stm32_dcache_full_inv();
	} else {
		/* if en=0 cache is clean (by reset or 1->0) */
		io_setbits32(dcache_conf->base + _DCACHE_CR, _DCACHE_CR_EN);
	}

	return 0;
}

int stm32_dcache_disable(void)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);

	if (dcache_conf->base == 0)
		return -ENODEV;

	io_clrbits32(dcache_conf->base + _DCACHE_CR, _DCACHE_CR_EN);

	return stm32_dcache_waitforready(_DCACHE_SR_BUSYENDF);
}

int stm32_dcache_full_inv(void)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);
	uintptr_t base = dcache_conf->base;
	uint32_t sr;

	if (!base)
		return -ENODEV;

	sr = io_read32(base + _DCACHE_SR);
	if (sr & (_DCACHE_SR_BUSYF | _DCACHE_SR_BUSYCMDF))
		return -EBUSY;

	io_write32(base + _DCACHE_FCR, _DCACHE_FCR_CBSYENDF);

	io_setbits32(base + _DCACHE_CR, _DCACHE_CR_CACHEINV);

	return stm32_dcache_waitforready(_DCACHE_SR_BUSYENDF);
}

int stm32_dcache_maintenance(int cmd, uintptr_t start, uintptr_t end)
{
	const struct stm32_dcache_config *dcache_conf = dev_get_config(dcache_dev);
	uintptr_t base = dcache_conf->base;
	uint32_t cr;
	uint32_t sr;

	if (!base)
		return -ENODEV;

	sr = io_read32(base + _DCACHE_SR);
	if (sr & (_DCACHE_SR_BUSYF | _DCACHE_SR_BUSYCMDF))
		return -EBUSY;

	cr = io_read32(base + _DCACHE_CR);
	if (!(cr & (_DCACHE_CR_EN))) {
		EMSG("Cache operation not possible when cache is disabled\n");
		return -EINVAL;
	}

	io_write32(base + _DCACHE_CMDRSADDRR, start);
	io_write32(base + _DCACHE_CMDREADDRR, end);

	io_clrsetbits32(base + _DCACHE_CR,
			_DCACHE_CR_CACHECMD_MASK,
			_DCACHE_FLD_PREP(_DCACHE_CR_CACHECMD, cmd));

	io_setbits32(base + _DCACHE_CR, _DCACHE_CR_STARTCMD);

	return stm32_dcache_waitforready(_DCACHE_SR_CMDENDF);
}

int stm32_dcache_init(const struct device *dev)
{
	stm32_dcache_get_hwconfig(dev);

	return stm32_dcache_enable_irq(dev);
}

#define STM32_DCACHE_INIT(n)					\
								\
BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,	\
	     "only one DCACHE instance is supported");		\
								\
DT_INST_IRQS_SPEC_DEFINE(n)					\
								\
static const struct stm32_dcache_config cfg_##n = {		\
	.base = DT_INST_REG_ADDR(n),				\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),			\
};								\
								\
static struct dcache_driver_data data_##n = { };		\
								\
static const struct device *dcache_dev = DEVICE_DT_INST_GET(0);	\
								\
DEVICE_DT_INST_DEFINE(n, &stm32_dcache_init, NULL,		\
		      &data_##n, &cfg_##n,			\
		      PRE_CORE, 17, NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_DCACHE_INIT)
