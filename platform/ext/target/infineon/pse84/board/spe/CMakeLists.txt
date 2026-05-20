#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
cmake_policy(SET CMP0118 NEW)

##################### TFM library with shared R/O data #########################

target_sources(ifx_tfm_sp_meta
    PRIVATE
        ${IFX_BSP_LIB_PATH}/COMPONENT_CM33/COMPONENT_SECURE_DEVICE/s_system_pse84.c
        ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}/cycfg_qspi_memslot.c
        shared_ro_data.c
)

target_compile_definitions(ifx_tfm_sp_meta
    PUBLIC
        $<$<BOOL:${IFX_MTB_BUILD}>:IFX_MTB_BUILD=1>
)

###################### TFM libraries for Secure image ##########################

target_sources(tfm_spm
    PRIVATE
        protection_regions_cfg.c
        ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}/cycfg_system.c
)

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${IFX_MTB_BUILD}>:IFX_MTB_BUILD=1>
)

######################### Install non secure interface #########################

# MTB uses own system for design files thus no need to install them
if(NOT IFX_MTB_BUILD)
    install(DIRECTORY   ${IFX_BSP_DESIGN_DIR_PATH}
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/board/shared/design)
endif()
