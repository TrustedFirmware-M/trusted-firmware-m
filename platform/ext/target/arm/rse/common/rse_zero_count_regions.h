/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_ZERO_COUNT_REGIONS_H__
#define __RSE_ZERO_COUNT_REGIONS_H__

#include <stdbool.h>

#include "lcm_drv.h"
#include "tfm_hal_platform.h"
#include "rse_otp_dev.h"
#include "rse_otp_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Defines a set of OTP areas on which the APIs of this module
 *        can compute or check the zero count
 */
enum zero_count_regions_t {
    ZC_OTP_HEADER_CM_AREA = 0x1,
    ZC_OTP_HEADER_BL1_2_AREA,
    ZC_OTP_HEADER_DM_AREA,
    ZC_OTP_HEADER_DYNAMIC_AREA,
    ZC_OTP_HEADER_SOC_AREA,
    ZC_OTP_CM_AREA,
    ZC_OTP_CM_ROTPK_AREA,
    ZC_OTP_BL1_2_AREA,
    ZC_OTP_DM_AREA,
    ZC_OTP_DM_ROTPK_AREA,
    ZC_OTP_SOC_AREA_UID,
    ZC_OTP_SOC_AREA_IDS,
    ZC_OTP_SOC_CFG_DATA,
    ZC_OTP_CM_ROTPK_AREA_R0,
    ZC_OTP_CM_ROTPK_AREA_RMAX = ZC_OTP_CM_ROTPK_AREA_R0 + RSE_OTP_CM_ROTPK_MAX_REVOCATIONS,
    ZC_OTP_DM_ROTPK_AREA_R0,
    ZC_OTP_DM_ROTPK_AREA_RMAX = ZC_OTP_DM_ROTPK_AREA_R0 + RSE_OTP_DM_ROTPK_MAX_REVOCATIONS,

    __ZERO_COUNT_REGIONS_MAX_VALUE = INT32_MAX,
};

/**
 * @brief Helper function that takes as input a OTP region ID and computes the zero
 *        count of the region writing into the OTP field that contains the computed
 *        integrity value. It uses the APIs available in \ref rse_zero_count.h
 *
 * @param[in] region_id Region ID over which to compute the zero count
 *
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t rse_zc_region_write_zero_count(enum zero_count_regions_t region_id);
/**
 * @brief Helper function that checks the integrity value (zero count) of the
 *        requested OTP area, using the APIs in \ref rse_zero_count.h
 *
 * @param[in] region_id  Region ID for which to check the zero count
 * @param[in] pass_empty When \p true, the zero check will return success if the area
 *                       is empty (i.e. all zeros), without running the integrity checker
 *
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t rse_zc_region_check_zero_count(enum zero_count_regions_t region_id,
                                                   bool pass_empty);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_ZERO_COUNT_REGIONS_H__ */
