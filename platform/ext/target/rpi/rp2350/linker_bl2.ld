;/*
; *  SPDX-License-Identifier: BSD-3-Clause
; *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
; *
; */
/* Linker script to configure memory regions. */
/* This file will be run trough the pre-processor. */
#include "region_defs.h"
MEMORY
{
    FLASH (rx)  : ORIGIN = BL2_CODE_START, LENGTH = BL2_CODE_SIZE
    RAM   (rwx) : ORIGIN = BL2_DATA_START, LENGTH = BL2_DATA_SIZE
#ifdef __ENABLE_SCRATCH__
    SCRATCH_X(rwx) : ORIGIN = SCRATCH_X_START, LENGTH = SCRATCH_X_SIZE
    SCRATCH_Y(rwx) : ORIGIN = SCRATCH_Y_START, LENGTH = SCRATCH_Y_SIZE
#endif
}
__heap_size__  = BL2_HEAP_SIZE;
__msp_stack_size__ = BL2_MSP_STACK_SIZE;
ENTRY(Reset_Handler)
SECTIONS
{
    .flash_begin : {
        __flash_binary_start = .;
    } > FLASH
    .text (READONLY) :
    {
        __logical_binary_start = .;
        __Vectors_Start = .;
        KEEP(*(.vectors))
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors_Start;
        KEEP (*(.binary_info_header))
        __binary_info_header_end = .;
        KEEP (*(.embedded_block))
        __embedded_block_end = .;
        KEEP (*(.reset))
        __end__ = .;
        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        PROVIDE(__bothinit_array_start = __preinit_array_start);
        KEEP(*(SORT(.preinit_array.*)))
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);
        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);
        PROVIDE(__bothinit_array_end = __init_array_end);
        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);
        /* .copy.table */
        . = ALIGN(4);
        __copy_table_start__ = .;
#ifdef CODE_SHARING
        LONG (LOADADDR(.tfm_shared_symbols))
        LONG (ADDR(.tfm_shared_symbols))
        LONG (SIZEOF(.tfm_shared_symbols) / 4)
#endif
        LONG (LOADADDR(.data))
        LONG (ADDR(.data))
        LONG (SIZEOF(.data) / 4)
        __copy_table_end__ = .;
        /* .zero.table */
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (ADDR(.bss))
        LONG (SIZEOF(.bss) / 4)
        __zero_table_end__ = .;
        KEEP(*(.init))
        *(EXCLUDE_FILE(*libgcc.a: *libc.a:*lib_a-mem*.o *libm.a:) .text*)
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
        *(EXCLUDE_FILE(*libgcc.a: *libc.a:*lib_a-mem*.o *libm.a:) .rodata*)
        *(.srodata*)
        . = ALIGN(4);
        *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.flashdata*)))
        . = ALIGN(4);
        KEEP(*(.eh_frame*))
        . = ALIGN(4);
    } > FLASH
    /* Note the boot2 section is optional, and should be discarded if there is
       no reference to it *inside* the binary, as it is not called by the
       bootrom. (The bootrom performs a simple best-effort XIP setup and
       leaves it to the binary to do anything more sophisticated.) However
       there is still a size limit of 256 bytes, to ensure the boot2 can be
       stored in boot RAM.
       Really this is a "XIP setup function" -- the name boot2 is historic and
       refers to its dual-purpose on RP2040, where it also handled vectoring
       from the bootrom into the user image.
    */
    .boot2 : {
        __boot2_start__ = .;
        *(.boot2)
        __boot2_end__ = .;
    } > FLASH
    ASSERT(__boot2_end__ - __boot2_start__ <= 256,
        "ERROR: Pico second stage bootloader must be no more than 256 bytes in size")
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
#ifdef CODE_SHARING
    /* The code sharing between bootloader and runtime firmware requires to
     * share the global variables. Section size must be equal with
     * SHARED_SYMBOL_AREA_SIZE defined in region_defs.h
     */
    .tfm_shared_symbols : ALIGN(4)
    {
        *(.data.mbedtls_calloc_func)
        *(.data.mbedtls_free_func)
        *(.data.mbedtls_exit)
        *(.data.memset_func)
        . = ALIGN(SHARED_SYMBOL_AREA_SIZE);
    } > RAM AT > FLASH
    ASSERT(SHARED_SYMBOL_AREA_SIZE % 4 == 0, "SHARED_SYMBOL_AREA_SIZE must be divisible by 4")
#endif
    .tfm_bl2_shared_data : ALIGN(32)
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > RAM
    Image$$SHARED_DATA$$RW$$Base = ADDR(.tfm_bl2_shared_data);
    Image$$SHARED_DATA$$RW$$Limit = ADDR(.tfm_bl2_shared_data) + SIZEOF(.tfm_bl2_shared_data);
    . = ALIGN(4);
   .ram_vector_table (NOLOAD): {
        *(.ram_vector_table)
    } > RAM
    .data : ALIGN(4)
    {
        __data_start__ = .;
        *(vtable)
        *(.time_critical*)
        /* remaining .text and .rodata; i.e. stuff we exclude above because we want it in RAM */
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN(4);
        *(.data*)
        *(.sdata*)
        . = ALIGN(4);
        *(.after_data.*)
        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__mutex_array_start = .);
        KEEP(*(SORT(.mutex_array.*)))
        KEEP(*(.mutex_array))
        PROVIDE_HIDDEN (__mutex_array_end = .);
        KEEP(*(.jcr*))
        . = ALIGN(4);
        /* All data end */
        __data_end__ = .;
    } > RAM AT > FLASH
    __etext = LOADADDR(.data);
    Image$$ER_DATA$$Base = ADDR(.data);
    .uninitialized_data (NOLOAD): {
        . = ALIGN(4);
        *(.uninitialized_data*)
    } > RAM
    .bss : ALIGN(4)
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.bss*)))
        *(COMMON)
        PROVIDE(__global_pointer$ = . + 2K);
        *(.sbss*)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    .msp_stack ALIGN(32) :
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
#else
    .msp_stack ALIGN(32) :
    {
        . += __msp_stack_size__;
    } > RAM
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
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
#endif
    .heap (NOLOAD): ALIGN(8)
    {
        . = ALIGN(8);
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        PROVIDE(__heap_start = __HeapBase);
        KEEP(*(.heap*))
        . += __heap_size__;
        __HeapLimit = .;
        PROVIDE(__heap_end = __HeapLimit);
        __heap_limit = .; /* Add for _sbrk */
    } > RAM
    Image$$ARM_LIB_HEAP$$ZI$$Limit = ADDR(.heap) + SIZEOF(.heap);
    /* .stack*_dummy section doesn't contains any symbols. It is only
     * used for linker to calculate size of stack sections, and assign
     * values to stack symbols later
     *
     * stack1 section may be empty/missing if platform_launch_core1 is not used */
    /* by default we put core 0 stack at the end of scratch Y, so that if core 1
     * stack is not used then all of SCRATCH_X is free.
     */
#ifdef __ENABLE_SCRATCH__
    .stack1_dummy (NOLOAD):
    {
        *(.stack1*)
    } > SCRATCH_X
    .stack_dummy (NOLOAD):
    {
        KEEP(*(.stack*))
    } > SCRATCH_Y
#endif
    .flash_end : {
        PROVIDE(__flash_binary_end = .);
    } > FLASH =0xaa
    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit);
#ifdef __ENABLE_SCRATCH__
    /* stack limit is poorly named, but historically is maximum heap ptr */
    __StackLimit = ORIGIN(RAM) + LENGTH(RAM);
    __StackOneTop = ORIGIN(SCRATCH_X) + LENGTH(SCRATCH_X);
    __StackTop = ORIGIN(SCRATCH_Y) + LENGTH(SCRATCH_Y);
    __StackOneBottom = __StackOneTop - SIZEOF(.stack1_dummy);
    __StackBottom = __StackTop - SIZEOF(.stack_dummy);
    /* Check if data + heap + stack exceeds RAM limit */
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed")
#endif
    ASSERT( __binary_info_header_end - __logical_binary_start <= 1024, "Binary info must be in first 1024 bytes of the binary")
    /* todo assert on extra code */
}
