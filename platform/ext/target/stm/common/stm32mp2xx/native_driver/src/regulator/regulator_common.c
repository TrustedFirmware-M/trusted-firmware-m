/*
 * Copyright 2022 Nordic Semiconductor ASA
 * Copyright 2023, STMicroelectronics
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
 */

#include <lib/delay.h>
#include <regulator.h>

static void regulator_delay(uint32_t delay_us)
{
	if (delay_us > 0U) {
		udelay(delay_us);
	}
}

void regulator_common_data_init(const struct device *dev)
{
	struct regulator_common_data *data = dev->data;

	data->refcnt = 0;
}

int regulator_common_init(const struct device *dev, bool is_enabled)
{
	const struct regulator_driver_api *api = dev->api;
	const struct regulator_common_config *config = dev->config;
	struct regulator_common_data *data = dev->data;
	int32_t current_uv;
	int ret;

	if (config->initial_mode != REGULATOR_INITIAL_MODE_UNKNOWN) {
		ret = regulator_set_mode(dev, config->initial_mode);
		if (ret < 0) {
			return ret;
		}
	}

	if (config->init_uv > INT32_MIN) {
		ret = regulator_set_voltage(dev, config->init_uv, config->init_uv);
		if (ret < 0) {
			return ret;
		}
	}

	/* If we have valid range values, we try to match them before enabling */
	if ((config->min_uv > INT32_MIN) || (config->max_uv < INT32_MAX)) {

		ret = regulator_get_voltage(dev, &current_uv);
		if (ret < 0) {
			return ret;
		}

		/* Snap to closest interval value if out of range */
		if (current_uv < config->min_uv) {
			ret = regulator_set_voltage(dev, config->min_uv, config->min_uv);
			if (ret < 0) {
				return ret;
			}
		} else if (current_uv > config->max_uv) {
			ret = regulator_set_voltage(dev, config->max_uv, config->max_uv);
			if (ret < 0) {
				return ret;
			}
		}
	}

	if (is_enabled) {
		data->refcnt++;
	} else if ((config->flags & REGULATOR_INIT_ENABLED) != 0U) {
		ret = api->enable(dev);
		if (ret < 0) {
			return ret;
		}

		regulator_delay(config->enable_ramp_delay_us);
		data->refcnt++;
	}

	return 0;
}

int regulator_enable(const struct device *dev)
{
	const struct regulator_driver_api *api = dev->api;
	const struct regulator_common_config *config = dev->config;
	struct regulator_common_data *data = dev->data;
	int ret = 0;

	/* enable not supported (always on) */
	if (api->enable == NULL) {
		return 0;
	}

	/* regulator must stay always on */
	if  ((config->flags & REGULATOR_ALWAYS_ON) != 0U) {
		return 0;
	}

	data->refcnt++;

	if (data->refcnt == 1) {
		ret = api->enable(dev);
		if (ret < 0) {
			data->refcnt--;
		} else {
			regulator_delay(config->enable_ramp_delay_us);
		}
	}

	return ret;
}

bool regulator_is_enabled(const struct device *dev)
{
	const struct regulator_common_config *config = dev->config;
	struct regulator_common_data *data = dev->data;
	bool enabled;

	if ((config->flags & REGULATOR_ALWAYS_ON) != 0U) {
		enabled = true;
	} else {

		enabled = data->refcnt != 0;
	}

	return enabled;
}

int regulator_disable(const struct device *dev)
{
	const struct regulator_driver_api *api = dev->api;
	const struct regulator_common_config *config = dev->config;
	struct regulator_common_data *data = dev->data;
	int ret = 0;

	/* disable not supported (always on) or not previously enabled */
	if ((api->disable == NULL) || (data->refcnt == 0)) {
		return 0;
	}

	/* regulator must stay always on */
	if  ((config->flags & REGULATOR_ALWAYS_ON) != 0U) {
		return 0;
	}

	data->refcnt--;

	if (data->refcnt == 0) {
		ret = api->disable(dev);
		if (ret < 0) {
			data->refcnt++;
		}
	}

	return ret;
}

int regulator_force_enable(const struct device *dev)
{
	const struct regulator_driver_api *api = dev->api;
	const struct regulator_common_config *config = dev->config;
	int ret = 0;

	/* enable not supported (always on) */
	if (api->enable == NULL) {
		return 0;
	}
	ret = api->enable(dev);
	if (ret == 0)
		regulator_delay(config->enable_ramp_delay_us);

	return ret;
}

int regulator_force_disable(const struct device *dev)
{
	const struct regulator_driver_api *api = dev->api;

	/* disable not supported (always on) or not previously enabled */
	if (api->disable == NULL)
		return 0;

	return api->disable(dev);
}

bool regulator_is_supported_voltage(const struct device *dev, int32_t min_uv,
				    int32_t max_uv)
{
	const struct regulator_common_config *config = dev->config;
	unsigned int volt_cnt;

	/* voltage may not be allowed, even if supported */
	if ((min_uv > config->max_uv) || (max_uv < config->min_uv)) {
		return false;
	}

	volt_cnt = regulator_count_voltages(dev);

	for (unsigned int idx = 0U; idx < volt_cnt; idx++) {
		int32_t volt_uv;

		(void)regulator_list_voltage(dev, idx, &volt_uv);

		if ((volt_uv >= min_uv) && (volt_uv <= max_uv)) {
			return true;
		}
	}

	return false;
}

int regulator_set_voltage(const struct device *dev, int32_t min_uv,
			  int32_t max_uv)
{
	const struct regulator_common_config *config = dev->config;
	const struct regulator_driver_api *api = dev->api;
	int32_t current_uv;
	int err;

	if (api->set_voltage == NULL) {
		return -ENOSYS;
	}

	/* voltage may not be allowed, even if supported */
	if ((min_uv > config->max_uv) || (max_uv < config->min_uv)) {
		return -EINVAL;
	}

	err = regulator_get_voltage(dev, &current_uv);
	if (err < 0) {
		return err;
	}

	if (current_uv >= min_uv && current_uv <= max_uv)
		return 0;

	err = api->set_voltage(dev, min_uv, max_uv);
	if (err) {
		return err;
	}

	if (config->ramp_delay_uv_per_us > 0U) {
		unsigned int d = 0;

		/* difference for worst case with min_uv <= current_uv <= max_uv */
		if (current_uv > max_uv)
			d = current_uv - min_uv;
		else
			d = max_uv - current_uv;

		d /= config->ramp_delay_uv_per_us;

		udelay(d);
	}

	return err;
}

int regulator_get_voltage(const struct device *dev,
			  int32_t *volt_uv)
{
	const struct regulator_driver_api *api =
		(const struct regulator_driver_api *)dev->api;

	if (api->get_voltage == NULL) {
		return -ENOSYS;
	}

	return api->get_voltage(dev, volt_uv);
}

int regulator_get_default_voltage(const struct device *dev,
				  int32_t *volt_uv)
{
	const struct regulator_common_config *config = dev->config;
	const struct regulator_driver_api *api =
		(const struct regulator_driver_api *)dev->api;
	int err;

	if (api->get_default_voltage == NULL) {
		return -ENOSYS;
	}

	err = api->get_default_voltage(dev, volt_uv);

	if (!err) {
		/* Snap to closest interval value if out of range */
		if (*volt_uv < config->min_uv)
			*volt_uv = config->min_uv;
		else if (*volt_uv > config->max_uv)
			*volt_uv = config->max_uv;
	}

	return err;
}

int regulator_set_current_limit(const struct device *dev, int32_t min_ua,
				int32_t max_ua)
{
	const struct regulator_common_config *config = dev->config;
	const struct regulator_driver_api *api = dev->api;

	if (api->set_current_limit == NULL) {
		return -ENOSYS;
	}

	/* current limit may not be allowed, even if supported */
	if ((min_ua > config->max_ua) || (max_ua < config->min_ua)) {
		return -EINVAL;
	}

	return api->set_current_limit(dev, min_ua, max_ua);
}

int regulator_set_mode(const struct device *dev, regulator_mode_t mode)
{
	const struct regulator_common_config *config = dev->config;
	const struct regulator_driver_api *api = dev->api;

	if (api->set_mode == NULL) {
		return -ENOSYS;
	}

	/* no mode restrictions */
	if (config->allowed_modes_cnt == 0U) {
		return api->set_mode(dev, mode);
	}

	/* check if mode is allowed, apply if it is */
	for (uint8_t i = 0U; i < config->allowed_modes_cnt; i++) {
		if (mode == config->allowed_modes[i]) {
			return api->set_mode(dev, mode);
		}
	}

	return -ENOTSUP;
}

/**
 * @brief Set minimum supported voltage.
 *
 * @param dev Regulator device instance.
 *
 * @retval 0 If successful
 * @retval -ENOENT If minimum voltage is not specified.
 * @retval -EINVAL If the given voltage window is not valid.
 * @retval -ENOSYS If function is not implemented.
 * @retval -errno In case of any other error.
 */
int regulator_common_set_min_voltage(const struct device *dev)
{
	int32_t min_uv;
	int err;

	err = regulator_common_get_min_voltage(dev, &min_uv);
	if (err)
		return err;

	err = regulator_set_voltage(dev, min_uv, min_uv);
	if (err)
		return err;

	return 0;
}

int regulator_show(const struct device *dev)
{
	const struct regulator_driver_api *api = dev->api;

	if (api->show == NULL) {
		return -ENOSYS;
	}

	return api->show(dev);
}
