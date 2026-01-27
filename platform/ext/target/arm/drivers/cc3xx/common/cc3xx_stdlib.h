/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_STDLIB_H
#define CC3XX_STDLIB_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief                        Copy a series of words in a randomised order.
 *                               Intended to be used as a DPA countermeasure
 *                               when copying key materal.
 *
 * @note                         This function may take a variable amount of
 *                               time to execute.
 *
 * @param[out] dst               Destination buffer to copy into
 * @param[in]  src               Source buffer to copy from.
 * @param[in]  word_count        The amount of words to copy.
 */
void cc3xx_dpa_hardened_word_copy(volatile uint32_t *dst,
                                  volatile const uint32_t *src, size_t word_count);
/**
 * @brief Securely erases the buffer pointed by buf by overwriting it with random values. Assumes
 *        the size of the buffer in bytes is a multiple of 4
 *
 * @param[in,out] buf        Pointer to the input buffer, must be 4 byte aligned
 * @param[in]     word_count Length in words of the input buffer
 *
 */
void cc3xx_secure_erase_buffer(uint32_t *buf, size_t word_count);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_STDLIB_H */
