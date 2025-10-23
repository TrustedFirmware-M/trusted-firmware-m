/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __BL1_2_IMAGE_BINDING_H__
#define __BL1_2_IMAGE_BINDING_H__

#include <stddef.h>
#include <stdint.h>

#include "image_layout_bl1_2.h"
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BL2_BINDING_MAC_LABEL "BL2_BINDING_MAC_KEY_V1"

/**
 * @brief Determines whether a binding tag is present in the specified image.
 *
 * @param image Pointer to the BL2 image.
 *
 * @return FIH_SUCCESS on success (if binding tag is found), non-zero on error
 */
FIH_RET_TYPE(int) is_binding_tag_present(const struct bl1_2_image_t *image);

/**
 * @brief Computes a cryptographic tag for the BL2 image.
 *
 * This function generates a 16-byte authentication tag for the provided BL2 image.
 * The tag is computed using the image data, its size, and a security counter value
 * The resulting tag is stored back to the image header.
 *
 * @param[in]  image              Pointer to the BL2 image.
 * @param[in]  image_id           Identifier for the BL2 image.
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
FIH_RET_TYPE(int) bl1_2_do_image_binding(struct bl1_2_image_t *image,
                                         uint32_t image_id);

/**
 * @brief Verifies the stored tag during subsequent boots.
 *
 * This function checks the integrity and validity of a previously stored tag
 * to ensure secure boot processes.
 *
 * @param[in]  image            Pointer to the BL2 image.
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
FIH_RET_TYPE(int) bl1_2_validate_image_binding(const struct bl1_2_image_t *image);

#ifdef __cplusplus
}
#endif

#endif /* __BL1_2_IMAGE_BINDING_H__ */
