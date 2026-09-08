/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <string.h>

#include <debug.h>
#include <device.h>
#include <lib/utils_def.h>
#include <stm_version.h>
#include <tfm_plat_otp.h>

/* Necessary to detect cold boot case */
#include <cmsis.h>

#define STM32_SOC_NAME_SIZE		24

#define STM32MP211A_PART_NB		U(0x40073E7D)
#define STM32MP211C_PART_NB		U(0x0007307D)
#define STM32MP211D_PART_NB		U(0xC0073E7D)
#define STM32MP211F_PART_NB		U(0x8007307D)
#define STM32MP213A_PART_NB		U(0x40073E1D)
#define STM32MP213C_PART_NB		U(0x0007301D)
#define STM32MP213D_PART_NB		U(0xC0073E1D)
#define STM32MP213F_PART_NB		U(0x8007301D)
#define STM32MP215A_PART_NB		U(0x40033E0D)
#define STM32MP215C_PART_NB		U(0x0003300D)
#define STM32MP215D_PART_NB		U(0xC0033E0D)
#define STM32MP215F_PART_NB		U(0x8003300D)

#define STM32MP231A_PART_NB		U(0x400B3FEF)
#define STM32MP231C_PART_NB		U(0x000B31EF)
#define STM32MP231D_PART_NB		U(0xC00B3FEF)
#define STM32MP231F_PART_NB		U(0x800B31EF)
#define STM32MP233A_PART_NB		U(0x400B3F8E)
#define STM32MP233C_PART_NB		U(0x000B318E)
#define STM32MP233D_PART_NB		U(0xC00B3F8E)
#define STM32MP233F_PART_NB		U(0x800B318E)
#define STM32MP235A_PART_NB		U(0x40082F82)
#define STM32MP235C_PART_NB		U(0x00082182)
#define STM32MP235D_PART_NB		U(0xC0082F82)
#define STM32MP235F_PART_NB		U(0x80082182)

#define STM32MP251A_PART_NB		U(0x400B3E6D)
#define STM32MP251C_PART_NB		U(0x000B306D)
#define STM32MP251D_PART_NB		U(0xC00B3E6D)
#define STM32MP251F_PART_NB		U(0x800B306D)
#define STM32MP253A_PART_NB		U(0x400B3E0C)
#define STM32MP253C_PART_NB		U(0x000B300C)
#define STM32MP253D_PART_NB		U(0xC00B3E0C)
#define STM32MP253F_PART_NB		U(0x800B300C)
#define STM32MP255A_PART_NB		U(0x40082E00)
#define STM32MP255C_PART_NB		U(0x00082000)
#define STM32MP255D_PART_NB		U(0xC0082E00)
#define STM32MP255F_PART_NB		U(0x80082000)
#define STM32MP257A_PART_NB		U(0x40002E00)
#define STM32MP257C_PART_NB		U(0x00002000)
#define STM32MP257D_PART_NB		U(0xC0002E00)
#define STM32MP257F_PART_NB		U(0x80002000)

#define STM32MP2_REV_A			U(0x08)
#define STM32MP2_REV_B			U(0x10)
#define STM32MP2_REV_X			U(0x12)
#define STM32MP2_REV_Y			U(0x11)
#define STM32MP2_REV_Z			U(0x09)

#if defined(STM32MP21xxxx)
#define STM32MP21_PKG_CUSTOM		U(0)
#define STM32MP21_PKG_AL_VFBGA361	U(1)
#define STM32MP21_PKG_AN_VFBGA273	U(3)
#define STM32MP21_PKG_AO_VFBGA225	U(4)
#define STM32MP21_PKG_AM_TFBGA289	U(5)
#elif defined(STM32MP23xxxx)
#define STM32MP23_PKG_CUSTOM		U(0)
#define STM32MP23_PKG_AL_VFBGA361	U(1)
#define STM32MP23_PKG_AK_VFBGA424	U(3)
#define STM32MP23_PKG_AJ_TFBGA361	U(7)
#else /* STM32MP25xxxx */
#define STM32MP25_PKG_CUSTOM		U(0)
#define STM32MP25_PKG_AL_VFBGA361	U(1)
#define STM32MP25_PKG_AK_VFBGA424	U(3)
#define STM32MP25_PKG_AI_TFBGA436	U(5)
#endif /* STM32MP21xxxx */

extern uint32_t SystemCoreClock;

static enum tfm_plat_err_t get_chip_info(char name[STM32_SOC_NAME_SIZE])
{
	char *cpu_s, *cpu_r, *pkg;
	enum tfm_plat_err_t ret;
	uint32_t otp_val;

	memset(name, 0, STM32_SOC_NAME_SIZE);

	/* MPUs Part Numbers */
	ret = tfm_plat_otp_read(PLAT_OTP_ID_RPN,
				sizeof(uint32_t), (uint8_t *)&otp_val);
	if (ret != TFM_PLAT_ERR_SUCCESS)
		return ret;

	switch (otp_val) {
#if defined(STM32MP21xxxx)
	case STM32MP211A_PART_NB:
		cpu_s = "211A";
		break;
	case STM32MP211C_PART_NB:
		cpu_s = "211C";
		break;
	case STM32MP211D_PART_NB:
		cpu_s = "211D";
		break;
	case STM32MP211F_PART_NB:
		cpu_s = "211F";
		break;
	case STM32MP213A_PART_NB:
		cpu_s = "213A";
		break;
	case STM32MP213C_PART_NB:
		cpu_s = "213C";
		break;
	case STM32MP213D_PART_NB:
		cpu_s = "213D";
		break;
	case STM32MP213F_PART_NB:
		cpu_s = "213F";
		break;
	case STM32MP215A_PART_NB:
		cpu_s = "215A";
		break;
	case STM32MP215C_PART_NB:
		cpu_s = "215C";
		break;
	case STM32MP215D_PART_NB:
		cpu_s = "215D";
		break;
	case STM32MP215F_PART_NB:
		cpu_s = "215F";
		break;
#elif defined(STM32MP23xxxx)
	case STM32MP231A_PART_NB:
		cpu_s = "231A";
		break;
	case STM32MP231C_PART_NB:
		cpu_s = "231C";
		break;
	case STM32MP231D_PART_NB:
		cpu_s = "231D";
		break;
	case STM32MP231F_PART_NB:
		cpu_s = "231F";
		break;
	case STM32MP233A_PART_NB:
		cpu_s = "233A";
		break;
	case STM32MP233C_PART_NB:
		cpu_s = "233C";
		break;
	case STM32MP233D_PART_NB:
		cpu_s = "233D";
		break;
	case STM32MP233F_PART_NB:
		cpu_s = "233F";
		break;
	case STM32MP235A_PART_NB:
		cpu_s = "235A";
		break;
	case STM32MP235C_PART_NB:
		cpu_s = "235C";
		break;
	case STM32MP235D_PART_NB:
		cpu_s = "235D";
		break;
	case STM32MP235F_PART_NB:
		cpu_s = "235F";
		break;
#else /* STM32MP25xxxx */
	case STM32MP251A_PART_NB:
		cpu_s = "251A";
		break;
	case STM32MP251C_PART_NB:
		cpu_s = "251C";
		break;
	case STM32MP251D_PART_NB:
		cpu_s = "251D";
		break;
	case STM32MP251F_PART_NB:
		cpu_s = "251F";
		break;
	case STM32MP253A_PART_NB:
		cpu_s = "253A";
		break;
	case STM32MP253C_PART_NB:
		cpu_s = "253C";
		break;
	case STM32MP253D_PART_NB:
		cpu_s = "253D";
		break;
	case STM32MP253F_PART_NB:
		cpu_s = "253F";
		break;
	case STM32MP255A_PART_NB:
		cpu_s = "255A";
		break;
	case STM32MP255C_PART_NB:
		cpu_s = "255C";
		break;
	case STM32MP255D_PART_NB:
		cpu_s = "255D";
		break;
	case STM32MP255F_PART_NB:
		cpu_s = "255F";
		break;
	case STM32MP257A_PART_NB:
		cpu_s = "257A";
		break;
	case STM32MP257C_PART_NB:
		cpu_s = "257C";
		break;
	case STM32MP257D_PART_NB:
		cpu_s = "257D";
		break;
	case STM32MP257F_PART_NB:
		cpu_s = "257F";
		break;
#endif /* STM32MP21xxxx */
	default:
		cpu_s = "????";
		break;
	}

	/* Package */
	ret = tfm_plat_otp_read(PLAT_OTP_ID_PACKAGE,
				sizeof(uint32_t), (uint8_t *)&otp_val);
	if (ret != TFM_PLAT_ERR_SUCCESS)
		return ret;

	switch (otp_val & GENMASK(2, 0)) {
#if defined(STM32MP21xxxx)
	case STM32MP21_PKG_CUSTOM:
		pkg = "XX";
		break;
	case STM32MP21_PKG_AL_VFBGA361:
		pkg = "AL";
		break;
	case STM32MP21_PKG_AN_VFBGA273:
		pkg = "AN";
		break;
	case STM32MP21_PKG_AO_VFBGA225:
		pkg = "AO";
		break;
	case STM32MP21_PKG_AM_TFBGA289:
		pkg = "AM";
		break;
#elif defined(STM32MP23xxxx)
	case STM32MP23_PKG_CUSTOM:
		pkg = "XX";
		break;
	case STM32MP23_PKG_AJ_TFBGA361:
		pkg = "AJ";
		break;
	case STM32MP23_PKG_AK_VFBGA424:
		pkg = "AK";
		break;
	case STM32MP23_PKG_AL_VFBGA361:
		pkg = "AL";
		break;
#else /* STM32MP25xxxx */
	case STM32MP25_PKG_CUSTOM:
		pkg = "XX";
		break;
	case STM32MP25_PKG_AL_VFBGA361:
		pkg = "AL";
		break;
	case STM32MP25_PKG_AK_VFBGA424:
		pkg = "AK";
		break;
	case STM32MP25_PKG_AI_TFBGA436:
		pkg = "AI";
		break;
#endif /* STM32MP21xxxx */
	default:
		pkg = "??";
		break;
	}

	/* REVISION */
	ret = tfm_plat_otp_read(PLAT_OTP_ID_REV_ID,
				sizeof(uint32_t), (uint8_t *)&otp_val);
	if (ret != TFM_PLAT_ERR_SUCCESS)
		return ret;

	switch (otp_val) {
	case STM32MP2_REV_A:
		cpu_r = "A";
		break;
	case STM32MP2_REV_B:
		cpu_r = "B";
		break;
	case STM32MP2_REV_X:
		cpu_r = "X";
		break;
	case STM32MP2_REV_Y:
		cpu_r = "Y";
		break;
	case STM32MP2_REV_Z:
		cpu_r = "Z";
		break;
	default:
		cpu_r = "?";
		break;
	}

	snprintf(name, STM32_SOC_NAME_SIZE,
		 "STM32MP%s%s Rev.%s", cpu_s, pkg, cpu_r);

	return TFM_PLAT_ERR_SUCCESS;
}

/* Internal layout of the 32bit OTP word board_id */
#define BOARD_ID_BOARD_NB_MASK		GENMASK_32(31, 16)
#define BOARD_ID_BOARD_NB_SHIFT		16
#define BOARD_ID_VARCPN_MASK		GENMASK_32(15, 12)
#define BOARD_ID_VARCPN_SHIFT		12
#define BOARD_ID_REVISION_MASK		GENMASK_32(11, 8)
#define BOARD_ID_REVISION_SHIFT		8
#define BOARD_ID_VARFG_MASK		GENMASK_32(7, 4)
#define BOARD_ID_VARFG_SHIFT		4
#define BOARD_ID_BOM_MASK		GENMASK_32(3, 0)
#define BOARD_ID_BOM_SHIFT		0

enum tfm_plat_err_t get_board_info(char name[STM32_SOC_NAME_SIZE])
{
	enum tfm_plat_err_t ret;
	uint32_t board_id;

	memset(name, 0, STM32_SOC_NAME_SIZE);

	ret = tfm_plat_otp_read(PLAT_OTP_ID_BOARD_ID,
				sizeof(uint32_t), (uint8_t *)&board_id);
	if (ret != TFM_PLAT_ERR_SUCCESS)
		return ret;

	/*
	 * The provisioning of this OTP is not mandatory, but return an error to avoid displaying
	 * an empty trace.
	 */
	if (!board_id)
		return TFM_PLAT_ERR_INVALID_INPUT;

	snprintf(name, STM32_SOC_NAME_SIZE, "MB%04x Var%u.%u Rev.%c-%02u",
		 _FLD_GET(BOARD_ID_BOARD_NB, board_id),
		 _FLD_GET(BOARD_ID_VARCPN, board_id),
		 _FLD_GET(BOARD_ID_VARFG, board_id),
		 (char)_FLD_GET(BOARD_ID_REVISION, board_id) - 1 + 'A',
		 _FLD_GET(BOARD_ID_BOM, board_id));

	return TFM_PLAT_ERR_SUCCESS;
}

static bool get_boot_status(void)
{
	return (RCC->BDCR & RCC_BDCR_RTCCKEN) == 0U;
}

static int __unused stm32mp2_banner(void)
{
	char name[STM32_SOC_NAME_SIZE];

	BOOT_LOG_INF("welcome to MCUboot: "MODEL_VERSION);

	if (get_chip_info(name) == TFM_PLAT_ERR_SUCCESS)
		BOOT_LOG_INF("cpu: %s", name);

	BOOT_LOG_INF("board: "MODEL_BOARD);

	if (get_board_info(name) == TFM_PLAT_ERR_SUCCESS)
		BOOT_LOG_INF("board ID: %s", name);

	BOOT_LOG_INF("dts: "MODEL_BL2_DTS);
	BOOT_LOG_INF("boot device: "MODEL_BOOT_DEV);
	BOOT_LOG_INF("mcu sysclk: %d", SystemCoreClock);

	if (get_boot_status()) {
		BOOT_LOG_INF("Boot status: Cold boot detected.");
	} else {
		BOOT_LOG_INF("Boot status: Warm boot detected.");
	}

	return 0;
}
SYS_INIT(stm32mp2_banner, CORE, 10);
