/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_INTERRUPT_HANDLER_H__
#define __SFCP_INTERRUPT_HANDLER_H__

#include "sfcp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Handle an interrupt raised by an SFCP link.
 *
 * Retrieves the outstanding message for the provided `link_id`, performs
 * any required legacy conversion, forwarding, decryption handshakes, and
 * dispatches the packet to the registered handler or emits a protocol
 * error response when needed.
 *
 * \param link_id Identifier of the SFCP transport link that raised the interrupt.
 *
 * \return `SFCP_ERROR_SUCCESS` on success or a specific `enum sfcp_error_t`
 *         value describing the failure.
 */
enum sfcp_error_t sfcp_interrupt_handler(sfcp_link_id_t link_id);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_INTERRUPT_HANDLER_H__ */
