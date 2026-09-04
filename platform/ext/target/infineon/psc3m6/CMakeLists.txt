#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Library with shared read-only data, only SPM/PRoT can write it
add_library(ifx_tfm_sp_meta STATIC)

target_compile_options(ifx_tfm_sp_meta
    PRIVATE
        ${COMPILER_CMSE_FLAG}
)

add_subdirectory(${IFX_PLATFORM_SOURCE_DIR}/libs libs)

add_subdirectory(${IFX_COMMON_SOURCE_DIR}/board board)

############################# Platform region defs #############################
target_include_directories(platform_region_defs
    INTERFACE
        shared/partition
)

############################## TF-M configuration ##############################
target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/config>
)

########################## Platform Common Interface ###########################
target_compile_definitions(tfm_config
    INTERFACE
        $<$<BOOL:${IFX_SET_PC3_MANUALLY}>:IFX_SET_PC3>
)

############################### Platform Secure ###############################
add_subdirectory(spe)

if(TFM_PARTITION_CRYPTO)
    target_include_directories(platform_crypto_keys
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/spe/services/crypto
    )

    target_include_directories(psa_interface
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/spe/services/crypto>
    )
endif()

################################ Code coverage #################################

# Code coverage flags must be added after all platform files have been added
# to the build

if(TEST_NS_IFX_CODE_COVERAGE)
    include(${IFX_COMMON_SOURCE_DIR}/cmake/code_coverage.cmake)

    set(IFX_COVERAGE_IGNORE_LIST "")

    # Exclude test (we measure coverage of the secure code, not the code that tests it)
    list(APPEND IFX_COVERAGE_IGNORE_LIST "platform/ext/target/infineon/psc3m6/tests")

    ifx_add_code_coverage(
        EXCLUDE ${IFX_COVERAGE_IGNORE_LIST}
        FILTER_FILE "${IFX_COMMON_SOURCE_DIR}/deploy/tfm_files_to_deploy.txt"
    )
endif()

################################################################################

include(./install.cmake)
