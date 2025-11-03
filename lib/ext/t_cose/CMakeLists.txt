#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

# Default configuration of T_COSE repository
set(T_COSE_PATH     "DOWNLOAD"      CACHE PATH      "Path to t_cose (or DOWNLOAD to fetch automatically")
set(T_COSE_VERSION  "v2.0-alpha-2"  CACHE STRING    "The version of t_cose to use")

fetch_remote_library(
    LIB_NAME                t_cose
    LIB_SOURCE_PATH_VAR     T_COSE_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    LIB_BASE_DIR            "${CMAKE_BINARY_DIR}/lib/ext"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/laurencelundblade/t_cose.git
        GIT_TAG             ${T_COSE_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
# The FetchContent_MakeAvailable() function automatically adds the fetched library
# directory to the build using add_subdirectory(). However, the TF-M t_cose module
# defines its own custom target instead of using the default one provided by the
# remote library.
# We set the SOURCE_SUBDIR variable to a non-existent directory as a workaround.
# Related issue: https://gitlab.kitware.com/cmake/cmake/-/issues/26220
        SOURCE_SUBDIR       non-exist-dir
)

############################ t_cose secure #####################################

add_library(tfm_t_cose_s STATIC EXCLUDE_FROM_ALL
    ${T_COSE_PATH}/crypto_adapters/t_cose_psa_crypto.c
    ${T_COSE_PATH}/src/t_cose_key.c
    ${T_COSE_PATH}/src/t_cose_parameters.c
    ${T_COSE_PATH}/src/t_cose_util.c
)

if(${SYMMETRIC_INITIAL_ATTESTATION})
target_sources(tfm_t_cose_s
    PRIVATE
        ${T_COSE_PATH}/src/t_cose_mac_compute.c
        ${T_COSE_PATH}/src/t_cose_mac_validate.c
)
else()
target_sources(tfm_t_cose_s
    PRIVATE
        ${T_COSE_PATH}/src/t_cose_sign_sign.c
        ${T_COSE_PATH}/src/t_cose_sign1_sign.c
        ${T_COSE_PATH}/src/t_cose_signature_sign_main.c
        ${T_COSE_PATH}/src/t_cose_sign_verify.c
        ${T_COSE_PATH}/src/t_cose_sign1_verify.c
        ${T_COSE_PATH}/src/t_cose_signature_verify_main.c
)
endif()

target_include_directories(tfm_t_cose_s
    PUBLIC
        $<BUILD_INTERFACE:${T_COSE_PATH}/inc>
        $<BUILD_INTERFACE:${T_COSE_PATH}/src>
)

target_compile_definitions(tfm_t_cose_s
    PUBLIC
        T_COSE_USE_PSA_CRYPTO
        T_COSE_DISABLE_CONTENT_TYPE
        T_COSE_DISABLE_COSE_SIGN
        T_COSE_DISABLE_KEYWRAP
        T_COSE_DISABLE_PS256
        T_COSE_DISABLE_PS384
        T_COSE_DISABLE_PS512
        T_COSE_DISABLE_SHORT_CIRCUIT_SIGN
        $<$<OR:$<NOT:$<STREQUAL:${ATTEST_KEY_BITS},384>>,$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>>:T_COSE_DISABLE_ES384>
        $<$<OR:$<NOT:$<STREQUAL:${ATTEST_KEY_BITS},521>>,$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>>:T_COSE_DISABLE_ES512>
)

target_link_libraries(tfm_t_cose_s
    PRIVATE
        psa_crypto_config
        psa_interface
        qcbor
        platform_s
)

target_compile_options(tfm_t_cose_s
    PRIVATE
        ${COMPILER_CP_FLAG}
)
