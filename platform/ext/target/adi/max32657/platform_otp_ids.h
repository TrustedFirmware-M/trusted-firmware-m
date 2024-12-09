/*
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PLATFORM_OTP_IDS_H__
#define __PLATFORM_OTP_IDS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_otp_element_id_t {
    PLAT_OTP_ID_HUK = 0,
    PLAT_OTP_ID_IAK,
    PLAT_OTP_ID_IAK_LEN,
    PLAT_OTP_ID_IAK_TYPE,
    PLAT_OTP_ID_IAK_ID,

    PLAT_OTP_ID_BOOT_SEED,
    PLAT_OTP_ID_LCS,
    PLAT_OTP_ID_IMPLEMENTATION_ID,
    PLAT_OTP_ID_CERT_REF,
    PLAT_OTP_ID_VERIFICATION_SERVICE_URL,
    PLAT_OTP_ID_PROFILE_DEFINITION,

    /* BL2 ROTPK must be contiguous */
    PLAT_OTP_ID_BL2_ROTPK_0,
    PLAT_OTP_ID_BL2_ROTPK_1,
    PLAT_OTP_ID_BL2_ROTPK_2,
    PLAT_OTP_ID_BL2_ROTPK_3,

    /* BL2 NV counters must be contiguous */
    PLAT_OTP_ID_NV_COUNTER_BL2_0,
    PLAT_OTP_ID_NV_COUNTER_BL2_1,
    PLAT_OTP_ID_NV_COUNTER_BL2_2,
    PLAT_OTP_ID_NV_COUNTER_BL2_3,

    PLAT_OTP_ID_NV_COUNTER_NS_0,
    PLAT_OTP_ID_NV_COUNTER_NS_1,
    PLAT_OTP_ID_NV_COUNTER_NS_2,

    PLAT_OTP_ID_ENTROPY_SEED,
    PLAT_OTP_ID_SECURE_DEBUG_PK,

    PLAT_OTP_ID_MAX,
};

#ifdef __cplusplus
}
#endif
#endif /* __PLATFORM_OTP_IDS_H__ */
