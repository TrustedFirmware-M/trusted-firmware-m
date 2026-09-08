/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#define DT_DRV_COMPAT st_stm32mp25_rcc_reset

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <debug.h>

#include <device.h>
#include <reset.h>

#if defined(STM32MP21xxxx)
#include <dt-bindings/reset/st,stm32mp21-rcc.h>
#else
#include <dt-bindings/reset/st,stm32mp25-rcc.h>
#endif

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,
	     "only one rcc reset compatible node is supported");

#define RESET_ID_MASK		GENMASK_32(31, 5)
#define RESET_ID_SHIFT		5
#define RESET_BIT_POS_MASK	GENMASK_32(4, 0)
#define RESET_OFFSET_MAX	1024

#define RESET_OFFSET(__id)	(((__id & RESET_ID_MASK) >> RESET_ID_SHIFT) \
				 * sizeof(uint32_t))
#define RESET_BIT(__id)		BIT((__id & RESET_BIT_POS_MASK))

/* registers offset */
#define _RCC_BDCR		U(0X400)
#define _RCC_C1RSTCSETR		U(0x404)
#define _RCC_C2BOOTRSTSCLRR	U(0x428)
#define _RCC_CPUBOOTCR		U(0x434)

/* Bit definition for RCC_C2BOOTRSTSCLRR register */
#define _C2BOOTRSTSCLRR_PORRSTF			BIT(0)
#define _C2BOOTRSTSCLRR_BORRSTF			BIT(1)
#define _C2BOOTRSTSCLRR_PADRSTF			BIT(2)
#define _C2BOOTRSTSCLRR_HCSSRSTF		BIT(3)
#define _C2BOOTRSTSCLRR_VCORERSTF		BIT(4)
#define _C2BOOTRSTSCLRR_SYSC1RSTF		BIT(6)
#define _C2BOOTRSTSCLRR_SYSC2RSTF		BIT(7)
#define _C2BOOTRSTSCLRR_IWDG1SYSRSTF		BIT(8)
#define _C2BOOTRSTSCLRR_IWDG2SYSRSTF		BIT(9)
#define _C2BOOTRSTSCLRR_IWDG3SYSRSTF		BIT(10)
#define _C2BOOTRSTSCLRR_IWDG4SYSRSTF		BIT(11)
#define _C2BOOTRSTSCLRR_IWDG5SYSRSTF		BIT(12)
#define _C2BOOTRSTSCLRR_C2RSTF			BIT(14)
#define _C2BOOTRSTSCLRR_RETCRCERRRSTF		BIT(17)
#define _C2BOOTRSTSCLRR_RETECCFAILCRCRSTF	BIT(18)
#define _C2BOOTRSTSCLRR_RETECCFAILRESTRSTF	BIT(19)
#define _C2BOOTRSTSCLRR_STBYC2RSTF		BIT(21)
#define _C2BOOTRSTSCLRR_D2STBYRSTF		BIT(23)

#define _C2BOOTRSTSCLRR_IWDGXSYSRSTF (_C2BOOTRSTSCLRR_IWDG1SYSRSTF | \
				      _C2BOOTRSTSCLRR_IWDG2SYSRSTF | \
				      _C2BOOTRSTSCLRR_IWDG3SYSRSTF | \
				      _C2BOOTRSTSCLRR_IWDG4SYSRSTF | \
				      _C2BOOTRSTSCLRR_IWDG5SYSRSTF)

#define _C2BOOTRSTSCLRR_RETRAMERRF (_C2BOOTRSTSCLRR_RETCRCERRRSTF | \
				    _C2BOOTRSTSCLRR_RETECCFAILCRCRSTF | \
				    _C2BOOTRSTSCLRR_RETECCFAILRESTRSTF)

#define _RCC_BDCR_RTCSRC_MASK	GENMASK(17, 16)

#define CPUBOOT_BIT(__offset)	__offset == _RCC_C1RSTCSETR ? BIT(1) : BIT(0)

#define TIMEOUT_RESET_US	USEC_PER_MSEC

struct stm32_reset_config {
	uintptr_t base;
};

static int _reset(const struct device *dev, uint32_t id, unsigned int to_us)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t addr = drv_cfg->base + RESET_OFFSET(id);
	uint32_t rst_mask = RESET_BIT(id);
	uint32_t cfgr;

	/* assert reset */
	io_setbits32(addr, rst_mask);

	if (!to_us)
		return 0;
	/* poll for reset deassert */
	return mmio_read32_poll_timeout(addr, cfgr, (~cfgr & rst_mask), to_us);
}

static int _assert(const struct device *dev, uint32_t id, unsigned int to_us)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t addr = drv_cfg->base + RESET_OFFSET(id);
	uint32_t rst_mask = RESET_BIT(id);
	uint32_t cfgr;

	io_setbits32(addr, rst_mask);

	if (!to_us)
		return 0;

	return  mmio_read32_poll_timeout(addr, cfgr, (cfgr & rst_mask), to_us);
}

static int _deassert(const struct device *dev, uint32_t id, unsigned int to_us)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t addr = drv_cfg->base + RESET_OFFSET(id);
	uint32_t rst_mask = RESET_BIT(id);
	uint32_t cfgr;

	io_clrbits32(addr, rst_mask);

	if (!to_us)
		return 0;

	return mmio_read32_poll_timeout(addr, cfgr, (~cfgr & rst_mask), to_us);
}

int _stm32_reset_status(const struct device *dev, uint32_t id)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t addr = drv_cfg->base + RESET_OFFSET(id);
	uint32_t reg;

	reg = io_read32(addr);

	return !!(reg & RESET_BIT(id));
}

int _stm32_reset_assert(const struct device *dev, uint32_t id)
{
	return _assert(dev, id, 0);
}

int _stm32_reset_deassert(const struct device *dev, uint32_t id)
{
	return _deassert(dev, id, 0);
}

int _stm32_reset_reset(const struct device *dev, uint32_t id)
{
	int err;

	err = _assert(dev, id, TIMEOUT_RESET_US);
	if (err)
		return err;

	return _deassert(dev, id, TIMEOUT_RESET_US);
}

static const struct reset_driver_api stm32_reset_ops = {
	.status = _stm32_reset_status,
	.assert_level = _stm32_reset_assert,
	.deassert_level = _stm32_reset_deassert,
	.reset = _stm32_reset_reset,
};

int _stm32_reset_only(const struct device *dev, uint32_t id)
{
	return _reset(dev, id, TIMEOUT_RESET_US);
}

static const struct reset_driver_api stm32_reset_only_ops = {
	.reset = _stm32_reset_only,
};

static int _cpu_assert(const struct device *dev, uint32_t id)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base;
	uintptr_t addr = base + _RCC_CPUBOOTCR;
	uint32_t rst_offset = RESET_OFFSET(id);
	uint32_t rst_mask = RESET_BIT(id);
	uint32_t cpu_mask = CPUBOOT_BIT(rst_offset);
	uint32_t cfgr;
	int err;

	/*  Set hold boot to block execution after reset */
	io_clrbits32(addr, cpu_mask);
	err = mmio_read32_poll_timeout(addr, cfgr, (~cfgr & cpu_mask), 1);

	io_setbits32(base + rst_offset, rst_mask);

	return err;
}

static int _cpu_deassert(const struct device *dev, uint32_t id)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t addr = drv_cfg->base + _RCC_CPUBOOTCR;
	uint32_t rst_offset = RESET_OFFSET(id);
	uint32_t cpu_mask = CPUBOOT_BIT(rst_offset);
	uint32_t cfgr;
	int err;

	/* release CPU after the reset: disable HOLD boot */
	io_setbits32(addr, cpu_mask);

	/* 1 us timeout to get hold boot not set */
	err = mmio_read32_poll_timeout(addr, cfgr, (cfgr & cpu_mask), 1);

	return err;
}

int _stm32_reset_cpu_assert(const struct device *dev, uint32_t id)
{
	return _cpu_assert(dev, id);
}

int _stm32_reset_cpu_deassert(const struct device *dev, uint32_t id)
{
	return _cpu_deassert(dev, id);
}

int _stm32_reset_cpu_reset(const struct device *dev, uint32_t id)
{
	int err;

	err = _stm32_reset_cpu_assert(dev, id);
	if (err)
		return err;

	return _stm32_reset_cpu_deassert(dev, id);
}

static const struct reset_driver_api stm32_reset_cpu_ops = {
	.assert_level = _stm32_reset_cpu_assert,
	.deassert_level = _stm32_reset_cpu_deassert,
	.reset = _stm32_reset_cpu_reset
};

int _stm32_reset_vsw_assert(const struct device *dev, uint32_t id)
{
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base;

	if ((io_read32(base + _RCC_BDCR) & _RCC_BDCR_RTCSRC_MASK))
		return 0;

	/* Reset backup domain on cold boot cases */
	return _assert(dev, id, 0);
}

int _stm32_reset_vsw_reset(const struct device *dev, uint32_t id)
{
	int err;

	err = _stm32_reset_vsw_assert(dev, id);
	if (err)
		return err;

	return _stm32_reset_deassert(dev, id);
}

static const struct reset_driver_api stm32_reset_vsw_ops = {
	.assert_level = _stm32_reset_vsw_assert,
	.deassert_level = _stm32_reset_deassert,
	.reset = _stm32_reset_vsw_reset,
};

#if defined(GPU_R)
#define stm32_reset_only(_id) (_id == GPU_R)
#else
#define stm32_reset_only(_id) (0)
#endif

#define stm32_reset_op(_op, _dev, _id)			\
({							\
	const struct reset_driver_api *ops;		\
							\
	if (_id == C1_R)				\
		ops = &stm32_reset_cpu_ops;		\
	else if (_id == VSW_R)				\
		ops = &stm32_reset_vsw_ops;		\
	else if stm32_reset_only(_id)			\
		ops = &stm32_reset_only_ops;		\
	else						\
		ops = &stm32_reset_ops;			\
							\
	(!ops->_op) ? -ENOSYS : ops->_op(_dev, _id);	\
})

int stm32_reset_com_status(const struct device *dev, uint32_t id)
{
	return stm32_reset_op(status, dev, id);
}

int stm32_reset_com_assert(const struct device *dev, uint32_t id)
{
	return stm32_reset_op(assert_level, dev, id);
}

int stm32_reset_com_deassert(const struct device *dev, uint32_t id)
{
	return stm32_reset_op(deassert_level, dev, id);
}

int stm32_reset_com_reset(const struct device *dev, uint32_t id)
{
	return stm32_reset_op(reset, dev, id);
}

static const struct reset_driver_api stm32_reset_com_api = {
	.status = stm32_reset_com_status,
	.assert_level = stm32_reset_com_assert,
	.deassert_level = stm32_reset_com_deassert,
	.reset = stm32_reset_com_reset,
};

static const struct stm32_reset_config stm32_reset_cfg = {
	.base = DT_REG_ADDR(DT_INST_PARENT(0)),
};

DEVICE_DT_INST_DEFINE(0,
		      NULL, NULL,
		      NULL, &stm32_reset_cfg,
		      PRE_CORE, 0,
		      &stm32_reset_com_api);

static int __unused stm32_reset_reason(void)
{
	const struct device *dev = DEVICE_DT_INST_GET(0);
	const struct stm32_reset_config *drv_cfg = dev_get_config(dev);
	const char *reason_str = "Unidentified";
	uint32_t rstsr;

	rstsr = io_read32(drv_cfg->base + _RCC_C2BOOTRSTSCLRR);

	if (rstsr & _C2BOOTRSTSCLRR_PADRSTF) {
		if (rstsr & _C2BOOTRSTSCLRR_PORRSTF)
			reason_str = "Power-on reset (por_rstn)";
		else if (rstsr & _C2BOOTRSTSCLRR_BORRSTF)
			reason_str = "Brownout reset (bor_rstn)";
		else if (rstsr & (_C2BOOTRSTSCLRR_SYSC2RSTF |
				     _C2BOOTRSTSCLRR_SYSC1RSTF))
			reason_str = "System reset (SYSRST)";
		else if (rstsr & _C2BOOTRSTSCLRR_HCSSRSTF)
			reason_str = "Clock failure on HSE";
		else if (rstsr & _C2BOOTRSTSCLRR_IWDGXSYSRSTF)
			reason_str = "IWDG system reset (iwdgX_out_rst)";
		else if (rstsr & _C2BOOTRSTSCLRR_RETRAMERRF)
			reason_str = "System exits from Standby with errors";
		else
			reason_str = "Pin reset from NRST";
	} else {
		if (rstsr & (_C2BOOTRSTSCLRR_STBYC2RSTF |
			      _C2BOOTRSTSCLRR_D2STBYRSTF))
			reason_str = "System exits from Standby";
		else if (rstsr & _C2BOOTRSTSCLRR_C2RSTF)
			reason_str = "CM33 reset by CA35 (C2RST)";
	}

	IMSG("Reset reason: %s (0x%x)", reason_str, rstsr);

	return 0;
}

#if defined(STM32_M33TDCID) && (STM32_BL2)
SYS_INIT(stm32_reset_reason, CORE, 2);
#endif
