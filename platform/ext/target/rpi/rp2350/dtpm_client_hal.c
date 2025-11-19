/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "dtpm_client_partition_hal.h"

enum tfm_plat_err_t tfm_plat_get_security_config_data(struct security_config *security_config,
                                                      size_t *security_config_len,
                                                      size_t security_config_max_len)
{
    *security_config_len = 0;
    (void)security_config;
    (void)security_config_max_len;

    return TFM_PLAT_ERR_SUCCESS;
}
