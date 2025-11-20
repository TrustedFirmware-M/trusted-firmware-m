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

#include <assert.h>

#include "sam_drv.h"

#include "sam_reg_map.h"
#include "tfm_hal_device_header.h"
#include "tfm_utils.h"

/* Index in the sames, samecl, samem or samim register arrays for event_id */
#define SAMEx_IDX(event_id) ((uint32_t)(event_id) >> 0x5UL)

/* Mask for event_id in the sames, samecl, samem or samim register */
#define SAMEx_MASK(event_id) (0x1UL << ((uint32_t)(event_id) & 0x1FUL))

/* Index in the samrrls register array of response for event_id */
#define SAMRRLS_IDX(event_id) ((uint32_t)(event_id) >> 0x3UL)

/* Offset within the samrrls register of response for event_id */
#define SAMRRLS_OFF(event_id) (((uint32_t)(event_id) & 0x7UL) << 0x2UL)

/* Mask for response in the samrrls register for event_id */
#define SAMRRLS_MASK(event_id) (0xFUL << SAMRRLS_OFF(event_id))

/* Mask for NEC in SAMBC */
#define SAMBC_NUMBER_EVENT_COUNTERS_MASK (0x07)

/* Position for NEC in SAMBC */
#define SAMBC_NUMBER_EVENT_COUNTERS_POS 8

/* Mask for Initialization value for the Watchdog */
#define SAMWDCIV_INIT_VALUE_WDT_MASK (0x3FFFFFFUL)

/* Buffer to store the value of the integrity protected SAM registers */
static uint32_t icv_regs_store[(offsetof(struct sam_reg_map_t, samicv) -
                                offsetof(struct sam_reg_map_t, samem)) /
                               4];

static uint32_t count_zero_bits(uint32_t val)
{
    uint32_t res = 32;

    while (val != 0) {
        val &= val - 1;
        res--;
    }

    return res;
}

static inline bool is_invalid_event_counter(struct sam_reg_map_t *regs, volatile uint32_t *reg)
{
    const uint32_t samnec =
        ((regs->sambc >> SAMBC_NUMBER_EVENT_COUNTERS_POS) & SAMBC_NUMBER_EVENT_COUNTERS_MASK);

    return (reg > &regs->samec[samnec]) && (reg <= &regs->samec[7]);
}

static void init_icv_regs_store(struct sam_reg_map_t *regs)
{
    /* Initialise the store with the values of each of the actual (not shadow) registers. Note that
     * we include all of the EC registers
     */
    for (uint8_t i = 0; i < ARRAY_SIZE(icv_regs_store); i++) {
        volatile uint32_t *reg = (volatile uint32_t *)((uintptr_t)&regs->samem + (4 * i));

        /* If this is an event counter that we do not have, initialise the value
         * in the store to 0, it will not be used in the calculation
         */
        if (is_invalid_event_counter(regs, reg)) {
            icv_regs_store[i] = 0;
        } else {
            icv_regs_store[i] = *reg;
        }
    }
}

static void write_icv_reg(struct sam_reg_map_t *regs, volatile uint32_t *reg, uint32_t value)
{
    uint32_t zero_count = 0;
    const uint8_t regs_store_idx = ((uintptr_t)reg - (uintptr_t)&regs->samem) / 4;

    /* Update the backing store, the actual register will only be updated
     * when the ICV is written
     */
    icv_regs_store[regs_store_idx] = value;

    /* Write all of the backing store values to the shadow registers and keep
     * track of the zero count
     */
    for (uint8_t i = 0; i < ARRAY_SIZE(icv_regs_store); i++) {
        volatile uint32_t *reg = (volatile uint32_t *)((uintptr_t)&regs->samem + (4 * i));

        /* Event counters that we do not have are not included
         * in the SAMICV calculation and should not be written
         */
        if (is_invalid_event_counter(regs, reg)) {
            continue;
        }

        *reg = icv_regs_store[i];
        zero_count += count_zero_bits(icv_regs_store[i]);
    }

    regs->samicv = zero_count;
}

static uint32_t log2(uint32_t val)
{
    uint32_t res = 0;

    while (val >>= 1) {
        res++;
    }

    return res;
}

static inline struct sam_reg_map_t *get_sam_dev_base(
    const struct sam_dev_t *dev)
{
    assert(dev != NULL);
    return (struct sam_reg_map_t *)dev->cfg->base;
}

enum sam_error_t sam_init(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    init_icv_regs_store(regs);

    return SAM_ERROR_NONE;
}

enum sam_error_t sam_enable_event(const struct sam_dev_t *dev,
                                  enum sam_event_id_t event_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    if (event_id > SAM_EVENT_ID_MAX) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    if (!(regs->samim[SAMEx_IDX(event_id)] & SAMEx_MASK(event_id))) {
        write_icv_reg(regs, &regs->samim[SAMEx_IDX(event_id)],
                      regs->samim[SAMEx_IDX(event_id)] | SAMEx_MASK(event_id));
    }

    return SAM_ERROR_NONE;
}

enum sam_error_t sam_disable_event(const struct sam_dev_t *dev,
                                   enum sam_event_id_t event_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    if (event_id > SAM_EVENT_ID_MAX) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    if (regs->samim[SAMEx_IDX(event_id)] & SAMEx_MASK(event_id)) {
        write_icv_reg(regs, &regs->samim[SAMEx_IDX(event_id)],
                      regs->samim[SAMEx_IDX(event_id)] & ~SAMEx_MASK(event_id));
    }

    return SAM_ERROR_NONE;
}

enum sam_error_t sam_set_event_response(const struct sam_dev_t *dev,
                                        enum sam_event_id_t event_id,
                                        enum sam_response_t response)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t old_reg_val;
    uint32_t new_reg_val;
    uint32_t rrl_val;
    uint32_t event_enabled;

    if ((event_id > SAM_EVENT_ID_MAX) || (response > SAM_RESPONSE_ACTION_MAX)) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    old_reg_val = regs->samrrls[SAMRRLS_IDX(event_id)];

    event_enabled = (response != SAM_RESPONSE_NONE) ? 1UL : 0UL;
    rrl_val = (event_enabled << 3UL) | log2((uint32_t)response);

    new_reg_val = (old_reg_val & ~SAMRRLS_MASK(event_id)) |
                  ((rrl_val << SAMRRLS_OFF(event_id)) & SAMRRLS_MASK(event_id));

    write_icv_reg(regs, &regs->samrrls[SAMRRLS_IDX(event_id)], new_reg_val);

    return SAM_ERROR_NONE;
}

void sam_set_watchdog_counter_initial_value(const struct sam_dev_t *dev,
                                            uint32_t count_value,
                                            enum sam_response_t responses)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    uint32_t wdciv_val = (count_value & SAMWDCIV_INIT_VALUE_WDT_MASK) |
                         ((((uint32_t)responses >> 2UL) & 0x3FUL) << 26UL);

    write_icv_reg(regs, &regs->samwdciv, wdciv_val);
}

enum sam_error_t sam_register_event_handler(struct sam_dev_t *dev,
                                            enum sam_event_id_t event_id,
                                            sam_event_handler_t event_handler)
{
    if (event_id > SAM_EVENT_ID_MAX) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    dev->event_handlers[event_id] = event_handler;

    return SAM_ERROR_NONE;
}

bool sam_is_event_pending(const struct sam_dev_t *dev,
                          enum sam_event_id_t event_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    if (event_id > SAM_EVENT_ID_MAX) {
        return false;
    }

    return (regs->sames[SAMEx_IDX(event_id)] & SAMEx_MASK(event_id)) != 0;
}

enum sam_error_t sam_clear_event(const struct sam_dev_t *dev,
                                 enum sam_event_id_t event_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    if (event_id > SAM_EVENT_ID_MAX) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    regs->samecl[SAMEx_IDX(event_id)] |= SAMEx_MASK(event_id);

    return SAM_ERROR_NONE;
}

void sam_clear_all_events(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);

    for (uint32_t idx = 0; idx < ARRAY_SIZE(regs->samecl); idx++) {
        regs->samecl[idx] = 0xFFFFFFFF;
    }
}

enum sam_error_t sam_handle_event(const struct sam_dev_t *dev,
                                  enum sam_event_id_t event_id)
{
    if (event_id > SAM_EVENT_ID_MAX) {
        return SAM_ERROR_INVALID_ARGUMENT;
    }

    if (sam_is_event_pending(dev, event_id)) {
        if (dev->event_handlers[event_id] != NULL) {
            dev->event_handlers[event_id](event_id);
        }

        return sam_clear_event(dev, event_id);
    }

    return SAM_ERROR_NONE;
}

void sam_handle_all_events(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t reg_idx;
    uint32_t event_id;
    uint32_t mask;
    uint32_t sames_val;
    uint32_t samecl_val;

    /* Iterate over each bit position in each of the SAMES registers to check if
     * the corresponding event ID is pending.
     */
    for (reg_idx = 0; reg_idx < ARRAY_SIZE(regs->sames); reg_idx++) {
        sames_val = regs->sames[reg_idx];
        samecl_val = 0;

        /* Check each bit position until all pending event have been handled
         * (when the clear value equals the status value). In most cases there
         * will only be one pending event.
         */
        for (event_id = reg_idx << 5UL, mask = 1;
             event_id <= SAM_EVENT_ID_MAX && samecl_val != sames_val;
             event_id++, mask <<= 1) {
            if (sames_val & mask) {
                if (dev->event_handlers[event_id] != NULL) {
                    dev->event_handlers[event_id](event_id);
                }
                samecl_val |= mask;
            }
        }

        if (samecl_val != 0) {
            regs->samecl[reg_idx] = samecl_val;
        }
    }
}

uint32_t sam_get_vm_partial_write_offset(const struct sam_dev_t *dev,
                                          uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t offset = regs->vmpwca[vm_id];

    regs->vmpwca[vm_id] = 0;

    return offset;
}

uint32_t sam_get_vm_single_corrected_err_offset(const struct sam_dev_t *dev,
                                                 uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t offset = regs->vmsceeca[vm_id];

    regs->vmsceeca[vm_id] = 0;

    return offset;
}

uint32_t sam_get_vm_double_uncorrected_err_offset(const struct sam_dev_t *dev,
                                                   uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t offset = regs->vmdueeca[vm_id];

    regs->vmdueeca[vm_id] = 0;

    return offset;
}

uint32_t sam_get_tram_single_corrected_err_offset(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t offset = regs->tramsceeca;

    regs->tramsceeca = 0;

    return offset;
}

uint32_t sam_get_tram_double_uncorrected_err_offset(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t offset = regs->tramdueeca;

    regs->tramdueeca = 0;

    return offset;
}
