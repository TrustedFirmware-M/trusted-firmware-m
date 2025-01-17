/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "config_impl.h"
#include "security_defs.h"
#include "tfm_arch.h"
#include "tfm_psa_call_pack.h"

#include "psa/client.h"
#include "psa/service.h"
#include "psa_api_veneers_common.h"

/*
 * This is the veneers of FF-M Client APIs, except for Armv8.0-m.
 * The interfaces are written in C unlike Armv8.0-m because reentrant detection
 * is done by the architecture.
 *
 * As NS Agent is also a Secure Partition, it can call the client APIs directly.
 *
 */

__tz_c_veneer
uint32_t tfm_psa_framework_version_veneer(void)
{
    uint32_t ret;

#if TFM_TZ_REENTRANCY_CHECK == 1
    tfm_psa_test_reentrancy_flag();
#endif

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
#endif
    ret = psa_framework_version();
#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(0);
#endif
    return ret;
}

__tz_c_veneer
uint32_t tfm_psa_version_veneer(uint32_t sid)
{
    uint32_t ret;

#if TFM_TZ_REENTRANCY_CHECK == 1
    tfm_psa_test_reentrancy_flag();
#endif

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
#endif
    ret = psa_version(sid);
#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(0);
#endif
    return ret;
}

__tz_c_veneer
psa_status_t tfm_psa_call_veneer(psa_handle_t handle,
                                 uint32_t ctrl_param,
                                 const psa_invec *in_vec,
                                 psa_outvec *out_vec)
{
    psa_status_t ret;

#if TFM_TZ_REENTRANCY_CHECK == 1
    tfm_psa_test_reentrancy_flag();
#endif

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
#endif
    ret = tfm_psa_call_pack(handle,
                            PARAM_SET_NS_VEC(ctrl_param),
                            in_vec, out_vec);
#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(0);
#endif
    return ret;
}

/* Following veneers are only needed by connection-based services */
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
__tz_c_veneer
psa_handle_t tfm_psa_connect_veneer(uint32_t sid, uint32_t version)
{
    psa_handle_t ret;

#if TFM_TZ_REENTRANCY_CHECK == 1
    tfm_psa_test_reentrancy_flag();
#endif

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
#endif
    ret = psa_connect(sid, version);
#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(0);
#endif
    return ret;
}

__tz_c_veneer
void tfm_psa_close_veneer(psa_handle_t handle)
{

#if TFM_TZ_REENTRANCY_CHECK == 1
    tfm_psa_test_reentrancy_flag();
#endif

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
#endif
    psa_close(handle);
#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
    __set_BASEPRI(0);
#endif
}
#else /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */
__tz_c_veneer
psa_handle_t tfm_psa_connect_veneer(uint32_t sid, uint32_t version)
{
    (void)sid;
    (void)version;

    return PSA_ERROR_NOT_SUPPORTED;
}

__tz_c_veneer
void tfm_psa_close_veneer(psa_handle_t handle)
{
    (void)handle;

    return;
}
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */
