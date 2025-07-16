/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_fih_platform.h"
#ifdef RSE_ENABLE_FIH_SW_DELAY
#include "bl1_random.h"
#else
#include "kmu_drv.h"
#include "device_definition.h"
#endif /* RSE_ENABLE_FIH_SW_DELAY */

#ifdef FIH_ENABLE_DELAY
int fih_delay_init(void)
{
    return 0;
}
#ifdef FIH_ENABLE_DELAY_PLATFORM
int fih_delay_platform(void)
{
#ifdef RSE_ENABLE_FIH_SW_DELAY
    uint64_t random;
    volatile uint32_t counter = 0;

    if (bl1_random_generate_fast((uint8_t *)&random, sizeof(random))) {
        FIH_PANIC;
    }

    /* Delays between 0 and 31 cycles to mimic the
     * same delays allowed by the KMU configured above
     */
    while (counter < ((uint32_t)random) & 0x1F) {
        counter++;
    }
#else
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
#endif /* RSE_ENABLE_FIH_SW_DELAY */
    return 1;
}
#endif /* FIH_ENABLE_DELAY_PLATFORM */
#endif /* FIH_ENABLE_DELAY */
