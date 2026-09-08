/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stdlib.h>
#include <stdio.h>

#include <stm32mp_ddr_debug.h>

#include <ddrphy_phyinit.h>

/*
 * This function loads the training firmware DMEM image and write the
 * Message Block parameters for the training firmware into the PHY.
 *
 * This function performs the following tasks:
 *
 * -# Load the firmware DMEM segment to initialize the data structures from the
 * DDR firmware source memory area.
 * -# Write the Firmware Message Block with the required contents detailing the training parameters.
 *
 * \return 0 on success.
 */
int ddrphy_phyinit_f_loaddmem(const struct stm32mp_ddr_config *config,
			      struct pmu_smb_ddr_1d *mb_ddr_1d)
{
	uint32_t sizeofmsgblk;
	uint16_t *ptr16;
	uint32_t *ptr32;

	DDR_VERBOSE("%s Start\n", __func__);

	/* Some basic checks on MessageBlock */
#if STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE
	if ((mb_ddr_1d->enableddqs > (8U * (uint8_t)config->uib.numactivedbytedfi0)) ||
	    (mb_ddr_1d->enableddqs <= 0U)) {
		DDR_ERROR("%s enableddqs is Zero or greater than NumActiveDbytes for Dfi0\n",__func__);
		return -1;
	}
#else /* STM32MP_LPDDR4_TYPE */
	if (((mb_ddr_1d->enableddqscha % 16U) != 0U) || ((mb_ddr_1d->enableddqschb % 16U) != 0U)) {
		DDR_ERROR("%s Lp3/Lp4 - Number of Dq's Enabled per Channel much be multipe of 16\n",
		      __func__);
		return -1;
	}

	if ((mb_ddr_1d->enableddqscha > (uint8_t)(8U * config->uib.numactivedbytedfi0)) ||
	    (mb_ddr_1d->enableddqschb > (uint8_t)(8U * config->uib.numactivedbytedfi1)) ||
	    ((mb_ddr_1d->enableddqscha == 0U) && (mb_ddr_1d->enableddqschb == 0U))) {
		DDR_ERROR("%s EnabledDqsChA/B are not set correctly./1\n", __func__);
		return -1;
	}
#endif /* STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE */

	sizeofmsgblk = sizeof(struct pmu_smb_ddr_1d);

	ptr16 = (uint16_t *)mb_ddr_1d;
	ddrphy_phyinit_writeoutmsgblk(ptr16, DMEM_ST_ADDR, sizeofmsgblk);

	ptr32 = (uint32_t *)(STM32MP_DDR_FW_BASE + STM32MP_DDR_FW_DMEM_OFFSET);
	ddrphy_phyinit_writeoutmem(ptr32, DMEM_ST_ADDR + DMEM_BIN_OFFSET,
				   DMEM_SIZE - STM32MP_DDR_FW_DMEM_OFFSET);

	DDR_VERBOSE("%s End\n", __func__);

	return 0;
}
