/*
 * Copyright (c) 2020-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "internal_status_code.h"
#include "mem_check_v6m_v7m.h"
#include "tfm_hal_defs.h"
#include "tfm_hal_isolation.h"
#include "mpu_config.h"
#include "mmio_defs.h"
#include "flash_layout.h"
#include "region_defs.h"

#define PROT_BOUNDARY_VAL \
    ((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK)
#define MPU_REGION_MIN_SIZE (0x100)

#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT

REGION_DECLARE(Image$$, PT_APP_ROT_DATA_START, $$Base);
REGION_DECLARE(Image$$, PT_APP_ROT_DATA_END, $$Base);

static enum tfm_hal_status_t configure_mpu(uint32_t rnr, uint32_t base,
                          uint32_t limit, uint32_t is_xn_exec, uint32_t ap_permissions)
{
    uint32_t rbar_size_field; /* region size as it is used in the RBAR */
    uint32_t rasr; /* region attribute and size register */
    uint32_t rbar; /* region base address register */

    rbar_size_field = get_rbar_size_field(limit - base);

    /* The MPU region's base address has to be aligned to the region
     * size for a valid MPU configuration */
    if ((base % (1 << (rbar_size_field + 1))) != 0) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* The MPU supports only 8 memory regions */
    if (rnr > 7) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* The minimum size for a region is 0x100 bytes */
    if((limit - base) < MPU_REGION_MIN_SIZE) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    rasr = ARM_MPU_RASR(is_xn_exec, ap_permissions, TEX, NOT_SHAREABLE,
            NOT_CACHEABLE, NOT_BUFFERABLE, SUB_REGION_DISABLE, rbar_size_field);
    rbar = base & MPU_RBAR_ADDR_Msk;

    ARM_MPU_SetRegionEx(rnr, rbar, rasr);

    return TFM_HAL_SUCCESS;
}

#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_set_up_static_boundaries(
                                            uintptr_t *p_spm_boundary)
{
#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT
    uint32_t rnr = TFM_ISOLATION_REGION_START_NUMBER; /* current region number */
    uint32_t base; /* start address */
    uint32_t limit; /* end address */
    enum tfm_hal_status_t ret;

    ARM_MPU_Disable();

    /* Armv6-M MPU allows region overlapping. The region with the higher RNR
     * will decide the attributes.
     *
     * The default attributes are set to XN_EXEC_OK and AP_RO_PRIV_UNPRIV for the
     * whole SRAM so the PT_UNPRIV_CODE, PT_APP_ROT_CODE and PT_PSA_ROT_CODE
     * don't have to be aligned and memory space can be saved.
     * This region has the lowest RNR so the next regions can overwrite these
     * attributes if it's needed.
     */
    base = SRAM_BASE;
    limit = SRAM_BASE + SRAM_SIZE;

    ret = configure_mpu(rnr++, base, limit,
                            XN_EXEC_OK, AP_RO_PRIV_UNPRIV);
    if (ret != TFM_HAL_SUCCESS) {
        FIH_RET(ret);
    }

    /* Set the RAM attributes. It is needed because the first region overlaps the whole
     * SRAM and it has to be overridden.
     * The RAM_MPU_REGION_BLOCK_1_SIZE and RAM_MPU_REGION_BLOCK_2_SIZE are calculated manually
     * and added to the platform_region_defs compile definitions.
     */
    base = S_DATA_START;
    limit = S_DATA_START + RAM_MPU_REGION_BLOCK_1_SIZE;
    ret = configure_mpu(rnr++, base, limit,
                            XN_EXEC_NOT_OK, AP_RW_PRIV_ONLY);
    if (ret != TFM_HAL_SUCCESS) {
        FIH_RET(ret);
    }

    base = S_DATA_START + RAM_MPU_REGION_BLOCK_1_SIZE;
    limit = S_DATA_START + RAM_MPU_REGION_BLOCK_1_SIZE + RAM_MPU_REGION_BLOCK_2_SIZE;
    ret = configure_mpu(rnr++, base, limit,
                            XN_EXEC_NOT_OK, AP_RW_PRIV_ONLY);
    if (ret != TFM_HAL_SUCCESS) {
        FIH_RET(ret);
    }

    /*
     * Application-RoT data region containing the metadata pointer and partition
     * RW data, ZI data and stacks.
     */
    base = (uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_DATA_START, $$Base);
    limit = (uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_DATA_END, $$Base);

    /* The section size can be bigger than the alignment size, else the code would
     * not fit into the memory. Because of this, the sections can use multiple MPU
     * regions. */
    do {
        ret = configure_mpu(rnr++, base, base + TFM_LINKER_PT_APP_ROT_DATA_ALIGNMENT,
                                XN_EXEC_NOT_OK, AP_RW_PRIV_UNPRIV);
        if (ret != TFM_HAL_SUCCESS) {
            FIH_RET(ret);
        }
        base += TFM_LINKER_PT_APP_ROT_DATA_ALIGNMENT;
    } while (base < limit);

    arm_mpu_enable();

#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

    *p_spm_boundary = (uintptr_t)PROT_BOUNDARY_VAL;

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(uintptr_t boundary,
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
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    if (access_type & TFM_HAL_ACCESS_NS) {
        flags |= MEM_CHECK_NONSECURE;
    }

    if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK)) {
        flags |= MEM_CHECK_MPU_UNPRIV;
    }

    if ((uint32_t)boundary & HANDLE_ATTR_NS_MASK) {
        flags |= MEM_CHECK_NONSECURE;
    }

    status = tfm_has_access_to_region((const void *)base, size, flags);
    if (status != SPM_SUCCESS) {
         FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

/*
 * Implementation of tfm_hal_bind_boundary() on Corstone1000:
 *
 * The API encodes some attributes into a handle and returns it to SPM.
 * The attributes include isolation boundaries, privilege, and MMIO information.
 * When scheduler switches running partitions, SPM compares the handle between
 * partitions to know if boundary update is necessary. If update is required,
 * SPM passes the handle to platform to do platform settings and update
 * isolation boundaries.
 *
 * The handle should be unique under isolation level 3. The implementation
 * encodes an index at the highest 8 bits to assure handle uniqueness. While
 * under isolation level 1/2, handles may not be unique.
 *
 * The encoding format assignment:
 * - For isolation level 3
 *      BIT | 31        24 | 23         20 | ... | 7           4 | 3       0 |
 *          | Unique Index | Region Attr 5 | ... | Region Attr 1 | Base Attr |
 *
 *      In which the "Region Attr i" is:
 *      BIT |       3      | 2        0 |
 *          | 1: RW, 0: RO | MMIO Index |
 *
 *      In which the "Base Attr" is:
 *      BIT |               1                |                           0                     |
 *          | 1: privileged, 0: unprivileged | 1: Trustzone-specific NSPE, 0: Secure partition |
 *
 * - For isolation level 1/2
 *      BIT | 31     2 |              1                |                           0                     |
 *          | Reserved |1: privileged, 0: unprivileged | 1: Trustzone-specific NSPE, 0: Secure partition |
 *
 * This is a reference implementation on Corstone1000, and may have some limitations.
 * 1. The maximum number of allowed MMIO regions is 5.
 * 2. Highest 8 bits are for index. It supports 256 unique handles at most.
 *
 */

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_bind_boundary(
                                    const struct partition_load_info_t *p_ldinf,
                                    uintptr_t *p_boundary)
{
    bool privileged;
    bool ns_agent;
    uint32_t partition_attrs = 0;

    if (!p_ldinf || !p_boundary) {
        return TFM_HAL_ERROR_GENERIC;
    }

#if TFM_ISOLATION_LEVEL == 1
    privileged = true;
#else
    privileged = IS_PSA_ROT(p_ldinf);
#endif

    ns_agent = IS_NS_AGENT_TZ(p_ldinf);
    partition_attrs = ((uint32_t)privileged << HANDLE_ATTR_PRIV_POS) &
                        HANDLE_ATTR_PRIV_MASK;
    partition_attrs |= ((uint32_t)ns_agent << HANDLE_ATTR_NS_POS) &
                        HANDLE_ATTR_NS_MASK;
    *p_boundary = (uintptr_t)partition_attrs;

    /* NOTE: Need to add validation of numbered MMIO if platform requires. */
    /* Platform does not have a need for MMIO yet. */

    FIH_RET(TFM_HAL_SUCCESS);
}

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

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(bool) tfm_hal_boundary_need_switch(uintptr_t boundary_from,
                                  uintptr_t boundary_to)
{
    if (boundary_from == boundary_to) {
        FIH_RET(false);
    }

    if (((uint32_t)boundary_from & HANDLE_ATTR_PRIV_MASK) &&
        ((uint32_t)boundary_to & HANDLE_ATTR_PRIV_MASK)) {
        FIH_RET(false);
    }
    FIH_RET(true);
}

#ifdef TFM_FIH_PROFILE_ON
fih_ret tfm_hal_verify_static_boundaries(void)
{
    FIH_RET(TFM_HAL_SUCCESS);
}
#endif