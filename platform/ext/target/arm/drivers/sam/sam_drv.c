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

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

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

static uint32_t count_zero_bits(uint32_t val)
{
    uint32_t res = 32;

    while (val != 0) {
        val &= val - 1;
        res--;
    }

    return res;
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
    uint32_t zero_count = 0;

    const uint32_t samnec =
        ((regs->sambc >> SAMBC_NUMBER_EVENT_COUNTERS_POS) & SAMBC_NUMBER_EVENT_COUNTERS_MASK);

    /*
     * The SAM registers are not initialised by the DMA ICS in all states
     * and therefore we need to correctly set up the value of the SAMICV
     * here. Failure to do so will result in SAM alarms for ICV failures
     * when we come to program the SAM registers
     */
    /* Calculate ZC over integrity checker protected area */
    for (volatile uint32_t *ptr = (volatile uint32_t *)&regs->samem;
         ptr < (volatile uint32_t *)&regs->samicv; ptr++) {
        /* Skip unavailable event counters */
        if ((ptr > (volatile uint32_t *)&regs->samec[samnec]) &&
            (ptr <= (volatile uint32_t *)&regs->samec[7])) {
            continue;
        }
        zero_count += count_zero_bits(*ptr);
    }

    regs->samicv = zero_count;

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
        regs->samim[SAMEx_IDX(event_id)] |= SAMEx_MASK(event_id);
        /* Update integrity check value, one lower zero count */
        regs->samicv--;
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
        regs->samim[SAMEx_IDX(event_id)] &= ~SAMEx_MASK(event_id);
        /* Update integrity check value, one higher zero count */
        regs->samicv++;
    }

    return SAM_ERROR_NONE;
}

static void update_samicv(struct sam_reg_map_t *regs, uint32_t new_reg_val, uint32_t old_reg_val)
{
    uint32_t zc_new, zc_old;

    zc_new = count_zero_bits(new_reg_val);
    zc_old = count_zero_bits(old_reg_val);

    if (zc_new > zc_old) {
        regs->samicv += zc_new - zc_old;
    } else {
        regs->samicv -= zc_old - zc_new;
    }
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

    event_enabled = (response != SAM_RESPONSE_NONE);
    rrl_val = (event_enabled << 3UL) | log2((uint32_t)response);

    new_reg_val = (old_reg_val & ~SAMRRLS_MASK(event_id)) |
                  ((rrl_val << SAMRRLS_OFF(event_id)) & SAMRRLS_MASK(event_id));

    regs->samrrls[SAMRRLS_IDX(event_id)] = new_reg_val;

    /* Update integrity check value with the difference in zero count */
    update_samicv(regs,  new_reg_val,  old_reg_val);

    return SAM_ERROR_NONE;
}

void sam_set_watchdog_counter_initial_value(const struct sam_dev_t *dev,
                                            uint32_t count_value,
                                            enum sam_response_t responses)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uint32_t old_reg_val = regs->samwdciv;

    uint32_t wdciv_val = (count_value & SAMWDCIV_INIT_VALUE_WDT_MASK) |
                         ((((uint32_t)responses >> 2UL) & 0x3FUL) << 26UL);

    regs->samwdciv = wdciv_val;

    /* Update integrity check value with the difference in zero count */
    update_samicv(regs, wdciv_val, old_reg_val);
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

    for (uint32_t idx = 0; idx < ARRAY_LEN(regs->samecl); idx++) {
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
    for (reg_idx = 0; reg_idx < ARRAY_LEN(regs->sames); reg_idx++) {
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

uintptr_t sam_get_vm_partial_write_addr(const struct sam_dev_t *dev,
                                        uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uintptr_t addr = regs->vmpwca[vm_id];

    regs->vmpwca[vm_id] = 0;

    return addr;
}

uintptr_t sam_get_vm_single_corrected_err_addr(const struct sam_dev_t *dev,
                                               uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uintptr_t addr = regs->vmsceeca[vm_id];

    regs->vmsceeca[vm_id] = 0;

    return addr;
}

uintptr_t sam_get_vm_double_uncorrected_err_addr(const struct sam_dev_t *dev,
                                                 uint32_t vm_id)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uintptr_t addr = regs->vmdueeca[vm_id];

    regs->vmdueeca[vm_id] = 0;

    return addr;
}

uintptr_t sam_get_tram_single_corrected_err_addr(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uintptr_t addr = regs->tramsceeca;

    regs->tramsceeca = 0;

    return addr;
}

uintptr_t sam_get_tram_double_uncorrected_err_addr(const struct sam_dev_t *dev)
{
    struct sam_reg_map_t *regs = get_sam_dev_base(dev);
    uintptr_t addr = regs->tramdueeca;

    regs->tramdueeca = 0;

    return addr;
}
