/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <cmsis.h>
#include <debug.h>
#include <device.h>

#include <lib/mmiopoll.h>
#include <lib/utils_def.h>

#include <stm32mp2_ramcfg.h>

/* Offset in each block of regisotr for internal SRAM */
#define _RAMCFG_CR			U(0x00)
#define _RAMCFG_IER			U(0x04)
#define _RAMCFG_ISR			U(0x08)
#define _RAMCFG_SEAR			U(0x0C)
#define _RAMCFG_DEAR			U(0x10)
#define _RAMCFG_ICR			U(0x14)
#define _RAMCFG_ECCKEY			U(0x24)
#define _RAMCFG_ERKEYR			U(0x28)
#define _RAMCFG_CCR1			U(0x30)
#define _RAMCFG_CCR2			U(0x34)
#define _RAMCFG_CRSR			U(0x38)
#define _RAMCFG_CSR			U(0x3C)
#define _RAMCFG_CCSR			U(0x40)

#define _RAMCFG_CR_SRAMHWERDIS		BIT(12)
#define _RAMCFG_CR_ALE			BIT(4)
#define _RAMCFG_CR_ECCE			BIT(0)

#define _RAMCFG_ISR_DED			BIT(1)
#define _RAMCFG_ISR_SEC			BIT(0)

#define _RAMCFG_ICR_DED			BIT(1)
#define _RAMCFG_ICR_SEC			BIT(0)

#define _RAMCFG_CCR1_CRCBS_SHIFT	U(4)
#define _RAMCFG_CCR1_CRCBS_MASK		GENMASK_32(6, 4)
#define _RAMCFG_CCR1_CRCC_MASK		GENMASK_32(1, 0)

#define _RAMCFG_CCR1_CRCC_DISA		U(0)
#define _RAMCFG_CCR1_CRCC_ENA		U(1)
#define _RAMCFG_CCR1_CRCC_CHECK		U(2)

#define _RAMCFG_CCR2_CRCFC		BIT(31)
#define _RAMCFG_CCR2_CRCCS		BIT(0)

#define _RAMCFG_ECCKEY_UNLOCK_1		U(0xAE)
#define _RAMCFG_ECCKEY_UNLOCK_2		U(0x75)

/* Timeout when polling on CRC status */
#define _RAMCFG_CRC_TIMEOUT_US		1000

/* Definition of each internal SRAM */
struct stm32_ramcfg_config {
	uint32_t base;
	bool has_ecc;
	bool has_crc;
	size_t crc_blk_sz;
};

/*
 * The CRC computation is calculation follow:
 * nb <crc_blk_sz> starting from internal SRAM start address
 */
int stm32_ramcfg_crc_compute(const struct device *dev, size_t buf_size)
{
	const struct stm32_ramcfg_config *drv_cfg = dev_get_config(dev);
	const uint32_t base = drv_cfg->base;
	uint32_t crcbs;
	uint32_t csr;
	int ret;

	if (!drv_cfg->has_crc || !drv_cfg->crc_blk_sz)
		return -ENOTSUP;

	crcbs = div_round_up(buf_size, drv_cfg->crc_blk_sz) - 1;

	/* Deactivate the CRC */
	mmio_write_32(base + _RAMCFG_CCR1, 0);

	/* Select the buffer size for the CRC computation */
	mmio_write_32(base + _RAMCFG_CCR1,
		      _FLD_PREP(_RAMCFG_CCR1_CRCBS, crcbs));

	/* Enable the CRC */
	mmio_clrsetbits_32(base + _RAMCFG_CCR1, _RAMCFG_CCR1_CRCC_MASK,
			   _RAMCFG_CCR1_CRCC_ENA);

	/* Start the CRC computation */
	mmio_setbits_32(base + _RAMCFG_CCR2, _RAMCFG_CCR2_CRCCS);

	/* Wait CRC computation is OK */
	ret = mmio_read32_poll_timeout(base + _RAMCFG_CSR,
				       csr, csr & RAMCFG_CSR_CRCEOC,
				       _RAMCFG_CRC_TIMEOUT_US);

	if (ret) {
		EMSG("[%s] Timeout (%d)\n", dev->name, ret);
		goto end;
	}

	/* Clear the CRC status */
	mmio_setbits_32(base + _RAMCFG_CCR2, _RAMCFG_CCR2_CRCFC);

	/* Save calculated signature in reference signature */
	mmio_write_32(base + _RAMCFG_CRSR, mmio_read_32(base + _RAMCFG_CCSR));

	/* Disable RETRAM erase on system reset/Standby exit */
	mmio_setbits_32(drv_cfg->base + _RAMCFG_CR, _RAMCFG_CR_SRAMHWERDIS);

end:
	/* Deactivate the CRC */
	mmio_clrsetbits_32(base + _RAMCFG_CCR1, _RAMCFG_CCR1_CRCC_MASK,
			   _RAMCFG_CCR1_CRCC_DISA);
	return ret;
}

void stm32_ramcfg_crc_enable(const struct device *dev)
{
	const struct stm32_ramcfg_config *drv_cfg = dev_get_config(dev);
	const uint32_t base = drv_cfg->base;

	if (!drv_cfg->has_crc)
		return;

	/* Enable CRC */
	mmio_clrsetbits_32(base + _RAMCFG_CCR1, _RAMCFG_CCR1_CRCC_MASK,
			   _RAMCFG_CCR1_CRCC_CHECK);
}

void stm32_ramcfg_crc_disable(const struct device *dev)
{
	const struct stm32_ramcfg_config *drv_cfg = dev_get_config(dev);
	const uint32_t base = drv_cfg->base;

	if (!drv_cfg->has_crc)
		return;

	/* Disable CRC  */
	mmio_clrsetbits_32(base + _RAMCFG_CCR1, _RAMCFG_CCR1_CRCC_MASK,
			   _RAMCFG_CCR1_CRCC_DISA);
}

static void stm32_ramcfg_ecc_enable(const struct device *dev)
{
	const struct stm32_ramcfg_config *drv_cfg = dev_get_config(dev);
	const uint32_t base = drv_cfg->base;
	const uint32_t ecckey = base + _RAMCFG_ECCKEY;
	const uint32_t cr = base + _RAMCFG_CR;
	const uint32_t isr = base + _RAMCFG_ISR;
	const uint32_t icr = base + _RAMCFG_ICR;

	if (!drv_cfg->has_ecc)
		return;

	/* Clear pending ECC error in ISR register */
	if (mmio_read_32(isr) & (_RAMCFG_ISR_DED | _RAMCFG_ISR_SEC)) {
		IMSG("[%s] Clear ECC flag in ISR=%x [0x%x]\n",
		     dev->name, mmio_read_32(isr), isr);
		mmio_write_32(icr, _RAMCFG_ICR_DED | _RAMCFG_ICR_SEC);
	}

	/* Enable ECC if not yet done */
	if ((mmio_read_32(cr) & _RAMCFG_CR_ECCE) == 0) {
		mmio_write_32(ecckey, _RAMCFG_ECCKEY_UNLOCK_1);
		mmio_write_32(ecckey, _RAMCFG_ECCKEY_UNLOCK_2);
		mmio_setbits_32(cr, _RAMCFG_CR_ECCE | _RAMCFG_CR_ALE);
		mmio_write_32(ecckey, U(0));
	}
}

static int __unused stm32_ramcfg_init(const struct device *dev)
{
	const struct stm32_ramcfg_config *drv_cfg = dev_get_config(dev);

	/* Enable hardware erase for SRAM on system reset */
	mmio_clrbits_32(drv_cfg->base + _RAMCFG_CR, _RAMCFG_CR_SRAMHWERDIS);

	/* Enable ECC when supported */
	stm32_ramcfg_ecc_enable(dev);

	return 0;
}

#define RAMCFG_DEFINE(_node_id, _id, _ecc, _crc, _crc_blk_sz)			\
static const struct stm32_ramcfg_config stm32_cfg_ ## _id = {			\
	.base = DT_REG_ADDR(_node_id),						\
	.has_ecc = _ecc,							\
	.has_crc = _crc,							\
	.crc_blk_sz = _crc_blk_sz,						\
};										\
										\
DEVICE_DT_DEFINE(_node_id, &stm32_ramcfg_init, NULL,				\
		 NULL, &stm32_cfg_ ## _id,					\
		 CORE, 7, NULL);

#define RAMCFG_DEFINE_COND(inst, child, _ecc, _crc, _crc_blk_sz)		\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(ramcfg_ ## child)),	\
		(RAMCFG_DEFINE(DT_NODELABEL(ramcfg_ ## child),			\
		inst ## _ ## child, _ecc, _crc, _crc_blk_sz)),			\
		())

#define STM32MP21_RAMCFG_ALL(inst)						\
	RAMCFG_DEFINE_COND(inst, sysram, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, retram, true, true, RETRAM_BUF_SZ)		\
	RAMCFG_DEFINE_COND(inst, bkpsram, true, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, sram1, false, false, 0U)

#define STM32MP25_RAMCFG_ALL(inst)						\
	RAMCFG_DEFINE_COND(inst, sysram, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, retram, true, true, RETRAM_BUF_SZ)		\
	RAMCFG_DEFINE_COND(inst, bkpsram, true, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, sram1, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, sram2, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, lpsram1, false, true, LPSRAM1_BUF_SZ)		\
	RAMCFG_DEFINE_COND(inst, lpsram2, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, lpsram3, false, false, 0U)			\
	RAMCFG_DEFINE_COND(inst, vderam, false, false, 0U)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_ramcfg
DT_INST_FOREACH_STATUS_OKAY(STM32MP21_RAMCFG_ALL)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp25_ramcfg
DT_INST_FOREACH_STATUS_OKAY(STM32MP25_RAMCFG_ALL)

