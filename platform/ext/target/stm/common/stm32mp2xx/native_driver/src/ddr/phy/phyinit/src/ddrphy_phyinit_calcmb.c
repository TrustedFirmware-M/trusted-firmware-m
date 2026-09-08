/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stdlib.h>

#include <stm32mp_ddr_debug.h>

#include <ddrphy_phyinit.h>

/*
 * Reads PhyInit inputs structures and sets relevant message block
 * parameters.
 *
 * This function sets Message Block parameters based on user_input_basic and
 * user_input_advanced. user changes in these files takes precedence
 * over this function call.
 *
 * MessageBlock fields set :
 *  - dramtype
 *  - pstate
 *  - dramfreq
 *  - pllbypassen
 *  - dfifreqratio
 *  - phyodtimpedance
 *  - phydrvimpedance
 *  - bpznresval
 *  - enableddqscha (LPDDR4)
 *  - cspresentcha (LPDDR4)
 *  - enableddqsChb (LPDDR4)
 *  - cspresentchb (LPDDR4)
 *  - enableddqs (DDR3/DDR4)
 *  - phycfg (DDR3/DDR4)
 *  - x16present (DDR4)
 *
 * \return 0 on success.
 */
int ddrphy_phyinit_calcmb(const struct stm32mp_ddr_config *config,
			  struct pmu_smb_ddr_1d *mb_ddr_1d)
{
	uint32_t nad0 = config->uib.numactivedbytedfi0;
	uint32_t nad1 = 0;
	uint16_t mr4 __unused;
	uint16_t disableddbyte __unused;
	uint32_t dbyte __unused;
	int ret;

	DDR_VERBOSE("%s Start\n", __func__);

#if STM32MP_LPDDR4_TYPE
	nad1 = config->uib.numactivedbytedfi1;
#endif /* STM32MP_LPDDR4_TYPE */

	/* A few checks to make sure valid programming */
	if ((nad0 == 0U) || (config->uib.numdbyte == 0U)) {
		DDR_ERROR("%s numactivedbytedfi0 or numdbyte out of range.\n",
		      __func__);
		return -1;
	}

	if ((nad0 + nad1) > config->uib.numdbyte) {
		DDR_ERROR("%s numactivedbytedfi0+numactivedbytedfi1 is larger than numdbyte\n",
		      __func__);
		return -1;
	}

	if ((config->uib.dfi1exists == 0U) && (nad1 != 0U)) {
		DDR_ERROR("%s dfi1exists==0 but numdbytedfi1 != 0\n", __func__);
		return -1;
	}

#if STM32MP_DDR4_TYPE
	/* OR all mr4 masked values, to help check in next loop */
	mr4 = mb_ddr_1d->mr4 & 0x1C0U;

	/* 1D message block defaults */
	if (mr4 != 0x0U) {
		DDR_ERROR("mr4 != 0x0\n");
		DDR_VERBOSE("%s Setting DRAM CAL mode is not supported by the PHY.\n", __func__);
		DDR_VERBOSE("Memory controller may set CAL mode after PHY has entered mission\n");
		DDR_VERBOSE("mode. Please check value programmed in mb_ddr_1d[*].mr4\n");
		DDR_VERBOSE("and unset A8:6\n");
		return -1;
	}
#endif /* STM32MP_DDR4_TYPE */

#if STM32MP_DDR3_TYPE
	if (config->uib.dimmtype == DDR_DIMMTYPE_NODIMM) {
		ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_DRAMTYPE, 0x1U);
		if (ret != 0) {
			return ret;
		}
	}
#elif STM32MP_DDR4_TYPE
	if (config->uib.dimmtype == DDR_DIMMTYPE_NODIMM) {
		ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_DRAMTYPE, 0x2U);
		if (ret != 0) {
			return ret;
		}
	}
#else /* STM32MP_LPDDR4_TYPE */
	/* Nothing to do */
#endif /* STM32MP_DDR3_TYPE */

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PSTATE, 0U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_DRAMFREQ, config->uib.frequency * 2U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PLLBYPASSEN, config->uib.pllbypass);
	if (ret != 0) {
		return ret;
	}

	if (config->uib.dfifreqratio == 1U) {
		ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_DFIFREQRATIO, 0x2U);
		if (ret != 0) {
			return ret;
		}
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PHYODTIMPEDANCE, 0U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PHYDRVIMPEDANCE, 0U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_BPZNRESVAL, 0U);
	if (ret != 0) {
		return ret;
	}

#if STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE
	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_ENABLEDDQS, nad0 * 8U);
	if (ret != 0) {
		return ret;
	}

	disableddbyte = 0x0U;

	for (dbyte = 0U; (dbyte < config->uib.numdbyte) && (dbyte < 8U); dbyte++) {
		if (ddrphy_phyinit_isdbytedisabled(config, mb_ddr_1d, dbyte) != 0) {
			disableddbyte |= 0x1U << dbyte;
		}
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_DISABLEDDBYTE, disableddbyte);
	if (ret != 0) {
		return ret;
	}

#if STM32MP_DDR3_TYPE
	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PHYCFG, config->uia.is2ttiming);
	if (ret != 0) {
		return ret;
	}
#else /* STM32MP_DDR4_TYPE */
	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_PHYCFG,
				       ((mb_ddr_1d->mr3 & 0x8U) != 0U) ?
				       0U : config->uia.is2ttiming);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_X16PRESENT,
				       (0x10U == config->uib.dramdatawidth) ?
				       mb_ddr_1d->cspresent : 0x0U);
	if (ret != 0) {
		return ret;
	}
#endif /* STM32MP_DDR3_TYPE */
#else /* STM32MP_LPDDR4_TYPE */
	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_ENABLEDDQSCHA, nad0 * 8U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_CSPRESENTCHA,
				       (2U == config->uib.numrank_dfi0) ?
				       0x3U : config->uib.numrank_dfi0);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_ENABLEDDQSCHB, nad1 * 8U);
	if (ret != 0) {
		return ret;
	}

	ret = ddrphy_phyinit_softsetmb(mb_ddr_1d, MB_FIELD_CSPRESENTCHB,
				       (2U == config->uib.numrank_dfi1) ?
				       0x3U : config->uib.numrank_dfi1);
	if (ret != 0) {
		return ret;
	}
#endif /* STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE */

	DDR_VERBOSE("%s End\n", __func__);

	return 0;
}
