/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stdio.h>
#include <stdlib.h>

#include <stm32mp_ddr_debug.h>
#include <lib/mmio.h>

#include <ddrphy_phyinit.h>

/* DDRDBG registers */
#define DDRDBG_DDR34_AC_SWIZZLE_ADD3_0		U(0x100)

/*
 * This function is called before training firmware is executed. Any
 * register override in this function might affect the firmware training
 * results.
 *
 * This function is executed before firmware execution loop. Thus this function
 * should be used only for the following:
 *
 *  - Override PHY register values written by
 *  ddrphy_phyinit_c_initphyconfig. An example use case is when this
 *  function does not perform the exact programing desired by the user.
 *  - Write custom PHY registers that need to take effect before training
 *  firmware execution.
 *
 * User shall use mmio_write_16 to write PHY registers in order for the register
 * to be tracked by PhyInit for retention restore.
 *
 * To override settings in the message block, users can assign values to the
 * fields in the message block data structure directly.
 *
 * \ref examples/simple/ddrphy_phyinit_usercustom_custompretrain.c example of this function.
 *
 * @return Void
 */
void ddrphy_phyinit_usercustom_custompretrain(const struct stm32mp_ddr_config *config)
{
	uint32_t byte __unused;
	uint32_t i = 0U;
	uint32_t j;
	uintptr_t base;
	int swizzle_array[NB_SWIZZLE] = {
		config->uis.swizzle_0 , config->uis.swizzle_1 , config->uis.swizzle_2 ,
		config->uis.swizzle_3 , config->uis.swizzle_4 , config->uis.swizzle_5 ,
		config->uis.swizzle_6 , config->uis.swizzle_7 , config->uis.swizzle_8 ,
		config->uis.swizzle_9 , config->uis.swizzle_10, config->uis.swizzle_11,
		config->uis.swizzle_12, config->uis.swizzle_13, config->uis.swizzle_14,
		config->uis.swizzle_15, config->uis.swizzle_16, config->uis.swizzle_17,
		config->uis.swizzle_18, config->uis.swizzle_19, config->uis.swizzle_20,
		config->uis.swizzle_21, config->uis.swizzle_22, config->uis.swizzle_23,
		config->uis.swizzle_24, config->uis.swizzle_25, config->uis.swizzle_26,
		config->uis.swizzle_27, config->uis.swizzle_28, config->uis.swizzle_29,
		config->uis.swizzle_30, config->uis.swizzle_31, config->uis.swizzle_32,
		config->uis.swizzle_33, config->uis.swizzle_34, config->uis.swizzle_35,
		config->uis.swizzle_36, config->uis.swizzle_37, config->uis.swizzle_38,
		config->uis.swizzle_39, config->uis.swizzle_40, config->uis.swizzle_41,
		config->uis.swizzle_42, config->uis.swizzle_43 };

	DDR_VERBOSE("%s Start\n", __func__);

#if STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE
	base = (uintptr_t)(DDRPHYC_BASE + (4U * (TMASTER | CSR_HWTSWIZZLEHWTADDRESS0_ADDR)));

	for (i = 0U; i < NB_HWT_SWIZZLE; i++) {
		mmio_write_16(base + (i * sizeof(uint32_t)),
			      (uint16_t)swizzle_array[i]);
	}

	base = (uintptr_t)(stm32_ddrdbg_get_base() + DDRDBG_DDR34_AC_SWIZZLE_ADD3_0);

	for (j = 0U; j < NB_AC_SWIZZLE; j++, i++) {
		mmio_write_32(base + (j * sizeof(uint32_t)), swizzle_array[i]);
	}
#else /* STM32MP_LPDDR4_TYPE */
	for (byte = 0U; byte < config->uib.numdbyte; byte++) {
		base = (uintptr_t)(DDRPHYC_BASE + (4U *
						   ((byte << 12) | TDBYTE | CSR_DQ0LNSEL_ADDR)));

		for (j = 0U; j < NB_DQLNSEL_SWIZZLE_PER_BYTE; j++, i++) {
			mmio_write_16(base + (j * sizeof(uint32_t)),
				      (uint16_t)swizzle_array[i]);
		}
	}

	base = (uintptr_t)(DDRPHYC_BASE + (4U * (TMASTER | CSR_MAPCAA0TODFI_ADDR)));

	for (j = 0U; j < NB_MAPCAATODFI_SWIZZLE; j++, i++) {
		mmio_write_16(base + (j * sizeof(uint32_t)),
			      (uint16_t)swizzle_array[i]);
	}

	base = (uintptr_t)(DDRPHYC_BASE + (4U * (TMASTER | CSR_MAPCAB0TODFI_ADDR)));

	for (j = 0U; j < NB_MAPCABTODFI_SWIZZLE; j++, i++) {
		mmio_write_16(base + (j * sizeof(uint32_t)),
			      (uint16_t)swizzle_array[i]);
	}
#endif /* STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE */

	DDR_VERBOSE("%s End\n", __func__);
}
