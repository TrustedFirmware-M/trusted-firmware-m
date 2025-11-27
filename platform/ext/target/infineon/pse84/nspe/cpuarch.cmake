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

# non-secure image
add_compile_definitions(DOMAIN_NS=1)
add_compile_definitions(COMPONENT_NON_SECURE_DEVICE)

set(NS_BUILD ON)

# This variable points to the root folder of the PSE84 EPC2/EPC4 platform
set(IFX_PLATFORM_SOURCE_DIR ${CONFIG_SPE_PATH}/platform)
# This variable points to the root folder of the PSE84 family
set(IFX_FAMILY_SOURCE_DIR ${CONFIG_SPE_PATH}/platform/pse84)
set(IFX_COMMON_SOURCE_DIR ${CONFIG_SPE_PATH}/platform/ifx)

include(${IFX_FAMILY_SOURCE_DIR}/shared/cpuarch.cmake)

if (IFX_CORE STREQUAL ${IFX_CM33})
    # CM33 core uses TZ agent interface
    set(IFX_NS_INTERFACE_TZ ON)
    add_compile_definitions(IFX_NS_INTERFACE_TZ=1)
elseif (IFX_CORE STREQUAL ${IFX_CM55})
    # CM55 core uses mailbox agent interface
    set(IFX_NS_INTERFACE_MAILBOX ON)
    add_compile_definitions(IFX_NS_INTERFACE_MAILBOX=1)
endif()
