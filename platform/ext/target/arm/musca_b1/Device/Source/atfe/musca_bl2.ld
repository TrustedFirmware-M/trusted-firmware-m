;/*
; * Copyright (c) 2009-2024 Arm Limited
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

MEMORY
{
    FLASH    (rx)  : ORIGIN = BL2_CODE_START, LENGTH = BL2_CODE_SIZE
    CODE_RAM (rwx) : ORIGIN = BL2_CODE_SRAM_BASE, LENGTH = S_RAM_CODE_SIZE
    RAM      (rwx) : ORIGIN = BL2_DATA_START, LENGTH = BL2_DATA_SIZE
}

__heap_size__  = BL2_HEAP_SIZE;
__msp_stack_size__ = BL2_MSP_STACK_SIZE;

ENTRY(Reset_Handler)

SECTIONS
{
    /* Startup section is loaded to Flash and runs from Flash */
    .startup :
    {
        __vectors_start = .;
        KEEP(*(.vectors))
        __vectors_end = .;


        KEEP(*(.init))
        KEEP(*(.fini))

        *startup_musca.*(.text*)
    } > FLASH

    /* eFlash driver code that gets copied from Flash to SRAM */
    .ER_CODE_SRAM : ALIGN(4)
    {
        *libflash_drivers.o(.text*)
        *libflash_drivers.o(.rodata*)
        . = ALIGN(4); /* This alignment is needed to make the section size 4 bytes aligned */
    } > CODE_RAM AT > FLASH
    Image$$ER_CODE_SRAM$$Base = ADDR(.ER_CODE_SRAM);
    Image$$ER_CODE_SRAM$$Limit = ADDR(.ER_CODE_SRAM) + SIZEOF(.ER_CODE_SRAM);

    .text : ALIGN(4)
    {
        *(.text*)

        /* .copy.table
         * To copy multiple ROM to RAM sections,
         * define __STARTUP_COPY_MULTIPLE in startup file */
        . = ALIGN(4);
        __copy_table_start__ = .;
        LONG (LOADADDR(.ER_CODE_SRAM))
        LONG (ADDR(.ER_CODE_SRAM))
        LONG (SIZEOF(.ER_CODE_SRAM) / 4)
#ifdef CODE_SHARING
        LONG (LOADADDR(.tfm_shared_symbols))
        LONG (ADDR(.tfm_shared_symbols))
        LONG (SIZEOF(.tfm_shared_symbols) / 4)
#endif
        LONG (LOADADDR(.data))
        LONG (ADDR(.data))
        LONG (SIZEOF(.data) / 4)
        __copy_table_end__ = .;

        /* .zero.table
         * To clear multiple BSS sections,
         * uncomment .zero.table and,
         * define __STARTUP_CLEAR_BSS_MULTIPLE in startup file */
        . = ALIGN(4);
        __zero_table_start__ = .;
       LONG (ADDR(.bss))
       LONG (SIZEOF(.bss) / 4)
        __zero_table_end__ = .;

        KEEP(*(.init))
        KEEP(*(.fini))
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

    .tfm_bl2_shared_data (NOLOAD): ALIGN(32)
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > RAM
    Image$$SHARED_DATA$$RW$$Base = ADDR(.tfm_bl2_shared_data);
    Image$$SHARED_DATA$$RW$$Limit = ADDR(.tfm_bl2_shared_data) + SIZEOF(.tfm_bl2_shared_data);

    .data : ALIGN(4)
    {
        *(.data*)
    } > RAM AT > FLASH

    .bss (NOLOAD) : ALIGN(4)
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
    } > RAM
    __bss_start = ADDR(.bss);
    __bss_end = ADDR(.bss) + SIZEOF(.bss);
    __bss_size = SIZEOF(.bss);

    .msp_stack (NOLOAD) : ALIGN(32)
    {
        . += BL2_MSP_STACK_SIZE;
    } > RAM
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);

    .heap (NOLOAD): ALIGN(8)
    {
        . += BL2_HEAP_SIZE;
        __tls_base = .;                /* dummy. for picolib crt0 only */
        __arm32_tls_tcb_offset = .;    /* dummy. for picolib crt0 only */
    } > RAM
    __heap_start = ADDR(.heap);
    __heap_end = ADDR(.heap) + SIZEOF(.heap);
    __heap_size = SIZEOF(.heap);

    /* Those 2 symbols defines the region for clearing on boot completion */
    Image$$ER_DATA$$Base = ADDR(.data);
    Image$$ARM_LIB_HEAP$$ZI$$Limit = ADDR(.heap) + SIZEOF(.heap);

#ifdef CODE_SHARING
    __data_start  = ADDR(.tfm_shared_symbols);
    __data_source = LOADADDR(.tfm_shared_symbols);
    __data_size   = SIZEOF(tfm_shared_symbols) + SIZEOF(tfm_bl2_shared_data) + SIZEOF(.data);
#else /* CODE_SHARING */
    __data_start  = ADDR(.data);
    __data_source = LOADADDR(.data);
    __data_size   = SIZEOF(.data);
#endif /* CODE_SHARING */

/*    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit); */
}
