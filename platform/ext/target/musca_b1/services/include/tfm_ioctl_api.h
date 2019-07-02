/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_IOCTL_API__
#define __TFM_IOCTL_API__

#include <limits.h>
#include <stdbool.h>
#include "tfm_api.h"
#include "tfm_platform_api.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_platform_ioctl_reqest_types_t {
    TFM_PLATFORM_IOCTL_PIN_SERVICE,
};

/*!
 * \enum tfm_pin_service_type_t
 *
 * \brief Pin service types
 */
enum tfm_pin_service_type_t {
    TFM_PIN_SERVICE_TYPE_SET_ALTFUNC     = 0,   /*!< Set alternate function type */
    TFM_PIN_SERVICE_TYPE_SET_DEFAULT_IN,        /*!< Set default in function type */
    TFM_PIN_SERVICE_TYPE_SET_PIN_MODE,          /*!< Set pin mode function type */
    TFM_PIN_SERVICE_TYPE_MAX = INT_MAX          /*!< Max to force enum max size */
};

/*!
 * \struct tfm_pin_service_args_t
 *
 * \brief Argument list for each platform pin service
 */
struct tfm_pin_service_args_t {
    enum tfm_pin_service_type_t type;
    union {
        struct set_altfunc { /*!< TFM_PIN_SERVICE_TYPE_SET_ALTFUNC */
            uint32_t alt_func;
            uint64_t pin_mask;
        } set_altfunc;
        struct set_default_in { /*!< TFM_PIN_SERVICE_TYPE_SET_DEFAULT_IN */
            uint32_t alt_func;
            uint32_t pin_value;
            bool default_in_value;
        } set_default_in;
        struct set_pin_mode { /*!< TFM_PIN_SERVICE_TYPE_SET_PIN_MODE */
            uint64_t pin_mask;
            uint32_t pin_mode;
        } set_pin_mode;
    } u;
};

/*!
 * \brief Sets pin alternate function for the given pins
 *
 * \param[in]  alt_func     Alternate function to set (allowed values vary
 *                          based on the platform)
 * \param[in]  pin_mask     Pin mask of the selected pins
 * \param[out] result       Return error value
 *
 * \return Returns values as specified by the \ref tfm_platform_err_t
 */
enum tfm_platform_err_t
tfm_platform_set_pin_alt_func(uint32_t alt_func, uint64_t pin_mask,
                              uint32_t *result);

/*!
 * \brief Sets default in value to use when the alternate function is not
 *        selected for the pin
 *
 * \param[in]  alt_func          Alternate function to use (allowed values vary
 *                               based on the platform)
 * \param[in]  pin_value         Pin value to use
 * \param[in]  default_in_value  Default in value to set
 * \param[out] result            Return error value
 *
 * \return Returns values as specified by the \ref tfm_platform_err_t
 */
enum tfm_platform_err_t
tfm_platform_set_pin_default_in(uint32_t alt_func, uint32_t pin_value,
                                bool default_in_value, uint32_t *result);

/*!
 * \brief Sets pin mode for the selected pins
 *
 * \param[in]  pin_mask     Pin mask of the selected pins
 * \param[in]  pin_mode     Pin mode to set for the selected pins
 * \param[out] result       Return error value
 *
 * \return Returns values as specified by the \ref tfm_platform_err_t
 */
enum tfm_platform_err_t
tfm_platform_set_pin_mode(uint64_t pin_mask, uint32_t pin_mode,
                          uint32_t *result);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_IOCTL_API__ */
