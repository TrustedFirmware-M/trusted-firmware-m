/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "util.h"

#include "fih.h"
#include <string.h>

#ifdef TFM_FIH_PROFILE_ON
fih_ret bl_fih_memeql(const void *ptr1, const void *ptr2, size_t num)
{
    size_t idx;

    for (idx = 0; idx < num; idx++) {
        if (((uint8_t *)ptr1)[idx] != ((uint8_t *)ptr2)[idx]) {
            FIH_RET(FIH_FAILURE);
        }

        fih_delay();

        if (((uint8_t *)ptr1)[idx] != ((uint8_t *)ptr2)[idx]) {
            FIH_RET(FIH_FAILURE);
        }
    }

    if (idx != num) {
        FIH_RET(FIH_FAILURE);
    }

    FIH_RET(FIH_SUCCESS);
}
#else
fih_ret bl_fih_memeql(const void *ptr1, const void *ptr2, size_t num)
{
    /* Only return 1 or 0 */
    FIH_RET(memcmp(ptr1, ptr2, num) != 0);
}
#endif /* TFM_FIH_PROFILE_ON */
