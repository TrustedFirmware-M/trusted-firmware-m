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
    CODE (rx) : ORIGIN = PROVISIONING_BUNDLE_CODE_START, LENGTH = MAIN_BUNDLE_CODE_SIZE
    DATA (rw) : ORIGIN = PROVISIONING_BUNDLE_DATA_START, LENGTH = PROVISIONING_BUNDLE_DATA_SIZE
    VALUES (r) : ORIGIN = PROVISIONING_BUNDLE_VALUES_START, LENGTH = PROVISIONING_BUNDLE_VALUES_SIZE
}

ENTRY(do_provision)

SECTIONS
{
    CODE :
    {
        *_provisioning_code.o(DO_PROVISION)
        *(.rodata*)
        *(.text*)
    } > CODE

    DATA :
    {
        *(.data*)
        *(.bss*)
        *(COMMON)
        /* Non secret provisioning values placed directly after data
         * so ensure 4 byte aligned */
        . = ALIGN(4);
    } > DATA

    Image$$DATA$$Limit = ADDR(DATA) + SIZEOF(DATA);
}
