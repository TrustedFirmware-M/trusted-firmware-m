/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_iac

#include <cmsis.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <device.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <tfm_hal_platform.h>
#include <tfm_platform_system.h>
#include <uart_stdout.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <irq.h>

/* IAC offset register */
#define _IAC_IER0		U(0x000)
#define _IAC_ISR0		U(0x080)
#define _IAC_ICR0		U(0x100)
#define _IAC_IISR0		U(0x36C)

#define _IAC_HWCFGR2		U(0x3EC)
#define _IAC_HWCFGR1		U(0x3F0)
#define _IAC_VERR		U(0x3F4)

/* IAC_HWCFGR2 register fields */
#define _IAC_HWCFGR2_CFG1_MASK	GENMASK_32(3, 0)
#define _IAC_HWCFGR2_CFG1_SHIFT	0
#define _IAC_HWCFGR2_CFG2_MASK	GENMASK_32(7, 4)
#define _IAC_HWCFGR2_CFG2_SHIFT	4

/* IAC_HWCFGR1 register fields */
#define _IAC_HWCFGR1_CFG1_MASK	GENMASK_32(3, 0)
#define _IAC_HWCFGR1_CFG1_SHIFT	0
#define _IAC_HWCFGR1_CFG2_MASK	GENMASK_32(7, 4)
#define _IAC_HWCFGR1_CFG2_SHIFT	4
#define _IAC_HWCFGR1_CFG3_MASK	GENMASK_32(11, 8)
#define _IAC_HWCFGR1_CFG3_SHIFT	8
#define _IAC_HWCFGR1_CFG4_MASK	GENMASK_32(15, 12)
#define _IAC_HWCFGR1_CFG4_SHIFT	12
#define _IAC_HWCFGR1_CFG5_MASK	GENMASK_32(24, 16)
#define _IAC_HWCFGR1_CFG5_SHIFT	16

/* IAC_VERR register fields */
#define _IAC_VERR_MINREV_MASK	GENMASK_32(3, 0)
#define _IAC_VERR_MINREV_SHIFT	0
#define _IAC_VERR_MAJREV_MASK	GENMASK_32(7, 4)
#define _IAC_VERR_MAJREV_SHIFT	4

/* Periph id per register */
#define _PERIPH_IDS_PER_REG	32

#define _IAC_FLD_PREP(field, value)	(((uint32_t)(value) << (field ## _SHIFT)) & (field ## _MASK))
#define _IAC_FLD_GET(field, value)	(((uint32_t)(value) & (field ## _MASK)) >> (field ## _SHIFT))

/*
 * no common errno between component
 * define iac internal errno
 */
#define	IAC_ERR_NOMEM		12	/* Out of memory */
#define IAC_ERR_NODEV		19	/* No such device */
#define IAC_ERR_INVAL		22	/* Invalid argument */
#define IAC_ERR_NOTSUP		45	/* Operation not supported */

struct stm32_iac_config {
	uintptr_t base;
	const struct irq_spec *int_spec;
	uint32_t *id_disable;
	uint32_t n_id_disable;
};

struct stm32_iac_data {
	uint8_t num_ilac;
	bool rif_en;
	bool sec_en;
	bool priv_en;
};

static void stm32_iac_get_hwconfig(const struct device *dev)
{
	const struct stm32_iac_config *drv_cfg = dev_get_config(dev);
	struct stm32_iac_data *drv_data = dev_get_data(dev);
	uint32_t regval;

	regval = io_read32(drv_cfg->base + _IAC_HWCFGR1);
	drv_data->num_ilac = _IAC_FLD_GET(_IAC_HWCFGR1_CFG5, regval);
	drv_data->rif_en = _IAC_FLD_GET(_IAC_HWCFGR1_CFG1, regval) != 0;
	drv_data->sec_en = _IAC_FLD_GET(_IAC_HWCFGR1_CFG2, regval) != 0;
	drv_data->priv_en = _IAC_FLD_GET(_IAC_HWCFGR1_CFG3, regval) != 0;

	regval = io_read32(drv_cfg->base + _IAC_VERR);

	DMSG("IAC version %"PRIu32".%"PRIu32"\n",
	     _IAC_FLD_GET(_IAC_VERR_MAJREV, regval),
	     _IAC_FLD_GET(_IAC_VERR_MINREV, regval));

	DMSG("HW cap: enabled[rif:sec:priv]:[%s:%s:%s] num ilac:[%"PRIu8"]\n",
	     drv_data->rif_en ? "true" : "false",
	     drv_data->sec_en ? "true" : "false",
	     drv_data->priv_en ? "true" : "false",
	     drv_data->num_ilac);
}

#define IAC_EXCEPT_MSB_BIT(x) (x * _PERIPH_IDS_PER_REG + _PERIPH_IDS_PER_REG - 1)
#define IAC_EXCEPT_LSB_BIT(x) (x * _PERIPH_IDS_PER_REG)

#define IAC_LOG(str) do { \
    stdio_output_string((const char *)str, strlen(str)); \
} while (0);

__weak void access_violation_handler(void)
{
	IAC_LOG("Ooops...\n\r");
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
	tfm_hal_system_halt();
#else
	tfm_platform_hal_system_reset();
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */
}

static bool stm32_iac_discarded(uint32_t iac)
{
#if defined(CONFIG_STM32MP25X_REVY)
	/*
	 * Discard some IAC as workaround for ROM code issues
	 * on STM32MP25X/STM32MP23X RevY and STM32MP21X RevA
	 */
	switch (iac) {
	case 108:
	case 156:
	case 177:
		return true;
	default:
		return false;
	}
#else
	return false;
#endif
}

static irqreturn_t stm32_iac_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32_iac_config *drv_cfg = dev_get_config(dev);
	struct stm32_iac_data *drv_data = dev_get_data(dev);
	int nreg = div_round_up(drv_data->num_ilac, _PERIPH_IDS_PER_REG);
	uint32_t isr = 0;
	uint32_t iac = 0;
	char tmp[50];
	int i = 0, j = 0;
	bool error = false;

	for (i = 0; i < nreg; i++) {
		uint32_t offset = sizeof(uint32_t) * i;

		isr = io_read32(drv_cfg->base + _IAC_ISR0 + offset);
		isr &= io_read32(drv_cfg->base + _IAC_IER0 + offset);
		if (!isr)
			continue;

		snprintf(tmp, sizeof(tmp),
			 "\r\niac exceptions: [%d:%d]=%#08x\r\n",
			 IAC_EXCEPT_MSB_BIT(i),
			 IAC_EXCEPT_LSB_BIT(i), isr);
		IAC_LOG(tmp);

		for (j = 0; j < _PERIPH_IDS_PER_REG; j++) {
			if (!(isr & BIT(j)))
				continue;

			iac = IAC_EXCEPT_LSB_BIT(i) + j;
			if (stm32_iac_discarded(iac)) {
				snprintf(tmp, sizeof(tmp), "Discarded IAC ID: %03d\r\n", iac);
			} else {
				error = true;
				snprintf(tmp, sizeof(tmp), "IAC exception ID: %03d\r\n", iac);
			}

			IAC_LOG(tmp);
		}

		io_write32(drv_cfg->base + _IAC_ICR0 + offset, isr);
	}

	if (error)
		access_violation_handler();

	return IRQ_HANDLED;
}

static int stm32_iac_setup(const struct device *dev)
{
	const struct stm32_iac_config *drv_cfg = dev_get_config(dev);
	struct stm32_iac_data *drv_data = dev_get_data(dev);
	int nreg = div_round_up(drv_data->num_ilac, _PERIPH_IDS_PER_REG);
	int i = 0;

	for (i = 0; i < nreg; i++) {
		uint32_t reg_ofst = drv_cfg->base + sizeof(uint32_t) * i;

		//clear status flags
		io_write32(reg_ofst + _IAC_ICR0, UINT32_MAX);
		//enable all peripherals of nreg
		io_write32(reg_ofst + _IAC_IER0, ~0x0);
	}

	for (i = 0; i < drv_cfg->n_id_disable; i++) {
		uint32_t reg_ofst = (drv_cfg->id_disable[i] / _PERIPH_IDS_PER_REG);
		uint32_t bit_ofst = (drv_cfg->id_disable[i]) & 0x1F;

		reg_ofst *= sizeof(uint32_t);
		io_clrbits32(drv_cfg->base + _IAC_IER0 + reg_ofst, BIT(bit_ofst));
	}

	return interrupt_request(drv_cfg->int_spec, (void *)dev, stm32_iac_isr, IRQF_NONE);
}

static int stm32_iac_init(const struct device *dev)
{
	stm32_iac_get_hwconfig(dev);

	return stm32_iac_setup(dev);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_iac_pm_action(const struct device *dev,
			       enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_RESUME && PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return stm32_iac_init(dev);

	return 0;
}
#endif

#define STM32_IAC_INIT(n)								\
											\
DT_INST_IRQS_SPEC_DEFINE(n)								\
											\
static uint32_t id_disable_##n[] =							\
	DT_INST_PROP_OR(n, id_disable, {});						\
											\
static const struct stm32_iac_config stm32_iac_cfg_##n = {				\
	.base = DT_INST_REG_ADDR(n),							\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),						\
	.id_disable = id_disable_##n,							\
	.n_id_disable = DT_INST_PROP_LEN_OR(n, id_disable, 0),				\
};											\
											\
static struct stm32_iac_data stm32_iac_data_##n = {};					\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_iac_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_iac_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_iac_data_##n,						\
		      &stm32_iac_cfg_##n,						\
		      PRE_CORE, 15,							\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_IAC_INIT)
