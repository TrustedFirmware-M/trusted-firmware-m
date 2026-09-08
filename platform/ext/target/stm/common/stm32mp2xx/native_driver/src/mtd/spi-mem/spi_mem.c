/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <assert.h>
#include <string.h>
#include <lib/utils_def.h>
#include <debug.h>
#include <spi_mem.h>

static bool spi_mem_check_buswidth_req(const struct spi_slave *spi_slave,
				       uint8_t buswidth, bool tx)
{
	unsigned int mode = spi_slave->mode;

	switch (buswidth) {
	case 1U:
		return true;

	case 2U:
		if ((tx &&
		     (mode & (SPI_TX_DUAL | SPI_TX_QUAD | SPI_TX_OCTAL)) != 0U) ||
		    (!tx &&
		     (mode & (SPI_RX_DUAL | SPI_RX_QUAD | SPI_RX_OCTAL)) != 0U)) {
			return true;
		}
		break;

	case 4U:
		if ((tx && (mode & (SPI_TX_QUAD | SPI_TX_OCTAL)) != 0U) ||
		    (!tx && (mode & (SPI_RX_QUAD | SPI_RX_OCTAL)) != 0U)) {
			return true;
		}
		break;

	case 8U:
		if ((tx && (mode & SPI_TX_OCTAL) != 0U) ||
		    (!tx && (mode & SPI_RX_OCTAL) != 0U)) {
			return true;
		}
		break;

	default:
		break;
	}

	return false;
}

static bool spi_mem_supports_op(const struct spi_slave *spi_slave,
				const struct spi_mem_op *op)
{
	if (!spi_mem_check_buswidth_req(spi_slave, op->cmd.buswidth, true)) {
		return false;
	}

	if ((op->addr.nbytes != 0U) &&
	    !spi_mem_check_buswidth_req(spi_slave, op->addr.buswidth, true)) {
		return false;
	}

	if ((op->dummy.nbytes != 0U) &&
	    !spi_mem_check_buswidth_req(spi_slave, op->dummy.buswidth, true)) {
		return false;
	}

	if ((op->data.nbytes != 0U) &&
	    !spi_mem_check_buswidth_req(spi_slave, op->data.buswidth,
					op->data.dir == SPI_MEM_DATA_OUT)) {
		return false;
	}

	return true;
}

static int spi_mem_check_bus_ops(const struct spi_bus_ops *ops)
{
	bool error = false;

	if (ops == NULL) {
		VERBOSE("Ops not defined\n");
		return -EINVAL;
	}

	if (ops->claim_bus == NULL) {
		VERBOSE("Ops claim bus is not defined\n");
		error = true;
	}

	if (ops->release_bus == NULL) {
		VERBOSE("Ops release bus is not defined\n");
		error = true;
	}

	if (ops->exec_op == NULL) {
		VERBOSE("Ops exec op is not defined\n");
		error = true;
	}

	return error ? -EINVAL : 0;
}

/*
 * spi_mem_exec_op() - Execute a memory operation.
 * @spi_slave: Pointer to spi slave config.
 * @op: The memory operation to execute.
 *
 * This function first checks that @op is supported and then tries to execute
 * it.
 *
 * Return: 0 in case of success, a negative error code otherwise.
 */
int spi_mem_exec_op(const struct spi_slave *spi_slave,
		    const struct spi_mem_op *op)
{
	const struct spi_bus_ops *ops = spi_slave->dev_ctrl->api;
	int ret;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addqr:%x len:%x\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	if (!spi_mem_supports_op(spi_slave, op)) {
		WARN("Error in spi_mem_support\n");
		return -ENOTSUP;
	}

	ret = ops->claim_bus(spi_slave->dev_ctrl, spi_slave->cs,
			     spi_slave->max_hz, spi_slave->mode);
	if (ret != 0) {
		WARN("Error claim_bus\n");
		return ret;
	}

	ret = ops->exec_op(spi_slave->dev_ctrl, op);

	ops->release_bus(spi_slave->dev_ctrl);

	return ret;
}

/*
 * spi_mem_dirmap_read() - Read data through a direct mapping
 * @spi_slave: Pointer to spi slave config.
 * @op: The memory operation to execute.
 *
 * This function reads data from a memory device using a direct mapping.
 *
 * Return: 0 in case of success, a negative error code otherwise.
 */
int spi_mem_dirmap_read(const struct spi_slave *spi_slave,
			const struct spi_mem_op *op)
{
	const struct spi_bus_ops *ops = spi_slave->dev_ctrl->api;
	int ret;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addr:%x len:%x\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	if (op->data.dir != SPI_MEM_DATA_IN) {
		return -EINVAL;
	}

	if (op->data.nbytes == 0U) {
		return 0;
	}

	if (ops->dirmap_read == NULL) {
		return spi_mem_exec_op(spi_slave, op);
	}

	if (!spi_mem_supports_op(spi_slave, op)) {
		WARN("Error in spi_mem_support\n");
		return -ENOTSUP;
	}

	ret = ops->claim_bus(spi_slave->dev_ctrl, spi_slave->cs,
			     spi_slave->max_hz, spi_slave->mode);
	if (ret != 0) {
		WARN("Error claim_bus\n");
		return ret;
	}

	ret = ops->dirmap_read(spi_slave->dev_ctrl, op);

	ops->release_bus(spi_slave->dev_ctrl);

	return ret;
}

/*
 * spi_mem_get_mode() - Get dual/quad/octo mode
 * @tx_bus_width: TX bus width
 * @rx_bus_width: RX bus width
 * @mode: pointer to the returned value
 *
 * This function creates SPI mode flags.
 *
 * Return: 0 in case of success, a negative error code otherwise.
 */
int spi_mem_get_mode(unsigned int tx_bus_width, unsigned int rx_bus_width,
		     unsigned int *mode)
{
	*mode = 0U;

	switch (tx_bus_width) {
	case 1U:
		break;
	case 2U:
		*mode |= SPI_TX_DUAL;
		break;
	case 4U:
		*mode |= SPI_TX_QUAD;
		break;
	case 8U:
		*mode |= SPI_TX_OCTAL;
		break;
	default:
		return -EINVAL;
	}

	switch (rx_bus_width) {
	case 1U:
		break;
	case 2U:
		*mode |= SPI_RX_DUAL;
		break;
	case 4U:
		*mode |= SPI_RX_QUAD;
		break;
	case 8U:
		*mode |= SPI_RX_OCTAL;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

/*
 * spi_mem_init_slave() - SPI slave device initialization.
 * @spi_slave: Pointer to spi slave config.
 *
 * This function first checks that @ops are supported and then tries to find
 * a SPI slave device.
 *
 * Return: 0 in case of success, a negative error code otherwise.
 */
int spi_mem_init_slave(const struct spi_slave *spi_slave)
{
	if ((spi_slave->max_hz == 0U) || (spi_slave->dev_ctrl == NULL)) {
		return -EINVAL;
	}

	return spi_mem_check_bus_ops(spi_slave->dev_ctrl->api);
}
