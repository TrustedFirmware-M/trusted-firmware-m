/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <nrfx.h>
#include <hal/nrf_gpio.h>
#include <stdint.h>
#include <tfm_platform_api.h>
#include <tfm_ioctl_core_api.h>

enum tfm_platform_err_t tfm_platform_mem_read(void *destination, uint32_t addr,
					      size_t len, uint32_t *result)
{
	enum tfm_platform_err_t ret;
	psa_invec in_vec;
	psa_outvec out_vec;
	struct tfm_read_service_args_t args;
	struct tfm_read_service_out_t out;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	args.destination = destination;
	args.addr = addr;
	args.len = len;

	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_READ_SERVICE, &in_vec,
				 &out_vec);

	*result = out.result;

	return ret;
}

enum tfm_platform_err_t tfm_platform_gpio_pin_mcu_select(uint32_t pin_number, uint32_t mcu,
							 uint32_t *result)
{
#if NRF_GPIO_HAS_SEL
	enum tfm_platform_err_t ret;
	psa_invec in_vec;
	psa_outvec out_vec;
	struct tfm_gpio_service_args args;
	struct tfm_gpio_service_out out;

	args.type = TFM_GPIO_SERVICE_TYPE_PIN_MCU_SELECT;
	args.mcu_select.pin_number = pin_number;
	args.mcu_select.mcu = mcu;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_GPIO_SERVICE, &in_vec,
				 &out_vec);

	*result = out.result;

	return ret;
#else
	return TFM_PLATFORM_ERR_NOT_SUPPORTED;
#endif
}

enum tfm_platform_err_t tfm_platform_mem_write32(uint32_t addr, uint32_t value,
						 uint32_t mask, uint32_t *result)
{
	enum tfm_platform_err_t ret;
	psa_invec in_vec;
	psa_outvec out_vec;
	struct tfm_write32_service_args_t args;
	struct tfm_write32_service_out_t out;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	args.addr = addr;
	args.value = value;
	args.mask = mask;
	/* Allowed values cannot be specified by the user */

	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_WRITE32_SERVICE, &in_vec,
				 &out_vec);

	*result = out.result;

	return ret;
}

#if defined(CONFIG_SOC_NRF7120_TFM_MRAMC_SERVICE)
enum tfm_platform_err_t tfm_platform_mramc_init(void)
{
	return tfm_platform_ioctl(TFM_PLATFORM_IOCTL_MRAMC_INIT_SERVICE, NULL,
			    NULL);
}

enum tfm_platform_err_t tfm_platform_mramc_set_wen(uint32_t write_mode)
{
	psa_invec in_vec;

	struct tfm_mramc_set_wen_service_args_t args;

	args.write_mode = write_mode;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(struct tfm_mramc_set_wen_service_args_t);

	return tfm_platform_ioctl(TFM_PLATFORM_IOCTL_MRAMC_SET_WEN_SERVICE, &in_vec,
				NULL);
}
#endif

#if defined(CONFIG_NRF_TFM_RAM_CTRL_SERVICE)
static enum tfm_platform_err_t ram_ctrl_set(uint32_t op, uint32_t addr, uint32_t len, bool on)
{
	psa_invec in_vec;
	psa_outvec out_vec;
	struct tfm_ram_ctrl_service_args_t args;
	struct tfm_ram_ctrl_service_out_t out;

	args.op = op;
	args.addr = addr;
	args.len = len;
	args.on = (uint32_t)on;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);
	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	return tfm_platform_ioctl(TFM_PLATFORM_IOCTL_RAM_CTRL_SERVICE, &in_vec, &out_vec);
}

enum tfm_platform_err_t tfm_platform_ram_ctrl_power_set(uint32_t addr, uint32_t len, bool on)
{
	return ram_ctrl_set(TFM_RAM_CTRL_OP_POWER, addr, len, on);
}

enum tfm_platform_err_t tfm_platform_ram_ctrl_retention_set(uint32_t addr, uint32_t len, bool on)
{
	return ram_ctrl_set(TFM_RAM_CTRL_OP_RETAIN, addr, len, on);
}

enum tfm_platform_err_t tfm_platform_ram_ctrl_read_status(uint32_t *control, uint32_t *ret,
							  uint32_t *ret2)
{
	enum tfm_platform_err_t err;
	psa_invec in_vec;
	psa_outvec out_vec;
	struct tfm_ram_ctrl_service_args_t args;
	struct tfm_ram_ctrl_service_out_t out;

	args.op = TFM_RAM_CTRL_OP_READ_STATUS;
	args.addr = 0;
	args.len = 0;
	args.on = 0;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);
	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	err = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_RAM_CTRL_SERVICE, &in_vec, &out_vec);

	if (control != NULL) {
		*control = out.control;
	}
	if (ret != NULL) {
		*ret = out.ret;
	}
	if (ret2 != NULL) {
		*ret2 = out.ret2;
	}

	return err;
}
#endif /* NRF_TFM_RAM_CTRL_SERVICE */
