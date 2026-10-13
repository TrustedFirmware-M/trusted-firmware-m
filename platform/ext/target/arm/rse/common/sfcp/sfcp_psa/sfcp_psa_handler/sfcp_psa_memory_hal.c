/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include "sfcp_psa_rse.h"
#include "sfcp_permissions_hal.h"

psa_status_t sfcp_psa_map_buffer(struct client_request_t *req, uint64_t address, uint32_t size,
                                 bool writable, void **mapped)
{
    struct sfcp_psa_rse_request_t *data = req->platform_data;
    uint8_t region;
    enum tfm_plat_err_t err;

    if (data == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    err = comms_permissions_memory_check(req->remote_id, address, size, writable);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_NOT_PERMITTED;
    }
    err = comms_atu_alloc_region(address, size, &region);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    err = comms_atu_add_region_to_set(&data->atu_regions, region);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        (void)comms_atu_free_region(region);
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    err = comms_atu_get_rse_ptr_from_host_addr(region, address, mapped);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    return PSA_SUCCESS;
}

void sfcp_psa_unmap_buffers(struct client_request_t *req)
{
    struct sfcp_psa_rse_request_t *data = req->platform_data;
    if (data != NULL) {
        (void)comms_atu_free_regions(data->atu_regions);
        memset(&data->atu_regions, 0, sizeof(data->atu_regions));
    }
}
