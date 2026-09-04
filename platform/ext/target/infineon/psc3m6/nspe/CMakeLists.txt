#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(../cmake/remote_library)
include(../cmake/utils.cmake)

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

# Vendor's common build of non-secure image
add_subdirectory(${IFX_COMMON_SOURCE_DIR} ifx)

# Common libraries
add_subdirectory(${IFX_COMMON_SOURCE_DIR}/libs libs)

# Board
add_subdirectory(${IFX_COMMON_SOURCE_DIR}/board board)

############################## Platform Non-Secure #############################

target_include_directories(platform_ns
    PUBLIC
        ${IFX_PLATFORM_SOURCE_DIR}/ext/common
        ${IFX_PLATFORM_SOURCE_DIR}/include
        ${IFX_PLATFORM_SOURCE_DIR}/shared
)

target_link_libraries(platform_ns
    PUBLIC
        ifx_cmsis_lib
)
