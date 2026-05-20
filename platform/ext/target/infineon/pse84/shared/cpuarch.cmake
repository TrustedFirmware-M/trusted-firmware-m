#-------------------------------------------------------------------------------
# Copyright (c) 2023-2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# cpuarch.cmake is used to set things that related to the platform that are both
# immutable and global, which is to say they should apply to any kind of project
# that uses this platform. In practice this is normally compiler definitions and
# variables related to hardware.

include(${IFX_COMMON_SOURCE_DIR}/shared/core_defs.cmake)

# Validate IFX_CORE
if (NOT DEFINED IFX_CORE)
    message(FATAL_ERROR "IFX_CORE is not defined")
elseif (NOT (IFX_CORE STREQUAL ${IFX_CM33} OR IFX_CORE STREQUAL ${IFX_CM55}))
    message(FATAL_ERROR "Unsupported IFX_CORE value: ${IFX_CORE}")
endif()

include(${IFX_COMMON_SOURCE_DIR}/shared/cpuarch.cmake)
