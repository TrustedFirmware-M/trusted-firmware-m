/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2021-2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <platform/include/tfm_platform_system.h>
#include <tfm_hal_device_header.h>
#include <stdio.h>
#include <tfm_ioctl_core_api.h>
#include <string.h>
#include <arm_cmse.h>
#include <tfm_utils.h>
#include <tfm_hal_isolation.h>

/* This contains the user provided allowed ranges */
#include <tfm_platform_user_memory_ranges.h>

#include <hal/nrf_gpio.h>
#ifdef NRF91_SERIES
#include <nrfx_nvmc.h>
#endif

#if SOC_NRF7120_TFM_MRAMC_SERVICE
#include <nrfx_mramc.h>
#endif

#if TFM_NRF_RAM_CTRL_SERVICE
#include <helpers/nrfx_ram_ctrl.h>
#include <hal/nrf_memconf.h>
#include "region_defs.h"
#endif

#include "handle_attr.h"

enum tfm_platform_err_t
tfm_platform_hal_read_service(const psa_invec  *in_vec,
			      const psa_outvec *out_vec)
{
	struct tfm_read_service_args_t *args;
	struct tfm_read_service_out_t *out;
	enum tfm_hal_status_t status;
	enum tfm_platform_err_t err;
	uintptr_t boundary = (1 << HANDLE_ATTR_NS_POS) &
	                      HANDLE_ATTR_NS_MASK;
	uint32_t attr = TFM_HAL_ACCESS_READWRITE;

	if (in_vec->len != sizeof(struct tfm_read_service_args_t) ||
	    out_vec->len != sizeof(struct tfm_read_service_out_t)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	args = (struct tfm_read_service_args_t *)in_vec->base;
	out = (struct tfm_read_service_out_t *)out_vec->base;

	/* Assume failure, unless valid region is hit in the loop */
	out->result = -1;
	err = TFM_PLATFORM_ERR_INVALID_PARAM;

	if (args->destination == NULL || args->len <= 0) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	status = tfm_hal_memory_check(boundary, (uintptr_t)args->destination,
	                              args->len, attr);
	if (status != TFM_HAL_SUCCESS) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	for (size_t i = 0; i < ARRAY_SIZE(ranges); i++) {
		uint32_t start = ranges[i].start;
		uint32_t size = ranges[i].size;

		if (args->addr >= start &&
		    args->addr + args->len <= start + size) {
#ifdef NRF91_SERIES
			if (start >= NRF_UICR_S_BASE &&
			    start < (NRF_UICR_S_BASE + sizeof(NRF_UICR_Type))) {
				/* Range is inside UICR. Some nRF platforms need special handling */
				uint32_t *src = (uint32_t *)args->addr;
				uint32_t *dst = (uint32_t *)args->destination;
				uint32_t uicr_end = NRF_UICR_S_BASE + sizeof(NRF_UICR_Type);

				if (!IS_ALIGNED(src, sizeof(uint32_t)) ||
				    (args->len % sizeof(uint32_t)) != 0 ||
				    (args->addr + args->len) > uicr_end) {
					return TFM_PLATFORM_ERR_NOT_SUPPORTED;
				}

				while (args->len) {
					*dst++ = nrfx_nvmc_uicr_word_read(src++);
					args->len -= sizeof(uint32_t);
				}
				out->result = 0;
				err = TFM_PLATFORM_ERR_SUCCESS;
				break;
			}
#endif
			memcpy(args->destination,
			       (const void *)args->addr,
			       args->len);
			out->result = 0;
			err = TFM_PLATFORM_ERR_SUCCESS;
			break;
		}
	}

	return err;
}

#if NRF_GPIO_HAS_SEL
static bool valid_mcu_select(uint32_t mcu)
{
	switch (mcu) {
#if defined(NRF54L_SERIES) || defined(NRF71_SERIES)
	case NRF_GPIO_PIN_SEL_GPIO:
	case NRF_GPIO_PIN_SEL_VPR:
	case NRF_GPIO_PIN_SEL_GRTC:
#else
	case NRF_GPIO_PIN_SEL_APP:
	case NRF_GPIO_PIN_SEL_NETWORK:
	case NRF_GPIO_PIN_SEL_PERIPHERAL:
	case NRF_GPIO_PIN_SEL_TND:
#endif
		return true;
	default:
		return false;
	}
}

static uint32_t gpio_service_mcu_select(struct tfm_gpio_service_args * args)
{
	if (nrf_gpio_pin_present_check(args->mcu_select.pin_number) &&
	    valid_mcu_select(args->mcu_select.mcu)) {
		nrf_gpio_pin_control_select(args->mcu_select.pin_number, args->mcu_select.mcu);
		return 0;
	} else {
		return -1;
	}
}

enum tfm_platform_err_t
tfm_platform_hal_gpio_service(const psa_invec  *in_vec, const psa_outvec *out_vec)
{
	struct tfm_gpio_service_args *args;
	struct tfm_gpio_service_out *out;

	if (in_vec->len != sizeof(struct tfm_gpio_service_args) ||
	    out_vec->len != sizeof(struct tfm_gpio_service_out)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	args = (struct tfm_gpio_service_args *)in_vec->base;
	out = (struct tfm_gpio_service_out *)out_vec->base;
	out->result = -1;

	switch(args->type)
	{
	case TFM_GPIO_SERVICE_TYPE_PIN_MCU_SELECT:
		out->result = gpio_service_mcu_select(args);
		break;
	default:
		return TFM_PLATFORM_ERR_NOT_SUPPORTED;
	}


	return TFM_PLATFORM_ERR_SUCCESS;
}
#endif /* NRF_GPIO_HAS_SEL */

enum tfm_platform_err_t tfm_platform_hal_write32_service(const psa_invec *in_vec,
							 const psa_outvec *out_vec)
{
	uint32_t addr;
	uint32_t mask;
	uint32_t allowed_values_array_size;

	struct tfm_write32_service_args_t *args;
	struct tfm_write32_service_out_t *out;

	enum tfm_platform_err_t err;

	if (in_vec->len != sizeof(struct tfm_write32_service_args_t) ||
	    out_vec->len != sizeof(struct tfm_write32_service_out_t)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	args = (struct tfm_write32_service_args_t *)in_vec->base;
	out = (struct tfm_write32_service_out_t *)out_vec->base;

	/* Assume failure, in case we don't find a match */
	out->result = TFM_WRITE32_SERVICE_ERROR_INVALID_ADDRESS;
	err = TFM_PLATFORM_ERR_INVALID_PARAM;

	for (size_t i = 0; i < ARRAY_SIZE(tfm_write32_service_addresses); i++) {
		addr = tfm_write32_service_addresses[i].addr;
		mask = tfm_write32_service_addresses[i].mask;
		allowed_values_array_size =
			tfm_write32_service_addresses[i].allowed_values_array_size;

		if (args->addr == addr) {
			out->result = TFM_WRITE32_SERVICE_ERROR_INVALID_MASK;

			if (args->mask == mask) {
				/* Check for allowed values if provided */
				if (allowed_values_array_size > 0 &&
				    tfm_write32_service_addresses[i].allowed_values != NULL) {
					bool is_value_allowed = false;

					for (int j = 0; j < allowed_values_array_size; j++) {

						const uint32_t allowed_value =
							tfm_write32_service_addresses[i]
								.allowed_values[j];

						if (allowed_value == (args->value & args->mask)) {
							is_value_allowed = true;
							break;
						}
					}

					if (!is_value_allowed) {
						out->result =
							TFM_WRITE32_SERVICE_ERROR_INVALID_VALUE;
						break;
					}
				}

				uint32_t new_value = *(uint32_t *)addr;
				/* Invert the mask to convert the masked bits to 0 first */
				new_value &= ~args->mask;
				new_value |= (args->value & args->mask);
				*(uint32_t *)addr = new_value;

				out->result = TFM_WRITE32_SERVICE_SUCCESS;
				err = TFM_PLATFORM_ERR_SUCCESS;
				break;
			}
		}
	}

	return err;
}

#if SOC_NRF7120_TFM_MRAMC_SERVICE
enum tfm_platform_err_t tfm_platform_hal_mramc_init_service(void)
{
	nrfx_mramc_config_t config = NRFX_MRAMC_DEFAULT_CONFIG();
	int ret = nrfx_mramc_init(&config, NULL);

	if (ret == -EALREADY) {
		/* Driver is initialise by ITS or PS at the ealier stage*/
		return TFM_PLATFORM_ERR_SUCCESS;
	} else if (ret != 0) {
		return TFM_PLATFORM_ERR_SYSTEM_ERROR;
	}

	return TFM_PLATFORM_ERR_SUCCESS;
}

enum tfm_platform_err_t tfm_platform_hal_mramc_set_wen_service(const psa_invec *in_vec)
{
	struct tfm_mramc_set_wen_service_args_t *args;

	if (in_vec->len != sizeof(struct tfm_mramc_set_wen_service_args_t)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	args = (struct tfm_mramc_set_wen_service_args_t *)in_vec->base;
	uint32_t write_mode = args->write_mode;

	while(!nrfx_mramc_ready_check()) {
	/* Wait until MRAMC is ready for the next operation */
	}
	nrfx_mramc_config_write_mode_set(write_mode);

	return TFM_PLATFORM_ERR_SUCCESS;
}
#endif /* SOC_NRF7120_TFM_MRAMC_SERVICE */

#if TFM_NRF_RAM_CTRL_SERVICE

/* RAM section granularity for the retention cache (32 KiB on nRF54L / nRF7120). */
#define RAM_CTRL_SECTION_SIZE 0x8000U

/* Align a RAM address down/up to the section granularity (power-of-two size). */
#define RAM_CTRL_SECTION_DOWN(x) ((x) & ~(RAM_CTRL_SECTION_SIZE - 1U))
#define RAM_CTRL_SECTION_UP(x)   RAM_CTRL_SECTION_DOWN((x) + (RAM_CTRL_SECTION_SIZE - 1U))

/* Mask of 32 KiB RAM sections to retain at System OFF (bit i => POWER[0] section i). */
static uint32_t s_ret_section_mask;

/* True if [addr, addr+len) lies entirely within the non-secure RAM window. */
static bool ram_ctrl_range_is_ns(uint32_t addr, uint32_t len)
{
	if (len == 0U || addr > (UINT32_MAX - len)) {
		return false;
	}

	return (addr >= NS_DATA_START) && ((addr + len - 1U) <= NS_DATA_LIMIT);
}

static uint32_t ram_ctrl_range_to_section_mask(uint32_t addr, uint32_t len)
{
	uint32_t first, last, count;

	if (len == 0U || addr < NRF_MEMORY_RAM_BASE) {
		return 0U;
	}

	first = (addr - NRF_MEMORY_RAM_BASE) / RAM_CTRL_SECTION_SIZE;
	last = (addr + len - 1U - NRF_MEMORY_RAM_BASE) / RAM_CTRL_SECTION_SIZE;
	if (last > 31U) {
		return 0U;
	}

	count = last - first + 1U;
	if (count >= 32U) {
		return 0xFFFFFFFFU;
	}

	return ((1U << count) - 1U) << first;
}

enum tfm_platform_err_t
tfm_platform_hal_ram_ctrl_service(const psa_invec *in_vec, const psa_outvec *out_vec)
{
	struct tfm_ram_ctrl_service_args_t *args;
	struct tfm_ram_ctrl_service_out_t *out;

	if (in_vec->len != sizeof(struct tfm_ram_ctrl_service_args_t) ||
	    out_vec->len != sizeof(struct tfm_ram_ctrl_service_out_t)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	args = (struct tfm_ram_ctrl_service_args_t *)in_vec->base;
	out = (struct tfm_ram_ctrl_service_out_t *)out_vec->base;
	out->result = -1;
	out->control = 0;
	out->ret = 0;
	out->ret2 = 0;
	out->ret_planned = 0;

	/* Read back MEMCONF registers + the cached retention plan. */
	if (args->op == TFM_RAM_CTRL_OP_READ_STATUS) {
		out->control = NRF_MEMCONF->POWER[0].CONTROL;
		out->ret = NRF_MEMCONF->POWER[0].RET;
		out->ret2 = NRF_MEMCONF->POWER[0].RET2;
		out->ret_planned = s_ret_section_mask;
		out->result = 0;
		return TFM_PLATFORM_ERR_SUCCESS;
	}

	/* Allow-list: reject anything not entirely within non-secure RAM. */
	if (!ram_ctrl_range_is_ns(args->addr, args->len)) {
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	switch (args->op) {
	case TFM_RAM_CTRL_OP_POWER: {
		/* Act only on whole 32 KiB sections fully inside the non-secure window. */
		uint32_t start = RAM_CTRL_SECTION_UP(args->addr);
		uint32_t end = RAM_CTRL_SECTION_DOWN(args->addr + args->len);
		uint32_t ns_hi = RAM_CTRL_SECTION_DOWN((uint32_t)NS_DATA_LIMIT + 1U);

		if (end > ns_hi) {
			end = ns_hi;
		}
		if (start < end) {
			nrfx_ram_ctrl_power_enable_set((void *)(uintptr_t)start,
						       end - start, args->on != 0U);
		}
		break;
	}
	case TFM_RAM_CTRL_OP_RETAIN: {
		/* Record in the secure cache; applied at System OFF. */
		uint32_t m = ram_ctrl_range_to_section_mask(args->addr, args->len);

		if (args->on != 0U) {
			s_ret_section_mask |= m;
		} else {
			s_ret_section_mask &= ~m;
		}
		break;
	}
	default:
		return TFM_PLATFORM_ERR_INVALID_PARAM;
	}

	out->result = 0;
	return TFM_PLATFORM_ERR_SUCCESS;
}
#endif /* TFM_NRF_RAM_CTRL_SERVICE */
