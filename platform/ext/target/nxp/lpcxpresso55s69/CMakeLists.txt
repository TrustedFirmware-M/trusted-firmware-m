#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2020, Linaro. All rights reserved.
# Copyright 2021-2024 NXP. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

set(NXP_COMMON_DIR ${CMAKE_CURRENT_LIST_DIR}/../common)

# Pull drivers from NXP git
if (TFM_PLATFORM_NXP_HAL_FILE_PATH STREQUAL "DOWNLOAD")
    set(NXP_HAL_FILE_PATH ${PLATFORM_DIR}/ext/target/nxp)
    Message("-- Pulling MCUxpresso NXP SDK drivers from "${NXP_SDK_GIT_REP}/${NXP_SDK_GIT_TAG})
    include(pull_drivers.cmake)
# Use specified path to NXP hal folder provided by user
else()
    set(NXP_HAL_FILE_PATH ${TFM_PLATFORM_NXP_HAL_FILE_PATH})
endif()

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOWER)
if (BL2 AND ${BUILD_TYPE_LOWER} STREQUAL "debug")
    Message(FATAL_ERROR "If BL2 is enabled, \"${CMAKE_BUILD_TYPE}\" build type cannot be selected as it is currently not \
                         supported on ${TFM_PLATFORM}. For more information please refer to the platform's README file.")
endif()

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_lpcxpresso55s69.c
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_common_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_common_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_common_s.icf>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_lpcxpresso55s69.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        Device/Include
        project_template/s
        partition
        ../../arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/nxp/common
        ${PLATFORM_DIR}/ext/target/nxp/common/CMSIS_Driver
        ${PLATFORM_DIR}/ext/target/nxp/common/Device/Config
        ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers
        ${NXP_HAL_FILE_PATH}/common/Native_Driver
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/lists
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str
)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_Flash_iap1.c
        ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_USART.c
        ../../arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        project_template/s/board.c
        project_template/s/clock_config.c
        project_template/s/pin_mux.c
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/system_LPC55S69_cm33_core0.c
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_clock.c
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_power.c
        ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_reset.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/lists/fsl_component_generic_list.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager/fsl_component_serial_manager.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager/fsl_component_serial_port_uart.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart/fsl_adapter_usart.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_common.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_common_arm.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_ctimer.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_flexcomm.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_gpio.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_iap.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_usart.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/fsl_assert.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console/fsl_debug_console.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str/fsl_str.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/services/src/tfm_platform_system.c>
)

target_link_libraries(platform_s
    PRIVATE
    # For attest HAL strnlen
        tfm_sprt
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

# GNU ld has some strange behaviour to do with weak functions, and does not deal
# well with strong functions in static libraries overriding weak functions in
# object files. For this reason, the file hardware_init is linked directly to
# the s binary as an object file. This issue does not affect armclang, but the
# fix is compatible.
target_sources(tfm_s
    PRIVATE
        project_template/s/hardware_init.c
)

#========================= Platform BL2 =======================================#
if(BL2)

    target_include_directories(platform_bl2
        PUBLIC
            partition
            Device/Include
            project_template/bl2
            ${PLATFORM_DIR}/ext/target/nxp/common
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers
        PRIVATE
            .
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Config
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager
            ${NXP_HAL_FILE_PATH}/common/Native_Driver
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str
    )
    target_sources(platform_bl2
        PRIVATE
            project_template/bl2/board.c
            project_template/bl2/clock_config.c
            project_template/bl2/pin_mux.c
            ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_Flash_iap1.c
            ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_USART.c
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/system_LPC55S69_cm33_core0.c
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_clock.c
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_power.c
            ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver/drivers/fsl_reset.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager/fsl_component_serial_manager.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager/fsl_component_serial_port_uart.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart/fsl_adapter_usart.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_common.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_common_arm.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_flexcomm.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_iap.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/fsl_usart.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/fsl_assert.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console/fsl_debug_console.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str/fsl_str.c
    )

    # GNU ld has some strange behaviour to do with weak functions, and does not deal
    # well with strong functions in static libraries overriding weak functions in
    # object files. For this reason, the file hardware_init is linked directly to
    # the s binary as an object file. This issue does not affect armclang, but the
    # fix is compatible.
    target_sources(bl2
    PRIVATE
        project_template/bl2/hardware_init.c
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        ${NXP_COMMON_DIR}/tfm_hal_isolation.c
        ${NXP_COMMON_DIR}/tfm_hal_platform.c
)

# If this is not added to the tfm_s it will not correctly override the weak
# default handlers declared in assemebly, and will instead be discarded as they
# are not in use.
target_sources(tfm_s
    PRIVATE
        ${NXP_COMMON_DIR}/mpc_ppc_faults.c
)

#========================= Files for building NS side platform ================#

install(FILES       ${TARGET_PLATFORM_PATH}/project_template/ns/board.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/hardware_init.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/clock_config.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/pin_mux.c
                    ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_USART.c
                    $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/plat_test.c>
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${NXP_COMMON_DIR}/Device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/Device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${NXP_HAL_FILE_PATH}/lpcxpresso55s69/Native_Driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${NXP_HAL_FILE_PATH}/common/Native_Driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/project_template/ns/app.h
                    ${TARGET_PLATFORM_PATH}/project_template/ns/board.h
                    ${TARGET_PLATFORM_PATH}/project_template/ns/clock_config.h
                    ${TARGET_PLATFORM_PATH}/project_template/ns/pin_mux.h
                    ${TARGET_PLATFORM_PATH}/config_tfm_target.h
                    ${TARGET_PLATFORM_PATH}/target_cfg.h
                    ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
                    ${NXP_COMMON_DIR}/target_cfg_common.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/partition
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
                    ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
                    ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# copy all files from active platform directory
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
                    ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
