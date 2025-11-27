/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_BOOT_SHARED_DATA_H
#define IFX_BOOT_SHARED_DATA_H

#ifdef BOOT_DATA_AVAILABLE
/**
 * \brief If boot shared data is not present, this function clears boot shared
 *        data area and adds boot shared data header to it. If boot shared data
 *        is present - this function does nothing. This allows TF-M to boot if
 *        bootloader does not create boot shared data.
 */
void ifx_mock_boot_shared_data_if_not_present(void);
#endif /* BOOT_DATA_AVAILABLE */

#endif /* IFX_BOOT_SHARED_DATA_H */
