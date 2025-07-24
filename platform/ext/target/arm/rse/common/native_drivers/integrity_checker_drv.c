/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file integrity_checker_drv.c
 * \brief Driver for Arm Integrity Checker.
 */

#include "integrity_checker_drv.h"

#include "fatal_error.h"

#include <stdbool.h>

#ifdef IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
#include "cmsis.h"
#endif

#ifndef __IM
#define __IM volatile const /*! Defines 'read only' structure member permissions */
#endif /* __IM */

#ifndef __OM
#define __OM volatile /*! Defines 'write only' structure member permissions */
#endif /* __OM */

#ifndef __IOM
#define __IOM volatile /*! Defines 'read / write' structure member permissions */
#endif /* __IOM */

struct _integrity_checker_reg_map_t {
    __IM  uint32_t icbc;
                /*!< Offset: 0x000 (R/ ) Integrity Checker Build Configuration Register */
    __IOM uint32_t icc;
                /*!< Offset: 0x004 (R/W) Integrity Checker Configuration Register */
    __IM  uint32_t icis;
                /*!< Offset: 0x008 (R/ ) Integrity Checker Interrupt Status Register */
    __IOM uint32_t icie;
                /*!< Offset: 0x00C (R/W) Integrity Checker Interrupt Enable Register */
    __IOM uint32_t icae;
                /*!< Offset: 0x010 (R/W) Integrity Checker Alarm Enable Register */
    __IOM uint32_t icic;
                /*!< Offset: 0x014 (R/W) Integrity Checker Interrupt Clear Register */
    __IOM uint32_t icda;
                /*!< Offset: 0x018 (R/W) Integrity Checker Data Address Register */
    __IOM uint32_t icdl;
                /*!< Offset: 0x01C (R/W) Integrity Checker Data Length Register */
    __IOM uint32_t iceva;
                /*!< Offset: 0x020 (R/W) Integrity Checker Expected Value Address Register */
    __IOM uint32_t iccva;
                /*!< Offset: 0x024 (R/W) Integrity Checker Computed Value Address Register */
    __IM  uint32_t iccval[8];
                /*!< Offset: 0x028 (R/ ) Integrity Checker Computed Value Register */
    __IOM uint32_t reserved_0[0x3E1];
                /*!< Offset: 0x48-0xFCC Reserved */
    __IM  uint32_t pidr4;
                /*!< Offset: 0xFD0 (R/ ) Peripheral ID 4 */
    __IOM uint32_t reserved_1[3];
                /*!< Offset: 0xFD4-0xFDC Reserved */
    __IM  uint32_t pidr0;
                /*!< Offset: 0xFE0 (R/ ) Peripheral ID 0 */
    __IM  uint32_t pidr1;
                /*!< Offset: 0xFE4 (R/ ) Peripheral ID 1 */
    __IM  uint32_t pidr2;
                /*!< Offset: 0xFE8 (R/ ) Peripheral ID 2 */
    __IM  uint32_t pidr3;
                /*!< Offset: 0xFEC (R/ ) Peripheral ID 3 */
    __IM  uint32_t cidr0;
                /*!< Offset: 0xFF0 (R/ ) Component ID 0 */
    __IM  uint32_t cidr1;
                /*!< Offset: 0xFF4 (R/ ) Component ID 1 */
    __IM  uint32_t cidr2;
                /*!< Offset: 0xFF8 (R/ ) Component ID 2 */
    __IM  uint32_t cidr3;
                /*!< Offset: 0xFFC (R/ ) Component ID 3 */
};

enum ic_aprot {
    IC_APROT_SECURE_UNPRIVILEGED     = 0x0,
    IC_APROT_SECURE_PRIVILEGED       = 0x1,
    IC_APROT_NON_SECURE_UNPRIVILEGED = 0x2,
    IC_APROT_NON_SECURE_PRIVILEGED   = 0x3,
};

static uintptr_t remap_addr(struct integrity_checker_dev_t *dev, uintptr_t addr)
{
    uint32_t idx;
    const integrity_checker_remap_region_t *region;

    for (idx = 0; idx < INTEGRITY_CHECKER_CONFIG_REMAP_REGION_AM; idx++) {
        region = &dev->cfg->remap_regions[idx];
        if (addr >= region->region_base
            && addr < region->region_base + region->region_size) {
            return (addr - region->region_base) + region->remap_base
                    + (region->remap_cpusel_offset * dev->cfg->remap_cpusel);
        }
    }

    return addr;
}

static const size_t mode_sizes[3] = {
    INTEGRITY_CHECKER_OUTPUT_SIZE_ZERO_COUNT,
    INTEGRITY_CHECKER_OUTPUT_SIZE_CRC32,
    INTEGRITY_CHECKER_OUTPUT_SIZE_SHA256,
};

static enum integrity_checker_error_t check_mode_is_supported(
                                      struct integrity_checker_dev_t *dev,
                                      enum integrity_checker_mode_t mode,
                                      bool is_compute)
{
    struct _integrity_checker_reg_map_t* p_integrity_checker =
        (struct _integrity_checker_reg_map_t*)dev->cfg->base;
    uint32_t bitmask = (1 << (mode + 3 * (is_compute)));

    if (mode > INTEGRITY_CHECKER_MODE_SHA256) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE);
        return INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE;
    }

    if (p_integrity_checker->icbc & bitmask) {
        return INTEGRITY_CHECKER_ERROR_NONE;
    } else {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE);
        return INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE;
    }
}

static void init_integrity_checker(struct integrity_checker_dev_t *dev,
                                   uint32_t *iccval)
{
    struct _integrity_checker_reg_map_t* p_integrity_checker =
        (struct _integrity_checker_reg_map_t*)dev->cfg->base;

    /* Set MatchTriggerDisable, as it is mandatory. */
    *iccval |= 1 << 5;

    /* Set EncompvalOut so the integrity checker writes the value pointer in
     * compute mode.
     */
    *iccval |= 1 << 6;

    *iccval |= (IC_APROT_SECURE_PRIVILEGED & 0b11) << 7;
    *iccval |= (IC_APROT_SECURE_PRIVILEGED & 0b11) << 9;

    /* Disable all alarms */
    p_integrity_checker->icae = 0;

    /* Enable and clear all interrupts */
    p_integrity_checker->icie = 0xFF;
    p_integrity_checker->icic = 0xFF;
}

enum integrity_checker_error_t integrity_checker_compute_value(struct integrity_checker_dev_t *dev,
                                                               enum integrity_checker_mode_t mode,
                                                               const uint32_t *data, size_t size,
                                                               uint32_t *value, size_t value_size,
                                                               size_t *value_len)
{
    volatile uint32_t __attribute__((aligned(INTEGRITY_CHECKER_REQUIRED_ALIGNMENT)))
        temp_val[INTEGRITY_CHECKER_OUTPUT_SIZE_SHA256 / sizeof(uint32_t)] = {0};
    volatile uint32_t *value_ptr = value;
    struct _integrity_checker_reg_map_t* p_integrity_checker =
        (struct _integrity_checker_reg_map_t*)dev->cfg->base;
    enum integrity_checker_error_t err;

    uint32_t iccval = 0;

    err = check_mode_is_supported(dev, mode, true);
    if (err != INTEGRITY_CHECKER_ERROR_NONE) {
        return err;
    }

    if (value_size < mode_sizes[mode]) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_BUFFER_TOO_SMALL);
        return INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_BUFFER_TOO_SMALL;
    }

    if (((uintptr_t)data % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_ALIGNMENT);
        return INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_ALIGNMENT;
    }

    if ((size % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_LENGTH);
        return INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_LENGTH;
    }

    if (((uintptr_t)value % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        value_ptr = temp_val;
    }

    init_integrity_checker(dev, &iccval);

    /* Set algorithm */
    iccval |= (mode & 0b111) << 1;

    /* Set to compute mode */
    iccval |= 1 << 4;

#ifdef IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
    SCB_CleanInvalidateDCache_by_Addr((volatile void *)data, size);
#endif

    /* Configure input data. Size is in words */
    p_integrity_checker->icda = remap_addr(dev, (uintptr_t)data);
    p_integrity_checker->icdl = size / INTEGRITY_CHECKER_REQUIRED_ALIGNMENT;

    /* Set output address */
    p_integrity_checker->iccva = remap_addr(dev, (uintptr_t)value_ptr);

    /* Start integrity checker */
    iccval |= 1;

    p_integrity_checker->icc = iccval;

    /* Poll for any interrupts */
    while(!p_integrity_checker->icis) {}

    /* Check for any unusual error interrupts */
    if (p_integrity_checker->icis & (~0b11)) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_OPERATION_FAILED);
        return INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_OPERATION_FAILED;
    }

#ifdef IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
    SCB_CleanInvalidateDCache_by_Addr((volatile void *)value_ptr, mode_sizes[mode]);
#endif

    if (value_ptr != value) {
        for (int idx = 0; idx < mode_sizes[mode] / sizeof(uint32_t); idx++) {
            value[idx] = value_ptr[idx];
        }
    }

    if (value_len != NULL) {
        *value_len = mode_sizes[mode];
    }

    return INTEGRITY_CHECKER_ERROR_NONE;
}

enum integrity_checker_error_t integrity_checker_check_value(struct integrity_checker_dev_t *dev,
                                                             enum integrity_checker_mode_t mode,
                                                             const uint32_t *data, size_t size,
                                                             const uint32_t *value, size_t value_size)
{
    volatile uint32_t __attribute__((aligned(INTEGRITY_CHECKER_REQUIRED_ALIGNMENT)))
        temp_val[INTEGRITY_CHECKER_OUTPUT_SIZE_SHA256 / sizeof(uint32_t)] = {0};
    const volatile uint32_t *value_ptr = value;
    struct _integrity_checker_reg_map_t* p_integrity_checker =
        (struct _integrity_checker_reg_map_t*)dev->cfg->base;
    enum integrity_checker_error_t err;
    uint32_t iccval = 0;

    err = check_mode_is_supported(dev, mode, false);
    if (err != INTEGRITY_CHECKER_ERROR_NONE) {
        return err;
    }

    if (value_size < mode_sizes[mode]) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_CHECK_VALUE_BUFFER_TOO_SMALL);
        return INTEGRITY_CHECKER_ERROR_CHECK_VALUE_BUFFER_TOO_SMALL;
    }

    if (((uintptr_t)data % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_CHECK_VALUE_INVALID_ALIGNMENT);
        return INTEGRITY_CHECKER_ERROR_CHECK_VALUE_INVALID_ALIGNMENT;
    }

    if ((size % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_CHECK_VALUE_INVALID_LENGTH);
        return INTEGRITY_CHECKER_ERROR_CHECK_VALUE_INVALID_LENGTH;
    }

    if (((uintptr_t)value % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0
           || (value_size % INTEGRITY_CHECKER_REQUIRED_ALIGNMENT) != 0) {
        for (int idx = 0; idx < value_size / sizeof(uint32_t); idx++) {
            temp_val[idx] = value[idx];
        }
        value_ptr = temp_val;
    }

    init_integrity_checker(dev, &iccval);

    /* Set algorithm */
    iccval |= (mode & 0b111) << 1;

#ifdef IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
    SCB_CleanInvalidateDCache_by_Addr((volatile void *)data, size);
#endif

    /* Configure input data. Size is in words */
    p_integrity_checker->icda = remap_addr(dev, (uintptr_t)data);
    p_integrity_checker->icdl = size / INTEGRITY_CHECKER_REQUIRED_ALIGNMENT;

#ifdef IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
    SCB_CleanInvalidateDCache_by_Addr((volatile void *)value_ptr, mode_sizes[mode]);
#endif

    /* Set compare address */
    p_integrity_checker->iceva = remap_addr(dev, (uintptr_t)value_ptr);

    /* Start integrity checker */
    iccval |= 1;

    p_integrity_checker->icc = iccval;

    /* Poll for any interrupts */
    while(!p_integrity_checker->icis) {}

    /* Check for any unusual error interrupts */
    if (p_integrity_checker->icis & (~0b11)) {
        FATAL_ERR(INTEGRITY_CHECKER_ERROR_CHECK_VALUE_OPERATION_FAILED);
        return INTEGRITY_CHECKER_ERROR_CHECK_VALUE_OPERATION_FAILED;
    } else if (p_integrity_checker->icis & (0b10)) {
        /* Check for comparison failure */
        NONFATAL_ERR(INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED);
        return INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED;
    }

    return INTEGRITY_CHECKER_ERROR_NONE;
}
