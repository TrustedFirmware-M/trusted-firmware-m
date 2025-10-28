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
MEMORY
{
    FLASH (rx)  : ORIGIN = NS_CODE_START, LENGTH = NS_CODE_SIZE
    RAM   (rwx) : ORIGIN = NS_DATA_START, LENGTH = NS_DATA_SIZE
#ifdef __ENABLE_SCRATCH__
    SCRATCH_X(rwx) : ORIGIN = SRAM_SCRATCH_X_BASE, LENGTH = SCRATCH_X_SIZE
    SCRATCH_Y(rwx) : ORIGIN = SRAM_SCRATCH_Y_BASE, LENGTH = SCRATCH_Y_SIZE
#endif
}

__heap_size__  = NS_HEAP_SIZE;
__stack_size__ = NS_STACK_SIZE;
ENTRY(_entry_point)
SECTIONS
{
    .vectors :
    {
        __logical_binary_start = .;
        __Vectors_Start__ = .;
        KEEP(*(.vectors))
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors_Start__;
        __end__ = .;
    } > FLASH

#if defined(NS_VECTOR_ALLOCATED_SIZE)
    ASSERT(. <= ADDR(.vectors) + NS_VECTOR_ALLOCATED_SIZE, ".vectors section size overflow.")
    . = ADDR(.vectors) + NS_VECTOR_ALLOCATED_SIZE;
#endif

    .CORE1_ENTRY : ALIGN(4)
    {
        KEEP (*(.core1_ns_entry*))
    }

    .PICO_RESET : ALIGN(4)
    {
        KEEP (*(.binary_info_header))
        __binary_info_header_end = .;
        KEEP (*(.embedded_block))
        __embedded_block_end = .;
        KEEP (*(.reset))
    } > FLASH

    .text (READONLY) :
    {
        *(.text*)

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__mutex_array_start = .);
        KEEP(*(SORT(.mutex_array.*)))
        KEEP(*(.mutex_array))
        PROVIDE_HIDDEN (__mutex_array_end = .);

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
        LONG (__etext)
        LONG (__data_start__)
        LONG ((__data_end__ - __data_start__) / 4)
        LONG (__etext2)
        LONG (__data2_start__)
        LONG ((__data2_end__ - __data2_start__) / 4)
        __copy_table_end__ = .;

        /* .zero.table */
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (__bss_start__)
        LONG ((__bss_end__ - __bss_start__) / 4)
        LONG (__bss2_start__)
        LONG ((__bss2_end__ - __bss2_start__) / 4)
        __zero_table_end__ = .;

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

        *(.rodata*)

        KEEP(*(.eh_frame*))
    } > FLASH

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

    __etext2 = ALIGN(4);

    .data : AT (__etext2)
    {
        __data2_start__ = .;
        *(vtable)
        *(.data*)

        KEEP(*(.jcr*))
        . = ALIGN(4);
        /* All data end */
        __data2_end__ = .;
    } > RAM

    /* Pico crt0.S copies the __data_start__-__data_end__ region, but we handle
     * that in our runtime_init */
     __etext = 0;
     __data_start__ = 0;
     __data_end__ = 0;

    .ram_vector_table (NOLOAD): ALIGN(256)  {
        *(.ram_vector_table)
    } > RAM

    .bss :
    {
        . = ALIGN(4);
        __bss2_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss2_end__ = .;
    } > RAM

    /* Pico crt0.S zeros the __bss_start__-__bss_end__ region, but we handle
     * that in our runtime_init */
     __bss_start__ = 0;
     __bss_end__ = 0;

    bss_size = __bss2_end__ - __bss2_start__;

    .heap : ALIGN(8)
    {
        . = ALIGN(8);
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        PROVIDE(__heap_start = __HeapBase);
        . += __heap_size__;
        __HeapLimit = .;
        PROVIDE(__heap_end = __HeapLimit);
        __heap_limit = .; /* Add for _sbrk */
    } > RAM

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

    /* stack limit is poorly named, but historically is maximum heap ptr */
    __StackLimit = ORIGIN(RAM) + LENGTH(RAM);
    __StackOneTop = ORIGIN(SCRATCH_X) + LENGTH(SCRATCH_X);
    __StackTop = ORIGIN(SCRATCH_Y) + LENGTH(SCRATCH_Y);
    __StackOneBottom = __StackOneTop - SIZEOF(.stack1_dummy);
    __StackBottom = __StackTop - SIZEOF(.stack_dummy);
    /* Check if data + heap + stack exceeds RAM limit */
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed")
    PROVIDE(__stack = __StackTop);
#endif

    ASSERT( __binary_info_header_end - __logical_binary_start <= 1024, "Binary info must be in first 1024 bytes of the binary")
}
