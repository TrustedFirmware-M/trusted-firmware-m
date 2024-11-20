#-------------------------------------------------------------------------------
# Portions Copyright (C) 2024-2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

################################################################################

# Fetch hal_adi repository
fetch_remote_library(
    LIB_NAME                hal_adi
    LIB_SOURCE_PATH_VAR     HAL_ADI_PATH
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/analogdevicesinc/hal_adi
        GIT_TAG             ${HAL_ADI_VERSION}
        GIT_PROGRESS        TRUE
)

set(TARGET_LC "max32657")
string(TOUPPER ${TARGET_LC} TARGET_UC)

set(HAL_ADI_LIBRARY_DIR     ${HAL_ADI_PATH}/MAX/Libraries)

set(HAL_ADI_CMSIS_DIR       ${HAL_ADI_LIBRARY_DIR}/CMSIS/Device/Maxim/${TARGET_UC})
set(HAL_ADI_CMSIS_INC_DIR   ${HAL_ADI_CMSIS_DIR}/Include)
set(HAL_ADI_CMSIS_SRC_DIR   ${HAL_ADI_CMSIS_DIR}/Source)

set(HAL_ADI_PERIPH_DIR      ${HAL_ADI_LIBRARY_DIR}/PeriphDrivers)
set(HAL_ADI_PERIPH_INC_DIR  ${HAL_ADI_PERIPH_DIR}/Include/${TARGET_UC})
set(HAL_ADI_PERIPH_SRC_DIR  ${HAL_ADI_PERIPH_DIR}/Source)

########################## Platform region defs ################################
target_include_directories(platform_region_defs
    INTERFACE
        ./
        partition
)

###### BL2 Related Cmake Configurations ########################################
if(BL2)
    # Add scatter files for BL2
    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/gcc/${TARGET_LC}_sla.ld>
    )

    # Add startup file for BL2
    target_sources(bl2
        PRIVATE
            ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/startup_${TARGET_LC}.c
            ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/system_${TARGET_LC}.c
            ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/sla_header_${TARGET_LC}.c
    )

    # Add includes for BL2
    target_include_directories(platform_bl2
        PUBLIC
            partition
            ${HAL_ADI_PERIPH_INC_DIR}
            ${HAL_ADI_CMSIS_INC_DIR}
        PRIVATE
            .
            ${PLATFORM_DIR}/..
    )

    target_compile_options(platform_bl2
        PUBLIC
            -mno-unaligned-access # Added to mitigate the unaligned access problem
    )

    target_sources(platform_bl2
        PRIVATE
            cmsis_drivers/Driver_Flash.c
            cmsis_drivers/Driver_USART.c
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/otp_max32657.c>

            ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_common.c
            ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_revb.c
            ${HAL_ADI_PERIPH_SRC_DIR}/SYS/sys_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/SYS/mxc_delay.c
            ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_common.c
            ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_reva.c
            ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_reva.c
            ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_common.c
            ${HAL_ADI_PERIPH_SRC_DIR}/SYS/pins_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/ICC/icc_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/ICC/icc_reva.c
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            TARGET=${TARGET_UC}
            TARGET_REV=0x4131
            CMSIS_device_header="${TARGET_LC}.h"
            CONFIG_TRUSTED_EXECUTION_SECURE
            IS_SECURE_ENVIRONMENT

            __MXC_FLASH_MEM_BASE=0x11000000
            __MXC_FLASH_MEM_SIZE=0x00100000
    )

endif()

###### TF-M Related Cmake Configurations #######################################

target_compile_definitions(tfm_s
    PRIVATE
        IS_SECURE_ENVIRONMENT
        TFM_DATA_INITIALIZE # Enables copying of TF-M specific Data sections from Flash to RAM during startup
)

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_s.ld>
)

target_sources(tfm_s
    PRIVATE
        ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/startup_${TARGET_LC}.c
        ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/system_${TARGET_LC}.c
)

target_compile_definitions(tfm_s
    PUBLIC
        TARGET=${TARGET_UC}
        TARGET_REV=0x4131
        CMSIS_device_header="${TARGET_LC}.h"
        CONFIG_TRUSTED_EXECUTION_SECURE
        IS_SECURE_ENVIRONMENT

        __MXC_FLASH_MEM_BASE=0x11000000
        __MXC_FLASH_MEM_SIZE=0x00100000
)

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        tfm_hal_isolation.c
        tfm_hal_platform.c
)

target_compile_definitions(platform_s
    PUBLIC
        TARGET=${TARGET_UC}
        TARGET_REV=0x4131
        CMSIS_device_header="${TARGET_LC}.h"
        CONFIG_TRUSTED_EXECUTION_SECURE
        IS_SECURE_ENVIRONMENT

        __MXC_FLASH_MEM_BASE=0x11000000
        __MXC_FLASH_MEM_SIZE=0x00100000

        $<$<BOOL:${TFM_S_REG_TEST}>:TFM_S_REG_TEST>
        $<$<BOOL:${TFM_NS_REG_TEST}>:TFM_NS_REG_TEST>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
        -mno-unaligned-access # Added to mitigate the unaligned access problem
)

target_sources(platform_s
    PRIVATE
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_USART.c
        cmsis_drivers/Driver_PPC.c
        cmsis_drivers/Driver_MPC.c
        device/src/mpc_sie200_drv.c
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/otp_max32657.c>

        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_common.c
        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_revb.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/sys_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/mxc_delay.c
        ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_common.c
        ${HAL_ADI_PERIPH_SRC_DIR}/FLC/flc_reva.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_reva.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_common.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/pins_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/TZ/spc_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/ICC/icc_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/ICC/icc_reva.c

        $<$<BOOL:TFM_PARTITION_PLATFORM>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
        $<$<BOOL:TFM_PARTITION_PLATFORM>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_hal_ioctl.c>
)

target_include_directories(platform_s
    PUBLIC
        .
        ../common
        partition
        device/inc
        services/include
        ${HAL_ADI_PERIPH_INC_DIR}
        ${HAL_ADI_CMSIS_INC_DIR}
        ${PLATFORM_DIR}/..
)

#========================= Files for building NS platform =====================#

install(FILES       ${TARGET_PLATFORM_PATH}/cmsis_drivers/Driver_USART.c
                    DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/partition/region_defs.h
                    ${TARGET_PLATFORM_PATH}/partition/flash_layout.h
                    ${TARGET_PLATFORM_PATH}/device/inc/mpc_sie200_drv.h
                    ${TARGET_PLATFORM_PATH}/platform_retarget.h
                    ${TARGET_PLATFORM_PATH}/target_cfg.h
                    ${TARGET_PLATFORM_PATH}/device_cfg.h
                    ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
                    ${TARGET_PLATFORM_PATH}/RTE_Device.h
                    ${TARGET_PLATFORM_PATH}/cmsis.h
                    ${PLATFORM_DIR}/ext/common/test_interrupt.h
                    ${PLATFORM_DIR}/ext/driver/Driver_USART.h
                    ${PLATFORM_DIR}/ext/driver/Driver_Common.h
                    ${PLATFORM_DIR}/include/tfm_plat_defs.h
                    ${CMAKE_SOURCE_DIR}/lib/fih/inc/fih.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${HAL_ADI_PERIPH_INC_DIR}
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${HAL_ADI_CMSIS_INC_DIR}
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include/cmsis)

install(FILES       ${TARGET_PLATFORM_PATH}/device/src/startup_${TARGET_LC}.c
                    ${TARGET_PLATFORM_PATH}/device/src/system_${TARGET_LC}.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/device/src)

install(FILES       ${HAL_ADI_CMSIS_INC_DIR}/max32657.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/device/inc)

install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# copy all files from active platform directory
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Copy the platform specific config
install(FILES       ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
