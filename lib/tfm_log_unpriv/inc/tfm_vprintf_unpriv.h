/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_VPRINTF_UNPRIV_H__
#define __TFM_VPRINTF_UNPRIV_H__

#include <stdarg.h>

int tfm_vprintf_unpriv(const char *fmt, va_list args);

#endif /* __TFM_VPRINTF_UNPRIV_H__ */
