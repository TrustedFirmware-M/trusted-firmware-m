/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_UTIL_H
#define BL1_UTIL_H

#include <stddef.h>

#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief                  Compares the given regions of memory for equality.
 *
 * \param[in]  ptr1        Pointer to the first memory region.
 * \param[in]  ptr2        Pointer to the second memory region.
 * \param[in]  size        Size of the two memory regions.
 *
 * \note                   This function is hardened against fault injection.
 *
 * \note                   This function only checks equality, and does not
 *                         return any information about the elements which
 *                         differ, so is semantically different to memcmp.
 *
 * \retval FIH_SUCCESS     The two given memory regions are identical.
 * \retval FIH_FAILURE     The two given memory regions are not identical, or a
 *                         failure has occurred and they cannot be compared.
 */
fih_ret bl_fih_memeql(const void *ptr1, const void *ptr2, size_t num);

#ifdef __cplusplus
}
#endif

#endif /* BL1_UTIL_H */
