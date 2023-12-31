/*
 * Copyright (c) 2018-2022, Arm Limited. All rights reserved.
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_NSPM_H__
#define __TFM_NSPM_H__

#include <stdint.h>

#define TFM_NS_CLIENT_INVALID_ID            ((int32_t)0)

#ifdef CONFIG_TFM_USE_TRUSTZONE

#endif /* CONFIG_TFM_USE_TRUSTZONE */

/**
 * \brief initialise the NS context database
 */
void tfm_nspm_ctx_init(void);

/**
 * \brief Get the client ID of the current NS client
 *
 * \return The client id of the current NS client. 0 (invalid client id) is
 *         returned in case of error.
 */
int32_t tfm_nspm_get_current_client_id(void);

#endif /* __TFM_NSPM_H__ */
