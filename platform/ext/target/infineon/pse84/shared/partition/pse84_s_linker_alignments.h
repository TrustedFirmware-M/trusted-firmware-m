/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PSE84_S_LINKER_ALIGNMENTS
#define PSE84_S_LINKER_ALIGNMENTS

/* For PSE84 MPC is used for protections, thus areas must be aligned to MPC
 * blocks sizes */
#define IFX_LINKER_RRAM_ALIGNMENT       0x1000  /* RRAM has 4 KBs MPC blocks */
#define IFX_LINKER_SMIF_ALIGNMENT       0x20000 /* SMIF has 128 KBs MPC blocks */
#define IFX_LINKER_SRAM_ALIGNMENT       0x1000  /* SRAM has 4 KBs MPC blocks */
#define IFX_LINKER_SOCMEM_ALIGNMENT     0x2000  /* SOCMEM has 8 KBs MPC blocks */

/************************************ Code ************************************/

#if IFX_TFM_IMAGE_EXECUTE_LOCATION == IFX_MEMORY_TYPE_SRAM
#define IFX_LINKER_CODE_ALIGNMENT                   IFX_LINKER_SRAM_ALIGNMENT
#elif IFX_TFM_IMAGE_EXECUTE_LOCATION == IFX_MEMORY_TYPE_SOCMEM_RAM
#define IFX_LINKER_CODE_ALIGNMENT                   IFX_LINKER_SOCMEM_ALIGNMENT
#elif IS_SMIF_MEMORY(IFX_TFM_IMAGE_EXECUTE_LOCATION)
#define IFX_LINKER_CODE_ALIGNMENT                   IFX_LINKER_SMIF_ALIGNMENT
#elif IFX_TFM_IMAGE_EXECUTE_LOCATION == IFX_MEMORY_TYPE_RRAM
#define IFX_LINKER_CODE_ALIGNMENT                   IFX_LINKER_RRAM_ALIGNMENT
#else /* IFX_TFM_IMAGE_EXECUTE_LOCATION == IFX_MEMORY_TYPE_SRAM */
#error Unsupported IFX_TFM_IMAGE_EXECUTE_LOCATION
#endif

#define TFM_LINKER_VENEERS_ALIGNMENT                IFX_LINKER_CODE_ALIGNMENT

#define TFM_LINKER_UNPRIV_CODE_ALIGNMENT            IFX_LINKER_CODE_ALIGNMENT

#define TFM_LINKER_NS_AGENT_TZ_CODE_ALIGNMENT       IFX_LINKER_CODE_ALIGNMENT

/************************************ Data ************************************/

#if IFX_TFM_DATA_LOCATION == IFX_MEMORY_TYPE_SRAM
#define IFX_LINKER_DATA_ALIGNMENT                   IFX_LINKER_SRAM_ALIGNMENT
#elif IFX_TFM_DATA_LOCATION == IFX_MEMORY_TYPE_SOCMEM_RAM
#define IFX_LINKER_DATA_ALIGNMENT                   IFX_LINKER_SOCMEM_ALIGNMENT
#else /* IFX_TFM_DATA_LOCATION == IFX_MEMORY_TYPE_SRAM */
#error Unsupported IFX_TFM_DATA_LOCATION
#endif

#define TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT    IFX_LINKER_DATA_ALIGNMENT

#define TFM_LINKER_PSA_ROT_LINKER_DATA_ALIGNMENT    IFX_LINKER_DATA_ALIGNMENT

#define TFM_LINKER_SP_META_PTR_ALIGNMENT            IFX_LINKER_DATA_ALIGNMENT

#ifndef TFM_LINKER_IFX_CODE_COVERAGE_ALIGNMENT
#define TFM_LINKER_IFX_CODE_COVERAGE_ALIGNMENT      IFX_LINKER_DATA_ALIGNMENT
#endif

/* In isolation level 3 partition stack is added to partition assets to be
 * protected by platform. In this case NS agent TZ and Idle partitions stacks
 * must be aligned to satisfy MPC alignment requirements. In other isolation
 * levels stack is not a partition asset and is protected as part of PSA/APP RoT
 * or SPM section thus special alignment is not needed. */
#if (TFM_ISOLATION_LEVEL == 3) || (TFM_ISOLATION_LEVEL == 2)
#define TFM_LINKER_NS_AGENT_TZ_STACK_ALIGNMENT      IFX_LINKER_DATA_ALIGNMENT

#define TFM_LINKER_IDLE_PARTITION_STACK_ALIGNMENT   IFX_LINKER_DATA_ALIGNMENT
#endif

#endif /* PSE84_S_LINKER_ALIGNMENTS */
