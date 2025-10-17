/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SKU_FEATURE_CONTROL_H__
#define __SKU_FEATURE_CONTROL_H__

#include <stdint.h>

/**
 * \brief Set feature control related bits in DCU_EN line based on the OTP fields.
 *
 * \param[in] lcm_dev               The LCM device structure.
 *
 *
 * \return Returns error code as specified in \ref tfm_plat_err_t
 */
enum tfm_plat_err_t rse_dcu_otp_feature_control(struct lcm_dev_t *lcm_dev);

#endif /* __SKU_FEATURE_CONTROL_H__ */
