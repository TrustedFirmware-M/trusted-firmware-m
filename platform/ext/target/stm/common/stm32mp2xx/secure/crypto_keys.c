/*
 * Copyright (c) 2017-2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <errno.h>
#include <lib/utils_def.h>
#include <sk_cipher.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/endian.h>
#include <psa_manifest/pid.h>
#include <psa/crypto.h>
#include <tfm_builtin_key_loader.h>
#include <tfm_plat_crypto_keys.h>
#include <tfm_plat_otp.h>
#include "tfm_builtin_key_ids.h"

#define NUMBER_OF_ELEMENTS_OF(x) sizeof(x)/sizeof(*x)
#define MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID -0x3c000000
#define TFM_NS_PARTITION_ID                  MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID

#define HUK_SUBKEY_MAX_LEN	32
#define HUK_MAX_DATA_LEN	25

#if defined(STM32_M33TDCID)
#define SAES_NODE_NAME	saes
#define HUK_SUBKEY_DIE_ID	2

BUILD_ASSERT(DT_NODE_HAS_STATUS(DT_NODELABEL(SAES_NODE_NAME), okay), "saes node is mandatory");

/* HUK subkey management section */
static void xor_block(uint8_t *b1, uint8_t *b2, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
		b1[i] ^= b2[i];
}

static int crypto_keys_cmac_prf_128(const struct device *dev,
				    enum sk_cipher_key_selection key_sel,
				    const void *key, size_t key_size,
				    uint8_t *data, size_t data_size,
				    uint8_t *out)
{
	struct sk_cipher_config_t config;
	int res = -EPERM;
	uint8_t block[AES_BLOCK_SIZE] = { };
	uint8_t k1[AES_BLOCK_SIZE] = { };
	uint8_t k2[AES_BLOCK_SIZE] = { };
	uint8_t l[AES_BLOCK_SIZE] = { };
	size_t processed = 0;
	uint8_t bit = 0;
	int i = 0;

	if (!dev)
		return -ENODEV;

	config = (struct sk_cipher_config_t){
		.is_dec = false,
		.ch_mode = SK_CIPHER_MODE_ECB,
		.key_select = key_sel,
		.key = key,
		.key_size = key_size,
		.iv = NULL,
		.iv_size = 0,
	};

	/* Get K1 and K2 */
	res = sk_cipher_ctx_init(dev, &config);
	if (res)
		goto end;

	res = sk_cipher_update(dev, true, l, l, sizeof(l));
	if (res)
		goto end;

	/* MSB(L) == 0 => K1 = L << 1 */
	bit = 0;
	for (i = sizeof(l) - 1; i >= 0; i--) {
		k1[i] = (l[i] << 1) | bit;
		bit = (l[i] & 0x80) >> 7;
	}
	/* MSB(L) == 1 => K1 = (L << 1) XOR const_Rb */
	if ((l[0] & 0x80))
		k1[sizeof(k1) - 1] = k1[sizeof(k1) - 1] ^ 0x87;

	/* MSB(K1) == 0 => K2 = K1 << 1 */
	bit = 0;
	for (i = sizeof(k1) - 1; i >= 0; i--) {
		k2[i] = (k1[i] << 1) | bit;
		bit = (k1[i] & 0x80) >> 7;
	}

	/* MSB(K1) == 1 => K2 = (K1 << 1) XOR const_Rb */
	if ((k1[0] & 0x80))
		k2[sizeof(k2) - 1] = k2[sizeof(k2) - 1] ^ 0x87;

	if (data_size > AES_BLOCK_SIZE) {
		uint8_t data_out[AES_BLOCK_SIZE] = {0};

		config = (struct sk_cipher_config_t){
			.is_dec = false,
			.ch_mode = SK_CIPHER_MODE_CBC,
			.key_select = key_sel,
			.key = key,
			.key_size = key_size,
			.iv = block,
			.iv_size = sizeof(block),
		};

		/* All block but last in CBC mode */
		res = sk_cipher_ctx_init(dev, &config);
		if (res)
			goto end;

		processed = round_down(data_size - 1, AES_BLOCK_SIZE);

		res = sk_cipher_update(dev, true, data, data_out, processed);
		if (!res) {
			/* Copy last out block or keep block as { 0 } */
			memcpy(block, data_out + processed - AES_BLOCK_SIZE,
			       AES_BLOCK_SIZE);
		}

		if (res)
			goto end;
	}

	/* Manage last block */
	xor_block(block, data + processed, data_size - processed);
	if (data_size - processed == AES_BLOCK_SIZE) {
		xor_block(block, k1, AES_BLOCK_SIZE);
	} else {
		/* xor with padding = 0b100... */
		block[data_size - processed] ^= 0x80;
		xor_block(block, k2, AES_BLOCK_SIZE);
	}

	/*
	 * AES last block.
	 * We need to use same chaining mode to keep same key if DHUK is
	 * selected so we reuse l as a zero initialized IV.
	 */
	memset(l, 0, sizeof(l));

	config = (struct sk_cipher_config_t){
		.is_dec = false,
		.ch_mode = SK_CIPHER_MODE_CBC,
		.key_select = key_sel,
		.key = key,
		.key_size = key_size,
		.iv = l,
		.iv_size = sizeof(l),
	};

	res = sk_cipher_ctx_init(dev, &config);
	if (res)
		goto end;

	res = sk_cipher_update(dev, true, block, out, AES_BLOCK_SIZE);

end:
	(void)sk_cipher_reset(dev);

	return res;
}

static int crypto_keys_kdf(const struct device *dev,
			   enum sk_cipher_key_selection key_sel,
			   const void *key, size_t key_size,
			   const void *input, size_t input_size,
			   uint8_t *subkey, size_t subkey_size)

{
	int res = 0;
	uint32_t index = 0;
	uint32_t index_be = 0;
	uint8_t data[HUK_MAX_DATA_LEN + sizeof(uint32_t)] = {0};
	size_t data_index = 0;
	size_t subkey_index = 0;
	size_t data_size = input_size + sizeof(index_be);
	uint8_t cmac[AES_BLOCK_SIZE] = { };

	if (!dev || !input || !input_size)
		return -EINVAL;

	/* For each K(i) we will add an index */
	if (input_size > HUK_MAX_DATA_LEN)
		return -ENOMEM;

	data_index = 0;
	index_be = htobe32(index);
	memcpy(data + data_index, &index_be, sizeof(index_be));
	data_index += sizeof(index_be);
	memcpy(data + data_index, input, input_size);
	data_index += input_size;

	/* K(i) computation. */
	index = 0;
	while (subkey_index < subkey_size) {
		index++;
		index_be = htobe32(index);
		memcpy(data, &index_be, sizeof(index_be));

		res = crypto_keys_cmac_prf_128(dev, key_sel, key, key_size,
					       data, data_size, cmac);
		if (res)
			goto out;

		memcpy(subkey + subkey_index, cmac,
		       MIN(subkey_size - subkey_index, sizeof(cmac)));
		subkey_index += sizeof(cmac);
	}

out:
	if (res)
		memset(subkey, 0, subkey_size);

	return res;
}

/**
 * @brief Implement hardware HUK derivation using SAES resources
 * @param dev: derive device instance
 * @param usage: intended usage of the subkey
 * @param const_data: constant data to generate different subkeys with the same
 *		      usage
 * @param const_data_len: length of constant data (maximum size: HUK_MAX_DATA)
 * @param subkey: the generated subkey
 * @param subkey_len: required size of the subkey, sizes larger than
 *		      HUK_SUBKEY_MAX_LEN are not accepted.
 *
 * Returns a subkey derived from the hardware unique key. Given the same
 * input the same subkey is returned each time.
 *
 * @retval 0 on success or an errno code on failure.
 */
static int subkey_derive(const struct device *dev, uint32_t usage,
			 const void *const_data, size_t const_data_len,
			 uint8_t *subkey, size_t subkey_len)
{
	int res = -EPERM;
	uint8_t input[HUK_MAX_DATA_LEN] = {0};
	size_t input_index = 0;
	size_t subkey_bitlen = 0;
	uint8_t separator = 0;
	size_t data_size = const_data_len + sizeof(separator) + sizeof(usage) +
			   sizeof(subkey_bitlen) + AES_BLOCK_SIZE;

	if ((!dev) || !device_is_ready(dev))
		return -ENODEV;

	if (sizeof(input) < data_size)
		return -ENOMEM;

	input_index = 0;
	if (const_data) {
		memcpy(input + input_index, const_data, const_data_len);
		input_index += const_data_len;

		memcpy(input + input_index, &separator, sizeof(separator));
		input_index += sizeof(separator);
	}

	memcpy(input + input_index, &usage, sizeof(usage));
	input_index += sizeof(usage);

	/*
	 * We should add the subkey_len in bits at end of input.
	 * And we choose to put in a MSB first uint32_t.
	 */
	subkey_bitlen = htobe32(subkey_len * 8);
	memcpy(input + input_index, &subkey_bitlen, sizeof(subkey_bitlen));
	input_index += sizeof(subkey_bitlen);

	/*
	 * We get K(0) to avoid some key control attack
	 * and store it at end of input.
	 */
	res = crypto_keys_cmac_prf_128(dev, STM32_SAES_KEY_DHU, NULL,
				       AES_KEYSIZE_128,
				       input, input_index,
				       input + input_index);
	if (res)
		return res;

	/* We just added K(0) to input */
	input_index += AES_BLOCK_SIZE;

	res = crypto_keys_kdf(dev, STM32_SAES_KEY_DHU, NULL, AES_KEYSIZE_128,
			      input, input_index, subkey, subkey_len);

	return res;
}
/* end of HUK subkey section */

static enum tfm_plat_err_t tfm_plat_get_huk(const void *ctx,
					    uint8_t *buf, size_t buf_len,
					    size_t *key_len,
					    psa_key_bits_t *key_bits,
					    psa_algorithm_t *algorithm,
					    psa_key_type_t *type)
{
	(void)ctx;

	/* Try to get the saes driver */
	const struct device *dev = SK_CIPHER_GET_BY_NODE_LABEL(SAES_NODE_NAME);

	if (buf_len > HUK_SUBKEY_MAX_LEN)
		buf_len = HUK_SUBKEY_MAX_LEN;

	if (subkey_derive(dev, HUK_SUBKEY_DIE_ID, NULL, 0, buf, buf_len))
		return TFM_PLAT_ERR_SYSTEM_ERR;

	*key_len = buf_len;
	*key_bits = *key_len * 8;
	*algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
	*type = PSA_KEY_TYPE_DERIVE;

	return TFM_PLAT_ERR_SUCCESS;
}
#else
static enum tfm_plat_err_t tfm_plat_get_huk(const void *ctx,
					    uint8_t *buf, size_t buf_len,
					    size_t *key_len,
					    psa_key_bits_t *key_bits,
					    psa_algorithm_t *algorithm,
					    psa_key_type_t *type)
{
	uint8_t certif[128];
	size_t certif_size;
	int err;
	psa_hash_operation_t operation = psa_hash_operation_init();
	psa_status_t res;

	(void)ctx;

	if (buf_len > HUK_SUBKEY_MAX_LEN)
		buf_len = HUK_SUBKEY_MAX_LEN;

	err = tfm_plat_otp_get_size(PLAT_OTP_ID_STM32_CERTIF, &certif_size);
	if (err)
		return TFM_PLAT_ERR_SYSTEM_ERR;

	err = tfm_plat_otp_read(PLAT_OTP_ID_STM32_CERTIF, certif_size, certif);
	if (err)
		return TFM_PLAT_ERR_SYSTEM_ERR;

	res = psa_hash_setup(&operation, PSA_ALG_SHA_256);
	if (res != PSA_SUCCESS)
		goto psa_abort;

	res = psa_hash_update(&operation, certif, certif_size);
	if (res != PSA_SUCCESS)
		goto psa_abort;

	res = psa_hash_finish(&operation, buf, buf_len, key_len);
	if (res != PSA_SUCCESS)
		goto psa_abort;

	*key_bits = *key_len * 8;
	*algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
	*type = PSA_KEY_TYPE_DERIVE;

	return TFM_PLAT_ERR_SUCCESS;

psa_abort:
	(void)psa_hash_abort(&operation);

	return TFM_PLAT_ERR_SYSTEM_ERR;
}
#endif

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
static enum tfm_plat_err_t tfm_plat_get_iak(const void *ctx,
					    uint8_t *buf, size_t buf_len,
					    size_t *key_len,
					    psa_key_bits_t *key_bits,
					    psa_algorithm_t *algorithm,
					    psa_key_type_t *type)
{
	enum tfm_plat_err_t err;

	(void)ctx;

	err = tfm_plat_otp_read(PLAT_OTP_ID_IAK_LEN,
				sizeof(size_t), (uint8_t*)key_len);
	if(err != TFM_PLAT_ERR_SUCCESS) {
		return err;
	}
	*key_bits = *key_len * 8;

	if (buf_len < *key_len) {
		return TFM_PLAT_ERR_SYSTEM_ERR;
	}

#ifdef SYMMETRIC_INITIAL_ATTESTATION
	*algorithm = PSA_ALG_HMAC(PSA_ALG_SHA_256);
	*type = PSA_KEY_TYPE_HMAC;
#else /* SYMMETRIC_INITIAL_ATTESTATION */
	*algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
	*type = PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1);
#endif /* SYMMETRIC_INITIAL_ATTESTATION */

	return tfm_plat_otp_read(PLAT_OTP_ID_IAK, *key_len, buf);
}
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
/**
 * @brief Table describing per-user key policy for the IAK
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_iak_per_user_policy[] = {
	{.user = TFM_SP_INITIAL_ATTESTATION,
#ifdef SYMMETRIC_INITIAL_ATTESTATION
		.usage = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT,
#else
		.usage = PSA_KEY_USAGE_SIGN_HASH,
#endif /* SYMMETRIC_INITIAL_ATTESTATION */
	},
#ifdef TEST_S_ATTESTATION
	{.user = TFM_SP_SECURE_TEST_PARTITION, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_S_ATTESTATION */
#ifdef TEST_NS_ATTESTATION
	{.user = TFM_NS_PARTITION_ID, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_NS_ATTESTATION */
};
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

/**
 * @brief Table describing per-key user policies
 *
 */
static const tfm_plat_builtin_key_policy_t g_builtin_keys_policy[] = {
	{.key_id = TFM_BUILTIN_KEY_ID_HUK, .per_user_policy = 0, .usage = PSA_KEY_USAGE_DERIVE},
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
	{.key_id = TFM_BUILTIN_KEY_ID_IAK,
		.per_user_policy = NUMBER_OF_ELEMENTS_OF(g_iak_per_user_policy),
		.policy_ptr = g_iak_per_user_policy},
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

/**
 * @brief Table describing the builtin-in keys (plaform keys) available in the platform. Note
 *	  that to bind the keys to the tfm_builtin_key_loader driver, the lifetime must be
 *	  explicitly set to the one associated to the driver, i.e. TFM_BUILTIN_KEY_LOADER_LIFETIME
 */
static const tfm_plat_builtin_key_descriptor_t g_builtin_keys_desc[] = {
	{.key_id = TFM_BUILTIN_KEY_ID_HUK,
		.slot_number = TFM_BUILTIN_KEY_SLOT_HUK,
		.lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
		.loader_key_func = tfm_plat_get_huk},
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
	{.key_id = TFM_BUILTIN_KEY_ID_IAK,
		.slot_number = TFM_BUILTIN_KEY_SLOT_IAK,
		.lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
		.loader_key_func = tfm_plat_get_iak},
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *desc_ptr[])
{
	*desc_ptr = &g_builtin_keys_policy[0];
	return NUMBER_OF_ELEMENTS_OF(g_builtin_keys_policy);
}

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
	*desc_ptr = &g_builtin_keys_desc[0];
	return NUMBER_OF_ELEMENTS_OF(g_builtin_keys_desc);
}
