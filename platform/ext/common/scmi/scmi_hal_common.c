/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "scmi_hal.h"
#include "scmi_protocol.h"
#include "tfm_hal_platform.h"

int32_t scmi_hal_sys_power_state(uint32_t agent_id, uint32_t flags,
                                 uint32_t system_state)
{
    switch (system_state) {
    case SCMI_SYS_POWER_STATE_SHUTDOWN:
        return SCMI_STATUS_SUCCESS;

    case SCMI_SYS_POWER_STATE_COLD_RESET:
    case SCMI_SYS_POWER_STATE_WARM_RESET:
        /* Trigger a system reset */
        tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
        /* Should not get here */
        return SCMI_STATUS_HARDWARE_ERROR;

    case SCMI_SYS_POWER_STATE_POWER_UP:
    case SCMI_SYS_POWER_STATE_SUSPEND:
        return SCMI_STATUS_NOT_SUPPORTED;

    default:
        return SCMI_STATUS_INVALID_PARAMETERS;
    }
}
