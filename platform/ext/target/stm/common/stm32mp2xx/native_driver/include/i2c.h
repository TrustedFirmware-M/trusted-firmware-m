/*
 * Copyright (c) 2015 Intel Corporation
 * Copyright (c) 2023, STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork of zephyr
 */
#ifndef _INCLUDE_I2C_H_
#define _INCLUDE_I2C_H_

/**
 * @brief I2C Interface
 * @defgroup i2c_interface I2C Interface
 * @ingroup io_interfaces
 * @{
 */

#include <errno.h>
#include <device.h>


/*
 * The following #defines are used to configure the I2C controller.
 */

/** I2C Standard Speed: 100 kHz */
#define I2C_SPEED_STANDARD		(0x1U)

/** I2C Fast Speed: 400 kHz */
#define I2C_SPEED_FAST			(0x2U)

/** I2C Fast Plus Speed: 1 MHz */
#define I2C_SPEED_FAST_PLUS		(0x3U)

/** I2C High Speed: 3.4 MHz */
#define I2C_SPEED_HIGH			(0x4U)

/** I2C Ultra Fast Speed: 5 MHz */
#define I2C_SPEED_ULTRA			(0x5U)

/** Device Tree specified speed */
#define I2C_SPEED_DT			(0x7U)

#define I2C_SPEED_SHIFT			(1U)
#define I2C_SPEED_SET(speed)		(((speed) << I2C_SPEED_SHIFT) \
						& I2C_SPEED_MASK)
#define I2C_SPEED_MASK			(0x7U << I2C_SPEED_SHIFT) /* 3 bits */
#define I2C_SPEED_GET(cfg) 		(((cfg) & I2C_SPEED_MASK) \
						>> I2C_SPEED_SHIFT)

/** Use 10-bit addressing. DEPRECATED - Use I2C_MSG_ADDR_10_BITS instead. */
#define I2C_ADDR_10_BITS		BIT(0)

/** Peripheral to act as Controller. */
#define I2C_MODE_CONTROLLER		BIT(4)

/**
 * @brief Complete I2C DT information
 *
 * @param bus is the I2C bus
 * @param addr is the target address
 */
struct i2c_dt_spec {
	const struct device *bus;
	uint16_t addr;
};

/**
 * @brief Structure initializer for i2c_dt_spec from devicetree (on I3C bus)
 *
 * This helper macro expands to a static initializer for a <tt>struct
 * i2c_dt_spec</tt> by reading the relevant bus and address data from
 * the devicetree.
 *
 * @param node_id Devicetree node identifier for the I2C device whose
 *                struct i2c_dt_spec to create an initializer for
 */
#define I2C_DT_SPEC_GET_ON_I3C(node_id)					\
	.bus = DEVICE_DT_GET(DT_BUS(node_id)),				\
	.addr = DT_PROP_BY_IDX(node_id, reg, 0)

/**
 * @brief Structure initializer for i2c_dt_spec from devicetree (on I2C bus)
 *
 * This helper macro expands to a static initializer for a <tt>struct
 * i2c_dt_spec</tt> by reading the relevant bus and address data from
 * the devicetree.
 *
 * @param node_id Devicetree node identifier for the I2C device whose
 *                struct i2c_dt_spec to create an initializer for
 */
#define I2C_DT_SPEC_GET_ON_I2C(node_id)					\
	.bus = DEVICE_DT_GET(DT_BUS(node_id)),				\
	.addr = DT_REG_ADDR(node_id)

/**
 * @brief Structure initializer for i2c_dt_spec from devicetree
 *
 * This helper macro expands to a static initializer for a <tt>struct
 * i2c_dt_spec</tt> by reading the relevant bus and address data from
 * the devicetree.
 *
 * @param node_id Devicetree node identifier for the I2C device whose
 *                struct i2c_dt_spec to create an initializer for
 */
#define I2C_DT_SPEC_GET(node_id)					\
	{								\
		COND_CODE_1(DT_ON_BUS(node_id, i3c),			\
			    (I2C_DT_SPEC_GET_ON_I3C(node_id)),		\
			    (I2C_DT_SPEC_GET_ON_I2C(node_id)))		\
	}

/**
 * @brief Structure initializer for i2c_dt_spec from devicetree instance
 *
 * This is equivalent to
 * <tt>I2C_DT_SPEC_GET(DT_DRV_INST(inst))</tt>.
 *
 * @param inst Devicetree instance number
 */
#define I2C_DT_SPEC_INST_GET(inst) \
	I2C_DT_SPEC_GET(DT_DRV_INST(inst))


/*
 * I2C_MSG_* are I2C Message flags.
 */

/** Write message to I2C bus. */
#define I2C_MSG_WRITE			(0U << 0U)

/** Read message from I2C bus. */
#define I2C_MSG_READ			BIT(0)

/** @cond INTERNAL_HIDDEN */
#define I2C_MSG_RW_MASK			BIT(0)
/** @endcond  */

/** Send STOP after this message. */
#define I2C_MSG_STOP			BIT(1)

/** RESTART I2C transaction for this message.
 *
 * @note Not all I2C drivers have or require explicit support for this
 * feature. Some drivers require this be present on a read message
 * that follows a write, or vice-versa.  Some drivers will merge
 * adjacent fragments into a single transaction using this flag; some
 * will not. */
#define I2C_MSG_RESTART			BIT(2)

/** Use 10-bit addressing for this message.
 *
 * @note Not all SoC I2C implementations support this feature. */
#define I2C_MSG_ADDR_10_BITS		BIT(3)

/**
 * @brief One I2C Message.
 *
 * This defines one I2C message to transact on the I2C bus.
 *
 * @note Some of the configurations supported by this API may not be
 * supported by specific SoC I2C hardware implementations, in
 * particular features related to bus transactions intended to read or
 * write data from different buffers within a single transaction.
 * Invocations of i2c_transfer() may not indicate an error when an
 * unsupported configuration is encountered.  In some cases drivers
 * will generate separate transactions for each message fragment, with
 * or without presence of @ref I2C_MSG_RESTART in #flags.
 */
struct i2c_msg {
	/** Data buffer in bytes */
	uint8_t		*buf;

	/** Length of buffer in bytes */
	uint32_t	len;

	/** Flags for this message */
	uint8_t		flags;
};

/**
 * @cond INTERNAL_HIDDEN
 *
 * These are for internal use only, so skip these in
 * public documentation.
 */

typedef int (*i2c_api_configure_t)(const struct device *dev,
				   uint32_t dev_config);
typedef int (*i2c_api_get_config_t)(const struct device *dev,
				    uint32_t *dev_config);
typedef int (*i2c_api_full_io_t)(const struct device *dev,
				 struct i2c_msg *msgs,
				 uint8_t num_msgs,
				 uint16_t addr);

typedef int (*i2c_api_recover_bus_t)(const struct device *dev);

struct i2c_driver_api {
	i2c_api_configure_t configure;
	i2c_api_get_config_t get_config;
	i2c_api_full_io_t transfer;
	i2c_api_recover_bus_t recover_bus;
};

/**
 * @endcond
 */

/**
 * @brief Validate that I2C bus is ready.
 *
 * @param spec I2C specification from devicetree
 *
 * @retval true if the I2C bus is ready for use.
 * @retval false if the I2C bus is not ready for use.
 */
static inline bool i2c_is_ready_dt(const struct i2c_dt_spec *spec)
{
	/* Validate bus is ready */
	return device_is_ready(spec->bus);
}

///**
// * @brief Dump out an I2C message
// *
// * Dumps out a list of I2C messages. For any that are writes (W), the data is
// * displayed in hex. Setting dump_read will dump the data for read messages too,
// * which only makes sense when called after the messages have been processed.
// *
// * It looks something like this (with name "testing"):
// *
// * @code
// * D: I2C msg: testing, addr=56
// * D:    W len=01: 06
// * D:    W len=0e:
// * D: contents:
// * D: 00 01 02 03 04 05 06 07 |........
// * D: 08 09 0a 0b 0c 0d       |......
// * D:    W len=01: 0f
// * D:    R len=01: 6c
// * @endcode
// *
// * @param dev Target for the messages being sent. Its name will be printed in the log.
// * @param msgs Array of messages to dump.
// * @param num_msgs Number of messages to dump.
// * @param addr Address of the I2C target device.
// * @param dump_read Dump data from I2C reads, otherwise only writes have data dumped.
// */
//void i2c_dump_msgs_rw(const struct device *dev, const struct i2c_msg *msgs, uint8_t num_msgs,
//                      uint16_t addr, bool dump_read);

///**
// * @brief Dump out an I2C message, before it is executed.
// *
// * This is equivalent to:
// *
// *     i2c_dump_msgs_rw(dev, msgs, num_msgs, addr, false);
// *
// * The read messages' data isn't dumped.
// *
// * @param dev Target for the messages being sent. Its name will be printed in the log.
// * @param msgs Array of messages to dump.
// * @param num_msgs Number of messages to dump.
// * @param addr Address of the I2C target device.
// */
//static inline void i2c_dump_msgs(const struct device *dev, const struct i2c_msg *msgs,
//                                 uint8_t num_msgs, uint16_t addr)
//{
//        i2c_dump_msgs_rw(dev, msgs, num_msgs, addr, false);
//}

#define I2C_DEVICE_DT_DEFINE(node_id, init_fn, pm, data, config, level,	\
			     prio, api, ...)				\
	DEVICE_DT_DEFINE(node_id, init_fn, pm, data, config, level,	\
			 prio, api, __VA_ARGS__)

/**
 * @brief Like I2C_DEVICE_DT_DEFINE() for an instance of a DT_DRV_COMPAT compatible
 *
 * @param inst instance number. This is replaced by
 * <tt>DT_DRV_COMPAT(inst)</tt> in the call to I2C_DEVICE_DT_DEFINE().
 *
 * @param ... other parameters as expected by I2C_DEVICE_DT_DEFINE().
 */
#define I2C_DEVICE_DT_INST_DEFINE(inst, ...)		\
	I2C_DEVICE_DT_DEFINE(DT_DRV_INST(inst), __VA_ARGS__)


/**
 * @brief Configure operation of a host controller.
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @param dev_config Bit-packed 32-bit value to the device runtime configuration
 * for the I2C controller.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error, failed to configure device.
 */
static inline int i2c_configure(const struct device *dev, uint32_t dev_config)
{
	const struct i2c_driver_api *api =
		(const struct i2c_driver_api *)dev->api;

	return api->configure(dev, dev_config);
}

/**
 * @brief Get configuration of a host controller.
 *
 * This routine provides a way to get current configuration. It is allowed to
 * call the function before i2c_configure, because some I2C ports can be
 * configured during init process. However, if the I2C port is not configured,
 * i2c_get_config returns an error.
 *
 * i2c_get_config can return cached config or probe hardware, but it has to be
 * up to date with current configuration.
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @param dev_config Pointer to return bit-packed 32-bit value of
 * the I2C controller configuration.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 * @retval -ERANGE Configured I2C frequency is invalid.
 * @retval -ENOSYS If get config is not implemented
 */
static inline int i2c_get_config(const struct device *dev, uint32_t *dev_config)
{
	const struct i2c_driver_api *api = (const struct i2c_driver_api *)dev->api;

	if (api->get_config == NULL) {
		return -ENOSYS;
	}

	return api->get_config(dev, dev_config);
}

/**
 * @brief Perform data transfer to another I2C device in controller mode.
 *
 * This routine provides a generic interface to perform data transfer
 * to another I2C device synchronously. Use i2c_read()/i2c_write()
 * for simple read or write.
 *
 * The array of message @a msgs must not be NULL.  The number of
 * message @a num_msgs may be zero,in which case no transfer occurs.
 *
 * @note Not all scatter/gather transactions can be supported by all
 * drivers.  As an example, a gather write (multiple consecutive
 * `i2c_msg` buffers all configured for `I2C_MSG_WRITE`) may be packed
 * into a single transaction by some drivers, but others may emit each
 * fragment as a distinct write transaction, which will not produce
 * the same behavior.  See the documentation of `struct i2c_msg` for
 * limitations on support for multi-message bus transactions.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param msgs Array of messages to transfer.
 * @param num_msgs Number of messages to transfer.
 * @param addr Address of the I2C target device.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_transfer(const struct device *dev,
			       struct i2c_msg *msgs, uint8_t num_msgs,
			       uint16_t addr)
{
	const struct i2c_driver_api *api =
		(const struct i2c_driver_api *)dev->api;

	int res =  api->transfer(dev, msgs, num_msgs, addr);

//        if (IS_ENABLED(CONFIG_I2C_DUMP_MESSAGES)) {
//                i2c_dump_msgs_rw(dev, msgs, num_msgs, addr, true);
//        }

	return res;
}

/**
 * @brief Perform data transfer to another I2C device in controller mode.
 *
 * This is equivalent to:
 *
 *     i2c_transfer(spec->bus, msgs, num_msgs, spec->addr);
 *
 * @param spec I2C specification from devicetree.
 * @param msgs Array of messages to transfer.
 * @param num_msgs Number of messages to transfer.
 *
 * @return a value from i2c_transfer()
 */
static inline int i2c_transfer_dt(const struct i2c_dt_spec *spec,
				  struct i2c_msg *msgs, uint8_t num_msgs)
{
	return i2c_transfer(spec->bus, msgs, num_msgs, spec->addr);
}

/**
 * @brief Recover the I2C bus
 *
 * Attempt to recover the I2C bus.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @retval 0 If successful
 * @retval -EBUSY If bus is not clear after recovery attempt.
 * @retval -EIO General input / output error.
 * @retval -ENOSYS If bus recovery is not implemented
 */
static inline int i2c_recover_bus(const struct device *dev)
{
	const struct i2c_driver_api *api =
		(const struct i2c_driver_api *)dev->api;

	if (api->recover_bus == NULL) {
		return -ENOSYS;
	}

	return api->recover_bus(dev);
}

/*
 * Derived i2c APIs -- all implemented in terms of i2c_transfer()
 */

/**
 * @brief Write a set amount of data to an I2C device.
 *
 * This routine writes a set amount of data synchronously.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param buf Memory pool from which the data is transferred.
 * @param num_bytes Number of bytes to write.
 * @param addr Address to the target I2C device for writing.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_write(const struct device *dev, const uint8_t *buf,
			    uint32_t num_bytes, uint16_t addr)
{
	struct i2c_msg msg;

	msg.buf = (uint8_t *)buf;
	msg.len = num_bytes;
	msg.flags = I2C_MSG_WRITE | I2C_MSG_STOP;

	return i2c_transfer(dev, &msg, 1, addr);
}

/**
 * @brief Write a set amount of data to an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_write(spec->bus, buf, num_bytes, spec->addr);
 *
 * @param spec I2C specification from devicetree.
 * @param buf Memory pool from which the data is transferred.
 * @param num_bytes Number of bytes to write.
 *
 * @return a value from i2c_write()
 */
static inline int i2c_write_dt(const struct i2c_dt_spec *spec,
			       const uint8_t *buf, uint32_t num_bytes)
{
	return i2c_write(spec->bus, buf, num_bytes, spec->addr);
}

/**
 * @brief Read a set amount of data from an I2C device.
 *
 * This routine reads a set amount of data synchronously.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param buf Memory pool that stores the retrieved data.
 * @param num_bytes Number of bytes to read.
 * @param addr Address of the I2C device being read.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_read(const struct device *dev, uint8_t *buf,
			   uint32_t num_bytes, uint16_t addr)
{
	struct i2c_msg msg;

	msg.buf = buf;
	msg.len = num_bytes;
	msg.flags = I2C_MSG_READ | I2C_MSG_STOP;

	return i2c_transfer(dev, &msg, 1, addr);
}

/**
 * @brief Read a set amount of data from an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_read(spec->bus, buf, num_bytes, spec->addr);
 *
 * @param spec I2C specification from devicetree.
 * @param buf Memory pool that stores the retrieved data.
 * @param num_bytes Number of bytes to read.
 *
 * @return a value from i2c_read()
 */
static inline int i2c_read_dt(const struct i2c_dt_spec *spec,
			      uint8_t *buf, uint32_t num_bytes)
{
	return i2c_read(spec->bus, buf, num_bytes, spec->addr);
}

/**
 * @brief Write then read data from an I2C device.
 *
 * This supports the common operation "this is what I want", "now give
 * it to me" transaction pair through a combined write-then-read bus
 * transaction.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param addr Address of the I2C device
 * @param write_buf Pointer to the data to be written
 * @param num_write Number of bytes to write
 * @param read_buf Pointer to storage for read data
 * @param num_read Number of bytes to read
 *
 * @retval 0 if successful
 * @retval negative on error.
 */
static inline int i2c_write_read(const struct device *dev, uint16_t addr,
				 const void *write_buf, size_t num_write,
				 void *read_buf, size_t num_read)
{
	struct i2c_msg msg[2];

	msg[0].buf = (uint8_t *)write_buf;
	msg[0].len = num_write;
	msg[0].flags = I2C_MSG_WRITE;

	msg[1].buf = (uint8_t *)read_buf;
	msg[1].len = num_read;
	msg[1].flags = I2C_MSG_RESTART | I2C_MSG_READ | I2C_MSG_STOP;

	return i2c_transfer(dev, msg, 2, addr);
}

/**
 * @brief Write then read data from an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_write_read(spec->bus, spec->addr,
 *                    write_buf, num_write,
 *                    read_buf, num_read);
 *
 * @param spec I2C specification from devicetree.
 * @param write_buf Pointer to the data to be written
 * @param num_write Number of bytes to write
 * @param read_buf Pointer to storage for read data
 * @param num_read Number of bytes to read
 *
 * @return a value from i2c_write_read()
 */
static inline int i2c_write_read_dt(const struct i2c_dt_spec *spec,
				    const void *write_buf, size_t num_write,
				    void *read_buf, size_t num_read)
{
	return i2c_write_read(spec->bus, spec->addr,
			      write_buf, num_write,
			      read_buf, num_read);
}

/**
 * @brief Read multiple bytes from an internal address of an I2C device.
 *
 * This routine reads multiple bytes from an internal address of an
 * I2C device synchronously.
 *
 * Instances of this may be replaced by i2c_write_read().
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param dev_addr Address of the I2C device for reading.
 * @param start_addr Internal address from which the data is being read.
 * @param buf Memory pool that stores the retrieved data.
 * @param num_bytes Number of bytes being read.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_burst_read(const struct device *dev,
				 uint16_t dev_addr,
				 uint8_t start_addr,
				 uint8_t *buf,
				 uint32_t num_bytes)
{
	return i2c_write_read(dev, dev_addr,
			      &start_addr, sizeof(start_addr),
			      buf, num_bytes);
}

/**
 * @brief Read multiple bytes from an internal address of an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_burst_read(spec->bus, spec->addr, start_addr, buf, num_bytes);
 *
 * @param spec I2C specification from devicetree.
 * @param start_addr Internal address from which the data is being read.
 * @param buf Memory pool that stores the retrieved data.
 * @param num_bytes Number of bytes to read.
 *
 * @return a value from i2c_burst_read()
 */
static inline int i2c_burst_read_dt(const struct i2c_dt_spec *spec,
				    uint8_t start_addr,
				    uint8_t *buf,
				    uint32_t num_bytes)
{
	return i2c_burst_read(spec->bus, spec->addr,
			      start_addr, buf, num_bytes);
}

/**
 * @brief Write multiple bytes to an internal address of an I2C device.
 *
 * This routine writes multiple bytes to an internal address of an
 * I2C device synchronously.
 *
 * @warning The combined write synthesized by this API may not be
 * supported on all I2C devices.  Uses of this API may be made more
 * portable by replacing them with calls to i2c_write() passing a
 * buffer containing the combined address and data.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param dev_addr Address of the I2C device for writing.
 * @param start_addr Internal address to which the data is being written.
 * @param buf Memory pool from which the data is transferred.
 * @param num_bytes Number of bytes being written.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_burst_write(const struct device *dev,
				  uint16_t dev_addr,
				  uint8_t start_addr,
				  const uint8_t *buf,
				  uint32_t num_bytes)
{
	struct i2c_msg msg[2];

	msg[0].buf = &start_addr;
	msg[0].len = 1U;
	msg[0].flags = I2C_MSG_WRITE;

	msg[1].buf = (uint8_t *)buf;
	msg[1].len = num_bytes;
	msg[1].flags = I2C_MSG_WRITE | I2C_MSG_STOP;

	return i2c_transfer(dev, msg, 2, dev_addr);
}

/**
 * @brief Write multiple bytes to an internal address of an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_burst_write(spec->bus, spec->addr, start_addr, buf, num_bytes);
 *
 * @param spec I2C specification from devicetree.
 * @param start_addr Internal address to which the data is being written.
 * @param buf Memory pool from which the data is transferred.
 * @param num_bytes Number of bytes being written.
 *
 * @return a value from i2c_burst_write()
 */
static inline int i2c_burst_write_dt(const struct i2c_dt_spec *spec,
				     uint8_t start_addr,
				     const uint8_t *buf,
				     uint32_t num_bytes)
{
	return i2c_burst_write(spec->bus, spec->addr,
			       start_addr, buf, num_bytes);
}

/**
 * @brief Read internal register of an I2C device.
 *
 * This routine reads the value of an 8-bit internal register of an I2C
 * device synchronously.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param dev_addr Address of the I2C device for reading.
 * @param reg_addr Address of the internal register being read.
 * @param value Memory pool that stores the retrieved register value.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_reg_read_byte(const struct device *dev,
				    uint16_t dev_addr,
				    uint8_t reg_addr, uint8_t *value)
{
	return i2c_write_read(dev, dev_addr,
			      &reg_addr, sizeof(reg_addr),
			      value, sizeof(*value));
}

/**
 * @brief Read internal register of an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_reg_read_byte(spec->bus, spec->addr, reg_addr, value);
 *
 * @param spec I2C specification from devicetree.
 * @param reg_addr Address of the internal register being read.
 * @param value Memory pool that stores the retrieved register value.
 *
 * @return a value from i2c_reg_read_byte()
 */
static inline int i2c_reg_read_byte_dt(const struct i2c_dt_spec *spec,
				       uint8_t reg_addr, uint8_t *value)
{
	return i2c_reg_read_byte(spec->bus, spec->addr, reg_addr, value);
}

/**
 * @brief Write internal register of an I2C device.
 *
 * This routine writes a value to an 8-bit internal register of an I2C
 * device synchronously.
 *
 * @note This function internally combines the register and value into
 * a single bus transaction.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param dev_addr Address of the I2C device for writing.
 * @param reg_addr Address of the internal register being written.
 * @param value Value to be written to internal register.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_reg_write_byte(const struct device *dev,
				     uint16_t dev_addr,
				     uint8_t reg_addr, uint8_t value)
{
	uint8_t tx_buf[2] = {reg_addr, value};

	return i2c_write(dev, tx_buf, 2, dev_addr);
}

/**
 * @brief Write internal register of an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_reg_write_byte(spec->bus, spec->addr, reg_addr, value);
 *
 * @param spec I2C specification from devicetree.
 * @param reg_addr Address of the internal register being written.
 * @param value Value to be written to internal register.
 *
 * @return a value from i2c_reg_write_byte()
 */
static inline int i2c_reg_write_byte_dt(const struct i2c_dt_spec *spec,
					uint8_t reg_addr, uint8_t value)
{
	return i2c_reg_write_byte(spec->bus, spec->addr, reg_addr, value);
}

/**
 * @brief Update internal register of an I2C device.
 *
 * This routine updates the value of a set of bits from an 8-bit internal
 * register of an I2C device synchronously.
 *
 * @note If the calculated new register value matches the value that
 * was read this function will not generate a write operation.
 *
 * @param dev Pointer to the device structure for an I2C controller
 * driver configured in controller mode.
 * @param dev_addr Address of the I2C device for updating.
 * @param reg_addr Address of the internal register being updated.
 * @param mask Bitmask for updating internal register.
 * @param value Value for updating internal register.
 *
 * @retval 0 If successful.
 * @retval -EIO General input / output error.
 */
static inline int i2c_reg_update_byte(const struct device *dev,
				      uint8_t dev_addr,
				      uint8_t reg_addr, uint8_t mask,
				      uint8_t value)
{
	uint8_t old_value, new_value;
	int rc;

	rc = i2c_reg_read_byte(dev, dev_addr, reg_addr, &old_value);
	if (rc != 0) {
		return rc;
	}

	new_value = (old_value & ~mask) | (value & mask);
	if (new_value == old_value) {
		return 0;
	}

	return i2c_reg_write_byte(dev, dev_addr, reg_addr, new_value);
}

/**
 * @brief Update internal register of an I2C device.
 *
 * This is equivalent to:
 *
 *     i2c_reg_update_byte(spec->bus, spec->addr, reg_addr, mask, value);
 *
 * @param spec I2C specification from devicetree.
 * @param reg_addr Address of the internal register being updated.
 * @param mask Bitmask for updating internal register.
 * @param value Value for updating internal register.
 *
 * @return a value from i2c_reg_update_byte()
 */
static inline int i2c_reg_update_byte_dt(const struct i2c_dt_spec *spec,
					 uint8_t reg_addr, uint8_t mask,
					 uint8_t value)
{
	return i2c_reg_update_byte(spec->bus, spec->addr,
				   reg_addr, mask, value);
}

#endif /* _INCLUDE_I2C_H_ */
