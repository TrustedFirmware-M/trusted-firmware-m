#-------------------------------------------------------------------------------
# Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
cmake_policy(SET CMP0118 NEW)

include(${IFX_COMMON_SOURCE_DIR}/cmake/mtb.cmake)

######################## BSP library for Secure image ##########################

add_library(ifx_bsp STATIC EXCLUDE_FROM_ALL)

target_compile_options(ifx_bsp
    PRIVATE
        ${COMPILER_CP_FLAG}
        ${COMPILER_CMSE_FLAG}
)

# Make BSP dependent on generated sources (IFX_BSP_GENERATED_FILES_OUTPUT_PATH)
add_dependencies(ifx_bsp ifx_bsp_generated_sources)

# Add sources to ifx_bsp target
ifx_mtb_autodiscovery(
    PATH ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}
    PATH ${IFX_BSP_LIB_PATH}
    TARGET ifx_bsp
    COMPONENTS ${IFX_BSP_S_COMPONENTS}
    EXCLUDE ${IFX_BSP_S_EXCLUDE}
    # Headers are added to ifx_pdl_inc_s, because PDL has cyclic dependency on BSP
    EXCLUDE_HEADERS
)

target_link_libraries(ifx_bsp
    PUBLIC
        ifx_pdl_inc_s
    PRIVATE
        $<$<BOOL:${IFX_MTB_SRF}>:ifx_mtb_srf_int>
        $<$<BOOL:${IFX_MTB_SRF}>:ifx_mtb_srf_s>
)

# Add headers to ifx_pdl_inc_s target, because PDL has cyclic dependency on BSP
add_dependencies(ifx_pdl_inc_s ifx_bsp_generated_sources)
ifx_mtb_autodiscovery(
    PATH ${IFX_BOARD_PATH}/shared
    PATH ${IFX_BOARD_PATH}/spe
    PATH ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}
    PATH ${IFX_BSP_LIB_PATH}
    PATH ${IFX_CONFIG_BSP_PATH}
    TARGET ifx_pdl_inc_s
    COMPONENTS ${IFX_BSP_S_COMPONENTS}
    # Sources are added to ifx_bsp
    EXCLUDE_SOURCES
)

##################### TFM library with shared R/O data #########################

# Make shared R/O data dependent on generated sources
add_dependencies(${IFX_SHARED_RO_DATA_TARGET} ifx_bsp_generated_sources)

target_link_libraries(${IFX_SHARED_RO_DATA_TARGET}
    PUBLIC
        ifx_pdl_inc_s
        ifx_pdl_s
)

###################### TFM libraries for Secure image ##########################

target_link_libraries(platform_s
    PUBLIC
        ifx_bsp
        ifx_pdl_inc_s
)

target_link_libraries(platform_region_defs
    INTERFACE
        ifx_pdl_inc_s
)
