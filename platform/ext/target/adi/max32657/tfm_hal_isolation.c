/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 * Copyright (C) 2024 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <arm_cmse.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "array.h"
#include "tfm_hal_device_header.h"
#include "Driver_Common.h"
#include "mmio_defs.h"
#include "region.h"
#include "target_cfg.h"
#include "tfm_hal_defs.h"
#include "tfm_hal_isolation.h"
#include "tfm_plat_defs.h"
#include "region_defs.h"
#include "tfm_peripherals_def.h"
#include "load/partition_defs.h"
#include "load/asset_defs.h"
#include "load/spm_load_api.h"

#define PROT_BOUNDARY_VAL \
    ((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK)

enum tfm_hal_status_t tfm_hal_set_up_static_boundaries(
                                            uintptr_t *p_spm_boundary)
{
    /* Set up isolation boundaries between SPE and NSPE */
    sau_and_idau_cfg();
    if (mpc_init_cfg() != ARM_DRIVER_OK) {
        return TFM_HAL_ERROR_GENERIC;
    }

    if (ppc_init_cfg() != ARM_DRIVER_OK) {
        return TFM_HAL_ERROR_GENERIC;
    }

    *p_spm_boundary = (uintptr_t)PROT_BOUNDARY_VAL;

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_FIH_PROFILE_ON
fih_ret tfm_hal_verify_static_boundaries(void)
{
    FIH_RET(TFM_HAL_SUCCESS);
}
#endif

enum tfm_hal_status_t tfm_hal_bind_boundary(
                                    const struct partition_load_info_t *p_ldinf,
                                    uintptr_t *p_boundary)
{
    uint32_t i, j;
    bool privileged;
    bool ns_agent;
    uint32_t partition_attrs = 0;
    const struct asset_desc_t *p_asset;
    struct platform_data_t *plat_data_ptr;

    if (!p_ldinf || !p_boundary) {
        return TFM_HAL_ERROR_GENERIC;
    }

#if TFM_ISOLATION_LEVEL == 1
    privileged = true;
#else
    privileged = IS_PSA_ROT(p_ldinf);
#endif

    ns_agent = IS_NS_AGENT(p_ldinf);
    p_asset = LOAD_INFO_ASSET(p_ldinf);

    /*
     * Validate if the named MMIO of partition is allowed by the platform.
     * Otherwise, skip validation.
     *
     * NOTE: Need to add validation of numbered MMIO if platform requires.
     */
    for (i = 0; i < p_ldinf->nassets; i++) {
        if (!(p_asset[i].attr & ASSET_ATTR_NAMED_MMIO)) {
            continue;
        }
        for (j = 0; j < ARRAY_SIZE(partition_named_mmio_list); j++) {
            if (p_asset[i].dev.dev_ref == partition_named_mmio_list[j]) {
                break;
            }
        }

        if (j == ARRAY_SIZE(partition_named_mmio_list)) {
            /* The MMIO asset is not in the allowed list of platform. */
            return TFM_HAL_ERROR_GENERIC;
        }
        /* Assume PPC & MPC settings are required even under level 1 */
        plat_data_ptr = REFERENCE_TO_PTR(p_asset[i].dev.dev_ref,
                                         struct platform_data_t *);

        if (plat_data_ptr->periph_ppc_bank != PPC_SP_DO_NOT_CONFIGURE) {
            ppc_configure_to_secure(plat_data_ptr->periph_ppc_loc);
            if (privileged) {
                ppc_clr_secure_unpriv(plat_data_ptr->periph_ppc_loc);
            } else {
                ppc_en_secure_unpriv(plat_data_ptr->periph_ppc_loc);
            }
        }
    }

    partition_attrs = ((uint32_t)privileged << HANDLE_ATTR_PRIV_POS) &
                        HANDLE_ATTR_PRIV_MASK;
    partition_attrs |= ((uint32_t)ns_agent << HANDLE_ATTR_NS_POS) &
                        HANDLE_ATTR_NS_MASK;
    *p_boundary = (uintptr_t)partition_attrs;

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_activate_boundary(
                             const struct partition_load_info_t *p_ldinf,
                             uintptr_t boundary)
{
    CONTROL_Type ctrl;
    uint32_t local_handle = (uint32_t)boundary;
    bool privileged = !!(local_handle & HANDLE_ATTR_PRIV_MASK);

    /* Privileged level is required to be set always */
    ctrl.w = __get_CONTROL();
    ctrl.b.nPRIV = privileged ? 0 : 1;
    __set_CONTROL(ctrl.w);

    FIH_RET((TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(uintptr_t boundary, uintptr_t base,
                                           size_t size, uint32_t access_type)
{
    int flags = 0;

    /* If size is zero, this indicates an empty buffer and base is ignored */
    if (size == 0) {
        FIH_RET((TFM_HAL_SUCCESS));
    }

    if (!base) {
        FIH_RET((TFM_HAL_ERROR_INVALID_INPUT));
    }

    if ((access_type & TFM_HAL_ACCESS_READWRITE) == TFM_HAL_ACCESS_READWRITE) {
        flags |= CMSE_MPU_READWRITE;
    } else if (access_type & TFM_HAL_ACCESS_READABLE) {
        flags |= CMSE_MPU_READ;
    } else {
        FIH_RET((TFM_HAL_ERROR_INVALID_INPUT));
    }

    if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK)) {
        flags |= CMSE_MPU_UNPRIV;
    }

    if ((uint32_t)boundary & HANDLE_ATTR_NS_MASK) {
        CONTROL_Type ctrl;
        ctrl.w = __TZ_get_CONTROL_NS();
        if (ctrl.b.nPRIV == 1) {
            flags |= CMSE_MPU_UNPRIV;
        } else {
            flags &= ~CMSE_MPU_UNPRIV;
        }
        flags |= CMSE_NONSECURE;
    }

    if (cmse_check_address_range((void *)base, size, flags) != NULL) {
        FIH_RET((TFM_HAL_SUCCESS));
    } else {
        FIH_RET((TFM_HAL_ERROR_MEM_FAULT));
    }
}

FIH_RET_TYPE(bool) tfm_hal_boundary_need_switch(uintptr_t boundary_from,
                                                uintptr_t boundary_to)
{
    if (boundary_from == boundary_to) {
        FIH_RET((false));
    }

    if (((uint32_t)boundary_from & HANDLE_ATTR_PRIV_MASK) &&
        ((uint32_t)boundary_to & HANDLE_ATTR_PRIV_MASK)) {
        FIH_RET((false));
    }
    FIH_RET((true));
}

#else /* TFM_FIH_PROFILE_ON */

enum tfm_hal_status_t tfm_hal_memory_check(uintptr_t boundary, uintptr_t base,
                                           size_t size, uint32_t access_type)
{
    int flags = 0;

    /* If size is zero, this indicates an empty buffer and base is ignored */
    if (size == 0) {
        return TFM_HAL_SUCCESS;
    }

    if (!base) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if ((access_type & TFM_HAL_ACCESS_READWRITE) == TFM_HAL_ACCESS_READWRITE) {
        flags |= CMSE_MPU_READWRITE;
    } else if (access_type & TFM_HAL_ACCESS_READABLE) {
        flags |= CMSE_MPU_READ;
    } else {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK)) {
        flags |= CMSE_MPU_UNPRIV;
    }

    if ((uint32_t)boundary & HANDLE_ATTR_NS_MASK) {
        CONTROL_Type ctrl;
        ctrl.w = __TZ_get_CONTROL_NS();
        if (ctrl.b.nPRIV == 1) {
            flags |= CMSE_MPU_UNPRIV;
        } else {
            flags &= ~CMSE_MPU_UNPRIV;
        }
        flags |= CMSE_NONSECURE;
    }

    if (cmse_check_address_range((void *)base, size, flags) != NULL) {
        return TFM_HAL_SUCCESS;
    } else {
        return TFM_HAL_ERROR_MEM_FAULT;
    }
}

enum tfm_hal_status_t tfm_hal_activate_boundary(
                             const struct partition_load_info_t *p_ldinf,
                             uintptr_t boundary)
{
    CONTROL_Type ctrl;
    uint32_t local_handle = (uint32_t)boundary;
    bool privileged = !!(local_handle & HANDLE_ATTR_PRIV_MASK);

    /* Privileged level is required to be set always */
    ctrl.w = __get_CONTROL();
    ctrl.b.nPRIV = privileged ? 0 : 1;
    __set_CONTROL(ctrl.w);

    return TFM_HAL_SUCCESS;
}

bool tfm_hal_boundary_need_switch(uintptr_t boundary_from,
                                  uintptr_t boundary_to)
{
    if (boundary_from == boundary_to) {
        return false;
    }

    if (((uint32_t)boundary_from & HANDLE_ATTR_PRIV_MASK) &&
        ((uint32_t)boundary_to & HANDLE_ATTR_PRIV_MASK)) {
        return false;
    }
    return true;
}

#endif /* TFM_FIH_PROFILE_ON */
