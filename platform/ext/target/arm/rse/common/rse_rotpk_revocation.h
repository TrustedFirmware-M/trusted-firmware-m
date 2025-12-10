/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_ROTPK_REVOCATION_H__
#define __RSE_ROTPK_REVOCATION_H__

#include <stddef.h>
#include <stdbool.h>

#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Revoke the currently provisioned CM ROTPK set.
 *
 * If \p specify_idx is false the next sequential ROTPK slot is selected.
 * Otherwise the revocation counter is moved to \p new_idx.
 *
 * \param[in] specify_idx  True to use the caller-provided \p new_idx.
 * \param[in] new_idx      New revocation counter value
 *
 * \return TFM_PLAT_ERR_SUCCESS on success or a platform error code.
 */
enum tfm_plat_err_t rse_revoke_cm_rotpks(bool specify_idx, uint32_t new_idx);

/**
 * \brief Revoke the currently provisioned DM ROTPK set.
 *
 * If \p specify_idx is false the next sequential ROTPK slot is selected.
 * Otherwise the revocation counter is moved to \p new_idx.
 *
 * \param[in] specify_idx  True to use the caller-provided \p new_idx.
 * \param[in] new_idx      New revocation counter value.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success or a platform error code.
 */
enum tfm_plat_err_t rse_revoke_dm_rotpks(bool specify_idx, uint32_t new_idx);

/**
 * \brief Provision a new CM ROTPK array and associated policies.
 *
 * Moves the revocation counter to a new value if the current array has been provisioned.
 * If \p specify_idx is true then, the counter is moved to \p new_idx and the
 * ROTPKs and policies given are then provisioned.
 *
 * \param[in] specify_idx  True to use the caller-provided \p new_idx.
 * \param[in] new_idx      New revocation counter value.
 * \param[in] policies     Policy bits to store alongside the ROTPK array.
 * \param[in] rotpks       Buffer holding CM ROTPK values.
 * \param[in] rotpks_len   Size of \p rotpks in bytes; must match the OTP layout.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success or a platform/LCM error code.
 */
enum tfm_plat_err_t rse_update_cm_rotpks(bool specify_idx, uint32_t new_idx, uint32_t policies,
                                         uint8_t *rotpks, size_t rotpks_len);

/**
 * \brief Provision a new DM ROTPK array and associated policies.
 *
 * Moves the revocation counter to a new value if the current array has been provisioned.
 * If \p specify_idx is true then, the counter is moved to \p new_idx and the
 * ROTPKs and policies given are then provisioned.
 *
 * \param[in] specify_idx       True to use the caller-provided \p new_idx.
 * \param[in] new_idx           New revocation counter value.
 * \param[in] allow_revocation  Whether the ROTPKs can be revoked if necessary.
 *                              If false and the current array has been provisioned,
 *                              TFM_PLAT_ERR_DM_ROTPK_UPDATE_REVOCATION_NOT_PERMITTED
 *                              is returned.
 * \param[in] policies          Policy bits to store alongside the ROTPK array.
 * \param[in] rotpks            Buffer holding DM ROTPK values.
 * \param[in] rotpks_len        Size of \p rotpks in bytes; must match the OTP layout.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success or a platform/LCM error code.
 */
enum tfm_plat_err_t rse_update_dm_rotpks(bool specify_idx, uint32_t new_idx, bool allow_revocation,
                                         uint32_t policies, uint8_t *rotpks, size_t rotpks_len);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_ROTPK_REVOCATION_H__ */
