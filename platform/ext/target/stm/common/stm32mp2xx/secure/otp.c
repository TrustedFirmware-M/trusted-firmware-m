/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#define DT_DRV_COMPAT st_stm32mp2_otp

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <cmsis_compiler.h>

#include <lib/utils_def.h>
#include <tfm_plat_otp.h>
#include <psa/crypto.h>
#include <config_tfm.h>
#include <tfm_plat_provisioning.h>

#include <devicetree.h>
#include <devicetree/nvmem.h>
#include <nvmem.h>

#ifdef TFM_DUMMY_PROVISIONING
__PACKED_STRUCT tfm_psa_rot_provisioning_data_t {
	uint8_t iak[32];
	uint8_t adac_rotpkh[32];
#if defined(STM32_BL2)
	uint8_t tfm_fw_pkh[32];
	uint8_t ddr_fw_pkh[32];
	uint8_t ca35_fw_pkh[32];
#endif
};

static const struct tfm_psa_rot_provisioning_data_t psa_rot_prov_data = {
	.iak = {
		0xA9, 0xB4, 0x54, 0xB2, 0x6D, 0x6F, 0x90, 0xA4,
		0xEA, 0x31, 0x19, 0x35, 0x64, 0xCB, 0xA9, 0x1F,
		0xEC, 0x6F, 0x9A, 0x00, 0x2A, 0x7D, 0xC0, 0x50,
		0x4B, 0x92, 0xA1, 0x93, 0x71, 0x34, 0x58, 0x5F,
	},
#if defined(PLATFORM_PSA_ADAC_SECURE_DEBUG)
	.adac_rotpkh = {
		0x2a, 0x53, 0x51, 0xc2, 0x83, 0x87, 0x66, 0x35,
		0x09, 0x75, 0x4a, 0xd2, 0x07, 0xbe, 0xf6, 0x4a,
		0xbe, 0xc7, 0x31, 0x06, 0x05, 0xbe, 0x4d, 0xb3,
		0x1e, 0x10, 0xac, 0x01, 0xd4, 0x0c, 0xac, 0x7d,
	},
#endif
#if defined(STM32_BL2)
#if defined(MCUBOOT_SIGN_RSA) && (MCUBOOT_SIGN_RSA_LEN == 3072)
	.tfm_fw_pkh = {
		0xbf, 0xe6, 0xd8, 0x6f, 0x88, 0x26, 0xf4, 0xff,
		0x97, 0xfb, 0x96, 0xc4, 0xe6, 0xfb, 0xc4, 0x99,
		0x3e, 0x46, 0x19, 0xfc, 0x56, 0x5d, 0xa2, 0x6a,
		0xdf, 0x34, 0xc3, 0x29, 0x48, 0x9a, 0xdc, 0x38,
	},
	.ddr_fw_pkh = {
		0xb3, 0x60, 0xca, 0xf5, 0xc9, 0x8c, 0x6b, 0x94,
		0x2a, 0x48, 0x82, 0xfa, 0x9d, 0x48, 0x23, 0xef,
		0xb1, 0x66, 0xa9, 0xef, 0x6a, 0x6e, 0x4a, 0xa3,
		0x7c, 0x19, 0x19, 0xed, 0x1f, 0xcc, 0xc0, 0x49,
	},
	.ca35_fw_pkh = {
		0xbf, 0xe6, 0xd8, 0x6f, 0x88, 0x26, 0xf4, 0xff,
		0x97, 0xfb, 0x96, 0xc4, 0xe6, 0xfb, 0xc4, 0x99,
		0x3e, 0x46, 0x19, 0xfc, 0x56, 0x5d, 0xa2, 0x6a,
		0xdf, 0x34, 0xc3, 0x29, 0x48, 0x9a, 0xdc, 0x38,
	},
#elif defined(MCUBOOT_SIGN_EC256)
	.tfm_fw_pkh = {
		0xe3, 0x04, 0x66, 0xf6, 0xb8, 0x47, 0x0c, 0x1f, \
		0x29, 0x07, 0x0b, 0x17, 0xf1, 0xe2, 0xd3, 0xe9, \
		0x4d, 0x44, 0x5e, 0x3f, 0x60, 0x80, 0x87, 0xfd, \
		0xc7, 0x11, 0xe4, 0x38, 0x2b, 0xb5, 0x38, 0xb6, \
	},
	.ddr_fw_pkh = {
		0x82, 0xa5, 0xb4, 0x43, 0x59, 0x48, 0x53, 0xd4, \
		0xbf, 0x0f, 0xdd, 0x89, 0xa9, 0x14, 0xa5, 0xdc, \
		0x16, 0xf8, 0x67, 0x54, 0x82, 0x07, 0xd7, 0x07, \
		0x7e, 0x74, 0xd8, 0x0c, 0x06, 0x3e, 0xfd, 0xa9, \
	},
	.ca35_fw_pkh = {
		0xe3, 0x04, 0x66, 0xf6, 0xb8, 0x47, 0x0c, 0x1f, \
		0x29, 0x07, 0x0b, 0x17, 0xf1, 0xe2, 0xd3, 0xe9, \
		0x4d, 0x44, 0x5e, 0x3f, 0x60, 0x80, 0x87, 0xfd, \
		0xc7, 0x11, 0xe4, 0x38, 0x2b, 0xb5, 0x38, 0xb6, \
	},
#else
#error "TFM_DUMMY_PROVISIONING: Please choose between EC-P256 or RSA-3072 for image signatures."
#endif
#endif
};
#endif /* TFM_DUMMY_PROVISIONING */

static const struct device *nvmem_dev_from_otp_id(enum tfm_otp_element_id_t id)
{
	const struct device *dev;

	switch (id) {
#if defined(STM32_BL2)
#if (MCUBOOT_IMAGE_NUMBER == 3)
	case PLAT_OTP_ID_BL2_ROTPK_0:
		dev = DT_INST_DEV_NVMEM(0, tfm_fw_pkh);
		break;
	case PLAT_OTP_ID_BL2_ROTPK_1:
		dev = DT_INST_DEV_NVMEM(0, ca35_fw_pkh);
		break;
	case PLAT_OTP_ID_BL2_ROTPK_2:
		dev = DT_INST_DEV_NVMEM(0, ddr_fw_pkh);
		break;
#else
	case PLAT_OTP_ID_BL2_ROTPK_0:
		dev = DT_INST_DEV_NVMEM(0, tfm_fw_pkh);
		break;
	case PLAT_OTP_ID_BL2_ROTPK_1:
		dev = DT_INST_DEV_NVMEM(0, ddr_fw_pkh);
		break;
#endif
#endif
	case PLAT_OTP_ID_IAK:
		dev = DT_INST_DEV_NVMEM(0, iak);
		break;
	case PLAT_OTP_ID_IMPLEMENTATION_ID:
		dev = DT_INST_DEV_NVMEM(0, implementation_id);
		break;
	case PLAT_OTP_ID_RPN:
		dev = DT_INST_DEV_NVMEM(0, rpn_otp);
		break;
	case PLAT_OTP_ID_REV_ID:
		dev = DT_INST_DEV_NVMEM(0, id_otp);
		break;
	case PLAT_OTP_ID_PACKAGE:
		dev = DT_INST_DEV_NVMEM(0, package_otp);
		break;
	case PLAT_OTP_ID_BOARD_ID:
		dev = DT_INST_DEV_NVMEM(0, board_id);
		break;
	case PLAT_OTP_ID_STM32_CERTIF:
		dev = DT_INST_DEV_NVMEM(0, stm32certif);
		break;
	case PLAT_OTP_ID_SECURE_DEBUG_PK:
		dev = DT_INST_DEV_NVMEM(0, adac_rotpkh);
		break;
	case PLAT_OTP_ID_FIP_EDMK:
		dev = DT_INST_DEV_NVMEM(0, fip_edmk);
		break;
	default:
		dev = NULL;
		break;
	}

	return dev;
}

static bool __maybe_unused is_factory_fused_otp(enum tfm_otp_element_id_t id)
{
	switch (id) {
	case PLAT_OTP_ID_BOARD_ID:
	case PLAT_OTP_ID_IMPLEMENTATION_ID:
	case PLAT_OTP_ID_PACKAGE:
	case PLAT_OTP_ID_STM32_CERTIF:
	case PLAT_OTP_ID_REV_ID:
	case PLAT_OTP_ID_RPN:
		return true;

	default:
		return false;
	}
}

#if TFM_DUMMY_PROVISIONING
#if !STM32_OVERRIDE_OTP
static enum tfm_plat_err_t stm32_check_otp_check_value(size_t out_len, uint8_t *out)
{
	for (int i = 0; i < out_len; i++) {
		if (out[i] != 0)
			return TFM_PLAT_ERR_SUCCESS;
	}

	return TFM_PLAT_ERR_INVALID_INPUT;
}
#endif /* !STM32_OVERRIDE_OTP */

static enum tfm_plat_err_t stm32_set_default_value(enum tfm_otp_element_id_t id,
						   size_t out_len, uint8_t *out)
{
	switch (id) {
	case PLAT_OTP_ID_IAK_LEN:
		if (out_len < sizeof(size_t))
			return TFM_PLAT_ERR_INVALID_INPUT;

		*out = sizeof(psa_rot_prov_data.iak);
		break;
	case PLAT_OTP_ID_IAK:
		if (out_len > sizeof(psa_rot_prov_data.iak))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void *)out, psa_rot_prov_data.iak, out_len);
		break;
#if PLATFORM_PSA_ADAC_SECURE_DEBUG
	case PLAT_OTP_ID_SECURE_DEBUG_PK:
		if (out_len > sizeof(psa_rot_prov_data.adac_rotpkh))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void *)out, psa_rot_prov_data.adac_rotpkh, out_len);
		break;
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
#if defined(STM32_BL2)
	case PLAT_OTP_ID_BL2_ROTPK_0:
		if (out_len > sizeof(psa_rot_prov_data.tfm_fw_pkh))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void*)out, psa_rot_prov_data.tfm_fw_pkh, out_len);
		break;
#if (MCUBOOT_IMAGE_NUMBER == 3)
	case PLAT_OTP_ID_BL2_ROTPK_1:
		if (out_len > sizeof(psa_rot_prov_data.ca35_fw_pkh))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void*)out, psa_rot_prov_data.ca35_fw_pkh, out_len);
		break;

	case PLAT_OTP_ID_BL2_ROTPK_2:
		if (out_len > sizeof(psa_rot_prov_data.ddr_fw_pkh))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void *)out, psa_rot_prov_data.ddr_fw_pkh, out_len);
		break;
#else
	case PLAT_OTP_ID_BL2_ROTPK_1:
		if (out_len > sizeof(psa_rot_prov_data.ddr_fw_pkh))
			return TFM_PLAT_ERR_INVALID_INPUT;

		memcpy((void*)out, psa_rot_prov_data.ddr_fw_pkh, out_len);
		break;
#endif
#endif
	default:
		break;
	}

	return TFM_PLAT_ERR_SUCCESS;
}
#endif

static enum tfm_plat_err_t otp_read_by_nvmem(const struct device *dev_nvmem,
					     size_t out_len, uint8_t *out)
{
	size_t read_len = 0;
	int err;

	if (!dev_nvmem)
		return TFM_PLAT_ERR_UNSUPPORTED;

	err = nvmem_read_cell(dev_nvmem, out_len, out, &read_len);
	if (read_len != out_len) {
		memset(out, 0, out_len);
		return TFM_PLAT_ERR_NOT_PERMITTED;
	}

	return TFM_PLAT_ERR_SUCCESS;
}

#define BOOTROM_CFG_9_SEC_BOOT	GENMASK(3, 0)
#define BOOTROM_CFG_9_PROV_DONE	GENMASK(7, 4)
#define HCONF1_DISABLE_SCAN	BIT(20)
static int otp_read_lcs(uint32_t out_len, uint8_t *out)
{
	uint32_t secure_boot, disable_scan, prov_done;
	enum plat_otp_lcs_t *lcs = (enum plat_otp_lcs_t *)out;
	uint32_t bootrom_cfg_9, hconf1;
	int err;

	*lcs = PLAT_OTP_LCS_ASSEMBLY_AND_TEST;

	err = otp_read_by_nvmem(DT_INST_DEV_NVMEM(0, bootrom_config_9),
				sizeof(uint32_t), (uint8_t *)&bootrom_cfg_9);
	if (err)
		return err;

	err = otp_read_by_nvmem(DT_INST_DEV_NVMEM(0, hconf1_otp),
				sizeof(uint32_t), (uint8_t *)&hconf1);
	if (err)
		return err;

	/* true if all bit of field are set */
	secure_boot = !!(bootrom_cfg_9 & BOOTROM_CFG_9_SEC_BOOT);
	prov_done = !!(bootrom_cfg_9 & BOOTROM_CFG_9_PROV_DONE);
	disable_scan = !!(hconf1 & HCONF1_DISABLE_SCAN);

	if (secure_boot && prov_done && disable_scan)
		*lcs = PLAT_OTP_LCS_SECURED;

	return 0;
}

enum tfm_plat_err_t tfm_plat_otp_read(enum tfm_otp_element_id_t id,
                                      size_t out_len, uint8_t *out)
{
	const struct device *dev_nvmem;
	size_t read_len = 0;
	size_t cell_size = 0;
	int err;

	switch (id) {
	case PLAT_OTP_ID_LCS:
		err = otp_read_lcs(out_len, out);
		break;
	case PLAT_OTP_ID_IAK_LEN:
		dev_nvmem = DT_INST_DEV_NVMEM(0, iak);
		if (!device_is_ready(dev_nvmem))
			return TFM_PLAT_ERR_UNSUPPORTED;

		err = nvmem_get_cell_size(dev_nvmem, &read_len);
		if (!err)
			memcpy(out, &read_len, sizeof(size_t));

		break;
	case PLAT_OTP_ID_IMPLEMENTATION_ID:
		dev_nvmem = DT_INST_DEV_NVMEM(0, implementation_id);
		if (!device_is_ready(dev_nvmem))
			return TFM_PLAT_ERR_UNSUPPORTED;

		/*
		 * On STM32MP2 platform, the Implementation ID is lower than the max size
		 * (currently 12 bytes vs. 32 bytes for the max).
		 */
		err = nvmem_get_cell_size(dev_nvmem, &cell_size);
		if (!err) {
			err = nvmem_read_cell(dev_nvmem, cell_size, out, &read_len);
		}
		break;
	default:
		dev_nvmem = nvmem_dev_from_otp_id(id);
		if (!device_is_ready(dev_nvmem))
			return TFM_PLAT_ERR_UNSUPPORTED;

		err = nvmem_read_cell(dev_nvmem, out_len, out, &read_len);
		if (read_len != out_len) {
			memset(out, 0, out_len);
			return TFM_PLAT_ERR_NOT_PERMITTED;
		}
#if TFM_DUMMY_PROVISIONING
		if (!err && !is_factory_fused_otp(id)) {
#if !STM32_OVERRIDE_OTP
			if (stm32_check_otp_check_value(out_len, out))
#endif
				err = stm32_set_default_value(id, out_len, out);
		}
#endif
		break;
	}

	if (err)
		return TFM_PLAT_ERR_SYSTEM_ERR;

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_get_size(enum tfm_otp_element_id_t id, size_t *size)
{
	const struct device *dev;
	int err = 0;

	switch (id) {
	case PLAT_OTP_ID_LCS:
		*size = sizeof(uint32_t);
		break;
	case PLAT_OTP_ID_IAK_LEN:
		*size = sizeof(uint32_t);
		break;
	default:
		dev = nvmem_dev_from_otp_id(id);
		if (!device_is_ready(dev))
			return TFM_PLAT_ERR_UNSUPPORTED;

		err = nvmem_get_cell_size(dev, size);
		break;
	}

	if (err)
		return TFM_PLAT_ERR_SYSTEM_ERR;

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_write(enum tfm_otp_element_id_t id, size_t in_len,
				       const uint8_t *in)
{
	return TFM_PLAT_ERR_NOT_PERMITTED;
}

enum tfm_plat_err_t tfm_plat_otp_init(void)
{
	return TFM_PLAT_ERR_SUCCESS;
}

#define NVMEM_ELEM(node_id, prop, idx)								\
	DT_NVMEM_SPEC_GET_BY_IDX(node_id, idx)

#define STM32_OTP_CONFIG(n)									\
												\
static const struct nvmem_dt_spec stm32_otp_cfg_##n[DT_INST_PROP_LEN(n, nvmem_cells)] = {	\
	DT_INST_FOREACH_PROP_ELEM_SEP(n, nvmem_cells, NVMEM_ELEM, (,))				\
};												\
												\
DEVICE_DT_INST_DEFINE(n, NULL, NULL,								\
		      NULL,									\
		      &stm32_otp_cfg_##n,							\
		      CORE, 7,									\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_OTP_CONFIG)

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,
	     "only one otp compatible node is supported");
