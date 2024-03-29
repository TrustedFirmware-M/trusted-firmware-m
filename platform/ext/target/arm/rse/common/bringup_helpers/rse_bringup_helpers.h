/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_BRINGUP_HELPERS_H__
#define __RSE_BRINGUP_HELPERS_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief                        Check the status of various platform-specific
 *                               GPIO pins, and if the pins are high then run
 *                               an unauthenticated image from either SRAM, QSPI
 *                               or one received via an RSE-to-RSE link.
 *                               Intended to be used in early board bringup.
 *
 * \note                         This function must not be called if the LCM is
 *                               in PCI TP mode.
 */
void rse_run_bringup_helpers_if_requested(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_BRINGUP_HELPERS_H__ */
