#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
#-------------------------------------------------------------------------------


# initialize pico-sdk from GIT
set(PICO_SDK_FETCH_FROM_GIT on)
set(PICO_PLATFORM rp2350-arm-s)
set(SKIP_BOOT_STAGE2 1)

# initialize the Raspberry Pi Pico SDK
include(${CMAKE_CURRENT_LIST_DIR}/pico_sdk_import.cmake)
pico_sdk_init()

get_target_property(pico_link_options pico_standard_link INTERFACE_LINK_OPTIONS)
list(FILTER pico_link_options EXCLUDE REGEX "LINKER.*--script")
list(APPEND pico_link_options "--entry=_entry_point")
set_target_properties(pico_standard_link PROPERTIES INTERFACE_LINK_OPTIONS "${pico_link_options}")
set_target_properties(pico_runtime PROPERTIES INTERFACE_LINK_OPTIONS "")

target_compile_options(cmsis_core
    INTERFACE
        ${COMPILER_CMSE_FLAG}
)

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(STATIC_ASSERT_OVERRIDE_HEADER "${CMAKE_CURRENT_LIST_DIR}/static_assert_override.h")
add_library(static_assert_override INTERFACE)
target_compile_options(static_assert_override
    INTERFACE
        "$<$<C_COMPILER_ID:Armclang>:SHELL:-include ${STATIC_ASSERT_OVERRIDE_HEADER}>"
        "$<$<C_COMPILER_ID:GNU>:SHELL:-include ${STATIC_ASSERT_OVERRIDE_HEADER}>"
        "$<$<C_COMPILER_ID:IAR>:SHELL:--preinclude ${STATIC_ASSERT_OVERRIDE_HEADER}>"
)

#========================= Platform region defs ===============================#

add_library(platform_s_init INTERFACE)
target_sources(platform_s_init
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/extra_init.c
)

target_link_libraries(platform_s_init
    INTERFACE
        pico_runtime_init
        pico_runtime_headers
        pico_bootrom_headers
)

target_link_options(tfm_s
    PUBLIC
        "--entry=_entry_point"
)

target_include_directories(platform_region_defs
    INTERFACE
        partition
)

target_link_libraries(platform_region_defs
    INTERFACE
        tfm_fih_headers
        hardware_regs_headers
        static_assert_override
)

target_compile_definitions(platform_region_defs
    INTERFACE
        PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
        PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
        PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
        $<$<BOOL:${TFM_LOAD_NS_IMAGE}>:TFM_LOAD_NS_IMAGE>
)

if(NOT PLATFORM_DEFAULT_PROVISIONING)
    add_subdirectory(${PLATFORM_DIR}/ext/common/provisioning_bundle provisioning)

    target_include_directories(provisioning_bundle
        INTERFACE
            ${PLATFORM_DIR}/../interface/include
    )

    if(NOT PLATFORM_DEFAULT_PROV_LINKER_SCRIPT)
        target_add_scatter_file(provisioning_bundle
            linker_provisioning.ld
        )

        target_compile_definitions(provisioning_bundle_scatter
            PRIVATE
                # u modifier in scatter file is not valid
                NO_U_MODIFIER=1
        )
    endif()
endif()

if(TFM_PARTITION_CRYPTO)
    target_include_directories(platform_crypto_keys
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}
    )
endif()

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_common_s.sct>
    linker_s.ld
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_common_s.icf>
)
target_compile_definitions(tfm_s_scatter
    PRIVATE
        # u modifier in scatter file is not valid
        NO_U_MODIFIER=1
)
target_compile_options(tfm_s_scatter
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

if(BL2)
    # Pico startup and runtime init
    target_link_libraries(bl2
        PUBLIC
            pico_runtime
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            linker_bl2.ld
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
    )
    target_compile_definitions(bl2_scatter
        PRIVATE
            # u modifier in scatter file is not valid
            NO_U_MODIFIER=1
    )

    target_compile_options(bl2_scatter
        PUBLIC
            ${COMPILER_CMSE_FLAG}
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        cmsis_drivers
        partition
        device/config
        ${PLATFORM_DIR}/..
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/tpm_client>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/spi>
    INTERFACE
        ${PLATFORM_DIR}/../interface/include
)

target_link_libraries(platform_s
    PUBLIC
        cmsis_core_headers
        hardware_uart_headers
        platform_s_init
    PRIVATE
        pico_crt0
        pico_rand
        pico_multicore
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>>:pico_bootrom>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>>:pico_sha256>
        hardware_regs
        hardware_flash
        hardware_uart
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:hardware_spi>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:hardware_gpio>
        cmsis_core
        tfm_sprt
)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        cmsis_drivers/Driver_Flash_RPI.c
        cmsis_drivers/Driver_USART_RPI.c

        tfm_peripherals_def.c

        rpi_trng.c

        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${CMAKE_CURRENT_SOURCE_DIR}/dtpm_spi.c>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${CMAKE_CURRENT_SOURCE_DIR}/mboot_to_pcr.c>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/tpm_client/tpm2_cmds.c>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/tpm_client/tpm2_chip.c>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/tpm_client/tpm2_fifo.c>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:${PLATFORM_DIR}/ext/driver/tpm_client/tpm2_fifo_spi.c>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>>:${CMAKE_CURRENT_SOURCE_DIR}/attest_hal.c>
        $<$<OR:$<BOOL:${TFM_S_REG_TEST}>,$<BOOL:${TFM_NS_REG_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
        $<$<AND:$<BOOL:${ITS_ENCRYPTION}>,$<BOOL:${TFM_PARTITION_INTERNAL_TRUSTED_STORAGE}>>:${PLATFORM_DIR}/ext/common/template/tfm_hal_its_encryption.c>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${CMAKE_CURRENT_SOURCE_DIR}/rp2350_otp.c>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>>:${CMAKE_CURRENT_SOURCE_DIR}/nv_counters.c>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_multi_core.c>
        $<$<BOOL:${TFM_NS_MAILBOX_API}>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_mailbox.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_compile_definitions(platform_s
    PUBLIC
        CMSIS_device_header=<RP2350.h>
        PICO_UART_DEFAULT_CRLF=1
        $<$<BOOL:${PS_NS_NV_COUNTER_IN_ITS}>:PS_NS_NV_COUNTER_IN_ITS=1>
        $<$<BOOL:${TEST_NS_FPU}>:TEST_NS_FPU>
        $<$<BOOL:${TEST_S_FPU}>:TEST_S_FPU>
        $<$<BOOL:${ITS_ENCRYPTION}>:ITS_ENCRYPTION>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:TFM_MULTI_CORE_TOPOLOGY>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:CS_GPIO=${CS_GPIO}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:MISO_GPIO=${MISO_GPIO}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:MOSI_GPIO=${MOSI_GPIO}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:SCLK_GPIO=${SCLK_GPIO}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:RESET_GPIO=${RESET_GPIO}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:SPI_MODE=${SPI_MODE}>
        $<$<BOOL:${TFM_PARTITION_DTPM_CLIENT}>:SPI_DELAY_US=${SPI_DELAY_US}>
)

# GNU Arm compiler version greater equal than *11.3.Rel1*
# throw warning when linker segments used as rwx
# Adding --no-warn-rwx-segments like the RPi SDK did.
if (CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 11.3.1)
    target_link_options(platform_s INTERFACE "LINKER:--no-warn-rwx-segments")
endif()

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            bl2/boot_hal_bl2.c
            cmsis_drivers/Driver_Flash_RPI_bl2.c
            cmsis_drivers/Driver_USART_RPI.c
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${CMAKE_CURRENT_SOURCE_DIR}/rp2350_otp.c>
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>>:${CMAKE_CURRENT_SOURCE_DIR}/nv_counters.c>
    )

    target_link_libraries(platform_bl2
        PUBLIC
            cmsis_core_headers
            hardware_uart_headers
        PRIVATE
            pico_runtime_headers
            pico_runtime_init
            hardware_regs
            hardware_flash
            hardware_uart
            cmsis_core
    )

    # GNU Arm compiler version greater equal than *11.3.Rel1*
    # throw warning when linker segments used as rwx
    # Adding --no-warn-rwx-segments like the RPi SDK did.
    if (CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 11.3.1)
        target_link_options(platform_bl2 INTERFACE "LINKER:--no-warn-rwx-segments")
    endif()

    target_include_directories(platform_bl2
        PUBLIC
            bl2
            partition
            retarget
            device/config
            device/include
            .
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            PICO_UART_DEFAULT_CRLF=1
            CMSIS_device_header=<RP2350.h>
    )

    target_include_directories(bl2
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}
)

endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        tfm_hal_platform.c
        tfm_hal_isolation_rp2350.c
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${PLATFORM_DIR}/ext/common/tfm_interrupts.c>
)

target_link_libraries(tfm_spm
    PRIVATE
        pico_bootrom_headers
)

#========================= Platform Crypto Keys ===============================#

if (TFM_PARTITION_CRYPTO)
    target_sources(platform_crypto_keys
        PRIVATE
            crypto_keys.c
    )
    target_link_libraries(platform_crypto_keys
        PRIVATE
            platform_s
    )
endif()

#========================= Files for building NS platform =====================#

if (TFM_LOAD_NS_IMAGE)
    install(FILES       ${PLATFORM_DIR}/ext/common/test_interrupt.c
                        ${TARGET_PLATFORM_PATH}/cmsis_drivers/Driver_USART_RPI.c
                        ${TARGET_PLATFORM_PATH}/pico-sdk.patch
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(DIRECTORY   ${TARGET_PLATFORM_PATH}/device
                        ${TARGET_PLATFORM_PATH}/cmsis_drivers
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(DIRECTORY   ${PLATFORM_DIR}/ext/target/arm/drivers
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/target/arm)

    install(FILES       ${TARGET_PLATFORM_PATH}/partition/region_defs.h
                        ${TARGET_PLATFORM_PATH}/partition/flash_layout.h
                        ${TARGET_PLATFORM_PATH}/target_cfg.h
                        ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
                        ${TARGET_PLATFORM_PATH}/platform_multicore.h
                        ${TARGET_PLATFORM_PATH}/tfm_builtin_key_ids.h
                        ${PLATFORM_DIR}/include/tfm_plat_defs.h
                        ${CMAKE_SOURCE_DIR}/lib/fih/inc/fih.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

    install(FILES       ${TARGET_PLATFORM_PATH}/linker_ns.ld
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

    # copy all files from active platform directory
    install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
                        ${TARGET_PLATFORM_PATH}/pico_sdk_import.cmake
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    # Copy the platform specific config
    install(FILES       ${TARGET_PLATFORM_PATH}/config.cmake
                        ${STATIC_ASSERT_OVERRIDE_HEADER}
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    # Install test configs
    install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})
endif()
