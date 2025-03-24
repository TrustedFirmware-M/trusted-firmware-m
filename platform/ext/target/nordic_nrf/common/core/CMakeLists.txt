#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2020, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/config.cmake)

if (NOT NRF_BOARD_SELECTED)
    if (${TFM_PLATFORM} STREQUAL "nordic_nrf/nrf5340")
        set(hint nordic_nrf/nrf5340dk_nrf5340_cpuapp)
    else()
        set(hint nordic_nrf/nrf9160dk_nrf9160)
    endif()
    message(FATAL_ERROR "Please select one of the nRF boards. "
        "Instead of '${TFM_PLATFORM}', choose e.g. '${hint}'.")
endif()

# At the time of writing there is no systematic way to identify which
# NVM technology is used by the SoC from the Kconfig, so we just
# hardcode this information here instead.
if((NRF_SOC_VARIANT MATCHES "^nrf54l1[05]$") OR (TFM_PLATFORM MATCHES "nordic\_nrf\/nrf54l15dk\_nrf54l1[05]\_cpuapp") OR (PSA_API_TEST_TARGET MATCHES "^nrf54l1[05]$"))
  # Maybe we only need to check one of these options but these
  # variables keep changing so we check both to be future proof
  set(HAS_RRAMC 1)
  set(HAS_CRACEN 1)
else()
  set(HAS_NVMC 1)
  set(HAS_CRACEN 0)
endif()

#========================= Platform dependencies ===============================#

include(hal_nordic.cmake)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_common_s.ld>
)

target_sources(tfm_s
    PRIVATE
        startup.c
)

if(BL2)
    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
    )
endif()

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${NULL_POINTER_EXCEPTION_DETECTION}>:NULL_POINTER_EXCEPTION_DETECTION>
        $<$<BOOL:${NRF_NS_STORAGE}>:NRF_NS_STORAGE>
        $<$<BOOL:${NRF_NS_SECONDARY}>:NRF_NS_SECONDARY>
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        native_drivers
        ${HAL_NORDIC_PATH}/nrfx
        ${HAL_NORDIC_PATH}/nrfx/mdk
        ${HAL_NORDIC_PATH}/nrfx/drivers/include
        common
        ${PLATFORM_DIR}/..
        services/include
)

if(PLATFORM_DEFAULT_OTP OR TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
set(nvm_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_Flash.c
)
endif()

if(HAS_RRAMC)
  list(APPEND nvm_sources
    ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_rramc.c
  )
elseif(HAS_NVMC)
  list(APPEND nvm_sources
    ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_nvmc.c
  )
else()
  message(FATAL_ERROR "Unexpected device")
endif()

target_sources(platform_s
  PRIVATE
       ${nvm_sources}
        nrfx_glue.c
        native_drivers/mpu_armv8m_drv.c
        native_drivers/spu.c
        $<$<BOOL:${TFM_EXCEPTION_INFO_DUMP}>:${CMAKE_CURRENT_SOURCE_DIR}/nrf_exception_info.c>
        $<$<OR:$<BOOL:${TFM_S_REG_TEST}>,$<BOOL:${TFM_NS_REG_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TEST_PSA_API}>:${CMAKE_CURRENT_SOURCE_DIR}/pal_plat_test.c>
        $<$<AND:$<BOOL:${ITS_ENCRYPTION}>,$<NOT:${HAS_CRACEN}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_its_encryption.c>
        $<$<AND:$<BOOL:${ITS_ENCRYPTION}>,$<BOOL:${HAS_CRACEN}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_its_encryption_cracen.c>
)

if (NRF_HW_INIT_RESET_ON_BOOT)
    target_sources(platform_s
        PRIVATE
            hw_init.c
    )

    target_compile_definitions(platform_s
        PUBLIC
            NRF_HW_INIT_RESET_ON_BOOT
            $<$<BOOL:${NRF_HW_INIT_NRF_PERIPHERALS}>:NRF_HW_INIT_NRF_PERIPHERALS>
    )
endif()

if(TFM_PARTITION_PLATFORM)
    target_sources(platform_s
        PRIVATE
            services/src/tfm_platform_hal_ioctl.c
            services/src/tfm_ioctl_core_s_api.c
    )
endif()

if(TFM_SPM_LOG_RAW_ENABLED)
    target_sources(platform_s
        PRIVATE
            cmsis_drivers/Driver_USART.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_uarte.c
    )

    target_compile_definitions(platform_s
        PUBLIC
            NRF_SECURE_UART_INSTANCE=${NRF_SECURE_UART_INSTANCE}
    )
endif()

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_ENABLED>
        $<$<BOOL:${NULL_POINTER_EXCEPTION_DETECTION}>:NULL_POINTER_EXCEPTION_DETECTION>
        $<$<BOOL:${ITS_ENCRYPTION}>:ITS_ENCRYPTION>
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            ${nvm_sources}
            cmsis_drivers/Driver_USART.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_uarte.c
            nrfx_glue.c
            $<$<BOOL:${TFM_SPM_LOG_RAW_ENABLED}>:ext/common/tfm_hal_spm_logdev_peripheral.c>
    )
    target_sources(bl2
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/startup.c>
    )

    target_include_directories(platform_bl2
        PUBLIC
            .
            ${HAL_NORDIC_PATH}/nrfx
            ${HAL_NORDIC_PATH}/nrfx/mdk
            ${HAL_NORDIC_PATH}/nrfx/drivers/include
            common
        PRIVATE
            ${PLATFORM_DIR}/..
    )

    target_compile_definitions(platform_bl2
         PUBLIC
         TFM_SPM_LOG_LEVEL=${TFM_SPM_LOG_LEVEL} # Required by nvm_sources
    )

endif()

if (TFM_PARTITION_PLATFORM)
install(FILES       services/include/tfm_ioctl_core_api.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       services/src/tfm_ioctl_core_ns_api.c
        DESTINATION ${INSTALL_INTERFACE_SRC_DIR})

endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        tfm_hal_isolation.c
        tfm_hal_platform_common.c
        faults.c
        target_cfg.c
)

target_sources(tfm_s
    PRIVATE
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/startup_${target}.c>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/startup_${target}.c>
    )
endif()

if(NRF_APPROTECT)
    target_compile_definitions(tfm_spm
    PRIVATE
        NRF_APPROTECT
    )
endif()

if(NRF_SECURE_APPROTECT)
    target_compile_definitions(tfm_spm
    PRIVATE
        NRF_SECURE_APPROTECT
    )
endif()

#========================= Files for building NS side platform ================#

configure_file(config_nordic_nrf_spe.cmake.in
               ${PROJECT_BINARY_DIR}/config_nordic_nrf_spe.cmake)

install(FILES       ${PROJECT_BINARY_DIR}/config_nordic_nrf_spe.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/core
)

install(FILES       startup.c
                    startup_${target}.c
                    nrfx_glue.c
                    pal_plat_test.c
                    pal_plat_test.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/core
)

install(FILES       startup.h
                    target_cfg.h
                    nrfx_config.h
                    ns/CMakeLists.txt
                    config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/core
)

install(DIRECTORY   native_drivers
                    cmsis_drivers
                    common
                    nrfx
                    services
                    tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/core
)

install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)
