/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <tfm_attest_hal.h>
#include <tfm_plat_boot_seed.h>
#include <tfm_plat_device_id.h>
#include <tfm_plat_otp.h>
#include <tfm_string.h>

#include <debug.h>
#include <stdbool.h>
#include <entropy.h>
#include <stm_profile.h>

static enum tfm_security_lifecycle_t map_otp_lcs_to_tfm_slc(enum plat_otp_lcs_t lcs)
{
		switch (lcs) {
		case PLAT_OTP_LCS_ASSEMBLY_AND_TEST:
			return TFM_SLC_ASSEMBLY_AND_TEST;
		case PLAT_OTP_LCS_PSA_ROT_PROVISIONING:
			return TFM_SLC_PSA_ROT_PROVISIONING;
		case PLAT_OTP_LCS_SECURED:
			return TFM_SLC_SECURED;
		case PLAT_OTP_LCS_DECOMMISSIONED:
			return TFM_SLC_DECOMMISSIONED;
		case PLAT_OTP_LCS_UNKNOWN:
		default:
			return TFM_SLC_UNKNOWN;
	}
}

enum tfm_security_lifecycle_t tfm_attest_hal_get_security_lifecycle(void)
{
	enum plat_otp_lcs_t otp_lcs;
	enum tfm_plat_err_t err;

	err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(otp_lcs), (uint8_t *)&otp_lcs);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return TFM_SLC_UNKNOWN;

	return map_otp_lcs_to_tfm_slc(otp_lcs);
}

enum tfm_plat_err_t
tfm_attest_hal_get_verification_service(uint32_t *size, uint8_t *buf)
{
	enum tfm_plat_err_t err;
	size_t otp_size;
	size_t copy_size;

	err = tfm_plat_otp_read(PLAT_OTP_ID_VERIFICATION_SERVICE_URL, *size, buf);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return err;

	err =  tfm_plat_otp_get_size(PLAT_OTP_ID_VERIFICATION_SERVICE_URL, &otp_size);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return err;

	/* Actually copied data is always the smaller */
	copy_size = *size < otp_size ? *size : otp_size;
	/* String content */
	*size = strnlen((char *)buf, copy_size);

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
tfm_attest_hal_get_profile_definition(uint32_t *size, uint8_t *buf)
{
	size_t copy_size;
#ifdef STM32_PROFILE_DEFINITION
	char *profile_definition = STM32_PROFILE_DEFINITION;
#else
	char *profile_definition = "UNDEFINED";
#endif

	/* Actually copied data is always the smaller */
	copy_size = *size < strlen(profile_definition) ? *size : strlen(profile_definition);

	memcpy(buf, profile_definition, copy_size);

	/* String content */
	*size = strnlen((char *)buf, copy_size);

	return TFM_PLAT_ERR_SUCCESS;
}

static bool __maybe_unused is_boot_seed_zero(uint32_t size, const uint8_t *boot_seed)
{
	uint8_t zero_array[BOOT_SEED_SIZE] = {0};

	return memcmp(boot_seed, zero_array, size) == 0;
}

enum tfm_plat_err_t tfm_plat_get_boot_seed(uint32_t size, uint8_t *buf)
{
	if (size > BOOT_SEED_SIZE)
		return TFM_PLAT_ERR_MAX_VALUE;

	if (IS_ENABLED(STM32_M33TDCID)) {
		static uint8_t boot_seed[BOOT_SEED_SIZE] = {0}; /* persistent value */

		/* Get a random value only at first call */
		if (is_boot_seed_zero(size, &boot_seed[0]))
			if (entropy_get_entropy(NULL, boot_seed, size))
				return TFM_PLAT_ERR_SYSTEM_ERR;

		memcpy(buf, boot_seed, size);
	} else if (IS_ENABLED(TFM_DUMMY_PROVISIONING)) {
		static const uint8_t dummy_boot_seed[BOOT_SEED_SIZE] = {
			0x40, 0xd1, 0x46, 0xc8, 0x4d, 0xa0, 0x74, 0xb0,
			0xa7, 0x60, 0x8c, 0x98, 0x02, 0x7d, 0x2b, 0x24,
			0xe8, 0x5f, 0xc3, 0xa2, 0xab, 0x85, 0x71, 0x27,
			0x78, 0x48, 0xd3, 0x5f, 0x00, 0x12, 0xf6, 0xae,
		};

		memcpy(buf, dummy_boot_seed, size);
	} else {
		/* Not supported yet */
		EMSG("Unsupported boot seed\r\n");
		return TFM_PLAT_ERR_UNSUPPORTED;
	}

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_get_implementation_id(uint32_t *size,
						   uint8_t  *buf)
{
	enum tfm_plat_err_t err;
	size_t otp_size;
	size_t copy_size;

	err = tfm_plat_otp_read(PLAT_OTP_ID_IMPLEMENTATION_ID, *size, buf);
	if(err != TFM_PLAT_ERR_SUCCESS)
		return err;

	err =  tfm_plat_otp_get_size(PLAT_OTP_ID_IMPLEMENTATION_ID, &otp_size);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return err;

	/* Actually copied data is always the smaller */
	copy_size = *size < otp_size ? *size : otp_size;
	/* Binary data */
	*size = copy_size;

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_get_cert_ref(uint32_t *size, uint8_t *buf)
{
	enum tfm_plat_err_t err;
	size_t otp_size;
	size_t copy_size;

	err = tfm_plat_otp_read(PLAT_OTP_ID_CERT_REF, *size, buf);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return err;

	err =  tfm_plat_otp_get_size(PLAT_OTP_ID_CERT_REF, &otp_size);
	if (err != TFM_PLAT_ERR_SUCCESS)
		return err;

	/* Actually copied data is always the smaller */
	copy_size = *size < otp_size ? *size : otp_size;
	/* String content */
	*size = strnlen((char *)buf, copy_size);

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_attest_hal_get_platform_config(uint32_t *size, uint8_t  *buf)
{
	uint32_t dummy_plat_config = 0xDEADBEEF;

	if (*size < sizeof(dummy_plat_config))
		return TFM_PLAT_ERR_SYSTEM_ERR;

	memcpy(buf, &dummy_plat_config, sizeof(dummy_plat_config));
	*size = sizeof(dummy_plat_config);

	return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_attest_hal_get_platform_hash_algo(uint32_t *size,
							  const char **buf)
{
#ifdef MEASUREMENT_HASH_ALGO_NAME
	static const char hash_algo[] = MEASUREMENT_HASH_ALGO_NAME;
#else
	static const char hash_algo[] = "not-hash-extended";
#endif

	/* Not including the null-terminator. */
	*size = (uint32_t)sizeof(hash_algo) - 1;
	*buf = hash_algo;

	return TFM_PLAT_ERR_SUCCESS;
}
