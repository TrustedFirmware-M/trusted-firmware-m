/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file rse_memory_sizes.h
 * \brief This file contains the sizes of main memories, boot flash and OTP.
 */

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

#define VM0_SIZE           0x80000 /* 512 KiB */
#define VM1_SIZE           0x80000 /* 512 KiB */

#define BOOT_FLASH_SIZE    0x4000000 /* 64MB */
#define AP_BOOT_FLASH_SIZE 0x4000000 /* 64MB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE (0x5000)

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

/* RSE flash layout */
/*
 * ┌─────────────────────┬──────────────────────┬──────────────────────────┐
 * │    Signed Images    │  Protected Storage   │ Internal Trusted Storage │
 * │     (48MB)          │       (64KB)         │           (1MB)          │
 * └─────────────────────┴──────────────────────┴──────────────────────────┘
 */
/* This part is for signed images. 48MB */
#define RSE_FLASH_IMG_SIZE          0x3000000UL
/* This part is for Protected Storage. 64KB */
#define RSE_FLASH_PS_SIZE           0x10000UL
/* This part is for Internal Trusted Storage. 1MB */
#define RSE_FLASH_ITS_SIZE          0x100000UL

#endif /* __RSE_MEMORY_SIZES_H__ */
