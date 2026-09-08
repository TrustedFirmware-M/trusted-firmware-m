#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)

include(${STM_FAMILY_DIR}/CMakeLists.txt)

#========================= Tfm config =========================================#
target_compile_definitions(tfm_config
    INTERFACE
        $<$<STREQUAL:${STM32_STM32MP25_SOC_REV},revY>:CONFIG_STM32MP25X_REVY=1>
        $<$<STREQUAL:${STM32_STM32MP25_SOC_REV},revX>:CONFIG_STM32MP25X_REVX=1>
)

#========================= Platform region defs ===============================#
# these flags are includes in bl2, tfm_s and tfm_ns
target_compile_definitions(platform_region_defs
    INTERFACE
        RELOCATE_DATA
)

#========================= Platform Secure ====================================#
target_sources(dt_tfm_s_libs
    PRIVATE
        ${STM_FAMILY_DIR}/native_driver/src/clk/clk-stm32mp25.c
)

target_sources(tfm_s
    PRIVATE
        ${STM_SOC_DIR}/src/startup_stm32mp2_s.c
)

#========================= Platform BL2 =======================================#
if(BL2)

    target_sources(dt_bl2_libs
        PRIVATE
            ${STM_FAMILY_DIR}/native_driver/src/clk/clk-stm32mp25.c
    )

    target_sources(bl2
        PRIVATE
            ${STM_SOC_DIR}/src/startup_stm32mp2_bl2.c
    )
endif()

#========================= Files for building NS side platform ================#
install(FILES
    ${STM_SOC_DIR}/config.cmake
    ${STM_SOC_DIR}/cpuarch.cmake
    ${STM_SOC_DIR}/CMakeLists.txt
    ${STM_SOC_DIR}/config_tfm_soc.h
    ${STM_SOC_DIR}/soc_config.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/stm32mp25
)

install(DIRECTORY
    ${STM_SOC_DIR}/ns
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/stm32mp25
)

install(FILES
    ${STM_SOC_DIR}/src/startup_stm32mp2_ns.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/stm32mp25/src
)

