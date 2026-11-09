/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * NS-side inline proxy for ROMAPI_GetVersion and ROMAPI_RunBootloader.
 * Forwards calls from the Non-Secure world to S-world via the TF-M
 * platform IOCTL channel.
 *
 * Included by fsl_romapi_tfm_ns.h when ROMAPI_PROXY_HAL_MCXL or
 * ROMAPI_PROXY_HAL_MCXA is defined.
 */

#ifndef FSL_ROMAPI_NS_PROXY_MCXL_MCXA_H__
#define FSL_ROMAPI_NS_PROXY_MCXL_MCXA_H__

#include "tfm_ioctl_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Return the ROM API version word.
 *
 * Forwards to the S-world ROM driver via TF-M platform IOCTL
 * (TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION).
 *
 * @return Raw version word from FLASH_API->version.version, or 0 on error.
 */
static inline uint32_t ROMAPI_GetVersion(void)
{
    uint32_t version = 0U;
    int32_t  result  = -1;

    (void)tfm_platform_romapi_get_version(&version, &result);

    return version;
}

/*!
 * @brief Invoke the ROM bootloader.
 *
 * Packs the user_app_boot_invoke_option_t union value into the IOCTL
 * request and forwards it to S-world via TF-M platform IOCTL
 * (TFM_PLATFORM_IOCTL_ROMAPI_RUN_BOOTLOADER).
 *
 * @param arg Pointer to a user_app_boot_invoke_option_t. The .option.U
 *            word is extracted and passed to the S-side handler.
 *            Pass NULL to use a zero option word.
 */
static inline void ROMAPI_RunBootloader(void *arg)
{
    uint32_t option = 0U;
    int32_t  result = -1;

    if (arg != NULL) {
        /* Treat arg as a pointer to a uint32_t option word, which matches
         * the layout of user_app_boot_invoke_option_t.option.U on both
         * MCXL (raw uint32_t) and MCXA (union with U member). */
        option = *(const uint32_t *)arg;
    }

    (void)tfm_platform_romapi_run_bootloader(option, &result);
}

#ifdef __cplusplus
}
#endif

#endif /* FSL_ROMAPI_NS_PROXY_MCXL_MCXA_H__ */
