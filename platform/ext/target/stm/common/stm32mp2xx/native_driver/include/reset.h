/*
 * Copyright (c) 2022 Andrei-Edward Popa <andrei.popa105@yahoo.com>
 * Copyright (c) 2023, STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork of zephyr
 */
#ifndef INCLUDE_RESET_H_
#define INCLUDE_RESET_H_

#include <errno.h>
#include <device.h>

/**
 * struct reset_control - a reset control
 * @dev: reference to the reset controller device.
 * id: id of the reset controller
 */
struct reset_control {
	const struct device *dev;
	uint32_t id;
};

/**
 * @brief Static initializer for a @p reset_control
 *
 * This returns a static initializer for a @p reset_control structure given a
 * devicetree node identifier, a property specifying a Reset Controller and an index.
 *
 * Example devicetree fragment:
 *
 *	n: node {
 *		resets = <&reset 10>;
 *	}
 *
 * Example usage:
 *
 *	const struct reset_control = DT_RESET_CONTROL_GET_BY_IDX(DT_NODELABEL(n), 0);
 *	// Initializes 'spec' to:
 *	// {
 *	//         .dev = DEVICE_DT_GET(DT_NODELABEL(reset)),
 *	//         .id = 10
 *	// }
 *
 * The 'reset' field must still be checked for readiness, e.g. using
 * device_is_ready(). It is an error to use this macro unless the node
 * exists, has the given property, and that property specifies a reset
 * controller reset line id as shown above.
 *
 * @param node_id devicetree node identifier
 * @param idx logical index into "resets"
 * @return static initializer for a struct reset_control for the property
 */
#define DT_RESET_CONTROL_GET_BY_IDX(node_id, idx)					\
	{										\
		.dev = DEVICE_DT_GET_OR_NULL(DT_RESET_CTLR_BY_IDX(node_id, idx)),	\
		.id = DT_RESET_ID_BY_IDX(node_id, idx)					\
	}

/**
 * @brief Equivalent to DT_RESET_CONTROL_GET_BY_IDX(node_id, 0).
 *
 * @param node_id devicetree node identifier
 * @return static initializer for a struct reset_control for the property
 * @see DT_RESET_CONTROL_GET_BY_IDX()
 */
#define DT_RESET_CONTROL_GET(node_id) \
	DT_RESET_CONTROL_GET_BY_IDX(node_id, 0)

/**
 * @brief Static initializer for a @p reset_control from a DT_DRV_COMPAT
 * instance's Reset Controller property at an index.
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param idx logical index into "resets"
 * @return static initializer for a struct reset_control for the property
 * @see DT_RESET_CONTROL_GET_BY_IDX()
 */
#define DT_INST_RESET_CONTROL_GET_BY_IDX(inst, idx) \
	DT_RESET_CONTROL_GET_BY_IDX(DT_DRV_INST(inst), idx)


/**
 * @brief Equivalent to DT_INST_RESET_CONTROL_GET_BY_IDX(inst, 0).
 *
 * @param inst DT_DRV_COMPAT instance number
 * @return static initializer for a struct reset_control for the property
 * @see DT_INST_RESET_CONTROL_GET_BY_IDX()
 */
#define DT_INST_RESET_CONTROL_GET(inst) \
	DT_INST_RESET_CONTROL_GET_BY_IDX(inst, 0)

#define _DT_RCTL(rst_id, node_id) DT_RESET_CONTROL_GET_BY_IDX(node_id, rst_id)

#define DT_RESETS_CONTROL(node_id)					\
	{								\
		LISTIFY(DT_NUM_RESETS(node_id), _DT_RCTL, (,), node_id)	\
	}

/**
 * @brief returns an array of reset_control
 *
 * @param inst DT_DRV_COMPAT instance number
 * @return an array of reset_control
 */
#define DT_INST_RESETS_CONTROL(inst)					\
	DT_RESETS_CONTROL(DT_DRV_INST(inst))

/**
 * @brief Reset Controller driver API
 *
 * @reset:	for self-deasserting resets, does all necessary
 *		things to reset the device
 * @assert_level:	manually assert the reset line, if supported
 * @deassert_level:	manually deassert the reset line, if supported
 * @status:	return the status of the reset line, if supported
 */
struct reset_driver_api {
	int (*reset)(const struct device *dev, uint32_t id);
	int (*assert_level)(const struct device *dev, uint32_t id);
	int (*deassert_level)(const struct device *dev, uint32_t id);
	int (*status)(const struct device *dev, uint32_t id);
};

/**
 * @brief Get the reset status
 *
 * This function returns the reset status of the device.
 *
 * @param dev Reset controller device.
 * @param id Reset line.
 *
 * @retval <0 negative errno if not supported
 *            -ENOSYS If the functionality is not implemented by the driver.
 * @retval >0 if the reset line is asserted
 * @retval  0 if the reset line is not asserted
 */
int reset_control_status(const struct reset_control *rstc);

/**
 * @brief Put the device in reset state
 *
 * This function sets/clears the reset bits of the device,
  *
 * @param dev Reset controller device.
 * @param id Reset line.
 *
 * @retval 0 On success.
 * @retval -ENOSYS If the functionality is not implemented by the driver.
 * @retval -errno Other negative errno in case of failure.
 */
int reset_control_assert(const struct reset_control *rstc);

/**
 * @brief Take out the device from reset state.
 *
 * This function sets/clears the reset bits of the device,
 * depending on the logic level (active-low/active-high).
 *
 * @param dev Reset controller device.
 * @param id Reset line.
 *
 * @retval 0 On success.
 * @retval -ENOSYS If the functionality is not implemented by the driver.
 * @retval -errno Other negative errno in case of failure.
 */
int reset_control_deassert(const struct reset_control *rstc);

/**
 * @brief Reset the device.
 *
 * This function performs reset for a device (assert_level + deassert_level).
 *
 * @param dev Reset controller device.
 * @param id Reset line.
 *
 * @retval 0 On success.
 * @retval -ENOSYS If the functionality is not implemented by the driver.
 * @retval -errno Other negative errno in case of failure.
 */
int reset_control_reset(const struct reset_control *rstc);

#endif /* INCLUDE_RESET_H_ */
