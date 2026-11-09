#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (TFM_PLATFORM_NXP_HAL_FILE_PATH STREQUAL "LOCAL")
    set(NXP_HAL_FILE_PATH ${PLATFORM_DIR}/ext/target/nxp)
else()
    set(NXP_HAL_FILE_PATH ${TFM_PLATFORM_NXP_HAL_FILE_PATH})
endif()

# select the NXP HE accelerator source path. currently hardcoded for zephyr use
#if (TFM_PLATFORM_NXP_HW_ACCEL_SOURCE_PATH STREQUAL "LOCAL")
#    set(NXP_HAL_FILE_PATH ${PLATFORM_DIR}/ext/target/nxp)
#else()
    set(NXP_HW_ACCEL_SGI_PKC_PATH ${TF_PSA_CRYPTO_PATH}/../)
#endif()

############################ Crypto Service ####################################
if(TFM_PARTITION_CRYPTO)

    # include sgi_pkc and psa_crypto_driver libraries. 
    add_subdirectory(${NXP_HW_ACCEL_SGI_PKC_PATH}sgi_pkc/cmake sgi_pkc)
    add_subdirectory(${NXP_HW_ACCEL_SGI_PKC_PATH}psa_crypto_driver psa_crypto_driver)
        
    target_sources(crypto_service_crypto_hw
        PRIVATE
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/dummy.c
    )

    # expose psa_crypto_driver_sgi_pkc headers
    target_include_directories(crypto_service_crypto_hw
        PUBLIC
            # crypto_service_tfpsacrypto does not link against PsaCryptoDriverSgiPkc directly, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be used here:
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    
    target_include_directories(crypto_service_tfpsacrypto
        PUBLIC
            # crypto_service_tfpsacrypto does not link against PsaCryptoDriverSgiPkc directly, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be used here:
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_include_directories(tfm_psa_rot_partition_crypto
        PUBLIC
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_sources(platform_crypto_keys
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/../../common/crypto_key/sgi_based/crypto_keys.c"
    )

    target_compile_options(platform_crypto_keys
        PRIVATE
            ${COMPILER_CMSE_FLAG}
    )

    target_compile_definitions(platform_crypto_keys
        PRIVATE
            $<$<BOOL:${USE_SGI_HUK}>:USE_SGI_HUK>
            PSA_CRYPTO_DRIVER_SGI
            PSA_CRYPTO_DRIVER_PKC
    )

    target_include_directories(platform_crypto_keys
        PUBLIC
            "${CMAKE_CURRENT_LIST_DIR}/../Device/Include"
            "${PLATFORM_DIR}/../interface/include/crypto_keys"
            "${PLATFORM_DIR}/../secure_fw/partitions/crypto/psa_driver_api"
            "${PLATFORM_DIR}/ext/target/nxp/common/Device/Config"
            "${PLATFORM_DIR}/ext/target/nxp/common/Device/Include"
            "${NXP_HAL_FILE_PATH}/frdmmcxl577/Native_Driver"
            "$<TARGET_PROPERTY:McuxSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_link_libraries(platform_crypto_keys
        PRIVATE
            cmsis
            McuxSgiPkc
    )

    target_include_directories(tfm_psa_rot_partition_crypto
        PUBLIC
            # tfm_psa_rot_partition_crypto does not link against PsaCryptoDriverSgiPkc directly, but we need to include it's
            # header files to have the function declarations, typedefs and defines available.
            # Those directories are declared in the included library cmake file and can be used here:
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    
    target_include_directories(psa_crypto_config
        INTERFACE
            $<BUILD_INTERFACE:${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/>
    )

    target_link_libraries(crypto_service_crypto_hw
        PRIVATE
            crypto_service_tfpsacrypto
            cmsis
            McuxSgiPkc
            McuxPsaCryptoDriverSgiPkc
    )

    get_target_property(CMSIS_INCLUDES cmsis INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(TFM_CONFIG_INCLUDES tfm_config INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(PLAT_COMMON_INCLUDES platform_common_interface INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(TFM_NXP_PLATFORM_INCLUDES platform_s INTERFACE_INCLUDE_DIRECTORIES)

    # TF-M config files need access to crypto accelerator configuration
    target_include_directories(psa_crypto_library_config
        INTERFACE
            "${PLATFORM_DIR}/ext/target/nxp/common"
            "${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}"
    )

    # Provide SGI-PKC headers to crypto_service_builtin so the PSA_CRYPTO_DRIVER_SGI_PKC
    # define (set in platform/ext/accelerator/nxp/CMakeLists.txt) can be resolved and
    # psa_hash_operation_t union size matches crypto_service_tfpsacrypto.
    target_include_directories(crypto_service_builtin
        PUBLIC
            "$<TARGET_PROPERTY:McuxPsaCryptoDriverSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>"
    )

    target_include_directories(McuxSgiPkc
        PUBLIC
            ${CMSIS_INCLUDES}
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/Native_Driver
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/Native_Driver/periph4
            ${TFM_NXP_PLATFORM_INCLUDES}
    )

    target_include_directories(McuxPsaCryptoDriverSgiPkc
        PUBLIC
            #${CMAKE_SOURCE_DIR}/platform/include
            ${TFM_CONFIG_INCLUDES}
            ${PLAT_COMMON_INCLUDES}
    )

    target_sources(McuxSgiPkc
        PUBLIC
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/trng/fsl_trng.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/glikey/fsl_glikey.c
        ${NXP_HAL_FILE_PATH}/common/Native_Driver/drivers/crc/fsl_crc.c
    )

    target_link_libraries(McuxPsaCryptoDriverSgiPkc PUBLIC McuxSgiPkc)

    target_link_libraries(platform_s
        PUBLIC
            platform_crypto_keys
    )

    target_link_libraries(platform_s
        PRIVATE
            crypto_service_crypto_hw
    )

    target_link_libraries(crypto_service_crypto_hw
         INTERFACE
            tfm_config
    )
endif()
