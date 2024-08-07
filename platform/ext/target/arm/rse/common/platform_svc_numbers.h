/*
 * Copyright (c) 2022-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PLAT_SVC_HANDLER_H__
#define __PLAT_SVC_HANDLER_H__

#include "svc_num.h"

/* Use the SVC number constructors to ensure the validness */
#define TFM_SVC_PLATFORM_DMA350_CONFIG          TFM_SVC_NUM_PLATFORM_THREAD(0)
#define TFM_SVC_PLATFORM_SDS_STRUCT_ADD         TFM_SVC_NUM_PLATFORM_THREAD(1)
#define TFM_SVC_PLATFORM_GET_MAILBOX_LOCALITY   TFM_SVC_NUM_PLATFORM_THREAD(2)

#endif /* __PLAT_SVC_HANDLER_H__ */
