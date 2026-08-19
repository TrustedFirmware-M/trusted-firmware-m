/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SVCALLS_H__
#define __TFM_SVCALLS_H__

#include <stdint.h>
#include "psa/service.h"

/**
 * \brief The C source of SVCall handlers
 *
 * \param[in] msp               MSP at SVCall entry.
 * \param[in] exc_return        EXC_RETURN value of the SVC.
 * \param[in] psp               PSP at SVCall entry.

 * \returns                     EXC_RETURN value indicates where to return.
 */
uint32_t spm_svc_handler(uint32_t *msp, uint32_t exc_return, uint32_t *psp);

/**
 * \brief Return from PSA API function executed in Thread mode.
 *        Trigger svc handler to restore thread context before entering PSA API function.
 *
 * \param[in] result            PSA API function return value.
 */
void tfm_svc_thread_mode_spm_return(psa_status_t result);

#if TFM_ISOLATION_LEVEL > 1
/**
 * \brief Returns whether the current Thread mode context executes SPM code
 *
 * \returns                     True if the current thread mode context executes SPM code.
 *                              False otherwise.
 */
bool tfm_svc_thread_mode_spm_active(void);
#endif /* TFM_ISOLATION_LEVEL > 1 */

#endif
