/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdint.h>

#include "device_definition.h"
#include "lcm_drv.h"
#include "rse_otp_dev.h"
#include "rse_zero_count.h"
#include "rse_zero_count_regions.h"
#include "tfm_hal_platform.h"
#include "tfm_plat_otp.h"

struct zero_count_region_details_t {
    uint32_t region_start_offset;
    uint32_t region_size;
    uint32_t zero_count_offset;
};

static enum tfm_plat_err_t get_zero_count_region(enum zero_count_regions_t region_id,
                                                 struct zero_count_region_details_t *region_details)
{
    uint32_t rotpk_index;
    uint32_t rotpk_base_offset;

    if ((region_id >= ZC_OTP_CM_ROTPK_AREA_R0)
        && (region_id <= ZC_OTP_CM_ROTPK_AREA_RMAX)) {
        rotpk_index = region_id - ZC_OTP_CM_ROTPK_AREA_R0;
        rotpk_base_offset = cm_area_info.offset + cm_area_info.size
            - sizeof(P_RSE_OTP_CM->rotpk_areas)
            + (sizeof(struct rse_otp_cm_rotpk_area_t) * rotpk_index);
        region_details->region_start_offset = rotpk_base_offset + sizeof(uint32_t);
        region_details->region_size = sizeof(struct rse_otp_cm_rotpk_area_t) - sizeof(uint32_t);
        region_details->zero_count_offset = rotpk_base_offset;
        return TFM_PLAT_ERR_SUCCESS;
    }

    if ((region_id >= ZC_OTP_DM_ROTPK_AREA_R0)
        && (region_id <= ZC_OTP_DM_ROTPK_AREA_RMAX)) {
        rotpk_index = region_id - ZC_OTP_DM_ROTPK_AREA_R0;
        rotpk_base_offset = dm_area_info.offset + dm_area_info.size
            - sizeof(P_RSE_OTP_DM->rotpk_areas)
            + (sizeof(struct rse_otp_dm_rotpk_area_t) * rotpk_index);
        region_details->region_start_offset = rotpk_base_offset + sizeof(uint32_t);
        region_details->region_size = sizeof(struct rse_otp_dm_rotpk_area_t) - sizeof(uint32_t);
        region_details->zero_count_offset = rotpk_base_offset;
        return TFM_PLAT_ERR_SUCCESS;
    }

    switch (region_id)
    {
    case ZC_OTP_HEADER_CM_AREA:
        region_details->region_start_offset = offsetof(struct rse_otp_header_area_t, cm_area_info.raw_data);
        region_details->region_size = sizeof(P_RSE_OTP_HEADER->cm_area_info.raw_data);
        region_details->zero_count_offset = offsetof(struct rse_otp_header_area_t, cm_area_info_zero_count);
        break;

    case ZC_OTP_HEADER_BL1_2_AREA:
        region_details->region_start_offset = offsetof(struct rse_otp_header_area_t, bl1_2_area_info.raw_data);
        region_details->region_size = sizeof(P_RSE_OTP_HEADER->bl1_2_area_info.raw_data);
        region_details->zero_count_offset = offsetof(struct rse_otp_header_area_t, bl1_2_area_info_zero_count);
        break;

    case ZC_OTP_HEADER_DM_AREA:
        region_details->region_start_offset = offsetof(struct rse_otp_header_area_t, dm_area_info.raw_data);
        region_details->region_size = sizeof(P_RSE_OTP_HEADER->dm_area_info.raw_data);
        region_details->zero_count_offset = offsetof(struct rse_otp_header_area_t, dm_area_info_zero_count);
        break;

    case ZC_OTP_HEADER_DYNAMIC_AREA:
        region_details->region_start_offset = offsetof(struct rse_otp_header_area_t, dynamic_area_info.raw_data);
        region_details->region_size = sizeof(P_RSE_OTP_HEADER->dynamic_area_info.raw_data);
        region_details->zero_count_offset = offsetof(struct rse_otp_header_area_t, dynamic_area_info_zero_count);
        break;

    case ZC_OTP_HEADER_SOC_AREA:
        region_details->region_start_offset = offsetof(struct rse_otp_header_area_t, soc_area_info.raw_data);
        region_details->region_size = sizeof(P_RSE_OTP_HEADER->soc_area_info.raw_data);
        region_details->zero_count_offset = offsetof(struct rse_otp_header_area_t, soc_area_info_zero_count);
        break;

    case ZC_OTP_CM_AREA:
        region_details->region_start_offset = cm_area_info.offset + offsetof(struct rse_otp_cm_area_t, zero_count) + sizeof(uint32_t);
        region_details->region_size = cm_area_info.size - sizeof(uint32_t) - sizeof(P_RSE_OTP_CM->rotpk_areas);
        region_details->zero_count_offset = cm_area_info.offset + offsetof(struct rse_otp_cm_area_t, zero_count);
        break;

    case ZC_OTP_CM_ROTPK_AREA:
        region_details->region_start_offset = cm_rotpk_area_info.offset + offsetof(struct rse_otp_cm_rotpk_area_t, zero_count) + sizeof(uint32_t);
        region_details->region_size = cm_rotpk_area_info.size - sizeof(uint32_t);
        region_details->zero_count_offset = cm_rotpk_area_info.offset + offsetof(struct rse_otp_cm_rotpk_area_t, zero_count);
        break;

    case ZC_OTP_BL1_2_AREA:
        region_details->region_start_offset = bl1_2_area_info.offset + offsetof(struct rse_otp_bl1_2_area_t, zero_count) + sizeof(uint32_t);
        region_details->region_size = bl1_2_area_info.size - sizeof(uint32_t);
        region_details->zero_count_offset = bl1_2_area_info.offset + offsetof(struct rse_otp_bl1_2_area_t, zero_count);
        break;

    case ZC_OTP_DM_AREA:
        region_details->region_start_offset = dm_area_info.offset + offsetof(struct rse_otp_dm_area_t, zero_count) + sizeof(uint32_t);
        region_details->region_size = dm_area_info.size - sizeof(uint32_t) - sizeof(P_RSE_OTP_DM->rotpk_areas);
        region_details->zero_count_offset = dm_area_info.offset + offsetof(struct rse_otp_dm_area_t, zero_count);
        break;

    case ZC_OTP_DM_ROTPK_AREA:
        region_details->region_start_offset = dm_rotpk_area_info.offset + offsetof(struct rse_otp_dm_rotpk_area_t, zero_count) + sizeof(uint32_t);
        region_details->region_size = dm_rotpk_area_info.size - sizeof(uint32_t);
        region_details->zero_count_offset = dm_rotpk_area_info.offset + offsetof(struct rse_otp_dm_rotpk_area_t, zero_count);
        break;

#ifdef RSE_OTP_HAS_SOC_AREA
    case ZC_OTP_SOC_AREA_UID:
        region_details->region_start_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_id_area.unique_id);
        region_details->region_size = sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id);
        region_details->zero_count_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_id_area.zero_count_unique_id);
        break;

    case ZC_OTP_SOC_AREA_IDS:
        region_details->region_start_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_id_area.family_id);
        region_details->region_size = sizeof(P_RSE_OTP_SOC->soc_id_area.family_id) + sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid);
        region_details->zero_count_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_id_area.zero_count_id);
        break;

    case ZC_OTP_SOC_CFG_DATA:
        region_details->region_start_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_cfg_area.soc_cfg_data_zc) + sizeof(uint32_t);
        region_details->region_size = sizeof(P_RSE_OTP_SOC->soc_cfg_area) - sizeof(uint32_t);
        region_details->zero_count_offset = soc_area_info.offset + offsetof(struct rse_otp_soc_area_t, soc_cfg_area.soc_cfg_data_zc);
        break;
#endif /*RSE_OTP_HAS_SOC_AREA*/
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_zc_region_write_zero_count(enum zero_count_regions_t region_id)
{
    struct zero_count_region_details_t region_details;
    enum tfm_plat_err_t res;
    enum lcm_error_t lcm_err;
    uint32_t zero_count;

    res = get_zero_count_region(region_id, &region_details);
    if (res != TFM_PLAT_ERR_SUCCESS) {
        return res;
    }

    res = rse_count_zero_bits((uint8_t *)((uintptr_t)OTP_BASE_S + region_details.region_start_offset),
                              region_details.region_size, &zero_count);
    if (res != TFM_PLAT_ERR_SUCCESS) {
        return res;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, region_details.zero_count_offset,
                            sizeof(zero_count), (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_zc_region_check_zero_count(enum zero_count_regions_t region_id, bool pass_empty)
{
    struct zero_count_region_details_t region_details;
    enum tfm_plat_err_t res;
    uint32_t *p_zero_count;

    res = get_zero_count_region(region_id, &region_details);
    if (res != TFM_PLAT_ERR_SUCCESS) {
        return res;
    }

    p_zero_count = (uint32_t *)((uintptr_t)OTP_BASE_S + region_details.zero_count_offset);
    if (pass_empty && (*p_zero_count == 0)) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    return rse_check_zero_bit_count((uint8_t *)((uintptr_t)OTP_BASE_S + region_details.region_start_offset),
                                   region_details.region_size,
                                   *p_zero_count);
}
