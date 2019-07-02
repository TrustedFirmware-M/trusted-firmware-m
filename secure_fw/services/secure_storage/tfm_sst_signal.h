/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SST_SIGNAL_H__
#define __TFM_SST_SIGNAL_H__

/*
 * FixMe: hardcode it now, will add support to autogenerate these signal
 * definitons later.
 */
/*
 * Each Secure Partition has up to 32 different signals. A signal is represented
 * as a single-bit value within a 32-bit integer.
 * The following signals are reserved in all Secure Partitions:
 *  - 0x00000001U
 *  - 0x00000002U
 *  - 0x00000004U
 *  - 0x00000008U
 * The remaining 28 general signals can be associated with other inputs to the
 * Secure Partition.
 */
#define TFM_SST_SET_SIG         (1 << (0 + 4))
#define TFM_SST_GET_SIG         (1 << (1 + 4))
#define TFM_SST_GET_INFO_SIG    (1 << (2 + 4))
#define TFM_SST_REMOVE_SIG      (1 << (3 + 4))
#define TFM_SST_GET_SUPPORT_SIG (1 << (4 + 4))

#endif /* __TFM_SST_SIGNAL_H__ */
