/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_SPRT_H__
#define __TFM_SPRT_H__

/**
 * \brief Return the length of a given string, up to a maximum of maxlen bytes.
 *        Redefine strnlen() missing from libc/string.h in some toolchains
 *        (e.g. ArmClang)
 *
 * \param[in]  s           Points to the string to be examined.
 * \param[in]  maxlen      The maximum number of characters to examine.
 */
size_t strnlen(const char *s, size_t maxlen);

#endif /* __TFM_SPRT_H__ */
