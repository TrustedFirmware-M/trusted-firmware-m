#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)

include(${STM_SOC_DIR}/CMakeLists.txt)

#========================= Platform defs ======================================#
target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${STM32_CACHE_ENABLED}>:STM32_CACHE_ENABLED>
)

#========================= Files for building NS side platform ================#
install(FILES
    ${TARGET_PLATFORM_PATH}/config.cmake
    ${TARGET_PLATFORM_PATH}/cpuarch.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY
    ${TARGET_PLATFORM_PATH}/include
    ${TARGET_PLATFORM_PATH}/ns/
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)
