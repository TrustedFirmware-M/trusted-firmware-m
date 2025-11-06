/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_PLAT_DEFS_H__
#define __SCMI_PLAT_DEFS_H__

#include "platform_base_address.h"

#ifndef SCP_SHARED_MEMORY_BASE
/* Base address and size of shared memory with SCP for SCMI transport */
#define SCP_SHARED_MEMORY_BASE HOST_FLASH0_TEMP_BASE_S
#define SCP_SHARED_MEMORY_SIZE (128U)

/* The shared memory is split in 2 halves to allow for Agent->Platform and Platform->Agent */
#define SCP_SHARED_MEMORY_RECEIVER_BASE (SCP_SHARED_MEMORY_BASE + (SCP_SHARED_MEMORY_SIZE / 2))
#endif

#endif /* __SCMI_PLAT_DEFS_H__ */
