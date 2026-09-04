#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
# Set CMP0118: The GENERATED source file property is now visible in all
# directories for all targets created in this file
cmake_policy(SET CMP0118 NEW)

############################ Platform specific PDL #############################

target_sources(ifx_pdl_ns
    PRIVATE
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_dma.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_sysint_v2.c
)

target_include_directories(tfm_config
    INTERFACE
        ${IFX_PLATFORM_SOURCE_DIR}/shared/partition
)
