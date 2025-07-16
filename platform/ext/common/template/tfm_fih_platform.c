/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "tfm_fih_platform.h"

#ifdef FIH_ENABLE_DELAY

fih_ret tfm_fih_random_init(void)
{
    SysTick->LOAD  = 0x000000FE;                  /* Set reload register */
    SysTick->VAL   = 0UL;                         /* Load the SysTick Counter Value */
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                     SysTick_CTRL_ENABLE_Msk;     /* Enable SysTick Timer */

    return (FIH_SUCCESS);
}

void tfm_fih_random_generate(uint8_t *rand)
{
    /* Repeat reading SysTick value to mitigate instruction skip */
    *rand = (uint8_t)SysTick->VAL;
    *rand = (uint8_t)SysTick->VAL;
    *rand = (uint8_t)SysTick->VAL;
    *rand = (uint8_t)SysTick->VAL;
    *rand = (uint8_t)SysTick->VAL;
}

int fih_delay_init(void)
{
    FIH_DECLARE(fih_ret, FIH_FAILURE);

    fih_ret = tfm_fih_random_init();

    if (FIH_NOT_EQ(fih_ret, FIH_SUCCESS))
    {
        FIH_PANIC;
    }

    return 0;
}

#ifdef FIH_ENABLE_DELAY_PLATFORM

int fih_delay_platform(void)
{
    /* Stub implementation */
    return 1;
}

#else

uint8_t fih_delay_random(void)
{
    uint8_t rand_value = 0xFF;

    /* Repeat random generation to mitigate instruction skip */
    tfm_fih_random_generate(&rand_value);
    tfm_fih_random_generate(&rand_value);
    tfm_fih_random_generate(&rand_value);

    return rand_value;
}
#endif /* FIH_ENABLE_DELAY_PLATFORM */
#endif /* FIH_ENABLE_DELAY */