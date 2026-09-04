#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_subdirectory(${IFX_COMMON_SOURCE_DIR}/spe common)

target_include_directories(platform_s
    PUBLIC
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m
        ${IFX_PLATFORM_SOURCE_DIR}/spe
        ${IFX_PLATFORM_SOURCE_DIR}/shared
        ${IFX_PLATFORM_SOURCE_DIR}/config
)

target_compile_definitions(tfm_s_scatter
    PRIVATE
        ${IFX_PDL_PART_NUMBER}
)

############################ Platform specific PDL #############################

target_sources(ifx_pdl_s
    PRIVATE
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_dma.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_sysint_v2.c
)

################################ tfm_spm #######################################

target_include_directories(tfm_spm
    PUBLIC
        ${IFX_COMMON_SOURCE_DIR}/spe/protection
        ${CMAKE_CURRENT_LIST_DIR}/protection
)

target_sources(tfm_spm
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m/target_cfg.c
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m/tfm_hal_platform.c
        ${IFX_COMMON_SOURCE_DIR}/spe/faults/faults_cat1b.c
        ${CMAKE_CURRENT_LIST_DIR}/protection/protection_data.c
)

if(TFM_PARTITION_CRYPTO)
    target_include_directories(crypto_service_tfpsacrypto_config
        INTERFACE
            ${CMAKE_SOURCE_DIR}/lib/ext/tf-psa-crypto/tfpsacrypto_config
    )

    target_compile_definitions(crypto_service_tfpsacrypto_config
        INTERFACE
            $<$<BOOL:${IFX_CRYPTOLITE_USER_CONFIG_FILE}>:CY_CRYPTOLITE_USER_CONFIG_FILE="${IFX_CRYPTOLITE_USER_CONFIG_FILE}">
            $<$<BOOL:${IFX_PSA_CRYPTOLITE_USER_CONFIG_FILE}>:IFX_PSA_CRYPTOLITE_USER_CONFIG_FILE="${IFX_PSA_CRYPTOLITE_USER_CONFIG_FILE}">
            $<$<BOOL:${IFX_PSA_CRYPTOSUITE_USER_CONFIG_FILE}>:IFX_PSA_CRYPTOSUITE_USER_CONFIG_FILE="${IFX_PSA_CRYPTOSUITE_USER_CONFIG_FILE}">
            $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:SYMMETRIC_INITIAL_ATTESTATION>
            $<$<BOOL:${IFX_CRYPTOSUITE_ENABLED}>:IFX_CRYPTOSUITE_ENABLED>
    )
endif()

if(TFM_PARTITION_INITIAL_ATTESTATION)
    target_compile_definitions(tfm_t_cose_s
        PUBLIC
            $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:T_COSE_ENABLE_AES_CMAC_128>
    )
endif()
