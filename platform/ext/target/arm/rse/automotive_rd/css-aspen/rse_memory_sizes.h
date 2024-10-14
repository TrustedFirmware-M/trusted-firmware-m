/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file rse_memory_sizes.h
 * \brief This file contains the sizes of main memories, boot flash and OTP.
 */

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

#define VM0_SIZE           0x80000 /* 512 KiB */
#define VM1_SIZE           0x80000 /* 512 KiB */

/* The uppermost RETAINED_RAM_SIZE bytes of VM1 are retained after cold reset */
#define RETAINED_RAM_SIZE  0x20000 /* 128 KiB */

#define BOOT_FLASH_SIZE    0x4000000 /* 64MB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE (0x0)

/* The total size of the OTP for the RSE */
#define OTP_TOTAL_SIZE     0x4000 /* 16 KiB */
/*
 * How much OTP is reserved for the portion of the DMA Initial Command Sequence
 * which is located in OTP. This is loaded by directly by the DMA hardware, so
 * this must match the size configured into the ROM part of the ICS.
 */
#define OTP_DMA_ICS_SIZE   0x400 /* 1 KiB*/
/* How much space in ROM is used for the DMA Initial Command Sequence */
#define ROM_DMA_ICS_SIZE   0x1000 /* 4 KiB */

/* How much space in OTP can be used for the manufacturing data */
#define OTP_MANUFACTURING_DATA_MAX_SIZE 0x1000

/* How much space in OTP can be used for the SAM configuration */
#define OTP_SAM_CONFIGURATION_SIZE 0x60

/* The maximum size for code in the provisioning bundle */
#define PROVISIONING_BUNDLE_CODE_SIZE   (0xB000)
/* The maximum size for secret values in the provisioning bundle */
#define PROVISIONING_BUNDLE_VALUES_SIZE (0x3D00)

#endif /* __RSE_MEMORY_SIZES_H__ */
