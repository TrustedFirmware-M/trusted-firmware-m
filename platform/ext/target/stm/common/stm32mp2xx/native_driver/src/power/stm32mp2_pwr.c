/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 */
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#include <debug.h>
#include <device.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <reset.h>

#include <stm32mp2_pwr_regs.h>
/* Necessary to detect cold boot case */
#include <cmsis.h>

/* Default value for STM32MP25 with STPMIC25, defined in AN5727 */
#define DEFAULT_POPL_D1			3U
#define DEFAULT_PODH_D2			1U
#define DEFAULT_POPL_D2			2U
#define DEFAULT_LPCFG_D2		1U	/* PWR_ON=0 for Standby1/2 = PMIC_PWRCTRL1 */
#define DEFAULT_LPLVDLY_D2		0U	/* 6xLSI cycle = 187 us */

struct stm32mp2_pwr_config {
	uintptr_t base;
	const struct reset_control rst_ctl_bck;
	uint32_t popl_d1_ms;
	uint32_t podh_d2_ms;
	uint32_t popl_d2_ms;
	uint32_t lpcfg_d2;
	uint32_t lplvdly_d2;
};

bool stm32_pwr_ddr_retention_get(const struct device *dev)
{
	const struct stm32mp2_pwr_config *dev_cfg = dev_get_config(dev);
	uintptr_t base = dev_cfg->base;

	return !(mmio_read_32(base + _PWR_CR11) & _CR11_DDRRETDIS);
}

void stm32_pwr_ddr_retention_set(const struct device *dev, bool enable)
{
	const struct stm32mp2_pwr_config *dev_cfg = dev_get_config(dev);
	uintptr_t base = dev_cfg->base;

	mmio_clrsetbits_32(base + _PWR_CR11, _CR11_DDRRETDIS,
			   enable ? 0 : _CR11_DDRRETDIS);
}

int stm32mp2_pwr_init(const struct device *dev)
{
	const struct stm32mp2_pwr_config *dev_cfg = dev_get_config(dev);
	uint32_t __maybe_unused bdcr;
	int __maybe_unused err;

#if defined(STM32_BL2)
	/*
	 * Disable the backup domain write protection.
	 * The protection is enable at each reset by hardware
	 * and must be disabled by software.
	 */
	mmio_setbits_32(dev_cfg->base + _PWR_BDCR1, _BDCR1_DBD3P);
	mmio_read32_poll_timeout(dev_cfg->base + _PWR_BDCR1,
				 bdcr, (bdcr &  _BDCR1_DBD3P), 0);

	/* Reset backup domain on cold boot cases */
	if (!(RCC->BDCR & RCC_BDCR_RTCCKEN)) {
		err = reset_control_reset(&dev_cfg->rst_ctl_bck);
		if (err)
			return err;
	}
#else
	/* Initialize PWR register with low power configuration and delay */
	mmio_write_32(dev_cfg->base + _PWR_D1CR,
		      _FLD_PREP(_D1CR_POPL_D1, dev_cfg->popl_d1_ms));

	mmio_write_32(dev_cfg->base + _PWR_D2CR,
		      _FLD_PREP(_D2CR_LPCFG_D2, dev_cfg->lpcfg_d2) |
		      _FLD_PREP(_D2CR_POPL_D2, dev_cfg->popl_d2_ms) |
		      _FLD_PREP(_D2CR_LPLVDLY_D2, dev_cfg->lplvdly_d2) |
		      _FLD_PREP(_D2CR_PODH_D2, dev_cfg->podh_d2_ms));

	/* Clear the CPU2 status flags on boot */
	io_setbits32(dev_cfg->base + _PWR_CPU2CR, _CPU2CR_CSSF);
#endif

	return 0;
}

/*
 * FIXME:
 * when we add supply domain managment, we need to create a power domain
 * framework.
 */
#define STM32MP2_PWR_INIT(n)						\
									\
static const struct stm32mp2_pwr_config stm32mp2_pwr_cfg_##n = {	\
	.base = DT_INST_REG_ADDR(n),					\
	.rst_ctl_bck = DT_INST_RESET_CONTROL_GET(n),			\
	.popl_d1_ms = DT_PROP_OR(n, st_popl_d1_ms, DEFAULT_POPL_D1),	\
	.podh_d2_ms = DT_PROP_OR(n, st_podh_d2_ms, DEFAULT_PODH_D2),	\
	.popl_d2_ms = DT_PROP_OR(n, st_popl_d2_ms, DEFAULT_POPL_D2),	\
	.lpcfg_d2 = DT_PROP_OR(n, st_lpcfg_d2, DEFAULT_LPCFG_D2),	\
	.lplvdly_d2 = DT_PROP_OR(n, st_lplvdly_d2, DEFAULT_LPLVDLY_D2),	\
};									\
									\
DEVICE_DT_INST_DEFINE(n, &stm32mp2_pwr_init, NULL,			\
		      NULL, &stm32mp2_pwr_cfg_##n,			\
		      STM32MP2_PWR_LVL, STM32MP2_PWR_PRIO, NULL);

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_pwr
DT_INST_FOREACH_STATUS_OKAY(STM32MP2_PWR_INIT)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp25_pwr
DT_INST_FOREACH_STATUS_OKAY(STM32MP2_PWR_INIT)
