/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _TFM_UTILS_H_
#define _TFM_UTILS_H_

#include "stdint.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#endif /* ARRAY_SIZE */

#ifndef IOVEC_LEN
#define IOVEC_LEN(x) ((uint32_t)ARRAY_SIZE(x))
#endif /* IOVEC_LEN */

#ifndef ALIGN_UP
#define ALIGN_UP(num, align)    ((num) + ((align) - ((num) % (align))) % (align))
#endif /* ALIGN_UP */

#ifndef ALIGN_DOWN
#define ALIGN_DOWN(num, align)  ((num) - ((num) % (align)))
#endif /* ALIGN_DOWN */

#endif /*_TFM_UTILS_H_*/

