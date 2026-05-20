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

# This variable points to the root folder of the PSE84 EPC2/EPC4 platform
set(IFX_PLATFORM_SOURCE_DIR ${CONFIG_SPE_PATH}/platform)
# This variable points to the root folder of the PSE84 family
set(IFX_FAMILY_SOURCE_DIR ${CONFIG_SPE_PATH}/platform/family)
set(IFX_COMMON_SOURCE_DIR ${CONFIG_SPE_PATH}/platform/ifx)

include(${IFX_COMMON_SOURCE_DIR}/shared/core_defs.cmake)

# NS interface type: CM33 uses TrustZone, CM55 uses Mailbox
if (IFX_CORE STREQUAL ${IFX_CM33})
    set(IFX_NS_INTERFACE_TZ ON)
elseif (IFX_CORE STREQUAL ${IFX_CM55})
    set(IFX_NS_INTERFACE_MAILBOX ON)
endif()

include(${IFX_COMMON_SOURCE_DIR}/cpuarch.cmake)
