#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(CMSIS_DEVICE_MP2_PATH       "DOWNLOAD"                                                   CACHE PATH   "Path to cmsis-device-mp2 package (or DOWNLOAD to fetch automatically)")
set(CMSIS_DEVICE_MP2_GIT_REMOTE "https://github.com/STMicroelectronics/cmsis-device-mp2.git" CACHE STRING "URL (or path) to retrieve cmsis-device-mp2 package")
set(CMSIS_DEVICE_MP2_VERSION    "v1.3.1"                                                     CACHE STRING "version of cmsis-device-mp2 package")

if (NOT EXISTS ${CMSIS_DEVICE_MP2_PATH})

    fetch_remote_library(
        LIB_NAME                cmsis-device-mp2
        LIB_SOURCE_PATH_VAR     CMSIS_DEVICE_MP2_PATH
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      ${CMSIS_DEVICE_MP2_GIT_REMOTE}
            GIT_TAG             ${CMSIS_DEVICE_MP2_VERSION}
            GIT_PROGRESS        TRUE
    )

    file(INSTALL
        ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt
        DESTINATION ${CMSIS_DEVICE_MP2_PATH}
    )

endif()

# to share the set of cmsis-device-mp2 options settled on secure side build
# but necessary for building the non-secure side too.
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmsis_device_mp2_config.cmake.in
    ${CMAKE_BINARY_DIR}/generated/platform/config/cmsis_device_mp2_config.cmake @ONLY
)

install(FILES
    ${CMAKE_BINARY_DIR}/generated/platform/config/cmsis_device_mp2_config.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config
)

add_subdirectory(${CMSIS_DEVICE_MP2_PATH} cmsis-device-mp2)

