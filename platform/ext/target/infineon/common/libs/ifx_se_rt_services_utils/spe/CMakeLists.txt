#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

########################## ifx_se_rt_services_utils_s ##########################

add_library(ifx_se_rt_services_utils_s STATIC EXCLUDE_FROM_ALL)

target_compile_options(ifx_se_rt_services_utils_s
    PRIVATE
        ${COMPILER_CP_FLAG}
)

target_sources(ifx_se_rt_services_utils_s
    PUBLIC
    PRIVATE
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_crc32.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_fih.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_platform.c
        ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_psacrypto.c
)

target_include_directories(ifx_se_rt_services_utils_s
    PUBLIC
        .
        ${IFX_SE_RT_SERVICES_UTILS_PATH}
    PRIVATE
)

target_link_libraries(ifx_se_rt_services_utils_s
    PUBLIC
        ifx_pdl_s
    PRIVATE
)
