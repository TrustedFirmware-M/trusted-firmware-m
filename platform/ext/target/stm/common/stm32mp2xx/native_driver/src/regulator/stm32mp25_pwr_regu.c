/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Gabriel Fernandez, <gabriel.fernandez@foss.st.com> for STMicroelectronics.
 */
#define STM32MP21_COMPAT st_stm32mp21_pwr_regulators
#define STM32MP25_COMPAT st_stm32mp25_pwr_regulators

// include generic device api and devicetree
#include <device.h>
#include <debug.h>
#include <regulator.h>

#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/delay.h>
#include <lib/utils_def.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <syscon.h>

#include <stm32mp2_pwr_regs.h>

#define TIMEOUT_US_10MS		U(10000)
#define DELAY_100US		U(100)

#define IOCOMP_CODE_MAX		U(2)

#define IO_VOLTAGE_THRESHOLD_UV	2700000

/*
 * SYSCFG IO compensation register offsets (base relative)
 */

#define VDDIO1_OFFSET		0x20U
#define VDDIO2_OFFSET		0x18U
#define VDDIO3_OFFSET		0x0U
#define VDDIO4_OFFSET		0x8U
#define VDDIO_OFFSET		0x10U

/*
 * struct pwr_regu - PWR regulator instance
 *
 * @enable_reg: Offset of regulator enable register in PWR IOMEM interface
 * @enable_mask: Bitmask of regulator enable bit in PWR IOMEM register
 * @ready_mask: Bitmask of regulator enable status bit in PWR IOMEM register
 * @valid_mask: Bitmask of regulator valid state bit in PWR IOMEM register
 * @vrsel_mask: Bitmask of reference voltage switch in PWR IOMEM register
 * @comp_idx: Index on compensation cell in SYSCFG IO domain
 * @is_an_iod: True if regulator relates to an IO domain, else false
 * @keep_monitor_on: True if regulator required monitoring state (see refman)
 */
struct stm32_pwr_regu {
	uint32_t enable_reg;
	uint32_t enable_mask;
	uint32_t ready_mask;
	uint32_t valid_mask;
	uint32_t vrsel_mask;

	/*
	 * An IO domain is a power switch, meaning that
	 * its output voltage follows its power supply voltage
	 * and the IOs have IO compensation cell
	 */
	bool is_an_iod;
	uint16_t iod_offset;

	bool keep_monitor_on;

	/*
	 * Has_clamp: The VDDA regulator implements a workaround
	 * to reduce power consumption that occurs when the regulator
	 * is disabled but its supply is still present.
	 * In this case, activating the monitor also activates a clamping
	 * mechanism.
	 */
	bool has_clamp;

	const struct device *vin_supply;

	const uint32_t iocomp_code[IOCOMP_CODE_MAX];
	uint32_t n_iocomp_code;
};

struct stm32_pwr_regu_config {
	struct regulator_common_config common;
	struct stm32_pwr_regu pwr_regu;
	uintptr_t base;
	const struct device *syscfg_dev;
	uint16_t syscfg_base;
};

struct stm32_pwr_regu_data {
	struct regulator_common_data data;
	bool suspend_state;
	int32_t suspend_uv;
};

/* IO compensation CCR registers bit definition */
#define SYSCFG_CCCR_CS				BIT(9)
#define SYSCFG_CCCR_EN				BIT(8)
#define SYSCFG_CCCR_RAPSRC_MASK			GENMASK_32(7, 4)
#define SYSCFG_CCCR_RAPSRC_SHIFT		4U
#define SYSCFG_CCCR_RANSRC_MASK			GENMASK_32(3, 0)
#define SYSCFG_CCCR_RANSRC_SHIFT		0U

/* IO compensation CCSR registers bit definition */
#define SYSCFG_CCSR_READY			BIT(8)
#define SYSCFG_CCSR_APSRC_MASK			GENMASK_32(7, 4)
#define SYSCFG_CCSR_ANSRC_MASK			GENMASK_32(3, 0)

#define SYSCFG_CCSR_OFFSET			4U

#define SYSCFG_CCSR_READY_TIMEOUT_US		U(1000)

static int stm32_pwr_enable_io_compensation(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uint32_t cccr_addr;
	uint32_t ccsr_addr;
	uint32_t value = 0U;
	int ret;

	cccr_addr = drv_cfg->syscfg_base + pwr_regu->iod_offset;
	ccsr_addr = cccr_addr + SYSCFG_CCSR_OFFSET;

	syscon_read(drv_cfg->syscfg_dev, ccsr_addr, &value);
	if (value & SYSCFG_CCSR_READY)
		return 0;

	syscon_setbits(drv_cfg->syscfg_dev, cccr_addr, SYSCFG_CCCR_EN);

	ret = syscon_read_poll_timeout(drv_cfg->syscfg_dev,
				       ccsr_addr,
				       value, (value & SYSCFG_CCSR_READY),
				       SYSCFG_CCSR_READY_TIMEOUT_US);
	if (ret) {
		EMSG("IO compensation cell not ready\n");
		return -EBUSY;
	}

	syscon_clrbits(drv_cfg->syscfg_dev, cccr_addr, SYSCFG_CCCR_CS);

	return 0;
}

static int stm32_pwr_disable_io_compensation(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uint32_t cccr_addr;
	uint32_t ccsr_addr;
	uint32_t value = 0;

	cccr_addr = drv_cfg->syscfg_base + pwr_regu->iod_offset;
	ccsr_addr = cccr_addr + SYSCFG_CCSR_OFFSET;

	syscon_read(drv_cfg->syscfg_dev, ccsr_addr, &value);
	if (!(value & SYSCFG_CCSR_READY))
		return 0;

	syscon_read(drv_cfg->syscfg_dev, ccsr_addr, &value);
	value &= (SYSCFG_CCSR_APSRC_MASK | SYSCFG_CCSR_ANSRC_MASK);

	syscon_clrsetbits(drv_cfg->syscfg_dev, cccr_addr,
			  SYSCFG_CCCR_RAPSRC_MASK | SYSCFG_CCCR_RANSRC_MASK,
			  value);

	syscon_setbits(drv_cfg->syscfg_dev, cccr_addr, SYSCFG_CCCR_CS);
	syscon_clrbits(drv_cfg->syscfg_dev, cccr_addr, SYSCFG_CCCR_EN);

	return 0;
}

static int stm32_pwr_fixed_io_compensation(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uint32_t cccr_addr;
	uint32_t value;

	if (pwr_regu->n_iocomp_code != IOCOMP_CODE_MAX)
		return -EINVAL;

	cccr_addr = drv_cfg->syscfg_base + pwr_regu->iod_offset;
	value = _FLD_PREP(SYSCFG_CCCR_RAPSRC, pwr_regu->iocomp_code[0]) |
	        _FLD_PREP(SYSCFG_CCCR_RANSRC, pwr_regu->iocomp_code[1]);
	syscon_write(drv_cfg->syscfg_dev, cccr_addr, value);

	return 0;
}

static int stm32_pwr_enable_reg(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uintptr_t reg = drv_cfg->base + pwr_regu->enable_reg;
	int err;
	uint32_t sr;

	if (!pwr_regu->enable_mask)
		return 0;

	mmio_setbits_32(reg, pwr_regu->enable_mask);

	/* Wait for vddgpu to enable as stated in the reference manual */
	if (pwr_regu->keep_monitor_on)
		udelay(DELAY_100US);

	err = mmio_read32_poll_timeout(reg, sr, (sr & pwr_regu->ready_mask),
				       TIMEOUT_US_10MS);
	if (err) {
		mmio_clrbits_32(reg, pwr_regu->enable_mask);

		return -EBUSY;
	}

	mmio_setbits_32(reg, pwr_regu->valid_mask);

	/*
	 * Disable voltage monitor to reduce consumption.
	 * Not for GPU or for clamp workaround
	 */
	if (!(pwr_regu->keep_monitor_on || pwr_regu->has_clamp))
		mmio_clrbits_32(reg, pwr_regu->enable_mask);

	return 0;
}

static void stm32_pwr_disable_reg(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uintptr_t reg = drv_cfg->base + pwr_regu->enable_reg;

	if (pwr_regu->enable_mask) {
		io_clrbits32(reg, pwr_regu->valid_mask);

		if (pwr_regu->has_clamp)
			io_setbits32(reg, pwr_regu->enable_mask);
		else
			io_clrbits32(reg, pwr_regu->enable_mask);
	}
}

static bool __maybe_unused stm32_pwr_get_state_reg(const struct stm32_pwr_regu_config *drv_cfg)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uintptr_t reg = drv_cfg->base + pwr_regu->enable_reg;
	bool enabled = true;

	if (pwr_regu->enable_mask)
		enabled = !!(io_read32(reg) & pwr_regu->valid_mask);

	return enabled;
}

static int stm32_pwr_enable(const struct device *dev)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	int res;

	if (pwr_regu->vin_supply) {
		res = regulator_enable(pwr_regu->vin_supply);
		if (res)
			return res;
	}

	res = stm32_pwr_enable_reg(drv_cfg);
	if (res) {
		if (pwr_regu->vin_supply)
			goto err;

		return res;
	}

	if (pwr_regu->is_an_iod && !pwr_regu->n_iocomp_code)  {
		res = stm32_pwr_enable_io_compensation(drv_cfg);
		if (res) {
			stm32_pwr_disable_reg(drv_cfg);
			goto err;
		}
	}

	return 0;

err:
	if (pwr_regu->vin_supply) {
		if (regulator_disable(pwr_regu->vin_supply))
			panic();
	}

	return res;
}

static int stm32_pwr_disable(const struct device *dev)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

	if (pwr_regu->is_an_iod && !pwr_regu->n_iocomp_code)
		stm32_pwr_disable_io_compensation(drv_cfg);

	stm32_pwr_disable_reg(drv_cfg);

	if (pwr_regu->vin_supply)
		regulator_disable(pwr_regu->vin_supply);

	return 0;
}

static unsigned int stm32_pwr_count_voltages(const struct device *dev)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

	return regulator_count_voltages(pwr_regu->vin_supply);
}

static int stm32_pwr_list_voltage(const struct device *dev, unsigned int idx,
				     int32_t *volt_uv)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

	return regulator_list_voltage(pwr_regu->vin_supply, idx, volt_uv);
}

static int stm32_pwr_set_low_volt(const struct stm32_pwr_regu_config *drv_cfg,
				  bool state)
{
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uintptr_t reg = drv_cfg->base + pwr_regu->enable_reg;

	if (pwr_regu->vrsel_mask) {
		if (state) {
			io_setbits32(reg, pwr_regu->vrsel_mask);

			if (!(io_read32(reg) & pwr_regu->vrsel_mask))
				return -EBUSY;

		} else {
			io_clrbits32(reg, pwr_regu->vrsel_mask);
		}
	}

	return 0;
}

static int stm32_pwr_set_voltage(const struct device *dev, int32_t min_uv,
				 int32_t max_uv)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	bool is_enabled = regulator_is_enabled(dev);
	int32_t level_uv = max_uv;
	int res;

	/* Isolate IOs and disable IOs compensation */
	if (is_enabled) {
		res = stm32_pwr_disable(dev);
		if (res)
			return res;
	}

	/* Set IO to high voltage */
	if (level_uv >= IO_VOLTAGE_THRESHOLD_UV) {
		res = stm32_pwr_set_low_volt(drv_cfg, false);
		if (res)
			return res;
	}

	/* Forward set voltage request to the power supply */
	res = regulator_set_voltage(pwr_regu->vin_supply, min_uv, max_uv);
	if (res) {
		/* Continue to restore IOs setting for current voltage */
		res = regulator_get_voltage(pwr_regu->vin_supply, &level_uv);
		if (res)
			return res;
	}

	if (level_uv < IO_VOLTAGE_THRESHOLD_UV) {
		res = stm32_pwr_set_low_volt(drv_cfg, true);
		if (res)
			return res;
	}

	/* De-isolate IOs and enable IOs compensation */
	if (is_enabled) {
		res = stm32_pwr_enable(dev);
		if (res)
			return res;
	}

	return 0;
}

static int stm32_pwr_get_voltage(const struct device *dev, int32_t *volt_uv)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

	return regulator_get_voltage(pwr_regu->vin_supply, volt_uv);
}

static int stm32_pwr_get_default_voltage(const struct device *dev,
					 int32_t *volt_uv)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

	return regulator_get_default_voltage(pwr_regu->vin_supply, volt_uv);
}

static const struct regulator_driver_api stm32_pwr_regu_ops = {
	.enable = stm32_pwr_enable,
	.disable = stm32_pwr_disable,
	.count_voltages = stm32_pwr_count_voltages,
	.list_voltage = stm32_pwr_list_voltage,
	.set_voltage = stm32_pwr_set_voltage,
	.get_voltage = stm32_pwr_get_voltage,
	.get_default_voltage = stm32_pwr_get_default_voltage,
};

static const struct regulator_driver_api stm32_pwr_regu_fixed_ops = {
	.enable = stm32_pwr_enable,
	.disable = stm32_pwr_disable,
	.get_voltage = stm32_pwr_get_voltage,
	.count_voltages = stm32_pwr_count_voltages,
	.list_voltage = stm32_pwr_list_voltage,

};

static int stm32_pwr_regulator_init(const struct device *dev)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	int err;

	regulator_common_data_init(dev);

	err = regulator_common_init(dev, false);
	if (err)
		return err;

	if (pwr_regu->is_an_iod) {
		int32_t level_uv = 0;

		if (pwr_regu->n_iocomp_code) {
			err = stm32_pwr_fixed_io_compensation(drv_cfg);
			if (err)
				return err;
		}

		err = stm32_pwr_get_voltage(dev, &level_uv);
		if (err)
			return err;

		if (level_uv < IO_VOLTAGE_THRESHOLD_UV) {
			err = stm32_pwr_set_low_volt(drv_cfg, true);
			if (err) {
				EMSG("%s: set VRSEL failed\n", dev->name);
				return err;
			}
		}
	}

	if (pwr_regu->has_clamp)
		io_setbits32(drv_cfg->base + pwr_regu->enable_reg, pwr_regu->enable_mask);

	return 0;
}

/*
 * Errata
 *
 * On A35 co-processor boot, the boot rom modifies regulator value without
 * taking care of pwr VDD I/O voltage range selection.
 * This function is called after A35 has started to update vddio range selection bit
 * based on the current voltage range.
 */
__unused static void _stm32_pwr_bootrom_errata(const struct device **regu_devices, uint32_t nb_regu)
{
	for (size_t i = 0; i < nb_regu; i++) {
		const struct device *dev = regu_devices[i];
		const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
		const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;

		if (pwr_regu->is_an_iod) {
			int32_t level_uv = 0;

			stm32_pwr_get_voltage(dev, &level_uv);

			if (level_uv < IO_VOLTAGE_THRESHOLD_UV) {
				if (stm32_pwr_set_low_volt(drv_cfg, true))
					EMSG("%s: set VRSEL failed\n", dev->name);
			}
		}
	}
}

#ifdef CONFIG_PM_DEVICE
static bool stm32_pwr_get_state(const struct device *dev)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	uintptr_t reg = drv_cfg->base + pwr_regu->enable_reg;

	if (pwr_regu->enable_reg)
		return !!(io_read32(reg) & pwr_regu->valid_mask);

	return true;
}

/* Restore the PWR regulator state, includng IOCOMP but without vin_supply */
static int stm32_pwr_set_state(const struct device *dev, bool state)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	bool is_enabled = stm32_pwr_get_state_reg(drv_cfg);
	int res;

	if (state) {
		if (!is_enabled) {
			res = stm32_pwr_enable_reg(drv_cfg);
			if (res)
				return res;
		}

		if (pwr_regu->is_an_iod && !pwr_regu->n_iocomp_code)  {
			res = stm32_pwr_enable_io_compensation(drv_cfg);
			if (res) {
				stm32_pwr_disable_reg(drv_cfg);
				return res;
			}
		}
	} else {
		if (pwr_regu->is_an_iod && !pwr_regu->n_iocomp_code)
			stm32_pwr_disable_io_compensation(drv_cfg);

		if (is_enabled)
			stm32_pwr_disable_reg(drv_cfg);
	}

	return 0;
}

static int stm32_pwr_regulator_pm_action(const struct device *dev,
					 enum pm_device_action action,
					 uint32_t pm_hint)
{
	const struct stm32_pwr_regu_config *drv_cfg = dev_get_config(dev);
	const struct stm32_pwr_regu *pwr_regu = &drv_cfg->pwr_regu;
	struct stm32_pwr_regu_data *drv_data = dev_get_data(dev);
	int err;

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		drv_data->suspend_state = stm32_pwr_get_state(dev);
		if (pwr_regu->is_an_iod) {
			err = stm32_pwr_get_voltage(dev, &drv_data->suspend_uv);
			if (err)
				return err;

			/* Disable low voltage mode to protect IOs */
			err = stm32_pwr_set_low_volt(drv_cfg, false);
			if (err)
				return err;

			if (!pwr_regu->n_iocomp_code)
				stm32_pwr_disable_io_compensation(drv_cfg);
		}
	} else {
		if (pwr_regu->is_an_iod) {
			if (pwr_regu->n_iocomp_code) {
				err = stm32_pwr_fixed_io_compensation(drv_cfg);
				if (err)
					return err;
			}

			err = stm32_pwr_set_voltage(dev, drv_data->suspend_uv,
						    drv_data->suspend_uv);
			if (err)
				return err;
		}
		return stm32_pwr_set_state(dev, drv_data->suspend_state);
	}

	return 0;
}
#endif

#define _DEVICE_REGU(node_id) DEVICE_DT_GET(node_id),
#define _PWR_REGULATORS_DEV(inst) DT_INST_FOREACH_CHILD_STATUS_OKAY(inst, _DEVICE_REGU)

#define STM32_PWR_BOOTROM_ERRATA(inst)								\
__unused void stm32_pwr_regulator_restore(void)							\
{												\
	static const struct device *regu_devices[] = {_PWR_REGULATORS_DEV(inst)};		\
												\
	_stm32_pwr_bootrom_errata(regu_devices, ARRAY_SIZE(regu_devices));			\
}

#define DEFINE_REGU_VDDIO(_node_id, _id, _reg) {						\
	.enable_reg = _PWR ## _reg ## _OFFSET,							\
	.enable_mask = _reg ## _ ## _id ## VMEN,						\
	.ready_mask = _reg ## _ ## _id ## RDY,							\
	.valid_mask = _reg ## _ ## _id ## SV,							\
	.vrsel_mask = _reg ## _ ## _id ## VRSEL,						\
	.vin_supply = DT_DEV_REGULATOR_SUPPLY(_node_id, vin),					\
	.is_an_iod = true,									\
	.iod_offset = _id ## _OFFSET,								\
	.iocomp_code = DT_PROP_OR(_node_id, st_iocomp, {}),					\
	.n_iocomp_code = DT_PROP_LEN_OR(_node_id, st_iocomp, 0),				\
}

#define DEFINE_REGU_VDD_IO(_node_id, _id, _reg) {						\
	.enable_reg = _PWR ## _reg ## _OFFSET,							\
	.vrsel_mask = _reg ## _ ## _id ## VRSEL,						\
	.vin_supply = DT_DEV_REGULATOR_SUPPLY(_node_id, vin),					\
	.is_an_iod = true,									\
	.iod_offset = _id ## _OFFSET,								\
	.iocomp_code = DT_PROP_OR(_node_id, st_iocomp, {}),					\
	.n_iocomp_code = DT_PROP_LEN_OR(_node_id, st_iocomp, 0),				\
}

#define DEFINE_REGU_FIXED(_node_id, _id, _reg) {						\
	.enable_reg = _PWR ## _reg ## _OFFSET,							\
	.enable_mask = _reg ## _ ## _id ## VMEN,						\
	.ready_mask = _reg ## _ ## _id ## RDY,							\
	.valid_mask = _reg ## _ ## _id ## SV,							\
	.vin_supply = DT_DEV_REGULATOR_SUPPLY(_node_id, vin),					\
}

#define DEFINE_REGU_FIXED_CLAMP(_node_id, _id, _reg) {						\
	.enable_reg = _PWR ## _reg ## _OFFSET,							\
	.enable_mask = _reg ## _ ## _id ## VMEN,						\
	.ready_mask = _reg ## _ ## _id ## RDY,							\
	.valid_mask = _reg ## _ ## _id ## SV,							\
	.vin_supply = DT_DEV_REGULATOR_SUPPLY(_node_id, vin),					\
	.has_clamp = true,									\
}

#define DEFINE_REGU_GPU(_node_id, _id, _reg) {							\
	.enable_reg = _PWR ## _reg ## _OFFSET,							\
	.enable_mask = _reg ## _GPUVMEN,							\
	.ready_mask = _reg ## _VDDGPURDY,							\
	.valid_mask = _reg ## _GPUSV,								\
	.keep_monitor_on = true,								\
	.vin_supply = DT_DEV_REGULATOR_SUPPLY(_node_id, vin),					\
}

#define REGULATOR_POWER_DEFINE(node_id, id, macro_desc, name, reg, ops)				\
	static struct stm32_pwr_regu_data stm32_data_##id = {					\
	};											\
												\
	static const struct stm32_pwr_regu_config stm32_cfg_##id = {				\
		.common = REGULATOR_DT_COMMON_CONFIG_INIT(node_id),				\
		.pwr_regu = macro_desc(node_id, name, reg),					\
		.base = DT_REG_ADDR(DT_GPARENT(node_id)),					\
		.syscfg_dev = DEVICE_DT_GET(DT_PHANDLE(DT_GPARENT(node_id),			\
						       st_syscfg_vddio)),			\
		.syscfg_base = DT_PHA_BY_IDX(DT_GPARENT(node_id),				\
					     st_syscfg_vddio, 0, offset),			\
	};											\
												\
	PM_DEVICE_DT_DEFINE(node_id, stm32_pwr_regulator_pm_action, PM_DEVICE_F_NONE);		\
												\
	DEVICE_DT_DEFINE(node_id, &stm32_pwr_regulator_init, PM_DEVICE_DT_GET(node_id),		\
			 &stm32_data_##id, &stm32_cfg_##id,					\
			 STM32MP2_PWR_REGU_LVL, STM32MP2_PWR_REGU_PRIO,				\
			 &ops);

#define REGULATOR_PWR_DEFINE_COND(inst, child, macro_desc, name, reg)				\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(DT_INST_CHILD(inst, child)),			\
		    (REGULATOR_POWER_DEFINE(DT_INST_CHILD(inst, child),				\
					    inst ## _ ## child,					\
					    macro_desc, name, reg,				\
					    stm32_pwr_regu_ops)),				\
		    ())

#define FIXED_PWR_DEFINE_COND(inst, child, macro_desc, name, reg)				\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(DT_INST_CHILD(inst, child)),			\
		    (REGULATOR_POWER_DEFINE(DT_INST_CHILD(inst, child),				\
					      inst ## _ ## child,				\
					      macro_desc, name, reg, stm32_pwr_regu_fixed_ops)),\
		    ())

#define STM32MP21_PWR_REGULATORS_DEFINE_ALL(inst)						\
	STM32_PWR_BOOTROM_ERRATA(inst)								\
	REGULATOR_PWR_DEFINE_COND(inst, vddio1, DEFINE_REGU_VDDIO, VDDIO1, _CR8)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio2, DEFINE_REGU_VDDIO, VDDIO2, _CR7)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio3, DEFINE_REGU_VDDIO, VDDIO3, _CR1)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio, DEFINE_REGU_VDD_IO, VDDIO, _CR1)			\
	FIXED_PWR_DEFINE_COND(inst, vdda18adc, DEFINE_REGU_FIXED_CLAMP, A, _CR1)

#define STM32MP25_PWR_REGULATORS_DEFINE_ALL(inst)						\
	STM32_PWR_BOOTROM_ERRATA(inst)								\
	REGULATOR_PWR_DEFINE_COND(inst, vddio1, DEFINE_REGU_VDDIO, VDDIO1, _CR8)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio2, DEFINE_REGU_VDDIO, VDDIO2, _CR7)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio3, DEFINE_REGU_VDDIO, VDDIO3, _CR1)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio4, DEFINE_REGU_VDDIO, VDDIO4, _CR1)		\
	REGULATOR_PWR_DEFINE_COND(inst, vddio, DEFINE_REGU_VDD_IO, VDDIO, _CR1)			\
	FIXED_PWR_DEFINE_COND(inst, vdd33ucpd, DEFINE_REGU_FIXED, UCPD, _CR1)			\
	FIXED_PWR_DEFINE_COND(inst, vdda18adc, DEFINE_REGU_FIXED, A, _CR1)			\
	REGULATOR_PWR_DEFINE_COND(inst, vddgpu, DEFINE_REGU_GPU, GPU, _CR12)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT STM32MP21_COMPAT

DT_INST_FOREACH_STATUS_OKAY(STM32MP21_PWR_REGULATORS_DEFINE_ALL)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT STM32MP25_COMPAT

DT_INST_FOREACH_STATUS_OKAY(STM32MP25_PWR_REGULATORS_DEFINE_ALL)

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(STM32MP21_COMPAT) +
	     DT_NUM_INST_STATUS_OKAY(STM32MP25_COMPAT) <= 1,
	     "only one pwr instance is supported");
