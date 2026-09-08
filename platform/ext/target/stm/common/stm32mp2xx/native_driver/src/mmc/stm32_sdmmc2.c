/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#define DT_DRV_COMPAT st_stm32mp25_sdmmc2

#include <stdint.h>
#include <string.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <lib/delay.h>
#include <debug.h>
#include <clk.h>
#include <pinctrl.h>
#include <reset.h>
#include <mmc.h>
#include <regulator.h>
#include <stm32_dcache.h>
#include <pm/device.h>
#include <pm/pm.h>

/* Registers offsets */
#define _SDMMC_POWER				0x00U
#define _SDMMC_CLKCR				0x04U
#define _SDMMC_ARGR				0x08U
#define _SDMMC_CMDR				0x0CU
#define _SDMMC_RESPCMDR				0x10U
#define _SDMMC_RESP1R				0x14U
#define _SDMMC_RESP2R				0x18U
#define _SDMMC_RESP3R				0x1CU
#define _SDMMC_RESP4R				0x20U
#define _SDMMC_DTIMER				0x24U
#define _SDMMC_DLENR				0x28U
#define _SDMMC_DCTRLR				0x2CU
#define _SDMMC_DCNTR				0x30U
#define _SDMMC_STAR				0x34U
#define _SDMMC_ICR				0x38U
#define _SDMMC_MASKR				0x3CU
#define _SDMMC_ACKTIMER				0x40U
#define _SDMMC_IDMACTRLR			0x50U
#define _SDMMC_IDMABSIZER			0x54U
#define _SDMMC_IDMABASE0R			0x58U
#define _SDMMC_IDMABASE1R			0x5CU
#define _SDMMC_FIFOR				0x80U

/* SDMMC power control register */
#define _SDMMC_POWER_PWRCTRL			GENMASK(1, 0)
#define _SDMMC_POWER_PWRCTRL_PWR_CYCLE		BIT(1)
#define _SDMMC_POWER_DIRPOL			BIT(4)

/* SDMMC clock control register */
#define _SDMMC_CLKCR_WIDBUS_4			BIT(14)
#define _SDMMC_CLKCR_WIDBUS_8			BIT(15)
#define _SDMMC_CLKCR_NEGEDGE			BIT(16)
#define _SDMMC_CLKCR_HWFC_EN			BIT(17)
#define _SDMMC_CLKCR_SELCLKRX_0			BIT(20)

/* SDMMC command register */
#define _SDMMC_CMDR_CMDTRANS			BIT(6)
#define _SDMMC_CMDR_CMDSTOP			BIT(7)
#define _SDMMC_CMDR_WAITRESP			GENMASK(9, 8)
#define _SDMMC_CMDR_WAITRESP_SHORT		BIT(8)
#define _SDMMC_CMDR_WAITRESP_SHORT_NOCRC	BIT(9)
#define _SDMMC_CMDR_CPSMEN			BIT(12)

/* SDMMC data control register */
#define _SDMMC_DCTRLR_DTEN			BIT(0)
#define _SDMMC_DCTRLR_DTDIR			BIT(1)
#define _SDMMC_DCTRLR_DTMODE			GENMASK(3, 2)
#define _SDMMC_DCTRLR_DBLOCKSIZE		GENMASK(7, 4)
#define _SDMMC_DCTRLR_DBLOCKSIZE_SHIFT		4
#define _SDMMC_DCTRLR_FIFORST			BIT(13)

#define _SDMMC_DCTRLR_CLEAR_MASK		(_SDMMC_DCTRLR_DTEN | \
						 _SDMMC_DCTRLR_DTDIR | \
						 _SDMMC_DCTRLR_DTMODE | \
						 _SDMMC_DCTRLR_DBLOCKSIZE)

/* SDMMC status register */
#define _SDMMC_STAR_CCRCFAIL			BIT(0)
#define _SDMMC_STAR_DCRCFAIL			BIT(1)
#define _SDMMC_STAR_CTIMEOUT			BIT(2)
#define _SDMMC_STAR_DTIMEOUT			BIT(3)
#define _SDMMC_STAR_TXUNDERR			BIT(4)
#define _SDMMC_STAR_RXOVERR			BIT(5)
#define _SDMMC_STAR_CMDREND			BIT(6)
#define _SDMMC_STAR_CMDSENT			BIT(7)
#define _SDMMC_STAR_DATAEND			BIT(8)
#define _SDMMC_STAR_DBCKEND			BIT(10)
#define _SDMMC_STAR_DPSMACT			BIT(12)
#define _SDMMC_STAR_RXFIFOHF			BIT(15)
#define _SDMMC_STAR_RXFIFOE			BIT(19)
#define _SDMMC_STAR_IDMATE			BIT(27)
#define _SDMMC_STAR_IDMABTC			BIT(28)

/* SDMMC DMA control register */
#define _SDMMC_IDMACTRLR_IDMAEN			BIT(0)

#define _SDMMC_STATIC_FLAGS			(_SDMMC_STAR_CCRCFAIL | \
						 _SDMMC_STAR_DCRCFAIL | \
						 _SDMMC_STAR_CTIMEOUT | \
						 _SDMMC_STAR_DTIMEOUT | \
						 _SDMMC_STAR_TXUNDERR | \
						 _SDMMC_STAR_RXOVERR  | \
						 _SDMMC_STAR_CMDREND  | \
						 _SDMMC_STAR_CMDSENT  | \
						 _SDMMC_STAR_DATAEND  | \
						 _SDMMC_STAR_DBCKEND  | \
						 _SDMMC_STAR_IDMATE   | \
						 _SDMMC_STAR_IDMABTC)

#define _TIMEOUT_US_10_MS			10000U
#define _TIMEOUT_US_2_S				2000000U

/* Power cycle delays in us */
#define _POWER_CYCLE_DELAY_US			2000U
#define _POWER_OFF_DELAY_US			2000U
#define _POWER_ON_DELAY_US			1000U

#define _STM32MP_MMC_INIT_FREQ			400000U		/* 400 KHz */
#define _STM32MP_SD_NORMAL_SPEED_MAX_FREQ	25000000U	/* 25 MHz */
#define _STM32MP_SD_HIGH_SPEED_MAX_FREQ		50000000U	/* 50 MHz */
#define _STM32MP_EMMC_NORMAL_SPEED_MAX_FREQ	26000000U	/* 26 MHz */
#define _STM32MP_EMMC_HIGH_SPEED_MAX_FREQ	52000000U	/* 52 MHz */

struct stm32_sdmmc2_config {
	uintptr_t base;
	unsigned int bus_width;
	unsigned int max_freq;
	bool use_ckin;
	bool negedge;
	bool dirpol;
	bool is_sd;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct pinctrl_dev_config *pcfg;
	const struct reset_control rst_ctl;
	const struct device *dev_vmmc;
	const struct device *dev_vqmmc;
};

struct stm32_sdmmc2_data {
	struct mmc_dev_info dev_info;
	struct clk *clk;
	uint32_t pin_ckin;
	uint32_t negedge;
	uint32_t dirpol;
	unsigned int width;
	bool next_cmd_is_acmd;
};

static int stm32_sdmmc2_send_cmd(const struct device *dev, struct mmc_cmd *cmd);

static int stm32_sdmmc2_init(const struct device *dev)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);
	uint32_t clock_div;
	uint32_t freq = _STM32MP_MMC_INIT_FREQ;
	int ret;

	ret = reset_control_reset(&drv_cfg->rst_ctl);
	if (ret != 0) {
		return ret;
	}

	if (drv_cfg->dev_vmmc != NULL) {
		ret = regulator_disable(drv_cfg->dev_vmmc);
		if (ret != 0) {
			return ret;
		}
	}

	if (drv_cfg->dev_vqmmc != NULL) {
		ret = regulator_disable(drv_cfg->dev_vqmmc);
		if (ret != 0) {
			return ret;
		}
	}

	mmio_write_32(drv_cfg->base + _SDMMC_POWER,
		      _SDMMC_POWER_PWRCTRL_PWR_CYCLE | drv_data->dirpol);
	udelay(_POWER_CYCLE_DELAY_US);

	if (drv_cfg->dev_vqmmc != NULL) {
		ret = regulator_enable(drv_cfg->dev_vqmmc);
		if (ret != 0) {
			return ret;
		}
	}

	if (drv_cfg->dev_vmmc != NULL) {
		ret = regulator_enable(drv_cfg->dev_vmmc);
		if (ret != 0) {
			return ret;
		}
	}

	mmio_write_32(drv_cfg->base + _SDMMC_POWER, drv_data->dirpol);
	udelay(_POWER_OFF_DELAY_US);

	if (drv_cfg->max_freq != 0U) {
		freq = MIN(drv_cfg->max_freq, freq);
	}

	clock_div = div_round_up(clk_get_rate(drv_data->clk), freq * 2U);
	mmio_write_32(drv_cfg->base + _SDMMC_CLKCR, _SDMMC_CLKCR_HWFC_EN |
		      clock_div | drv_data->negedge | drv_data->pin_ckin);
	mmio_write_32(drv_cfg->base + _SDMMC_POWER,
		      _SDMMC_POWER_PWRCTRL | drv_data->dirpol);
	udelay(_POWER_ON_DELAY_US);

	return 0;
}

static int stm32_sdmmc2_stop_transfer(const struct device *dev)
{
	struct mmc_cmd cmd_stop;

	memset(&cmd_stop, 0x0U, sizeof(struct mmc_cmd));
	cmd_stop.cmd_idx = MMC_CMD(12);
	cmd_stop.resp_type = MMC_RESPONSE_R1B;

	return stm32_sdmmc2_send_cmd(dev, &cmd_stop);
}

static int stm32_sdmmc2_send_cmd_req(const struct device *dev,
				     struct mmc_cmd *cmd)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);
	struct mmc_dev_info *dev_info = &drv_data->dev_info;
	uint32_t flags_cmd, status;
	uint32_t flags_data = 0;
	int err = 0;
	unsigned int cmd_reg, arg_reg;

	if (cmd == NULL) {
		return -EINVAL;
	}

	flags_cmd = _SDMMC_STAR_CTIMEOUT;
	arg_reg = cmd->cmd_arg;

	if ((mmio_read_32(drv_cfg->base + _SDMMC_CMDR) &
	    _SDMMC_CMDR_CPSMEN) != 0U) {
		mmio_write_32(drv_cfg->base + _SDMMC_CMDR, 0U);
	}

	cmd_reg = cmd->cmd_idx | _SDMMC_CMDR_CPSMEN;

	if (cmd->resp_type == 0U) {
		flags_cmd |= _SDMMC_STAR_CMDSENT;
	}

	if ((cmd->resp_type & MMC_RSP_48) != 0U) {
		if ((cmd->resp_type & MMC_RSP_136) != 0U) {
			flags_cmd |= _SDMMC_STAR_CMDREND;
			cmd_reg |= _SDMMC_CMDR_WAITRESP;
		} else if ((cmd->resp_type & MMC_RSP_CRC) != 0U) {
			flags_cmd |= _SDMMC_STAR_CMDREND | _SDMMC_STAR_CCRCFAIL;
			cmd_reg |= _SDMMC_CMDR_WAITRESP_SHORT;
		} else {
			flags_cmd |= _SDMMC_STAR_CMDREND;
			cmd_reg |= _SDMMC_CMDR_WAITRESP_SHORT_NOCRC;
		}
	}

	switch (cmd->cmd_idx) {
	case MMC_CMD(1):
		arg_reg |= OCR_POWERUP;
		break;
	case MMC_CMD(6):
		if ((dev_info->dev_type == MMC_IS_SD_HC) &&
		    (!drv_data->next_cmd_is_acmd)) {
			cmd_reg |= _SDMMC_CMDR_CMDTRANS;
			flags_data |= _SDMMC_STAR_DCRCFAIL |
				      _SDMMC_STAR_DTIMEOUT |
				      _SDMMC_STAR_DATAEND |
				      _SDMMC_STAR_RXOVERR |
				      _SDMMC_STAR_IDMATE |
				      _SDMMC_STAR_DBCKEND;
		}
		break;
	case MMC_CMD(8):
		if (dev_info->dev_type == MMC_IS_EMMC) {
			cmd_reg |= _SDMMC_CMDR_CMDTRANS;
		}
		break;
	case MMC_CMD(12):
		cmd_reg |= _SDMMC_CMDR_CMDSTOP;
		break;
	case MMC_CMD(17):
	case MMC_CMD(18):
		cmd_reg |= _SDMMC_CMDR_CMDTRANS;
		flags_data |= _SDMMC_STAR_DCRCFAIL |
			      _SDMMC_STAR_DTIMEOUT |
			      _SDMMC_STAR_DATAEND |
			      _SDMMC_STAR_RXOVERR |
			      _SDMMC_STAR_IDMATE;
		break;
	case MMC_CMD(24):
	case MMC_CMD(25):
		cmd_reg |= _SDMMC_CMDR_CMDTRANS;
		flags_data |= _SDMMC_STAR_DCRCFAIL |
			      _SDMMC_STAR_DTIMEOUT |
			      _SDMMC_STAR_DATAEND |
			      _SDMMC_STAR_TXUNDERR |
			      _SDMMC_STAR_IDMATE;
		break;
	case MMC_ACMD(41):
		arg_reg |= OCR_3_2_3_3 | OCR_3_3_3_4;
		break;
	case MMC_ACMD(51):
		cmd_reg |= _SDMMC_CMDR_CMDTRANS;
		flags_data |= _SDMMC_STAR_DCRCFAIL |
			      _SDMMC_STAR_DTIMEOUT |
			      _SDMMC_STAR_DATAEND |
			      _SDMMC_STAR_RXOVERR |
			      _SDMMC_STAR_IDMATE |
			      _SDMMC_STAR_DBCKEND;
		break;
	default:
		break;
	}

	drv_data->next_cmd_is_acmd = (cmd->cmd_idx == MMC_CMD(55));
	mmio_write_32(drv_cfg->base + _SDMMC_ICR, _SDMMC_STATIC_FLAGS);

	/*
	 * Clear the SDMMC_DCTRLR if the command does not await data.
	 * Skip CMD55 as the next command could be data related, and
	 * the register could have been set in prepare function.
	 */
	if (((cmd_reg & _SDMMC_CMDR_CMDTRANS) == 0U) &&
	    !drv_data->next_cmd_is_acmd) {
		mmio_write_32(drv_cfg->base + _SDMMC_DCTRLR, 0U);
	}

	if ((cmd->resp_type & MMC_RSP_BUSY) != 0U) {
		mmio_write_32(drv_cfg->base + _SDMMC_DTIMER, UINT32_MAX);
	}

	mmio_write_32(drv_cfg->base + _SDMMC_ARGR, arg_reg);
	mmio_write_32(drv_cfg->base + _SDMMC_CMDR, cmd_reg);

	err = mmio_read32_poll_timeout(drv_cfg->base + _SDMMC_STAR, status,
				       (status & flags_cmd) != 0U,
				       _TIMEOUT_US_10_MS);
	if (err != 0) {
		ERROR("%s: timeout 10ms (cmd = %u,status = %x)\n",
		      __func__, cmd->cmd_idx, status);
		goto err_exit;
	}

	if ((status & (_SDMMC_STAR_CTIMEOUT | _SDMMC_STAR_CCRCFAIL)) != 0U) {
		if ((status & _SDMMC_STAR_CTIMEOUT) != 0U) {
			err = -ETIMEDOUT;

			/*
			 * Those timeouts can occur, and framework will handle
			 * the retries. CMD8 is expected to return this timeout
			 * for eMMC
			 */
			if (!((cmd->cmd_idx == MMC_CMD(1)) ||
			      (cmd->cmd_idx == MMC_CMD(13)) ||
			      ((cmd->cmd_idx == MMC_CMD(8)) &&
			       (cmd->resp_type == MMC_RESPONSE_R7)))) {
				ERROR("%s: CTIMEOUT (cmd = %u,status = %x)\n",
				      __func__, cmd->cmd_idx, status);
			}
		} else {
			err = -EIO;
			ERROR("%s: CRCFAIL (cmd = %u,status = %x)\n",
			      __func__, cmd->cmd_idx, status);
		}

		goto err_exit;
	}

	if ((cmd_reg & _SDMMC_CMDR_WAITRESP) != 0U) {
		if ((cmd->cmd_idx == MMC_CMD(9)) &&
		    ((cmd_reg & _SDMMC_CMDR_WAITRESP) ==
		     _SDMMC_CMDR_WAITRESP)) {
			/* Need to invert response to match CSD structure */
			cmd->resp_data[0] = mmio_read_32(drv_cfg->base +
							 _SDMMC_RESP4R);
			cmd->resp_data[1] = mmio_read_32(drv_cfg->base +
							 _SDMMC_RESP3R);
			cmd->resp_data[2] = mmio_read_32(drv_cfg->base +
							 _SDMMC_RESP2R);
			cmd->resp_data[3] = mmio_read_32(drv_cfg->base +
							 _SDMMC_RESP1R);
		} else {
			cmd->resp_data[0] = mmio_read_32(drv_cfg->base +
							 _SDMMC_RESP1R);

			if ((cmd_reg & _SDMMC_CMDR_WAITRESP) ==
			    _SDMMC_CMDR_WAITRESP) {
				cmd->resp_data[1] = mmio_read_32(drv_cfg->base +
								 _SDMMC_RESP2R);
				cmd->resp_data[2] = mmio_read_32(drv_cfg->base +
								 _SDMMC_RESP3R);
				cmd->resp_data[3] = mmio_read_32(drv_cfg->base +
								 _SDMMC_RESP4R);
			}
		}
	}

	if (flags_data == 0U) {
		mmio_write_32(drv_cfg->base + _SDMMC_ICR, _SDMMC_STATIC_FLAGS);

		return 0;
	}

	err = mmio_read32_poll_timeout(drv_cfg->base + _SDMMC_STAR, status,
				       (status & flags_data) != 0U,
				       _TIMEOUT_US_2_S);
	if (err != 0) {
		ERROR("%s: timeout 2s (cmd = %u,status = %x)\n",
		      __func__, cmd->cmd_idx, status);
		goto err_exit;
	}

	if ((status & (_SDMMC_STAR_DTIMEOUT | _SDMMC_STAR_DCRCFAIL |
		       _SDMMC_STAR_TXUNDERR | _SDMMC_STAR_RXOVERR |
		       _SDMMC_STAR_TXUNDERR | _SDMMC_STAR_IDMATE)) != 0U) {
		ERROR("%s: Error flag (cmd = %u,status = %x)\n", __func__,
		      cmd->cmd_idx, status);
		err = -EIO;
	}

err_exit:
	mmio_write_32(drv_cfg->base + _SDMMC_ICR, _SDMMC_STATIC_FLAGS);
	mmio_clrbits_32(drv_cfg->base + _SDMMC_CMDR, _SDMMC_CMDR_CMDTRANS);

	if ((err != 0) && ((status & _SDMMC_STAR_DPSMACT) != 0U)) {
		int ret_stop = stm32_sdmmc2_stop_transfer(dev);

		if (ret_stop != 0) {
			return ret_stop;
		}
	}

	return err;
}

static int stm32_sdmmc2_send_cmd(const struct device *dev, struct mmc_cmd *cmd)
{
	uint8_t retry;
	int err;

	if (cmd == NULL) {
		return -EINVAL;
	}

	for (retry = 0U; retry < 3U; retry++) {
		err = stm32_sdmmc2_send_cmd_req(dev, cmd);
		if (err == 0) {
			return 0;
		}

		if ((cmd->cmd_idx == MMC_CMD(1)) ||
		    (cmd->cmd_idx == MMC_CMD(13))) {
			return 0; /* Retry managed by framework */
		}

		/* Command 8 is expected to fail for eMMC */
		if (cmd->cmd_idx != MMC_CMD(8)) {
			WARN(" CMD%u, Retry: %u, Error: %d\n",
			     cmd->cmd_idx, retry + 1U, err);
		}

		udelay(10U);
	}

	return err;
}

static int stm32_sdmmc2_set_ios(const struct device *dev, unsigned int clk_rate,
				unsigned int width)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);
	struct mmc_dev_info *dev_info = &drv_data->dev_info;
	uint32_t bus_cfg = 0;
	uint32_t clock_div, max_freq, freq;

	switch (width) {
	case MMC_BUS_WIDTH_1:
		break;
	case MMC_BUS_WIDTH_4:
		bus_cfg |= _SDMMC_CLKCR_WIDBUS_4;
		break;
	case MMC_BUS_WIDTH_8:
		bus_cfg |= _SDMMC_CLKCR_WIDBUS_8;
		break;
	default:
		return -EINVAL;
	}

	if (dev_info->dev_type == MMC_IS_EMMC) {
		if (dev_info->max_bus_freq >=
		    _STM32MP_EMMC_HIGH_SPEED_MAX_FREQ) {
			max_freq = _STM32MP_EMMC_HIGH_SPEED_MAX_FREQ;
		} else {
			max_freq = _STM32MP_EMMC_NORMAL_SPEED_MAX_FREQ;
		}
	} else {
		if (dev_info->max_bus_freq >=
		    _STM32MP_SD_HIGH_SPEED_MAX_FREQ) {
			max_freq = _STM32MP_SD_HIGH_SPEED_MAX_FREQ;
		} else {
			max_freq = _STM32MP_SD_NORMAL_SPEED_MAX_FREQ;
		}
	}

	if (drv_cfg->max_freq != 0U) {
		freq = MIN(drv_cfg->max_freq, max_freq);
	} else {
		freq = max_freq;
	}

	clock_div = div_round_up(clk_rate, freq * 2U);
	mmio_write_32(drv_cfg->base + _SDMMC_CLKCR,
		      _SDMMC_CLKCR_HWFC_EN | clock_div | bus_cfg |
		      drv_data->negedge | drv_data->pin_ckin);

	return 0;
}

static int stm32_sdmmc2_prepare(const struct device *dev, int lba,
				uintptr_t buf, size_t size, bool dir_read)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct mmc_cmd cmd;
	int ret;
	uint32_t data_ctrl = 0U;
	uint32_t arg_size;

	if ((size == 0U) || (size > UINT32_MAX) ||
	    ((buf & GENMASK(1, 0)) != 0U)) {
		return -EINVAL;
	}

	if (dir_read) {
		data_ctrl = _SDMMC_DCTRLR_DTDIR;
	}

	if (size > MMC_BLOCK_SIZE) {
		arg_size = MMC_BLOCK_SIZE;
	} else {
		arg_size = (uint32_t)size;
	}

	stm32_dcache_clean_inv(buf, buf + size - 1U);

	/* Prepare CMD 16*/
	mmio_write_32(drv_cfg->base + _SDMMC_DTIMER, 0U);
	mmio_write_32(drv_cfg->base + _SDMMC_DLENR, 0U);
	mmio_write_32(drv_cfg->base + _SDMMC_DCTRLR, 0U);

	memset(&cmd, 0x0U, sizeof(struct mmc_cmd));
	cmd.cmd_idx = MMC_CMD(16);
	cmd.cmd_arg = arg_size;
	cmd.resp_type = MMC_RESPONSE_R1;

	ret = stm32_sdmmc2_send_cmd(dev, &cmd);
	if (ret != 0) {
		ERROR("CMD16 failed\n");
		return ret;
	}

	/* Prepare data command */
	data_ctrl |= __builtin_ctz(arg_size) << _SDMMC_DCTRLR_DBLOCKSIZE_SHIFT;
	mmio_clrsetbits_32(drv_cfg->base + _SDMMC_DCTRLR,
			   _SDMMC_DCTRLR_CLEAR_MASK, data_ctrl);
	mmio_write_32(drv_cfg->base + _SDMMC_DTIMER, UINT32_MAX);
	mmio_write_32(drv_cfg->base + _SDMMC_DLENR, size);
	mmio_write_32(drv_cfg->base + _SDMMC_IDMABASE0R, buf);
	mmio_write_32(drv_cfg->base + _SDMMC_IDMACTRLR,
		      _SDMMC_IDMACTRLR_IDMAEN);

	return 0;
}

static int stm32_sdmmc2_read(const struct device *dev, int lba,
			     uintptr_t buf, size_t size)
{
	return 0;
}

static int stm32_sdmmc2_write(const struct device *dev, int lba,
			      uintptr_t buf, size_t size)
{
	return 0;
}

static struct mmc_dev_info *stm32_sdmmc2_get_dev_info(const struct device *dev)
{
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);

	return &drv_data->dev_info;
}

static __unused int stm32_sdmmc2_mmc_init(const struct device *dev)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);
	struct mmc_dev_info *dev_info = &drv_data->dev_info;
	int ret;

	drv_data->clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (drv_data->clk == NULL) {
		return -ENODEV;
	}

	ret = pinctrl_apply_state_optional(drv_cfg->pcfg,
					   PINCTRL_STATE_DEFAULT);
	if (ret != 0) {
		return ret;
	}

	if (drv_cfg->is_sd) {
		dev_info->dev_type = MMC_IS_SD;
		dev_info->flags = MMC_FLAG_SD_CMD6;
	} else {
		dev_info->dev_type = MMC_IS_EMMC;
	}

	dev_info->ocr_voltage = OCR_3_2_3_3 | OCR_3_3_3_4;
	if (drv_cfg->dirpol) {
		drv_data->dirpol = _SDMMC_POWER_DIRPOL;
	}
	if (drv_cfg->negedge) {
		drv_data->negedge = _SDMMC_CLKCR_NEGEDGE;
	}
	if (drv_cfg->use_ckin) {
		drv_data->pin_ckin = _SDMMC_CLKCR_SELCLKRX_0;
	}

	switch (drv_cfg->bus_width) {
	case 1:
		drv_data->width = MMC_BUS_WIDTH_1;
		break;
	case 4:
		drv_data->width = MMC_BUS_WIDTH_4;
		break;
	case 8:
		drv_data->width = MMC_BUS_WIDTH_8;
		break;
	default:
		return -EINVAL;
	}

	ret = clk_enable(drv_data->clk);
	if (ret != 0) {
		return ret;
	}

	ret = mmc_init(dev, clk_get_rate(drv_data->clk), drv_data->width);
	if (ret != 0) {
		clk_disable(drv_data->clk);
	}

	return ret;
}

#ifdef CONFIG_PM_DEVICE
static __unused int stm32_sdmmc_pm_action(const struct device *dev,
					  enum pm_device_action action,
					  uint32_t pm_hint)
{
	const struct stm32_sdmmc2_config *drv_cfg = dev_get_config(dev);
	struct stm32_sdmmc2_data *drv_data = dev_get_data(dev);
	int ret;

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		clk_disable(drv_data->clk);

		return pinctrl_apply_state_optional(drv_cfg->pcfg,
						    PINCTRL_STATE_SLEEP);
	}

	ret = pinctrl_apply_state_optional(drv_cfg->pcfg,
					   PINCTRL_STATE_DEFAULT);
	if (ret != 0) {
		return ret;
	}

	ret = clk_enable(drv_data->clk);
	if (ret != 0) {
		return ret;
	}

	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT)) {
		return 0;
	}

	return mmc_init(dev, clk_get_rate(drv_data->clk), drv_data->width);
}
#endif

static __maybe_unused const struct mmc_ops stm32_sdmmc2_mmc_ops = {
	.init = stm32_sdmmc2_init,
	.send_cmd = stm32_sdmmc2_send_cmd,
	.set_ios = stm32_sdmmc2_set_ios,
	.prepare = stm32_sdmmc2_prepare,
	.read = stm32_sdmmc2_read,
	.write = stm32_sdmmc2_write,
	.get_dev_info = stm32_sdmmc2_get_dev_info,
};

#define STM32_SDMMC2_INIT(n)							\
										\
PINCTRL_DT_INST_DEFINE(n);							\
										\
static const struct stm32_sdmmc2_config stm32_sdmmc2_mmc_cfg_##n = {		\
	.base = DT_INST_REG_ADDR(n),						\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),			\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),		\
	.rst_ctl = DT_INST_RESET_CONTROL_GET(n),				\
	.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),				\
	.dev_vmmc = DT_INST_DEV_REGULATOR_SUPPLY(n, vmmc),			\
	.dev_vqmmc = DT_INST_DEV_REGULATOR_SUPPLY(n, vqmmc),			\
	.use_ckin = DT_INST_PROP_OR(n, st_use_ckin, false),			\
	.negedge = DT_INST_PROP_OR(n, st_neg_edge, false),			\
	.dirpol = DT_INST_PROP_OR(n, st_sig_dir, false),			\
	.bus_width = DT_INST_PROP_OR(n, bus_width, 1U),				\
	.max_freq = DT_INST_PROP(n, max_frequency),				\
	.is_sd = DT_INST_PROP_OR(n, no_mmc, false),				\
};										\
										\
static struct stm32_sdmmc2_data stm32_sdmmc2_mmc_data_##n = {};			\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_sdmmc_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_INST_DEFINE(n,							\
		      &stm32_sdmmc2_mmc_init,					\
		      PM_DEVICE_DT_INST_GET(n),					\
		      &stm32_sdmmc2_mmc_data_##n, &stm32_sdmmc2_mmc_cfg_##n,	\
		      CORE, 12,							\
		      &stm32_sdmmc2_mmc_ops);

DT_INST_FOREACH_STATUS_OKAY(STM32_SDMMC2_INIT)
