/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_PSA_QUEUE_H__
#define __SFCP_PSA_QUEUE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t queue_enqueue(void *entry);

int32_t queue_dequeue(void **entry);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_PSA_QUEUE_H__ */
