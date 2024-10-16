/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "atu_rse_drv_internal.h"
#include "atu_rse_drv.h"

static enum atu_error_t is_aligned_to_page(struct atu_dev_t *dev, uint64_t address)
{
    uint8_t ps;
    struct _atu_reg_map_t *p_atu;

    p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    ps = ATU_GET_ATUPS(p_atu);

    return ((address & ((1 << ps) - 1)) == 0);
}

static void enable_atu_region(struct atu_dev_t *dev, uint8_t region)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    p_atu->atuc |= (1u << region);
}

static void disable_atu_region(struct atu_dev_t *dev, uint8_t region)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    p_atu->atuc &= ~(1u << region);
}

enum atu_error_t atu_rse_set_start_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                   uint32_t address)
{
    struct _atu_reg_map_t *p_atu = NULL;
    uint8_t ps = 0;
    enum atu_error_t err;

    if (dev == NULL) {
        return ATU_ERR_INIT_REGION_INVALID_ARG;
    }

    p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    ps = ATU_GET_ATUPS(p_atu);

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    /*
     * The value stored in this field is the start logical address
     * right shifted by the value of the PS
     */
    p_atu->atursla[region] = (address >> ps);

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_get_start_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                   uint32_t *address)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    enum atu_error_t err;

    uint8_t ps = ATU_GET_ATUPS(p_atu);

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    *address = p_atu->atursla[region] << ps;

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_set_end_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                 uint32_t address)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    uint8_t ps = ATU_GET_ATUPS(p_atu);

    /* The end page should be greater than or equal to the start page */
    if ((address >> ps) < p_atu->atursla[region]) {
        return ATU_ERR_INVALID_LOGICAL_ADDRESS;
    }

    p_atu->aturela[region] = ((address - 1) >> ps);

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_get_end_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                 uint32_t *address)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    enum atu_error_t err;

    uint8_t ps = ATU_GET_ATUPS(p_atu);

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    *address = (p_atu->aturela[region] + 1) << ps;

    return ATU_ERR_NONE;
}

void atu_rse_set_physical_region_offset(struct atu_dev_t *dev, uint8_t region, uint64_t offset)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    uint8_t ps = ATU_GET_ATUPS(p_atu);
    uint64_t shifted_offset = offset >> ps;

    p_atu->aturav_l[region] = (uint32_t)(shifted_offset);
    p_atu->aturav_m[region] = (uint32_t)(shifted_offset >> 32);
}

enum atu_error_t atu_rse_get_physical_region_offset(struct atu_dev_t *dev, uint8_t region,
                                                    uint64_t *offset)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    enum atu_error_t err;
    uint8_t ps = ATU_GET_ATUPS(p_atu);
    uint64_t shifted_offset = 0;

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    shifted_offset = ((uint64_t)p_atu->aturav_m[region] << 32) | p_atu->aturav_l[region];
    *offset = shifted_offset << ps;

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_set_bus_attributes(struct atu_dev_t *dev, uint8_t region, uint32_t val)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    enum atu_error_t err;

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    p_atu->aturoba[region] = (val & ATU_REGION_ROBA_MASK);

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_get_bus_attributes(struct atu_dev_t *dev, uint8_t region, uint32_t *val)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    enum atu_error_t err;

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    *val = p_atu->aturoba[region] & ATU_REGION_ROBA_MASK;

    return ATU_ERR_NONE;
}

uint8_t atu_rse_get_supported_region_count(struct atu_dev_t *dev)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    return (uint8_t)(0x1u << (p_atu->atubc & ATU_ATUBC_RC_MASK));
}

enum atu_error_t atu_rse_check_supported_region(struct atu_dev_t *dev, uint8_t region)
{
    if (region >= atu_rse_get_supported_region_count(dev)) {
        return ATU_ERR_INVALID_REGION;
    }

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_initialize_region(struct atu_dev_t *dev, uint8_t region,
                                           uint32_t log_addr, uint64_t phys_addr,
                                           uint32_t size)
{
    enum atu_error_t err;
    struct _atu_reg_map_t *p_atu;
    uint8_t ps;
    uint32_t end_log_addr;
    uint64_t physical_region_offset;

    if (dev == NULL) {
        return ATU_ERR_INIT_REGION_INVALID_ARG;
    }

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    ps = ATU_GET_ATUPS(p_atu);

    if (log_addr > UINT32_MAX - (size - 1)) {
        return ATU_ERR_INIT_REGION_INVALID_ADDRESS;
    }

    end_log_addr = log_addr + size;
    physical_region_offset = phys_addr - log_addr;

    /* Make sure that the regions are aligned to the page size (PS) of the peripheral */
    if ( !is_aligned_to_page(dev, phys_addr) ||
         !is_aligned_to_page(dev, (uint64_t)log_addr) ||
         !is_aligned_to_page(dev, (uint64_t)size) ) {
        return ATU_ERR_INIT_REGION_INVALID_ADDRESS;
    }

    err = atu_rse_set_start_logical_address(dev, region, log_addr);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    err = atu_rse_set_end_logical_address(dev, region, end_log_addr);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    atu_rse_set_physical_region_offset(dev, region, physical_region_offset);
    enable_atu_region(dev, region);

    return ATU_ERR_NONE;
}

enum atu_error_t atu_rse_uninitialize_region(struct atu_dev_t *dev, uint8_t region)
{
    enum atu_error_t err;

    if (dev == NULL) {
        return ATU_ERR_UNINIT_REGION_INVALID_ARG;
    }

    err = atu_rse_check_supported_region(dev, region);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    disable_atu_region(dev, region);

    return ATU_ERR_NONE;
}
