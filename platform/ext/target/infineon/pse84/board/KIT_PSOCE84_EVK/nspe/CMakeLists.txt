#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

###################### BSP library for Non-Secure image ########################

target_compile_definitions(ifx_pdl_inc_ns
    INTERFACE
        # project_memory_layout.h uses board name to customize configuration
        ${IFX_BOARD_NAME}
        $<$<BOOL:${IFX_HALT_CM55}>:IFX_HALT_CM55>
)

################################################################################

# Add startup file for cm33 and cm55 NSPEs
target_sources(tfm_ns
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../shared/device/source/startup_pse84.c
)

# Sources are added to PDL library, because BSP and PDL depend on one another
target_sources(ifx_pdl_ns
    PRIVATE
        # CM33
        $<$<STREQUAL:${IFX_CORE},${IFX_CM33}>:${IFX_BSP_LIB_PATH}/COMPONENT_CM33/COMPONENT_NON_SECURE_DEVICE/ns_system_pse84.c>

        # CM55
        $<$<STREQUAL:${IFX_CORE},${IFX_CM55}>:${IFX_BSP_LIB_PATH}/COMPONENT_CM55/COMPONENT_NON_SECURE_DEVICE/ns_system_pse84.c>
)

########################### Non-Secure Application ############################

# Add config file definition for cm33 and cm55 NSPEs linker script
# Note that target_add_scatter_file creates ${target}_scatter CMake target
# which is used to build scatter file, but this target is not available for platform.
# So, tfm_config is used instead which is linked with ${target}_scatter target.
target_compile_definitions(tfm_config
    INTERFACE
        IFX_TARGET_LINKER_CONFIG_HEADER="region_defs.h"
)

target_include_directories(tfm_config
    INTERFACE
        ${IFX_FAMILY_SOURCE_DIR}/shared/partition
)
