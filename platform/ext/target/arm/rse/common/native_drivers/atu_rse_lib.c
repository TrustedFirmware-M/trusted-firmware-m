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
#include "atu_rse_lib.h"
#include "atu_config.h"

#define ATU_STATIC_CFG_ENABLED ((defined ATU_STATIC_SLOT_COUNT) && (ATU_STATIC_SLOT_COUNT > 0))
#define ATU_DYNAMIC_CFG_ENABLED ((defined ATU_DYN_SLOT_COUNT) && (ATU_DYN_SLOT_COUNT > 0))

#if ATU_DYNAMIC_CFG_ENABLED

/**
 * \brief ATU logical address space bank context
 */
struct atu_bank_ctx_t {
    uint8_t bank_cnt_max;           /*!< Maximum bank count supported */
    uint32_t bank_size_max;         /*!< Maximum bank size supported */
    uint16_t bank_align;            /*!< Bank alignment required based on ATU page size */
    uint8_t mem_chunk_parts;        /*!< Number of parts in each bank (Dynamic ATU slot count) */
    uint32_t mem_start;             /*!< Memory start - logical address start */
    uint32_t mem_size;              /*!< Total Memory size - logical address space size */
};

/*
 * Global structure to store the context of memory bank
 * Number of atu memory bank context depends on the Security type (Secure/Non-Secure)
 */
static struct atu_bank_ctx_t atu_bank_ctx[ATU_LOG_ADDR_TYPE_MAX];

/* Domain policy mask */
static uint8_t secure_domain_cfg = ATU_DOMAIN_SECURE | ATU_DOMAIN_ROOT;

/*
 * @brief Calculate log2 rounded up
 *  - log(0)  => 0
 *  - log(1)  => 0
 *  - log(2)  => 1
 *  - log(3)  => 2
 *  - log(4)  => 2
 *  - log(5)  => 3
 *        :      :
 *  - log(16) => 4
 *  - log(32) => 5
 *
 * @param[in] value     Input value to compute
 *
 * @return Log 2 (value)
 *
 */
static inline uint8_t log2_bitwise(uint32_t value)
{
    uint8_t result = 0;
    value = value >> 1;
    while (value) {
        result++;
        value = value >> 1;
    }
    return result;
}

/*
 * @brief API to return bank index which can hold the requested size
 *          Each bank index can hold a value based on below calculation
 *          bank_align = 4Kb
 *          idx = 0; Bank size = 2^0 x 4KB = 4KB
 *          idx = 1; Bank size = 2^1 x 4KB = 8KB
 *          idx = 2; Bank size = 2^2 x 4KB = 16KB
 *          Find the best bank index based on the size parameter
 *
 * @param[in] size      Size to fit in the bank
 * @param[in] bank_align    Size alignment for the bank
 *
 * @return Returns the best fit bank index
 *
 */
static uint8_t find_bank_idx(uint32_t size, uint32_t bank_align)
{
    uint32_t bank_width = 0;
    uint8_t bank_idx = 0;

    if (size == 0 || bank_align == 0)
        return 0;

    bank_width = (size + bank_align - 1) / bank_align;

    if (bank_width <= 1) {
        return 0;
    }

    /* Calculate leading zeroes with 32-bit intrinsic function */
    bank_idx = 32 - __builtin_clz(bank_width - 1);

    return bank_idx;
}

/*
 * @brief API to find maximum bank that could be created.
 *      Based on the Total memory size (mem_size), memory alignment (mem_align)
 *      and number of parts to split (mem_chunk_parts), the function finds how many bank could
 *      be created/supported.
 *
 * @param[in] mem_size          Total memory size available
 * @param[in] mem_align         Memory alignment
 * @param[in] mem_chunk_parts   Number of required memory chunk
 *
 * @return Returns the max bank count that could be supported
 *
 */
static uint8_t get_bank_cnt_max(uint32_t mem_size, uint16_t mem_align, uint8_t mem_chunk_parts)
{
    uint8_t ret_bank_cnt = 0;
    uint32_t temp_val = 0;

    /*
     * Validate the input arguments
     */
    if ((mem_size == 0) || (mem_align == 0) || (mem_chunk_parts == 0)) {
        ret_bank_cnt = 0;
        return ret_bank_cnt;
    }

    /*
     * Bank_cnt = (log₂(( Total available size / ( mem_chunk_parts * mem_align )) + 1 )
     */
    temp_val = ((mem_size / (mem_chunk_parts * mem_align)) + 1);
    ret_bank_cnt = log2_bitwise(temp_val);

    return ret_bank_cnt;
}

/*
 * @brief API to get the Logical address space size based on the security type
 *
 * @param[in] sec_type      Security type (secure/non-secure)
 *
 * @return Returns the (Sec/Non-Sec) logical address size
 *
 */
static inline uint32_t get_log_addr_space_size(enum atu_log_type_t sec_type)
{
    if (ATU_LOG_ADDR_TYPE_NON_SECURE == sec_type) {
        return ATU_DYN_NON_SEC_LOG_ADDR_SIZE;
    }
    else if (ATU_LOG_ADDR_TYPE_SECURE == sec_type) {
        return ATU_DYN_SEC_LOG_ADDR_SIZE;
    }
    else {
        /* Not reachable */
        return 0;
    }
}

/*
 * @brief API to get the Logical address start value based on the security type
 *
 * @param[in] sec_type      Security type (secure/non-secure)
 *
 * @return Returns the (Sec/Non-Sec) logical address start
 *
 */
static inline uint32_t get_log_addr_space_start(enum atu_log_type_t sec_type)
{
    if (ATU_LOG_ADDR_TYPE_NON_SECURE == sec_type) {
        return ATU_DYN_NON_SEC_LOG_ADDR_START;
    }
    else if (ATU_LOG_ADDR_TYPE_SECURE == sec_type) {
        return ATU_DYN_SEC_LOG_ADDR_START;
    }
    else {
        /* Not reachable */
        return 0;
    }
}

/*
 * @brief API to get the Security type based on the Out bus attributes
 *          Based on AxPROT[1] value, security type is extracted
 *
 * @param[in] out_bus_attr  Out bus attribute value
 *
 * @return atu_log_type_t - Return Secure or Non-secure type
 *
 */
static enum atu_log_type_t get_sec_type(uint32_t out_bus_attr)
{
    uint32_t nse = (out_bus_attr & ATU_ATUROBA_AXNSE_MASK) >> ATU_ATUROBA_AXNSE_OFF;
    uint32_t prot1 = (out_bus_attr & ATU_ATUROBA_AXPROT1_MASK) >> ATU_ATUROBA_AXPROT1_OFF;
    uint8_t target_domain;

    /*
     * AMBA AXI Protocol - Table A5.7: Security attribute
     * --------------------------------------------------
     * AxNSE AxPROT[1] Security attribute
     *   0       0          Secure
     *   0       1       Non-secure
     *   1       0           Root
     *   1       1          Realm
     */
    target_domain = (nse << 1) | prot1;

    if (secure_domain_cfg & target_domain) {
        return ATU_LOG_ADDR_TYPE_SECURE;
    } else {
        return ATU_LOG_ADDR_TYPE_NON_SECURE;
    }
}

/*
 * @brief API to Initialize Memory allocation management structure
 *
 * Entire Logical address space is splited into multiple bank for efficient
 * management of logical address
 *
 * ATU Logical address memory management
 *
 * Bank index (n)              0           1                   2
 * Bank increment (2 ^ n)      1           2                   4
 * Multiples of the bank(kb)   4           4                   4
 *
 * Total mem (KB)              4           8                   16
 * Supported size (KB)         1 to 4KB    (4KB + 1 to 8KB)    (8KB +1 to 16KB)
 *
 * ATU slot / Memory chunk parts = 6
 *
 * Bank index      0       1       2       3
 * mem chunk   ------------------------------------
 *     0       |  4kb  |  8kb  |  16kb  |  ......
 *             --------------------------
 *     1       |  4kb  |  8kb  |  16kb  |  ......
 *             --------------------------
 *     2       |  4kb  |  8kb  |  16kb  |  ......
 *             --------------------------
 *     3       |  4kb  |  8kb  |  16kb  |  ......
 *             --------------------------
 *     4       |  4kb  |  8kb  |  16kb  |  ......
 *             --------------------------
 *     5       |  4kb  |  8kb  |  16kb  |  ......
 *             ------------------------------------
 *
 * @param[in] dev       Pointer to ATU device structure
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_mem_alloc_init(struct atu_dev_t *dev)
{
    /*
     * 1. Clear the dynamic configuration data structure to zero
     * 2. Clear the atu bank context data structure to zero
     * 3. Based on Dynamic configuration logical address size,
     *      derive maximum number bank count and maximum bank size
     */

    struct atu_bank_ctx_t *cur_atu_bank_ctx = NULL;
    enum atu_log_type_t sec_type = ATU_LOG_ADDR_TYPE_MAX;
    enum atu_error_t err = ATU_ERR_UNKNOWN;

    memset(atu_bank_ctx, 0, sizeof(atu_bank_ctx));

    for (sec_type = ATU_LOG_ADDR_TYPE_NON_SECURE; sec_type < ATU_LOG_ADDR_TYPE_MAX; sec_type++) {

        cur_atu_bank_ctx = &atu_bank_ctx[sec_type];

        cur_atu_bank_ctx->mem_start = get_log_addr_space_start(sec_type);
        cur_atu_bank_ctx->mem_size = get_log_addr_space_size(sec_type);

        cur_atu_bank_ctx->mem_chunk_parts = ATU_DYN_SLOT_COUNT;
        cur_atu_bank_ctx->bank_align = atu_rse_get_page_size(dev);
        cur_atu_bank_ctx->bank_cnt_max = get_bank_cnt_max(cur_atu_bank_ctx->mem_size,
                                        cur_atu_bank_ctx->bank_align,
                                        cur_atu_bank_ctx->mem_chunk_parts);

        if (cur_atu_bank_ctx->bank_cnt_max > 0) {
            /*
             * Maximum size of the bank supported = (((2^ (Bank count max - 1) * ( bank alignment))
             */
            cur_atu_bank_ctx->bank_size_max =
                ((1 << (cur_atu_bank_ctx->bank_cnt_max - 1)) * (cur_atu_bank_ctx->bank_align));

            err = ATU_ERR_NONE;
        }
        else {
            cur_atu_bank_ctx->bank_size_max = 0;
            err = ATU_ERR_MEM_INIT;
            break;
        }
    }
    return err;
}

/*
 * @brief API to perform Dynamic configuration. Initialize the required data structure
 *      to perform any dynamic configuration in runtime
 *
 * @param[in] dev       Pointer to ATU device structure
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_dyn_cfg_init(struct atu_dev_t *dev)
{
    enum atu_error_t err = ATU_ERR_UNKNOWN;
    uint8_t hw_avail_count = 0;

    hw_avail_count = atu_rse_get_supported_region_count(dev);

    if ((ATU_DYN_SLOT_START > hw_avail_count) ||
        ((ATU_DYN_SLOT_START + ATU_DYN_SLOT_COUNT) > hw_avail_count)) {
        return ATU_ERR_SLOT_NOT_AVAIL;
    }

    err = atu_mem_alloc_init(dev);

    return err;
}

/*
 * @brief API to check and if available blocks a ATU slot for dynamic mapping
 *
 * @param[in] slot_idx      Pointer to store the slot index, if slot is available
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 */
static enum atu_error_t atu_slot_alloc(struct atu_dev_t *dev, uint8_t *slot_idx)
{
    uint8_t mask_value = 0;
    enum atu_error_t err = ATU_ERR_SLOT_NOT_AVAIL;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    /*
    * Iterate over the atu slot availability status
    *
    * - Bit shift from zero to Max available atu slot
    *     - If bit is set to 1 - then return that ATU slot, set the return status success
    *    - If bit is set to 0 - check the next index
    * If we get any atu slot index, write the value to the pointer requested
    * Else, Return failure
    */
    for (uint8_t idx = ATU_DYN_SLOT_START; idx < (ATU_DYN_SLOT_START + ATU_DYN_SLOT_COUNT); idx++) {
        mask_value = ((p_atu->atuc >> idx) & 1);
        if (mask_value == 0) {
            err = ATU_ERR_NONE;
            *slot_idx = idx;
            break;
        }
    }

    return err;
}

/*
 * @brief API to check and block a logical address, if available.
 *          Based on the requested size and security type, checks whether any
 *          memory bank available to hold the size requested. If available, returns
 *          the logical address, else Returns error
 *
 * @param[in] req_size          Required logical address space
 * @param[in] slot_idx          dynamic slot index
 * @param[in] out_attr          Out bus attributes
 * @param[in] log_addr          Pointer to store the logical address, on success
 * @param[in] aligned_bank_size Pointer to store the aligned memory size, on success
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_mem_alloc_addr(uint32_t req_size, uint8_t slot_idx,
                                           uint32_t out_attr, uint32_t *log_addr,
                                           uint32_t *aligned_bank_size)
{
    /*
    - Initialize the local variables
    - Validate the input argument
    - Load the relevant memory chunk context based on security type (sec_type)
    - Check, If the requested size is greater than the largest chunk
        - Return ERROR
    - Else
        - Go to next step
    - Find the bank memory offset
    - Return the logical address
    */

    uint32_t temp_var = 0;
    uint32_t bank_offset = 0;
    uint32_t temp_log_addr = 0;
    uint32_t temp_bank_size = 0;
    uint8_t bank_align_bits = 0;
    uint8_t req_bank_idx = 0;
    struct atu_bank_ctx_t *cur_bank = NULL;
    enum atu_log_type_t sec_type = ATU_LOG_ADDR_TYPE_MAX;

    /*
     * Extract the security type (secure/non-secure) from out bus attributes
     */
    sec_type = get_sec_type(out_attr);

    cur_bank = &atu_bank_ctx[sec_type];
    bank_align_bits = log2_bitwise(cur_bank->bank_align);

    if ((req_size == 0) || (req_size > cur_bank->bank_size_max)) {
        return ATU_ERR_MEM_SIZE_NOT_AVAILABLE;
    }

    req_bank_idx = find_bank_idx(req_size, cur_bank->bank_align);
    temp_var = (cur_bank->mem_chunk_parts * ((1 << req_bank_idx) - 1)) ;
    bank_offset = (temp_var + (slot_idx * (1 << req_bank_idx))) << (bank_align_bits);

    temp_log_addr = cur_bank->mem_start + bank_offset;
    temp_bank_size = ((1 << req_bank_idx) << bank_align_bits);

    if (((temp_log_addr + temp_bank_size) > (cur_bank->mem_start + cur_bank->mem_size))) {
        return ATU_ERR_MEM_LOG_ADDR;
    }

    *aligned_bank_size = temp_bank_size;
    *log_addr = temp_log_addr;

    return ATU_ERR_NONE;
}

/*
 * @brief API to check if there is an active logical region that overlaps with the
 *           input area.
 *
 * @param[in] dev               Pointer to ATU device structure
 * @param[in] log_addr_start    Start address of the logical area
 * @param[in] log_addr_end      End address of the logical area
 * @param[out] idx              Index of the overlapping region
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t check_log_overlap(struct atu_dev_t *dev, uint32_t log_addr_start,
                                          uint32_t log_addr_end, uint8_t *idx)
{
    enum atu_error_t atu_err = ATU_MAPPING_NOT_AVAIL;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    uint32_t region_log_start = 0;
    uint32_t region_log_end = 0;

    for (*idx = ATU_DYN_SLOT_START; *idx < ATU_DYN_SLOT_START + ATU_DYN_SLOT_COUNT; (*idx) ++) {

        if (((p_atu->atuc >> *idx) & 1) == 0){
            continue;
        }

        atu_err = atu_rse_get_start_logical_address(dev, *idx, &region_log_start);
        if (ATU_ERR_NONE != atu_err) {
            return atu_err;
        }

        atu_err = atu_rse_get_end_logical_address(dev, *idx, &region_log_end);
        if (ATU_ERR_NONE != atu_err) {
            return atu_err;
        }

        if ((region_log_start <= log_addr_start) && (log_addr_start < region_log_end)) {
            return ATU_MAPPING_AVAIL;
        }

        if ((region_log_start <= log_addr_end) && (log_addr_end < region_log_end)) {
            return ATU_MAPPING_AVAIL;
        }
    }

    return ATU_MAPPING_NOT_AVAIL;
}

static enum atu_error_t check_if_region_usable(struct atu_dev_t *dev, uint8_t idx, struct atu_region_map_t *addr_req)
{
    enum atu_error_t atu_err = ATU_ERR_NONE;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    uint64_t region_add_value = 0;
    uint32_t region_log_start = 0;
    uint32_t region_log_end = 0;
    uint64_t region_phy_start = 0;
    uint64_t region_phy_end = 0;
    uint32_t region_out_bus_attr = 0;
    uint64_t request_phy_start = 0;
    uint64_t request_phy_end = 0;
    uint64_t request_add_value = 0;
    int32_t offset = 0;

    request_phy_start = addr_req->phys_addr;
    request_phy_end = addr_req->phys_addr + addr_req->size;
    request_add_value = addr_req->phys_addr - addr_req->log_addr;

    /* Return if the region is not active */
    if (((p_atu->atuc >> idx) & 1) == 0){
        return ATU_ERR_SLOT_NOT_AVAIL;
    }

    atu_err = atu_rse_get_start_logical_address(dev, idx, &region_log_start);
    if (ATU_ERR_NONE != atu_err) {
        return atu_err;
    }

    atu_err = atu_rse_get_end_logical_address(dev, idx, &region_log_end);
    if (ATU_ERR_NONE != atu_err) {
        return atu_err;
    }

    atu_err = atu_rse_get_physical_region_offset(dev, idx, &region_add_value);
    if (ATU_ERR_NONE != atu_err) {
        return atu_err;
    }

    atu_err = atu_rse_get_bus_attributes(dev, idx, &region_out_bus_attr);
    if (ATU_ERR_NONE != atu_err) {
        return atu_err;
    }

    region_phy_start = (uint64_t)region_log_start + region_add_value;
    region_phy_end = (uint64_t)region_log_end + region_add_value;
    /* Address difference between the existing and the requested region */
    offset = region_log_start - addr_req->log_addr;

    /* Verify that the config could be reused */
    if (region_out_bus_attr == addr_req->out_bus_attr) {

        if ((region_phy_start <= request_phy_start) && (request_phy_start < region_phy_end)) {

            /*
             * If the region is overlapping, but the add value differs,
             * the request is erronous.
             */
            if (!addr_req->dynamically_allocate_logical_address) {
                if (region_add_value != (addr_req->phys_addr - addr_req->log_addr)) {
                    return ATU_ERR_INVALID_REGION;
                }
            }

            /* The requested physical area fits in the current region */
            if (request_phy_end <= region_phy_end) {
                /* Return the found region's logical address */
                addr_req->log_addr += offset;
                addr_req->region_idx = idx;
                return ATU_MAPPING_AVAIL;
            }

            /*
             * If the requested address starts in an existing area, but the requested size is
             * to huge, the area needs to be increased if possible. addr_req contains the start
             * address of the found region and the increased size.
             */
            addr_req->log_addr = region_log_start;
            addr_req->size = (region_phy_end - region_phy_start);
            return ATU_MAPPING_TOO_SMALL;
        }
    }

    return ATU_MAPPING_NOT_AVAIL;
}

/*
 * @brief API to check whether requested physical address region already mapped
 *
 * @param[in] dev           Pointer to the ATU hardware base register address
 * @param[in] addr_req      Pointer holding the address request
 *
 * @return atu_map_sts_t    Returns Mapping available or not status
 *
 */
static enum atu_error_t atu_check_mapping(struct atu_dev_t *dev, struct atu_region_map_t *addr_req)
{
    enum atu_error_t atu_err = ATU_ERR_NONE;
    uint8_t idx = 0;
    uint32_t request_log_start = 0;
    uint32_t request_log_end = 0;

    request_log_start = addr_req->log_addr;
    request_log_end = addr_req->log_addr + addr_req->size;

    if (addr_req->dynamically_allocate_logical_address == false) {
        atu_err = check_log_overlap(dev, request_log_start, request_log_end, &idx);
        if (atu_err == ATU_MAPPING_AVAIL){
            /* Found a region, which must be used to avoid duplicated logical addresses
             * If we can't use it that means the request can not be completed */
            atu_err = check_if_region_usable(dev, idx, addr_req);
            if (atu_err == ATU_MAPPING_NOT_AVAIL) {
                return ATU_MAPPING_INVALID;
            }
            return atu_err;
        } else if (atu_err == ATU_MAPPING_NOT_AVAIL) {
            /* Continue */
        } else {
            return atu_err;
        }
    }

    for (idx = ATU_DYN_SLOT_START; idx < ATU_DYN_SLOT_START + ATU_DYN_SLOT_COUNT; idx ++) {

        atu_err = check_if_region_usable(dev, idx, addr_req);
        switch (atu_err) {
            case ATU_ERR_SLOT_NOT_AVAIL:
            case ATU_MAPPING_NOT_AVAIL:
                /* Skip to the next region */
                continue;
            default:
                return atu_err;
        }
    }

    return ATU_MAPPING_NOT_AVAIL;
}

/*
 * @brief API to get the dynamic slot index based on input logical address
 *
 * @param[in] dev           Pointer to ATU device structure
 * @param[in] log_addr      Logical address to free the mapping
 * @param[in] slot_idx      Pointer to store the dynamic slot idx, if we get a logical
 *                          address match
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t get_dyn_cfg_slot_idx(struct atu_dev_t *dev, uint32_t log_addr,
                                             uint8_t *slot_idx)
{
    uint8_t idx = 0;
    enum atu_error_t err = ATU_ERR_INVALID_LOGICAL_ADDRESS;
    uint32_t start_logical_address;
    uint32_t end_logical_address;
    *slot_idx = 0xFF;

    for (idx = ATU_DYN_SLOT_START; idx < ATU_DYN_SLOT_START + ATU_DYN_SLOT_COUNT; idx++) {
        err = atu_rse_get_start_logical_address(dev, idx, &start_logical_address);
        if (ATU_ERR_NONE != err) {
            return err;
        }

        err = atu_rse_get_end_logical_address(dev, idx, &end_logical_address);
        if (ATU_ERR_NONE != err) {
            return err;
        }

        if ((log_addr >= start_logical_address) &&
             (log_addr <  end_logical_address)) {
            /* For loop indexing protects from underflow */
            *slot_idx = idx;
            err = ATU_ERR_NONE;
            break;
        }
    }
    return err;
}

static enum atu_error_t atu_map_addr(struct atu_dev_t *dev, struct atu_region_map_t *addr_req)
{
    uint32_t log_addr = 0;
    uint32_t page_aligned_size = 0;
    uint8_t dyn_slot_idx = 0;
    enum atu_error_t err = ATU_ERR_UNKNOWN;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    if (addr_req->size == 0) {
        return ATU_ERR_MEM_INVALID_ARG;
    }

    err = atu_check_mapping(dev, addr_req);
    switch (err) {
        case ATU_MAPPING_AVAIL:
            /*
             * We have existing mapping with same address request range.
             * Return the retrieved logical address and slot id to the requested driver
             */
            if (p_atu->aturgpv[addr_req->region_idx] == UINT8_MAX) {
                return ATU_MAPPING_NOT_AVAIL;
            }

            p_atu->aturgpv[addr_req->region_idx]++;
            return ATU_ERR_NONE;
            break;
        case ATU_MAPPING_TOO_SMALL:
        case ATU_MAPPING_INVALID:
        case ATU_ERR_INVALID_REGION:
            return err;
        case ATU_MAPPING_NOT_AVAIL:
        default:
            break;
    }

    err = atu_slot_alloc(dev, &dyn_slot_idx);
    if (ATU_ERR_NONE != err) {
        return err;
    }

    err = atu_mem_alloc_addr(addr_req->size, dyn_slot_idx, addr_req->out_bus_attr,
                                 &log_addr, &page_aligned_size);

    if (ATU_ERR_NONE != err) {
        return err;
    }

    /* The client lets the driver choose an optimal address */
    if (addr_req->dynamically_allocate_logical_address) {
        addr_req->log_addr = log_addr;
        addr_req->size = page_aligned_size;
    }

    addr_req->region_idx = dyn_slot_idx;
    err = atu_rse_initialize_region(dev, addr_req->region_idx, addr_req->log_addr,
                                    addr_req->phys_addr, addr_req->size);
    if (ATU_ERR_NONE != err) {
        return err;
    }

    err = atu_rse_set_bus_attributes(dev, addr_req->region_idx, addr_req->out_bus_attr);

    if (err == ATU_ERR_NONE) {
        p_atu->aturgpv[addr_req->region_idx] = 1;
    }
    return err;
}
#endif /* ATU_DYNAMIC_CFG_ENABLED */

#if ATU_STATIC_CFG_ENABLED
/*
 * @brief API to check whether any two region overlap in the given region list
 *      Compares all the region and return the status.
 *
 * @param[in] region    Pointer to region list
 * @param[in] reg_count Number of regions in the list
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_check_addr_overlap(const struct atu_region_map_t *region,
                                               uint8_t reg_count)
{
    uint8_t idx_1 = 0;
    uint8_t idx_2 = 0;
    uint32_t start_addr_1 = 0;
    uint32_t start_addr_2 = 0;
    uint32_t end_addr_1 = 0;
    uint32_t end_addr_2 = 0;

    if (region == NULL || reg_count == 0) {
        return ATU_ERR_MEM_INVALID_ARG;
    }

    /* None of the region should have zero or overflowing size */
    for (idx_1 = 0; idx_1 < reg_count; idx_1++) {
        if ((region[idx_1].size == 0)
            || ((UINT32_MAX - region[idx_1].log_addr) < region[idx_1].size)){
            return ATU_ERR_MEM_INVALID_ARG;
        }
    }

    /* Test every region to every other region against overlapping */
    for (idx_1 = 0; idx_1 < (reg_count - 1); idx_1++) {

        start_addr_1 = region[idx_1].log_addr;
        end_addr_1 = ((region[idx_1].log_addr + region[idx_1].size) - 1U );

        for (idx_2 = idx_1 + 1; idx_2 < reg_count; idx_2++) {

            start_addr_2 = region[idx_2].log_addr;
            end_addr_2 = ((region[idx_2].log_addr + region[idx_2].size) - 1U );

            /*
             * Validate whether two address regions overlap
             */
            if ((start_addr_1 <= end_addr_2) && (start_addr_2 <= end_addr_1)) {
                return ATU_ERR_STAT_CFG_OVRLP;
            }
        }
    }

    return ATU_ERR_NONE;
}


/*
 * @brief API to perform static configuration. Initialize the ATU hardware
 *      based on the region configuration available in the static configuration
 *      structure
 *
 * @param[in] dev       Pointer to ATU device structure
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_static_cfg_init(struct atu_dev_t *dev,
                                            const struct atu_region_map_t *ptr_reg,
                                            const uint8_t stat_count)
{
    uint8_t idx = 0;
    enum atu_error_t err = ATU_ERR_UNKNOWN;

    if (stat_count > ATU_STATIC_SLOT_COUNT) {
        return ATU_ERR_STAT_CFG_COUNT;
    }

    err = atu_check_addr_overlap(ptr_reg, stat_count);

    if (err != ATU_ERR_NONE) {
        return err;
    }

    for (idx = 0; idx < stat_count; idx++) {
        /*
         * Pass each entry of static configuration to ATU intialize
         */
        err = atu_rse_initialize_region(dev, (idx + ATU_STATIC_SLOT_START), ptr_reg[idx].log_addr,
                                        ptr_reg[idx].phys_addr, ptr_reg[idx].size);

        if (err != ATU_ERR_NONE) {
            return err;
        }

        err = atu_rse_set_bus_attributes(dev, (idx + ATU_STATIC_SLOT_START), ptr_reg[idx].out_bus_attr);

        if (ATU_ERR_NONE != err) {
            return err;
        }

    }

    return ATU_ERR_NONE;
}

/*
 * @brief API to perform static configuration De Initialization. Un-Initialize the ATU hardware
 *      based on the static region count
 *
 * @param[in] dev                 Pointer to ATU device structure
 * @param[in] atu_static_cfg      Static configuration array of the driver
 * @param[in] atu_static_cfg_cnt  Number of static configuration entries of the driver
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
static enum atu_error_t atu_static_cfg_uninit(struct atu_dev_t *dev, const uint8_t atu_stat_count)
{
    uint8_t idx = 0;
    enum atu_error_t err = ATU_ERR_UNKNOWN;

    if (atu_stat_count > ATU_STATIC_SLOT_COUNT) {
        return ATU_ERR_STAT_CFG_COUNT;
    }

    for (idx = 0; idx < atu_stat_count; idx++) {
        /*
         * Pass each entry of static configuration to ATU unintialize
         */
        err = atu_rse_uninitialize_region(dev, (idx + ATU_STATIC_SLOT_START));

        if (err != ATU_ERR_NONE) {
            return err;
        }
    }

    return ATU_ERR_NONE;
}
#endif /* ATU_STATIC_CFG_ENABLED */

uint16_t atu_rse_get_page_size(struct atu_dev_t *dev)
{
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    return (uint16_t)(0x1u << ATU_GET_ATUPS(p_atu));
}

enum atu_error_t atu_rse_drv_init(struct atu_dev_t *dev, uint8_t secure_domains,
                                  const struct atu_region_map_t atu_static_cfg[],
                                  const uint8_t atu_stat_cfg_cnt)
{
    enum atu_error_t err = ATU_ERR_NONE;

    /* Store the config for further use */
    secure_domain_cfg = secure_domains;

    if (dev == NULL) {
        return ATU_ERR_INIT_REGION_INVALID_ARG;
    }

#if ATU_STATIC_CFG_ENABLED
    if (atu_stat_cfg_cnt > 0) {
        err = atu_static_cfg_init(dev, atu_static_cfg, atu_stat_cfg_cnt);

        if (ATU_ERR_NONE != err) {
            return err;
        }
    }
#endif /* ATU_STATIC_CFG_ENABLED */

#if ATU_DYNAMIC_CFG_ENABLED
    err = atu_dyn_cfg_init(dev);

#endif /* ATU_DYNAMIC_CFG_ENABLED */

    return err;
}

enum atu_error_t atu_rse_drv_deinit(struct atu_dev_t *dev, const uint8_t atu_static_cfg_cnt)
{
    enum atu_error_t err = ATU_ERR_NONE;

#if ATU_STATIC_CFG_ENABLED
    if (atu_static_cfg_cnt > 0) {
        err = atu_static_cfg_uninit(dev, atu_static_cfg_cnt);

        if (ATU_ERR_NONE != err) {
            return err;
        }
    }
#endif /* ATU_STATIC_CFG_ENABLED */

#if ATU_DYNAMIC_CFG_ENABLED
    memset(atu_bank_ctx, 0, sizeof(atu_bank_ctx));
#endif /* ATU_DYNAMIC_CFG_ENABLED */

    /*
     * Clear the ATU base address in the global data structure
     * for the ATU driver
     */

    dev = NULL;

    return err;
}

#if ATU_DYNAMIC_CFG_ENABLED

enum atu_error_t atu_rse_map_addr_to_log_addr(struct atu_dev_t *dev, uint64_t phys_addr,
                                              uint32_t log_addr, uint32_t size,
                                              uint32_t out_bus_attr)
{
    struct atu_region_map_t addr_req = {
        .log_addr = log_addr,
        .out_bus_attr = out_bus_attr,
        .phys_addr = phys_addr,
        .size = size
    };

    if (dev == NULL) {
        return ATU_ERR_MEM_INVALID_ARG;
    }

    return atu_map_addr(dev, &addr_req);
}

enum atu_error_t atu_rse_map_addr_automatically(struct atu_dev_t *dev, uint64_t phys_addr,
                                                uint32_t size, uint32_t out_bus_attr,
                                                uint32_t *log_addr, uint32_t *avail_size)
{
    enum atu_error_t err = ATU_ERR_NONE;
    struct atu_region_map_t addr_req = {
        .dynamically_allocate_logical_address = true,
        .out_bus_attr = out_bus_attr,
        .phys_addr = phys_addr,
        .size = size
    };

    if (dev == NULL) {
        return ATU_ERR_MEM_INVALID_ARG;
    }

    err = atu_map_addr(dev, &addr_req);

    if (err == ATU_ERR_NONE) {
        *log_addr = addr_req.log_addr;
        *avail_size = addr_req.size;
    }

    return err;
}

enum atu_error_t atu_rse_free_addr(struct atu_dev_t *dev, uint32_t log_addr)
{
    enum atu_error_t err = ATU_ERR_UNKNOWN;
    uint8_t atu_slot_idx = 0xFF;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    err = get_dyn_cfg_slot_idx(dev, log_addr, &atu_slot_idx);

    if (ATU_ERR_NONE != err) {
        return err;
    }

    switch (p_atu->aturgpv[atu_slot_idx]) {
        case 0:
            return ATU_ERR_SLOT_NOT_AVAIL;
        case 1:
            p_atu->aturgpv[atu_slot_idx] = 0;
            break;
        default:
            p_atu->aturgpv[atu_slot_idx]--;
            return ATU_ERR_NONE;
    }

    err = atu_rse_uninitialize_region(dev, atu_slot_idx);

    return err;
}

#endif /* ATU_DYNAMIC_CFG_ENABLED */
