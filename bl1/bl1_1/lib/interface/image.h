/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_1_IMAGE_H
#define BL1_1_IMAGE_H

#include <stdint.h>
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

fih_ret bl1_read_bl1_2_image(uint8_t *image);

#ifdef __cplusplus
}
#endif

#endif /* BL1_1_IMAGE_H */
