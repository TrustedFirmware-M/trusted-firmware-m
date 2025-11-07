/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_STRING_H__
#define __TFM_STRING_H__

/**
 * \file Declare strnlen() as it's missing from the string.h include of
 *       some toolchains (e.g. ArmClang)
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Return the length of a given string \p s, up to a maximum of \p maxlen
 *        characters.
 *
 * \param[in]  s           Points to the string to be examined.
 * \param[in]  maxlen      The maximum number of characters to examine.
 */
size_t strnlen(const char *s, size_t maxlen);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_STRING_H__ */
