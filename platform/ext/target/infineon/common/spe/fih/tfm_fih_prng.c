/*
 * (c) 2023-2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "coverity_check.h"
#include "tfm_fih_trng.h"

#define PRNG_A   13
#define PRNG_B   17
#define PRNG_C   5

static uint32_t ifx_prng_dwX;

static bool ifx_prng_initialised = false;

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
        ifx_prng_dwX = ifx_trng();
        rnd = ifx_prng_dwX;
    } while (rnd == ifx_prng_get());

    ifx_prng_initialised = true;
}

TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Directive_4_6, "FIH uses basic types without size and signedness")
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
