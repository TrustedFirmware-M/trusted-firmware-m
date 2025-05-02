/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_OTP_DEV_H__
#define __RSE_OTP_DEV_H__

#include "device_definition.h"
#include "rse_otp_layout.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSE_OTP_HAS_CM_AREA
extern struct rse_otp_area_info_t cm_area_info;
extern struct rse_otp_area_info_t cm_rotpk_area_info;
#endif
#ifdef RSE_OTP_HAS_BL1_2
extern struct rse_otp_area_info_t bl1_2_area_info;
#endif
#ifdef RSE_OTP_HAS_DM_AREA
extern struct rse_otp_area_info_t dm_area_info;
extern struct rse_otp_area_info_t dm_rotpk_area_info;
#endif
#ifdef RSE_OTP_HAS_DYNAMIC_AREA
extern struct rse_otp_area_info_t dynamic_area_info;
#endif
#ifdef RSE_OTP_HAS_SOC_AREA
extern const struct rse_otp_area_info_t soc_area_info;
#endif

#define OTP_BASE_S (LCM_BASE_S + 0x1000)

#define OTP_OFFSET(x) (((uintptr_t)&x) - OTP_BASE_S)

/**
 * \brief Checks whether the provided area pointer is valid.
 *
 * Validity is determined by checking that both the \c offset and \c size
 * fields in the \c area_info structure are non-zero.
 *
 * \param[in] area_info Pointer to a struct rse_otp_area_info_t containing
 *                      area configuration (offset and size).
 *
 * \return true if both offset and size are non-zero; false otherwise.
 */
static inline bool __area_ptr_is_valid(struct rse_otp_area_info_t *area_info)
{
    return area_info->offset != 0 && area_info->size != 0;
}

/**
 * \brief Returns a pointer to the memory area described by the area info.
 *
 * This function validates the provided area information and, if valid,
 * returns a pointer to the corresponding memory-mapped OTP region.
 * If the area information is invalid, the function triggers an assertion
 * failure and returns NULL.
 *
 * \param[in] area_info Pointer to a struct rse_otp_area_info_t containing
 *                      the offset to compute the area base address.
 *
 * \return A pointer to the corresponding memory area if valid; otherwise, NULL.
 */
static inline volatile const void *__get_area_info_ptr(struct rse_otp_area_info_t *area_info)
{
    if (!__area_ptr_is_valid(area_info)) {
        assert(0);
        return NULL;
    }

    return (volatile const void *)(OTP_BASE_S + area_info->offset);
}

#define AREA_PTR_VALID(name) \
    (__area_ptr_is_valid(&name ## _area_info))

#define P_RSE_OTP_CM_IS_VALID       AREA_PTR_VALID(cm)
#define P_RSE_OTP_BL1_2_IS_VALID    AREA_PTR_VALID(bl1_2)
#define P_RSE_OTP_DM_IS_VALID       AREA_PTR_VALID(dm)
#define P_RSE_OTP_DYNAMIC_IS_VALID  AREA_PTR_VALID(dynamic)
#define P_RSE_OTP_SOC_IS_VALID      AREA_PTR_VALID(soc)

#define P_RSE_OTP_CM_ROTPK_IS_VALID AREA_PTR_VALID(cm_rotpk)
#define P_RSE_OTP_DM_ROTPK_IS_VALID AREA_PTR_VALID(dm_rotpk)

/**
 * \brief Checks if the specified OTP area is valid.
 *
 * This macro evaluates to a predefined validity flag for a given OTP area.
 * It is typically used to determine whether a specific OTP memory region
 * is available or properly configured.
 *
 * \param name The name of the OTP area to check. Valid values include:
 *        - \c CM
 *        - \c BL1_2
 *        - \c DM
 *        - \c DYNAMIC
 *        - \c SOC
 *        - \c CM_ROTPK
 *        - \c DM_ROTPK
 *
 * \return A boolean-like value indicating whether the specified OTP area is valid.
 */
#define IS_RSE_OTP_AREA_VALID(name) P_RSE_OTP_ ## name ## _IS_VALID

#define AREA_PTR(name) \
    ((volatile const struct rse_otp_ ## name ## _area_t *)__get_area_info_ptr(&name ## _area_info))

#define P_RSE_OTP_HEADER   ((volatile struct rse_otp_header_area_t *)(OTP_BASE_S))

#define P_RSE_OTP_CM                AREA_PTR(cm)
#define P_RSE_OTP_BL1_2             AREA_PTR(bl1_2)
#define P_RSE_OTP_DM                AREA_PTR(dm)
#define P_RSE_OTP_DYNAMIC           AREA_PTR(dynamic)
#define P_RSE_OTP_SOC               AREA_PTR(soc)

#define P_RSE_OTP_CM_ROTPK          AREA_PTR(cm_rotpk)
#define P_RSE_OTP_DM_ROTPK          AREA_PTR(dm_rotpk)

#ifdef __cplusplus
}
#endif

#endif /* __RSE_OTP_DEV_H__ */
