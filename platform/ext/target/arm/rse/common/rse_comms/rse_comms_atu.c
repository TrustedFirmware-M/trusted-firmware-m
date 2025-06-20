/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_atu.h"
#include "atu_config.h"
#include "atu_rse_lib.h"
#include "tfm_log.h"
#include "device_definition.h"
#include "platform_base_address.h"

struct comms_atu_region_params_t
{
    uint32_t log_addr;
    uint64_t phys_addr;
    uint32_t size;
    uint32_t out_bus_attr;
    uint32_t ref_count;
};

/* ATU config */
static struct comms_atu_region_params_t atu_regions[RSE_COMMS_ATU_REGION_AM] = {0};

static inline uint64_t round_down(uint64_t num, uint64_t boundary)
{
    return num - (num % boundary);
}

enum tfm_plat_err_t comms_atu_add_region_to_set(comms_atu_region_set_t *set,
                                                uint8_t region)
{
    if (region >= RSE_COMMS_ATU_REGION_AM) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    set->ref_counts[region]++;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t get_region_idx_from_host_buf(uint64_t host_addr,
                                                        uint32_t size,
                                                        uint32_t *region_idx)
{
    uint32_t idx;
    struct comms_atu_region_params_t *region;

    for (idx = 0; idx < RSE_COMMS_ATU_REGION_AM; idx++) {
        region = &atu_regions[idx];

        if (atu_regions[idx].ref_count > 0 &&
            host_addr >= region->phys_addr &&
            host_addr + size <= region->phys_addr + region->size) {
            *region_idx = idx;
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_INVALID_INPUT;
}

enum tfm_plat_err_t comms_atu_get_rse_ptr_from_host_addr(uint8_t region,
                                                         uint64_t host_addr,
                                                         void **rse_ptr)
{
    struct comms_atu_region_params_t *region_params;

    if (region >= RSE_COMMS_ATU_REGION_AM) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }


    region_params = &atu_regions[region];
    *rse_ptr = (uint8_t *)((uint32_t)(host_addr - region_params->phys_addr)
                           + region_params->log_addr);

    return TFM_PLAT_ERR_SUCCESS;
}

static int get_free_region_idx(uint32_t *region_idx) {
    uint32_t idx;

    for (idx = 0; idx < RSE_COMMS_ATU_REGION_AM; idx++) {
        if (atu_regions[idx].ref_count == 0) {
            *region_idx = idx;
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_MAX_VALUE;
}

static enum tfm_plat_err_t setup_region_for_host_buf(uint64_t host_addr,
                                                     uint32_t size,
                                                     uint32_t region_idx)
{
    struct comms_atu_region_params_t *region_params;
    int32_t atu_err;
    uint64_t host_buf_end = host_addr + size;

    if (host_buf_end <= host_addr) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    region_params = &atu_regions[region_idx];
    region_params->phys_addr = round_down(host_addr, RSE_COMMS_ATU_PAGE_SIZE);
    region_params->size = RSE_COMMS_ATU_REGION_SIZE;

    if (host_buf_end > region_params->phys_addr + region_params->size) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    region_params->out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS;
    atu_err = atu_rse_map_addr_automatically(&ATU_DEV_S, region_params->phys_addr,
                                             region_params->size, region_params->out_bus_attr,
                                             &region_params->log_addr, &region_params->size);

    if (atu_err != ATU_ERR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    VERBOSE_RAW("[COMMS ATU] Mapping new region: 0x%08x\n", region_idx);
    VERBOSE_RAW("[COMMS ATU] Region start: 0x%08x\n", region_params->phys_addr);
    VERBOSE_RAW("[COMMS ATU] Region end:   0x%08x\n", region_params->phys_addr + region_params->size);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t comms_atu_alloc_region(uint64_t host_addr, uint32_t size,
                                           uint8_t *region)
{
    uint32_t region_idx;
    enum tfm_plat_err_t err;

    err = get_region_idx_from_host_buf(host_addr, size, &region_idx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        err = get_free_region_idx(&region_idx);
        if (err) {
            return err;
        }

        err = setup_region_for_host_buf(host_addr, size, region_idx);
        if (err) {
            return err;
        }
    }

    atu_regions[region_idx].ref_count++;

    *region = region_idx;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t comms_atu_free_region(uint8_t region)
{
    int32_t atu_err;
    struct comms_atu_region_params_t *region_params;

    if (region >= RSE_COMMS_ATU_REGION_AM) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    atu_regions[region].ref_count--;
    region_params = &atu_regions[region];

    if (atu_regions[region].ref_count == 0) {
        atu_err = atu_rse_free_addr(&ATU_DEV_S, region_params->log_addr);
        if (atu_err) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
        VERBOSE_RAW("[COMMS ATU] Deallocating region: 0x%08x\n", region);
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t comms_atu_free_regions(comms_atu_region_set_t regions)
{
    uint32_t region_idx;
    int32_t atu_err;
    struct comms_atu_region_params_t *region_params;

    for (region_idx = 0; region_idx < RSE_COMMS_ATU_REGION_AM; region_idx++) {
        if ((regions.ref_counts[region_idx]) > 0) {
            atu_regions[region_idx].ref_count -= regions.ref_counts[region_idx];
            region_params = &atu_regions[region_idx];

            if (atu_regions[region_idx].ref_count == 0) {
                atu_err = atu_rse_free_addr(&ATU_DEV_S, region_params->log_addr);
                if (atu_err) {
                    return TFM_PLAT_ERR_SYSTEM_ERR;
                }
                VERBOSE_RAW("[COMMS ATU] Deallocating region: 0x%08x\n", region_idx);
            }
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}
