#-------------------------------------------------------------------------------
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if(NOT DEFINED CC312_PATH)
    set(CC312_PATH ../../../../lib/ext/cryptocell-312-runtime CACHE PATH "Path to CC312 lib")
endif()

if(BL2)
    target_compile_definitions(platform_bl2
        PRIVATE
            CRYPTO_HW_ACCELERATOR
    )
endif()

# The config files need to access mbedtls_accelerator_config.h and crypto_accelerator_config.h
target_include_directories(psa_crypto_library_config
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

################################ BL2 ###########################################

if(BL2)

    set(CC312_LIB_PREFIX bl2_)
    # Platform depedency needed to access platform specific dx_reg_base_host.h
    set(CC312_PLATFORM_DEPENDENCY platform_bl2)

    target_sources(bl2_crypto_hw
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/cc312.c
    )

    target_include_directories(bl2_crypto_hw
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    if (${PLATFORM_PSA_ADAC_SECURE_DEBUG})
        add_subdirectory(psa-adac)
    endif()

    target_link_libraries(bl2_crypto_hw
        PUBLIC
            ${CC312_LIB_PREFIX}cc312
        PRIVATE
            bl2_mbedcrypto
            platform_bl2
    )

    set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
    set(CMAKE_BUILD_TYPE ${MBEDCRYPTO_BUILD_TYPE})
    add_subdirectory(${CC312_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${CC312_LIB_PREFIX}cc312)
    set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

    target_sources(${CC312_LIB_PREFIX}cc312
        PUBLIC
            $<$<OR:$<CONFIG:Debug>,$<CONFIG:relwithdebinfo>>:${CMAKE_CURRENT_SOURCE_DIR}/cc312_log.c>
    )

    # Adding two targets as link-time dependencies of each other seems bad, but
    # in reality it just means that they'll share headers and compile defs.
    target_link_libraries(${CC312_LIB_PREFIX}cc312_mbedtls_api
        PRIVATE
            bl2_mbedcrypto
            platform_bl2
        PUBLIC
            platform_common_interface
    )
    target_link_libraries(bl2_mbedcrypto
        PRIVATE
            ${CC312_LIB_PREFIX}cc312_mbedtls_api
        PUBLIC
            bl2_crypto_hw
    )

    # boot_hal depends on crypto_hw_accelerator abstractions
    target_link_libraries(platform_bl2
        PRIVATE
            bl2_crypto_hw
            tfm_config
    )

    target_link_libraries(${CC312_LIB_PREFIX}cc312_cdmpu
        INTERFACE
            bl2_mbedcrypto
    )

    target_compile_definitions(bl2_mbedcrypto
        PUBLIC
            CRYPTO_HW_ACCELERATOR
            MBEDTLS_ECDH_LEGACY_CONTEXT
    )

    target_compile_options(bl2_mbedcrypto
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
            $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
    )

    target_compile_options(${CC312_LIB_PREFIX}cc312
        PRIVATE
            ${BL2_COMPILER_CP_FLAG}
    )

    target_compile_options(bl2_crypto_hw
        PRIVATE
            ${BL2_COMPILER_CP_FLAG}
    )

    target_compile_options(${CC312_LIB_PREFIX}cc312_cdmpu
        INTERFACE
            ${BL2_COMPILER_CP_FLAG}
    )

    unset(CC312_LIB_PREFIX)
    unset(CC312_PLATFORM_DEPENDENCY)

endif()

############################ Crypto Service ####################################

if (TFM_PARTITION_CRYPTO)

    option(CC3XX_RUNTIME_ENABLED
           "EXPERIMENTAL: This variable controls whether the cc3xx driver is being used in runtime FW. \
           Enable it only for testing purposes." OFF)

    # Control the enablement of the legacy CC-312 driver interface or the PSA
    # driver interface. Default value is for the legacy interface
    option(CC312_LEGACY_DRIVER_API_ENABLED
           "This variable controls whether the legacy driver interface is used for CC-312." ON)

    # FixMe: Secure tests enabled and Debug builds with FP support set to hardware
    #        need to fallback to the legacy driver as the new PSA driver overflows
    #        the available flash memory on Musca-S1 and Musca-B1
    if ((NOT ${CC312_LEGACY_DRIVER_API_ENABLED}) AND
        TEST_S AND (${CMAKE_BUILD_TYPE} STREQUAL "Debug") AND (${CONFIG_TFM_FLOAT_ABI} STREQUAL "hard"))
        set(CC312_LEGACY_DRIVER_API_ENABLED ON)
        message(WARNING
            "The CC-312 legacy driver interface fallback is forced to ${CC312_LEGACY_DRIVER_API_ENABLED}. \
            The following parameters are not supported at the same time: \
            (TEST_S: ${TEST_S}, \
            CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}, \
            CONFIG_TFM_FLOAT_ABI: ${CONFIG_TFM_FLOAT_ABI}) for the PSA Cryptoprocessor driver interface due to flash memory constraints.")
    endif()

    # FixMe: Secure tests enabled and Debug builds on Musca-B1 need to fallback to
    #        the legacy driver as the new PSA driver overflows the available flash
    #        memory of the SSE-200 subsystem
    if ((NOT ${CC312_LEGACY_DRIVER_API_ENABLED}) AND
        TEST_S AND (${CMAKE_BUILD_TYPE} STREQUAL "Debug") AND (${TFM_PLATFORM} STREQUAL "arm/musca_b1"))
        set(CC312_LEGACY_DRIVER_API_ENABLED ON)
        message(WARNING
            "The CC-312 legacy driver interface fallback is forced to ${CC312_LEGACY_DRIVER_API_ENABLED}. \
            The following parameters are not supported at the same time: \
            (TEST_S: ${TEST_S}, \
            CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}, \
            TFM_PLATFORM: ${TFM_PLATFORM}) for the PSA Cryptoprocessor driver interface due to flash memory constraints.")
    endif()

    if (${CC3XX_RUNTIME_ENABLED} AND ${CC312_LEGACY_DRIVER_API_ENABLED})
        message(FATAL_ERROR "CC3xx and the Legacy Crypto driver API can't be enabled at the same time.")
    endif()

    if ((NOT ${CC312_LEGACY_DRIVER_API_ENABLED}) AND ${CC3XX_RUNTIME_ENABLED})
        target_sources(crypto_service_crypto_hw
            PRIVATE
                cc312_rom_crypto_hw.c
        )

        target_link_libraries(crypto_service_crypto_hw
            PRIVATE
                crypto_service_mbedcrypto
        )
    endif()

    if (${CC312_LEGACY_DRIVER_API_ENABLED} OR (NOT ${CC3XX_RUNTIME_ENABLED}))
        set(CC312_LIB_PREFIX crypto_service_)

        target_sources(crypto_service_crypto_hw
            PRIVATE
                cc312.c
                $<$<OR:$<CONFIG:Debug>,$<CONFIG:relwithdebinfo>>:${CMAKE_CURRENT_SOURCE_DIR}/cc312_log.c>
        )

        target_include_directories(crypto_service_crypto_hw
            PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}
        )

        target_link_libraries(crypto_service_crypto_hw
            PUBLIC
                ${CC312_LIB_PREFIX}cc312
            PRIVATE
                crypto_service_mbedcrypto
                platform_s
        )

        # Platform depedency needed to access platform specific dx_reg_base_host.h
        set(CC312_PLATFORM_DEPENDENCY platform_s)

        set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
        set(CMAKE_BUILD_TYPE ${MBEDCRYPTO_BUILD_TYPE})
        add_subdirectory(${CC312_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${CC312_LIB_PREFIX}cc312)
        set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

        target_sources(${CC312_LIB_PREFIX}cc312
            PRIVATE
                $<$<OR:$<CONFIG:Debug>,$<CONFIG:relwithdebinfo>>:${CMAKE_CURRENT_SOURCE_DIR}/cc312_log.c>
        )

        target_compile_options(${CC312_LIB_PREFIX}cc312
            PUBLIC
                $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
                $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
        )
    endif()

    if (${CC312_LEGACY_DRIVER_API_ENABLED})
        set(CC312_DRIVER_API_TARGET ${CC312_LIB_PREFIX}cc312_mbedtls_api)
    else()
        if (${CC3XX_RUNTIME_ENABLED})
            set(CC3XX_TARGET_PREFIX crypto_service_)
            set(CC312_DRIVER_API_TARGET ${CC3XX_TARGET_PREFIX}cc3xx_psa_driver_api)
        else()
            set(CC312_DRIVER_API_TARGET ${CC312_LIB_PREFIX}cc312_psa_driver_api)
        endif()
    endif()

    if (NOT ${CC312_LEGACY_DRIVER_API_ENABLED} AND ${CC3XX_RUNTIME_ENABLED})
        set(CC3XX_TARGET_PREFIX crypto_service_)
        set(CC3XX_PLATFORM_INTERFACE platform_s)
        add_subdirectory(${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx ${CMAKE_CURRENT_BINARY_DIR}/${CC3XX_TARGET_PREFIX}cc3xx)
    endif()

    # Adding two targets as link-time dependencies of each other seems bad, but
    # in reality it just means that they'll share headers and compile defs.
    target_link_libraries(${CC312_DRIVER_API_TARGET}
        PRIVATE
            crypto_service_mbedcrypto
        PUBLIC
            platform_s
    )
    target_link_libraries(crypto_service_mbedcrypto
        PUBLIC
            ${CC312_DRIVER_API_TARGET}
            crypto_service_crypto_hw
    )

    target_compile_definitions(crypto_service_mbedcrypto
        PUBLIC
            CRYPTO_HW_ACCELERATOR
            MBEDTLS_ECDH_LEGACY_CONTEXT
            $<$<BOOL:${CC312_LEGACY_DRIVER_API_ENABLED}>:LEGACY_DRIVER_API_ENABLED>
            $<$<BOOL:${CC3XX_RUNTIME_ENABLED}>:CC3XX_RUNTIME_ENABLED>
            $<$<NOT:$<BOOL:${CC312_LEGACY_DRIVER_API_ENABLED}>>:PSA_CRYPTO_DRIVER_CC3XX>
    )

    target_include_directories(psa_crypto_config
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

    target_compile_options(crypto_service_mbedcrypto
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
            $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
    )

    unset(CC312_LIB_PREFIX)
    unset(CC312_PLATFORM_DEPENDENCY)
endif()
