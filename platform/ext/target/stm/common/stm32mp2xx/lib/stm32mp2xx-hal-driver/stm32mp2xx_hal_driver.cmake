#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(STM32MP2XX_HAL_DRIVER_PATH       "DOWNLOAD"                                                        CACHE PATH   "Path to stm32mp2xx-hal-driver package (or DOWNLOAD to fetch automatically)")
set(STM32MP2XX_HAL_DRIVER_GIT_REMOTE "https://github.com/STMicroelectronics/stm32mp2xx-hal-driver.git" CACHE STRING "URL (or path) to retrieve stm32mp2xx-hal-driver package")
set(STM32MP2XX_HAL_DRIVER_VERSION    "v1.3.1"                                                          CACHE STRING "version of stm32mp2xx-hal-driver package")

if (NOT EXISTS ${STM32MP2XX_HAL_DRIVER_PATH})
    fetch_remote_library(
        LIB_NAME                stm32mp2xx-hal-driver
        LIB_SOURCE_PATH_VAR     STM32MP2XX_HAL_DRIVER_PATH
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      ${STM32MP2XX_HAL_DRIVER_GIT_REMOTE}
            GIT_TAG             ${STM32MP2XX_HAL_DRIVER_VERSION}
            GIT_PROGRESS        TRUE
    )
endif()

if (NOT EXISTS ${STM32MP2XX_HAL_DRIVER_PATH}/CMakeLists.txt)
    file(INSTALL
        ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt
        DESTINATION ${STM32MP2XX_HAL_DRIVER_PATH}
    )
endif()

# to share the set of stm32mp2xx_hal_driver options settled on secure side build
# but necessary for building the non-secure side too.
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/stm32mp2xx_hal_driver_config.cmake.in
    ${CMAKE_BINARY_DIR}/generated/platform/config/stm32mp2xx_hal_driver_config.cmake @ONLY
)

install(FILES
    ${CMAKE_BINARY_DIR}/generated/platform/config/stm32mp2xx_hal_driver_config.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config
)

add_subdirectory(${STM32MP2XX_HAL_DRIVER_PATH} stm32mp2xx-hal-driver)

