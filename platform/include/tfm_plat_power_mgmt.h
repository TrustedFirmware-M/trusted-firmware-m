/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PLAT_POWER_MGMT_H__
#define __TFM_PLAT_POWER_MGMT_H__
/**
 * \note The interfaces defined in this file must be implemented for each
 *       target using the optional Power Management services.
 */

#include "tfm_plat_defs.h"
#include "power_mgmt/tfm_power_mgmt_api.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_power_mgmt_power_policy_t {
    TFM_POWER_MGMT_PWR_POLICY_GRACEFUL = 0,
    TFM_POWER_MGMT_PWR_POLICY_FORCEFUL,

    TFM_POWER_MGMT_PWR_POLICY_COUNT,
    _TFM_POWER_MGMT_PWR_POLICY_INT_SIZE = INT_MAX
};

struct plat_power_mgmt_set_state_callback_settings_t {
    enum tfm_power_mgmt_power_state_t state;
    enum tfm_power_mgmt_err_t (*pre_cb)(enum tfm_power_mgmt_power_state_t state);
    enum tfm_power_mgmt_err_t (*post_cb)(enum tfm_power_mgmt_power_state_t state);
    enum tfm_power_mgmt_power_policy_t policy;
};

/**
 * \brief Get power table
 *
 * \details The table of callbacks for platforms operations.
 */
void platform_power_mgmt_get_power_table(
    const struct plat_power_mgmt_set_state_callback_settings_t **callbacks,
    size_t *callbacks_count);

/**
 * \brief Get address of memory used during retention power saving mode MEM_RET
 *
 * \details The base address and size of the memory used for retention. The
 *          platform needs to provide a memory that is at least as large as
 *          mem_size.
 */
enum tfm_power_mgmt_err_t platform_power_mgmt_get_retention_memory(
    volatile uint32_t **mem_addr,
    size_t mem_size);

/**
 * \brief Get the callback for the devices power state getter
 *
 * \details The callback for platforms operations when get_ is invoked
 */
enum tfm_power_mgmt_err_t platform_power_mgmt_get_callback(
    power_mgmt_get_callback_t *get_cb);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PLAT_POWER_MGMT_H__ */
