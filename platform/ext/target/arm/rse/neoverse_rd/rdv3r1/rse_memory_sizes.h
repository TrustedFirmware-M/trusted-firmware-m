/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

#define VM0_SIZE           0x80000 /* 512 KiB */
#define VM1_SIZE           0x80000 /* 512 KiB */

#define BOOT_FLASH_SIZE    0x800000 /* 8MB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE       0x0

/* The total size of the OTP for the RSE */
#define OTP_TOTAL_SIZE     0x4000 /* 16 KiB */
/*
 * How much OTP is reserved for the portion of the DMA Initial Command Sequence
 * which is located in OTP. This is loaded by directly by the DMA hardware, so
 * this must match the size configured into the ROM part of the ICS.
 */
#define OTP_DMA_ICS_SIZE   0x400 /* 1 KiB*/

/* How much space in OTP can be used for the manufacturing data */
#define OTP_MANUFACTURING_DATA_MAX_SIZE 0x1000

/* How much space in OTP can be used for the SAM configuration */
#define OTP_SAM_CONFIGURATION_SIZE 0x60

/* How much space in ROM is used for the DMA Initial Command Sequence */
#define ROM_DMA_ICS_SIZE   0x1000 /* 4 KiB */

#endif /* __RSE_MEMORY_SIZES_H__ */
