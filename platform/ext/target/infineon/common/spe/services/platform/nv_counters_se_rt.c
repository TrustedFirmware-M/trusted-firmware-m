/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "tfm_plat_nv_counters.h"

#include "ifx_se_fih.h"
#include "ifx_se_platform.h"
#include "ifx_se_tfm_utils.h"
#include <string.h>

/*! \brief RRAM counters 0..2 are used for Protected Storage */
#define IFX_PLAT_NV_COUNTER_PS_0        IFX_SE_RRAM_ROLLBACK_COUNTER_NUM_MIN

/*! \brief RRAM counters 3..5 are used for NS */
#define IFX_PLAT_NV_COUNTER_NS_0        (IFX_PLAT_NV_COUNTER_PS_0 \
                                         + ((uint32_t)PLAT_NV_COUNTER_PS_2 \
                                            - (uint32_t)PLAT_NV_COUNTER_PS_0 + 1U))

/*! \brief Number of RRAM counters use by Platform Service */
#define IFX_PLAT_RRAM_COUNTER_NUMBER    ((PLAT_NV_COUNTER_PS_2 - PLAT_NV_COUNTER_PS_0 + 1U) \
                                         + (PLAT_NV_COUNTER_NS_2 - PLAT_NV_COUNTER_NS_0 + 1U))

/* Check that TF-M RRAM counters can be handled */
#if (IFX_PLAT_RRAM_COUNTER_NUMBER > ((IFX_SE_RRAM_ROLLBACK_COUNTER_NUM_MAX \
                                      - IFX_SE_RRAM_ROLLBACK_COUNTER_NUM_MIN) + 1U))
#error "IFX_PLAT_RRAM_COUNTER_NUMBER is unexpected. SE counters amount less than expected by TF-M."
#endif

/* Convert from a TF-M counter_id to an SE IPC counter number */
static enum tfm_plat_err_t ifx_map_counter_num(enum tfm_nv_counter_t counter_id,
                                               ifx_se_fih_t *num)
{
    uint32_t mapped_id;
    switch (counter_id) {
#ifdef TFM_PARTITION_PROTECTED_STORAGE
        case (PLAT_NV_COUNTER_PS_0):
        case (PLAT_NV_COUNTER_PS_1):
        case (PLAT_NV_COUNTER_PS_2):
            mapped_id = IFX_PLAT_NV_COUNTER_PS_0
                         + (uint32_t)counter_id
                         - (uint32_t)PLAT_NV_COUNTER_PS_0;
            break;
#endif

        case (PLAT_NV_COUNTER_NS_0):
        case (PLAT_NV_COUNTER_NS_1):
        case (PLAT_NV_COUNTER_NS_2):
            mapped_id = IFX_PLAT_NV_COUNTER_NS_0
                         + (uint32_t)counter_id
                         - (uint32_t)PLAT_NV_COUNTER_NS_0;
            break;

        default:
            return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *num = ifx_se_fih_uint_encode(mapped_id);
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_init_nv_counter(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_read_nv_counter(enum tfm_nv_counter_t counter_id,
                                             uint32_t size, uint8_t *val)
{
    ifx_se_fih_t ctr_num;
    uint32_t ctr_val;
    ifx_se_status_t status;
    ifx_se_fih_uint ctr_fih = {0};
    enum tfm_plat_err_t ret = TFM_PLAT_ERR_SYSTEM_ERR;

    /* This check ensure that we can treat val as a uint32_t * */
    if (size != sizeof(uint32_t)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (ifx_map_counter_num(counter_id, &ctr_num) != TFM_PLAT_ERR_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = ifx_se_get_rollback_counter(ctr_num,
                                         ifx_se_fih_ptr_encode(&ctr_fih),
                                         IFX_SE_TFM_SYSCALL_CONTEXT);

    if (IFX_SE_IS_STATUS_SUCCESS(status))
    {
        ctr_val = ifx_se_fih_uint_decode(ctr_fih);
        memcpy(val, &ctr_val, sizeof(ctr_val));
        ret = TFM_PLAT_ERR_SUCCESS;
    }

    return ret;
}

enum tfm_plat_err_t tfm_plat_increment_nv_counter(
                                              enum tfm_nv_counter_t counter_id)
{
    ifx_se_fih_t ctr_num;
    ifx_se_status_t status;
    ifx_se_fih_uint ctr_fih = {0};
    uint32_t val;

    if (ifx_map_counter_num(counter_id, &ctr_num) != TFM_PLAT_ERR_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = ifx_se_get_rollback_counter(ctr_num,
                                         ifx_se_fih_ptr_encode(&ctr_fih),
                                         IFX_SE_TFM_SYSCALL_CONTEXT);
    if (IFX_SE_IS_STATUS_SUCCESS(status)) {
        val = ifx_se_fih_uint_decode(ctr_fih);
        status = ifx_se_update_rollback_counter(ctr_num,
                                                ifx_se_fih_uint_encode(val + 1U),
                                                IFX_SE_TFM_SYSCALL_CONTEXT);
    }

    if (!IFX_SE_IS_STATUS_SUCCESS(status)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
