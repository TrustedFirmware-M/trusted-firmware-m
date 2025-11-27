/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file ifx_se_tfm_utils.h
 *
 * \brief This file is a wrapper for ifx-se-rt-services-utils library for TF-M.
 *        It adds additional stuff needed to use this library from within secure
 *        partitions.
 */

#ifndef IFX_SE_TFM_UTILS_H
#define IFX_SE_TFM_UTILS_H


#include <stddef.h>

#include "ifx_se_psacrypto.h"

/**
 * \brief Use this macro as context parameter to ifx_se_* functions.
 *
 * Example:
 * \code
 *      ifx_se_generate_random(output, output_size, IFX_SE_TFM_SYSCALL_CONTEXT);
 * \endcode
 */
#define IFX_SE_TFM_SYSCALL_CONTEXT          NULL


#endif /* IFX_SE_TFM_UTILS_H */
