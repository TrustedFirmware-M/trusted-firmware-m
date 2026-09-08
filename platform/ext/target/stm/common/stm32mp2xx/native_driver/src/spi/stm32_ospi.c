/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#define DT_DRV_COMPAT st_stm32mp25_ospi

#include <stdint.h>
#include <string.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <debug.h>
#include <spi_mem.h>
#include <clk.h>
#include <pinctrl.h>
#include <reset.h>
#include <syscon.h>
#include <pm/device.h>
#include <pm/pm.h>

/* OCTOSPI registers */
#define _OSPI_CR			0x00U
#define _OSPI_DCR1			0x08U
#define _OSPI_DCR2			0x0CU
#define _OSPI_SR			0x20U
#define _OSPI_FCR			0x24U
#define _OSPI_DLR			0x40U
#define _OSPI_AR			0x48U
#define _OSPI_DR			0x50U
#define _OSPI_CCR			0x100U
#define _OSPI_TCR			0x108U
#define _OSPI_IR			0x110U
#define _OSPI_ABR			0x120U

/* OCTOSPI control register */
#define _OSPI_CR_EN			BIT(0)
#define _OSPI_CR_ABORT			BIT(1)
#define _OSPI_CR_CSSEL			BIT(24)
#define _OSPI_CR_FMODE			GENMASK_32(29, 28)
#define _OSPI_CR_FMODE_SHIFT		28U
#define _OSPI_CR_FMODE_INDW		0U
#define _OSPI_CR_FMODE_INDR		1U
#define _OSPI_CR_FMODE_MM		3U

/* OCTOSPI device configuration register 1 */
#define _OSPI_DCR1_CKMODE		BIT(0)
#define _OSPI_DCR1_DLYBYP		BIT(3)
#define _OSPI_DCR1_CSHT			GENMASK_32(13, 8)
#define _OSPI_DCR1_CSHT_SHIFT		8U
#define _OSPI_DCR1_DEVSIZE		GENMASK_32(20, 16)

/* OCTOSPI device configuration register 2 */
#define _OSPI_DCR2_PRESCALER		GENMASK_32(7, 0)

/* OCTOSPI status register */
#define _OSPI_SR_TEF			BIT(0)
#define _OSPI_SR_TCF			BIT(1)
#define _OSPI_SR_FTF			BIT(2)
#define _OSPI_SR_SMF			BIT(3)
#define _OSPI_SR_BUSY			BIT(5)

/* OCTOSPI flag clear register */
#define _OSPI_FCR_CTEF			BIT(0)
#define _OSPI_FCR_CTCF			BIT(1)
#define _OSPI_FCR_CSMF			BIT(3)

/* OCTOSPI communication configuration register */
#define _OSPI_CCR_ADMODE_SHIFT		8U
#define _OSPI_CCR_ADSIZE_SHIFT		12U
#define _OSPI_CCR_ABMODE_SHIFT		16U
#define _OSPI_CCR_ABSIZE_SHIFT		20U
#define _OSPI_CCR_DMODE_SHIFT		24U

/* OCTOSPI timing configuration register */
#define _OSPI_TCR_DCYC			GENMASK_32(4, 0)
#define _OSPI_TCR_SSHIFT		BIT(30)

/* OCTOSPI SYSCFG DLYBOS registers */
#define _DLYBOS_CR		0x0U
#define _DLYBOS_SR		0x4U

/* OCTOSPI SYSCFG DLYBOS control register */
#define _DLYBOS_CR_EN			BIT(0)
#define _DLYBOS_CR_RXTAPSEL_SHIFT	1U
#define _DLYBOS_CR_RXTAPSEL		GENMASK(6, 1)
#define _DLYBOS_CR_TXTAPSEL_SHIFT	7U
#define _DLYBOS_CR_TXTAPSEL		GENMASK(12, 7)
#define _DLYBOS_TAPSEL_NB		33U
#define _DLYBOS_BYP_EN			BIT(16)
#define _DLYBOS_BYP_CMD			GENMASK(21, 17)

/* OCTOSPI SYSCFG DLYBOS status register */
#define _DLYBOS_SR_LOCK			BIT(0)
#define _DLYBOS_SR_RXTAPSEL_ACK		BIT(1)
#define _DLYBOS_SR_TXTAPSEL_ACK		BIT(2)

#define _OSPI_MAX_CHIP			2U

#define _OSPI_FIFO_TIMEOUT_US		30U
#define _OSPI_CMD_TIMEOUT_US		1000U
#define _OSPI_BUSY_TIMEOUT_US		100U
#define _OSPI_ABT_TIMEOUT_US		100U
#define _DLYBOS_TIMEOUT_US		10000U

#define _FREQ_100MHZ			100000000U
#define _DLYB_FREQ_50MHZ		50000000U

#define _OP_READ_ID			0x9FU
#define _MAX_ID_LEN			8U

struct stm32_ospi_config {
	uintptr_t base;
	uintptr_t mm_base;
	size_t mm_size;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct pinctrl_dev_config *pcfg;
	const struct reset_control *rst_ctl;
	int n_rst;
	const struct device *dlyb_dev;
	uint16_t dlyb_base;
};

struct stm32_ospi_data {
	uint64_t str_idcode;
	int cs_used;
};

static int stm32_ospi_wait_for_not_busy(const struct device *dev)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint32_t sr;
	int ret;

	ret = mmio_read32_poll_timeout(drv_cfg->base + _OSPI_SR, sr,
				       (sr & _OSPI_SR_BUSY) == 0U,
				       _OSPI_BUSY_TIMEOUT_US);
	if (ret != 0) {
		ERROR("%s: busy timeout\n", __func__);
	}

	return ret;
}

static int stm32_ospi_wait_cmd(const struct device *dev,
			       const struct spi_mem_op *op)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint32_t sr;
	int ret = 0;

	ret = mmio_read32_poll_timeout(drv_cfg->base + _OSPI_SR, sr,
				       (sr & _OSPI_SR_TCF) != 0U,
				       _OSPI_CMD_TIMEOUT_US);
	if (ret != 0) {
		ERROR("%s: cmd timeout\n", __func__);
	} else if ((mmio_read_32(drv_cfg->base + _OSPI_SR) & _OSPI_SR_TEF)
		   != 0U) {
		ERROR("%s: transfer error\n", __func__);
		ret = -EIO;
	}

	/* Clear flags */
	mmio_write_32(drv_cfg->base + _OSPI_FCR, _OSPI_FCR_CTCF | _OSPI_FCR_CTEF);

	if (ret == 0) {
		ret = stm32_ospi_wait_for_not_busy(dev);
	}

	return ret;
}

static void stm32_ospi_read_fifo(uint8_t *val, uintptr_t addr)
{
	*val = mmio_read_8(addr);
}

static void stm32_ospi_write_fifo(uint8_t *val, uintptr_t addr)
{
	mmio_write_8(addr, *val);
}

static int stm32_ospi_poll(const struct device *dev,
			   const struct spi_mem_op *op)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	void (*fifo)(uint8_t *val, uintptr_t addr);
	uint32_t len;
	uint8_t *buf;
	uint32_t sr;
	int ret;

	if (op->data.dir == SPI_MEM_DATA_IN) {
		fifo = stm32_ospi_read_fifo;
	} else {
		fifo = stm32_ospi_write_fifo;
	}

	buf = (uint8_t *)op->data.buf;

	for (len = op->data.nbytes; len != 0U; len--) {
		ret = mmio_read32_poll_timeout(drv_cfg->base + _OSPI_SR, sr,
					       (sr & _OSPI_SR_FTF) != 0U,
					       _OSPI_FIFO_TIMEOUT_US);
		if (ret != 0) {
			ERROR("%s: fifo timeout\n", __func__);
			return ret;
		}

		fifo(buf++, drv_cfg->base + _OSPI_DR);
	}

	return 0;
}

static int stm32_ospi_mm(const struct device *dev, const struct spi_mem_op *op)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uintptr_t from = drv_cfg->mm_base + op->addr.val;
	uint32_t nbytes = op->data.nbytes;
	uint8_t *buf = op->data.buf;

	while ((nbytes != 0U) && !((from % sizeof(uint32_t)) == 0U)) {
		*(uint8_t *)buf = mmio_read_8(from);
		buf++;
		from++;
		nbytes--;
	}

	while (nbytes >= sizeof(uint32_t)) {
		*(uint32_t *)buf = mmio_read_32(from);
		buf += sizeof(uint32_t);
		from += sizeof(uint32_t);
		nbytes -= sizeof(uint32_t);
	}

	while (nbytes != 0U) {
		*(uint8_t *)buf = mmio_read_8(from);
		buf++;
		from++;
		nbytes--;
	}

	return 0;
}

static int stm32_ospi_tx(const struct device *dev, const struct spi_mem_op *op,
			 uint8_t fmode)
{
	if (op->data.nbytes == 0U) {
		return 0;
	}

	if (fmode == _OSPI_CR_FMODE_MM) {
		return stm32_ospi_mm(dev, op);
	}

	return stm32_ospi_poll(dev, op);
}

static unsigned int stm32_ospi_get_mode(uint8_t buswidth)
{
	switch (buswidth) {
	case SPI_MEM_BUSWIDTH_8_LINE:
		return 4U;
	case SPI_MEM_BUSWIDTH_4_LINE:
		return 3U;
	default:
		return buswidth;
	}
}

static int stm32_ospi_send(const struct device *dev,
			   const struct spi_mem_op *op, uint8_t fmode)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint32_t ccr;
	uint32_t dcyc = 0U;
	uint32_t cr;
	int ret;

	VERBOSE("%s: cmd:%x mode:%d.%d.%d.%d addr:%x len:%x\r\n",
		__func__, op->cmd.opcode, op->cmd.buswidth, op->addr.buswidth,
		op->dummy.buswidth, op->data.buswidth,
		op->addr.val, op->data.nbytes);

	ret = stm32_ospi_wait_for_not_busy(dev);
	if (ret != 0) {
		return ret;
	}

	if (op->data.nbytes != 0U) {
		mmio_write_32(drv_cfg->base + _OSPI_DLR, op->data.nbytes - 1U);
	}

	if ((op->dummy.buswidth != 0U) && (op->dummy.nbytes != 0U)) {
		dcyc = op->dummy.nbytes * 8U / op->dummy.buswidth;
	}

	mmio_clrsetbits_32(drv_cfg->base + _OSPI_TCR, _OSPI_TCR_DCYC, dcyc);

	mmio_clrsetbits_32(drv_cfg->base + _OSPI_CR, _OSPI_CR_FMODE,
			   fmode << _OSPI_CR_FMODE_SHIFT);

	ccr = stm32_ospi_get_mode(op->cmd.buswidth);

	if (op->addr.nbytes != 0U) {
		ccr |= (op->addr.nbytes - 1U) << _OSPI_CCR_ADSIZE_SHIFT;
		ccr |= stm32_ospi_get_mode(op->addr.buswidth) <<
		       _OSPI_CCR_ADMODE_SHIFT;
	}

	if (op->data.nbytes != 0U) {
		ccr |= stm32_ospi_get_mode(op->data.buswidth) <<
		       _OSPI_CCR_DMODE_SHIFT;
	}

	mmio_write_32(drv_cfg->base + _OSPI_CCR, ccr);

	mmio_write_32(drv_cfg->base + _OSPI_IR, op->cmd.opcode);

	if ((op->addr.nbytes != 0U) && (fmode != _OSPI_CR_FMODE_MM)) {
		mmio_write_32(drv_cfg->base + _OSPI_AR, op->addr.val);
	}

	ret = stm32_ospi_tx(dev, op, fmode);

	/*
	 * Abort in:
	 * - Error case.
	 * - Memory mapped read: prefetching must be stopped if we read the last
	 *   byte of device (device size - fifo size). If device size is not
	 *   known then prefetching is always stopped.
	 */
	if ((ret != 0) || (fmode == _OSPI_CR_FMODE_MM)) {
		goto abort;
	}

	/* Wait end of TX in indirect mode */
	ret = stm32_ospi_wait_cmd(dev, op);
	if (ret != 0) {
		goto abort;
	}

	return 0;

abort:
	mmio_setbits_32(drv_cfg->base + _OSPI_CR, _OSPI_CR_ABORT);

	/* Wait clear of abort bit by hardware */
	ret = mmio_read32_poll_timeout(drv_cfg->base + _OSPI_CR, cr,
				       (cr & _OSPI_CR_ABORT) == 0U,
				       _OSPI_ABT_TIMEOUT_US);

	mmio_write_32(drv_cfg->base + _OSPI_FCR, _OSPI_FCR_CTCF);

	if (ret != 0) {
		ERROR("%s: exec op error\n", __func__);
	}

	return ret;
}

static int stm32_ospi_set_mode(const struct device *dev, unsigned int mode)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);

	if ((mode & SPI_CS_HIGH) != 0U) {
		return -ENODEV;
	}

	if (((mode & SPI_CPHA) != 0U) && ((mode & SPI_CPOL) != 0U)) {
		mmio_setbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_CKMODE);
	} else if (((mode & SPI_CPHA) == 0U) && ((mode & SPI_CPOL) == 0U)) {
		mmio_clrbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_CKMODE);
	} else {
		return -ENODEV;
	}

#if DEBUG
	VERBOSE("%s: mode=0x%x\n", __func__, mode);

	if ((mode & SPI_RX_OCTAL) != 0U) {
		VERBOSE("rx: octal\n");
	} else if ((mode & SPI_RX_QUAD) != 0U) {
		VERBOSE("rx: quad\n");
	} else if ((mode & SPI_RX_DUAL) != 0U) {
		VERBOSE("rx: dual\n");
	} else {
		VERBOSE("rx: single\n");
	}

	if ((mode & SPI_TX_OCTAL) != 0U) {
		VERBOSE("tx: octal\n");
	} else if ((mode & SPI_TX_QUAD) != 0U) {
		VERBOSE("tx: quad\n");
	} else if ((mode & SPI_TX_DUAL) != 0U) {
		VERBOSE("tx: dual\n");
	} else {
		VERBOSE("tx: single\n");
	}
#endif

	return 0;
}

static int stm32_ospi_set_speed(const struct device *dev, unsigned int hz)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	struct clk *clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	unsigned long ospi_clk = clk_get_rate(clk);
	unsigned int bus_freq;
	uint32_t prescaler = UINT8_MAX;
	uint32_t csht;

	if (ospi_clk == 0U) {
		return -EINVAL;
	}

	if (hz > 0U) {
		prescaler = div_round_up(ospi_clk, hz) - 1U;
		if (prescaler > UINT8_MAX) {
			prescaler = UINT8_MAX;
		}
	}

	csht = div_round_up((5U * ospi_clk) / (prescaler + 1U), _FREQ_100MHZ);
	csht = ((csht - 1U) << _OSPI_DCR1_CSHT_SHIFT) & _OSPI_DCR1_CSHT;

	mmio_clrsetbits_32(drv_cfg->base + _OSPI_DCR2, _OSPI_DCR2_PRESCALER,
			   prescaler);

	mmio_clrsetbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_CSHT, csht);

	bus_freq = div_round_up(ospi_clk, prescaler + 1U);
	if (bus_freq <= _DLYB_FREQ_50MHZ) {
		mmio_setbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_DLYBYP);
	} else {
		mmio_clrbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_DLYBYP);
	}

	VERBOSE("%s: speed=%d\r\n", __func__, ospi_clk / (prescaler + 1U));

	return 0;
}

static int stm32_ospi_readid(const struct device *dev)
{
	struct stm32_ospi_data *drv_data = dev_get_data(dev);
	uint64_t id;
	struct spi_mem_op readid_op;
	int ret;

	memset(&readid_op, 0x0U, sizeof(struct spi_mem_op));
	readid_op.cmd.opcode = _OP_READ_ID;
	readid_op.cmd.buswidth = SPI_MEM_BUSWIDTH_1_LINE;
	readid_op.data.nbytes = _MAX_ID_LEN;
	readid_op.data.buf = &id;
	readid_op.data.buswidth = SPI_MEM_BUSWIDTH_1_LINE;

	ret = stm32_ospi_send(dev, &readid_op, _OSPI_CR_FMODE_INDR);
	if (ret != 0) {
		return ret;
	}

	VERBOSE("Flash ID 0x%x%x\n", (uint32_t)(id >> 32), (uint32_t)id);

	/* On stm32_ospi_readid() first execution, save the golden read id */
	if (drv_data->str_idcode == 0U) {
		drv_data->str_idcode = id;
	}

	if (id == drv_data->str_idcode) {
		return 0;
	}

	return -EIO;
}

static int stm32_ospi_dlyb_set_tap(const struct device *dev, uint8_t tap,
				   bool rx_tap)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint32_t mask, ack, sr;
	uint8_t shift;
	int ret;

	if (rx_tap) {
		mask = _DLYBOS_CR_RXTAPSEL;
		shift = _DLYBOS_CR_RXTAPSEL_SHIFT;
		ack = _DLYBOS_SR_RXTAPSEL_ACK;
	} else {
		mask = _DLYBOS_CR_TXTAPSEL;
		shift = _DLYBOS_CR_TXTAPSEL_SHIFT;
		ack = _DLYBOS_SR_TXTAPSEL_ACK;
	}

	syscon_clrsetbits(drv_cfg->dlyb_dev, drv_cfg->dlyb_base + _DLYBOS_CR,
			  mask, (tap << shift) & mask);

	ret = syscon_read_poll_timeout(drv_cfg->dlyb_dev,
				       drv_cfg->dlyb_base + _DLYBOS_SR,
				       sr, (sr & ack) != 0U,
				       _DLYBOS_TIMEOUT_US);
	if (ret != 0) {
		ERROR("%s: %s delay block phase configuration timeout\n",
		      __func__, rx_tap ? "RX" : "TX");
	}

	return ret;
}

static void stm32_ospi_dlyb_stop(const struct device *dev)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);

	syscon_write(drv_cfg->dlyb_dev, drv_cfg->dlyb_base + _DLYBOS_CR, 0x0U);
}

static int stm32_ospi_dlyb_find_tap(const struct device *dev, uint8_t *window_len)
{
	uint8_t rx_tap, rx_len, rx_window_len, rx_window_end;
	int ret;

	rx_len = 0U;
	rx_window_len = 0U;
	rx_window_end = 0U;

	ret = stm32_ospi_dlyb_set_tap(dev, 0U, false);
	if (ret != 0) {
		return ret;
	}

	for (rx_tap = 0U; rx_tap < _DLYBOS_TAPSEL_NB; rx_tap++) {
		ret = stm32_ospi_dlyb_set_tap(dev, rx_tap, true);
		if (ret != 0) {
			return ret;
		}

		ret = stm32_ospi_readid(dev);
		if (ret != 0) {
			if (ret == -ETIMEDOUT) {
				break;
			}

			rx_len = 0U;
		} else {
			rx_len++;

			if (rx_len > rx_window_len) {
				rx_window_len = rx_len;
				rx_window_end = rx_tap;
			}
		}
	}

	VERBOSE("%s: rx_window_end = %d rx_window_len = %d\r\n",
		__func__, rx_window_end, rx_window_len);

	if (rx_window_len == 0U) {
		WARN("%s: can't find RX phase settings\n", __func__);

		return -EIO;
	}

	rx_tap = rx_window_end - rx_window_len / 2U;
	VERBOSE("%s: RX_TAP_SEL set to %d\r\n", __func__, rx_tap);

	return stm32_ospi_dlyb_set_tap(dev, rx_tap, true);
}

static int stm32_ospi_dlyb_init(const struct device *dev)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint32_t sr;
	int ret;

	syscon_clrsetbits(drv_cfg->dlyb_dev, drv_cfg->dlyb_base + _DLYBOS_CR,
			  _DLYBOS_CR_EN, _DLYBOS_CR_EN);

	/* In lock mode, wait for lock status bit */
	ret = syscon_read_poll_timeout(drv_cfg->dlyb_dev,
				       drv_cfg->dlyb_base + _DLYBOS_SR,
				       sr, (sr & _DLYBOS_SR_LOCK) != 0U,
				       _DLYBOS_TIMEOUT_US);
	if (ret != 0) {
		ERROR("%s: delay Block lock timeout\n", __func__);
		syscon_clrbits(drv_cfg->dlyb_dev,
			       drv_cfg->dlyb_base + _DLYBOS_CR,
			       _DLYBOS_CR_EN);
	}

	return ret;
}

static int stm32_ospi_dlyb_set_cr(const struct device *dev, uint32_t dlyb_cr)
{
	uint8_t rx_tap;
	uint8_t tx_tap;
	int ret;

	ret = stm32_ospi_dlyb_init(dev);
	if (ret != 0) {
		return ret;
	}

	/* restore Rx and TX tap */
	rx_tap = (dlyb_cr & _DLYBOS_CR_RXTAPSEL) >> _DLYBOS_CR_RXTAPSEL_SHIFT;
	ret = stm32_ospi_dlyb_set_tap(dev, rx_tap, true);
	if (ret != 0) {
		return ret;
	}

	tx_tap = (dlyb_cr & _DLYBOS_CR_TXTAPSEL) >> _DLYBOS_CR_TXTAPSEL_SHIFT;

	return stm32_ospi_dlyb_set_tap(dev, tx_tap, false);
}

static void stm32_ospi_dlyb_get_cr(const struct device *dev, uint32_t *dlyb_cr)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);

	syscon_read(drv_cfg->dlyb_dev, drv_cfg->dlyb_base + _DLYBOS_CR,
		    dlyb_cr);
}

static int stm32_ospi_str_calibration(const struct device *dev,
				      unsigned int max_hz)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	struct clk *clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	uint32_t dlyb_cr;
	uint8_t window_len_tcr0 = 0U;
	uint8_t window_len_tcr1 = 0U;
	int ret;
	int ret_tcr0;
	int ret_tcr1;
	uint32_t prescaler;
	unsigned int bus_freq;

	/*
	 * Set memory device at low frequency (50 MHz) and sent
	 * READID (0x9F) command, save the answer as golden answer
	 */
	ret = stm32_ospi_set_speed(dev, _DLYB_FREQ_50MHZ);
	if (ret != 0) {
		return ret;
	}

	ret = stm32_ospi_readid(dev);
	if (ret != 0) {
		return ret;
	}

	/* Set frequency at requested value */
	ret = stm32_ospi_set_speed(dev, max_hz);
	if (ret != 0) {
		return ret;
	}

	/* Calculate real bus frequency */
	prescaler = mmio_read_32(drv_cfg->base + _OSPI_DCR2) &
		    _OSPI_DCR2_PRESCALER;
	bus_freq = div_round_up(clk_get_rate(clk), prescaler + 1U);

	/* Calibration needed above 50MHz */
	if (bus_freq <= _DLYB_FREQ_50MHZ) {
		return 0;
	}

	/* Perform calibration */
	ret = stm32_ospi_dlyb_init(dev);
	if (ret != 0) {
		return ret;
	}

	/* Perform only RX TAP selection */
	ret_tcr0 = stm32_ospi_dlyb_find_tap(dev, &window_len_tcr0);
	if (ret_tcr0 == 0) {
		stm32_ospi_dlyb_get_cr(dev, &dlyb_cr);
	}

	stm32_ospi_dlyb_stop(dev);

	ret = stm32_ospi_dlyb_init(dev);
	if (ret != 0) {
		return ret;
	}

	mmio_setbits_32(drv_cfg->base + _OSPI_TCR, _OSPI_TCR_SSHIFT);

	ret_tcr1 = stm32_ospi_dlyb_find_tap(dev, &window_len_tcr1);
	if ((ret_tcr0 != 0) && (ret_tcr1 != 0)) {
		WARN("Calibration phase failed\n");

		return ret_tcr0;
	}

	if (window_len_tcr0 >= window_len_tcr1) {
		mmio_clrbits_32(drv_cfg->base + _OSPI_TCR, _OSPI_TCR_SSHIFT);
		stm32_ospi_dlyb_stop(dev);

		ret = stm32_ospi_dlyb_set_cr(dev, dlyb_cr);
		if (ret != 0) {
			return ret;
		}
	}

	return 0;
}

static int stm32_ospi_exec_op(const struct device *dev,
			      const struct spi_mem_op *op)
{
	uint8_t fmode = _OSPI_CR_FMODE_INDW;

	if ((op->data.dir == SPI_MEM_DATA_IN) && (op->data.nbytes != 0U)) {
		fmode = _OSPI_CR_FMODE_INDR;
	}

	return stm32_ospi_send(dev, op, fmode);
}

static int stm32_ospi_dirmap_read(const struct device *dev,
				  const struct spi_mem_op *op)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	uint8_t fmode = _OSPI_CR_FMODE_INDR;
	size_t addr_max;

	addr_max = op->addr.val + op->data.nbytes + 1U;
	if ((addr_max < drv_cfg->mm_size) && (op->addr.buswidth != 0U)) {
		fmode = _OSPI_CR_FMODE_MM;
	}

	return stm32_ospi_send(dev, op, fmode);
}

static int stm32_ospi_claim_bus(const struct device *dev, unsigned int cs,
				unsigned int max_hz, unsigned int mode)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	struct stm32_ospi_data *drv_data = dev_get_data(dev);
	int ret;

	if (cs >= _OSPI_MAX_CHIP) {
		return -ENODEV;
	}

	mmio_setbits_32(drv_cfg->base + _OSPI_CR, _OSPI_CR_EN);

	if (drv_data->cs_used == cs) {
		return 0;
	}

	drv_data->cs_used = cs;
	drv_data->str_idcode = 0U;

	stm32_ospi_dlyb_stop(dev);

	/* Set chip select */
	mmio_clrsetbits_32(drv_cfg->base + _OSPI_CR, _OSPI_CR_CSSEL,
			   drv_data->cs_used ? _OSPI_CR_CSSEL : 0);
	mmio_clrbits_32(drv_cfg->base + _OSPI_TCR, _OSPI_TCR_SSHIFT);

	ret = stm32_ospi_set_mode(dev, mode);
	if (ret != 0) {
		return ret;
	}

	ret = stm32_ospi_str_calibration(dev, max_hz);
	if (ret != 0) {
		WARN("Set flash frequency to a safe value (%u Hz)\n",
		     _DLYB_FREQ_50MHZ);

		stm32_ospi_dlyb_stop(dev);
		mmio_clrbits_32(drv_cfg->base + _OSPI_TCR, _OSPI_TCR_SSHIFT);

		ret = stm32_ospi_set_speed(dev, _DLYB_FREQ_50MHZ);
	}

	return ret;
}

static void stm32_ospi_release_bus(const struct device *dev)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);

	mmio_clrbits_32(drv_cfg->base + _OSPI_CR, _OSPI_CR_EN);
}

static __unused int stm32_ospi_init(const struct device *dev)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	struct stm32_ospi_data *drv_data = dev_get_data(dev);
	struct clk *clk;
	int ret, i;

	clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (clk == NULL) {
		return -ENODEV;
	}

	ret = pinctrl_apply_state_optional(drv_cfg->pcfg,
					   PINCTRL_STATE_DEFAULT);
	if (ret != 0) {
		return ret;
	}

	ret = clk_enable(clk);
	if (ret != 0) {
		return ret;
	}

	for (i = 0; i < drv_cfg->n_rst; i++) {
		ret = reset_control_reset(&drv_cfg->rst_ctl[i]);
		if (ret != 0) {
			return ret;
		}
	}

	/* Set dcr devsize to max address */
	mmio_setbits_32(drv_cfg->base + _OSPI_DCR1, _OSPI_DCR1_DEVSIZE);
	drv_data->cs_used = -1;

	return 0;
}

#ifdef CONFIG_PM_DEVICE
static __unused int stm32_ospi_pm_action(const struct device *dev,
					 enum pm_device_action action,
					 uint32_t pm_hint)
{
	const struct stm32_ospi_config *drv_cfg = dev_get_config(dev);
	struct clk *clk;
	int ret;

	clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (clk == NULL) {
		return -ENODEV;
	}

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		clk_disable(clk);

		return pinctrl_apply_state_optional(drv_cfg->pcfg,
						    PINCTRL_STATE_SLEEP);
	}

	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT)) {
		ret = pinctrl_apply_state_optional(drv_cfg->pcfg,
						   PINCTRL_STATE_DEFAULT);
		if (ret != 0) {
			return ret;
		}

		return clk_enable(clk);
	}

	return stm32_ospi_init(dev);
}
#endif

static __maybe_unused const struct spi_bus_ops stm32_ospi_bus_ops = {
	.claim_bus = stm32_ospi_claim_bus,
	.release_bus = stm32_ospi_release_bus,
	.exec_op = stm32_ospi_exec_op,
	.dirmap_read = stm32_ospi_dirmap_read,
};

#define STM32_OSPI_INIT(n)							\
										\
PINCTRL_DT_INST_DEFINE(n);							\
										\
static const struct reset_control rst_ctrl_##n[] = DT_INST_RESETS_CONTROL(n);	\
										\
static const struct stm32_ospi_config stm32_ospi_cfg_##n = {			\
	.base = DT_INST_REG_ADDR(n),						\
	.mm_base = DT_INST_MEMORY_REGION_ADDR_OR(n, 0U),			\
	.mm_size = DT_INST_MEMORY_REGION_SIZE_OR(n, 0U),			\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),			\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),		\
	.rst_ctl = rst_ctrl_##n,						\
        .n_rst = DT_INST_NUM_RESETS(n),						\
	.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),				\
	.dlyb_dev = DEVICE_DT_GET(DT_INST_PHANDLE(n, st_syscfg_dlyb)),		\
	.dlyb_base = DT_INST_PHA_BY_IDX(n, st_syscfg_dlyb, 0, offset),		\
};										\
										\
static struct stm32_ospi_data stm32_ospi_data_##n = {};				\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_ospi_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_INST_DEFINE(n,							\
		      &stm32_ospi_init,						\
		      PM_DEVICE_DT_INST_GET(n),					\
		      &stm32_ospi_data_##n, &stm32_ospi_cfg_##n,		\
		      CORE, 12,							\
		      &stm32_ospi_bus_ops);

DT_INST_FOREACH_STATUS_OKAY(STM32_OSPI_INIT)
