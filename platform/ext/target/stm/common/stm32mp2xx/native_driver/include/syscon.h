/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef SYSCON_H
#define SYSCON_H

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <lib/timeout.h>

/**
 * @brief SYSCON driver API
 *
 * @read:	read from a syscon register.
 * @write:	write to a syscon register.
 * @clrsetbits:	clear bits, then set bits of a syscon register.
 * @clrbits:	clear bits of a syscon register.
 * @setbits:	set bits of a syscon register.
 */
struct syscon_driver_api {
	int (*read)(const struct device *dev, uint16_t off, uint32_t *val);
	int (*write)(const struct device *dev, uint16_t off, uint32_t val);
	int (*clrsetbits)(const struct device *dev, uint16_t off,
			  uint32_t clr, uint32_t set);
	int (*clrbits)(const struct device *dev, uint16_t off,
		       uint32_t clr);
	int (*setbits)(const struct device *dev, uint16_t off,
		       uint32_t set);
};

/**
 * @brief Read from syscon register.
 *
 * This function reads from a specific register in the syscon area.
 *
 * @param dev The device to get the register.
 * @param off The register offset.
 * @param val The returned value read from the syscon register.
 *
 * @return 0 on success, negative on error.
 */
static inline int syscon_read(const struct device *dev, uint16_t off,
			      uint32_t *val)
{
	const struct syscon_driver_api *api = dev->api;

	if (api == NULL) {
		return -ENOTSUP;
	}

	return api->read(dev, off, val);
}

/**
 * @brief Write to syscon register.
 *
 * This function writes to a specific register in the syscon area.
 *
 * @param dev The device to get the register.
 * @param off The register offset.
 * @param val The value to be written in the syscon register.
 *
 * @return 0 on success, negative on error.
 */
static inline int syscon_write(const struct device *dev, uint16_t off,
			       uint32_t val)
{
	const struct syscon_driver_api *api = dev->api;

	if (api == NULL) {
		return -ENOTSUP;
	}

	return api->write(dev, off, val);
}

/**
 * @brief Clear ans set bits in a syscon register.
 *
 * This function clears and set bits of a specific register in the syscon area.
 *
 * @param dev The device to get the register.
 * @param off The register offset.
 * @param clr The bits to be cleared in the syscon register.
 * @param set The bits to be set in the syscon register.
 *
 * @return 0 on success, negative on error.
 */
static inline int syscon_clrsetbits(const struct device *dev, uint16_t off,
				    uint32_t clr, uint32_t set)
{
	const struct syscon_driver_api *api = dev->api;

	if (api == NULL) {
		return -ENOTSUP;
	}

	return api->clrsetbits(dev, off, clr, set);
}

/**
 * @brief Clear bits in a syscon register.
 *
 * This function clears bits of a specific register in the syscon area.
 *
 * @param dev The device to get the register.
 * @param off The register offset.
 * @param clr The bits to be cleared in the syscon register.
 *
 * @return 0 on success, negative on error.
 */
static inline int syscon_clrbits(const struct device *dev, uint16_t off,
				 uint32_t clr)
{
	const struct syscon_driver_api *api = dev->api;

	if (api == NULL) {
		return -ENOTSUP;
	}

	return api->clrbits(dev, off, clr);
}

/**
 * @brief Set bits in a syscon register.
 *
 * This function set bits of a specific register in the syscon area.
 *
 * @param dev The device to get the register.
 * @param off The register offset.
 * @param clr The bits to be set in the syscon register.
 *
 * @return 0 on success, negative on error.
 */
static inline int syscon_setbits(const struct device *dev, uint16_t off,
				 uint32_t set)
{
	const struct syscon_driver_api *api = dev->api;

	if (api == NULL) {
		return -ENOTSUP;
	}

	return api->setbits(dev, off, set);
}

/**
 * syscon_read_poll_timeout - Periodically poll an address until a condition
 * is met or a timeout occurs.
 * @dev: The device to get the register.
 * @addr: Address to poll.
 * @val: Variable to read the value into.
 * @cond: Break condition (usually involving @val).
 * @timeout_us: Timeout in us, 0 means never timeout.
 *
 * Returns 0 on success and -ETIMEDOUT upon a timeout. In either
 * case, the last read value at @addr is stored in @val. Must not
 * be called from atomic context if sleep_us or timeout_us are used.
 */
#define syscon_read_poll_timeout(dev, addr, val, cond, timeout_us) \
({ \
	uint64_t __timeout_us = (timeout_us); \
	uint64_t __timeout = timeout_init_us(__timeout_us); \
	for (;;) { \
		syscon_read(dev, addr, &val); \
		if (cond) \
			break; \
		if (__timeout_us && timeout_elapsed(__timeout)) { \
			syscon_read(dev, addr, &val); \
			break; \
		} \
	} \
	(cond) ? 0 : -ETIMEDOUT; \
})
#endif /* SYSCON_H */
