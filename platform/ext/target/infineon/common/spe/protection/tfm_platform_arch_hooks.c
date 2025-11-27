/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "tfm_platform_arch_hooks.h"
#include "spm.h"
#include "protection_regions_cfg.h"

static fih_int ifx_arch_get_partition_protection_context(const struct partition_t *partition,
                                                         uint32_t exc_return)
{
    uintptr_t boundary = partition->boundary;
    const ifx_partition_info_t *p_info = (const ifx_partition_info_t *)boundary;

    fih_int protection_context = FIH_INVALID_VALUE;
    if ((exc_return & EXC_RETURN_S) != 0U) {
        protection_context = p_info->ifx_ldinfo->secure_pc;
    } else {
        protection_context = p_info->ifx_ldinfo->non_secure_pc;
    }

    fih_int_validate(protection_context);
    (void)fih_delay();

    return protection_context;
}

ifx_aapcs_fih_int ifx_arch_get_context_protection_context(const struct context_ctrl_t *prev_ctx,
                                                          const struct context_ctrl_t *cur_ctx,
                                                          uint32_t exc_return)
{
    const struct partition_t *partition = GET_CTX_OWNER(cur_ctx);
    return ifx_fih_to_aapcs_fih(ifx_arch_get_partition_protection_context(partition, exc_return));
}

ifx_aapcs_fih_int ifx_arch_get_current_component_protection_context(uint32_t exc_return)
{
    const struct partition_t *partition = GET_CURRENT_COMPONENT();
    return ifx_fih_to_aapcs_fih(ifx_arch_get_partition_protection_context(partition, exc_return));
}
