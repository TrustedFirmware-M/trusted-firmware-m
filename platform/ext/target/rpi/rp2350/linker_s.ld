;/*
; *  SPDX-License-Identifier: BSD-3-Clause
; *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
; *
; */
/* Linker script to configure memory regions. */
/* This file will be run trough the pre-processor. */
#include "region_defs.h"
/* Include file with definitions for section alignments.
 * Note: it should be included after region_defs.h to let platform define
 * default values if needed. */
#include "tfm_s_linker_alignments.h"
MEMORY
{
  FLASH    (rx)  : ORIGIN = S_CODE_START, LENGTH = S_CODE_SIZE
  RAM      (rw)  : ORIGIN = S_DATA_START, LENGTH = S_DATA_SIZE
#if defined(S_RAM_CODE_START)
  CODE_RAM (rwx) : ORIGIN = S_RAM_CODE_START, LENGTH = S_RAM_CODE_SIZE
#endif
#ifdef __ENABLE_SCRATCH__
  SCRATCH_X(rwx) : ORIGIN = SCRATCH_X_START, LENGTH = SCRATCH_X_SIZE
  SCRATCH_Y(rwx) : ORIGIN = SCRATCH_Y_START, LENGTH = SCRATCH_Y_SIZE
#endif
}

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

ENTRY(_entry_point)

SECTIONS
{
    /* Start address of the code. */
    Image$$PT_RO_START$$Base = ADDR(.TFM_VECTORS);

    .TFM_VECTORS : ALIGN(4)
    {
        __logical_binary_start = .;
        __vectors_start__ = .;
        KEEP(*(.vectors))
        . = ALIGN(4);
        __vectors_end__ = .;
    } > FLASH

    ASSERT(__vectors_start__ != __vectors_end__, ".vectors should not be empty")

#if defined(S_CODE_VECTOR_TABLE_SIZE)
    ASSERT(. <= ADDR(.TFM_VECTORS) + S_CODE_VECTOR_TABLE_SIZE, ".TFM_VECTORS section size overflow.")
    . = ADDR(.TFM_VECTORS) + S_CODE_VECTOR_TABLE_SIZE;
#endif

    .PICO_RESET : ALIGN(4)
    {
        KEEP (*(.binary_info_header))
        __binary_info_header_end = .;
        KEEP (*(.embedded_block))
        __embedded_block_end = .;
        KEEP (*(.reset))
    } > FLASH

#if defined(CONFIG_TFM_USE_TRUSTZONE) && !defined(TFM_LINKER_VENEERS_LOCATION_END)
    VENEERS()
#endif

    /**** Section for holding partition RO load data */
    /*
     * Sort the partition info by priority to guarantee the initing order.
     * The first loaded partition will be inited at last in SFN model.
     */
    .TFM_SP_LOAD_LIST ALIGN(4) :
    {
       KEEP(*(.part_load))
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

#if defined(S_RAM_CODE_START)
    /* Flash drivers code that gets copied from Flash */
    .ER_CODE_SRAM ALIGN(S_RAM_CODE_START, 4) :
    {
        *libflash_drivers*:(SORT_BY_ALIGNMENT(.text*))
        *libflash_drivers*:(SORT_BY_ALIGNMENT(.rodata*))
        KEEP(*(.ramfunc))
        . = ALIGN(4); /* This alignment is needed to make the section size 4 bytes aligned */
    } > CODE_RAM AT > FLASH

    ASSERT(S_RAM_CODE_START % 4 == 0, "S_RAM_CODE_START must be divisible by 4")

    Image$$ER_CODE_SRAM$$RO$$Base = ADDR(.ER_CODE_SRAM);
    Image$$ER_CODE_SRAM$$RO$$Limit = ADDR(.ER_CODE_SRAM) + SIZEOF(.ER_CODE_SRAM);
    Image$$ER_CODE_SRAM$$Base = ADDR(.ER_CODE_SRAM);
    Image$$ER_CODE_SRAM$$Limit = ADDR(.ER_CODE_SRAM) + SIZEOF(.ER_CODE_SRAM);
#endif

    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > FLASH
    __exidx_end = .;

    /* Machine inspectable binary information */
    . = ALIGN(4);
    __binary_info_start = .;
    .binary_info :
    {
        KEEP(*(.binary_info.keep.*))
        *(.binary_info.*)
    } > FLASH
    __binary_info_end = .;

    /* Data copy is done by extra_init */
    __etext = 0;
    __data_start__ = 0;
    __data_end__ = 0;

    .ER_TFM_CODE ALIGN(4) (READONLY) :
    {
        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__mutex_array_start = .);
        KEEP(*(SORT(.mutex_array.*)))
        KEEP(*(.mutex_array))
        PROVIDE_HIDDEN (__mutex_array_end = .);

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(SORT(.preinit_array.*)))
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
#ifdef RAM_VECTORS_SUPPORT
        /* Copy interrupt vectors from flash to RAM */
        LONG (__vectors_start__)                            /* From */
        LONG (__ram_vectors_start__)                        /* To   */
        LONG ((__vectors_end__ - __vectors_start__) / 4)    /* Size */
#endif
        LONG (LOADADDR(.TFM_DATA))
        LONG (ADDR(.TFM_DATA))
        LONG (SIZEOF(.TFM_DATA) / 4)

        LONG (LOADADDR(.TFM_PSA_ROT_LINKER_DATA))
        LONG (ADDR(.TFM_PSA_ROT_LINKER_DATA))
        LONG (SIZEOF(.TFM_PSA_ROT_LINKER_DATA) / 4)

        LONG (LOADADDR(.TFM_APP_ROT_LINKER_DATA))
        LONG (ADDR(.TFM_APP_ROT_LINKER_DATA))
        LONG (SIZEOF(.TFM_APP_ROT_LINKER_DATA) / 4)

#if defined (S_RAM_CODE_START)
        LONG (LOADADDR(.ER_CODE_SRAM))
        LONG (ADDR(.ER_CODE_SRAM))
        LONG (SIZEOF(.ER_CODE_SRAM) / 4)
#endif
        __copy_table_end__ = .;

        /* .zero.table */
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (ADDR(.TFM_BSS))
        LONG (SIZEOF(.TFM_BSS) / 4)
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
        /* Remove flash driver related files */
        EXCLUDE_FILE (*libplatform_s*:*Flash_RPI*) *libplatform_s*:(SORT_BY_ALIGNMENT(.text*))
        *libtfm_spm*:(SORT_BY_ALIGNMENT(.text*))

        EXCLUDE_FILE (*libplatform_s*:*Flash_RPI*) *libplatform_s*:*(.rodata*)
        *libtfm_spm*:*(.rodata*)
    } > FLASH

    .TFM_UNPRIV_CODE ALIGN(TFM_LINKER_UNPRIV_CODE_ALIGNMENT) :
    {
        /* Remove flash driver related files */
        EXCLUDE_FILE (*libplatform_s*:*Flash_RPI*) *(SORT_BY_ALIGNMENT(.text*))

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
        . = ALIGN(4);
        *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.flashdata*)))

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
    .tfm_secure_data_start :
    {
        /* Relocate current position to RAM */
        . = ALIGN(4);
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
#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) || \
    defined(__ARM_ARCH_8_1M_MAIN__)
#ifdef CODE_SHARING
    /* The code sharing between bootloader and runtime requires to share the
     * global variables.
     */
    .TFM_SHARED_SYMBOLS ALIGN(TFM_LINKER_SHARED_SYMBOLS_ALIGNMENT) :
    {
        . += SHARED_SYMBOL_AREA_SIZE;
    } > RAM
#endif

    /* shared_data and msp_stack are overlapping on purpose when
     * msp_stack is extended until the beginning of RAM, when shared_date
     * was read out by partitions
     */
    .tfm_bl2_shared_data ALIGN(TFM_LINKER_BL2_SHARED_DATA_ALIGNMENT) :
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > RAM

    .msp_stack ALIGN(TFM_LINKER_MSP_STACK_ALIGNMENT) :
    {
        . += __msp_stack_size__ - 0x8;
    } > RAM
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);

    .msp_stack_seal_res :
    {
        . += 0x8;
    } > RAM
    __StackSeal = ADDR(.msp_stack_seal_res);

#endif /* defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) || \
        * defined(__ARM_ARCH_8_1M_MAIN__) */

   .ram_vector_table (NOLOAD): ALIGN(256) {
        *(.ram_vector_table)
    } > RAM

#if defined(ENABLE_HEAP)
    __heap_size__ = S_HEAP_SIZE;
    .heap (NOLOAD): ALIGN(8)
    {
        . = ALIGN(8);
        __end__ = .;
        end = __end__;
        PROVIDE(end = .);
        __HeapBase = .;
        KEEP(*(.heap*))
        . += __heap_size__;
        __HeapLimit = .;
        __heap_limit = .;
    } > RAM
#else
    end = 0;
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
        . = ALIGN(4);
    } > RAM AT> FLASH
    Image$$TFM_APP_ROT_LINKER_DATA$$RW$$Base = ADDR(.TFM_APP_ROT_LINKER_DATA);
    Image$$TFM_APP_ROT_LINKER_DATA$$RW$$Limit = ADDR(.TFM_APP_ROT_LINKER_DATA) + SIZEOF(.TFM_APP_ROT_LINKER_DATA);

    .TFM_APP_ROT_LINKER_BSS ALIGN(4) (NOLOAD) :
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
        . = ALIGN(4);
    } > RAM AT> FLASH
    Image$$TFM_PSA_ROT_LINKER_DATA$$RW$$Base = ADDR(.TFM_PSA_ROT_LINKER_DATA);
    Image$$TFM_PSA_ROT_LINKER_DATA$$RW$$Limit = ADDR(.TFM_PSA_ROT_LINKER_DATA) + SIZEOF(.TFM_PSA_ROT_LINKER_DATA);

    .TFM_PSA_ROT_LINKER_BSS ALIGN(4) (NOLOAD) :
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

#ifdef RAM_VECTORS_SUPPORT
    .ramVectors ALIGN(TFM_LINKER_RAM_VECTORS_ALIGNMENT) (NOLOAD) :
    {
        __ram_vectors_start__ = .;
        KEEP(*(.ram_vectors))
        __ram_vectors_end__   = .;
    } > RAM
    .TFM_DATA __ram_vectors_end__ :
#else

    .TFM_DATA ALIGN(4) :
#endif
    {
        *(vtable)
        *(.time_critical*)
        *(*libplatform_s*:*Flash_RPI* .text*)
        *(*libplatform_s*:*Flash_RPI* .rodata*)
        *(SORT_BY_ALIGNMENT(.data*))
        *(.sdata*)
        . = ALIGN(4);
        *(.after_data.*)

        KEEP(*(.jcr*))
        . = ALIGN(4);

    } > RAM AT> FLASH
    Image$$ER_TFM_DATA$$RW$$Base = ADDR(.TFM_DATA);
    Image$$ER_TFM_DATA$$RW$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA);

    .uninitialized_data (NOLOAD): {
        . = ALIGN(4);
        *(.uninitialized_data*)
    } > RAM AT> RAM

    .TFM_BSS ALIGN(4) (NOLOAD) :
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
        *(.sbss*)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM AT> RAM
    Image$$ER_TFM_DATA$$ZI$$Base = ADDR(.TFM_BSS);
    Image$$ER_TFM_DATA$$ZI$$Limit = ADDR(.TFM_BSS) + SIZEOF(.TFM_BSS);
    Image$$ER_PART_RT_POOL$$ZI$$Base = __partition_runtime_start__;
    Image$$ER_PART_RT_POOL$$ZI$$Limit = __partition_runtime_end__;
    Image$$ER_SERV_RT_POOL$$ZI$$Base = __service_runtime_start__;
    Image$$ER_SERV_RT_POOL$$ZI$$Limit = __service_runtime_end__;

    Image$$ER_TFM_DATA$$Base = ADDR(.TFM_DATA);
    Image$$ER_TFM_DATA$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA) + SIZEOF(.TFM_BSS);

#if defined(CONFIG_TFM_USE_TRUSTZONE)
    Image$$ER_VENEER$$Base = ADDR(.gnu.sgstubs);
    Image$$VENEER_ALIGN$$Limit = ADDR(.sgstubs_end);

#if defined(TFM_LINKER_VENEERS_SIZE)
    ASSERT ((Image$$VENEER_ALIGN$$Limit - Image$$ER_VENEER$$Base) <= TFM_LINKER_VENEERS_SIZE, "Veneer region overflowed")
#endif
#endif

#if defined(TFM_LOAD_NS_IMAGE)
    Load$$LR$$LR_NS_PARTITION$$Base = NS_PARTITION_START;
#endif

#ifdef BL2
    Load$$LR$$LR_SECONDARY_PARTITION$$Base = SECONDARY_PARTITION_START;
#endif /* BL2 */

    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit);

#ifdef __ENABLE_SCRATCH__
    /* Start and end symbols must be word-aligned */
    .scratch_x : {
        __scratch_x_start__ = .;
        *(.scratch_x.*)
        . = ALIGN(4);
        __scratch_x_end__ = .;
    } > SCRATCH_X AT > FLASH
    __scratch_x_source__ = LOADADDR(.scratch_x);
    .scratch_y : {
        __scratch_y_start__ = .;
        *(.scratch_y.*)
        . = ALIGN(4);
        __scratch_y_end__ = .;
    } > SCRATCH_Y AT > FLASH
    __scratch_y_source__ = LOADADDR(.scratch_y);

    .stack1_dummy (NOLOAD):
    {
        *(.stack1*)
    } > SCRATCH_X
    .stack_dummy (NOLOAD):
    {
        KEEP(*(.stack*))
    } > SCRATCH_Y

    PROVIDE(__StackBottom = Image$$ARM_LIB_STACK$$ZI$$Base);
    PROVIDE(__StackTop = Image$$ARM_LIB_STACK$$ZI$$Limit);
    __StackOneTop = ORIGIN(SCRATCH_X) + LENGTH(SCRATCH_X);
    __StackOneBottom = __StackOneTop - SIZEOF(.stack1_dummy);
#endif

    ASSERT( __binary_info_header_end - __logical_binary_start <= 1024, "Binary info must be in first 1024 bytes of the binary")
}
