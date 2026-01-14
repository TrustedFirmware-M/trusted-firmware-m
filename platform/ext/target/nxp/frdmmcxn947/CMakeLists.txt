#-------------------------------------------------------------------------------
# Copyright 2025-2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

set(NXP_COMMON_DIR ${CMAKE_CURRENT_LIST_DIR}/../common)

# select the NXP Drivers path. Else condition is expected to be used with zephyr
if (TFM_PLATFORM_NXP_HAL_FILE_PATH STREQUAL "LOCAL")
    set(NXP_HAL_FILE_PATH ${PLATFORM_DIR}/ext/target/nxp)
else()
    set(NXP_HAL_FILE_PATH ${TFM_PLATFORM_NXP_HAL_FILE_PATH})
endif()
    
Message("HAL_NXP path to be used: ${NXP_HAL_FILE_PATH}")
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

#========================= Platform region defs ===============================#
target_include_directories(platform_region_defs
    INTERFACE
        partition
)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_frdmmcxn947.c
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_common_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_common_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_common_s.icf>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_frdmmcxn947.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
    )
endif()

#========================= Platform Secure ====================================#

if (USE_TFM_LPUART_FEATURE)
    set(TFM_LPUART_FEATURE_COMPILE_DEFINITION "TFM_LPUART_FEATURE")
endif()

set(HARDENING_COMPILE_DEFINITION "HARDENING_MACROS_ENABLED")
if (DEFINED USE_HARDENED_PLATFORM_INIT)
    if(NOT ${USE_HARDENED_PLATFORM_INIT})
        set(HARDENING_COMPILE_DEFINITION "")
    endif()
endif()

target_compile_definitions(platform_s
    PUBLIC
        ${TFM_LPUART_FEATURE_COMPILE_DEFINITION}
        ${HARDENING_COMPILE_DEFINITION}
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

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
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/periph
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/romapi/flash/
        ${NXP_HAL_FILE_PATH}/common/Native_Driver
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console_lite
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/common
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/lpuart
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/ctimer
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/gpio
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/mcx_spc
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/port

)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
    ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_Flash_iap_n4a.c
    ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_LPUART.c
        ../../arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        project_template/s/board.c
        project_template/s/clock_config.c
        project_template/s/pin_mux.c
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/system_MCXN947_cm33_core0.c
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/romapi/flash/src/fsl_flash.c
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/fsl_clock.c
        ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/fsl_reset.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/common/fsl_common.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/common/fsl_common_arm.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/fsl_lpflexcomm.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/lpuart/fsl_lpuart.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/ctimer/fsl_ctimer.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/gpio/fsl_gpio.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/mcx_spc/fsl_spc.c    
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart/fsl_adapter_lpuart.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/assert/fsl_assert.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console_lite/fsl_debug_console.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str/fsl_str.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/services/src/tfm_platform_system.c>
)

target_link_libraries(platform_s
    PRIVATE
    # For attest HAL strnlen
        tfm_sprt
)

if (MCUX_PSA_CRYPTO_DRIVER_ELS_PKC)
#add_subdirectory(${NXP_HAL_FILE_PATH}/common/Native_Driver/components/els_pkc els_pkc)
add_subdirectory(${MBEDCRYPTO_PATH}/../els_pkc els_pkc)

message(STATUS "RNC RNC RNC ${MBEDCRYPTO_PATH}/../els_pkc")
target_link_libraries(platform_s
    PRIVATE
    # For attest HAL strnlen
        tfm_sprt
        McuxElsPkc
)

message(STATUS "RNC RNC RNC ${MBEDCRYPTO_PATH}/../psa_crypto_driver")
add_subdirectory(${NXP_HAL_FILE_PATH}/common/Native_Driver/components/psa_crypto_driver psa_crypto_driver)
#   add_subdirectory(${MBEDCRYPTO_PATH}/../psa_crypto_driver psa_crypto_driver)
    target_link_libraries(platform_s
        PRIVATE
            McuxPsaCryptoDriverElsPkc
    )
endif()


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

    target_compile_definitions(platform_bl2
        PUBLIC
            ${TFM_LPUART_FEATURE_COMPILE_DEFINITION}
    )

    target_include_directories(platform_bl2
        PUBLIC
            partition
            Device/Include
            project_template/bl2
            project_template/s
            ${PLATFORM_DIR}/ext/target/nxp/common
            ${PLATFORM_DIR}/ext/target/nxp/common/CMSIS_Driver
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Config
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/periph
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/romapi/flash/
            ${NXP_HAL_FILE_PATH}/common/Native_Driver
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console_lite
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/common
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/lpuart
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/ctimer
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/gpio
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/mcx_spc
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/port

        PRIVATE
            .
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Config
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/serial_manager
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/lists
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/str
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/assert
    )
    target_sources(platform_bl2
        PRIVATE
            project_template/s/board.c
            project_template/s/clock_config.c
            project_template/s/pin_mux.c
            ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_Flash_iap_n4a.c
            ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_LPUART.c
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/system_MCXN947_cm33_core0.c
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/romapi/flash/src/fsl_flash.c
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/fsl_clock.c
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver/drivers/fsl_reset.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/fsl_lpflexcomm.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/lpflexcomm/lpuart/fsl_lpuart.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/ctimer/fsl_ctimer.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/gpio/fsl_gpio.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/mcx_spc/fsl_spc.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/components/uart/fsl_adapter_lpuart.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/assert/fsl_assert.c
            ${NXP_HAL_FILE_PATH}/common/Native_Driver/utilities/debug_console_lite/fsl_debug_console.c
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
# default handlers declared in assembly, and will instead be discarded as they
# are not in use.
target_sources(tfm_s
    PRIVATE
        ${NXP_COMMON_DIR}/mpc_ppc_faults.c
)

# Use HW acceleration
if (MCUX_PSA_CRYPTO_DRIVER_ELS_PKC)
if (TFM_PARTITION_CRYPTO)

    target_compile_options(platform_crypto_keys
        PUBLIC
            ${COMPILER_CMSE_FLAG}
    )

    # TODO: add crypto_keys.c with frdmmcxn947 implementation of huk/iak.

    target_link_libraries(platform_crypto_keys
        PRIVATE
            cmsis
    )

    target_include_directories(platform_crypto_keys
        PUBLIC
            ./Device/Include
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Config
            ${PLATFORM_DIR}/ext/target/nxp/common/Device/Include
            ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver
            # platform_crypto_keys does not link against els_pkc and PsaCryptoDriverElsPkc, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be
            # used here:
            "$<TARGET_PROPERTY:McuxElsPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_compile_definitions(platform_crypto_keys
        PUBLIC
            $<$<BOOL:${USE_ELS_PKC_HUK}>:USE_ELS_PKC_HUK>
            $<$<BOOL:${USE_ELS_PKC_IAK}>:USE_ELS_PKC_IAK>
    )

    target_include_directories(platform_crypto_keys
        PUBLIC
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverElsPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    target_include_directories(tfm_psa_rot_partition_crypto
        PUBLIC
            # tfm_psa_rot_partition_crypto does not link against PsaCryptoDriverElsPkc directly, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be used here:
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverElsPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_include_directories(crypto_service_mbedcrypto
        PUBLIC
            # crypto_service_mbedcrypto does not link against PsaCryptoDriverElsPkc directly, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be used here:
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverElsPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    target_compile_definitions(crypto_service_mbedcrypto
        PUBLIC
            $<$<BOOL:${MCUX_PSA_CRYPTO_DRIVER_ELS_PKC}>:PSA_CRYPTO_DRIVER_ELS_PKC>
    )
endif()
endif()

#========================= Files for building NS side platform ================#

install(FILES       ${TARGET_PLATFORM_PATH}/project_template/ns/board.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/hardware_init.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/clock_config.c
                    ${TARGET_PLATFORM_PATH}/project_template/ns/pin_mux.c
                    ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_LPUART.c
                    ${NXP_COMMON_DIR}/CMSIS_Driver/Driver_Flash_iap_n4a.c
                    $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${PLATFORM_DIR}/ext/target/nxp/common/plat_test.c>
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${NXP_COMMON_DIR}/Device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/Device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})


install(DIRECTORY   ${NXP_HAL_FILE_PATH}/common/Native_Driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
install(DIRECTORY   ${NXP_HAL_FILE_PATH}/frdmmcxn947/Native_Driver
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
