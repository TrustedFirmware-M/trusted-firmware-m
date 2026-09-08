/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_serc

#include <cmsis.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <clk.h>
#include <target_cfg.h>
#include <uart_stdout.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <irq.h>

/* SERC offset register */
#define _SERC_IER0		U(0x000)
#define _SERC_ISR0		U(0x040)
#define _SERC_ICR0		U(0x080)
#define _SERC_ENABLE		U(0x100)

#define _SERC_HWCFGR		U(0x3F0)
#define _SERC_VERR		U(0x3F4)

/* SERC_ENABLE register fields */
#define _SERC_ENABLE_SERFEN	BIT(0)

/* SERC_HWCFGR register fields */
#define _SERC_HWCFGR_CFG1_MASK	GENMASK_32(7, 0)
#define _SERC_HWCFGR_CFG1_SHIFT	0
#define _SERC_HWCFGR_CFG2_MASK	GENMASK_32(18, 16)
#define _SERC_HWCFGR_CFG2_SHIFT	16

/* SERC_VERR register fields */
#define _SERC_VERR_MINREV_MASK	GENMASK_32(3, 0)
#define _SERC_VERR_MINREV_SHIFT	0
#define _SERC_VERR_MAJREV_MASK	GENMASK_32(7, 4)
#define _SERC_VERR_MAJREV_SHIFT	4

/* Periph id per register */
#define _PERIPH_IDS_PER_REG	32

struct stm32_serc_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct irq_spec *int_spec;
	uint32_t *id_disable;
	uint32_t n_id_disable;
};

struct stm32_serc_data {
	uint8_t num_ilac;
};

static void stm32_serc_get_hwconfig(const struct device *dev)
{
	const struct stm32_serc_config *drv_cfg = dev_get_config(dev);
	struct stm32_serc_data *drv_data = dev_get_data(dev);
	uint32_t regval;

	regval = io_read32(drv_cfg->base + _SERC_HWCFGR);
	drv_data->num_ilac = _FLD_GET(_SERC_HWCFGR_CFG1, regval);

	regval = io_read32(drv_cfg->base + _SERC_VERR);

	DMSG("SERC version %"PRIu32".%"PRIu32"\n",
	     _FLD_GET(_SERC_VERR_MAJREV, regval),
	     _FLD_GET(_SERC_VERR_MINREV, regval));

	DMSG("HW cap: num ilac:[%"PRIu8"]\n", drv_data->num_ilac);
}

#define SERC_EXCEPT_MSB_BIT(x) (x * _PERIPH_IDS_PER_REG + _PERIPH_IDS_PER_REG - 1)
#define SERC_EXCEPT_LSB_BIT(x) (x * _PERIPH_IDS_PER_REG)

#define SERC_LOG(str) do { \
    stdio_output_string((const char *)str, strlen(str)); \
} while (0);

__weak void access_violation_handler(void)
{
	SERC_LOG("Ooops...\n\r");
	while (1) {
		;
	}
}

static irqreturn_t stm32_serc_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32_serc_config *drv_cfg = dev_get_config(dev);
	struct stm32_serc_data *drv_data = dev_get_data(dev);
	int nreg = div_round_up(drv_data->num_ilac, _PERIPH_IDS_PER_REG);
	uint32_t isr = 0;
	char tmp[50];
	int i = 0;

	for (i = 0; i < nreg; i++) {
		uint32_t offset = sizeof(uint32_t) * i;

		isr = io_read32(drv_cfg->base + _SERC_ISR0 + offset);
		isr &= io_read32(drv_cfg->base + _SERC_IER0 + offset);
		if (isr) {
			snprintf(tmp, sizeof(tmp),
				 "\r\nserc exceptions: [%d:%d]=%#08x\r\n",
				 SERC_EXCEPT_MSB_BIT(i),
				 SERC_EXCEPT_LSB_BIT(i), isr);

			SERC_LOG(tmp);
			io_write32(drv_cfg->base + _SERC_ICR0 + offset, isr);
		}
	}

	access_violation_handler();

	return IRQ_HANDLED;
}

static int stm32_serc_setup(const struct device *dev)
{
	const struct stm32_serc_config *drv_cfg = dev_get_config(dev);
	struct stm32_serc_data *drv_data = dev_get_data(dev);
	int nreg = div_round_up(drv_data->num_ilac, _PERIPH_IDS_PER_REG);
	int err, i = 0;

	for (i = 0; i < nreg; i++) {
		uint32_t reg_ofst = drv_cfg->base + sizeof(uint32_t) * i;

		//clear status flags
		io_write32(reg_ofst + _SERC_ICR0, 0x0);
		//enable all peripherals of nreg
		io_write32(reg_ofst + _SERC_IER0, ~0x0);
	}

	/* disable exceptions listed in dt property id_disable */
	for (i = 0; i < drv_cfg->n_id_disable; i++) {
		uint32_t reg_ofst = (drv_cfg->id_disable[i] / _PERIPH_IDS_PER_REG) * sizeof(uint32_t);
		uint32_t bit_ofst = (drv_cfg->id_disable[i]) & 0x1F;

		io_clrbits32(drv_cfg->base + _SERC_IER0 + reg_ofst,
			     BIT(bit_ofst));
	}

	err = interrupt_request(drv_cfg->int_spec, (void *)dev, stm32_serc_isr, IRQF_NONE);
	if (err)
		return err;

	mmio_setbits_32(drv_cfg->base + _SERC_ENABLE, _SERC_ENABLE_SERFEN);

	return 0;
}

static int stm32_serc_init(const struct device *dev)
{
	const struct stm32_serc_config *drv_cfg = dev_get_config(dev);
	struct clk *clk;
	int err;

	clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (!clk)
		return -ENODEV;

	err = clk_enable(clk);
	if (err)
		return err;

	stm32_serc_get_hwconfig(dev);

	return stm32_serc_setup(dev);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_serc_pm_action(const struct device *dev,
				enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_RESUME && PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return stm32_serc_init(dev);

	return 0;
}
#endif

#define STM32_SERC_INIT(n)								\
											\
DT_INST_IRQS_SPEC_DEFINE(n)								\
											\
static uint32_t id_disable_##n[] =							\
	DT_INST_PROP_OR(n, id_disable, {});						\
											\
static const struct stm32_serc_config stm32_serc_cfg_##n = {				\
	.base = DT_INST_REG_ADDR(n),							\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),				\
	.clk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL(n, bits),			\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),						\
	.id_disable = id_disable_##n,							\
	.n_id_disable = DT_INST_PROP_LEN_OR(n, id_disable, 0),				\
};											\
											\
static struct stm32_serc_data stm32_serc_data_##n = {};					\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_serc_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_serc_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_serc_data_##n,						\
		      &stm32_serc_cfg_##n,						\
		      PRE_CORE, 15,							\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_SERC_INIT)
