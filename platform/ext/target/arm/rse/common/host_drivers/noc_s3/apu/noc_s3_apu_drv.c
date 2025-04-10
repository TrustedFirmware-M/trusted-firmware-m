/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "discovery/noc_s3_discovery_drv.h"
#include "noc_s3_apu_drv.h"
#include "noc_s3_apu_reg.h"
#include "util/noc_s3_util.h"

#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#define NOC_S3_APU_ADDRESS_GRAN      (1ULL << 6)
#define NOC_S3_APU_ADDRESS_MASK      (~(NOC_S3_APU_ADDRESS_GRAN - 1))
#define NOC_S3_APU_ADDRESS_H(addr)   ((addr) >> 32)
#define NOC_S3_APU_ADDRESS_L(addr)   ((addr) & NOC_S3_APU_ADDRESS_MASK)

#define NOC_S3_APU_GET64_BASE_ADDRESS(high, low)    \
    (((uint64_t)(high) << 32) | (low)) & NOC_S3_APU_ADDRESS_MASK

#define NOC_S3_APU_GET64_END_ADDRESS(high, low)     \
    (((uint64_t)(high) << 32) | (low)) | (NOC_S3_APU_ADDRESS_GRAN-1) | 0xFFF

static uint64_t noc_s3_apu_get_base_address(
                    const struct noc_s3_apu_reg_map* reg, uint32_t region)
{
    return NOC_S3_APU_GET64_BASE_ADDRESS(reg->region[region].prbar_high,
                                         reg->region[region].prbar_low);
}

static uint64_t noc_s3_apu_get_end_address(
                    const struct noc_s3_apu_reg_map* reg, uint32_t region)
{
    return NOC_S3_APU_GET64_END_ADDRESS(reg->region[region].prbar_high,
                                        reg->region[region].prbar_low);
}

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
/*
 * Example pretty print log for a configured APU
 *
 *        APU configuration for APP_AMNI
 *        ------------------------------
 *        00:[0x000000005 - 0x13ffff000] - Foreground [LOCKED]
 *              <overall> : ALL_PERM
 *        04:[0x180000005 - 0x1bffff00f] - Foreground [NOT LOCKED]
 *              Entity 0 [valid]: <none>
 *              Entity 1 [valid]: SEC_RW
 *              Entity 2 [valid]: N_SEC_RW
 *              Entity 3 [valid]: <none>
 *        01:[0x200000005 - 0x23ffff00f] - Foreground [LOCKED]
 *              <default> : ROOT_RW
 *              Entity 0 [valid]: <default>
 *              Entity 1 [valid]: ALL_PERM
 *              Entity 2 [valid]: <default>
 *              Entity 3 [not valid]: <none>
 *        03:[0x280000005 - 0x284fff000] - Background [LOCKED]
 *              <overall> : ALL_PERM
 *        02:[0x285b00005 - 0x285b0f000] - Foreground [LOCKED]
 *              <overall> : SEC_RW | ROOT_RW
 *
 *
 * APU log format:
 *        XX:[Y - Z]: B [L]
 *              <T> : _PERM_
 *              Entity E [V]: P
 *  , where
 *    1. XX : region index at where memory protection is configured.
 *    2. [Y - Z] : base and end address of the memory to be protected.
 *    3. B : specifies whether the region is Background or Foreground.
 *    4. L : specifies whether the region is locked or not.
 *    5. T : <overall> if no ID based filtering. All entities share overall
 *           permission,
 *           <default> if a default permission is available to be used.
 *    6. _PERM_ : Or'ed permission list
 *    7. E : Entity ID if ID based filtering is enabled.
 *    8. V : specified if an entity ID is valid or not.
 *    9. P : <none> if no protection enabled to that entity.
 *           <default> if default permission is used.
 *           Can also be Or'ed permission list specific to that entity.
 *
 */

static void noc_s3_print_apu_permission(uint32_t permission)
{
    bool perm_printed;
    int check;

    enum {
        WRITE_PERM = 0b001,
        READ_PERM  = 0b100,
        PERM_MASK  = 0b111,
    };

    struct {
        char *str;
        uint8_t mask_pos;
    } perm_label[] = {{"N_SEC", 0}, {"SEC", 1}, {"REALM", 4}, {"ROOT", 5}};

    perm_printed = false;
    permission &= NOC_S3_ALL_PERM;

    if (permission == 0) {
        NOC_S3_DRV_LOG("<none>");
        return;
    }

    if (permission == NOC_S3_ALL_PERM) {
        NOC_S3_DRV_LOG("ALL_PERM");
        return;
    }

    for (int p_t = 0; p_t < ARRAY_SIZE(perm_label); ++p_t) {
        check = (permission >> perm_label[p_t].mask_pos) & PERM_MASK;

        if (check & (READ_PERM | WRITE_PERM)) {
            NOC_S3_DRV_LOG("%s%s_%s%s", (perm_printed) ? " | " : "",
                    perm_label[p_t].str,
                    (check & READ_PERM) ? "R" : "",
                    (check & WRITE_PERM) ? "W" : "");
            perm_printed = true;
        }
    }

    return;
}

static void noc_s3_print_apu_region(const struct noc_s3_apu_reg_map* reg,
                                    uint32_t region)
{
    uint32_t permission[NOC_S3_APU_NUM_ENTITIES];
    uint32_t id[NOC_S3_APU_NUM_ENTITIES];
    uint32_t id_idx;
    uint64_t base, end;
    bool has_default;

    has_default = false;
    base = noc_s3_apu_get_base_address(reg, region);
    end = noc_s3_apu_get_end_address(reg, region);

    NOC_S3_DRV_LOG("\r\n%02d:[0x%lx%08lx - 0x%lx%08lx] - %s %s",
            region,
            (uint32_t)(base >> 32), (uint32_t)(base),
            (uint32_t)(end >> 32), (uint32_t)(end),
            (reg->region[region].prbar_low &
                NOC_S3_APU_BR_MSK) ? "Background" : "Foreground",
            (reg->region[region].prbar_low &
                NOC_S3_APU_LOCK_MSK) ? "[LOCKED]" : "[NOT LOCKED]");

    for (id_idx = 0; id_idx < NOC_S3_APU_NUM_ENTITIES; ++id_idx) {
        switch (1 << id_idx) {
        case NOC_S3_ID_0_SELECT:
            permission[0] = (reg->region[region].prid_low &
                    NOC_S3_APU_PERM_0_MSK) >> NOC_S3_APU_PERM_0_POS;
            id[0] = (reg->region[region].prid_low &
                    NOC_S3_APU_ID_0_MSK) >> NOC_S3_APU_ID_0_POS;
            break;
        case NOC_S3_ID_1_SELECT:
            permission[1] = (reg->region[region].prid_low &
                    NOC_S3_APU_PERM_1_MSK) >> NOC_S3_APU_PERM_1_POS;
            id[1] = (reg->region[region].prid_low &
                    NOC_S3_APU_ID_1_MSK) >> NOC_S3_APU_ID_1_POS;
            break;
        case NOC_S3_ID_2_SELECT:
            permission[2] = (reg->region[region].prid_high &
                    NOC_S3_APU_PERM_2_MSK) >> NOC_S3_APU_PERM_2_POS;
            id[2] = (reg->region[region].prid_high &
                    NOC_S3_APU_ID_2_MSK) >> NOC_S3_APU_ID_2_POS;
            break;
        case NOC_S3_ID_3_SELECT:
            permission[3] = (reg->region[region].prid_high &
                    NOC_S3_APU_PERM_3_MSK) >> NOC_S3_APU_PERM_3_POS;
            id[3] = (reg->region[region].prid_high &
                    NOC_S3_APU_ID_3_MSK) >> NOC_S3_APU_ID_3_POS;
            break;
        }
    }

    if ((id[0] == 0) && (id[1] == 0) && (id[2] == 0) && (id[3] == 0)) {
        NOC_S3_DRV_LOG("\r\n      <overall> : ");
        noc_s3_print_apu_permission(permission[0] | permission[1] |
                                      permission[2] | permission[3]);
        return;
    }

    if (id[0] == 0) {
        NOC_S3_DRV_LOG("\r\n      <default> : ");
        noc_s3_print_apu_permission(permission[0]);
        has_default = true;
    }

    for (id_idx = 0; id_idx < NOC_S3_APU_NUM_ENTITIES; ++id_idx) {
        NOC_S3_DRV_LOG("\r\n      Entity %d [%s]: ", id_idx,
            ((reg->region[region].prlar_low & NOC_S3_APU_ID_VALID_MSK) >>
                NOC_S3_APU_ID_VALID_POS) & (1 << id_idx) ?
                "valid" : "not valid");
        if ((id[id_idx] == 0) && has_default) {
            NOC_S3_DRV_LOG("<default>");
        } else {
            noc_s3_print_apu_permission(permission[id_idx]);
        }
    }
}

static enum noc_s3_err noc_s3_print_apu_config(
    const struct noc_s3_apu_dev *dev)
{
    const char *node_label;
    enum noc_s3_err err;
    struct noc_s3_apu_reg_map* reg;
    struct noc_s3_sorted_region_data sorted_buffer[NOC_S3_MAX_APU_REGIONS];
    struct noc_s3_sorted_region_list list = {
            .sorted_regions = sorted_buffer,
            .sorted_region_count = 0,
            .sorted_region_max = NOC_S3_MAX_APU_REGIONS,
        };
    uint32_t r_idx, region;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    if (dev->data.noc_s3_dev == NULL || dev->data.component == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (noc_s3_type_is_xSNI(dev->data.component->type)) {
        if (dev->data.noc_s3_dev->get_xSNI_label == NULL)
            return NOC_S3_ERR_INVALID_ARG;
        node_label = dev->data.noc_s3_dev->get_xSNI_label(
                        dev->data.component->id);
    } else {
        if (dev->data.noc_s3_dev->get_xMNI_label == NULL)
            return NOC_S3_ERR_INVALID_ARG;
        node_label = dev->data.noc_s3_dev->get_xMNI_label(
                        dev->data.component->id);
    }

    if (node_label == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    NOC_S3_DRV_LOG_HEADING("APU configuration for %s", node_label);

    for (region = 0; region < NOC_S3_MAX_APU_REGIONS; ++region) {
        if (reg->region[region].prbar_low & NOC_S3_APU_REGION_ENABLE) {
            err = noc_s3_sorted_add_entry(&list, region,
                    noc_s3_apu_get_base_address(reg, region));
            if (err != NOC_S3_SUCCESS) {
                return err;
            }
        }
    }

    for (r_idx = 0; r_idx < list.sorted_region_count; ++r_idx) {
        noc_s3_print_apu_region((struct noc_s3_apu_reg_map *)dev->base,
            list.sorted_regions[r_idx].region_idx);
    }

    NOC_S3_DRV_LOG("\r\n");

    return NOC_S3_SUCCESS;
}
#endif

static enum noc_s3_err noc_s3_apu_set_addr_range(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region,
    uint64_t base_addr,
    uint64_t end_addr)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    base_addr += dev->region_mapping_offset;
    end_addr += dev->region_mapping_offset;

    /* Check alignment of base and end addresses */
    if (((base_addr & (NOC_S3_APU_ADDRESS_GRAN - 1)) != 0) ||
        ((~end_addr & (NOC_S3_APU_ADDRESS_GRAN - 1)) != 0)) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    /* Set base address */
    reg->region[region].prbar_high = NOC_S3_APU_ADDRESS_H(base_addr);
    reg->region[region].prbar_low = NOC_S3_APU_ADDRESS_L(base_addr);
    /* Set end address */
    reg->region[region].prlar_high = NOC_S3_APU_ADDRESS_H(end_addr);
    reg->region[region].prlar_low = NOC_S3_APU_ADDRESS_L(end_addr);

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_access_perms(
    const struct noc_s3_apu_dev *dev, uint32_t region,
    const enum noc_s3_apu_access_perm_type permission,
    const enum noc_s3_apu_entity_type id_select)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    switch (id_select) {
    case NOC_S3_ID_0_SELECT:
        /* Clear permission */
        reg->region[region].prid_low &= ~NOC_S3_APU_PERM_0_MSK;
        /* Set permission */
        reg->region[region].prid_low |=
            (permission << NOC_S3_APU_PERM_0_POS) & NOC_S3_APU_PERM_0_MSK;
        break;
    case NOC_S3_ID_1_SELECT:
        /* Clear permission */
        reg->region[region].prid_low &= ~NOC_S3_APU_PERM_1_MSK;
        /* Set permission */
        reg->region[region].prid_low |=
            (permission << NOC_S3_APU_PERM_1_POS) & NOC_S3_APU_PERM_1_MSK;
        break;
    case NOC_S3_ID_2_SELECT:
        /* Clear permission */
        reg->region[region].prid_high &= ~NOC_S3_APU_PERM_2_MSK;
        /* Set permission */
        reg->region[region].prid_high |=
            (permission << NOC_S3_APU_PERM_2_POS) & NOC_S3_APU_PERM_2_MSK;
        break;
    case NOC_S3_ID_3_SELECT:
        /* Clear permission */
        reg->region[region].prid_high &= ~NOC_S3_APU_PERM_3_MSK;
        /* Set permission */
        reg->region[region].prid_high |=
            (permission << NOC_S3_APU_PERM_3_POS) & NOC_S3_APU_PERM_3_MSK;
        break;
    default:
        return NOC_S3_ERR_INVALID_ARG;
    }

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_entity_id(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region,
    const uint32_t id_value,
    const enum noc_s3_apu_entity_type id_select)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    switch (id_select) {
    case NOC_S3_ID_0_SELECT:
        /* Clear apu id */
        reg->region[region].prid_low &= ~NOC_S3_APU_ID_0_MSK;
        /* Set apu id */
        reg->region[region].prid_low |=
            (id_value << NOC_S3_APU_ID_0_POS) & NOC_S3_APU_ID_0_MSK;
        break;
    case NOC_S3_ID_1_SELECT:
        /* Clear apu id */
        reg->region[region].prid_low &= ~NOC_S3_APU_ID_1_MSK;
        /* Set apu id */
        reg->region[region].prid_low |=
            (id_value << NOC_S3_APU_ID_1_POS) & NOC_S3_APU_ID_1_MSK;
        break;
    case NOC_S3_ID_2_SELECT:
        /* Clear apu id */
        reg->region[region].prid_high &= ~NOC_S3_APU_ID_2_MSK;
        /* Set apu id */
        reg->region[region].prid_high |=
            (id_value << NOC_S3_APU_ID_2_POS) & NOC_S3_APU_ID_2_MSK;
        break;
    case NOC_S3_ID_3_SELECT:
        /* Clear apu id */
        reg->region[region].prid_high &= ~NOC_S3_APU_ID_3_MSK;
        /* Set apu id */
        reg->region[region].prid_high |=
            (id_value << NOC_S3_APU_ID_3_POS) & NOC_S3_APU_ID_3_MSK;
        break;
    default:
        return NOC_S3_ERR_INVALID_ARG;
    }

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_lock(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region,
    const enum noc_s3_apu_lock_type lock)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /* Once locked, the region cannot be unlocked unless APU is reset again. */
    reg->region[region].prbar_low |= (lock << NOC_S3_APU_LOCK_POS) &
                                   NOC_S3_APU_LOCK_MSK;

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_br(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region,
    const enum noc_s3_apu_br_type background)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /* Clear background bit */
    reg->region[region].prbar_low &= ~NOC_S3_APU_BR_MSK;
    /* Set background bit */
    reg->region[region].prbar_low |= (background << NOC_S3_APU_BR_POS) &
                                   NOC_S3_APU_BR_MSK;

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_region_enable(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region)
{
    enum noc_s3_apu_br_type temp_br_type, curr_br_type;
    struct noc_s3_apu_reg_map* reg;
    uint64_t temp_base_addr, temp_end_addr, curr_base_addr, curr_end_addr;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /* Clear apu region enable bit */
    reg->region[region].prbar_low &= ~NOC_S3_APU_REGION_ENABLE_MSK;

    /*
     * Check whether two foreground or two background region overlaps.
     * Foreground region can overlap two different background region, APU
     * prioritises the foreground access permissions.
     */
    curr_br_type = reg->region[region].prbar_low & NOC_S3_APU_BR_MSK ?
                                        NOC_S3_BACKGROUND : NOC_S3_FOREGROUND;

    curr_base_addr = noc_s3_apu_get_base_address(reg, region);
    curr_end_addr = noc_s3_apu_get_end_address(reg, region);

    for (r_idx = 0; r_idx < NOC_S3_MAX_APU_REGIONS; ++r_idx) {
        temp_br_type = reg->region[r_idx].prbar_low & NOC_S3_APU_BR_MSK ?
                                        NOC_S3_BACKGROUND : NOC_S3_FOREGROUND;
        if ((reg->region[r_idx].prbar_low & NOC_S3_APU_REGION_ENABLE) &&
            (temp_br_type == curr_br_type))
        {
            temp_base_addr = noc_s3_apu_get_base_address(reg, r_idx);
            temp_end_addr = noc_s3_apu_get_end_address(reg, r_idx);

            if (noc_s3_check_region_overlaps(curr_base_addr, curr_end_addr,
                    temp_base_addr, temp_end_addr) !=
                NOC_S3_SUCCESS) {
                return NOC_S3_ERR_REGION_OVERLAPS;
            }
        }
    }

    /* Set apu region enable bit */
    reg->region[region].prbar_low |= NOC_S3_APU_REGION_ENABLE;

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err noc_s3_apu_set_id_valid(
    const struct noc_s3_apu_dev *dev,
    const uint32_t region,
    const enum noc_s3_apu_entity_valid_type valid)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /* Clear id valid */
    reg->region[region].prbar_low &= ~NOC_S3_APU_ID_VALID_MSK;
    /* Set id valid */
    reg->region[region].prlar_low |= (valid << NOC_S3_APU_ID_VALID_POS) &
                                   NOC_S3_APU_ID_VALID_MSK;

    return NOC_S3_SUCCESS;
}

enum noc_s3_err noc_s3_apu_enable(const struct noc_s3_apu_dev *dev)
{
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    enum noc_s3_err err;
#endif
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /*
     * Cannot disable this field once enabled. This can only cleared by
     * APU reset.
     */
    reg->apu_ctlr |= NOC_S3_APU_CTLR_APU_ENABLE;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    err = noc_s3_print_apu_config(dev);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }
#endif
    return NOC_S3_SUCCESS;
}

enum noc_s3_err noc_s3_apu_sync_err_enable(
    const struct noc_s3_apu_dev *dev)
{
    struct noc_s3_apu_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    /* Clear sync_err_en */
    reg->apu_ctlr &= ~NOC_S3_APU_CTLR_SYNC_ERROR_EN_MSK;
    /* Set sync_err_en */
    reg->apu_ctlr |= NOC_S3_APU_CTLR_SYNC_ERROR_EN;

    return NOC_S3_SUCCESS;
}

enum noc_s3_err noc_s3_apu_dev_init(
    const struct noc_s3_dev *noc_s3_dev,
    const struct noc_s3_component_node *component,
    const uint64_t region_mapping_offset,
    struct noc_s3_apu_dev *dev)
{
    enum noc_s3_err err;
    uint32_t off_addr;

    if (noc_s3_dev == NULL || noc_s3_dev->periphbase == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (component == NULL || dev == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    /* Fetch offset address for the APU */
    err = noc_s3_fetch_subfeature_offset(
            noc_s3_dev,
            component->type,
            component->id,
            NOC_S3_APU, &off_addr);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    dev->base = noc_s3_dev->periphbase + off_addr;
    dev->region_mapping_offset = region_mapping_offset;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    dev->data.noc_s3_dev = noc_s3_dev;
    dev->data.component = component;
#endif

    return NOC_S3_SUCCESS;
}

enum noc_s3_err noc_s3_apu_configure_region(
    const struct noc_s3_apu_dev *dev,
    const struct noc_s3_apu_reg_cfg_info *cfg_info,
    const uint32_t region)
{
    struct noc_s3_apu_reg_map *reg;
    enum noc_s3_err err;
    uint32_t id_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map *)dev->base;

    /*
     * If this region is locked, disallow re-configuration of this APU region
     */
    if (reg->region[region].prbar_low & NOC_S3_APU_LOCK) {
        return NOC_S3_ERR_NOT_PERMITTED;
    }

    err = noc_s3_apu_set_addr_range(dev, region,
                                      cfg_info->base_addr,
                                      cfg_info->end_addr);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    err = noc_s3_apu_set_br(dev, region, cfg_info->background);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    err = noc_s3_apu_set_id_valid(dev, region, cfg_info->id_valid);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    for (id_idx = 0; id_idx < NOC_S3_APU_NUM_ENTITIES; ++id_idx) {
        err = noc_s3_apu_set_access_perms(dev, region,
                                            cfg_info->permissions[id_idx],
                                            (1 << id_idx));
        if (err != NOC_S3_SUCCESS) {
            return err;
        }

        err = noc_s3_apu_set_entity_id(dev, region,
                                         cfg_info->entity_ids[id_idx],
                                         (1 << id_idx));
        if (err != NOC_S3_SUCCESS) {
            return err;
        }
    }

    if (cfg_info->region_enable == NOC_S3_REGION_ENABLE) {
        err = noc_s3_apu_set_region_enable(dev, region);
        if (err != NOC_S3_SUCCESS) {
            return err;
        }
    }

    err = noc_s3_apu_set_lock(dev, region, cfg_info->lock);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err get_next_available_region(
    const struct noc_s3_apu_dev *dev,
    uint32_t *region)
{
    struct noc_s3_apu_reg_map* reg;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_apu_reg_map*)dev->base;

    for (r_idx = 0; r_idx < NOC_S3_MAX_APU_REGIONS; ++r_idx) {
        if (!(reg->region[r_idx].prbar_low & NOC_S3_APU_REGION_ENABLE)) {
            *region = r_idx;
            return NOC_S3_SUCCESS;
        }
    }

    return NOC_S3_ERR;
}

enum noc_s3_err noc_s3_apu_configure_next_available_region(
    const struct noc_s3_apu_dev *dev,
    const struct noc_s3_apu_reg_cfg_info *cfg_info)
{
    enum noc_s3_err err;
    uint32_t next_available_region;

    err = get_next_available_region(dev, &next_available_region);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    return noc_s3_apu_configure_region(dev, cfg_info, next_available_region);
}
