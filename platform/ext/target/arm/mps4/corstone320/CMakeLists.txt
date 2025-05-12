#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

include(${MPS4_COMMON_DIR}/common.cmake)

#========================= Device definition lib ===============================#

target_include_directories(device_definition
    INTERFACE
        device/include
        native_drivers
        ${CMAKE_SOURCE_DIR}
)

#========================= Platform common defs ===============================#

target_sources(tfm_s
    PRIVATE
        device/source/startup_mps4_corstone320.c
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        cmsis_drivers/config/secure
        cmsis_drivers
        device
)

target_sources(platform_s
    PRIVATE
        cmsis_drivers/Driver_PPC.c
        cmsis_drivers/Driver_MPC.c
        device/source/system_core_init.c
        device/source/platform_s_device_definition.c
        native_drivers/ppc_corstone320_drv.c
        ${ETHOS_DRIVER_PATH}/src/ethosu_device_u85.c
)

target_compile_definitions(platform_s
    PRIVATE
        # Needed for DMA-350 library
        CMSIS_device_header=<corstone320.h>
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(bl2
        PRIVATE
            device/source/startup_mps4_corstone320.c
    )

    target_sources(platform_bl2
            PRIVATE
                device/source/system_core_init.c
                device/source/platform_s_device_definition.c
        )

    target_include_directories(platform_bl2
        PUBLIC
            device/include
        PRIVATE
            .
            device
            services/src
            ${CMAKE_CURRENT_SOURCE_DIR}/device/config
            cmsis_drivers/config/secure
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
)

#========================= platform_region_defs ===============================#
target_include_directories(platform_region_defs
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        partition
)

#========================= Flash driver library ===============================#
target_include_directories(flash_drivers
    INTERFACE
        cmsis_drivers/config/secure
        partition
)

target_sources(flash_drivers
    INTERFACE
        cmsis_drivers/Driver_Flash.c
)

#========================= Platform BL1_1 =======================================#

# If this is not added to the bl1_1 it will not correctly override the weak
# functions and will instead be discarded as they are not in use.
target_sources(bl1_1
    PUBLIC
        device/source/startup_mps4_corstone320.c
)

target_sources(platform_bl1_1
    PRIVATE
        device/source/system_core_init.c
        device/source/platform_s_device_definition.c
)

target_include_directories(platform_bl1_1
    PRIVATE
        cmsis_drivers/config/secure
)

#========================= Platform BL1_2 =====================================#

# If this is not added to the bl1_2 it will not correctly override the weak
# functions and will instead be discarded as they are not in use.
target_sources(bl1_2
    PRIVATE
        device/source/startup_mps4_corstone320.c
)

target_include_directories(platform_bl1_2
    PRIVATE
        cmsis_drivers/config/secure
)

#========================= Files for building NS side platform ================#
install(DIRECTORY   device
                    native_drivers
                    cmsis_drivers
                    partition
                    ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(FILES       ns/cpuarch_ns.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
        RENAME      cpuarch.cmake)
