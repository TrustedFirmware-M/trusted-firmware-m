/*
 * Copyright (c) 2018, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#define IPC_SYNC_MAGIC 0x7DADE011

struct tfm_spm_partition_platform_data_t;

extern struct tfm_spm_partition_platform_data_t tfm_peripheral_std_uart;
extern struct tfm_spm_partition_platform_data_t tfm_peripheral_uart1;

#define TFM_PERIPHERAL_STD_UART     (&tfm_peripheral_std_uart)
#define TFM_PERIPHERAL_UART1        (&tfm_peripheral_uart1)

#endif /* __TFM_PERIPHERALS_DEF_H__ */
