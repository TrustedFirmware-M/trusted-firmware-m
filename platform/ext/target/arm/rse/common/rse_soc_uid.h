/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_SOC_UID_H__
#define __RSE_SOC_UID_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Checks if the SoC UID has already been generated.
 *
 * This function determines whether a unique identifier (UID) for SOC
 * has been previously generated and stored.
 *
 * \return true if the UID has been generated, false otherwise.
 */
bool rse_soc_uid_is_generated(void);

/**
 * \brief Generates a unique identifier (UID) for the SoC.
 *
 * This function generates and writes a unique identifier for
 * for the SoC to the OTP. It should only be called once.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_generate_soc_uid(void);

/**
 * \brief Locks the SoC UID to prevent further modifications.
 *
 * After the UID is generated and stored, this function can be used to
 * permanently lock it, by writing the SoC UID zero count to the OTP.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_lock_soc_uid(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_SOC_UID_H__ */
