/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "sid_drv.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "tfm_hal_device_header.h"

/* SID register offsets */
#define SID_SYSTEM_ID_OFFSET    0x40
#define SID_SOC_ID_OFFSET       0x50
#define SID_NODE_ID_OFFSET      0x60
#define SID_SYSTEM_CFG_OFFSET   0x70

/* Bit mask for CL1 presence in SYSTEM_CFG */
#define SID_SYSTEM_CFG_CL1_PRESENT_MASK (1U << 0)

/* Generic register read by offset */
static inline uint32_t sid_get_reg(const struct sid_dev_t *dev,
                                   uintptr_t offset)
{
    return *(volatile uint32_t *)(dev->sid_base + offset);
}

/* Check if CL1 is present */
bool sid_is_cl1_present(const struct sid_dev_t *dev)
{
    uint32_t system_cfg = sid_get_reg(dev, SID_SYSTEM_CFG_OFFSET);
    return (system_cfg & SID_SYSTEM_CFG_CL1_PRESENT_MASK) != 0U;
}
