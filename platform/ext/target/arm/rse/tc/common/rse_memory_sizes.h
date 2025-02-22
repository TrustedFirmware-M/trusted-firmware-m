/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

#ifdef RSE_XIP
#define VM0_SIZE                         0x00010000 /* 64 KiB */
#define VM1_SIZE                         0x00010000 /* 64 KiB */
#else
#define VM0_SIZE                         0x00080000 /* 512 KiB */
#define VM1_SIZE                         0x00080000 /* 512 KiB */
#endif /* RSE_XIP */

#define OTP_DMA_ICS_SIZE   0x400 /* 1 KiB*/

#define ROM_DMA_ICS_SIZE   0x1000 /* 4 KiB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE (0x5000)

#endif /* __RSE_MEMORY_SIZES_H__ */
