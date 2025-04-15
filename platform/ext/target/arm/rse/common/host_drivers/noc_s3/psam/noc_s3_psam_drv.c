/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "discovery/noc_s3_discovery_drv.h"
#include "noc_s3_psam_drv.h"
#include "noc_s3_psam_reg.h"
#include "util/noc_s3_util.h"

#include <stddef.h>

#define NOC_S3_PSAM_ADDRESS_GRAN      (1ULL << 12)
#define NOC_S3_PSAM_ADDRESS_MASK      (~(NOC_S3_PSAM_ADDRESS_GRAN - 1))
#define NOC_S3_PSAM_ADDRESS_H(addr)   ((addr) >> 32)
#define NOC_S3_PSAM_ADDRESS_L(addr)   ((addr) & NOC_S3_PSAM_ADDRESS_MASK)

#define NOC_S3_PSAM_GET64_BASE_ADDRESS(high, low)   \
    (((uint64_t)(high) << 32) | (low)) & NOC_S3_PSAM_ADDRESS_MASK

#define NOC_S3_PSAM_GET64_END_ADDRESS(high, low)                          \
    (((uint64_t)(high) << 32) | (low)) | (NOC_S3_PSAM_ADDRESS_GRAN - 1) | \
        0xFFFF

static uint64_t noc_s3_psam_get_base_address(
                    const struct noc_s3_psam_reg_map* reg, uint32_t region)
{
    uint64_t base;

    base = NOC_S3_PSAM_GET64_BASE_ADDRESS(reg->nh_region[region].cfg1,
                                            reg->nh_region[region].cfg0);

    return base;
}

static uint64_t noc_s3_psam_get_end_address(
                    const struct noc_s3_psam_reg_map* reg, uint32_t region)
{
    uint64_t end;

    end = NOC_S3_PSAM_GET64_END_ADDRESS(reg->nh_region[region].cfg3,
                                          reg->nh_region[region].cfg2);

    return end;
}

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
/*
 * Example pretty print log for a configured PSAM
 *
 *        PSAM configuration for RSE_ASNI
 *        -------------------------------
 *        (REG 00)[0x0000000000000000 - 0x000000000fffffff]: APP_AMNI
 *                [0x0000000010000000 - 0x000000001fffffff]: <undefined>
 *        (REG 03)[0x0000000020000000 - 0x0000000020ffffff]: CONFIG_SPACE
 *        (REG 01)[0x0000000021000000 - 0x000000002a5affff]: APP_AMNI
 *        (REG 02)[0x000000002a5b0000 - 0x000000002a5cffff]: SCP_PMNI
 *                [0x000000002a5d0000 - 0x000000002a7fffff]: <undefined>
 *        (REG 04)[0x000000002a800000 - 0x000000002ac8ffff]: APP_AMNI
 *                [0x0000000800000000 - 0xffffffffffffffff]: <undefined>
 *
 *
 * PSAM log format:
 *        (REG XX)[Y - Z]: A
 *  , where
 *      1. (REG XX) : region index at where routing info is configured.
 *      2. [Y - Z] : base and end address of the routing info.
 *      3. A : Target where a particular region is routed to. '<undefined>' if no
 *         routing target is defined.
 */
#define NOC_S3_INVALID_REGION     UINT32_MAX
static void noc_s3_print_psam_region(uint64_t base, uint64_t end,
                                       uint32_t region, const char* target)
{
    if (region == NOC_S3_INVALID_REGION) {
        NOC_S3_DRV_LOG("\r\n        ");
    } else {
        NOC_S3_DRV_LOG("\r\n(REG %02d)", region);
    }

    NOC_S3_DRV_LOG("[0x%08lx%08lx - 0x%08lx%08lx]: %s ",
                                    (uint32_t)(base >> 32),
                                    (uint32_t)(base),
                                    (uint32_t)(end >> 32),
                                    (uint32_t)(end),
                                    (target == NULL) ? "<undefined>"
                                                     : target);
}

static void noc_s3_print_undefined_psam_region(uint64_t base, uint64_t end)
{
    noc_s3_print_psam_region(base, end, NOC_S3_INVALID_REGION, NULL);
}

static enum noc_s3_err noc_s3_print_psam_config(
    const struct noc_s3_psam_dev *dev)
{
    const char *node_label;
    enum noc_s3_err err;
    struct noc_s3_psam_reg_map* reg;
    struct noc_s3_sorted_region_data sorted_buffer[NOC_S3_MAX_NH_REGIONS];
    struct noc_s3_sorted_region_list list = {
            .sorted_regions = sorted_buffer,
            .sorted_region_count = 0,
            .sorted_region_max = NOC_S3_MAX_NH_REGIONS,
        };
    uint32_t r_idx, region;
    uint64_t base, end, prev_end, tgt_id;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_psam_reg_map*)dev->base;

    if (dev->data.noc_s3_dev == NULL || dev->data.component == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (dev->data.noc_s3_dev->get_xSNI_label == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    node_label = dev->data.noc_s3_dev->get_xSNI_label(
                    dev->data.component->id);

    if (node_label == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    NOC_S3_DRV_LOG_HEADING("PSAM configuration for %s", node_label);

    for (region = 0; region < NOC_S3_MAX_NH_REGIONS; ++region) {
        if (reg->nh_region[region].cfg0 & NOC_S3_NH_REGION_REGION_VALID) {
            err = noc_s3_sorted_add_entry(&list, region,
                    noc_s3_psam_get_base_address(reg, region));
            if (err != NOC_S3_SUCCESS) {
                return err;
            }
        }
    }

    if (list.sorted_region_count == 0) {
        noc_s3_print_undefined_psam_region(0x0, UINT64_MAX);
        return NOC_S3_SUCCESS;
    }

    for (r_idx = 0; r_idx < list.sorted_region_count; ++r_idx) {
        region = list.sorted_regions[r_idx].region_idx;
        base = noc_s3_psam_get_base_address(reg, region);
        end = noc_s3_psam_get_end_address(reg, region);

        prev_end = (r_idx > 0) ? noc_s3_psam_get_end_address(reg,
                     list.sorted_regions[r_idx - 1].region_idx) : UINT64_MAX;
        if (base != prev_end + 1) {
            noc_s3_print_undefined_psam_region(prev_end + 1, base - 1);
        }

        tgt_id = reg->nh_region[region].cfg2 & NOC_S3_NH_REGION_TGT_ID_MSK;
        noc_s3_print_psam_region(base, end, region,
                dev->data.noc_s3_dev->get_xMNI_label(tgt_id));
    }

    if (end != UINT64_MAX) {
        noc_s3_print_undefined_psam_region(end + 1, UINT64_MAX);
    }

    NOC_S3_DRV_LOG("\r\n");

    return NOC_S3_SUCCESS;
}
#endif

enum noc_s3_err noc_s3_psam_dev_init(
    const struct noc_s3_dev *noc_s3_dev,
    const struct noc_s3_component_node* component,
    const uint64_t region_mapping_offset,
    struct noc_s3_psam_dev *dev)
{
    enum noc_s3_err err;
    uint32_t off_addr;

    if (noc_s3_dev == NULL || noc_s3_dev->periphbase == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (component == NULL || dev == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    /* Fetch offset address for the PSAM */
    err = noc_s3_fetch_subfeature_offset(
            noc_s3_dev,
            component->type,
            component->id,
            NOC_S3_PSAM, &off_addr);
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

enum noc_s3_err noc_s3_psam_configure_nhregion(
    const struct noc_s3_psam_dev *dev,
    const struct noc_s3_psam_reg_cfg_info *cfg_info,
    const uint32_t region)
{
    struct noc_s3_psam_reg_map* reg;
    uint64_t base_addr, end_addr;
    uint64_t temp_base_addr, temp_end_addr;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_psam_reg_map*)dev->base;

    if (cfg_info == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    base_addr = cfg_info->base_addr + dev->region_mapping_offset;
    end_addr = cfg_info->end_addr + dev->region_mapping_offset;

    /* Checking alignment of base and end addresses */
    if (((base_addr & (NOC_S3_PSAM_ADDRESS_GRAN - 1)) != 0) ||
        ((~end_addr & (NOC_S3_PSAM_ADDRESS_GRAN - 1)) != 0)) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    /* Disable region */
    reg->nh_region[region].cfg0 &= ~NOC_S3_NH_REGION_REGION_VALID;

    /* Check whether region overlaps with another valid region */
    for (r_idx = 0; r_idx < NOC_S3_MAX_NH_REGIONS; ++r_idx) {
        if (reg->nh_region[r_idx].cfg0 & NOC_S3_NH_REGION_REGION_VALID) {
            temp_base_addr = noc_s3_psam_get_base_address(reg, r_idx);
            temp_end_addr = noc_s3_psam_get_end_address(reg, r_idx);

            if (noc_s3_check_region_overlaps(base_addr, end_addr,
                    temp_base_addr, temp_end_addr) !=
                NOC_S3_SUCCESS) {
                return NOC_S3_ERR_REGION_OVERLAPS;
            }
        }
    }

    /* Set base address */
    reg->nh_region[region].cfg0 = NOC_S3_PSAM_ADDRESS_L(base_addr);
    reg->nh_region[region].cfg1 = NOC_S3_PSAM_ADDRESS_H(base_addr);
    /* Set end address */
    reg->nh_region[region].cfg2 = NOC_S3_PSAM_ADDRESS_L(end_addr);
    reg->nh_region[region].cfg3 = NOC_S3_PSAM_ADDRESS_H(end_addr);
    /* Set ID for the Target interface. */
    reg->nh_region[region].cfg2 |= (cfg_info->target_id &
                                    NOC_S3_NH_REGION_TGT_ID_MSK);
    /* Set region valid */
    reg->nh_region[region].cfg0 |= NOC_S3_NH_REGION_REGION_VALID;

    return NOC_S3_SUCCESS;
}

static enum noc_s3_err get_next_available_region(
    const struct noc_s3_psam_dev *dev,
    uint32_t *region)
{
    struct noc_s3_psam_reg_map* reg;
    uint32_t r_idx;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_psam_reg_map*)dev->base;

    for (r_idx = 0; r_idx < NOC_S3_MAX_NH_REGIONS; ++r_idx) {
        if (!(reg->nh_region[r_idx].cfg0 & NOC_S3_NH_REGION_REGION_VALID)) {
            *region = r_idx;
            return NOC_S3_SUCCESS;
        }
    }

    return NOC_S3_ERR;
}

enum noc_s3_err noc_s3_psam_configure_next_available_nhregion(
    const struct noc_s3_psam_dev *dev,
    const struct noc_s3_psam_reg_cfg_info *cfg_info)
{
    enum noc_s3_err err;
    uint32_t next_available_region;

    err = get_next_available_region(dev, &next_available_region);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    return noc_s3_psam_configure_nhregion(dev, cfg_info,
            next_available_region);
}

enum noc_s3_err noc_s3_psam_enable(const struct noc_s3_psam_dev *dev)
{
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    enum noc_s3_err err;
#endif
    struct noc_s3_psam_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_psam_reg_map*)dev->base;

    reg->sam_status |= NOC_S3_SAM_STATUS_SETUP_COMPLETE;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    err = noc_s3_print_psam_config(dev);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }
#endif
    return NOC_S3_SUCCESS;
}

enum noc_s3_err noc_s3_psam_disable(const struct noc_s3_psam_dev *dev)
{
    struct noc_s3_psam_reg_map* reg;

    if (dev == NULL || dev->base == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_psam_reg_map*)dev->base;

    reg->sam_status &= ~NOC_S3_SAM_STATUS_SETUP_COMPLETE;

    return NOC_S3_SUCCESS;
}
