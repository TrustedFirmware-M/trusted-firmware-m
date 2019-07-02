/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_audit_veneers.h"
#include "secure_fw/services/audit_logging/audit_core.h"
#include "tfm_secure_api.h"
#include "spm_partition_defs.h"
#include "audit_wrappers.h"

__tfm_secure_gateway_attributes__
enum psa_audit_err tfm_audit_veneer_retrieve_record(
                                const struct audit_core_retrieve_input *input_s,
                                    struct audit_core_retrieve_output *output_s)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_AUDIT_LOG_ID,
                         (void *) audit_core_retrieve_record_wrapper,
                         input_s, output_s, 0, 0);
}

__tfm_secure_gateway_attributes__
enum psa_audit_err tfm_audit_veneer_add_record(
                                          const struct psa_audit_record *record)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_AUDIT_LOG_ID, (void *) audit_core_add_record,
                         record, 0, 0, 0);
}

__tfm_secure_gateway_attributes__
enum psa_audit_err tfm_audit_veneer_get_info(uint32_t *num_records,
                                             uint32_t *size)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_AUDIT_LOG_ID, (void *) audit_core_get_info,
                         num_records, size, 0, 0);
}

__tfm_secure_gateway_attributes__
enum psa_audit_err tfm_audit_veneer_get_record_info(const uint32_t record_index,
                                                    uint32_t *size)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_AUDIT_LOG_ID, (void *) audit_core_get_record_info,
                         record_index, size, 0, 0);
}

__tfm_secure_gateway_attributes__
enum psa_audit_err tfm_audit_veneer_delete_record(const uint32_t record_index,
                                                  const uint8_t *token,
                                                  const uint32_t token_size)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_AUDIT_LOG_ID, (void *) audit_core_delete_record,
                         record_index, token, token_size, 0);
}
