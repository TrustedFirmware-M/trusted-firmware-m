/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_GET_SOC_INFO_REG_H__
#define __RSE_GET_SOC_INFO_REG_H__

#include <stdint.h>
#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Retrieves the current value of the SoC information register.
 *
 * This function must be implemented by the platform. It reads the
 * platform-specific SOC_INFO_REG value, which may be used for device
 * attestation or identification purposes.
 *
 * \param[out] reg_val Pointer to a variable where the SOC_INFO_REG value will be stored.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t rse_get_soc_info_reg(uint32_t *reg_val);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_GET_SOC_INFO_REG_H__ */
