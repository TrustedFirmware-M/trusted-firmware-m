#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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

# The config files need to access crypto accelerator configurations.
target_include_directories(psa_crypto_library_config
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# CC log level is controlled indirectly through the SP log level. When SP log is
# disabled we can assume that the CC log should also be turned off. Otherwise,
# enable only if debugging information may be needed.
if(${TFM_PARTITION_LOG_LEVEL} STREQUAL LOG_LEVEL_NONE)
    set(CC_LOG_ENABLED OFF)
else()
    set(CC_LOG_ENABLED $<CONFIG:Debug,relwithdebinfo>)
endif()

################################ BL2 ###########################################

if (BL2)

    target_compile_definitions(bl2_crypto_config
        INTERFACE
            TF_PSA_CRYPTO_ACCELERATOR_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/tf_psa_crypto_accelerator_config_bl2.h"
    )

    # BL2 only supports CC3XX
    set(CC3XX_PLATFORM_INTERFACE platform_bl2)

    set(CC3XX_TARGET_PREFIX bl2_)
    set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
    set(CMAKE_BUILD_TYPE ${TF_PSA_CRYPTO_BUILD_TYPE})
    add_subdirectory(${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx ${CMAKE_CURRENT_BINARY_DIR}/${CC3XX_TARGET_PREFIX}cc3xx)
    set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

    target_link_libraries(bl2_crypto
        PUBLIC
            ${CC3XX_TARGET_PREFIX}cc3xx_psa_driver_api
    )

    target_include_directories(bl2_crypto_config
        INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    target_link_libraries(${CC3XX_TARGET_PREFIX}cc3xx_psa_driver_api
        PUBLIC
            bl2_crypto_config
    )

    if (${PLATFORM_PSA_ADAC_SECURE_DEBUG})
        target_link_libraries(psa_adac_psa_crypto
            PUBLIC
                bl2_crypto
        )
        target_sources(psa_adac_psa_crypto
            PRIVATE
                crypto_hw.c
        )
    endif()

endif()

############################ Crypto Service ####################################

if (TFM_PARTITION_CRYPTO)

    option(CC3XX_RUNTIME_ENABLED
           "EXPERIMENTAL: This variable controls whether the cc3xx driver is being used in runtime FW. \
           Enable it only for testing purposes." OFF)

    # FixMe: Secure tests enabled and Debug builds with FP support set to hardware
    #        may overflow the available flash memory on Musca-B1 with the new PSA driver.
    if (TEST_S AND (${CMAKE_BUILD_TYPE} STREQUAL "Debug") AND (${CONFIG_TFM_FLOAT_ABI} STREQUAL "hard"))
        message(WARNING
            "The following parameters may not be operational at the same time: \
            (TEST_S: ${TEST_S}, \
            CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}, \
            CONFIG_TFM_FLOAT_ABI: ${CONFIG_TFM_FLOAT_ABI}) \
            for the PSA Cryptoprocessor driver interface due to flash memory constraints.")
    endif()

    if (${CC3XX_RUNTIME_ENABLED})
        # Using the CC3XX driver
        set(CC3XX_TARGET_PREFIX crypto_service_)
        set(CC312_DRIVER_API_TARGET ${CC3XX_TARGET_PREFIX}cc3xx_psa_driver_api)
        set(CC3XX_PLATFORM_INTERFACE platform_s)

        add_subdirectory(${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx ${CMAKE_CURRENT_BINARY_DIR}/${CC3XX_TARGET_PREFIX}cc3xx)

        target_sources(crypto_service_crypto_hw
            PRIVATE
                cc312_rom_crypto_hw.c
        )

        target_link_libraries(crypto_service_crypto_hw
            PRIVATE
                crypto_service_tfpsacrypto
        )
    else()
        # Using the CC312 driver (legacy)
        set(CC312_LIB_PREFIX crypto_service_)
        set(CC312_DRIVER_API_TARGET ${CC312_LIB_PREFIX}cc312_psa_driver_api)

        target_sources(crypto_service_crypto_hw
            PRIVATE
                cc312.c
                $<$<BOOL:${CC_LOG_ENABLED}>:${CMAKE_CURRENT_SOURCE_DIR}/cc312_log.c>
        )

        target_include_directories(crypto_service_crypto_hw
            PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}
        )

        target_link_libraries(crypto_service_crypto_hw
            PUBLIC
                ${CC312_LIB_PREFIX}cc312
            PRIVATE
                crypto_service_tfpsacrypto
                platform_s
        )

        # Platform dependency needed to access platform specific dx_reg_base_host.h
        set(CC312_PLATFORM_DEPENDENCY platform_s)

        set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
        set(CMAKE_BUILD_TYPE ${TF_PSA_CRYPTO_BUILD_TYPE})
        add_subdirectory(${CC312_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${CC312_LIB_PREFIX}cc312)
        set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

        target_sources(${CC312_LIB_PREFIX}cc312
            PRIVATE
                $<$<BOOL:${CC_LOG_ENABLED}>:${CMAKE_CURRENT_SOURCE_DIR}/cc312_log.c>
        )

        target_compile_options(${CC312_LIB_PREFIX}cc312
            PUBLIC
                $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
                $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
        )
    endif()

    # Adding two targets as link-time dependencies of each other seems bad, but
    # in reality it just means that they'll share headers and compile defs.
    target_link_libraries(${CC312_DRIVER_API_TARGET}
        PRIVATE
            crypto_service_tfpsacrypto
        PUBLIC
            platform_s
    )
    target_link_libraries(crypto_service_tfpsacrypto
        PUBLIC
            ${CC312_DRIVER_API_TARGET}
            crypto_service_crypto_hw
    )

    target_compile_definitions(crypto_service_tfpsacrypto
        PUBLIC
            CRYPTO_HW_ACCELERATOR
            MBEDTLS_ECDH_LEGACY_CONTEXT
            $<$<BOOL:${CC3XX_RUNTIME_ENABLED}>:CC3XX_RUNTIME_ENABLED>
            PSA_CRYPTO_DRIVER_CC3XX
    )

    target_include_directories(psa_crypto_config
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

    target_compile_options(crypto_service_tfpsacrypto
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
            $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
    )

    unset(CC312_LIB_PREFIX)
    unset(CC312_PLATFORM_DEPENDENCY)
endif()
