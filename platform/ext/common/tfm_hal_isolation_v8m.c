/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022-2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <arm_cmse.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "array.h"
#include "tfm_hal_device_header.h"
#include "region.h"
#include "armv8m_mpu.h"
#include "common_target_cfg.h"
#include "tfm_hal_defs.h"
#include "tfm_hal_isolation.h"
#include "tfm_peripherals_def.h"
#include "load/spm_load_api.h"

/* Boundary handle binding macros. */
#define HANDLE_ATTR_PRIV_POS            1U
#define HANDLE_ATTR_PRIV_MASK           (0x1UL << HANDLE_ATTR_PRIV_POS)
#define HANDLE_ATTR_NS_POS              0U
#define HANDLE_ATTR_NS_MASK             (0x1UL << HANDLE_ATTR_NS_POS)

#if TFM_ISOLATION_LEVEL == 3
#define HANDLE_ATTR_SPM_POS             2U
#define HANDLE_ATTR_SPM_MASK            (1UL << HANDLE_ATTR_SPM_POS)
#define HANDLE_PER_ATTR_BITS            4U
#define HANDLE_ATTR_RW_POS              (1UL << (HANDLE_PER_ATTR_BITS - 1))
#define HANDLE_ATTR_INDEX_MASK          (HANDLE_ATTR_RW_POS - 1)
#define HANDLE_INDEX_BITS               8U
#define HANDLE_INDEX_MASK               (((1UL << HANDLE_INDEX_BITS) - 1) << 24)
#define HANDLE_ENCODE_INDEX(attr, idx)                 \
    do {                                               \
        (attr) |= (((idx) << 24) & HANDLE_INDEX_MASK); \
        (idx)++;                                       \
    } while (0)

#define PROT_BOUNDARY_VAL \
    (((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK) | \
     ((1U << HANDLE_ATTR_SPM_POS) & HANDLE_ATTR_SPM_MASK))

/* Isolation level 3 needs to reserve at least one MPU region for private data asset. */
#define MIN_NR_PRIVATE_DATA_REGION  1U

static uint32_t idx_boundary_handle = 0;

#else /* TFM_ISOLATION_LEVEL == 3 */
#define PROT_BOUNDARY_VAL \
    ((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK)

/* Isolation level 1&2 do not need to reserve MPU region for private data asset. */
#define MIN_NR_PRIVATE_DATA_REGION  0U
#endif /* TFM_ISOLATION_LEVEL == 3 */

#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT
static uint32_t n_static_regions;

REGION_DECLARE(Image$$, PT_UNPRIV_CODE_START, $$Base);
REGION_DECLARE(Image$$, PT_UNPRIV_CODE_END, $$Base);
REGION_DECLARE(Image$$, PT_APP_ROT_CODE_START, $$Base);
REGION_DECLARE(Image$$, PT_APP_ROT_CODE_END, $$Base);
REGION_DECLARE(Image$$, PT_PSA_ROT_CODE_START, $$Base);
REGION_DECLARE(Image$$, PT_PSA_ROT_CODE_END, $$Base);
REGION_DECLARE(Image$$, PT_RO_DATA_START, $$Base);
REGION_DECLARE(Image$$, PT_RO_DATA_END, $$Base);
#if TFM_ISOLATION_LEVEL != 3
REGION_DECLARE(Image$$, PT_APP_ROT_DATA_START, $$Base);
REGION_DECLARE(Image$$, PT_APP_ROT_DATA_END, $$Base);
#elif defined(CONFIG_TFM_PARTITION_META)
REGION_DECLARE(Image$$, TFM_SP_META_PTR, $$ZI$$Base);
REGION_DECLARE(Image$$, TFM_SP_META_PTR_END, $$ZI$$Limit);
#endif
REGION_DECLARE(Image$$, PT_PSA_ROT_DATA_START, $$Base);
REGION_DECLARE(Image$$, PT_PSA_ROT_DATA_END, $$Base);

#define ARM_MPU_NON_TRANSIENT        ( 1U )
#define ARM_MPU_TRANSIENT            ( 0U )
#define ARM_MPU_WRITE_BACK           ( 1U )
#define ARM_MPU_WRITE_THROUGH        ( 0U )
#define ARM_MPU_READ_ALLOCATE        ( 1U )
#define ARM_MPU_NON_READ_ALLOCATE    ( 0U )
#define ARM_MPU_WRITE_ALLOCATE       ( 1U )
#define ARM_MPU_NON_WRITE_ALLOCATE   ( 0U )
#define ARM_MPU_READ_ONLY            ( 1U )
#define ARM_MPU_READ_WRITE           ( 0U )
#define ARM_MPU_UNPRIVILEGED         ( 1U )
#define ARM_MPU_PRIVILEGED           ( 0U )
#define ARM_MPU_EXECUTE_NEVER        ( 1U )
#define ARM_MPU_EXECUTE_OK           ( 0U )
#define ARM_MPU_PRIVILEGE_EXECUTE_NEVER  ( 1U )
#define ARM_MPU_PRIVILEGE_EXECUTE_OK     ( 0U )

#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_set_up_static_boundaries(uintptr_t *p_spm_boundary)
{
#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT
const ARM_MPU_Region_t mpu_region_attributes[] = {
    /* If PXN is enabled, for higher isolation levels mark ARoT code as PXN.
     * Otherwise, combine unpriv and ARoT code into a single unprivileged MPU
     * region that permits privileged execution.
     */
#if defined(TFM_PXN_ENABLE) && (TFM_ISOLATION_LEVEL > 1)
    /* Unprivileged code region (including veneers if TZ is enabled)
     * Non-shareable, Read-Only, Unprivileged, Executable,
     * Privileged Executable, Attribute set: 0
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_UNPRIV_CODE_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_ONLY,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_OK),
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_UNPRIV_CODE_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_OK,
                         0)
    },
    /* Application RoT code region
     * Non-shareable, Read-Only, Unprivileged, Executable,
     * Privileged Execute Never, Attribute set: 0
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_CODE_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_ONLY,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_OK),
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_CODE_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                         0)
    },
#else /* TFM_PXN_ENABLE && TFM_ISOLATION_LEVEL > 1 */
    /* Combined unprivileged/ARoT code region
     * Non-shareable, Read-Only, Unprivileged, Executable,
     * Privileged Executable - if PXN available, Attribute set: 0
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_UNPRIV_CODE_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_ONLY,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_OK),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_CODE_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_OK,
                         0)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_CODE_END, $$Base) - 1,
                     0)
        #endif
    },
#endif /* TFM_PXN_ENABLE && TFM_ISOLATION_LEVEL > 1 */
    /* PSA RoT code region
     * Non-shareable, Read-Only, Privileged, Executable,
     * Privileged Executable - if PXN available, Attribute set: 0
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_CODE_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_ONLY,
                     ARM_MPU_PRIVILEGED,
                     ARM_MPU_EXECUTE_OK),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_CODE_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_OK,
                         0)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_CODE_END, $$Base) - 1,
                     0)
        #endif
    },
    /* RO data region
     * Non-shareable, Read-Only, Unprivileged, Execute Never,
     * Privileged Execute Never - if PXN available, Attribute set: 0
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_RO_DATA_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_ONLY,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_NEVER),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_RO_DATA_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                         0)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, PT_RO_DATA_END, $$Base) - 1,
                     0)
        #endif
    },
    /* For isolation levels below 3, configure all App RoT data (which includes
     * the metadata pointer region) as unprivileged. For isolation level 3, only
     * the metadata pointer region is configured unprivileged and App RoT
     * partition data regions are dynamically configured during partition
     * scheduling.
     */
#if TFM_ISOLATION_LEVEL != 3
    /* Application RoT data region
     * Non-shareable, Read-Write, Unprivileged, Execute Never
     * Privileged Execute Never - if PXN available, Attribute set: 1
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_DATA_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_WRITE,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_NEVER),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_DATA_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                         1)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, PT_APP_ROT_DATA_END, $$Base) - 1,
                     1)
        #endif
    },
#elif defined(CONFIG_TFM_PARTITION_META)
    /* TFM partition metadata pointer region
     * Non-shareable, Read-Write, Unprivileged, Execute Never
     * Privileged Execute Never - if PXN available, Attribute set: 1
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, TFM_SP_META_PTR, $$ZI$$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_WRITE,
                     ARM_MPU_UNPRIVILEGED,
                     ARM_MPU_EXECUTE_NEVER),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, TFM_SP_META_PTR_END, $$ZI$$Limit) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                         1)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, TFM_SP_META_PTR_END, $$ZI$$Limit) - 1,
                     1)
        #endif
    },
#endif
    /* PSA RoT data region
     * Non-shareable, Read-Write, Privileged, Execute Never
     * Privileged Execute Never - if PXN available, Attribute set: 1
     */
    {
        ARM_MPU_RBAR((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_DATA_START, $$Base),
                     ARM_MPU_SH_NON,
                     ARM_MPU_READ_WRITE,
                     ARM_MPU_PRIVILEGED,
                     ARM_MPU_EXECUTE_NEVER),
        #ifdef TFM_PXN_ENABLE
        ARM_MPU_RLAR_PXN((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_DATA_END, $$Base) - 1,
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                         1)
        #else
        ARM_MPU_RLAR((uint32_t)&REGION_NAME(Image$$, PT_PSA_ROT_DATA_END, $$Base) - 1,
                     1)
        #endif
    },
    /* Individual platforms may add further static MPU regions by defining
     * PLATFORM_STATIC_MPU_REGIONS in their tfm_peripherals_def.h header.
     */
#ifdef PLATFORM_STATIC_MPU_REGIONS
    PLATFORM_STATIC_MPU_REGIONS
#endif
};
#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

    /* Set up isolation boundaries between SPE and NSPE */
    sau_and_idau_cfg();
    if (mpc_init_cfg() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
    if (ppc_init_cfg() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    /* Set up static isolation boundaries inside SPE */
#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT
    uint32_t i;
    const uint32_t mpu_region_num =
        (MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;

    n_static_regions = ARRAY_SIZE(mpu_region_attributes);

    if (n_static_regions + MIN_NR_PRIVATE_DATA_REGION > mpu_region_num) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    /* Turn off MPU during configuration */
    if (MPU->CTRL & MPU_CTRL_ENABLE_Msk) {
        ARM_MPU_Disable();
    }

    /* Configure attribute registers
     * Attr0 : Normal memory, Inner/Outer Cacheable, Write-Through Read-Allocate
     */
    ARM_MPU_SetMemAttr(0,
                   ARM_MPU_ATTR(ARM_MPU_ATTR_MEMORY_(ARM_MPU_NON_TRANSIENT,
                                                     ARM_MPU_WRITE_THROUGH,
                                                     ARM_MPU_READ_ALLOCATE,
                                                     ARM_MPU_NON_WRITE_ALLOCATE),
                                ARM_MPU_ATTR_MEMORY_(ARM_MPU_NON_TRANSIENT,
                                                     ARM_MPU_WRITE_THROUGH,
                                                     ARM_MPU_READ_ALLOCATE,
                                                     ARM_MPU_NON_WRITE_ALLOCATE)));
    /* Attr1 : Normal memory, Inner/Outer Cacheable, Write-Back R-W Allocate */
    ARM_MPU_SetMemAttr(1,
                    ARM_MPU_ATTR(ARM_MPU_ATTR_MEMORY_(ARM_MPU_NON_TRANSIENT,
                                                     ARM_MPU_WRITE_BACK,
                                                     ARM_MPU_READ_ALLOCATE,
                                                     ARM_MPU_WRITE_ALLOCATE),
                                ARM_MPU_ATTR_MEMORY_(ARM_MPU_NON_TRANSIENT,
                                                     ARM_MPU_WRITE_BACK,
                                                     ARM_MPU_READ_ALLOCATE,
                                                     ARM_MPU_WRITE_ALLOCATE)));
    /* Attr2 : Device memory, nGnRE */
    ARM_MPU_SetMemAttr(2,
                       ARM_MPU_ATTR(ARM_MPU_ATTR_DEVICE,
                                    ARM_MPU_ATTR_DEVICE_nGnRE));

    /* Configure regions */
    /* Note: CMSIS MPU API clears the lower 5 address bits without check */
    for (i = 0; i < n_static_regions; i++) {
        ARM_MPU_SetRegion(i, mpu_region_attributes[i].RBAR,
                          mpu_region_attributes[i].RLAR);
    }
    /* Disable unused regions */
    while (i < mpu_region_num) {
        ARM_MPU_ClrRegion(i++);
    }

    /* Enable MPU with the above configurations. Allow default memory map for
     * privileged software and enable MPU during HardFault and NMI handlers.
     */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_HFNMIENA_Msk);
#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

    *p_spm_boundary = (uintptr_t)PROT_BOUNDARY_VAL;

    FIH_RET(TFM_HAL_SUCCESS);
}

/*
 * Implementation of tfm_hal_bind_boundary():
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
 * NOTE: This is a reference implementation for Armv8-M, and has some
 * limitations:
 * 1. The maximum number of allowed MMIO regions is 5 per partition.
 * 2. The valid range of values for MMIO Index is 1 to 7.
 * 3. Highest 8 bits are for index. It supports 256 unique handles at most.
 * 4. Only named MMIO regions are supported. Numbered MMIO regions are ignored.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_bind_boundary(const struct partition_load_info_t *p_ldinf,
                                                          uintptr_t *p_boundary)
{
    bool privileged;
    bool ns_agent_tz;
    uint32_t partition_attrs = 0;
#if CONFIG_TFM_MMIO_REGION_ENABLE == 1
    uint32_t i, j;
    const struct asset_desc_t *p_asset;
    struct platform_data_t *plat_data_ptr;
    const uintptr_t *mmio_list;
    size_t mmio_list_length;
#if TFM_ISOLATION_LEVEL == 2
    ARM_MPU_Region_t local_mpu_region;
    uint32_t mpu_region_num;
#endif /* TFM_ISOLATION_LEVEL == 2 */
#endif /* CONFIG_TFM_MMIO_REGION_ENABLE == 1 */

    if (!p_ldinf || !p_boundary) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

#if TFM_ISOLATION_LEVEL == 1
    privileged = true;
#else
    privileged = IS_PSA_ROT(p_ldinf);
#endif

    ns_agent_tz = IS_NS_AGENT_TZ(p_ldinf);

    /*
     * Validate that the named MMIO of the partition is allowed by the platform.
     * Otherwise, skip validation.
     */
#if CONFIG_TFM_MMIO_REGION_ENABLE == 1
    p_asset = LOAD_INFO_ASSET(p_ldinf);

    get_partition_named_mmio_list(&mmio_list, &mmio_list_length);

    for (i = 0; i < p_ldinf->nassets; i++) {
        if (!(p_asset[i].attr & ASSET_ATTR_NAMED_MMIO)) {
            continue;
        }
        for (j = 0; j < mmio_list_length; j++) {
            if (p_asset[i].dev.dev_ref == mmio_list[j]) {
                break;
            }
        }

        if (j == mmio_list_length) {
            /* The MMIO asset is not in the allowed list of platform. */
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
        /* Assume PPC & MPC settings are required even under level 1 */
        plat_data_ptr = REFERENCE_TO_PTR(p_asset[i].dev.dev_ref,
                                         struct platform_data_t *);

        if (plat_data_ptr->periph_ppc_bank != PPC_SP_DO_NOT_CONFIGURE) {
            ppc_configure_to_secure(plat_data_ptr->periph_ppc_bank,
                                    plat_data_ptr->periph_ppc_mask);
            if (privileged) {
                ppc_clr_secure_unpriv(plat_data_ptr->periph_ppc_bank,
                                      plat_data_ptr->periph_ppc_mask);
            } else {
                ppc_en_secure_unpriv(plat_data_ptr->periph_ppc_bank,
                                     plat_data_ptr->periph_ppc_mask);
            }
        }
#if TFM_ISOLATION_LEVEL == 2
        /*
         * Static boundaries are set. Set up MPU region for MMIO.
         * Setup regions for unprivileged assets only.
         */
        if (!privileged) {
            mpu_region_num =
                (MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;

            /* There is a limited number of available MPU regions in v8M */
            if (mpu_region_num <= n_static_regions) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
            if ((plat_data_ptr->periph_start & ~MPU_RBAR_BASE_Msk) != 0) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
            if ((plat_data_ptr->periph_limit & ~MPU_RLAR_LIMIT_Msk) != 0x1F) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }

            /* Turn off MPU during configuration */
            ARM_MPU_Disable();

            /* Assemble region base and limit address register contents. */
            local_mpu_region.RBAR = ARM_MPU_RBAR(plat_data_ptr->periph_start,
                                                 ARM_MPU_SH_NON,
                                                 ARM_MPU_READ_WRITE,
                                                 ARM_MPU_UNPRIVILEGED,
                                                 ARM_MPU_EXECUTE_NEVER);
            /* Attr2 contains required attribute set for device regions */
            #ifdef TFM_PXN_ENABLE
            local_mpu_region.RLAR = ARM_MPU_RLAR_PXN(plat_data_ptr->periph_limit,
                                                     ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                                                     2);
            #else
            local_mpu_region.RLAR = ARM_MPU_RLAR(plat_data_ptr->periph_limit,
                                                 2);
            #endif

            /* Configure device MPU region */
            ARM_MPU_SetRegion(n_static_regions++,
                              local_mpu_region.RBAR,
                              local_mpu_region.RLAR);

            /* Enable MPU with the new region added */
            ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_HFNMIENA_Msk);
        }
#elif TFM_ISOLATION_LEVEL == 3
        /* MMIO Index is limited to 3 bits */
        if (((j + 1) & HANDLE_ATTR_INDEX_MASK) != j + 1) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
        /* Encode MMIO attributes into the "partition_attrs". */
        partition_attrs |= j + 1;
        if (p_asset[i].attr & ASSET_ATTR_READ_WRITE) {
            partition_attrs |= HANDLE_ATTR_RW_POS;
        }
        partition_attrs <<= HANDLE_PER_ATTR_BITS;
#endif /* TFM_ISOLATION_LEVEL */
    }
#endif /* CONFIG_TFM_MMIO_REGION_ENABLE == 1 */

#if TFM_ISOLATION_LEVEL == 3
    /*
     * Highest 8 bits are reserved for index, if they are non-zero, MMIO numbers
     * must have exceeded the limit of 5.
     */
    if (partition_attrs & HANDLE_INDEX_MASK) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
    HANDLE_ENCODE_INDEX(partition_attrs, idx_boundary_handle);
#endif /* TFM_ISOLATION_LEVEL == 3 */

    partition_attrs |= ((uint32_t)privileged << HANDLE_ATTR_PRIV_POS) &
                        HANDLE_ATTR_PRIV_MASK;
    partition_attrs |= ((uint32_t)ns_agent_tz << HANDLE_ATTR_NS_POS) &
                        HANDLE_ATTR_NS_MASK;
    *p_boundary = (uintptr_t)partition_attrs;

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_activate_boundary(const struct partition_load_info_t *p_ldinf,
                                                              uintptr_t boundary)
{
    CONTROL_Type ctrl;
    uint32_t local_handle = (uint32_t)boundary;
    bool privileged = !!(local_handle & HANDLE_ATTR_PRIV_MASK);
#if TFM_ISOLATION_LEVEL == 3
    bool is_spm = !!(local_handle & HANDLE_ATTR_SPM_MASK);
    ARM_MPU_Region_t local_mpu_region;
    const uint32_t mpu_region_num =
        (MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
    uint32_t i;
    const struct asset_desc_t *rt_mem;
    enum tfm_hal_status_t status = TFM_HAL_SUCCESS;
#if CONFIG_TFM_MMIO_REGION_ENABLE == 1
    uint32_t mmio_index;
    struct platform_data_t *plat_data_ptr;
    const uintptr_t *mmio_list;
    size_t mmio_list_length;
#endif /* CONFIG_TFM_MMIO_REGION_ENABLE == 1 */
#endif /* TFM_ISOLATION_LEVEL == 3 */

    /* Privileged level is required to be set always */
    ctrl.w = __get_CONTROL();
    ctrl.b.nPRIV = privileged ? 0 : 1;
    __set_CONTROL(ctrl.w);

#if TFM_ISOLATION_LEVEL == 3
    if (is_spm) {
        FIH_RET(TFM_HAL_SUCCESS);
    }

    if (!p_ldinf) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    /* Update regions, for unprivileged partitions only */
    if (privileged) {
        FIH_RET(TFM_HAL_SUCCESS);
    }

    /* Turn off MPU during configuration */
    ARM_MPU_Disable();

    /* Setup runtime memory first */
    rt_mem = LOAD_INFO_ASSET(p_ldinf);
    /*
     * NOTE: This implementation relies on the partition load info template
     * ordering the runtime memory asset(s) before the MMIO assets. If more
     * memory assets or numbered MMIO assets with memory regions are added then
     * it needs to be revisited.
     */
    for (i = 0;
         i < p_ldinf->nassets && !(rt_mem[i].attr & ASSET_ATTR_MMIO);
         i++) {
        if ((n_static_regions + i >= mpu_region_num) ||
            ((rt_mem[i].mem.start & ~MPU_RBAR_BASE_Msk) != 0) ||
            (((rt_mem[i].mem.limit - 1) & ~MPU_RLAR_LIMIT_Msk) != 0x1F)) {
            status = TFM_HAL_ERROR_GENERIC;
            goto out;
        }
        /* Assemble region base and limit address register contents. */
        local_mpu_region.RBAR = ARM_MPU_RBAR(rt_mem[i].mem.start,
                                             ARM_MPU_SH_NON,
                                             ARM_MPU_READ_WRITE,
                                             ARM_MPU_UNPRIVILEGED,
                                             ARM_MPU_EXECUTE_NEVER);
        /* Attr1 contains required attribute set for data regions */
        #ifdef TFM_PXN_ENABLE
        local_mpu_region.RLAR = ARM_MPU_RLAR_PXN(rt_mem[i].mem.limit - 1,
                                                 ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                                                 1);
        #else
        local_mpu_region.RLAR = ARM_MPU_RLAR(rt_mem[i].mem.limit - 1,
                                             1);
        #endif

        /* Configure device MPU region */
        ARM_MPU_SetRegion(n_static_regions + i,
                          local_mpu_region.RBAR,
                          local_mpu_region.RLAR);
    }

    i += n_static_regions;

#if CONFIG_TFM_MMIO_REGION_ENABLE == 1
    /* Named MMIO part */
    local_handle &= ~HANDLE_INDEX_MASK;
    local_handle >>= HANDLE_PER_ATTR_BITS;
    mmio_index = local_handle & HANDLE_ATTR_INDEX_MASK;

    get_partition_named_mmio_list(&mmio_list, &mmio_list_length);

    while (mmio_index) {
        if ((i >= mpu_region_num) || (mmio_index > mmio_list_length)) {
            status = TFM_HAL_ERROR_GENERIC;
            goto out;
        }

        plat_data_ptr = (struct platform_data_t *)mmio_list[mmio_index - 1];

        if (((plat_data_ptr->periph_start & ~MPU_RBAR_BASE_Msk) != 0) ||
            ((plat_data_ptr->periph_limit & ~MPU_RLAR_LIMIT_Msk) != 0x1F)) {
            status = TFM_HAL_ERROR_GENERIC;
            goto out;
        }

        /* Assemble region base and limit address register contents. */
        local_mpu_region.RBAR = ARM_MPU_RBAR(plat_data_ptr->periph_start,
                                             ARM_MPU_SH_NON,
                                             (local_handle & HANDLE_ATTR_RW_POS) ?
                                             ARM_MPU_READ_WRITE : ARM_MPU_READ_ONLY,
                                             ARM_MPU_UNPRIVILEGED,
                                             ARM_MPU_EXECUTE_NEVER);
        /* Attr2 contains required attribute set for device regions */
        #ifdef TFM_PXN_ENABLE
        local_mpu_region.RLAR = ARM_MPU_RLAR_PXN(plat_data_ptr->periph_limit,
                                                 ARM_MPU_PRIVILEGE_EXECUTE_NEVER,
                                                 2);
        #else
        local_mpu_region.RLAR = ARM_MPU_RLAR(plat_data_ptr->periph_limit,
                                             2);
        #endif

        /* Configure device MPU region */
        ARM_MPU_SetRegion(i++, local_mpu_region.RBAR, local_mpu_region.RLAR);

        local_handle >>= HANDLE_PER_ATTR_BITS;
        mmio_index = local_handle & HANDLE_ATTR_INDEX_MASK;
    }
#endif /* CONFIG_TFM_MMIO_REGION_ENABLE == 1 */

    /* Disable unused regions */
    while (i < mpu_region_num) {
        ARM_MPU_ClrRegion(i++);
    }

out:
    /* Enable MPU with the new regions added */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_HFNMIENA_Msk);

    FIH_RET(status);
#else /* TFM_ISOLATION_LEVEL == 3 */
    FIH_RET(TFM_HAL_SUCCESS);
#endif /* TFM_ISOLATION_LEVEL == 3 */
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(uintptr_t boundary, uintptr_t base,
                                                         size_t size, uint32_t access_type)
{
    int flags = 0;

    /* If size is zero, this indicates an empty buffer and base is ignored */
    if (size == 0) {
        FIH_RET(TFM_HAL_SUCCESS);
    }

    if (!base) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    if ((access_type & TFM_HAL_ACCESS_READWRITE) == TFM_HAL_ACCESS_READWRITE) {
        flags |= CMSE_MPU_READWRITE;
    } else if (access_type & TFM_HAL_ACCESS_READABLE) {
        flags |= CMSE_MPU_READ;
    } else {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    if (access_type & TFM_HAL_ACCESS_NS) {
        flags |= CMSE_NONSECURE;
    }

    if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK)) {
        flags |= CMSE_MPU_UNPRIV;
    }

    /* This check is only done for ns_agent_tz */
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
        FIH_RET(TFM_HAL_SUCCESS);
    } else {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }
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
