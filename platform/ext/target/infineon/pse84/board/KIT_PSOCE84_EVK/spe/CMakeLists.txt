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

######################### BSP library for Secure image #########################

target_compile_definitions(ifx_pdl_inc_s
    INTERFACE
        CYBSP_SKIP_SAU_INIT # TFM configures SAU by own code
        CYBSP_SKIP_MPC_INIT # TFM configures MPC by own code
        CYBSP_SKIP_MPU_INIT # TFM configures MPU by own code
        CYBSP_SKIP_PPC_INIT # TFM configures PPC by own code
)

##################### TFM library with shared R/O data #########################

target_sources(${IFX_SHARED_RO_DATA_TARGET}
    PRIVATE
        ${IFX_BSP_LIB_PATH}/COMPONENT_CM33/COMPONENT_SECURE_DEVICE/s_system_pse84.c
        ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}/cycfg_qspi_memslot.c
        shared_ro_data.c
)

target_compile_definitions(${IFX_SHARED_RO_DATA_TARGET}
    PUBLIC
        $<$<BOOL:${IFX_MTB_BUILD}>:IFX_MTB_BUILD=1>
)

###################### TFM libraries for Secure image ##########################

target_sources(platform_s
    PRIVATE
        ifx_spm_init.c
)

target_sources(tfm_spm
    PRIVATE
        protection_regions_cfg.c
        ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}/cycfg_system.c
)

target_compile_definitions(tfm_spm
    PRIVATE
        # Define dummy symbols for NSC region to fix ARM Clang error.
        # Although TFM manages the NSC region using its own driver, ARM Clang
        # still requires these symbols to be present for the default SAU
        # configuration.
        NSC_START_ADDRESS=0
        NSC_END_ADDRESS=0
        NSC_SIZE=0
)

target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../shared/device/source/startup_pse84.c
)

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${IFX_MTB_BUILD}>:IFX_MTB_BUILD=1>
)

######################### Install non secure interface #########################

# MTB uses own system for design files thus no need to install them
if(NOT IFX_MTB_BUILD)
    install(FILES       ${IFX_BSP_DESIGN_FILE_PATH}
                        ${IFX_BSP_QSPI_DESIGN_FILE_PATH}
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/board/shared/design/${IFX_BSP_DESIGN_FILE_NAME})

    install(DIRECTORY   ${IFX_BSP_QSPI_FLASH_LOADERS_DIR_PATH}
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/board/shared/design/${IFX_BSP_DESIGN_FILE_NAME})
endif()
