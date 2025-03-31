/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_M_VPRINTF_PRIV_H__
#define __TF_M_VPRINTF_PRIV_H__

#include <stdint.h>
#include <stdarg.h>

/**
 * \typedef tfm_log_output_str
 * \brief   Function pointer type for a custom log output handler.
 *
 *          This type defines a callback function used by the logging subsystem
 *          to send output strings to a user-defined destination, such as UART
 *          or a memory buffer.
 *
 * \param[in] priv  Pointer to user-defined context or state.
 * \param[in] str   Pointer to the character buffer containing the string to output.
 * \param[in] len   Length of the string (in bytes) to output.
 */
typedef void (*tfm_log_output_str)(void *priv, const char *str, uint32_t len);

/**
  * \brief   Format a string and send it to a user-defined output handler.
  *
  *          This function is similar to vprintf(), but instead of writing to a
  *          standard output stream, it sends the formatted output to a callback
  *          function provided by the user.
  *
  *
  * \param[in] output_func  Pointer to the output function that handles the formatted string.
  * \param[in] priv         Pointer to user-defined context, passed to the output function.
  * \param[in] fmt          Format string specifying how to format the output. This is expected
  *                         to begin with a MARKER character.
  * \param[in] args         Variable argument list to match the format string.
  */
void tfm_vprintf(tfm_log_output_str output_func, void *priv, const char *fmt, va_list args);

#endif /* __TF_M_VPRINTF_PRIV_H__ */
