/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <string.h>
#include <cmsis_compiler.h>

#include <config_tfm.h>
#include <tfm_plat_provisioning.h>
#include <tfm_plat_otp.h>
#include <tfm_attest_hal.h>
#include <psa/crypto.h>
#include <debug.h>

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
#if TFM_DUMMY_PROVISIONING
	IMSG("***************************\n");
	IMSG("Provisioning bypassed, if your OTP are not set.\n");
	IMSG("Default values will be used.\033[1;31m\n");
	IMSG("DUMMY_PROVISIONING is not suitable for production!\n");
	IMSG("This device is \033[1;1mNOT SECURE\033[0m\n");
	IMSG("***************************\n");
	return TFM_PLAT_ERR_SUCCESS;
#else
	return TFM_PLAT_ERR_NOT_PERMITTED;
#endif
}

void tfm_plat_provisioning_check_for_dummy_keys(void)
{
	uint64_t iak_start;
	enum tfm_plat_err_t err;

	err = tfm_plat_otp_read(PLAT_OTP_ID_IAK, sizeof(iak_start), (uint8_t*)&iak_start);
	if(err != TFM_PLAT_ERR_SUCCESS) {
                EMSG("OTP read failed");
	}

	if(iak_start == 0xA4906F6DB254B4A9) {
		WMSG("This device was provisioned with dummy keys.\033[1;31m\r\n");
		WMSG("This device is \033[1;1mNOT SECURE\033[0m\r\n");
	}

	memset(&iak_start, 0, sizeof(iak_start));
}

enum tfm_plat_err_t tfm_plat_provisioning_is_required(bool *provisioning_required)
{
	enum tfm_plat_err_t err;
	enum plat_otp_lcs_t lcs;

	if (!provisioning_required)
		return TFM_PLAT_ERR_INVALID_INPUT;

	err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t*)&lcs);
	if (err != TFM_PLAT_ERR_SUCCESS) {
		return err;
	}

	*provisioning_required = (lcs == PLAT_OTP_LCS_PSA_ROT_PROVISIONING);

	return TFM_PLAT_ERR_SUCCESS;
}
