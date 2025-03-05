#-------------------------------------------------------------------------------
# Portions Copyright (C) 2024-2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

################################################################################

# Get S - NS peripheral and memory access
include(s_ns_access.cmake)

# Add hal_adi in build system
include(hal_adi.cmake)

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
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            CMSIS_device_header="${TARGET_LC}.h"
    )

    #
    # Process Trusted Edge Security Arhictecture (TESA) extention
    #
    include(tesa-toolkit.cmake)

endif()

###### TF-M Related Cmake Configurations #######################################

target_compile_definitions(tfm_s
    PRIVATE
        IS_SECURE_ENVIRONMENT
        TFM_DATA_INITIALIZE # Enables copying of TF-M specific Data sections from Flash to RAM during startup
)

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_common_s.ld>
)

target_sources(tfm_s
    PRIVATE
        ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/startup_${TARGET_LC}.c
        ${PLATFORM_DIR}/ext/target/adi/${TARGET_LC}/device/src/system_${TARGET_LC}.c
)

if(EXISTS "${CMAKE_BINARY_DIR}/../../adi_soc_peripheral_init.c")
    target_sources(tfm_s
        PRIVATE
            ${CMAKE_BINARY_DIR}/../../adi_soc_peripheral_init.c
    )
endif()

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
        CMSIS_device_header="${TARGET_LC}.h"

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
        ${PLATFORM_DIR}/..
)

if(NOT PLATFORM_DEFAULT_PROVISIONING)
    add_subdirectory(${PLATFORM_DIR}/ext/common/provisioning_bundle provisioning)

    target_compile_definitions(platform_region_defs
        INTERFACE
            PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
            PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
            PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
    )
endif()

if(ITS_ENCRYPTION)

    set(SECURE_FW_PARTITION_CRYPTO_DIR  ${PLATFORM_DIR}/../secure_fw/partitions/crypto)
    set(TFM_MBEDCRYPTO_CONFIG_CLIENT_PATH ${TFM_MBEDCRYPTO_CONFIG_PATH})

    target_compile_definitions(tfm_psa_rot_partition_its
        PRIVATE
            ITS_ENCRYPTION
            MBEDTLS_CONFIG_FILE="${TFM_MBEDCRYPTO_CONFIG_CLIENT_PATH}"
            MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${TFM_MBEDCRYPTO_PSA_CRYPTO_CONFIG_PATH}"
    )

    target_include_directories(tfm_psa_rot_partition_its
        PRIVATE
        $<BUILD_INTERFACE:${PLATFORM_DIR}/../interface/include>
        ${SECURE_FW_PARTITION_CRYPTO_DIR}/psa_driver_api
    )

    target_sources(tfm_psa_rot_partition_its
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_its_encryption_mbed.c
    )

endif()

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

install(FILES       ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include/adi_psa_random.h
                    ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include/crypto_accelerator_config.h
                    ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include/mbedtls_accelerator_config.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/accelerator/include)

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

# Copy the S-NS peripheral & memory configuration
install(FILES       ${TARGET_PLATFORM_PATH}/s_ns_access.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Export configuration flags
target_compile_definitions(tfm_spm
    PUBLIC
        $<$<BOOL:${ADI_NS_PRPH_GCR}>:ADI_NS_PRPH_GCR>
        $<$<BOOL:${ADI_NS_PRPH_SIR}>:ADI_NS_PRPH_SIR>
        $<$<BOOL:${ADI_NS_PRPH_FCR}>:ADI_NS_PRPH_FCR>
        $<$<BOOL:${ADI_NS_PRPH_WDT}>:ADI_NS_PRPH_WDT>
        $<$<BOOL:${ADI_NS_PRPH_AES}>:ADI_NS_PRPH_AES>
        $<$<BOOL:${ADI_NS_PRPH_AESKEY}>:ADI_NS_PRPH_AESKEY>
        $<$<BOOL:${ADI_NS_PRPH_CRC}>:ADI_NS_PRPH_CRC>
        $<$<BOOL:${ADI_NS_PRPH_GPIO0}>:ADI_NS_PRPH_GPIO0>
        $<$<BOOL:${ADI_NS_PRPH_TIMER0}>:ADI_NS_PRPH_TIMER0>
        $<$<BOOL:${ADI_NS_PRPH_TIMER1}>:ADI_NS_PRPH_TIMER1>
        $<$<BOOL:${ADI_NS_PRPH_TIMER2}>:ADI_NS_PRPH_TIMER2>
        $<$<BOOL:${ADI_NS_PRPH_TIMER3}>:ADI_NS_PRPH_TIMER3>
        $<$<BOOL:${ADI_NS_PRPH_TIMER4}>:ADI_NS_PRPH_TIMER4>
        $<$<BOOL:${ADI_NS_PRPH_TIMER5}>:ADI_NS_PRPH_TIMER5>
        $<$<BOOL:${ADI_NS_PRPH_I3C}>:ADI_NS_PRPH_I3C>
        $<$<BOOL:${ADI_NS_PRPH_UART}>:ADI_NS_PRPH_UART>
        $<$<BOOL:${ADI_NS_PRPH_SPI}>:ADI_NS_PRPH_SPI>
        $<$<BOOL:${ADI_NS_PRPH_TRNG}>:ADI_NS_PRPH_TRNG>
        $<$<BOOL:${ADI_NS_PRPH_BTLE_DBB}>:ADI_NS_PRPH_BTLE_DBB>
        $<$<BOOL:${ADI_NS_PRPH_BTLE_RFFE}>:ADI_NS_PRPH_BTLE_RFFE>
        $<$<BOOL:${ADI_NS_PRPH_RSTZ}>:ADI_NS_PRPH_RSTZ>
        $<$<BOOL:${ADI_NS_PRPH_BOOST}>:ADI_NS_PRPH_BOOST>
        $<$<BOOL:${ADI_NS_PRPH_BBSIR}>:ADI_NS_PRPH_BBSIR>
        $<$<BOOL:${ADI_NS_PRPH_BBFCR}>:ADI_NS_PRPH_BBFCR>
        $<$<BOOL:${ADI_NS_PRPH_RTC}>:ADI_NS_PRPH_RTC>
        $<$<BOOL:${ADI_NS_PRPH_WUT0}>:ADI_NS_PRPH_WUT0>
        $<$<BOOL:${ADI_NS_PRPH_WUT1}>:ADI_NS_PRPH_WUT1>
        $<$<BOOL:${ADI_NS_PRPH_PWR}>:ADI_NS_PRPH_PWR>
        $<$<BOOL:${ADI_NS_PRPH_MCR}>:ADI_NS_PRPH_MCR>
)
