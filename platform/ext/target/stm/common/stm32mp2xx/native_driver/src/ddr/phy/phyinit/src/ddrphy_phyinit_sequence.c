/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stm32mp_ddr_debug.h>

#include <ddrphy_phyinit.h>

/*
 * This function implements the flow of PhyInit software to initialize the PHY.
 *
 * The execution sequence follows the overview figure provided in the Reference Manual.
 *
 * \returns 0 on completion of the sequence, EXIT_FAILURE on error.
 */
int ddrphy_phyinit_sequence(const struct stm32mp_ddr_config *config)
{
	int ret;
	struct pmu_smb_ddr_1d mb_ddr_1d; /* Firmware 1D Message Block structure */

	/* Check user input pstate number consistency vs. SW capabilities */
	if (config->uib.numpstates > 1U) {
		return -1;
	}

	DDR_VERBOSE("%s Start\n", __func__);

	/* Initialize structures */
	ddrphy_phyinit_initstruct(config, &mb_ddr_1d);

	/* Re-calculate Firmware Message Block input based on final user input */
	ret = ddrphy_phyinit_calcmb(config, &mb_ddr_1d);
	if (ret != 0) {
		return ret;
	}

	/* (C) Initialize PHY Configuration */
	ret = ddrphy_phyinit_c_initphyconfig(config, &mb_ddr_1d);
	if (ret != 0) {
		return ret;
	}
	/*
	 * Customize any register write desired; This can include any CSR not covered by PhyInit
	 * or user wish to override values calculated in step_C.
	 */
	ddrphy_phyinit_usercustom_custompretrain(config);

	/* (D) Load the IMEM Memory for 1D training */
	ddrphy_phyinit_d_loadimem();

	/* (F) Write the Message Block parameters for the training firmware */
	ret = ddrphy_phyinit_f_loaddmem(config, &mb_ddr_1d);
	if (ret != 0) {
		return ret;
	}

	/* (G) Execute the Training Firmware */
	ret = ddrphy_phyinit_g_execfw();
	if (ret != 0) {
		return ret;
	}

	/* (I) Load PHY Init Engine Image */
	ddrphy_phyinit_i_loadpieimage(config);

	DDR_VERBOSE("%s End\n", __func__);

	return 0;
}
