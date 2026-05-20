#-------------------------------------------------------------------------------
# Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Common non-secure image CPU architecture configuration.

# Non-secure image
add_compile_definitions(DOMAIN_NS=1)
add_compile_definitions(COMPONENT_NON_SECURE_DEVICE)

set(NS_BUILD ON)

if (DEFINED IFX_FAMILY_SOURCE_DIR)
    include(${IFX_FAMILY_SOURCE_DIR}/shared/cpuarch.cmake)
else()
    include(${IFX_PLATFORM_SOURCE_DIR}/shared/cpuarch.cmake)
endif()

# NS interface configuration
if (IFX_NS_INTERFACE_TZ)
    add_compile_definitions(IFX_NS_INTERFACE_TZ=1)
elseif (IFX_NS_INTERFACE_MAILBOX)
    add_compile_definitions(IFX_NS_INTERFACE_MAILBOX=1)
else()
    message(FATAL_ERROR "NS interface type is not defined")
endif()
