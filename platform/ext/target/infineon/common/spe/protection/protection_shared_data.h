/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_SHARED_DATA_H
#define PROTECTION_SHARED_DATA_H

#include <stdint.h>

/* SPM is initializing, scheduler is not started yet */
#define IFX_SPM_STATE_INITIALIZING      0x3498A78Bu
/* SPM is initialized, scheduler is started */
#define IFX_SPM_STATE_RUNNING           0xA78B3498u

/**
 * \brief Shared state between SPM and partitions.
 *
 * Partitions can access this value in read-only mode, while SPM have write access.
 *
 * It's used by SE IPC Service to select a proper communication method.
 *
 * Valid values are:
 *   - \ref IFX_SPM_STATE_INITIALIZING - allows SPM to use SE RT Services Utils.
 *          Must be used during static initialization phase only.
 *   - \ref IFX_SPM_STATE_RUNNING - SE IPC interface is used by SE IPC Service only.
 */
extern uint32_t ifx_spm_state;

#define IFX_IS_SPM_INITILIZING()        (ifx_spm_state == IFX_SPM_STATE_INITIALIZING)
#define IFX_IS_SPM_RUNNING()            (ifx_spm_state == IFX_SPM_STATE_RUNNING)

#endif /* PROTECTION_SHARED_DATA_H */
