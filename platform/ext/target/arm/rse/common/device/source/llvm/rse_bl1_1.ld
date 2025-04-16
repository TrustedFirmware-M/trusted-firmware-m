;/*
; * Copyright (c) 2021-2024 Arm Limited. All rights reserved.
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
; * This file is derivative of gcc/mps4_corstone3xx_bl1_1.ld
; */

/* Linker script to configure memory regions. */
/* This file will be run through the pre-processor. */

#include "region_defs.h"

MEMORY
{
    FLASH  (rx)  : ORIGIN = BL1_1_CODE_START, LENGTH = BL1_1_CODE_SIZE
    SHARED (rwx) : ORIGIN = BOOT_TFM_SHARED_DATA_BASE, LENGTH = BOOT_TFM_SHARED_DATA_SIZE
    RAM    (rwx) : ORIGIN = BL1_1_DATA_START, LENGTH = BL1_1_DATA_SIZE
}

ENTRY(Reset_Handler)

SECTIONS
{
    .text :
    {
        KEEP(*(.vectors))
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors;
        __end__ = .;

        *(.text*)
        *(.rodata*)
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

    __etext = ALIGN(4);

    .tfm_bl2_shared_data (NOLOAD) : ALIGN(32)
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > SHARED

    . = BL1_1_DATA_START;
    .data : AT (__etext)
    {
        *(.data*)
	} > RAM
    __data_start = ADDR(.data);
    __data_source = LOADADDR(.data);
    __data_size = SIZEOF(.data);

    .bss (NOLOAD) : ALIGN(4)
    {
        *(.bss*)
        . = ALIGN(4);
        __tls_base = . ;                /* to satisfy crt0 */
        __arm32_tls_tcb_offset = . ;    /* to satisfy crt0 */
    } > RAM
    __bss_start = ADDR(.bss);
    __bss_size = SIZEOF(.bss);

    .msp_stack (NOLOAD) : ALIGN(32)
    {
        . += BL1_MSP_STACK_SIZE;
    } > RAM
    __stack_seal = ADDR(.msp_stack) + SIZEOF(.msp_stack) - 0x8;
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = __stack_seal;

    .heap (NOLOAD) : ALIGN(8)
    {
        . += BL1_HEAP_SIZE;
    } > RAM
    __heap_start = ADDR(.heap);
    __heap_end = ADDR(.heap) + SIZEOF(.heap);
}
