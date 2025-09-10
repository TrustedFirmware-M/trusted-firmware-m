#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

install(DIRECTORY ${CMAKE_BINARY_DIR}/bin/
        DESTINATION bin
)

# export veneer lib
if (CONFIG_TFM_USE_TRUSTZONE)
    install(FILES       ${CMAKE_BINARY_DIR}/secure_fw/s_veneers.o
            DESTINATION ${INSTALL_INTERFACE_LIB_DIR})
endif()

####################### export headers #########################################

if (BL1 AND PLATFORM_DEFAULT_BL1)
    install(DIRECTORY   ${BL1_1_CONFIG_DIR}/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/bl1_1_config)

    install(DIRECTORY   ${BL1_2_CONFIG_DIR}/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/bl1_2_config)
endif()

install(FILES       ${INTERFACE_INC_DIR}/psa/api_broker.h
                    ${INTERFACE_INC_DIR}/psa/client.h
                    ${INTERFACE_INC_DIR}/hybrid_platform/api_broker_defs.h
                    ${INTERFACE_INC_DIR}/psa/error.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)

install(FILES       ${CMAKE_BINARY_DIR}/generated/interface/include/psa_manifest/sid.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa_manifest)

install(FILES       ${CMAKE_BINARY_DIR}/generated/interface/include/config_impl.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       ${INTERFACE_INC_DIR}/tfm_veneers.h
                    ${INTERFACE_INC_DIR}/tfm_ns_interface.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       ${INTERFACE_INC_DIR}/tfm_ns_client_ext.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       ${CMAKE_SOURCE_DIR}/secure_fw/include/config_tfm.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})
install(FILES       ${CMAKE_SOURCE_DIR}/config/config_base.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})
install(FILES       ${CMAKE_SOURCE_DIR}/secure_fw/spm/include/tfm_hybrid_platform.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       ${INTERFACE_INC_DIR}/tfm_psa_call_pack.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})
install(FILES       ${CMAKE_BINARY_DIR}/generated/interface/include/psa/framework_feature.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    install(FILES       ${INTERFACE_INC_DIR}/multi_core/tfm_multi_core_api.h
                        ${INTERFACE_INC_DIR}/multi_core/tfm_ns_mailbox.h
                        ${INTERFACE_INC_DIR}/multi_core/tfm_mailbox.h
                        ${INTERFACE_INC_DIR}/multi_core/tfm_ns_mailbox_test.h
                        ${CMAKE_BINARY_DIR}/generated/interface/include/tfm_mailbox_config.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/multi_core)
endif()

if (TFM_PARTITION_PROTECTED_STORAGE)
    install(FILES       ${INTERFACE_INC_DIR}/psa/protected_storage.h
                        ${INTERFACE_INC_DIR}/psa/storage_common.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_ps_defs.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if (TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
    install(FILES       ${INTERFACE_INC_DIR}/psa/internal_trusted_storage.h
                        ${INTERFACE_INC_DIR}/psa/storage_common.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_its_defs.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if (TFM_PARTITION_CRYPTO)
    install(FILES       ${INTERFACE_INC_DIR}/psa/README.rst
                        ${INTERFACE_INC_DIR}/psa/build_info.h
                        ${INTERFACE_INC_DIR}/psa/crypto.h
                        ${INTERFACE_INC_DIR}/psa/crypto_adjust_auto_enabled.h
                        ${INTERFACE_INC_DIR}/psa/crypto_adjust_config_dependencies.h
                        ${INTERFACE_INC_DIR}/psa/crypto_adjust_config_key_pair_types.h
                        ${INTERFACE_INC_DIR}/psa/crypto_adjust_config_synonyms.h
                        ${INTERFACE_INC_DIR}/psa/crypto_builtin_composites.h
                        ${INTERFACE_INC_DIR}/psa/crypto_builtin_key_derivation.h
                        ${INTERFACE_INC_DIR}/psa/crypto_builtin_primitives.h
                        ${INTERFACE_INC_DIR}/psa/crypto_compat.h
                        ${INTERFACE_INC_DIR}/psa/crypto_driver_common.h
                        ${INTERFACE_INC_DIR}/psa/crypto_driver_contexts_composites.h
                        ${INTERFACE_INC_DIR}/psa/crypto_driver_contexts_key_derivation.h
                        ${INTERFACE_INC_DIR}/psa/crypto_driver_contexts_primitives.h
                        ${INTERFACE_INC_DIR}/psa/crypto_extra.h
                        ${INTERFACE_INC_DIR}/psa/crypto_legacy.h
                        ${INTERFACE_INC_DIR}/psa/crypto_platform.h
                        ${INTERFACE_INC_DIR}/psa/crypto_se_driver.h
                        ${INTERFACE_INC_DIR}/psa/crypto_sizes.h
                        ${INTERFACE_INC_DIR}/psa/crypto_struct.h
                        ${INTERFACE_INC_DIR}/psa/crypto_types.h
                        ${INTERFACE_INC_DIR}/psa/crypto_values.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_crypto_defs.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    install(DIRECTORY   ${INTERFACE_INC_DIR}/mbedtls
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if (TFM_PARTITION_INITIAL_ATTESTATION)
    install(FILES       ${CMAKE_BINARY_DIR}/generated/interface/include/psa/initial_attestation.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_attest_defs.h
                        ${INTERFACE_INC_DIR}/tfm_attest_iat_defs.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if(TFM_PARTITION_PLATFORM)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_platform_api.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if(TFM_PARTITION_FIRMWARE_UPDATE)
    install(FILES       ${INTERFACE_INC_DIR}/psa/update.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    install(FILES       ${INTERFACE_INC_DIR}/tfm_fwu_defs.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    if(FWU_DEVICE_CONFIG_FILE)
        install(FILES       ${FWU_DEVICE_CONFIG_FILE}
                RENAME      fwu_config.h
                DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    else()
        install(FILES       ${CMAKE_BINARY_DIR}/generated/interface/include/psa/fwu_config.h
                DESTINATION ${INSTALL_INTERFACE_INC_DIR}/psa)
    endif()
    if(FWU_DEVICE_IMPL_INFO_DEF_FILE)
        install(FILES       ${FWU_DEVICE_IMPL_INFO_DEF_FILE}
                RENAME      tfm_fwu_impl_info.h
                DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    else()
        install(FILES       ${INTERFACE_INC_DIR}/tfm_fwu_impl_info.h
                DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    endif()
endif()

if(PLATFORM_DEFAULT_CRYPTO_KEYS)
    install(DIRECTORY   ${INTERFACE_INC_DIR}/crypto_keys
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

####################### export sources #########################################

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    install(FILES       ${INTERFACE_SRC_DIR}/multi_core/tfm_ns_mailbox.c
                        ${INTERFACE_SRC_DIR}/multi_core/tfm_multi_core_ns_api.c
                        ${INTERFACE_SRC_DIR}/multi_core/tfm_multi_core_psa_ns_api.c
                        ${INTERFACE_SRC_DIR}/multi_core/tfm_ns_mailbox_thread.c
                        ${INTERFACE_SRC_DIR}/multi_core/tfm_ns_mailbox_common.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR}/multi_core)
endif()

if (TFM_PARTITION_NS_AGENT_TZ)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_tz_psa_ns_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

install(DIRECTORY   ${INTERFACE_INC_DIR}/os_wrapper
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

if (CONFIG_TFM_USE_TRUSTZONE)
    install(DIRECTORY   ${INTERFACE_SRC_DIR}/os_wrapper
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if (TFM_HYBRID_PLATFORM_API_BROKER)
    install(DIRECTORY   ${INTERFACE_SRC_DIR}/hybrid_platform
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if (TFM_PARTITION_PROTECTED_STORAGE)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_ps_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if (TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_its_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if (TFM_PARTITION_CRYPTO)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_crypto_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if (TFM_PARTITION_INITIAL_ATTESTATION)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_attest_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

if(TFM_PARTITION_PLATFORM)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_platform_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

##################### Export image signing information #########################

if(BL2 AND PLATFORM_DEFAULT_IMAGE_SIGNING)
    install(DIRECTORY bl2/ext/mcuboot/scripts
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}
            PATTERN "scripts/*.py"
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
            GROUP_EXECUTE GROUP_READ
            PATTERN "scripts/*.py"
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                        GROUP_EXECUTE GROUP_READ)

    install(DIRECTORY ${MCUBOOT_PATH}/scripts/imgtool
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/scripts)

    if (MCUBOOT_ENC_IMAGES)
        install(FILES ${MCUBOOT_KEY_ENC}
                RENAME image_enc_key.pem
                DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)
    endif()

    install(FILES $<TARGET_OBJECTS:signing_layout_s>
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/layout_files)
    install(FILES ${MCUBOOT_KEY_S}
            RENAME image_s_signing_private_key.pem
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)
    # Specify the MCUBOOT_KEY_S path for NS build
    set(MCUBOOT_INSTALL_KEY_S
        ${INSTALL_IMAGE_SIGNING_DIR}/keys/image_s_signing_private_key.pem)
    install(FILES $<TARGET_FILE_DIR:bl2>/image_s_signing_public_key.pem
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)

    if(MCUBOOT_IMAGE_NUMBER GREATER 1)
        install(FILES $<TARGET_OBJECTS:signing_layout_ns>
                DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/layout_files)
        install(FILES ${MCUBOOT_KEY_NS}
                RENAME image_ns_signing_private_key.pem
                DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)
        # Specify the MCUBOOT_KEY_NS path for NS build
        set(MCUBOOT_INSTALL_KEY_NS
            ${INSTALL_IMAGE_SIGNING_DIR}/keys/image_ns_signing_private_key.pem)
        install(FILES $<TARGET_FILE_DIR:bl2>/image_ns_signing_public_key.pem
                DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)
    endif()
endif()

if(TFM_PARTITION_FIRMWARE_UPDATE)
    install(FILES       ${INTERFACE_SRC_DIR}/tfm_fwu_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

######################### Export common configurations #########################

install(FILES       ${CMAKE_SOURCE_DIR}/config/cp_check.cmake
        DESTINATION ${INSTALL_CONFIG_DIR})

################### Read recommended tf-m-tests version ########################

include(${CMAKE_SOURCE_DIR}/lib/ext/tf-m-tests/read_version.cmake)

###################### Install NS platform sources #############################

install(CODE "MESSAGE(\"----- Installing platform NS -----\")")

install(DIRECTORY   $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Core/Include>
                    $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Driver/Include>
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/cmsis)

if(PLATFORM_DEFAULT_UART_STDOUT)
    install(FILES       ${PLATFORM_DIR}/ext/common/uart_stdout.c
                        ${PLATFORM_DIR}/ext/common/uart_stdout.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/common)
endif()

install(DIRECTORY   ${PLATFORM_DIR}/include
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES ${CMAKE_SOURCE_DIR}/cmake/spe-CMakeLists.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        RENAME CMakeLists.txt)

install(FILES       ${PLATFORM_DIR}/ns/toolchain_ns_GNUARM.cmake
                    ${PLATFORM_DIR}/ns/toolchain_ns_ARMCLANG.cmake
                    ${PLATFORM_DIR}/ns/toolchain_ns_IARARM.cmake
                    ${PLATFORM_DIR}/ns/toolchain_ns_CLANG.cmake
        DESTINATION ${INSTALL_CMAKE_DIR})

install(FILES
        ${CMAKE_SOURCE_DIR}/lib/fih/inc/fih.h
        ${PLATFORM_DIR}/include/tfm_plat_ns.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

if (TARGET psa_crypto_config)
# FIXIT: This is a temporal patch to reduce the change scope and simplify review.
# In the future we shall decouple this target from tfm_config becuase
# "psa_crypto_config" target exists not in all configurations.
# Functionally "psa_crypto_config" provides only include path for Crypto accelerator.
install(TARGETS tfm_config psa_crypto_config psa_interface
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        EXPORT tfm-config
        )
else()
        install(TARGETS tfm_config psa_interface
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        EXPORT tfm-config
        )
endif()

target_include_directories(psa_interface
        INTERFACE
        $<INSTALL_INTERFACE:interface/include>
        )

install(EXPORT tfm-config
        FILE spe_export.cmake
        DESTINATION ${INSTALL_CMAKE_DIR})

configure_file(${CMAKE_SOURCE_DIR}/config/spe_config.cmake.in
               ${INSTALL_CMAKE_DIR}/spe_config.cmake @ONLY)

# Toolchain utils
install(FILES
        cmake/set_extensions.cmake
        cmake/mcpu_features.cmake
        cmake/imported_target.cmake
        cmake/hex_generator.cmake
        DESTINATION ${INSTALL_CMAKE_DIR})
