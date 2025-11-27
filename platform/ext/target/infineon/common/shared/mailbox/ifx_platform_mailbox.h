/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_PLATFORM_MAILBOX_H
#define IFX_PLATFORM_MAILBOX_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if CONFIG_TFM_PSA_CALL_ADDRESS_REMAP
/**
 * \brief Check if the address is in the internal memory of the non-secure CPU.
 *
 * \param[in]   base   The base address to check.
 * \param[in]   size   The size of the memory region to check.
 *
 * \return Returns whether the address is in the NS CPU internal memory.
 */
bool ifx_is_ns_cpu_internal_memory(uintptr_t base, size_t size);

/**
 * \brief Check if the address is in the remapped internal memory of the non-secure CPU.
 *
 * \param[in]   base   The base address to check.
 * \param[in]   size   The size of the memory region to check.
 *
 * \return Returns whether the address is in the NS CPU remapped internal memory.
 */
bool ifx_is_ns_cpu_internal_memory_remapped(uintptr_t base, size_t size);
#endif /* CONFIG_TFM_PSA_CALL_ADDRESS_REMAP */

#endif /* IFX_PLATFORM_MAILBOX_H */
