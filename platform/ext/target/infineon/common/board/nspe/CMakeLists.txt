#-------------------------------------------------------------------------------
# Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
# Set CMP0118: The GENERATED source file property is now visible in all
# directories for all targets created in this file
cmake_policy(SET CMP0118 NEW)

include(${IFX_COMMON_SOURCE_DIR}/cmake/mtb.cmake)

###################### BSP library for Non-Secure image ########################

add_library(ifx_bsp STATIC EXCLUDE_FROM_ALL)

# Make BSP dependent on generated sources (IFX_BSP_GENERATED_FILES_OUTPUT_PATH)
add_dependencies(ifx_bsp ifx_bsp_generated_sources)

# Add sources to ifx_bsp target
ifx_mtb_autodiscovery(
    PATH ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}
    PATH ${IFX_BSP_LIB_PATH}
    TARGET ifx_bsp
    COMPONENTS ${IFX_BSP_NS_COMPONENTS}
    EXCLUDE ${IFX_BSP_NS_EXCLUDE}
    # Headers are added to ifx_pdl_inc_ns, because PDL has cyclic dependency on BSP
    EXCLUDE_HEADERS
)

target_link_libraries(ifx_bsp
    PUBLIC
        ifx_pdl_inc_ns
    PRIVATE
        $<$<BOOL:${IFX_MTB_SRF}>:ifx_mtb_srf_int>
        $<$<BOOL:${IFX_MTB_SRF}>:ifx_mtb_srf_ns>
        ifx_pdl_ns
)

# Add headers to ifx_pdl_inc_ns target, because PDL has cyclic dependency on BSP
add_dependencies(ifx_pdl_inc_ns ifx_bsp_generated_sources)
ifx_mtb_autodiscovery(
    PATH ${IFX_BOARD_PATH}/nspe
    PATH ${IFX_BOARD_PATH}/shared
    PATH ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}
    PATH ${IFX_BSP_LIB_PATH}
    PATH ${IFX_CONFIG_BSP_PATH}
    TARGET ifx_pdl_inc_ns
    COMPONENTS ${IFX_BSP_NS_COMPONENTS}
    # Sources are added to ifx_bsp
    EXCLUDE_SOURCES
)

target_compile_definitions(ifx_pdl_inc_ns
    INTERFACE
        ${IFX_PDL_PART_NUMBER}
)

################################################################################

target_link_libraries(platform_ns
    PUBLIC
        ifx_bsp
        ifx_pdl_inc_ns
)

target_link_libraries(platform_region_defs
    INTERFACE
        ifx_pdl_inc_ns
)
