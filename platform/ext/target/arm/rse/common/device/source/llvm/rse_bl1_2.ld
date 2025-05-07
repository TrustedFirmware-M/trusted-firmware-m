;/*
; * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
; * This file is derivative of gcc/mps4_corstone3xx_bl1_2.ld
; */

/* Linker script to configure memory regions. */
/* This file will be run through the pre-processor. */

#include "region_defs.h"

MEMORY
{
    FLASH (rx)  : ORIGIN = BL1_2_CODE_START, LENGTH = BL1_2_CODE_SIZE
    RAM   (rwx) : ORIGIN = BL1_2_DATA_START, LENGTH = BL1_2_DATA_SIZE
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

    . = BL1_2_DATA_START;
    Image$$BL1_2_ER_DATA_START$$Base = .;
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

    /* No stack or heap defined as BL1_2 uses the same stack and
     * heap as BL1_1
     */

    Image$$BL1_2_ER_DATA_LIMIT$$Base = .;

    Image$$BL1_1_ER_DATA_START$$Base = BL1_1_DATA_START;
    Image$$BL1_1_ER_DATA_LIMIT$$Base = BL1_1_DATA_START + BL1_1_DATA_SIZE;
}
