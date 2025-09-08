/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include "array.h"
#include "tfm_boot_status.h"
#include "region_defs.h"
#include "psa_manifest/pid.h"
#include "internal_status_code.h"
#include "utilities.h"
#include "psa/service.h"
#include "thread.h"
#include "spm.h"
#include "load/partition_defs.h"
#include "tfm_hal_isolation.h"
#include "tfm_plat_shared_measurement_data.h"

/*!
 * \def BOOT_DATA_VALID
 *
 * \brief Indicates that shared data between bootloader and runtime firmware was
 *        passed the sanity check with success.
 */
#define BOOT_DATA_VALID (1u)

/*!
 * \def BOOT_DATA_INVALID
 *
 * \brief Indicates that shared data between bootloader and runtime firmware was
 *        failed on sanity check.
 */
#define BOOT_DATA_INVALID (0u)

/*!
 * \var is_boot_data_valid
 *
 * \brief Indicates the status of shared data between bootloader and runtime
 *        firmware
 */
static uint32_t is_boot_data_valid = BOOT_DATA_INVALID;

/*!
 * \struct boot_data_access_policy
 *
 * \brief Defines the access policy of secure partitions to data items in shared
 *        data area (between bootloader and runtime firmware).
 */
struct boot_data_access_policy {
    int32_t partition_id;
    uint32_t major_type;
};

/*!
 * \var access_policy_table
 *
 * \brief Contains the partition_id and major_type assignments. This describes
 *        which secure partition is allowed to access which data item
 *        (identified by major_type).
 */
static const struct boot_data_access_policy access_policy_table[] = {
    /*
     * IAR won't accept zero element array definition, so an invalid element
     * is always defined here.
     */
    {INVALID_PARTITION_ID, TLV_MAJOR_INVALID},
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    {TFM_SP_INITIAL_ATTESTATION, TLV_MAJOR_IAS},
#endif
#ifdef TFM_PARTITION_FIRMWARE_UPDATE
    {TFM_SP_FWU, TLV_MAJOR_FWU},
#endif
#ifdef TFM_PARTITION_MEASURED_BOOT
    {TFM_SP_MEASURED_BOOT, TLV_MAJOR_MBS},
#endif
#ifdef TFM_PARTITION_DPE
    {TFM_SP_DPE, TLV_MAJOR_MBS},
#endif
};

/*!
 * \brief Verify the access right of the active secure partition to the
 *        specified data type in the shared data area.
 *
 * \param[in]  major_type  Data type identifier.
 *
 * \return  Returns 0 in case of success, otherwise -1.
 */
static int32_t tfm_core_check_boot_data_access_policy(uint8_t major_type)
{
    int32_t partition_id;
    uint32_t i;
    int32_t rc = -1;
    const uint32_t array_size = ARRAY_SIZE(access_policy_table);

    partition_id = tfm_spm_partition_get_running_partition_id();

    /*
     * The first element of the access_policy_table is an invalid element,
     * which isn't need to be checked, that's why the iteration
     * starts from i=1.
     */
    for (i = 1; i < array_size; ++i) {
        if (partition_id == access_policy_table[i].partition_id) {
            if (major_type == access_policy_table[i].major_type) {
                rc = 0;
                break;
            }
        }
    }

    return rc;
}

void tfm_core_validate_boot_data(void)
{
#ifdef BOOT_DATA_AVAILABLE
    struct tfm_boot_data *boot_data;
    const uintptr_t data_base = tfm_plat_get_shared_measurement_data_base();
    const uintptr_t data_limit = data_base + tfm_plat_get_shared_measurement_data_size() - 1;

    const bool overlapping_with_ns =
        ((data_base >= NS_DATA_START) && (data_base <= NS_DATA_LIMIT)) ||
        ((data_limit >= NS_DATA_START) && (data_limit <= NS_DATA_LIMIT));
    if (overlapping_with_ns) {
        assert(false);
        /* Not setting BOOT_DATA_VALID */
        return;
    }

    boot_data = (struct tfm_boot_data *)data_base;

    if (boot_data->header.tlv_magic == SHARED_DATA_TLV_INFO_MAGIC) {
        is_boot_data_valid = BOOT_DATA_VALID;
    }
#else
    is_boot_data_valid = BOOT_DATA_VALID;
#endif /* BOOT_DATA_AVAILABLE */
}

void tfm_core_get_boot_data_handler(uint32_t args[])
{
    uint8_t  tlv_major = (uint8_t)args[0];
    uint8_t *buf_start = (uint8_t *)args[1];
    uint16_t buf_size  = (uint16_t)args[2];
    struct tfm_boot_data *boot_data;
#ifdef BOOT_DATA_AVAILABLE
    uint8_t *ptr;
    struct shared_data_tlv_entry tlv_entry;
    uintptr_t tlv_end, offset;
    size_t next_tlv_offset = 0;
#endif /* BOOT_DATA_AVAILABLE */
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    FIH_CALL(tfm_hal_memory_check, fih_rc,
             curr_partition->boundary, (uintptr_t)buf_start,
             buf_size, TFM_HAL_ACCESS_READWRITE);
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        args[0] = (uint32_t)PSA_ERROR_INVALID_ARGUMENT;
        return;
    }

    if (is_boot_data_valid != BOOT_DATA_VALID) {
        args[0] = (uint32_t)PSA_ERROR_INVALID_ARGUMENT;
        return;
    }

    /* Check whether caller has access right to given tlv_major_type */
    if (tfm_core_check_boot_data_access_policy(tlv_major)) {
        args[0] = (uint32_t)PSA_ERROR_INVALID_ARGUMENT;
        return;
    }

#ifdef BOOT_DATA_AVAILABLE
    const uintptr_t data_base = tfm_plat_get_shared_measurement_data_base();
    /* Get the boundaries of TLV section */
    boot_data = (struct tfm_boot_data *)data_base;
    tlv_end = data_base + boot_data->header.tlv_tot_len;
    offset = data_base + SHARED_DATA_HEADER_SIZE;
#endif /* BOOT_DATA_AVAILABLE */

    /* Add header to output buffer as well */
    if (buf_size < SHARED_DATA_HEADER_SIZE) {
        args[0] = (uint32_t)PSA_ERROR_INVALID_ARGUMENT;
        return;
    } else {
        boot_data = (struct tfm_boot_data *)buf_start;
        boot_data->header.tlv_magic   = SHARED_DATA_TLV_INFO_MAGIC;
        boot_data->header.tlv_tot_len = SHARED_DATA_HEADER_SIZE;
    }

#ifdef BOOT_DATA_AVAILABLE
    ptr = boot_data->data;
    /* Iterates over the TLV section and copy TLVs with requested major
     * type to the provided buffer.
     */
    for (; offset < tlv_end; offset += next_tlv_offset) {
        /* Create local copy to avoid unaligned access */
        (void)spm_memcpy(&tlv_entry, (const void *)offset,
                         SHARED_DATA_ENTRY_HEADER_SIZE);

        next_tlv_offset = SHARED_DATA_ENTRY_HEADER_SIZE + tlv_entry.tlv_len;

        if (GET_MAJOR(tlv_entry.tlv_type) == tlv_major) {
            /* Check buffer overflow */
            if (((ptr - buf_start) + next_tlv_offset) > buf_size) {
                args[0] = (uint32_t)PSA_ERROR_INVALID_ARGUMENT;
                return;
            }

            (void)spm_memcpy(ptr, (const void *)offset, next_tlv_offset);
            ptr += next_tlv_offset;
            boot_data->header.tlv_tot_len += next_tlv_offset;
        }
    }
#endif /* BOOT_DATA_AVAILABLE */

    args[0] = (uint32_t)PSA_SUCCESS;
    return;
}
