#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

# Generate framework feature
set(PSA_FRAMEWORK_ISOLATION_LEVEL   ${TFM_ISOLATION_LEVEL})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/psa/framework_feature.h.in
               ${CMAKE_BINARY_DIR}/generated/interface/include/psa/framework_feature.h
               @ONLY)

###################### PSA interface (header only) #############################

add_library(psa_interface INTERFACE)

target_include_directories(psa_interface
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/generated/interface/include>
        $<BUILD_INTERFACE:$<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/include/multi_core>>
)

target_link_libraries(psa_interface
    INTERFACE
        tfm_config
)

target_compile_definitions(psa_interface
    INTERFACE
        $<$<BOOL:${CONFIG_TFM_ENABLE_CTX_MGMT}>:CONFIG_TFM_ENABLE_CTX_MGMT>
        $<$<BOOL:${TFM_ISOLATION_LEVEL}>:TFM_ISOLATION_LEVEL=${TFM_ISOLATION_LEVEL}>
        $<$<BOOL:${CONFIG_TFM_USE_TRUSTZONE}>:CONFIG_TFM_USE_TRUSTZONE>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:TFM_MULTI_CORE_TOPOLOGY>
        $<$<BOOL:${CONFIG_TFM_PARTITION_META}>:CONFIG_TFM_PARTITION_META>
        $<$<BOOL:${TEST_NS_MULTI_CORE}>:TFM_MULTI_CORE_TEST>
        $<$<BOOL:${TFM_HYBRID_PLATFORM_API_BROKER}>:TFM_HYBRID_PLATFORM_API_BROKER>
)

add_dependencies(psa_interface manifest_tool)

###################### PSA api (S lib) #########################################

target_sources(tfm_sprt
    PRIVATE
        $<$<BOOL:${TFM_PARTITION_INITIAL_ATTESTATION}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_attest_api.c>
        $<$<BOOL:${TFM_PARTITION_CRYPTO}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_crypto_api.c>
        $<$<BOOL:${TFM_PARTITION_FIRMWARE_UPDATE}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_fwu_api.c>
        $<$<BOOL:${TFM_PARTITION_INTERNAL_TRUSTED_STORAGE}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_its_api.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_platform_api.c>
        $<$<BOOL:${TFM_PARTITION_PROTECTED_STORAGE}>:${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_ps_api.c>
        ${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_psa_call.c
)

###################### Export configurations to NS #############################

if (TFM_MULTI_CORE_TOPOLOGY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/multi_core/tfm_mailbox_config.h.in
                   ${CMAKE_BINARY_DIR}/generated/interface/include/tfm_mailbox_config.h
                   NEWLINE_STYLE UNIX
    )
endif()
