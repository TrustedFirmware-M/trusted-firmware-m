/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ni_tower_psam_drv.h"
#include "ni_tower_psam_reg.h"
#include "util/ni_tower_util.h"

#include <stddef.h>

#define NI_TOWER_PSAM_ADDRESS_GRAN      (1ULL << 12)
#define NI_TOWER_PSAM_ADDRESS_MASK      (~(NI_TOWER_PSAM_ADDRESS_GRAN - 1))
#define NI_TOWER_PSAM_ADDRESS_H(addr)   ((addr) >> 32)
#define NI_TOWER_PSAM_ADDRESS_L(addr)   ((addr) & NI_TOWER_PSAM_ADDRESS_MASK)

#define NI_TOWER_PSAM_GET64_BASE_ADDRESS(addr, high, low)   \
    addr = (((uint64_t)(high) << 32) | (low)) & NI_TOWER_PSAM_ADDRESS_MASK

#define NI_TOWER_PSAM_GET64_END_ADDRESS(addr, high, low)    \
    addr = (((uint64_t)(high) << 32) | (low)) |             \
            (NI_TOWER_PSAM_ADDRESS_GRAN - 1)

enum ni_tower_err ni_tower_psam_configure_nhregion(
                            struct ni_tower_psam_dev *dev,
                            const struct ni_tower_psam_reg_cfg_info *cfg_info,
                            uint32_t region)
{
    struct ni_tower_psam_reg_map* reg;
    uint64_t temp_base_addr, temp_end_addr;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_psam_reg_map*)dev->base;

    if (cfg_info == NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    /* Checking alignment of base and end addresses */
    if (((cfg_info->base_addr & (NI_TOWER_PSAM_ADDRESS_GRAN - 1)) != 0) ||
        ((~cfg_info->end_addr & (NI_TOWER_PSAM_ADDRESS_GRAN - 1)) != 0)) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    /* Disable region */
    reg->nh_region[region].cfg0 &= ~NI_TOWER_NH_REGION_REGION_VALID;

    /* Check whether region overlaps with another valid region */
    for (r_idx = 0; r_idx < NI_TOWER_MAX_NH_REGIONS; ++r_idx) {
        if (reg->nh_region[r_idx].cfg0 & NI_TOWER_NH_REGION_REGION_VALID) {
            NI_TOWER_PSAM_GET64_BASE_ADDRESS(temp_base_addr,
                                             reg->nh_region[r_idx].cfg1,
                                             reg->nh_region[r_idx].cfg0);

            NI_TOWER_PSAM_GET64_END_ADDRESS(temp_end_addr,
                                            reg->nh_region[r_idx].cfg3,
                                            reg->nh_region[r_idx].cfg2);

            if (ni_tower_check_region_overlaps(cfg_info->base_addr,
                    cfg_info->end_addr, temp_base_addr, temp_end_addr) !=
                NI_TOWER_SUCCESS) {
                return NI_TOWER_ERR_REGION_OVERLAPS;
            }
        }
    }

    /* Set base address */
    reg->nh_region[region].cfg0 = NI_TOWER_PSAM_ADDRESS_L(cfg_info->base_addr);
    reg->nh_region[region].cfg1 = NI_TOWER_PSAM_ADDRESS_H(cfg_info->base_addr);
    /* Set end address */
    reg->nh_region[region].cfg2 = NI_TOWER_PSAM_ADDRESS_L(cfg_info->end_addr);
    reg->nh_region[region].cfg3 = NI_TOWER_PSAM_ADDRESS_H(cfg_info->end_addr);
    /* Set ID for the Target interface. */
    reg->nh_region[region].cfg2 |= (cfg_info->target_id &
                                    NI_TOWER_NH_REGION_TGT_ID_MSK);
    /* Set region valid */
    reg->nh_region[region].cfg0 |= NI_TOWER_NH_REGION_REGION_VALID;

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err get_next_available_region(
    struct ni_tower_psam_dev *dev,
    uint32_t *region)
{
    struct ni_tower_psam_reg_map* reg;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_psam_reg_map*)dev->base;

    for (r_idx = 0; r_idx < NI_TOWER_MAX_NH_REGIONS; ++r_idx) {
        if (!(reg->nh_region[r_idx].cfg0 & NI_TOWER_NH_REGION_REGION_VALID)) {
            *region = r_idx;
            return NI_TOWER_SUCCESS;
        }
    }

    return NI_TOWER_ERR;
}

enum ni_tower_err ni_tower_psam_configure_next_available_nhregion(
    struct ni_tower_psam_dev *dev,
    const struct ni_tower_psam_reg_cfg_info *cfg_info)
{
    enum ni_tower_err err;
    uint32_t next_available_region;

    err = get_next_available_region(dev, &next_available_region);
    if (err != NI_TOWER_SUCCESS) {
        return err;
    }

    return ni_tower_psam_configure_nhregion(dev, cfg_info,
            next_available_region);
}

enum ni_tower_err ni_tower_psam_enable(struct ni_tower_psam_dev *dev)
{
    struct ni_tower_psam_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_psam_reg_map*)dev->base;

    reg->sam_status |= NI_TOWER_SAM_STATUS_SETUP_COMPLETE;

    return NI_TOWER_SUCCESS;
}

enum ni_tower_err ni_tower_psam_disable(struct ni_tower_psam_dev *dev)
{
    struct ni_tower_psam_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_psam_reg_map*)dev->base;

    reg->sam_status &= ~NI_TOWER_SAM_STATUS_SETUP_COMPLETE;

    return NI_TOWER_SUCCESS;
}
