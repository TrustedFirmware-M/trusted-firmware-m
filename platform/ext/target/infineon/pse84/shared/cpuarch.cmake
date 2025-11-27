#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# cpuarch.cmake is used to set things that related to the platform that are both
# immutable and global, which is to say they should apply to any kind of project
# that uses this platform. In practice this is normally compiler definitions and
# variables related to hardware.

# Use to set/check IFX_CORE
set(IFX_CM33 "cm33")
set(IFX_CM55 "cm55")

# IFX_CORE allows to check active core
add_compile_definitions(IFX_CM33=33)
add_compile_definitions(IFX_CM55=55)

# TFM is built without BL2 but external build of bootloader is present on
# device, this bootloader will populate shared data, so BOOT_DATA_AVAILABLE
# needs to be defined.
add_compile_definitions(BOOT_DATA_AVAILABLE)

# FPU for CM33 and CM55 cores
set(CONFIG_TFM_FP_ARCH "fpv5-d16")
set(CONFIG_TFM_FP_ARCH_ASM "FPv5_D16")

# Set architecture and CPU
if (NOT DEFINED IFX_CORE)
    # Incorrect core value
    message(FATAL_ERROR "IFX_CORE is not defined, supported values : cm33, cm55")
elseif (IFX_CORE STREQUAL ${IFX_CM33})
    # CM33 core for SPE/NSPE
    set(TFM_SYSTEM_PROCESSOR cortex-m33)
    set(TFM_SYSTEM_ARCHITECTURE armv8-m.main)
    # PSE84 CM33 core supports hardware DSP, but TF-M currently doesn't support it
    set(TFM_SYSTEM_DSP OFF)

    # IFX_CORE allows to check active core
    add_compile_definitions(IFX_CORE=33)
elseif (IFX_CORE STREQUAL ${IFX_CM55})
    # CM55 core for NSPE
    set(TFM_SYSTEM_PROCESSOR cortex-m55)
    set(TFM_SYSTEM_ARCHITECTURE armv8.1-m.main)
    # CM55 always has DSP. See TRM for more details.
    set(TFM_SYSTEM_DSP ON)

    # IFX_CORE allows to check active core
    add_compile_definitions(IFX_CORE=55)
else()
    # No core value
    message(FATAL_ERROR "Please specify IFX_CORE : cm33 or cm55")
endif()

#set(CRYPTO_HW_ACCELERATOR_TYPE vendor_target)
