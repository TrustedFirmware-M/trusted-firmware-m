/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "stdint.h"

#include "tfm_boot_measurement.h"
#include "tfm_crypto_defs.h"
#include "tfm_plat_nv_counters.h"

#include "boot_hal.h"
#include "rse_rotpk_mapping.h"
#include "rse_boot_measurements.h"

static int get_rotpk_sw_type(uint8_t rotpk_index, uint8_t rotpk_revocation_counter_index,
                             char *sw_type_buf, size_t sw_buf_size)
{
    size_t sw_type_str_offset = 0;
    char *prefix = "CM";
    size_t prefix_size = sizeof("CM") - 1;


    if (rotpk_index >= 10 || rotpk_revocation_counter_index >= 10) {
        return 1;
    }

    /* CM_<REVOCATION_COUNTER_INDEX>_<CM_ROTPK_INDEX>
     * Revocation counter and CM ROTPK index are assumed to be single digits.
     */
    size_t req_len = prefix_size + sizeof(char) + sizeof(char) +
                     sizeof(char) + sizeof(char);

    if (req_len > sw_buf_size) {
        return 1;
    }

    memcpy(sw_type_buf + sw_type_str_offset, prefix, prefix_size);
    sw_type_str_offset += prefix_size;

    sw_type_buf[sw_type_str_offset] = (char)('_');
    sw_type_str_offset += sizeof(char);

    sw_type_buf[sw_type_str_offset] = (char)('0' + rotpk_revocation_counter_index);
    sw_type_str_offset += sizeof(char);

    sw_type_buf[sw_type_str_offset] = (char)('_');
    sw_type_str_offset += sizeof(char);

    sw_type_buf[sw_type_str_offset] = (char)('0' + rotpk_index);
    sw_type_str_offset += sizeof(char);

    sw_type_buf[sw_type_str_offset] = '\0';

    return 0;
}

int32_t add_rotpk_hash_to_shared_area(void)
{
    size_t rotpk_len;
    int rotpk_cnt = 0;
    int32_t result;
    uint8_t index;
    uint8_t rotpk_buf[RSE_ROTPK_MAX_SIZE];
    enum rse_rotpk_hash_alg rse_hash_alg;
    uint32_t active_cm_idx;

    struct boot_measurement_metadata metadata = {
        .measurement_type = 0,
        .signer_id = { 0 },
        .signer_id_size = SIGNER_ID_MIN_SIZE,
        .sw_type = "",
        .sw_version = { 0 },
    };

    result = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_CM_ROTPK_REPROVISIONING,
                                     sizeof(active_cm_idx),
                                     (uint8_t *)&active_cm_idx);
    if (result) {
        return result;
    }

    for (enum tfm_otp_element_id_t id = PLAT_OTP_ID_CM_ROTPK;
         id < PLAT_OTP_ID_CM_ROTPK_MAX; id++, rotpk_cnt++) {
        index = BOOT_MEASUREMENT_SLOT_CM_ROTPK_0 + rotpk_cnt;

        if (tfm_plat_otp_get_size(id, &rotpk_len) != TFM_PLAT_ERR_SUCCESS) {
            return 1;
        }

        if (tfm_plat_otp_read(id, rotpk_len, rotpk_buf) != TFM_PLAT_ERR_SUCCESS) {
            return 1;
        }

        if (rse_rotpk_get_hash_alg(id, &rse_hash_alg) != TFM_PLAT_ERR_SUCCESS) {
            return 1;
        }

        if (rse_hash_alg == RSE_ROTPK_HASH_ALG_SHA256) {
            metadata.measurement_type = PSA_ALG_SHA_256;
        }
        else if (rse_hash_alg == RSE_ROTPK_HASH_ALG_SHA384) {
            metadata.measurement_type = PSA_ALG_SHA_384;
        }
        else {
            return 1;
        }

        get_rotpk_sw_type(rotpk_cnt, active_cm_idx,
                          (char *)&metadata.sw_type, sizeof(metadata.sw_type));

        result = boot_store_measurement(index, rotpk_buf,
                                        rotpk_len, &metadata, true);
        if (result) {
            return result;
        }
    }

    return 0;
}
