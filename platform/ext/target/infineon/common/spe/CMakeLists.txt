#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_subdirectory(protection)
add_subdirectory(services)

################################ PSA Interface ################################

target_include_directories(psa_interface
    INTERFACE
        $<BUILD_INTERFACE:${IFX_COMMON_SOURCE_DIR}/interface/include>
)

############################# Platform region defs #############################

target_include_directories(platform_region_defs
    INTERFACE
        ${IFX_COMMON_SOURCE_DIR}/utils
)

############################### Platform Secure ###############################

target_include_directories(platform_s
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/interface/src
        $<$<BOOL:${TEST_S_FPU}>:${CMAKE_SOURCE_DIR}/platform/ext/common>
    PUBLIC
        ${CMAKE_SOURCE_DIR}/interface/include
        ${IFX_COMMON_SOURCE_DIR}/config
        ${IFX_COMMON_SOURCE_DIR}/device/include
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash
        ${IFX_COMMON_SOURCE_DIR}/interface/include
        ${IFX_COMMON_SOURCE_DIR}/spe/faults
        ${IFX_COMMON_SOURCE_DIR}/spe/provisioning
        ${IFX_COMMON_SOURCE_DIR}/spe/svc
        $<$<BOOL:${TEST_S_FPU}>:${IFX_COMMON_SOURCE_DIR}/spe/test>
        $<$<BOOL:${IFX_UART_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/stdio>
        ${IFX_COMMON_SOURCE_DIR}/utils
        ${MBEDCRYPTO_PATH}/target/infineon/mbedtls
        ${CMAKE_SOURCE_DIR}/secure_fw/spm/include/boot
        ${CMAKE_SOURCE_DIR}/secure_fw/spm/include/interface
)

target_sources(platform_s
    PRIVATE
        ${CMAKE_SOURCE_DIR}/platform/ext/common/tfm_hal_nvic.c
        ${IFX_COMMON_SOURCE_DIR}/device/src/device_definition.c
        $<$<BOOL:${IFX_UART_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/stdio/uart_pdl_stdout.c>
        $<$<BOOL:${IFX_PLATFORM_DEFAULT_OTP}>:${IFX_COMMON_SOURCE_DIR}/spe/otp/otp_flash.c>
        ${CMAKE_SOURCE_DIR}/platform/ext/common/provisioning_bundle/runtime_stub_provisioning.c
        ${IFX_COMMON_SOURCE_DIR}/spe/provisioning/provisioning.c
        ${IFX_COMMON_SOURCE_DIR}/utils/ifx_boot_shared_data.c
        ${IFX_COMMON_SOURCE_DIR}/utils/ifx_regions.c
        $<$<BOOL:${TEST_S_FPU}>:${IFX_COMMON_SOURCE_DIR}/spe/test/ifx_fpu_s.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${IFX_UART_ENABLED}>:IFX_UART_ENABLED=1>
        $<$<BOOL:${TEST_S_FPU}>:TEST_S_FPU>
        # IFX tests can reboot devices so ensure that all logs was printed before reboot
        $<$<BOOL:${TEST_NS_IFX_FRAMEWORK}>:IFX_TFM_SPM_UART_FLUSH=1>
)

target_link_libraries(platform_s
    PUBLIC
        ifx_pdl_s
        ${IFX_SHARED_RO_DATA_TARGET}
)

# SPRT can be used by ARoT partitions
target_sources(tfm_sprt
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/spe/svc/platform_svc_api.c
)

if(IFX_MTB_MAILBOX)
    target_sources(platform_s
        PRIVATE
            # Core specific multi core hal is added so that SPE can use internal
            # memory detection functions (e.g. MPC driver)
            $<$<BOOL:${IFX_MULTICORE_CM55}>:${CMAKE_CURRENT_LIST_DIR}/services/mailbox/platform_hal_multi_core_cm55.c>
    )

    target_include_directories(platform_s
        PRIVATE
            # Core specific multi core hal is added so that SPE can use internal
            # memory detection functions (e.g. MPC driver). Include directories
            # are added accordingly
            ${IFX_COMMON_SOURCE_DIR}/shared/mailbox
    )
endif()

############################## TF-M configuration ##############################

target_compile_definitions(tfm_config
    INTERFACE
        ${IFX_BOARD_NAME}
        TEST_NS_IFX_CODE_COVERAGE=$<BOOL:${TEST_NS_IFX_CODE_COVERAGE}>
        $<$<BOOL:${IFX_PRINT_CORE_PREFIX}>:IFX_PRINT_CORE_PREFIX=1>
        $<$<BOOL:${IFX_MTB_SRF}>:IFX_MTB_SRF>
        TEST_NS_IFX_ISOLATION_TEST=$<BOOL:${TEST_NS_IFX_ISOLATION_TEST}>
        $<$<BOOL:${TEST_NS_IFX_IRQ_TEST_MASKED}>:TEST_NS_IFX_IRQ_TEST_MASKED=1>
        $<$<BOOL:${TEST_NS_IFX_IRQ_TEST_UNMASKED}>:TEST_NS_IFX_IRQ_TEST_UNMASKED=1>
        $<$<BOOL:${TEST_NS_IFX_CRYPTO_BENCHMARK}>:TEST_NS_IFX_CRYPTO_BENCHMARK=1>
        $<$<BOOL:${TEST_NS_IFX_FRAMEWORK}>:TEST_NS_IFX_FRAMEWORK=1>
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_ENABLED>
        # Always dump attestation token from tf-m-tests
        # So that attestation token could be verified
        DUMP_TOKEN=1
        $<$<BOOL:${IFX_MTB_MAILBOX}>:IFX_MTB_MAILBOX=1>
)

target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${IFX_GENERATED_DIR}/secure_fw/ifx>
)

if(DEFINED IFX_PROJECT_CONFIG_PATH)
    target_compile_definitions(tfm_config
        INTERFACE
            $<BUILD_INTERFACE:IFX_PROJECT_CONFIG_PATH="${IFX_PROJECT_CONFIG_PATH}">
    )
endif()

# Overwrite PS_RAM_FS in .h files if PS_RAM_FS is specified in CMake
# This makes it possible to set PS_RAM_FS through CMake
if(DEFINED PS_RAM_FS)
    target_compile_definitions(tfm_config
        INTERFACE
            $<$<BOOL:${PS_RAM_FS}>:PS_RAM_FS=1>
            $<$<NOT:$<BOOL:${PS_RAM_FS}>>:PS_RAM_FS=0>
    )
endif()

# Overwrite ITS_RAM_FS in .h files if ITS_RAM_FS is specified in CMake
# This makes it possible to set ITS_RAM_FS through CMake
if(DEFINED ITS_RAM_FS)
    target_compile_definitions(tfm_config
        INTERFACE
            $<$<BOOL:${ITS_RAM_FS}>:ITS_RAM_FS=1>
            $<$<NOT:$<BOOL:${ITS_RAM_FS}>>:ITS_RAM_FS=0>
    )
endif()

# Generate SPE configuration
configure_file(${IFX_COMMON_SOURCE_DIR}/config/ifx_spe_config.h.in
               ${IFX_GENERATED_DIR}/secure_fw/ifx/ifx_spe_config.h)

################################ tfm_s_scatter #################################

# Use normal scatter file for L1 and L2 and generated one for L3
# IAR is currently not supported in L3
target_add_scatter_file(tfm_s
    # IMPROVEMENT: Use secure linker files from common code, not infineon ones
    $<$<AND:$<VERSION_LESS:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:ARMClang>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/armclang/tfm_common_s.sct>
    $<$<AND:$<VERSION_LESS:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:GNU>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/gcc/tfm_common_s.ld>
    $<$<AND:$<VERSION_LESS:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:IAR>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/iar/tfm_common_s.icf>

    $<$<AND:$<VERSION_EQUAL:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:ARMClang>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/armclang/tfm_isolation_l3.sct>
    $<$<AND:$<VERSION_EQUAL:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:GNU>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/gcc/tfm_isolation_l3.ld>
    $<$<AND:$<VERSION_EQUAL:${TFM_ISOLATION_LEVEL},3>,$<C_COMPILER_ID:IAR>>:${IFX_GENERATED_DIR}/platform/ext/target/infineon/common/toolchain/iar/tfm_isolation_l3.icf>
)

target_compile_definitions(tfm_s_scatter
    PRIVATE
        IFX_LINKER_SCRIPT=1
        $<$<C_COMPILER_ID:ARMClang>:IFX_ARM_CLANG_LINKER_SCRIPT>
        TEST_NS_IFX_CODE_COVERAGE=$<BOOL:${TEST_NS_IFX_CODE_COVERAGE}>
)

################################ tfm_spm #############################################

target_sources(tfm_spm
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/spe/faults/faults.c
        svc/platform_svc_handler.c
)

target_compile_definitions(tfm_spm
    PRIVATE
        $<$<BOOL:${IFX_FAULTS_INFO_DUMP}>:IFX_FAULTS_INFO_DUMP>
        $<$<BOOL:${TEST_NS_IFX_CODE_COVERAGE}>:TEST_NS_IFX_CODE_COVERAGE=1>
)

#################################### Shared data #####################################

target_include_directories(${IFX_SHARED_RO_DATA_TARGET}
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash
        ${IFX_COMMON_SOURCE_DIR}/utils
        ${IFX_FAMILY_SOURCE_DIR}/shared
        ${CMAKE_SOURCE_DIR}/platform/ext/driver
)

target_link_libraries(${IFX_SHARED_RO_DATA_TARGET}
    PUBLIC
        ifx_pdl_inc_s
        tfm_config
)

################################## FIH ###############################################

target_sources(tfm_fih
    INTERFACE
        $<$<STREQUAL:${TFM_FIH_PROFILE},HIGH>:${IFX_COMMON_SOURCE_DIR}/spe/fih/tfm_fih_mxcrypto.c>
)

target_link_libraries(tfm_fih
    INTERFACE
        ifx_pdl_s
        # FIH delay uses TRNG provided by PDL crypto acceleration driver
        $<$<STREQUAL:${TFM_FIH_PROFILE},HIGH>:ifx_pdl_mbedtls_acceleration>
)
