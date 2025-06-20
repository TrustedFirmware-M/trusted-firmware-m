/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_HAL_DEFS_H__
#define __SCMI_HAL_DEFS_H__

#include "platform_base_address.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Base address and size of shared memory with SCP for SCMI transport */
#define SCP_SHARED_MEMORY_BASE HOST_FLASH0_TEMP_BASE_S
#define SCP_SHARED_MEMORY_SIZE 128U

#ifdef __cplusplus
}
#endif

#endif /* __SCMI_HAL_DEFS_H__ */
