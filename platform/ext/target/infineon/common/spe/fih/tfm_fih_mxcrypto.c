/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_fih_platform.h"
#include "cy_device.h"
#include "cy_crypto_core_trng.h"

#define PRNG_A   13
#define PRNG_B   17
#define PRNG_C   5

static uint32_t ifx_prng_dwX;

static bool ifx_prng_initialised = false;


/*
 * Obtain a 32-bit number from the TRNG
 * Returns 0 on failure.
 */
static uint32_t ifx_trng(void)
{
    cy_en_crypto_status_t status;
    uint32_t random;

    status = Cy_Crypto_Core_Enable(CRYPTO);
    if (status != CY_CRYPTO_SUCCESS) {
        return 0;
    }

    /* Use TRNG to generate a single random 32-bit number */
    status = Cy_Crypto_Core_Trng_Ext(CRYPTO, 32, &random);
    if (status != CY_CRYPTO_SUCCESS) {
        return 0;
    }

    /* We're done with the TRNG and Crypto block */
    Cy_Crypto_Core_Trng_DeInit(CRYPTO);
    (void)Cy_Crypto_Core_Disable(CRYPTO);

    return random;
}

/*
 * Return a 32-bit pseudo-random number
 */
static uint32_t ifx_prng_get(void)
{
    ifx_prng_dwX ^= (ifx_prng_dwX << PRNG_A);
    ifx_prng_dwX ^= (ifx_prng_dwX >> PRNG_B);
    ifx_prng_dwX ^= (ifx_prng_dwX << PRNG_C);

    return ifx_prng_dwX;
}

/*
 * Initialize the pseudo-random number generator
 */
static void ifx_prng_init(void)
{
    uint32_t rnd;

    ifx_prng_initialised = false;

    /* If TRNG generation fails this code will loop forever. There is not much
     * that can be done because even calling tfm_core_panic requires fih_delay
     * which uses RNG. */
    do {
        rnd = ifx_prng_dwX = ifx_trng();
    } while (rnd == ifx_prng_get());

    ifx_prng_initialised = true;
}

int fih_delay_init(void)
{
    ifx_prng_init();

    return 0;
}

void tfm_fih_random_generate(uint8_t *rand)
{
    if (!ifx_prng_initialised) {
        FIH_PANIC;
    }

    /* Use the low 8 bits */
    *rand = ifx_prng_get() & 0xffU;
}

uint8_t fih_delay_random(void)
{
    uint8_t rand_value = 0xFF;

    /* Repeat random generation to mitigate instruction skip */
    tfm_fih_random_generate(&rand_value);
    tfm_fih_random_generate(&rand_value);
    tfm_fih_random_generate(&rand_value);

    return rand_value;
}
