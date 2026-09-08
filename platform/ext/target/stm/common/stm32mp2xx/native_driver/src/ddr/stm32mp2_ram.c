/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#define DT_DRV_COMPAT st_stm32mp2_ddr

#include <errno.h>
#include <inttypes.h>
#include <string.h>

#include <stm32mp_ddr_debug.h>
#include <stm32mp_ddr.h>
#include <stm32mp_ddr_test.h>
#include <stm32mp2_ddr.h>
#include <stm32mp2_ddr_helpers.h>
#include <stm32mp2_pwr.h>
#include <lib/mmio.h>
#include <lib/delay.h>

#include <ddrphy_phyinit.h>
#include <device.h>
#include <regulator.h>
#include <clk.h>

/*
 * Cortex-M33 address space is limited to 4GBytes.
 * Max DDR size is 0x8000 0000 (DDR_MEM_BASE is 0x8000 0000).
 * Warning: Cortex-M33 System control starts at 0xE000 0000,
 * but no access to this area is supposed to happen during tests.
 */
#define DDR_MAX_SIZE	0x80000000

uintptr_t stm32mp_ddrphyc_base(void)
{
	return DT_INST_REG_ADDR_BY_NAME(0, phy);
}

uintptr_t stm32mp_ddrctrl_base(void)
{
	return DT_INST_REG_ADDR_BY_NAME(0, ctrl);
}

uintptr_t stm32_ddrdbg_get_base(void)
{
	return DT_INST_REG_ADDR_BY_NAME(0, dbg);
}

uintptr_t stm32mp_rcc_base(void)
{
	return DT_REG_ADDR(DT_NODELABEL(rcc));
}

int stm32mp_board_ddr_power_init(enum ddr_type ddr_type)
{
#if STM32MP_LPDDR4_TYPE
	const struct device *dev_vdd1, *dev_vdd2, *dev_vddq;
	int err;

	/*
	 * LPDDR4 power on sequence is:
	 * enable VDD1_DDR
	 * enable VDD2_DDR
	 * enable VDDQ_DDR
	 */

	dev_vdd1 = DT_INST_DEV_REGULATOR_SUPPLY(0, vdd1);
	if (!dev_vdd1)
		return -ENODEV;

	err = regulator_common_set_min_voltage(dev_vdd1);
	if (err)
		return err;

	dev_vdd2 = DT_INST_DEV_REGULATOR_SUPPLY(0, vdd2);
	if (!dev_vdd2)
		return -ENODEV;

	err = regulator_common_set_min_voltage(dev_vdd2);
	if (err)
		return err;

	dev_vddq = DT_INST_DEV_REGULATOR_SUPPLY(0, vddq);
	if (!dev_vddq)
		return -ENODEV;

	err = regulator_common_set_min_voltage(dev_vddq);
	if (err)
		return err;

	err = regulator_enable(dev_vdd1);
	if (err)
		return err;

	/* could be set via enable_ramp_delay on vdd1_ddr */
	udelay(2000);

	err = regulator_enable(dev_vdd2);
	if (err)
		return err;

	return regulator_enable(dev_vddq);

#else
	const struct device *dev_vpp, *dev_vref, *dev_vtt, *dev_vdd;
	int err;

	/*
	 * LPDDR4 power on sequence is:
	 * enable VPP_DDR
	 * enable VREF_DDR
	 * enable VPP_DDR
	 * enable VDD_DDR
	 */

	dev_vpp = DT_INST_DEV_REGULATOR_SUPPLY(0, vpp);
	if (!dev_vpp)
		return -ENODEV;

	err = regulator_common_set_min_voltage(dev_vpp);
	if (err)
		return err;

	dev_vref = DT_INST_DEV_REGULATOR_SUPPLY(0, vref);
	if (!dev_vref)
		return -ENODEV;

	dev_vtt = DT_INST_DEV_REGULATOR_SUPPLY(0, vtt);
	if (!dev_vtt)
		return -ENODEV;

	dev_vdd = DT_INST_DEV_REGULATOR_SUPPLY(0, vdd);
	if (!dev_vdd)
		return -ENODEV;

	err = regulator_common_set_min_voltage(dev_vdd);
	if (err)
		return err;

	err = regulator_enable(dev_vpp);
	if (err)
		return err;

	/* could be set via enable_ramp_delay on vpp_ddr */
	udelay(2000);

	err = regulator_enable(dev_vref);
	if (err)
		return err;

	err = regulator_enable(dev_vtt);
	if (err)
		return err;

	err = regulator_enable(dev_vdd);
	if (err)
		return err;

#endif
	return 0;
}

#define DDR_CLK_DEV	DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(0))
#define DDR_CLK_ID	DT_INST_CLOCKS_CELL(0, bits)

int stm32mp2_ddr_dt_init(void)
{
	unsigned long ret;
	struct clk *clk;
	size_t retsize;

	const struct stm32mp_ddr_config drv_cfg = {
		.info = {
			.speed = DT_INST_PROP(0, st_mem_speed),
			.size = ((uint64_t)DT_INST_PROP_BY_IDX(0, st_mem_size, 0) << 32) |
				(DT_INST_PROP_BY_IDX(0, st_mem_size, 1)),
			.name = DT_INST_PROP(0, st_mem_name),
		},
		.c_reg = DT_INST_PROP(0, st_ctl_reg),
		.c_timing = DT_INST_PROP(0, st_ctl_timing),
		.c_map = DT_INST_PROP(0, st_ctl_map),
		.c_perf = DT_INST_PROP(0, st_ctl_perf),
		.uib = DT_INST_PROP(0, st_phy_basic),
		.uia = DT_INST_PROP(0, st_phy_advanced),
		.uim = DT_INST_PROP(0, st_phy_mr),
		.uis = DT_INST_PROP(0, st_phy_swizzle),
	};

	struct stm32mp_ddr_priv drv_data = {
		.info = {
			.base = DDR_MEM_BASE,
			.size = DDR_MAX_SIZE,
		},
		.ctl = (struct stm32mp_ddrctl *)DT_INST_REG_ADDR_BY_NAME(0, ctrl),
		.phy = (struct stm32mp_ddrphy *)DT_INST_REG_ADDR_BY_NAME(0, phy),
		.pwr = stm32_pwr_dev(),
		.rcc = DT_REG_ADDR(DT_NODELABEL(rcc)),
	};

	clk = clk_get(DDR_CLK_DEV, (clk_subsys_t)DDR_CLK_ID);
	if (!clk)
		return -ENODEV;

	ret = clk_enable(clk);
	if (ret)
		return ret;

	/* Limit drv_data.info.size if size is lower on device tree side */
	if (drv_cfg.info.size < (uint64_t)drv_data.info.size)
		drv_data.info.size = (size_t)drv_cfg.info.size;

	stm32mp2_ddr_init(&drv_data, &drv_cfg);

	ret = stm32mp_ddr_test_data_bus(drv_data.info.base);
	if (ret != 0UL) {
		DDR_ERROR("DDR data bus test: can't access memory @ %#lx\n", ret);
		panic();
	}

	ret = stm32mp_ddr_test_addr_bus(drv_data.info.base, drv_data.info.size);
	if (ret != 0UL) {
		DDR_ERROR("DDR addr bus test: can't access memory @ %#lx\n", ret);
		panic();
	}

	retsize = stm32mp_ddr_check_size(drv_data.info.base, drv_data.info.size);
	if (retsize < drv_data.info.size) {
		DDR_ERROR("DDR size: 0x%x does not match initial config: 0x%x\n",
			  (uint32_t)retsize, (uint32_t)drv_data.info.size);
		panic();
	}

	if ((uint64_t)drv_data.info.size != drv_cfg.info.size)
		DDR_INFO("Memory size (M33 side) = 0x%x (%u MB)\n",
			 (uint32_t)retsize, (uint32_t)(retsize / (1024U * 1024U)));

	/*
	 * This driver is used in BL2 with minimal printf implementation.
	 * Long long formatters such as %llx are not supported in this case.
	 * To avoid using 64bit format specifier, the size is printed in two 32bit values.
	 */
	DDR_INFO("Memory size = 0x%x%08x (%u MB)\n",
		 (uint32_t)(drv_cfg.info.size >> 32),
		 (uint32_t)(drv_cfg.info.size & 0xFFFFFFFF),
		 (uint32_t)(drv_cfg.info.size / (1024U * 1024U)));

	/*
	 * Initialization sequence has configured DDR registers with settings.
	 * The Self Refresh (SR) mode corresponding to these settings has now
	 * to be set.
	 */
	ddr_set_sr_mode(ddr_read_sr_mode());

	return 0;
}

#define CHECK_DT_VS_STRUCT(prop, struct_name) \
	(DT_INST_PROP_LEN(0, prop) == (sizeof(struct struct_name) / sizeof(uint32_t)))

BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_phy_basic, user_input_basic),
	     "st,phy-basic property not match with user_input_basic size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_phy_advanced, user_input_advanced),
	     "st,phy-advanced property not match with user_input_advanced size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_phy_mr, user_input_mode_register),
	     "st,phy-mr property not match with user_input_mode_register size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_phy_swizzle, user_input_swizzle),
	     "st,phy-swizzle property not match with user_input_swizzle size");

BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_ctl_reg, stm32mp2_ddrctrl_reg),
	     "st,ctl-reg property not match with stm32mp2_ddrctrl_reg size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_ctl_timing, stm32mp2_ddrctrl_timing),
	     "st,ctl-timing property not match with stm32mp2_ddrctrl_timing size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_ctl_map, stm32mp2_ddrctrl_map),
	     "st,ctl-map property not match with stm32mp2_ddrctrl_map size");
BUILD_ASSERT(CHECK_DT_VS_STRUCT(st_ctl_perf, stm32mp2_ddrctrl_perf),
	     "st,ctl-perf property not match with stm32mp2_ddrctrl_perf size");
