/*
 * Copyright (c) 2022-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MPU_ARMV8M_DRV_H
#define MPU_ARMV8M_DRV_H

#include <stdint.h>
#include "cmsis.h"

#define PRIVILEGED_DEFAULT_ENABLE 1
#define HARDFAULT_NMI_ENABLE      1

/* MAIR_ATTR. Hardware optimization of memory access, depends on memory processing type */
/* DeviceType nGnRE - non-Gathering, Non-reordering, Early Write Acknowledge */
#define MPU_ARMV8M_MAIR_ATTR_DEVICE_VAL      0x04
#define MPU_ARMV8M_MAIR_ATTR_DEVICE_IDX      0
/* Normal memory, Inner and Outer: Write-Through, Non-transient, Read allocated, Write not allocated */
#define MPU_ARMV8M_MAIR_ATTR_CODE_VAL        0xAA
#define MPU_ARMV8M_MAIR_ATTR_CODE_IDX        1
/* Normal memory, Inner and Outer: Write-Back, Non-transient, Read and Write allocated */
#define MPU_ARMV8M_MAIR_ATTR_DATA_VAL        0xFF
#define MPU_ARMV8M_MAIR_ATTR_DATA_IDX        2

enum mpu_armv8m_attr_exec_t {
    MPU_ARMV8M_XN_EXEC_OK,
    MPU_ARMV8M_XN_EXEC_NEVER
};

enum mpu_armv8m_attr_access_t {
    MPU_ARMV8M_AP_RW_PRIV_ONLY,
    MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
    MPU_ARMV8M_AP_RO_PRIV_ONLY,
    MPU_ARMV8M_AP_RO_PRIV_UNPRIV
};

enum mpu_armv8m_attr_shared_t {
    MPU_ARMV8M_SH_NONE,
    MPU_ARMV8M_SH_UNUSED,
    MPU_ARMV8M_SH_OUTER,
    MPU_ARMV8M_SH_INNER
};

struct mpu_armv8m_region_cfg_t {
    uint32_t region_base; /* First address of protected region */
    uint32_t region_limit; /* Last address of protected region */
    uint32_t region_attridx;
    enum mpu_armv8m_attr_exec_t     attr_exec;
    enum mpu_armv8m_attr_access_t   attr_access;
    enum mpu_armv8m_attr_shared_t   attr_sh;
};

#endif /* MPU_ARMV8M_DRV_H */
