#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0118 NEW)

##################### TFM library with shared R/O data #########################

target_sources(ifx_tfm_sp_meta
    PRIVATE
        ${IFX_BSP_LIB_PATH}/system_psc3_x6.c
)

# Check if we are using the hardware peripheral init in startup
target_compile_definitions(ifx_tfm_sp_meta
    PRIVATE
        # This is used to disable startup IP when TF-M is used with bootloader
        $<$<NOT:$<BOOL:${IFX_ENABLE_HW_PERI_IN_STARTUP}>>:CY_NOT_ENABLE_IP_IN_STARTUP>
)

#################################### tfm_spm ###################################

target_sources(tfm_spm
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/source/protection_regions_cfg.c
        ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH}/cycfg_system.c
)
