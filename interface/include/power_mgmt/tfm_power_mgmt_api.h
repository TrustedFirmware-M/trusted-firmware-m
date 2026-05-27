/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_POWER_MGMT_API_H__
#define __TFM_POWER_MGMT_API_H__

#include <limits.h>
#include <stdint.h>

#include "tfm_plat_power_mgmt_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PSA call types */
#define TFM_POWER_MGMT_SET      (1101)
#define TFM_POWER_MGMT_GET      (1102)

/* The `wait_for` type */
#define TFM_POWER_MGMT_WAIT_FOR_NONE        0 /* for custom */
#define TFM_POWER_MGMT_WAIT_FOR_EVENT       1
#define TFM_POWER_MGMT_WAIT_FOR_INTERRUPT   2

/* Platform code to optionally override this */
#ifndef TFM_POWER_MGMT_PWR_STATE_CUSTOM
#define TFM_POWER_MGMT_PWR_STATE_CUSTOM         0
#endif

/*!
 * \enum tfm_power_mgmt_err_t
 *
 * \brief Power Management service error types
 *
 */
enum tfm_power_mgmt_err_t {
    TFM_POWER_MGMT_ERR_SUCCESS = 0,
    TFM_POWER_MGMT_ERR_NOT_SUPPORTED,
    TFM_POWER_MGMT_ERR_INVALID_PARAM,
    TFM_POWER_MGMT_ERR_BUSY,
    TFM_POWER_MGMT_ERR_SYSTEM_ERROR,

    _TFM_POWER_MGMT_ERR_INT_SIZE = UINT_MAX
};

/**
 * \enum tfm_power_mgmt_power_state_t
 *
 * \brief Power Management service supported states: generic for CPU and custom
 *
 */
enum tfm_power_mgmt_power_state_t {
    /* CPU & SYSTEM STATES */
    TFM_POWER_MGMT_PWR_STATE_OFF = 0,
    TFM_POWER_MGMT_PWR_STATE_SLEEP,
    TFM_POWER_MGMT_PWR_STATE_DEEPSLEEP,
    TFM_POWER_MGMT_PWR_STATE_SUSPEND,
    TFM_POWER_MGMT_PWR_STATE_HIBERNATE,
    TFM_POWER_MGMT_PWR_STATE_CPUSYSTEM_COUNT,

    /*
     * Custom states
     * Platform implementation can add custom states in their tfm_plat_power_mgmt_defs.h
     */
    TFM_POWER_MGMT_PWR_STATE_COUNT =
        TFM_POWER_MGMT_PWR_STATE_HIBERNATE + TFM_POWER_MGMT_PWR_STATE_CUSTOM,

    TFM_POWER_MGMT_PWR_STATE_MAX = TFM_POWER_MGMT_PWR_STATE_COUNT,
    _TFM_POWER_MGMT_PWR_STATE_INT_SIZE = INT_MAX
};

/* The typedef for the get() callback platforms may need to implement or support */
typedef enum tfm_power_mgmt_err_t (*power_mgmt_get_callback_t)(uint32_t device_id, int32_t *state);

/* Internal usage of the API implementation */
struct tfm_power_mgmt_set_params {
    int32_t call_type;  /* set by the interface */
    enum tfm_power_mgmt_power_state_t pwr_state; /* the targeted power state */
    uint32_t wait_for;  /* the type of wait */
};

struct tfm_power_mgmt_get_params {
    int32_t call_type;  /* set by the interface */
    uint32_t device_id; /* the targeted device */
};

union tfm_power_mgmt_call_params {
    int32_t call_type;
    struct tfm_power_mgmt_set_params set;
    struct tfm_power_mgmt_get_params get;
};

/*!
 * \brief Performs a SET power state
 *
 * \param[in]   pwr_state   The requested power state to transition into
 * \param[in]   wait_for    The requested waiting state upon transition
 *
 * \return Returns values as specified by the \ref tfm_power_mgmt_err_t
 */
enum tfm_power_mgmt_err_t tfm_power_mgmt_set_state(
    enum tfm_power_mgmt_power_state_t pwr_state,
    uint32_t wait_for);

/*!
 * \brief   Performs a GET power state
 *
 * \note    This API is fully customized. The service only acts as proxy between
 *          the caller and the platform code that eventually returns the power
 *          state of the requested device.
 *
 * \param[in]   device_id   Custom device id
 *
 * \param[out]  state       Custom device state
 *
 * \return Returns values as specified by the \ref tfm_power_mgmt_err_t
 */
enum tfm_power_mgmt_err_t tfm_power_mgmt_get_state(
    uint32_t device_id,
    int32_t *state);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_POWER_MGMT_API_H__ */
