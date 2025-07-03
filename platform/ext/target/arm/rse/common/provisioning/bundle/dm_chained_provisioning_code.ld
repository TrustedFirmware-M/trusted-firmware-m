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
    CODE (rx) : ORIGIN = PROVISIONING_BUNDLE_CODE_START, LENGTH = PROVISIONING_BUNDLE_CODE_SIZE
    DATA (rw) : ORIGIN = PROVISIONING_BUNDLE_DATA_START, LENGTH = PROVISIONING_BUNDLE_DATA_SIZE
    VALUES (r) : ORIGIN = PROVISIONING_BUNDLE_VALUES_START, LENGTH = PROVISIONING_BUNDLE_VALUES_SIZE
}

ENTRY(do_jump)

SECTIONS
{
    CODE :
    {
        /* In the case of the chained provisioning flow, shift the chainloader blob to the
         * end of the ITCM and place a jump instruction to this at the start
         */
        *_provisioning_code.o(DO_JUMP)
        . = MAIN_BUNDLE_CODE_SIZE;
        *_provisioning_code.o(DO_PROVISION)
        *(.rodata*)
        *(.text*)
    } > CODE

    /* Both these sections cannot be used as they will be
     * overwritten when we chainload the next blob */
    DATA :
    {
        *(.data*)
        *(.bss*)
        *(COMMON)
    } > DATA

    ASSERT(SIZEOF(DATA) == 0, "DATA section must be empty")
}
