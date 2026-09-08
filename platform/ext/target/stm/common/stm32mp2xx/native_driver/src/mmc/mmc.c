/*
 * Copyright (c) 2024, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Define a simple and generic interface to access eMMC and SD-card devices. */

#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <lib/timeout.h>
#include <lib/delay.h>
#include <debug.h>
#include <mmc.h>

#define TIMEOUT_US_1_S			1000000U
#define SEND_OP_COND_MAX_RETRIES	100

#define MULT_BY_512K_SHIFT		19

static const unsigned char tran_speed_base[16] = {
	0U, 10U, 12U, 13U, 15U, 20U, 26U, 30U,
	35U, 40U, 45U, 52U, 55U, 60U, 70U, 80U
};

static const unsigned char sd_tran_speed_base[16] = {
	0U, 10U, 12U, 13U, 15U, 20U, 25U, 30U,
	35U, 40U, 45U, 50U, 55U, 60U, 70U, 80U
};

static bool is_cmd23_enabled(unsigned int mmc_flags)
{
	return ((mmc_flags & MMC_FLAG_CMD23) != 0U);
}

static bool is_sd_cmd6_enabled(unsigned int mmc_flags)
{
	return ((mmc_flags & MMC_FLAG_SD_CMD6) != 0U);
}

static int mmc_send_cmd(const struct device *dev,
			unsigned int idx, unsigned int arg,
			unsigned int r_type, unsigned int *r_data)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_cmd cmd;
	int ret;

	memset(&cmd, 0x0U, sizeof(struct mmc_cmd));
	cmd.cmd_idx = idx;
	cmd.cmd_arg = arg;
	cmd.resp_type = r_type;

	ret = ops->send_cmd(dev, &cmd);
	if ((ret == 0) && (r_data != NULL)) {
		int i;

		for (i = 0; i < 4; i++) {
			r_data[i] = cmd.resp_data[i];
		}
	}

	if (ret != 0) {
		ERROR("Send command %u error: %d\n", idx, ret);
	}

	return ret;
}

static int mmc_device_state(const struct device *dev)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	unsigned int resp_data[4] = {0U};
	uint64_t timeout;
	int ret;

	timeout = timeout_init_us(TIMEOUT_US_1_S);
	do {
		if (timeout_elapsed(timeout)) {
			ERROR("CMD13 failed after 1s retries\n");
			return -EIO;
		}

		ret = mmc_send_cmd(dev, MMC_CMD(13),
				   dev_info->rca << RCA_SHIFT_OFFSET,
				   MMC_RESPONSE_R1, &resp_data[0]);
		if (ret != 0) {
			continue;
		}

		if ((resp_data[0] & STATUS_SWITCH_ERROR) != 0U) {
			return -EIO;
		}
	} while ((resp_data[0] & STATUS_READY_FOR_DATA) == 0U);

	return MMC_GET_STATE(resp_data[0]);
}

static int mmc_set_ext_csd(const struct device *dev, unsigned int ext_cmd,
			   unsigned int value)
{
	int ret;

	ret = mmc_send_cmd(dev, MMC_CMD(6),
			   EXTCSD_WRITE_BYTES | EXTCSD_CMD(ext_cmd) |
			   EXTCSD_VALUE(value) | EXTCSD_CMD_SET_NORMAL,
			   MMC_RESPONSE_R1B, NULL);
	if (ret != 0) {
		return ret;
	}

	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return ret;
		}
	} while (ret == MMC_STATE_PRG);

	return 0;
}

static int mmc_sd_switch(const struct device *dev, unsigned int bus_width)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret;
	unsigned int bus_width_arg = 0U;
	unsigned int scr[2] = {0U};
	uint64_t timeout;

	ret = ops->prepare(dev, 0, (uintptr_t)&scr, sizeof(scr), true);
	if (ret != 0) {
		return ret;
	}

	/* CMD55: Application Specific Command */
	ret = mmc_send_cmd(dev, MMC_CMD(55), dev_info->rca << RCA_SHIFT_OFFSET,
			   MMC_RESPONSE_R5, NULL);
	if (ret != 0) {
		return ret;
	}

	timeout = timeout_init_us(TIMEOUT_US_1_S);
	/* ACMD51: SEND_SCR */
	do {
		ret = mmc_send_cmd(dev, MMC_ACMD(51), 0, MMC_RESPONSE_R1, NULL);
		if ((ret != 0) && timeout_elapsed(timeout)) {
			ERROR("ACMD51 failed after 1s retries (ret=%d)\n", ret);
			return ret;
		}
	} while (ret != 0);

	ret = ops->read(dev, 0, (uintptr_t)&scr, sizeof(scr));
	if (ret != 0) {
		return ret;
	}

	if (((scr[0] & SD_SCR_BUS_WIDTH_4) != 0U) &&
	    (bus_width == MMC_BUS_WIDTH_4)) {
		bus_width_arg = 2U;
	}

	/* CMD55: Application Specific Command */
	ret = mmc_send_cmd(dev, MMC_CMD(55), dev_info->rca << RCA_SHIFT_OFFSET,
			   MMC_RESPONSE_R5, NULL);
	if (ret != 0) {
		return ret;
	}

	/* ACMD6: SET_BUS_WIDTH */
	ret = mmc_send_cmd(dev, MMC_ACMD(6), bus_width_arg,
			   MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return ret;
	}

	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return ret;
		}
	} while (ret == MMC_STATE_PRG);

	return 0;
}

static int mmc_set_ios(const struct device *dev, unsigned int clk_rate,
		       unsigned int bus_width)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret;
	unsigned int width = bus_width;

	if (dev_info->dev_type != MMC_IS_EMMC) {
		if (width == MMC_BUS_WIDTH_8) {
			WARN("Wrong bus config for SD-card, force to 4\n");
			width = MMC_BUS_WIDTH_4;
		}

		ret = mmc_sd_switch(dev, width);
		if (ret != 0) {
			return ret;
		}
	} else if (dev_info->csd.spec_vers == 4U) {
		ret = mmc_set_ext_csd(dev, CMD_EXTCSD_BUS_WIDTH,
				      (unsigned int)width);
		if (ret != 0) {
			return ret;
		}
	} else {
		ERROR("Wrong MMC type or spec version\n");
		return -EINVAL;
	}

	return ops->set_ios(dev, clk_rate, width);
}

static int mmc_fill_device_info(const struct device *dev)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	unsigned long long c_size;
	unsigned int speed_idx;
	unsigned int nb_blocks;
	unsigned int freq_unit;
	int ret = 0;
	struct mmc_csd_sd_v2 *csd_sd_v2;

	switch (dev_info->dev_type) {
	case MMC_IS_EMMC:
		dev_info->block_size = MMC_BLOCK_SIZE;

		ret = ops->prepare(dev, 0, (uintptr_t)&dev_info->ext_csd,
				   sizeof(dev_info->ext_csd), true);
		if (ret != 0) {
			return ret;
		}

		/* MMC CMD8: SEND_EXT_CSD */
		ret = mmc_send_cmd(dev, MMC_CMD(8), 0, MMC_RESPONSE_R1, NULL);
		if (ret != 0) {
			return ret;
		}

		ret = ops->read(dev, 0, (uintptr_t)&dev_info->ext_csd,
				sizeof(dev_info->ext_csd));
		if (ret != 0) {
			return ret;
		}

		do {
			ret = mmc_device_state(dev);
			if (ret < 0) {
				return ret;
			}
		} while (ret != MMC_STATE_TRAN);

		nb_blocks = (dev_info->ext_csd[CMD_EXTCSD_SEC_CNT] << 0) |
			    (dev_info->ext_csd[CMD_EXTCSD_SEC_CNT + 1] << 8) |
			    (dev_info->ext_csd[CMD_EXTCSD_SEC_CNT + 2] << 16) |
			    (dev_info->ext_csd[CMD_EXTCSD_SEC_CNT + 3] << 24);

		dev_info->device_size = (unsigned long long)nb_blocks *
					dev_info->block_size;

		break;

	case MMC_IS_SD:
		/*
		 * Use the same mmc_csd struct, as required fields here
		 * (READ_BL_LEN, C_SIZE, CSIZE_MULT) are common with eMMC.
		 */
		dev_info->block_size = BIT_32(dev_info->csd.read_bl_len);

		c_size = ((unsigned long long)dev_info->csd.c_size_high << 2U) |
			 (unsigned long long)dev_info->csd.c_size_low;

		if (c_size == 0xFFFU) {
			return -EINVAL;
		}

		dev_info->device_size = (c_size + 1U) *
					BIT_64(dev_info->csd.c_size_mult + 2U) *
					dev_info->block_size;

		break;

	case MMC_IS_SD_HC:
		if (dev_info->csd.csd_structure != 1U) {
			return -EINVAL;
		}

		dev_info->block_size = MMC_BLOCK_SIZE;

		/* Need to use mmc_csd_sd_v2 struct */
		csd_sd_v2 = (struct mmc_csd_sd_v2 *)&dev_info->csd;
		c_size = ((unsigned long long)csd_sd_v2->c_size_high << 16U) |
			 (unsigned long long)csd_sd_v2->c_size_low;

		dev_info->device_size = (c_size + 1U) << MULT_BY_512K_SHIFT;

		break;

	default:
		ret = -EINVAL;
		break;
	}

	if (ret < 0) {
		return ret;
	}

	speed_idx = (dev_info->csd.tran_speed & CSD_TRAN_SPEED_MULT_MASK) >>
		    CSD_TRAN_SPEED_MULT_SHIFT;

	if (speed_idx <= 0U) {
		return -EINVAL;
	}

	if (dev_info->dev_type == MMC_IS_EMMC) {
		dev_info->max_bus_freq = tran_speed_base[speed_idx];
	} else {
		dev_info->max_bus_freq = sd_tran_speed_base[speed_idx];
	}

	freq_unit = dev_info->csd.tran_speed & CSD_TRAN_SPEED_UNIT_MASK;
	while (freq_unit != 0U) {
		dev_info->max_bus_freq *= 10U;
		--freq_unit;
	}

	dev_info->max_bus_freq *= 10000U;

	return 0;
}

static int sd_switch(const struct device *dev, unsigned int mode,
		     unsigned char group, unsigned char func)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	unsigned int group_shift = (group - 1U) * 4U;
	unsigned int group_mask = GENMASK(group_shift + 3U,  group_shift);
	unsigned int arg;
	int ret;

	ret = ops->prepare(dev, 0, (uintptr_t)&dev_info->sd_switch_func_status,
			   sizeof(dev_info->sd_switch_func_status), true);
	if (ret != 0) {
		return ret;
	}

	/* MMC CMD6: SWITCH_FUNC */
	arg = mode | SD_SWITCH_ALL_GROUPS_MASK;
	arg &= ~group_mask;
	arg |= func << group_shift;
	ret = mmc_send_cmd(dev, MMC_CMD(6), arg, MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return ret;
	}

	return ops->read(dev, 0, (uintptr_t)&dev_info->sd_switch_func_status,
			 sizeof(dev_info->sd_switch_func_status));
}

static int sd_send_op_cond(const struct device *dev)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int n;
	unsigned int resp_data[4];

	for (n = 0; n < SEND_OP_COND_MAX_RETRIES; n++) {
		int ret;

		/* CMD55: Application Specific Command */
		ret = mmc_send_cmd(dev, MMC_CMD(55), 0, MMC_RESPONSE_R1, NULL);
		if (ret != 0) {
			return ret;
		}

		/* ACMD41: SD_SEND_OP_COND */
		ret = mmc_send_cmd(dev, MMC_ACMD(41),
				   OCR_HCS | dev_info->ocr_voltage,
				   MMC_RESPONSE_R3, &resp_data[0]);
		if (ret != 0) {
			return ret;
		}

		if ((resp_data[0] & OCR_POWERUP) != 0U) {
			dev_info->ocr_value = resp_data[0];

			if ((dev_info->ocr_value & OCR_HCS) != 0U) {
				dev_info->dev_type = MMC_IS_SD_HC;
			} else {
				dev_info->dev_type = MMC_IS_SD;
			}

			return 0;
		}

		udelay(10000U);
	}

	ERROR("ACMD41 failed after %d retries\n", SEND_OP_COND_MAX_RETRIES);

	return -EIO;
}

static int mmc_reset_to_idle(const struct device *dev)
{
	int ret;

	/* CMD0: reset to IDLE */
	ret = mmc_send_cmd(dev, MMC_CMD(0), 0, 0, NULL);
	if (ret != 0) {
		return ret;
	}

	udelay(2000U);

	return 0;
}

static int mmc_send_op_cond(const struct device *dev)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret, n;
	unsigned int resp_data[4];

	for (n = 0; n < SEND_OP_COND_MAX_RETRIES; n++) {
		ret = mmc_send_cmd(dev, MMC_CMD(1), OCR_SECTOR_MODE |
				   OCR_VDD_MIN_2V7 | OCR_VDD_MIN_1V7,
				   MMC_RESPONSE_R3, &resp_data[0]);
		if (ret != 0) {
			return ret;
		}

		if ((resp_data[0] & OCR_POWERUP) != 0U) {
			dev_info->ocr_value = resp_data[0];
			return 0;
		}

		udelay(10000U);
	}

	ERROR("CMD1 failed after %d retries\n", SEND_OP_COND_MAX_RETRIES);

	return -EIO;
}

static int mmc_enumerate(const struct device *dev, unsigned int clk_rate,
			 unsigned int bus_width)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret;
	unsigned int resp_data[4];

	ret = ops->init(dev);
	if (ret != 0) {
		return ret;
	}

	ret = mmc_reset_to_idle(dev);
	if (ret != 0) {
		return ret;
	}

	if (dev_info->dev_type == MMC_IS_EMMC) {
		ret = mmc_send_op_cond(dev);
	} else {
		/* CMD8: Send Interface Condition Command */
		ret = mmc_send_cmd(dev, MMC_CMD(8),
				   VHS_2_7_3_6_V | CMD8_CHECK_PATTERN,
				   MMC_RESPONSE_R5, &resp_data[0]);

		if ((ret == 0) &&
		    ((resp_data[0] & 0xffU) == CMD8_CHECK_PATTERN)) {
			ret = sd_send_op_cond(dev);
		}
	}
	if (ret != 0) {
		return ret;
	}

	/* CMD2: Card Identification */
	ret = mmc_send_cmd(dev, MMC_CMD(2), 0, MMC_RESPONSE_R2, NULL);
	if (ret != 0) {
		return ret;
	}

	/* CMD3: Set Relative Address */
	if (dev_info->dev_type == MMC_IS_EMMC) {
		dev_info->rca = MMC_FIX_RCA;

		ret = mmc_send_cmd(dev, MMC_CMD(3),
				   dev_info->rca << RCA_SHIFT_OFFSET,
				   MMC_RESPONSE_R1, NULL);
		if (ret != 0) {
			return ret;
		}
	} else {
		ret = mmc_send_cmd(dev, MMC_CMD(3), 0,
				   MMC_RESPONSE_R6, &resp_data[0]);
		if (ret != 0) {
			return ret;
		}

		dev_info->rca = (resp_data[0] & 0xFFFF0000U) >> 16U;
	}

	/* CMD9: CSD Register */
	ret = mmc_send_cmd(dev, MMC_CMD(9), dev_info->rca << RCA_SHIFT_OFFSET,
			   MMC_RESPONSE_R2, &resp_data[0]);
	if (ret != 0) {
		return ret;
	}

	memcpy(&dev_info->csd, &resp_data, sizeof(resp_data));

	/* CMD7: Select Card */
	ret = mmc_send_cmd(dev, MMC_CMD(7), dev_info->rca << RCA_SHIFT_OFFSET,
			   MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return ret;
	}

	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return ret;
		}
	} while (ret != MMC_STATE_TRAN);

	ret = mmc_set_ios(dev, clk_rate, bus_width);
	if (ret != 0) {
		return ret;
	}

	ret = mmc_fill_device_info(dev);
	if (ret != 0) {
		return ret;
	}

	if (is_sd_cmd6_enabled(dev_info->flags) &&
	    (dev_info->dev_type == MMC_IS_SD_HC)) {
		struct sd_switch_status	*sd_switch_func_status;

		sd_switch_func_status = &dev_info->sd_switch_func_status;

		/* Try to switch to High Speed Mode */
		ret = sd_switch(dev, SD_SWITCH_FUNC_CHECK, 1U, 1U);
		if (ret != 0) {
			return ret;
		}

		if ((sd_switch_func_status->support_g1 & BIT(9)) == 0U) {
			/* High speed not supported, keep default speed */
			return 0;
		}

		ret = sd_switch(dev, SD_SWITCH_FUNC_SWITCH, 1U, 1U);
		if (ret != 0) {
			return ret;
		}

		if ((sd_switch_func_status->sel_g2_g1 & 0x1U) == 0U) {
			/* Cannot switch to high speed, keep default speed */
			return 0;
		}

		dev_info->max_bus_freq = 50000000U;
		ret = ops->set_ios(dev, clk_rate, bus_width);
	}

	return ret;
}

size_t mmc_read_blocks(const struct device *dev, int lba,
		       uintptr_t buf, size_t size)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret;
	unsigned int cmd_idx, cmd_arg;

	if ((size == 0U) || ((size & MMC_BLOCK_MASK) != 0U)) {
		return 0;
	}

	ret = ops->prepare(dev, lba, buf, size, true);
	if (ret != 0) {
		return 0;
	}

	if (is_cmd23_enabled(dev_info->flags)) {
		/* Set block count */
		ret = mmc_send_cmd(dev, MMC_CMD(23), size / MMC_BLOCK_SIZE,
				   MMC_RESPONSE_R1, NULL);
		if (ret != 0) {
			return 0;
		}

		cmd_idx = MMC_CMD(18);
	} else {
		if (size > MMC_BLOCK_SIZE) {
			cmd_idx = MMC_CMD(18);
		} else {
			cmd_idx = MMC_CMD(17);
		}
	}

	if (((dev_info->ocr_value & OCR_ACCESS_MODE_MASK) == OCR_BYTE_MODE) &&
	    (dev_info->dev_type != MMC_IS_SD_HC)) {
		cmd_arg = lba * MMC_BLOCK_SIZE;
	} else {
		cmd_arg = lba;
	}

	ret = mmc_send_cmd(dev, cmd_idx, cmd_arg, MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return 0;
	}

	ret = ops->read(dev, lba, buf, size);
	if (ret != 0) {
		return 0;
	}

	/* Wait buffer empty */
	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return 0;
		}
	} while ((ret != MMC_STATE_TRAN) && (ret != MMC_STATE_DATA));

	if (!is_cmd23_enabled(dev_info->flags) && (size > MMC_BLOCK_SIZE)) {
		ret = mmc_send_cmd(dev, MMC_CMD(12), 0, MMC_RESPONSE_R1B, NULL);
		if (ret != 0) {
			return 0;
		}
	}

	return size;
}

size_t mmc_write_blocks(const struct device *dev, int lba,
			const uintptr_t buf, size_t size)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	int ret;
	unsigned int cmd_idx, cmd_arg;

	if ((size == 0U) || ((size & MMC_BLOCK_MASK) != 0U)) {
		return 0;
	}

	ret = ops->prepare(dev, lba, buf, size, false);
	if (ret != 0) {
		return 0;
	}

	if (is_cmd23_enabled(dev_info->flags)) {
		/* Set block count */
		ret = mmc_send_cmd(dev, MMC_CMD(23), size / MMC_BLOCK_SIZE,
				   MMC_RESPONSE_R1, NULL);
		if (ret != 0) {
			return 0;
		}

		cmd_idx = MMC_CMD(25);
	} else {
		if (size > MMC_BLOCK_SIZE) {
			cmd_idx = MMC_CMD(25);
		} else {
			cmd_idx = MMC_CMD(24);
		}
	}

	if ((dev_info->ocr_value & OCR_ACCESS_MODE_MASK) == OCR_BYTE_MODE) {
		cmd_arg = lba * MMC_BLOCK_SIZE;
	} else {
		cmd_arg = lba;
	}

	ret = mmc_send_cmd(dev, cmd_idx, cmd_arg, MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return 0;
	}

	ret = ops->write(dev, lba, buf, size);
	if (ret != 0) {
		return 0;
	}

	/* Wait buffer empty */
	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return 0;
		}
	} while ((ret != MMC_STATE_TRAN) && (ret != MMC_STATE_RCV));

	if (!is_cmd23_enabled(dev_info->flags) && (size > MMC_BLOCK_SIZE)) {
		ret = mmc_send_cmd(dev, MMC_CMD(12), 0, MMC_RESPONSE_R1B, NULL);
		if (ret != 0) {
			return 0;
		}
	}

	return size;
}

size_t mmc_erase_blocks(const struct device *dev, int lba, size_t size)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);
	unsigned int cmd_erase_start = dev_info->dev_type == MMC_IS_EMMC ?
				       MMC_CMD(35) : MMC_CMD(32);
	unsigned int cmd_erase_end = dev_info->dev_type == MMC_IS_EMMC ?
				     MMC_CMD(36) : MMC_CMD(33);
	int ret;

	if ((size == 0U) || ((size & MMC_BLOCK_MASK) != 0U)) {
		return 0;
	}

	ret = mmc_send_cmd(dev, cmd_erase_start, lba, MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return 0;
	}

	ret = mmc_send_cmd(dev, cmd_erase_end, lba + (size / MMC_BLOCK_SIZE) - 1U,
			   MMC_RESPONSE_R1, NULL);
	if (ret != 0) {
		return 0;
	}

	ret = mmc_send_cmd(dev, MMC_CMD(38), lba, MMC_RESPONSE_R1B, NULL);
	if (ret != 0) {
		return 0;
	}

	do {
		ret = mmc_device_state(dev);
		if (ret < 0) {
			return 0;
		}
	} while (ret != MMC_STATE_TRAN);

	return size;
}

size_t mmc_get_device_size(const struct device *dev)
{
	const struct mmc_ops *ops = dev->api;
	struct mmc_dev_info *dev_info = ops->get_dev_info(dev);

	return dev_info->device_size;
}

int mmc_init(const struct device *dev, unsigned int clk_rate,
	     unsigned int width)
{
	const struct mmc_ops *ops;

	if ((dev == NULL) || (clk_rate == 0U)) {
		return -EINVAL;
	}

	switch (width) {
	case MMC_BUS_WIDTH_1:
	case MMC_BUS_WIDTH_4:
	case MMC_BUS_WIDTH_8:
	case MMC_BUS_WIDTH_DDR_4:
	case MMC_BUS_WIDTH_DDR_8:
		break;
	default:
		return -EINVAL;
	}

	ops = dev->api;

	if ((ops == NULL) || (ops->init == NULL) || (ops->send_cmd == NULL) ||
	    (ops->set_ios == NULL) || (ops->prepare == NULL) ||
	    (ops->read == NULL) || (ops->write == NULL) ||
	    (ops->get_dev_info == NULL)) {
		return -EINVAL;
	}

	if (ops->get_dev_info(dev) == NULL) {
		return -EINVAL;
	}

	return mmc_enumerate(dev, clk_rate, width);
}
