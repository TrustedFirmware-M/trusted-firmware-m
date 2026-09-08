/*
 * Copyright (c) 2018-2019 Nordic Semiconductor ASA
 * Copyright (c) 2015 Wind River Systems, Inc.
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork of zephyr
 */

#ifndef  __UART_H__
#define  __UART_H__

#include <errno.h>
#include <pm/device.h>

/** @brief Parity modes */
enum uart_config_parity {
	UART_CFG_PARITY_NONE,
	UART_CFG_PARITY_ODD,
	UART_CFG_PARITY_EVEN,
	UART_CFG_PARITY_MARK,
	UART_CFG_PARITY_SPACE,
};

/** @brief Number of stop bits. */
enum uart_config_stop_bits {
	UART_CFG_STOP_BITS_0_5,
	UART_CFG_STOP_BITS_1,
	UART_CFG_STOP_BITS_1_5,
	UART_CFG_STOP_BITS_2,
};

/** @brief Number of data bits. */
enum uart_config_data_bits {
	UART_CFG_DATA_BITS_5,
	UART_CFG_DATA_BITS_6,
	UART_CFG_DATA_BITS_7,
	UART_CFG_DATA_BITS_8,
	UART_CFG_DATA_BITS_9,
};

/**
 * @brief Hardware flow control options.
 *
 * With flow control set to none, any operations related to flow control
 * signals can be managed by user with uart_line_ctrl functions.
 * In other cases, flow control is managed by hardware/driver.
 */
enum uart_config_flow_control {
	UART_CFG_FLOW_CTRL_NONE,
	UART_CFG_FLOW_CTRL_RTS_CTS,
	UART_CFG_FLOW_CTRL_DTR_DSR,
	UART_CFG_FLOW_CTRL_RS485,
};

/**
 * @brief UART controller configuration structure
 *
 * @param baudrate  Baudrate setting in bps
 * @param parity    Parity bit, use @ref uart_config_parity
 * @param stop_bits Stop bits, use @ref uart_config_stop_bits
 * @param data_bits Data bits, use @ref uart_config_data_bits
 * @param flow_ctrl Flow control setting, use @ref uart_config_flow_control
 */
struct uart_config {
	uint32_t baudrate;
	uint8_t parity;
	uint8_t stop_bits;
	uint8_t data_bits;
	uint8_t flow_ctrl;
};

/**
 * struct uart_driver_api - Uart driver API
 *
 * @configure:		Callback used to configure the device UART.
 * @tx:			Callback used to transmit a given number of bytes from a buffer.
 * @rx:			Callback used to receive a given number of bytes into a buffer.
 * @rx_available:	Callback used to check if data becomes available for
 *			reception within the specified timeout.
 */
struct uart_driver_api {
	/** UART configuration functions */
	int (*configure)(const struct device *dev,
			 const struct uart_config *cfg);
	int (*tx)(const struct device *dev, const uint8_t *buf, size_t len,
		  uint32_t timeout);
	int (*rx)(const struct device *dev, uint8_t *buf, size_t len,
		  uint32_t timeout);
	bool (*rx_available)(const struct device *dev, uint32_t timeout);
};

/**
 * @brief Set UART configuration.
 *
 * Sets UART configuration using data from *cfg.
 *
 * @param dev UART device instance.
 * @param cfg UART configuration structure.
 *
 * @retval 0 If successful.
 * @retval -errno Negative errno code in case of failure.
 * @retval -ECANCELED if device is not in activated state
 * @retval -ENOSYS If configuration is not supported by device
 *                  or driver does not support setting configuration in runtime.
 */
static inline int uart_configure(const struct device *dev,
				 const struct uart_config *cfg)
{
	const struct uart_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	if (!pm_device_is_active(dev))
		return -ECANCELED;

	api = dev->api;

	if (!api || !api->configure)
		return -ENOSYS;

	return api->configure(dev, cfg);
}

/**
 * @brief Send given number of data from buffer through UART.
 *
 * Function returns after transfer completed
 *
 * @param dev     UART device instance.
 * @param buf     Pointer to wide data transmit buffer.
 * @param len     Length of wide data transmit buffer.
 * @param timeout Timeout in milliseconds. Valid only if flow control is
 *		  enabled. @ref SYS_FOREVER_MS disables timeout.
 *
 * @retval 0 If successful.
 * @retval -ECANCELED if device is not in activated state
 * @retval -ENOSYS If API is not enabled.
 * @retval -EBUSY If there is already an ongoing transfer.
 * @retval -errno Other negative errno value in case of failure.
 */
static inline int uart_tx(const struct device *dev, const uint8_t *buf,
			  size_t len, int32_t timeout)
{
	const struct uart_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	if (!pm_device_is_active(dev))
		return -ECANCELED;

	api = dev->api;

	if (!api || !api->tx)
		return -ENOSYS;

	return api->tx(dev, buf, len, timeout);
}

/**
 * @brief Start receiving data through UART.
 *
 * Function sets given buffer as first buffer for receiving and returns
 * immediately.
 *
 * @param dev     UART device instance.
 * @param buf     Pointer to receive buffer.
 * @param len     Buffer length.
 * @param timeout Inactivity period after receiving at least a byte which
 *		  triggers  #UART_RX_RDY event. Given in microseconds.
 *		  @ref SYS_FOREVER_US disables timeout. See @ref uart_event_type
 *		  for details.
 *
 * @retval 0 If successful.
 * @retval -ECANCELED if device is not in activated state
 * @retval -ENOSYS If API is not enabled.
 * @retval -EBUSY RX already in progress.
 * @retval -errno Other negative errno value in case of failure.
 *
 */
static inline int uart_rx(const struct device *dev, uint8_t *buf,
			  size_t len, int32_t timeout)
{
	const struct uart_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	if (!pm_device_is_active(dev))
		return -ECANCELED;

	api = dev->api;

	if (!api || !api->rx)
		return -ENOSYS;

	return api->rx(dev, buf, len, timeout);
}

/**
 * @brief Check whether data is available for reception through UART.
 *
 * Checks whether data becomes available for reception within the specified
 * timeout.
 *
 * @param dev     UART device instance.
 * @param timeout Timeout in milliseconds.
 *
 * @retval true Data is available for reception.
 * @retval false No data is available, the API is not enabled, or the device
 *               is not in the active state.
 */
static inline bool uart_rx_available(const struct device *dev, uint32_t timeout)
{
	const struct uart_driver_api *api;

	if (!device_is_ready(dev) || !pm_device_is_active(dev))
		return false;

	api = dev->api;

	if (!api || !api->rx_available)
		return false;

	return api->rx_available(dev, timeout);
}

#endif   /* ----- #ifndef __UART_H__  ----- */
