/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)
GROUP(libgcc.a libc.a libm.a libnosys.a)
ENTRY(Reset_Handler)

#define IFX_LINKER_SCRIPT   1

/* Verify that target config header exists */
#ifndef IFX_TARGET_LINKER_CONFIG_HEADER
#error IFX_TARGET_LINKER_CONFIG_HEADER must be defined
#endif

/* Include target configuration header */
#include IFX_TARGET_LINKER_CONFIG_HEADER

/* The MEMORY section below describes the location and size of blocks of memory
 * in the target. Use this section to specify the memory regions available for
 * allocation.
 */
MEMORY
{
    flash      (rx)     : ORIGIN = NS_CODE_START,    LENGTH = NS_CODE_SIZE
    ram       (rwx)     : ORIGIN = NS_DATA_START,    LENGTH = NS_DATA_SIZE
#ifdef IFX_NS_SHARED_MEMORY_ADDR
    sharedmem (rw)      : ORIGIN = IFX_NS_SHARED_MEMORY_ADDR, LENGTH = IFX_NS_SHARED_MEMORY_SIZE
#endif /* IFX_NS_SHARED_MEMORY_ADDR */
}

/* Linker script to place sections and symbol values.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __Vectors_End
 *   __Vectors_Size
 */

SECTIONS
{
    .vectors (READONLY) :
    {
        /* Vector table */
        . = ALIGN(4);
        __Vectors = . ;
        KEEP(*(.vectors))
        . = ALIGN(4);
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors;
    } > flash


    .text (READONLY) :
    {
        /* Program code */
        . = ALIGN(4);
        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))

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

        /* Read only data */
        *(.rodata .rodata.* .constdata .constdata.* .conststring .conststring.*)
    } > flash


    .ARM.extab (READONLY) :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > flash


    __exidx_start = .;
    .ARM.exidx (READONLY) :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > flash
    __exidx_end = .;


    .copy.table (READONLY) :
    {
        . = ALIGN(4);
        __copy_table_start__ = .;

#ifdef RAM_VECTORS_SUPPORT
        /* Copy interrupt vectors from flash to RAM */
        LONG (ADDR(.vectors))                               /* From */
        LONG (ADDR(.ramVectors))                            /* To   */
        LONG (SIZEOF(.vectors) / 4)                         /* Size */
#endif
        /* Copy data section to RAM */
        LONG (LOADADDR(.data))                              /* From */
        LONG (ADDR(.data))                                  /* To   */
        LONG (SIZEOF(.data) / 4)                            /* Size */

        __copy_table_end__ = .;
    } > flash


    .zero.table (READONLY) :
    {
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (__bss_start__)
        LONG ((__bss_end__ - __bss_start__) / 4)
        __zero_table_end__ = .;
    } > flash
    __etext = ALIGN(4);


#ifdef RAM_VECTORS_SUPPORT
    .ramVectors (NOLOAD) :
    {
        . = ALIGN(4);
        __ram_vectors_start__ = .;
        KEEP(*(.ram_vectors))
        . = ALIGN(4);
        __ram_vectors_end__   = .;
        __ram_vectors_size__  = __ram_vectors_end__ - __ram_vectors_start__;
    } > ram


    .data __ram_vectors_end__ :
#else
    .data :
#endif
    {
        . = ALIGN(4);
        __data_start__ = .;

        *(vtable)
        *(.data*)

        KEEP(*(.jcr*))
        . = ALIGN(4);

#ifdef RAM_CODE_SEC_NAME
        KEEP(*(S_RAM_CODE_SEC_NAME))
        . = ALIGN(4);
#endif

        __data_end__ = .;
    } > ram AT> flash


    /* Place variables in the section that should not be initialized during the
    *  device startup.
    */
    .noinit (NOLOAD) : ALIGN(8)
    {
        KEEP(*(.noinit))
    } > ram


    /* The uninitialized global or static variables are placed in this section. */
    .bss (NOLOAD):
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > ram


    .heap (NOLOAD):
    {
        __HeapBase = .;
        __end__ = .;
        PROVIDE(end = .);
        end = __end__;
        /* Allocates all available RAM to heap - similar to PDL linker script */
        . = ORIGIN(ram) + LENGTH(ram)
        - NS_MSP_STACK_SIZE;
        __HeapLimit = .;
    } > ram


    .msp_stack (NOLOAD): ALIGN(32)
    {
        /* Stack location for PDL startup */
        __StackLimit = .;
        . += NS_MSP_STACK_SIZE;
        /* Stack location for PDL startup */
        __StackTop = .;
    } > ram

    PROVIDE(__stack = __StackTop);

#ifdef IFX_NS_SHARED_MEMORY_ADDR
    .cy_sharedmem (NOLOAD) : ALIGN(4)
    {
        KEEP(*(.cy_sharedmem))
        . = ALIGN(4);
    } > sharedmem
#endif /* IFX_NS_SHARED_MEMORY_ADDR */
}
