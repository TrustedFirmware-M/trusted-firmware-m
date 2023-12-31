/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ni_tower_apu_drv.h"
#include "ni_tower_apu_reg.h"

#include <stddef.h>

#define NI_TOWER_APU_ADDRESS_GRAN      (1UL << 6)
#define NI_TOWER_APU_ADDRESS_MASK      (~(NI_TOWER_APU_ADDRESS_GRAN - 1))
#define NI_TOWER_APU_ADDRESS_H(addr)   ((addr) >> 32)
#define NI_TOWER_APU_ADDRESS_L(addr)   ((addr) & NI_TOWER_APU_ADDRESS_MASK)

static enum ni_tower_err ni_tower_apu_set_addr_range(
                        struct ni_tower_apu_dev *dev, uint32_t region,
                        uint64_t base_addr, uint64_t end_addr)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    /* Check alignment of base and end addresses */
    if (((base_addr & (NI_TOWER_APU_ADDRESS_GRAN - 1)) != 0) ||
        ((~end_addr & (NI_TOWER_APU_ADDRESS_GRAN - 1)) != 0)) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    /* Set base address */
    reg->region[region].prbar_high = NI_TOWER_APU_ADDRESS_H(base_addr);
    reg->region[region].prbar_low = NI_TOWER_APU_ADDRESS_L(base_addr);
    /* Set end address */
    reg->region[region].prlar_high = NI_TOWER_APU_ADDRESS_H(end_addr);
    reg->region[region].prlar_low = NI_TOWER_APU_ADDRESS_L(end_addr);

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_access_perms(
                            struct ni_tower_apu_dev *dev, uint32_t region,
                            enum ni_tower_apu_access_perm_type permission,
                            enum ni_tower_apu_entity_type id_select)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    switch (id_select) {
    case NI_T_ID_0_SELECT: reg->region[region].prid_low |=
                                    (permission << NI_TOWER_APU_PERM_0_POS) &
                                    NI_TOWER_APU_PERM_0_MSK;
        break;
    case NI_T_ID_1_SELECT: reg->region[region].prid_low |=
                                    (permission << NI_TOWER_APU_PERM_1_POS) &
                                    NI_TOWER_APU_PERM_1_MSK;
        break;
    case NI_T_ID_2_SELECT: reg->region[region].prid_high |=
                                    (permission << NI_TOWER_APU_PERM_2_POS) &
                                    NI_TOWER_APU_PERM_2_MSK;
        break;
    case NI_T_ID_3_SELECT: reg->region[region].prid_high |=
                                    (permission << NI_TOWER_APU_PERM_3_POS) &
                                    NI_TOWER_APU_PERM_3_MSK;
        break;
    default:
        return NI_TOWER_ERR_INVALID_ARG;
    }

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_entity_id(
                                struct ni_tower_apu_dev *dev,
                                uint32_t region, uint32_t id_value,
                                enum ni_tower_apu_entity_type id_select)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    switch (id_select) {
    case NI_T_ID_0_SELECT: reg->region[region].prid_low |=
                                        (id_value << NI_TOWER_APU_ID_0_POS) &
                                        NI_TOWER_APU_ID_0_MSK;
        break;
    case NI_T_ID_1_SELECT: reg->region[region].prid_low |=
                                        (id_value << NI_TOWER_APU_ID_1_POS) &
                                        NI_TOWER_APU_ID_1_MSK;
        break;
    case NI_T_ID_2_SELECT: reg->region[region].prid_high |=
                                        (id_value << NI_TOWER_APU_ID_2_POS) &
                                        NI_TOWER_APU_ID_2_MSK;
        break;
    case NI_T_ID_3_SELECT: reg->region[region].prid_high |=
                                        (id_value << NI_TOWER_APU_ID_3_POS) &
                                        NI_TOWER_APU_ID_3_MSK;
        break;
    default:
        return NI_TOWER_ERR_INVALID_ARG;
    }

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_lock(
                                            struct ni_tower_apu_dev *dev,
                                            uint32_t region,
                                            enum ni_tower_apu_lock_type lock)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->region[region].prbar_low |= (lock << NI_TOWER_APU_LOCK_POS) &
                                   NI_TOWER_APU_LOCK_MSK;

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_br(
                                        struct ni_tower_apu_dev *dev,
                                        uint32_t region,
                                        enum ni_tower_apu_br_type background)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->region[region].prbar_low |= (background << NI_TOWER_APU_BR_POS) &
                                   NI_TOWER_APU_BR_MSK;

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_region_enable(
                            struct ni_tower_apu_dev *dev, uint32_t region)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->region[region].prbar_low |= NI_TOWER_APU_REGION_ENABLE;

    return NI_TOWER_SUCCESS;
}

static enum ni_tower_err ni_tower_apu_set_id_valid(
                                    struct ni_tower_apu_dev *dev,
                                    uint32_t region,
                                    enum ni_tower_apu_entity_valid_type valid)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->region[region].prlar_low |= (valid << NI_TOWER_APU_ID_VALID_POS) &
                                   NI_TOWER_APU_ID_VALID_MSK;

    return NI_TOWER_SUCCESS;
}

enum ni_tower_err ni_tower_apu_enable(struct ni_tower_apu_dev *dev)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->apu_ctlr |= NI_TOWER_APU_CTLR_APU_ENABLE;

    return NI_TOWER_SUCCESS;
}

enum ni_tower_err ni_tower_apu_sync_err_enable(struct ni_tower_apu_dev *dev)
{
    struct ni_tower_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    reg = (struct ni_tower_apu_reg_map*)dev->base;

    reg->apu_ctlr |= NI_TOWER_APU_CTLR_SYNC_ERROR_EN;

    return NI_TOWER_SUCCESS;
}

enum ni_tower_err ni_tower_apu_configure_region(
                            struct ni_tower_apu_dev *dev,
                            const struct ni_tower_apu_reg_cfg_info *cfg_info,
                            uint32_t region)
{
    enum ni_tower_err err;
    uint32_t id_idx;

    if (dev == NULL) {
        return NI_TOWER_ERR_INVALID_ARG;
    }

    err = ni_tower_apu_set_addr_range(dev, region,
                                      cfg_info->base_addr,
                                      cfg_info->end_addr);
    if (err != NI_TOWER_SUCCESS) {
        return err;
    }

    err = ni_tower_apu_set_br(dev, region, cfg_info->background);
    if (err != NI_TOWER_SUCCESS) {
        return err;
    }

    err = ni_tower_apu_set_id_valid(dev, region, cfg_info->id_valid);
    if (err != NI_TOWER_SUCCESS) {
        return err;
    }

    for (id_idx = 0; id_idx < NI_TOWER_APU_NUM_ENTITIES; ++id_idx) {
        err = ni_tower_apu_set_access_perms(dev, region,
                                            cfg_info->permissions[id_idx],
                                            (1 << id_idx));
        if (err != NI_TOWER_SUCCESS) {
            return err;
        }

        err = ni_tower_apu_set_entity_id(dev, region,
                                         cfg_info->entity_ids[id_idx],
                                         (1 << id_idx));
        if (err != NI_TOWER_SUCCESS) {
            return err;
        }
    }

    if (cfg_info->region_enable == NI_T_REGION_ENABLE) {
        err = ni_tower_apu_set_region_enable(dev, region);
        if (err != NI_TOWER_SUCCESS) {
            return err;
        }
    }

    err = ni_tower_apu_set_lock(dev, region, cfg_info->lock);
    if (err != NI_TOWER_SUCCESS) {
        return err;
    }

    return NI_TOWER_SUCCESS;
}
