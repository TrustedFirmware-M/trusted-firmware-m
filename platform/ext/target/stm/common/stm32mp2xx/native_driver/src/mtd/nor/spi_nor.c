/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <lib/timeout.h>
#include <debug.h>
#include <spi_nor.h>
#include <spi_mem.h>
#include <pm/device.h>

#define DT_DRV_COMPAT			jedec_spi_nor

/* Opcode */
#define SPI_NOR_OP_WREN			0x06U	/* Write enable */
#define SPI_NOR_OP_WRDI			0x04U	/* Write disable */
#define SPI_NOR_OP_WRSR			0x01U	/* Write status register 1 byte */
#define SPI_NOR_OP_READ_ID		0x9FU	/* Read JEDEC ID */
#define SPI_NOR_OP_READ_CR		0x35U	/* Read configuration register */
#define SPI_NOR_OP_READ_SR		0x05U	/* Read status register */
#define SPI_NOR_OP_READ_FSR		0x70U	/* Read flag status register */
#define SPINOR_OP_RDEAR			0xC8U	/* Read Extended Address Register */
#define SPINOR_OP_WREAR			0xC5U	/* Write Extended Address Register */

/* Used for Spansion flashes only. */
#define SPINOR_OP_BRWR			0x17U	/* Bank register write */
#define SPINOR_OP_BRRD			0x16U	/* Bank register read */

/* Read/write/erase opcodes */
#define SPI_NOR_OP_READ			0x03U	/* Read data bytes (low frequency) */
#define SPI_NOR_OP_READ_FAST		0x0BU	/* Read data bytes (high frequency) */
#define SPI_NOR_OP_READ_1_1_2		0x3BU	/* Read data bytes (Dual Output SPI) */
#define SPI_NOR_OP_READ_1_2_2		0xBBU	/* Read data bytes (Dual I/O SPI) */
#define SPI_NOR_OP_READ_1_1_4		0x6BU	/* Read data bytes (Quad Output SPI) */
#define SPI_NOR_OP_READ_1_4_4		0xEBU	/* Read data bytes (Quad I/O SPI) */
#define SPI_NOR_OP_READ_1_1_8		0x8BU	/* Read data bytes (Octal Output SPI) */
#define SPI_NOR_OP_READ_1_8_8		0xCBU	/* Read data bytes (Octal I/O SPI) */

#define SPI_NOR_OP_WRITE		0x02U	/* Write data bytes */
#define SPI_NOR_OP_WRITE_1_1_4		0x32U	/* Write data bytes (Quad page program) */
#define SPI_NOR_OP_WRITE_1_4_4		0x38U	/* Write data bytes (Quad page program) */
#define SPI_NOR_OP_WRITE_1_1_8		0x82U	/* Write data bytes (Octal page program) */
#define SPI_NOR_OP_WRITE_1_8_8		0xC2U	/* Write data bytes (Octal page program) */

#define SPI_NOR_OP_SE			0x20U	/* Erase a sector */
#define SPI_NOR_OP_BE			0xD8U	/* Erase a block */

/* Read/write/erase 4-bytes address opcodes */
#define SPI_NOR_OP_READ_1_1_4_4B	0x6CU	/* Read data bytes (Quad Output SPI) */

#define SPI_NOR_OP_WRITE_1_4_4_4B	0x3EU	/* Write data bytes (Quad page program) */

#define SPI_NOR_OP_SE_4B		0x21U	/* Erase a sector */
#define SPI_NOR_OP_BE_4B		0xDCU	/* Erase a block */

#define SR_WIP				BIT(0)	/* Write in progress */
#define CR_QUAD_EN_SPAN			BIT(1)	/* Spansion Quad I/O */
#define SR_QUAD_EN_MX			BIT(6)	/* Macronix Quad I/O */
#define FSR_READY			BIT(7)	/* Device status, 0 = Busy, 1 = Ready */

/* Defined IDs for supported memories */
#define SPANSION_ID			0x01U
#define MACRONIX_ID			0xC2U
#define MICRON_ID			0x2CU

#define BANK_SIZE			0x1000000U

#define WRITE_STATUS_TIMEOUT_US		100000U
#define PROGRAM_TIMEOUT_US		5000U
#define ERASE_TIMEOUT_US		5000000U

struct spi_nor_config {
	const struct device *dev_ctrl;
	uint32_t cs;
	uint32_t max_frequency;
	uint32_t rx_bus_width;
	uint32_t tx_bus_width;
	uint32_t size;
	uint32_t erase_size;
	uint32_t write_size;
	uint8_t read_cmd;
	uint8_t write_cmd;
	uint8_t erase_cmd;
	bool use_bank;
	bool use_fsr;
};

struct spi_nor_data {
	struct spi_slave spi_slave;
	struct spi_mem_op read_op;
	struct spi_mem_op write_op;
	struct spi_mem_op erase_op;
	uint8_t selected_bank;
	uint8_t bank_write_cmd;
	uint8_t bank_read_cmd;
};

static int spi_nor_reg(const struct device *dev, uint8_t reg, uint8_t *buf,
		       size_t len, enum spi_mem_data_dir dir)
{
	struct spi_nor_data *dev_data = dev_get_data(dev);
	struct spi_mem_op op;

	memset(&op, 0, sizeof(struct spi_mem_op));
	op.cmd.opcode = reg;
	op.cmd.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
	op.data.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
	op.data.dir = dir;
	op.data.nbytes = len;
	op.data.buf = buf;

	return spi_mem_exec_op(&dev_data->spi_slave, &op);
}

static inline int spi_nor_read_id(const struct device *dev, uint8_t *id)
{
	return spi_nor_reg(dev, SPI_NOR_OP_READ_ID, id, 1U, SPI_MEM_DATA_IN);
}

static inline int spi_nor_read_cr(const struct device *dev, uint8_t *cr)
{
	return spi_nor_reg(dev, SPI_NOR_OP_READ_CR, cr, 1U, SPI_MEM_DATA_IN);
}

static inline int spi_nor_read_sr(const struct device *dev, uint8_t *sr)
{
	return spi_nor_reg(dev, SPI_NOR_OP_READ_SR, sr, 1U, SPI_MEM_DATA_IN);
}

static inline int spi_nor_read_fsr(const struct device *dev, uint8_t *fsr)
{
	return spi_nor_reg(dev, SPI_NOR_OP_READ_FSR, fsr, 1U, SPI_MEM_DATA_IN);
}

static inline int spi_nor_write_en(const struct device *dev)
{
	return spi_nor_reg(dev, SPI_NOR_OP_WREN, NULL, 0U, SPI_MEM_DATA_OUT);
}

static inline int spi_nor_write_dis(const struct device *dev)
{
	return spi_nor_reg(dev, SPI_NOR_OP_WRDI, NULL, 0U, SPI_MEM_DATA_OUT);
}

/*
 * Check if device is ready.
 *
 * Return 0 if ready, 1 if busy or a negative error code otherwise
 */
static int spi_nor_ready(const struct device *dev)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	uint8_t sr;
	int ret;

	ret = spi_nor_read_sr(dev, &sr);
	if (ret != 0) {
		return ret;
	}

	if (dev_cfg->use_fsr) {
		uint8_t fsr;

		ret = spi_nor_read_fsr(dev, &fsr);
		if (ret != 0) {
			return ret;
		}

		return (((fsr & FSR_READY) != 0U) && ((sr & SR_WIP) == 0U)) ?
			0 : 1;
	}

	return (((sr & SR_WIP) == 0U) ? 0 : 1);
}

static int spi_nor_wait_ready(const struct device *dev, uint64_t timeout_us)
{
	int ret;
	uint64_t timeout = timeout_init_us(timeout_us);

	while (!timeout_elapsed(timeout)) {
		ret = spi_nor_ready(dev);
		if (ret <= 0) {
			return ret;
		}
	}

	return -ETIMEDOUT;
}

static int spi_nor_macronix_quad_enable(const struct device *dev)
{
	uint8_t sr;
	int ret;

	ret = spi_nor_read_sr(dev, &sr);
	if (ret != 0) {
		return ret;
	}

	if ((sr & SR_QUAD_EN_MX) != 0U) {
		return 0;
	}

	ret = spi_nor_write_en(dev);
	if (ret != 0) {
		return ret;
	}

	sr |= SR_QUAD_EN_MX;
	ret = spi_nor_reg(dev, SPI_NOR_OP_WRSR, &sr, 1U, SPI_MEM_DATA_OUT);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_wait_ready(dev, WRITE_STATUS_TIMEOUT_US);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_read_sr(dev, &sr);
	if ((ret != 0) || ((sr & SR_QUAD_EN_MX) == 0U)) {
		return -EINVAL;
	}

	return 0;
}

static int spi_nor_write_sr_cr(const struct device *dev, uint8_t *sr_cr)
{
	int ret;

	ret = spi_nor_write_en(dev);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_reg(dev, SPI_NOR_OP_WRSR, sr_cr, 2U, SPI_MEM_DATA_OUT);
	if (ret != 0) {
		return -EINVAL;
	}

	ret = spi_nor_wait_ready(dev, WRITE_STATUS_TIMEOUT_US);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

static int spi_nor_default_quad_enable(const struct device *dev)
{
	uint8_t sr_cr[2];
	int ret;

	ret = spi_nor_read_cr(dev, &sr_cr[1]);
	if (ret != 0) {
		return ret;
	}

	if ((sr_cr[1] & CR_QUAD_EN_SPAN) != 0U) {
		return 0;
	}

	sr_cr[1] |= CR_QUAD_EN_SPAN;
	ret = spi_nor_read_sr(dev, &sr_cr[0]);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_write_sr_cr(dev, sr_cr);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_read_cr(dev, &sr_cr[1]);
	if ((ret != 0) || ((sr_cr[1] & CR_QUAD_EN_SPAN) == 0U)) {
		return -EINVAL;
	}

	return 0;
}

static int spi_nor_quad_enable(const struct device *dev, uint8_t id)
{
	struct spi_nor_data *dev_data = dev_get_data(dev);
	int ret = 0;

	if ((dev_data->read_op.data.buswidth == 4U) ||
	    (dev_data->write_op.data.buswidth == 4U)) {
		switch (id) {
		case MACRONIX_ID:
			INFO("Enable Macronix quad support\n");
			ret = spi_nor_macronix_quad_enable(dev);
			break;
		case MICRON_ID:
			break;
		default:
			ret = spi_nor_default_quad_enable(dev);
			break;
		}
	}

	return ret;
}

static int spi_nor_clean_bar(const struct device *dev)
{
	struct spi_nor_data *dev_data = dev_get_data(dev);
	int ret;

	if (dev_data->selected_bank == 0U) {
		return 0;
	}

	dev_data->selected_bank = 0U;

	ret = spi_nor_write_en(dev);
	if (ret != 0) {
		return ret;
	}

	return spi_nor_reg(dev, dev_data->bank_write_cmd,
			   &dev_data->selected_bank, 1U, SPI_MEM_DATA_OUT);
}

static int spi_nor_write_bar(const struct device *dev, uint32_t offset)
{
	struct spi_nor_data *dev_data = dev_get_data(dev);
	uint8_t selected_bank = offset / BANK_SIZE;
	int ret;

	if (selected_bank == dev_data->selected_bank) {
		return 0;
	}

	ret = spi_nor_write_en(dev);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_reg(dev, dev_data->bank_write_cmd, &selected_bank,
			  1U, SPI_MEM_DATA_OUT);
	if (ret != 0) {
		return ret;
	}

	dev_data->selected_bank = selected_bank;

	return 0;
}

static int spi_nor_read_bar(const struct device *dev)
{
	struct spi_nor_data *dev_data = dev_get_data(dev);
	uint8_t selected_bank = 0U;
	int ret;

	ret = spi_nor_reg(dev, dev_data->bank_read_cmd, &selected_bank,
			  1U, SPI_MEM_DATA_IN);
	if (ret != 0) {
		return ret;
	}

	dev_data->selected_bank = selected_bank;

	return 0;
}

static int spi_nor_read(const struct device *dev, unsigned int offset,
			uintptr_t buffer, size_t length, size_t *length_read)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	struct spi_nor_data *dev_data = dev_get_data(dev);
	size_t remain_len;
	int ret = 0;

	*length_read = 0U;
	dev_data->read_op.addr.val = offset;
	dev_data->read_op.data.buf = (void *)buffer;

	VERBOSE("%s offset %i length %u\r\n", __func__, offset, length);

	while (length != 0U) {
		if (dev_cfg->use_bank) {
			ret = spi_nor_write_bar(dev,
						dev_data->read_op.addr.val);
			if (ret != 0) {
				return ret;
			}

			remain_len = ((dev_data->selected_bank + 1U) *
				      BANK_SIZE) - dev_data->read_op.addr.val;
			dev_data->read_op.data.nbytes = MIN(length, remain_len);
		} else {
			dev_data->read_op.data.nbytes = length;
		}

		ret = spi_mem_dirmap_read(&dev_data->spi_slave,
					  &dev_data->read_op);
		if (ret != 0) {
			goto read_err;
		}

		length -= dev_data->read_op.data.nbytes;
		dev_data->read_op.addr.val += dev_data->read_op.data.nbytes;
		dev_data->read_op.data.buf += dev_data->read_op.data.nbytes;
		*length_read += dev_data->read_op.data.nbytes;
	}

read_err:
	if (dev_cfg->use_bank) {
		spi_nor_clean_bar(dev);
	}

	return ret;
}

static int spi_nor_write(const struct device *dev, unsigned int offset,
			 uintptr_t buffer, size_t length, size_t *length_write)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	struct spi_nor_data *dev_data = dev_get_data(dev);
	size_t remain_len;
	size_t page_offset;
	int ret = 0;

	*length_write = 0U;
	dev_data->write_op.addr.val = offset;
	dev_data->write_op.data.buf = (void *)buffer;

	VERBOSE("%s offset %i length %u\r\n", __func__, offset, length);

	while (length != 0U) {
		page_offset = dev_data->write_op.addr.val % dev_cfg->write_size;
		remain_len = (size_t)dev_cfg->write_size - page_offset;
		dev_data->write_op.data.nbytes = MIN(length, remain_len);

		if (dev_cfg->use_bank) {
			ret = spi_nor_write_bar(dev,
						dev_data->write_op.addr.val);
			if (ret != 0) {
				return ret;
			}
		}

		ret = spi_nor_write_en(dev);
		if (ret != 0) {
			return ret;
		}

		ret = spi_mem_exec_op(&dev_data->spi_slave,
				      &dev_data->write_op);
		if (ret != 0) {
			goto write_err;
		}

		ret = spi_nor_wait_ready(dev, PROGRAM_TIMEOUT_US);
		if (ret != 0) {
			goto write_err;
		}

		length -= dev_data->write_op.data.nbytes;
		dev_data->write_op.addr.val += dev_data->write_op.data.nbytes;
		dev_data->write_op.data.buf += dev_data->write_op.data.nbytes;
		*length_write += dev_data->write_op.data.nbytes;
	}

write_err:
	if (dev_cfg->use_bank) {
		spi_nor_clean_bar(dev);
	}

	spi_nor_write_dis(dev);

	return ret;
}

static int spi_nor_erase(const struct device *dev, unsigned int offset)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	struct spi_nor_data *dev_data = dev_get_data(dev);
	int ret;

	VERBOSE("%s offset %i\r\n", __func__, offset);

	if ((offset % dev_cfg->erase_size) != 0U) {
		return -EINVAL;
	}

	dev_data->erase_op.addr.val = offset;

	if (dev_cfg->use_bank) {
		ret = spi_nor_write_bar(dev, dev_data->erase_op.addr.val);
		if (ret != 0) {
			return ret;
		}
	}

	ret = spi_nor_write_en(dev);
	if (ret != 0) {
		return ret;
	}

	ret = spi_mem_exec_op(&dev_data->spi_slave, &dev_data->erase_op);
	if (ret != 0) {
		goto erase_err;
	}

	ret = spi_nor_wait_ready(dev, ERASE_TIMEOUT_US);

erase_err:
	if (dev_cfg->use_bank) {
		spi_nor_clean_bar(dev);
	}

	spi_nor_write_dis(dev);

	return ret;
}

static int spi_nor_build_op(uint8_t cmd, struct spi_mem_op *op)
{
	int ret = 0;

	memset(op, 0U, sizeof(struct spi_mem_op));
	op->cmd.opcode = cmd;
	op->cmd.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
	op->addr.nbytes = 3U;
	op->addr.buswidth = SPI_MEM_BUSWIDTH_1_LINE;

	switch(cmd) {
	case SPI_NOR_OP_READ:
		op->data.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
		op->data.dir = SPI_MEM_DATA_IN;
		break;
	case SPI_NOR_OP_READ_FAST:
		op->dummy.nbytes = 1U;
		op->dummy.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
		op->data.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
		op->data.dir = SPI_MEM_DATA_IN;
		break;
	case SPI_NOR_OP_READ_1_1_4_4B:
		op->addr.nbytes = 4U;
		/* fall through */
	case SPI_NOR_OP_READ_1_1_4:
		op->dummy.nbytes = 1U;
		op->dummy.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
		op->data.buswidth = SPI_MEM_BUSWIDTH_4_LINE;
		op->data.dir = SPI_MEM_DATA_IN;
		break;

	case SPI_NOR_OP_WRITE:
		op->data.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
		op->data.dir = SPI_MEM_DATA_OUT;
		break;
	case SPI_NOR_OP_WRITE_1_4_4_4B:
		op->addr.nbytes = 4U;
		/* fall through */
	case SPI_NOR_OP_WRITE_1_4_4:
		op->addr.buswidth = SPI_MEM_BUSWIDTH_4_LINE;
		op->data.buswidth = SPI_MEM_BUSWIDTH_4_LINE;
		op->data.dir = SPI_MEM_DATA_OUT;
		break;

	case SPI_NOR_OP_BE_4B:
	case SPI_NOR_OP_SE_4B:
		op->addr.nbytes = 4U;
		/* fall through */
	case SPI_NOR_OP_BE:
	case SPI_NOR_OP_SE:
		break;

	default:
		ret = -EOPNOTSUPP;
		break;
	}

	return ret;
}

static __maybe_unused int spi_nor_init(const struct device *dev)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	struct spi_nor_data *dev_data = dev_get_data(dev);
	int ret;
	uint8_t id;

	if ((dev_cfg->erase_size == 0U) || (dev_cfg->write_size == 0U) ||
	    (dev_cfg->size == 0U)) {
		return -EINVAL;
	}

	/* Build the SPI MEM read command to use */
	ret = spi_nor_build_op(dev_cfg->read_cmd, &dev_data->read_op);
	if (ret != 0) {
		return ret;
	}

	/* Build the SPI MEM write command to use */
	ret = spi_nor_build_op(dev_cfg->write_cmd, &dev_data->write_op);
	if (ret != 0) {
		return ret;
	}

	/* Build the SPI MEM erase command to use */
	ret = spi_nor_build_op(dev_cfg->erase_cmd, &dev_data->erase_op);
	if (ret != 0) {
		return ret;
	}

	/* Set SPI bus parameters */
	dev_data->spi_slave.dev_ctrl = dev_cfg->dev_ctrl;
	dev_data->spi_slave.max_hz = dev_cfg->max_frequency;
	dev_data->spi_slave.cs = dev_cfg->cs;
	ret = spi_mem_get_mode(dev_cfg->tx_bus_width, dev_cfg->rx_bus_width,
			       &dev_data->spi_slave.mode);
	if (ret != 0) {
		return ret;
	}

	/* Check that SPI bus is ready */
	ret = spi_mem_init_slave(&dev_data->spi_slave);
	if (ret != 0) {
		return ret;
	}

	if ((dev_data->read_op.addr.nbytes != dev_data->write_op.addr.nbytes) ||
	    (dev_data->read_op.addr.nbytes != dev_data->erase_op.addr.nbytes)) {
		ERROR("%s: use 3-bytes or 4-bytes address opcodes, do not mixed\n",
		      __func__);
		return -EINVAL;
	}

	if ((dev_cfg->size > BANK_SIZE) &&
	    (dev_data->read_op.addr.nbytes == 3U) &&
	    !dev_cfg->use_bank) {
		WARN("%s: Only the first 16 MB of the memory are available.\r\n", __func__);
	}

	ret = spi_nor_read_id(dev, &id);
	if (ret != 0) {
		return ret;
	}

	if (dev_cfg->use_bank) {
		switch (id) {
		case SPANSION_ID:
			dev_data->bank_read_cmd = SPINOR_OP_BRRD;
			dev_data->bank_write_cmd = SPINOR_OP_BRWR;
			break;
		default:
			dev_data->bank_read_cmd = SPINOR_OP_RDEAR;
			dev_data->bank_write_cmd = SPINOR_OP_WREAR;
			break;
		}
	}

	ret = spi_nor_quad_enable(dev, id);
	if (ret != 0) {
		return ret;
	}

	if (dev_cfg->use_bank) {
		ret = spi_nor_read_bar(dev);
	}

	return ret;
}

#ifdef CONFIG_PM_DEVICE
static __maybe_unused int spi_nor_pm_action(const struct device *dev,
					    enum pm_device_action action,
					    uint32_t pm_hint)
{
	const struct spi_nor_config *dev_cfg = dev_get_config(dev);
	int ret = 0;
	uint8_t id;

	if (action == PM_DEVICE_ACTION_RESUME) {
		ret = spi_nor_read_id(dev, &id);
		if (ret != 0) {
			return ret;
		}

		ret = spi_nor_quad_enable(dev, id);
		if (ret != 0) {
			return ret;
		}

		if (dev_cfg->use_bank) {
			ret = spi_nor_read_bar(dev);
		}
	}

	return ret;
}
#endif

static __maybe_unused const struct spi_nor_ops spi_nor_ops = {
	.read = spi_nor_read,
	.write = spi_nor_write,
	.erase = spi_nor_erase,
};

#define DT_READ_CMD_PROP_OR(n)								\
	COND_CODE_1(DT_INST_NODE_HAS_PROP(n, read_cmd),					\
		    (_CONCAT(SPI_NOR_OP_, DT_STRING_TOKEN(DT_DRV_INST(n), read_cmd))),	\
		    (SPI_NOR_OP_READ))

#define DT_WRITE_CMD_PROP_OR(n)								\
	COND_CODE_1(DT_INST_NODE_HAS_PROP(n, write_cmd),				\
		    (_CONCAT(SPI_NOR_OP_, DT_STRING_TOKEN(DT_DRV_INST(n), write_cmd))),	\
		    (SPI_NOR_OP_WRITE))

#define DT_ERASE_CMD_PROP_OR(n)								\
	COND_CODE_1(DT_INST_NODE_HAS_PROP(n, erase_cmd),				\
		    (_CONCAT(SPI_NOR_OP_, DT_STRING_TOKEN(DT_DRV_INST(n), erase_cmd))),	\
		    (SPI_NOR_OP_BE))

#define SPI_NOR_INIT(n)									\
											\
static const struct spi_nor_config spi_nor_cfg_##n = {					\
	.dev_ctrl = DEVICE_DT_GET(DT_INST_PARENT(n)),					\
	.cs = DT_INST_PROP(n, reg),							\
	.rx_bus_width = DT_INST_PROP_OR(n, spi_rx_bus_width, 1),			\
	.tx_bus_width = DT_INST_PROP_OR(n, spi_tx_bus_width, 1),			\
	.max_frequency = DT_INST_PROP(n, spi_max_frequency),				\
	.size = DT_INST_PROP(n, size),							\
	.erase_size = DT_INST_PROP(n, erase_size),					\
	.write_size = DT_INST_PROP(n, write_size),					\
	.read_cmd = DT_READ_CMD_PROP_OR(n),						\
	.write_cmd = DT_WRITE_CMD_PROP_OR(n),						\
	.erase_cmd = DT_ERASE_CMD_PROP_OR(n),						\
	.use_bank = DT_INST_PROP(n, use_bank),						\
	.use_fsr = DT_INST_PROP(n, use_fsr),						\
};											\
											\
static struct spi_nor_data spi_nor_data_##n = {};					\
											\
PM_DEVICE_DT_INST_DEFINE(n, spi_nor_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n,								\
		      &spi_nor_init,							\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &spi_nor_data_##n, &spi_nor_cfg_##n,				\
		      CORE, 13,								\
		      &spi_nor_ops);

DT_INST_FOREACH_STATUS_OKAY(SPI_NOR_INIT)
