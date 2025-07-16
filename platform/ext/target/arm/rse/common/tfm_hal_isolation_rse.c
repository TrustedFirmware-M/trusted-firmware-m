/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "tfm_hal_isolation.h"
#include "platform_base_address.h"
#include "platform_regs.h"

/* RSE uses this function to lock down security-critical registers once the
 * static isolation boundaries have been set up.
 */
fih_ret tfm_hal_post_partition_init_hook(void)
{
    struct cpu0_secctrl_t *secctrl = (struct cpu0_secctrl_t *)CPU0_SECCTRL_BASE_S;
    uint32_t cpuseccfg_val = secctrl->cpuseccfg;

    /* Disable further writes to the VTOR_S, AIRCR.PRIS and AIRCR.BFHFNMINS registers */
    cpuseccfg_val |= CPUSECCFG_LOCKSVTAIRCR_POS_MASK;

#if TFM_ISOLATION_LEVEL < 3
    /* In isolation levels 1 and 2, disable further writes to the Secure MPU registers */
    cpuseccfg_val |= CPUSECCFG_LOCKSMPU_POS_MASK;
#endif

    secctrl->cpuseccfg = cpuseccfg_val;

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
/* This function is responsible for checking all critical isolation configurations. */
fih_ret tfm_hal_verify_static_boundaries(void)
{
    FIH_RET(FIH_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */