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
    CODE (rx) : ORIGIN = PROVISIONING_BUNDLE_CODE_START, LENGTH = PROVISIONING_BUNDLE_CODE_SIZE
    DATA (rw) : ORIGIN = PROVISIONING_BUNDLE_DATA_START, LENGTH = PROVISIONING_BUNDLE_DATA_SIZE
    VALUES (r) : ORIGIN = PROVISIONING_BUNDLE_VALUES_START, LENGTH = PROVISIONING_BUNDLE_VALUES_SIZE
}

ENTRY(do_provision)

SECTIONS
{
    CODE :
    {
        *provisioning_code.o(DO_PROVISION)
        *(.text*)
        *(.time_critical*)
    } > CODE

    RW_DATA :
    {
        *(COMMON .data*)
    } > DATA

    RO_DATA :
    {
        *(EXCLUDE_FILE (*provisioning_data.o) .rodata*)
    } > DATA

    BSS_DATA :
    {
        *(.bss*)
    } > DATA

    VALUES :
    {
        *provisioning_data.o(.rodata.data)
    } > VALUES

}
