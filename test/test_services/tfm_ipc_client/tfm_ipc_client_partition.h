/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_IPC_CLIENT_PARTITION_H__
#define __TFM_IPC_CLIENT_PARTITION_H__

/* FixMe: hardcode it for the tool cannot support now */
#ifdef TFM_PSA_API
#define IPC_CLIENT_TEST_BASIC_SIGNAL                          (1 << (0 + 4))
#define IPC_CLIENT_TEST_PSA_ACCESS_APP_MEM_SIGNAL             (1 << (1 + 4))
#define IPC_CLIENT_TEST_PSA_ACCESS_APP_READ_ONLY_MEM_SIGNAL   (1 << (2 + 4))
#define IPC_CLIENT_TEST_APP_ACCESS_PSA_MEM_SIGNAL             (1 << (3 + 4))
#define IPC_CLIENT_TEST_MEM_CHECK_SIGNAL                      (1 << (4 + 4))
#endif /* TFM_PSA_API */

#endif /* __TFM_IPC_CLIENT_PARTITION_H__ */
