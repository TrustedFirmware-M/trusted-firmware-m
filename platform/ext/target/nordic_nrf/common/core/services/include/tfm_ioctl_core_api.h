/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** @file
 * @brief TFM IOCTL API header.
 */


#ifndef TFM_IOCTL_CORE_API_H__
#define TFM_IOCTL_CORE_API_H__

/**
 * @defgroup tfm_ioctl_api TFM IOCTL API
 * @{
 *
 */

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <tfm_platform_api.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Supported request types.
 */
enum tfm_platform_ioctl_core_reqest_types_t {
	TFM_PLATFORM_IOCTL_READ_SERVICE,
	TFM_PLATFORM_IOCTL_WRITE32_SERVICE,
	TFM_PLATFORM_IOCTL_GPIO_SERVICE,
	TFM_PLATFORM_IOCTL_MRAMC_INIT_SERVICE,
	TFM_PLATFORM_IOCTL_MRAMC_SET_WEN_SERVICE,
	TFM_PLATFORM_IOCTL_RAM_CTRL_SERVICE,
	/* Last core service, start platform specific from this value. */
	TFM_PLATFORM_IOCTL_CORE_LAST
};

/** @brief Argument list for each platform read service.
 */
struct tfm_read_service_args_t {
	void *destination;
	uint32_t addr;
	size_t len;
};


/** @brief Output list for each read platform service
 */
struct tfm_read_service_out_t {
	uint32_t result;
};

/** @brief Argument list for each platform write32 service.
 */
struct tfm_write32_service_args_t {
	uint32_t addr;
	uint32_t value;
	uint32_t mask;
};
/** @brief Output list for each write32 platform service
 */

struct tfm_write32_service_out_t {
	uint32_t result;
};

enum tfm_gpio_service_type {
	/** Select which MCU / Subsystem controls the pin */
	TFM_GPIO_SERVICE_TYPE_PIN_MCU_SELECT = 0,
};

/** @brief Arguments for selecting the MCU to control a GPIO pin. */
struct tfm_gpio_service_args_mcu_select {
	uint32_t pin_number;
	uint32_t mcu;
};

/** @brief Argument list for each platform GPIO service */
struct tfm_gpio_service_args {
	uint32_t type;
	union {
		struct tfm_gpio_service_args_mcu_select mcu_select;
	};
};

/** @brief Output list for each GPIO platform service
 */
struct tfm_gpio_service_out {
	uint32_t result;
};

#if defined(CONFIG_SOC_NRF7120_TFM_MRAMC_SERVICE)
struct tfm_mramc_set_wen_service_args_t {
	uint32_t write_mode;
};
#endif

#if defined(CONFIG_NRF_TFM_RAM_CTRL_SERVICE) || defined(TFM_NRF_RAM_CTRL_SERVICE)
/** @brief RAM-control operation selector. */
enum tfm_ram_ctrl_op {
	/** System ON power (MEMCONF CONTROL), applied immediately. */
	TFM_RAM_CTRL_OP_POWER,
	/** System OFF retention (MEMCONF RET), recorded in the secure cache. */
	TFM_RAM_CTRL_OP_RETAIN,
	/** Read back CONTROL/RET/RET2 and the cached retention plan. */
	TFM_RAM_CTRL_OP_READ_STATUS,
};

/** @brief Argument list for the RAM-control service. */
struct tfm_ram_ctrl_service_args_t {
	uint32_t op;   /* enum tfm_ram_ctrl_op */
	uint32_t addr; /* RAM region start (must lie within non-secure RAM) */
	uint32_t len;  /* RAM region length in bytes */
	uint32_t on;   /* powered/retained (true) or not (false) */
};

/** @brief Output for the RAM-control service. */
struct tfm_ram_ctrl_service_out_t {
	uint32_t result;
	uint32_t control;     /* MEMCONF POWER[0].CONTROL snapshot (read status) */
	uint32_t ret;         /* MEMCONF POWER[0].RET snapshot (read status) */
	uint32_t ret2;        /* MEMCONF POWER[0].RET2 snapshot (read status) */
	uint32_t ret_planned; /* cached mask of 32 KiB sections to retain at OFF (read status) */
};
#endif

/**
 * @brief Perform a read operation.
 *
 * @param[out] destination   Pointer where read result is stored
 * @param[in]  addr          Address to read from
 * @param[in]  len           Number of bytes to read
 * @param[out] result        Result of operation
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_mem_read(void *destination, uint32_t addr,
					      size_t len, uint32_t *result);

/**
 * @brief Perform a write32 operation.
 *
 * @param[in]  addr          Address to write to
 * @param[in]  value         32 bit value to write
 * @param[in]  mask          Mask applied to the write value
 * @param[out] result        An enum tfm_write32_service_result value
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_mem_write32(uint32_t addr, uint32_t value,
						 uint32_t mask, uint32_t *result);

/** @brief Represents an accepted read range.
 */
struct tfm_read_service_range {
	uint32_t start;
	size_t size;
};

/** @brief Represents the accepted addresses and masks for write32 service.
 */
struct tfm_write32_service_address {
	uint32_t addr;
	uint32_t mask;
	const uint32_t *allowed_values;
	const uint32_t allowed_values_array_size;
};

enum tfm_write32_service_result {
	TFM_WRITE32_SERVICE_SUCCESS,
	TFM_WRITE32_SERVICE_ERROR_INVALID_ADDRESS,
	TFM_WRITE32_SERVICE_ERROR_INVALID_MASK,
	TFM_WRITE32_SERVICE_ERROR_INVALID_VALUE,
};

/**
 * @brief Perform a GPIO MCU select operation.
 *
 * @param pin_number         Pin_number.
 * @param mcu                MCU to control the pin, use nrf_gpio_pin_sel_t values.

 * @param[out] result        Result of operation
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_gpio_pin_mcu_select(uint32_t pin_number, uint32_t mcu,
							 uint32_t *result);

#if defined(CONFIG_SOC_NRF7120_TFM_MRAMC_SERVICE)
/**
 * @brief Initialise MRAMC peripheral.
 *
 * @return On success the processor will initialise MRAMC, in case of error it returns
 *         values as specified by the \ref tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_mramc_init(void);

/**
 * @brief Setting write permission for MRAMC peripheral.
 *
 * @param write_mode    Write mode for MRAMC peripheral.
 *
 * @return On success the processor will set MRAMC config write mode, in case of error it returns
 *         values as specified by the \ref tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_mramc_set_wen(uint32_t write_mode);
#endif /* SOC_NRF7120_TFM_MRAMC_SERVICE */

#if defined(CONFIG_NRF_TFM_RAM_CTRL_SERVICE)
/**
 * @brief Power up/down a non-secure RAM range in System ON (MEMCONF CONTROL).
 *
 * @param addr  Start address of the range (must be within non-secure RAM).
 * @param len   Length of the range in bytes.
 * @param on    true to power up, false to power down.
 *
 * @return Values as specified by \ref tfm_platform_err_t.
 */
enum tfm_platform_err_t tfm_platform_ram_ctrl_power_set(uint32_t addr, uint32_t len, bool on);

/**
 * @brief Mark/unmark a non-secure RAM range for retention across System OFF.
 *
 * Recorded in the secure domain; applied when the system enters System OFF.
 *
 * @param addr  Start address of the range (must be within non-secure RAM).
 * @param len   Length of the range in bytes.
 * @param on    true to retain across System OFF, false to drop retention.
 *
 * @return Values as specified by \ref tfm_platform_err_t.
 */
enum tfm_platform_err_t tfm_platform_ram_ctrl_retention_set(uint32_t addr, uint32_t len, bool on);

/**
 * @brief Read back MEMCONF POWER[0] CONTROL/RET/RET2 and the cached retention plan.
 *
 * @param control      MEMCONF POWER[0].CONTROL value (may be NULL).
 * @param ret          MEMCONF POWER[0].RET value (may be NULL).
 * @param ret2         MEMCONF POWER[0].RET2 value (may be NULL).
 * @param ret_planned  Cached mask of 32 KiB sections to retain at OFF (may be NULL).
 *
 * @return Values as specified by \ref tfm_platform_err_t.
 */
enum tfm_platform_err_t tfm_platform_ram_ctrl_read_status(uint32_t *control, uint32_t *ret,
							  uint32_t *ret2, uint32_t *ret_planned);
#endif /* NRF_TFM_RAM_CTRL_SERVICE */

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* TFM_IOCTL_CORE_API_H__ */
