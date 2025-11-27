#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

########################## IFX_SE_RT_SERVICES_UTILS_S ##########################

add_library(${IFX_SE_RT_SERVICES_UTILS_S_TARGET} STATIC EXCLUDE_FROM_ALL)

target_compile_options(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
    PRIVATE
        ${COMPILER_CP_FLAG}
)

target_sources(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
    PUBLIC
    PRIVATE
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_crc32.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_fih.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_platform.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_psacrypto.c
)

target_include_directories(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
    PUBLIC
        .
        ${IFX_SE_RT_SERVICES_UTILS_PATH}
    PRIVATE
)

target_link_libraries(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
    PUBLIC
        ifx_pdl_s
    PRIVATE
)
