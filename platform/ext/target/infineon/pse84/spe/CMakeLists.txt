#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_subdirectory(${IFX_COMMON_SOURCE_DIR}/spe common)

############################### Platform Secure ###############################

target_include_directories(platform_s
    PUBLIC
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m
        ${IFX_FAMILY_SOURCE_DIR}/shared
        ${IFX_FAMILY_SOURCE_DIR}/shared/device/include
        ${IFX_FAMILY_SOURCE_DIR}/shared/device/config
        ${IFX_FAMILY_SOURCE_DIR}/config
        ${IFX_FAMILY_SOURCE_DIR}/spe
)

target_sources(platform_s
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/provisioning/ifx_platform_provisioning.c
)

############################### PDL code to run from SRAM ############################

target_sources(flash_drivers
    PRIVATE
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_smif.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_smif_sfdp.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_smif_memnum.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_smif_memslot.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_smif_hb_flash.c
)

################################ tfm_spm #############################################

target_sources(tfm_spm
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m/target_cfg.c
        ${IFX_COMMON_SOURCE_DIR}/spe/v80m/tfm_hal_platform.c
        ${IFX_COMMON_SOURCE_DIR}/spe/faults/faults_cat1d.c
        protection/protection_data.c
)

target_include_directories(tfm_spm
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/protection
)

############################# Secure Application ##############################

target_compile_definitions(tfm_s_scatter
    PRIVATE
        ${IFX_PDL_PART_NUMBER}
        ${IFX_BOARD_NAME}
        $<$<BOOL:${IFX_CM33_NS_PRESENT}>:IFX_CM33_NS_PRESENT=1>
        $<$<BOOL:${IFX_CM55_NS_PRESENT}>:IFX_CM55_NS_PRESENT=1>
)
