/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_2_IMAGE_H
#define BL1_2_IMAGE_H

#include <stddef.h>
#include <stdint.h>
#include "cmsis_compiler.h"
#include "mbedtls/lms.h"
#include "fih.h"
#include "image_layout_bl1_2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BL1_2_HEADER_SIZE (offsetof(struct bl1_2_image_t, protected_values.encrypted_data.data))

/**
 *
 * @param image_id
 * @return uint32_t
 */
uint32_t bl1_image_get_flash_offset(uint32_t image_id);

/**
 * @brief
 *
 * @param image_id
 * @param out
 * @return fih_int
 */
fih_ret bl1_image_copy_to_sram(uint32_t image_id, uint8_t *out);

/**
 * @brief BL1_2 selects the active BL2 image
 *
 * @note This function must call FIH_PANIC if no active image is available.
 *       It must NOT return an invalid image index.
 *
 * @return The active image index in fih_init type
 */
fih_int bl1_2_select_image(void);

/**
 * @brief BL1_2 rolls back to the previous BL2 image
 *
 * @note This function must call FIH_PANIC if it failed to roll back images.
 *       It must NOT return an invalid image index.
 *
 * @return The image index in fih_init type
 */
fih_int bl1_2_rollback_image(void);

#ifdef __cplusplus
}
#endif

#endif /* BL1_2_IMAGE_H */
