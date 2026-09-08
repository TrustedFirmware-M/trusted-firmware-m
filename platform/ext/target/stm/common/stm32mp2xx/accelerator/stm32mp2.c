/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stm32_bsec3.h>
#include <crypto_hw.h>
#include <entropy.h>
#include <psa/crypto.h>

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
psa_status_t
mbedtls_psa_external_get_random(mbedtls_psa_external_random_context_t *context,
				uint8_t *output, size_t output_size,
				size_t *output_length)
{
	if (output == NULL || output_size == 0)
		return PSA_ERROR_INVALID_ARGUMENT;

	if (IS_ENABLED(STM32_M33TDCID)) {
		if (entropy_get_entropy(NULL, output, output_size))
			return PSA_ERROR_HARDWARE_FAILURE;

	} else {
		return PSA_ERROR_NOT_SUPPORTED;
	}

	*output_length = output_size;
	return PSA_SUCCESS;
}
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */

/*
 * \brief Initialize the stm crypto accelerator
 */

int crypto_hw_accelerator_init(void)
{
	return 0;
}

/*
 * \brief Deallocate the stm crypto accelerator
 */
int crypto_hw_accelerator_finish(void)
{
	return 0;
}

/**
 * \brief Apply permissions on debug signals
 *
 * \param[in]   permissions_mask   permission vector for debug signals
 *                                 vector bits interpretation is specific
 *                                 to a target and depends on the architecture
 * \param[in]   len                length of permission vector
 *
 * \return 0 on success, non-zero otherwise
 */
int crypto_hw_apply_debug_permissions(uint8_t *permissions_mask, uint32_t len __unused)
{
	uint32_t perm_mask;

	/*
	 * permissions_mask is given by psa-adac library, with len == 16,
	 * but permission mask on this platform is defined on 32 bits
	 */
	memcpy(&perm_mask, permissions_mask, sizeof(uint32_t));

	return stm32_bsec_write_debug_conf(perm_mask);
}
