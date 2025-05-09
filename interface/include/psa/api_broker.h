/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __PSA_API_BROKER_H__
#define __PSA_API_BROKER_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "client.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(TFM_HYBRID_PLATFORM_API_BROKER)

enum tfm_hybrid_plat_api_broker_pe_exec_t {
    TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE = 0,
    TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE = 1,
    TFM_HYBRID_PLATFORM_API_BROKER_TYPE_COUNT,

    _TFM_HYBRID_PLATFORM_API_BROKER_TYPE_MAX = UINT8_MAX,
};

/**
 * \brief Set the running Processing Element execution target
 *
 * \return Returns 0 when successful, -1 otherwise
 */
int32_t tfm_hybrid_plat_api_broker_set_exec_target(
    enum tfm_hybrid_plat_api_broker_pe_exec_t exec_target);
#endif /* TFM_HYBRID_PLATFORM_API_BROKER */


/*
 **** API functions for Multi Core and TrusZone Interfaces ***
 *
 * This client API is renamed to either:
 * - appending 'multicore/tz' when the API broker is chosen, to allow redirection
 * or
 * - standard name when no API broker is required
 *
 * The client always calls the APIs with the standard names.
 */

#if defined(TFM_HYBRID_PLATFORM_API_BROKER)
#define PSA_CLOSE_TZ                        psa_close_tz
#define PSA_CONNECT_TZ                      psa_connect_tz
#define PSA_CALL_TZ                         psa_call_tz
#define PSA_FRAMEWORK_VERSION_TZ            psa_framework_version_tz
#define PSA_VERSION_TZ                      psa_version_tz

#define PSA_CLOSE_MULTICORE                 psa_close_multicore
#define PSA_CONNECT_MULTICORE               psa_connect_multicore
#define PSA_CALL_MULTICORE                  psa_call_multicore
#define PSA_FRAMEWORK_VERSION_MULTICORE     psa_framework_version_multicore
#define PSA_VERSION_MULTICORE               psa_version_multicore

#else
#define PSA_CLOSE_TZ                        psa_close
#define PSA_CONNECT_TZ                      psa_connect
#define PSA_CALL_TZ                         psa_call
#define PSA_FRAMEWORK_VERSION_TZ            psa_framework_version
#define PSA_VERSION_TZ                      psa_version

#define PSA_CLOSE_MULTICORE                 psa_close
#define PSA_CONNECT_MULTICORE               psa_connect
#define PSA_CALL_MULTICORE                  psa_call
#define PSA_FRAMEWORK_VERSION_MULTICORE     psa_framework_version
#define PSA_VERSION_MULTICORE               psa_version
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PSA_API_BROKER_H__ */
