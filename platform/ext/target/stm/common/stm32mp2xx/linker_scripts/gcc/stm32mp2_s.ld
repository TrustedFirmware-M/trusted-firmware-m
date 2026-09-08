;/*
; * Copyright (c) 2009-2024 Arm Limited
; * Copyright (c) 2022-2023 Cypress Semiconductor Corporation (an Infineon company)
; * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
; * Copyright (C) 2026 STMicroelectronics.
; *
; * Licensed under the Apache License, Version 2.0 (the "License");
; * you may not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; *     http://www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an "AS IS" BASIS,
; * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; *
; *
; * This file is derivative of CMSIS V5.00 gcc_arm.ld
; */

/* Linker script to configure memory regions. */
/* This file will be run trough the pre-processor. */

#include "region_defs.h"

/* Include file with definitions for section alignments.
 * Note: it should be included after region_defs.h to let platform define
 * default values if needed. */
#include "tfm_s_linker_alignments.h"


#ifndef TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT
#define TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT    TFM_LINKER_DEFAULT_ALIGNMENT
#endif


MEMORY
{
  DDR      (rx)  : ORIGIN = S_CODE_START, LENGTH = S_CODE_SIZE
  RAM      (rw)  : ORIGIN = S_DATA_START, LENGTH = S_DATA_SIZE
#if defined(S_RAM_CODE_START)
  CODE_RAM (rwx) : ORIGIN = S_RAM_CODE_START, LENGTH = S_RAM_CODE_SIZE
#endif
}

REGION_ALIAS("FLASH", DDR);

#ifndef TFM_LINKER_VENEERS_START
#define TFM_LINKER_VENEERS_START ALIGN(TFM_LINKER_VENEERS_ALIGNMENT)
#endif

#ifndef TFM_LINKER_VENEERS_END
#define TFM_LINKER_VENEERS_END ALIGN(TFM_LINKER_VENEERS_ALIGNMENT)
#endif

#define VENEERS() \
/* \
 * Place the CMSE Veneers (containing the SG instruction) after the code, in \
 * a separate at least 32 bytes aligned region so that the SAU can \
 * programmed to just set this region as Non-Secure Callable. \
 */ \
.gnu.sgstubs TFM_LINKER_VENEERS_START : \
{ \
    *(.gnu.sgstubs*) \
} > FLASH \
/* GCC always places veneers at the end of .gnu.sgstubs section, so the only \
 * way to align the end of .gnu.sgstubs section is to align start of the \
 * next section */ \
.sgstubs_end : TFM_LINKER_VENEERS_END \
{ \
} > FLASH

__msp_stack_size__ = S_MSP_STACK_SIZE;

ENTRY(Reset_Handler)

SECTIONS
{
    /* Start address of the code. */
    Image$$PT_RO_START$$Base = ADDR(.TFM_VECTORS);

    /*
     * To support firmware image encryption by OP-TEE (TF-M running on a coprocessor),
     * we need to align all sections to have a modulo 16 size. This size is the atomic block size to
     * encrypt. Use TFM_LINKER_DEFAULT_ALIGNMENT that is set to 32 bytes.
     * Each section declared should respect this template:
     *
     * section_name : ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
     * {
     *     ...
     *     ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
     * }
     */

   .TFM_VECTORS : ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
    {
        __vectors_start__ = .;
        KEEP(*(.vectors))
        . = ALIGN(4);
        __vectors_end__ = .;
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH

    ASSERT(__vectors_start__ != __vectors_end__, ".vectors should not be empty")

#if defined(S_CODE_VECTOR_TABLE_SIZE)
    ASSERT(. <= ADDR(.TFM_VECTORS) + S_CODE_VECTOR_TABLE_SIZE, ".TFM_VECTORS section size overflow.")
    . = ADDR(.TFM_VECTORS) + S_CODE_VECTOR_TABLE_SIZE;
#endif

    VENEERS()

    /**** Section for holding partition RO load data */
    /*
     * Sort the partition info by priority to guarantee the initing order.
     * The first loaded partition will be inited at last in SFN model.
     */
    .TFM_SP_LOAD_LIST ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) :
    {
        KEEP(*(.part_load))
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH
    Image$$TFM_SP_LOAD_LIST$$RO$$Base = ADDR(.TFM_SP_LOAD_LIST);
    Image$$TFM_SP_LOAD_LIST$$RO$$Limit = ADDR(.TFM_SP_LOAD_LIST) + SIZEOF(.TFM_SP_LOAD_LIST);

    /**** PSA RoT RO part (CODE + RODATA) start here */
    . = ALIGN(TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT);
    Image$$TFM_PSA_CODE_START$$Base = .;

    .TFM_PSA_ROT_LINKER ALIGN(TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT) :
    {
        *tfm_psa_rot_partition*:(SORT_BY_ALIGNMENT(.text*))
        *tfm_psa_rot_partition*:(SORT_BY_ALIGNMENT(.rodata*))
        *(TFM_*_PSA-ROT_ATTR_FN)
        . = ALIGN(TFM_LINKER_PSA_ROT_LINKER_CODE_ALIGNMENT);
    } > FLASH

    Image$$TFM_PSA_ROT_LINKER$$RO$$Base = ADDR(.TFM_PSA_ROT_LINKER);
    Image$$TFM_PSA_ROT_LINKER$$RO$$Limit = ADDR(.TFM_PSA_ROT_LINKER) + SIZEOF(.TFM_PSA_ROT_LINKER);
    Image$$TFM_PSA_ROT_LINKER$$Base = ADDR(.TFM_PSA_ROT_LINKER);
    Image$$TFM_PSA_ROT_LINKER$$Limit = ADDR(.TFM_PSA_ROT_LINKER) + SIZEOF(.TFM_PSA_ROT_LINKER);

    /**** PSA RoT RO part (CODE + RODATA) end here */
    Image$$TFM_PSA_CODE_END$$Base = .;

    /**** APPLICATION RoT RO part (CODE + RODATA) start here */
    Image$$TFM_APP_CODE_START$$Base = .;

    .TFM_APP_ROT_LINKER ALIGN(TFM_LINKER_APP_ROT_LINKER_CODE_ALIGNMENT) :
    {
        *tfm_app_rot_partition*:(SORT_BY_ALIGNMENT(.text*))
        *tfm_app_rot_partition*:(SORT_BY_ALIGNMENT(.rodata*))
        *(TFM_*_APP-ROT_ATTR_FN)
        . = ALIGN(TFM_LINKER_APP_ROT_LINKER_CODE_ALIGNMENT);
    } > FLASH

    Image$$TFM_APP_ROT_LINKER$$RO$$Base = ADDR(.TFM_APP_ROT_LINKER);
    Image$$TFM_APP_ROT_LINKER$$RO$$Limit = ADDR(.TFM_APP_ROT_LINKER) + SIZEOF(.TFM_APP_ROT_LINKER);
    Image$$TFM_APP_ROT_LINKER$$Base = ADDR(.TFM_APP_ROT_LINKER);
    Image$$TFM_APP_ROT_LINKER$$Limit = ADDR(.TFM_APP_ROT_LINKER) + SIZEOF(.TFM_APP_ROT_LINKER);

    /**** APPLICATION RoT RO part (CODE + RODATA) end here */
    Image$$TFM_APP_CODE_END$$Base = .;

    .ARM.extab : ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH

    __exidx_start = .;
    .ARM.exidx : ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH
    __exidx_end = .;

    .ER_TFM_CODE ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) (READONLY) :
    {
        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);

        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);

        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);

        /* .copy.table */
        . = ALIGN(4);
        __copy_table_start__ = .;

        LONG (LOADADDR(.TFM_DATA))
        LONG (ADDR(.TFM_DATA))
        LONG (SIZEOF(.TFM_DATA) / 4)

        LONG (LOADADDR(.TFM_PSA_ROT_LINKER_DATA))
        LONG (ADDR(.TFM_PSA_ROT_LINKER_DATA))
        LONG (SIZEOF(.TFM_PSA_ROT_LINKER_DATA) / 4)

        LONG (LOADADDR(.TFM_APP_ROT_LINKER_DATA))
        LONG (ADDR(.TFM_APP_ROT_LINKER_DATA))
        LONG (SIZEOF(.TFM_APP_ROT_LINKER_DATA) / 4)

        __copy_table_end__ = .;

        /* .zero.table */
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (ADDR(.TFM_PSA_ROT_LINKER_BSS))
        LONG (SIZEOF(.TFM_PSA_ROT_LINKER_BSS) / 4)

        LONG (ADDR(.TFM_APP_ROT_LINKER_BSS))
        LONG (SIZEOF(.TFM_APP_ROT_LINKER_BSS) / 4)
#if defined(CONFIG_TFM_PARTITION_META)
        LONG (ADDR(.TFM_SP_META_PTR))
        LONG (SIZEOF(.TFM_SP_META_PTR) / 4)
#endif
        __zero_table_end__ = .;

        *startup*(.text*)
        *libplatform_s*:(SORT_BY_ALIGNMENT(.text*))
        *libtfm_spm*:(SORT_BY_ALIGNMENT(.text*))

        *libplatform_s*:*(.rodata*)
        *libtfm_spm*:*(.rodata*)
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH

#if defined(TFM_PARTITION_PM)
    tfm_lp_fw ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) (READONLY) :
    {
	__tfm_lp_fw_start = .;
	KEEP(TFM_LP_FW(.data*))
	__tfm_lp_fw_end = .;

        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > FLASH
#endif

#include <linker/devices.ld>

    .TFM_UNPRIV_CODE ALIGN(TFM_LINKER_UNPRIV_CODE_ALIGNMENT) :
    {
        *(SORT_BY_ALIGNMENT(.text*))

        KEEP(*(.init))
        KEEP(*(.fini))

        /* .ctors */
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)

        /* .dtors */
         *crtbegin.o(.dtors)
         *crtbegin?.o(.dtors)
         *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
         *(SORT(.dtors.*))
         *(.dtors)

        *(SORT_BY_ALIGNMENT(.rodata*))

        KEEP(*(.eh_frame*))
        . = ALIGN(TFM_LINKER_UNPRIV_CODE_ALIGNMENT);
    } > FLASH
    Image$$TFM_UNPRIV_CODE_START$$RO$$Base = ADDR(.TFM_UNPRIV_CODE);
    Image$$TFM_UNPRIV_CODE_END$$RO$$Limit = ADDR(.TFM_UNPRIV_CODE) + SIZEOF(.TFM_UNPRIV_CODE);

#if defined(CONFIG_TFM_USE_TRUSTZONE) && defined(TFM_LINKER_VENEERS_LOCATION_END)
    VENEERS()
#endif

    /* Position tag */
    . = ALIGN(TFM_LINKER_PT_RO_ALIGNMENT);
    Image$$PT_RO_END$$Base = .;

    /**** Base address of secure data area */
    .tfm_secure_data_start : ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT)
    {
        /* Relocate current position to RAM */
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM

    /*
     * MPU on Armv6-M/v7-M core in multi-core topology may require more strict
     * alignment that MPU region base address must align with the MPU region
     * size.
     * As a result, on Armv6-M/v7-M cores, to save memory resource and MPU
     * regions, unprivileged data sections and privileged data sections are
     * separated and gathered in unprivileged/privileged data area respectively.
     * Keep BL2 shared data and MSP stack at the beginning of the secure data
     * area on Armv8-M cores, while move the two areas to the beginning of
     * privileged data region on Armv6-M/v7-M cores.
     */

    /* shared_data and msp_stack are overlapping on purpose when
     * msp_stack is extended until the beginning of RAM, when shared_date
     * was read out by partitions
     */
    .tfm_bl2_shared_data ALIGN(TFM_LINKER_BL2_SHARED_DATA_ALIGNMENT) :
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM

    .msp_stack ALIGN(TFM_LINKER_MSP_STACK_ALIGNMENT) :
    {
        . += __msp_stack_size__ - 0x8;
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);

    .msp_stack_seal_res ALIGN(TFM_LINKER_MSP_STACK_ALIGNMENT) :
    {
        . += 0x8;
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM
    __StackSeal = ADDR(.msp_stack_seal_res);

#if defined(ENABLE_HEAP)
    __heap_size__ = S_HEAP_SIZE;
    .heap ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) :
    {
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        . += __heap_size__;
        __HeapLimit = .;
        __heap_limit = .; /* Add for _sbrk */
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM
#endif

#if defined(CONFIG_TFM_PARTITION_META)
    .TFM_SP_META_PTR ALIGN(TFM_LINKER_SP_META_PTR_ALIGNMENT) (NOLOAD):
    {
        *(.bss.SP_META_PTR_SPRTL_INST)
        . = ALIGN(TFM_LINKER_SP_META_PTR_ALIGNMENT);
    } > RAM
    Image$$TFM_SP_META_PTR$$ZI$$Base = ADDR(.TFM_SP_META_PTR);
    Image$$TFM_SP_META_PTR$$ZI$$Limit = ADDR(.TFM_SP_META_PTR) + SIZEOF(.TFM_SP_META_PTR);
    /* This is needed for the uniform configuration of MPU region. */
    Image$$TFM_SP_META_PTR_END$$ZI$$Limit = Image$$TFM_SP_META_PTR$$ZI$$Limit;
#endif

    /**** APPLICATION RoT DATA start here */
    . = ALIGN(TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT);
    Image$$TFM_APP_RW_STACK_START$$Base = .;

    .TFM_APP_ROT_LINKER_DATA ALIGN(TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT) :
    {
        *tfm_app_rot_partition*:(SORT_BY_ALIGNMENT(.data*))
        *(TFM_*_APP-ROT_ATTR_RW)
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM AT> FLASH
    Image$$TFM_APP_ROT_LINKER_DATA$$RW$$Base = ADDR(.TFM_APP_ROT_LINKER_DATA);
    Image$$TFM_APP_ROT_LINKER_DATA$$RW$$Limit = ADDR(.TFM_APP_ROT_LINKER_DATA) + SIZEOF(.TFM_APP_ROT_LINKER_DATA);

    .TFM_APP_ROT_LINKER_BSS ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) (NOLOAD) :
    {
        start_of_TFM_APP_ROT_LINKER = .;
        *tfm_app_rot_partition*:(SORT_BY_ALIGNMENT(.bss*))
        *tfm_app_rot_partition*:*(COMMON)
        *(TFM_*_APP-ROT_ATTR_ZI)
        . += (. - start_of_TFM_APP_ROT_LINKER) ? 0 : 4;
        . = ALIGN(TFM_LINKER_APP_ROT_LINKER_DATA_ALIGNMENT);
    } > RAM AT> RAM
    Image$$TFM_APP_ROT_LINKER_DATA$$ZI$$Base = ADDR(.TFM_APP_ROT_LINKER_BSS);
    Image$$TFM_APP_ROT_LINKER_DATA$$ZI$$Limit = ADDR(.TFM_APP_ROT_LINKER_BSS) + SIZEOF(.TFM_APP_ROT_LINKER_BSS);

    /**** APPLICATION RoT DATA end here */
    Image$$TFM_APP_RW_STACK_END$$Base = .;

    /**** PSA RoT DATA start here */

    Image$$TFM_PSA_RW_STACK_START$$Base = .;

    .TFM_PSA_ROT_LINKER_DATA ALIGN(TFM_LINKER_PSA_ROT_LINKER_DATA_ALIGNMENT) :
    {
        *tfm_psa_rot_partition*:(SORT_BY_ALIGNMENT(.data*))
        *(TFM_*_PSA-ROT_ATTR_RW)
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM AT> FLASH
    Image$$TFM_PSA_ROT_LINKER_DATA$$RW$$Base = ADDR(.TFM_PSA_ROT_LINKER_DATA);
    Image$$TFM_PSA_ROT_LINKER_DATA$$RW$$Limit = ADDR(.TFM_PSA_ROT_LINKER_DATA) + SIZEOF(.TFM_PSA_ROT_LINKER_DATA);

    .TFM_PSA_ROT_LINKER_BSS ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) (NOLOAD) :
    {
        start_of_TFM_PSA_ROT_LINKER = .;
        *tfm_psa_rot_partition*:(SORT_BY_ALIGNMENT(.bss*))
        *tfm_psa_rot_partition*:*(COMMON)
        *(TFM_*_PSA-ROT_ATTR_ZI)
        . += (. - start_of_TFM_PSA_ROT_LINKER) ? 0 : 4;
        . = ALIGN(TFM_LINKER_PSA_ROT_LINKER_DATA_ALIGNMENT);
    } > RAM AT> RAM
    Image$$TFM_PSA_ROT_LINKER_DATA$$ZI$$Base = ADDR(.TFM_PSA_ROT_LINKER_BSS);
    Image$$TFM_PSA_ROT_LINKER_DATA$$ZI$$Limit = ADDR(.TFM_PSA_ROT_LINKER_BSS) + SIZEOF(.TFM_PSA_ROT_LINKER_BSS);

    /**** PSA RoT DATA end here */
    Image$$TFM_PSA_RW_STACK_END$$Base = .;

    .TFM_DATA ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) :
    {
        *(SORT_BY_ALIGNMENT(.data*))

        KEEP(*(.jcr*))
#ifdef DEVSTATE_SECTION
        DEVSTATE_SECTION
#endif
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);

    } > RAM AT> FLASH
    Image$$ER_TFM_DATA$$RW$$Base = ADDR(.TFM_DATA);
    Image$$ER_TFM_DATA$$RW$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA);

    .TFM_BSS ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT) (NOLOAD) :
    {
        __bss_start__ = .;

        /* The runtime partition placed order is same as load partition */
        __partition_runtime_start__ = .;
        KEEP(*(.bss.part_runtime))
        __partition_runtime_end__ = .;
        . = ALIGN(4);

        /* The runtime service placed order is same as load partition */
        __service_runtime_start__ = .;
        KEEP(*(.bss.serv_runtime))
        __service_runtime_end__ = .;
        *(SORT_BY_ALIGNMENT(.bss*))
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
        . = ALIGN(TFM_LINKER_DEFAULT_ALIGNMENT);
    } > RAM AT> RAM
    Image$$ER_TFM_DATA$$ZI$$Base = ADDR(.TFM_BSS);
    Image$$ER_TFM_DATA$$ZI$$Limit = ADDR(.TFM_BSS) + SIZEOF(.TFM_BSS);
    Image$$ER_PART_RT_POOL$$ZI$$Base = __partition_runtime_start__;
    Image$$ER_PART_RT_POOL$$ZI$$Limit = __partition_runtime_end__;
    Image$$ER_SERV_RT_POOL$$ZI$$Base = __service_runtime_start__;
    Image$$ER_SERV_RT_POOL$$ZI$$Limit = __service_runtime_end__;

    Image$$ER_TFM_DATA$$Base = ADDR(.TFM_DATA);
    Image$$ER_TFM_DATA$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA) + SIZEOF(.TFM_BSS);

#ifdef PM_DEVICE_SLOTS_AREA
    PM_DEVICE_SLOTS_AREA
#endif

#if defined(CONFIG_TFM_USE_TRUSTZONE)
    Image$$ER_VENEER$$Base = ADDR(.gnu.sgstubs);
    Image$$VENEER_ALIGN$$Limit = ADDR(.sgstubs_end);

#if defined(TFM_LINKER_VENEERS_SIZE)
    ASSERT ((Image$$VENEER_ALIGN$$Limit - Image$$ER_VENEER$$Base) <= TFM_LINKER_VENEERS_SIZE, "Veneer region overflowed")
#endif
#endif

    Load$$LR$$LR_NS_PARTITION$$Base = NS_PARTITION_START;

    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit);
}
