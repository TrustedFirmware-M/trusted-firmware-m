/*
 * Copyright (c) 2017-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <arm_cmse.h>

#include "tfm_svc.h"
#include "tfm_secure_api.h"
#include "tfm_internal.h"
#include "secure_fw/include/tfm_spm_services_api.h"
#include "spm_api.h"

uint8_t *tfm_scratch_area;
uint32_t tfm_scratch_area_size;
nsfptr_t ns_entry;

void jump_to_ns_code(void)
{
#if TFM_LVL == 3 || ((!defined(TFM_PSA_API)) && (TFM_LVL != 1))
    /* Initialization is done, set thread mode to unprivileged. */
    tfm_spm_partition_change_privilege(TFM_PARTITION_UNPRIVILEGED_MODE);
#endif
    /* All changes made to memory will be effective after this point */
    __DSB();
    __ISB();

    /* Calls the non-secure Reset_Handler to jump to the non-secure binary */
    ns_entry();
}

#ifndef TFM_PSA_API
__attribute__((naked))
int32_t tfm_core_memory_permission_check(const void *ptr,
                                         uint32_t len,
                                         int32_t access)
{
  __ASM volatile(
        "SVC    %0\n"
        "BX     lr\n"
        : : "I" (TFM_SVC_MEMORY_CHECK));
}

__attribute__((naked))
int32_t tfm_core_get_caller_client_id(int32_t *caller_client_id)
{
    __ASM volatile(
        "SVC %0\n"
        "BX LR\n"
        : : "I" (TFM_SVC_GET_CALLER_CLIENT_ID));
}

__attribute__((naked))
int32_t tfm_spm_request_reset_vote(void)
{
    __ASM volatile(
        "MOVS   R0, %0\n"
        "B      tfm_spm_request\n"
        : : "I" (TFM_SPM_REQUEST_RESET_VOTE));
}

__attribute__((naked))
int32_t tfm_spm_request(void)
{
    __ASM volatile(
        "SVC    %0\n"
        "BX     lr\n"
        : : "I" (TFM_SVC_SPM_REQUEST));
}

__attribute__((naked))
int32_t tfm_core_validate_secure_caller(void)
{
    __ASM volatile(
        "SVC    %0\n"
        "BX     lr\n"
        : : "I" (TFM_SVC_VALIDATE_SECURE_CALLER));
}

__attribute__((naked))
int32_t tfm_core_set_buffer_area(enum tfm_buffer_share_region_e share)
{
    __ASM volatile(
        "SVC    %0\n"
        "BX     lr\n"
        : : "I" (TFM_SVC_SET_SHARE_AREA));
}
#endif

__attribute__((naked))
int32_t tfm_core_get_boot_data(uint8_t major_type,
                               struct tfm_boot_data *boot_status,
                               uint32_t len)
{
    __ASM volatile(
        "SVC    %0\n"
        "BX     lr\n"
        : : "I" (TFM_SVC_GET_BOOT_DATA));
}
