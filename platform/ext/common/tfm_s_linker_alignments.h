/*
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* This file defines default alignments for TFM secure linker script sections.
 * If needed, platform may define some/all of them in its' region_defs.h
 * file.*/

#ifndef __TFM_S_LINKER_ALIGNMENTS__
#define __TFM_S_LINKER_ALIGNMENTS__

/* Helper macro that can be used to round up to multiple to satisfy required
 * alignment. */
#define ROUND_UP_TO_MULTIPLE(number, multiple) \
    ((((number) + (multiple) - 1) / (multiple)) * (multiple))

#define CHECK_ALIGNMENT_4(size) ASSERT((size) % 4 == 0, #size)

/* For Cortex-M0+ VTOR: 256-byte vector table is at the offset 0x00 of the image.
 * To keep that table in one block, the image base must be a multiple of 0x100.
 * For reference: https://developer.arm.com/documentation/ddi0419/latest/
 */
#define CHECK_ALIGNMENT_256(addr) ASSERT((addr % 256) == 0, #addr)

/* Default alignment for linker file sections is set to 32 because ARM TrustZone
 * protection units (SAU and MPU) require regions to be 32 bytes aligned. */
#ifndef TFM_LINKER_DEFAULT_ALIGNMENT
#define TFM_LINKER_DEFAULT_ALIGNMENT    32
#endif

#ifndef TFM_LINKER_VENEERS_ALIGNMENT
#define TFM_LINKER_VENEERS_ALIGNMENT            TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT
#define TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_APP_ROT_LINKER_CODE_ALIGNMENT
#define TFM_LINKER_APP_ROT_LINKER_CODE_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_SHARED_SYMBOLS_ALIGNMENT
#define TFM_LINKER_SHARED_SYMBOLS_ALIGNMENT     TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_BL2_SHARED_DATA_ALIGNMENT
#define TFM_LINKER_BL2_SHARED_DATA_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_MSP_STACK_ALIGNMENT
#define TFM_LINKER_MSP_STACK_ALIGNMENT          TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_SP_META_PTR_ALIGNMENT
#define TFM_LINKER_SP_META_PTR_ALIGNMENT        TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT
#define TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PSA_ROT_LINKER_DATA_ALIGNMENT
#define TFM_LINKER_PSA_ROT_LINKER_DATA_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_UNPRIV_CODE_ALIGNMENT
#define TFM_LINKER_UNPRIV_CODE_ALIGNMENT        TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_RO_ALIGNMENT
#define TFM_LINKER_PT_RO_ALIGNMENT              TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_UNPRIV_CODE_ALIGNMENT
#define TFM_LINKER_PT_UNPRIV_CODE_ALIGNMENT     TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_APP_ROT_CODE_ALIGNMENT
#define TFM_LINKER_PT_APP_ROT_CODE_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_PSA_ROT_CODE_ALIGNMENT
#define TFM_LINKER_PT_PSA_ROT_CODE_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_RO_DATA_ALIGNMENT
#define TFM_LINKER_PT_RO_DATA_ALIGNMENT         TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_APP_ROT_DATA_ALIGNMENT
#define TFM_LINKER_PT_APP_ROT_DATA_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_AROT_PART_PRIVATE_DATA_ALIGNMENT
#define TFM_LINKER_PT_AROT_PART_PRIVATE_DATA_ALIGNMENT  TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_PSA_ROT_DATA_ALIGNMENT
#define TFM_LINKER_PT_PSA_ROT_DATA_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_PT_PROT_PART_PRIVATE_DATA_ALIGNMENT
#define TFM_LINKER_PT_PROT_PART_PRIVATE_DATA_ALIGNMENT  TFM_LINKER_DEFAULT_ALIGNMENT
#endif

#ifndef TFM_LINKER_SPM_CODE_ALIGNMENT
#define TFM_LINKER_SPM_CODE_ALIGNMENT  TFM_LINKER_DEFAULT_ALIGNMENT
#endif

/* Alignment of stack of NS agent TZ partition. This should not be needed once
 * TZ NS agent partition is reworked to use manifest files. */
#ifndef TFM_LINKER_NS_AGENT_TZ_STACK_ALIGNMENT
#define TFM_LINKER_NS_AGENT_TZ_STACK_ALIGNMENT  TFM_LINKER_DEFAULT_ALIGNMENT
#endif

/* Alignment of stack of Idle partition. This should not be needed once Idle
 * partition is reworked to use manifest files. */
#ifndef TFM_LINKER_IDLE_PARTITION_STACK_ALIGNMENT
#define TFM_LINKER_IDLE_PARTITION_STACK_ALIGNMENT   TFM_LINKER_DEFAULT_ALIGNMENT
#endif

/* Alignment of RAM vector table */
#ifndef TFM_LINKER_RAM_VECTORS_ALIGNMENT
#define TFM_LINKER_RAM_VECTORS_ALIGNMENT        256
#endif

#endif /* __TFM_S_LINKER_ALIGNMENTS__ */
