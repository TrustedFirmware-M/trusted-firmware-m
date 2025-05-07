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
; * This file is derivative of CMSIS V5.00 gcc_arm.ld
; */

/* Linker script to configure memory regions. */
/* This file will be run through the pre-processor. */

#include "region_defs.h"

MEMORY
{
    FLASH (rx)  : ORIGIN = BL2_CODE_START, LENGTH = BL2_CODE_SIZE
    RAM   (rwx) : ORIGIN = BL2_DATA_START, LENGTH = BL2_DATA_SIZE
}

ENTRY(Reset_Handler)

SECTIONS
{
    .text :
    {
        __vectors_start = .;
        KEEP(*(.vectors))
        __vectors_end = .;

        *(.text*)
        *(.rodata*)
    } > FLASH

#ifdef CODE_SHARING
    /* The code sharing between bootloader and runtime firmware requires to
     * share the global variables. Section size must be equal with
     * SHARED_SYMBOL_AREA_SIZE defined in region_defs.h
     */
    .tfm_shared_symbols (NOLOAD) : ALIGN(4)
    {
        *(.data.mbedtls_calloc_func)
        *(.data.mbedtls_free_func)
        *(.data.mbedtls_exit)
        *(.data.memset_func)
        . = ALIGN(SHARED_SYMBOL_AREA_SIZE);
    } > RAM AT > FLASH

    ASSERT(SHARED_SYMBOL_AREA_SIZE % 4 == 0, "SHARED_SYMBOL_AREA_SIZE must be divisible by 4")
#endif

#ifdef BOOT_TFM_SHARED_DATA_SIZE
    .tfm_bl2_shared_data (NOLOAD) : ALIGN(32)
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > RAM
    Image$$SHARED_DATA$$RW$$Base = ADDR(.tfm_bl2_shared_data);
    Image$$SHARED_DATA$$RW$$Limit = ADDR(.tfm_bl2_shared_data) + SIZEOF(.tfm_bl2_shared_data);
#endif

    /*
    * Bootoader will clear region [Image$$ER_DATA$$Base - Image$$ARM_LIB_HEAP$$ZI$$Limit]
    * It's important to keep .tfm_bl2_shared_data out of that region
    */
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
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack) - 0x8;
    __stack_seal = Image$$ARM_LIB_STACK$$ZI$$Limit;
#else
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
    __stack = Image$$ARM_LIB_STACK$$ZI$$Limit;

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
