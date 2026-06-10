/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa/client.h"
#include "psa_manifest/sid.h"
#include "tfm_its_defs.h"
#include "psa_manifest/pid.h"
#include "tfm_internal_trusted_storage.h"

uint8_t *p_psa_src_data;
uint8_t *p_psa_dest_data;

psa_status_t psa_its_set(psa_storage_uid_t uid,
                         size_t data_length,
                         void *p_data,
                         psa_storage_create_flags_t create_flags)
{
    p_psa_src_data = (uint8_t *)p_data;

    return tfm_its_set(TFM_SP_PS, uid, data_length, create_flags);
}

psa_status_t psa_its_get(psa_storage_uid_t uid,
                         size_t data_offset,
                         size_t data_size,
                         void *p_data,
                         size_t *p_data_length)
{
    if (p_data_length == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    p_psa_dest_data = p_data;

    return tfm_its_get(TFM_SP_PS, uid, data_offset, data_size, p_data_length);
}

psa_status_t psa_its_get_info(psa_storage_uid_t uid,
                              struct psa_storage_info_t *p_info)
{
    return tfm_its_get_info(TFM_SP_PS, uid, p_info);
}

psa_status_t psa_its_remove(psa_storage_uid_t uid)
{
    return tfm_its_remove(TFM_SP_PS, uid);
}
