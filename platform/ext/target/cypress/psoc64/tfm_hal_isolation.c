/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_utils.h"
#include "cy_device.h"
#include "mmio_defs.h"
#include "internal_status_code.h"
#include "mem_check_v6m_v7m.h"
#include "target_cfg.h"
#include "tfm_hal_defs.h"
#include "tfm_plat_defs.h"
#include "tfm_peripherals_def.h"
#include "load/asset_defs.h"
#include "load/spm_load_api.h"
#include "tfm_hal_isolation.h"

#define PROT_BOUNDARY_VAL \
    ((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK)

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_set_up_static_boundaries(
                                            uintptr_t *p_spm_boundary)
{
    Cy_PDL_Init(CY_DEVICE_CFG);

    if (smpu_init_cfg() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    if (ppu_init_cfg() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    if (bus_masters_cfg() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    *p_spm_boundary = (uintptr_t)PROT_BOUNDARY_VAL;

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(
                                           uintptr_t boundary,
                                           uintptr_t base,
                                           size_t size,
                                           uint32_t access_type)
{
    int32_t status;
    uint32_t flags = 0;

    if ((access_type & TFM_HAL_ACCESS_READWRITE) == TFM_HAL_ACCESS_READWRITE) {
        flags |= MEM_CHECK_MPU_READWRITE;
    } else if (access_type & TFM_HAL_ACCESS_READABLE) {
        flags |= MEM_CHECK_MPU_READ;
    } else {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_INVALID_INPUT));
    }

    if (access_type & TFM_HAL_ACCESS_NS) {
        flags |= MEM_CHECK_NONSECURE;
    }

    if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK)) {
        flags |= MEM_CHECK_MPU_UNPRIV;
    }

    if ((uint32_t)boundary & HANDLE_ATTR_NS_MASK) {
        tfm_core_panic();
    }

    status = tfm_has_access_to_region((const void *)base, size, flags);
    if (status != SPM_SUCCESS) {
         FIH_RET(fih_int_encode(TFM_HAL_ERROR_MEM_FAULT));
    }

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

/*
 * Implementation of tfm_hal_bind_boundary() on PSOC64:
 *
 * The API encodes some attributes into a handle and returns it to SPM.
 * The attributes include isolation boundaries, privilege, and MMIO information.
 * When scheduler switches running partitions, SPM compares the handle between
 * partitions to know if boundary update is necessary. If update is required,
 * SPM passes the handle to platform to do platform settings and update
 * isolation boundaries.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_bind_boundary(
                                    const struct partition_load_info_t *p_ldinf,
                                    uintptr_t *p_boundary)
{
    uint32_t i, j;
    bool privileged;
    uint32_t partition_attrs = 0;
    const struct asset_desc_t *p_asset;

    if (!p_ldinf || !p_boundary) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

#if TFM_ISOLATION_LEVEL == 1
    privileged = true;
#else
    privileged = IS_PSA_ROT(p_ldinf);
#endif

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
            FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
        }
    }
    partition_attrs = ((uint32_t)privileged << HANDLE_ATTR_PRIV_POS) &
                        HANDLE_ATTR_PRIV_MASK;
    *p_boundary = (uintptr_t)partition_attrs;

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_activate_boundary(
                             const struct partition_load_info_t *p_ldinf,
                             uintptr_t boundary)
{
    CONTROL_Type ctrl;
    bool privileged = !!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK);

    /* Privileged level is required to be set always */
    ctrl.w = __get_CONTROL();
    ctrl.b.nPRIV = privileged ? 0 : 1;
    __set_CONTROL(ctrl.w);

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(bool) tfm_hal_boundary_need_switch(uintptr_t boundary_from,
                                                uintptr_t boundary_to)
{
    if (boundary_from == boundary_to) {
        FIH_RET(fih_int_encode(false));
    }

    if (((uint32_t)boundary_from & HANDLE_ATTR_PRIV_MASK) &&
        ((uint32_t)boundary_to & HANDLE_ATTR_PRIV_MASK)) {
        FIH_RET(fih_int_encode(false));
    }
    FIH_RET(fih_int_encode(true));
}
