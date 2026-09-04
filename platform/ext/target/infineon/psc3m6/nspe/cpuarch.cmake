#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# cpuarch.cmake is used to set things that related to the platform that are both
# immutable and global, which is to say they should apply to any kind of project
# that uses this platform. In practice this is normally compiler definitions and
# variables related to hardware.

# This variable points to the root folder of the platform
set(IFX_PLATFORM_SOURCE_DIR ${CONFIG_SPE_PATH}/platform)
set(IFX_COMMON_SOURCE_DIR ${CONFIG_SPE_PATH}/platform/ifx)

# NS interface type
set(IFX_NS_INTERFACE_TZ ON)

include(${IFX_COMMON_SOURCE_DIR}/cpuarch.cmake)
