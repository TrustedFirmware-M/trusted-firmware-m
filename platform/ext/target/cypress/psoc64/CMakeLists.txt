#-------------------------------------------------------------------------------
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
# Copyright (c) 2020-2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set (CY_PLATFORM_DIR  ${CMAKE_CURRENT_SOURCE_DIR})
set (CY_CORE_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/core-lib)
set (CY_PSOC64_DIR    ${CMAKE_CURRENT_SOURCE_DIR})

#========================= Libraries ==========================================#

set(MTB_PDL_CAT1_LIB_S_TARGET  mtb-pdl-cat1_lib_s)
set(P64_UTILS_LIB_TARGET   p64_utils_lib)

add_subdirectory(libs/mtb-pdl-cat1/mtb-pdl-cat1_s_lib)
add_subdirectory(libs/p64_utils)

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
)
target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_ENABLED>
)

#========================= Platform common defs ===============================#

target_sources(tfm_s
    PRIVATE
        $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:ARMClang>>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/startup_psoc64_s.S>
        $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:ARMClang>>:${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S>
        $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/iar/startup_psoc64_s.s>
        $<$<C_COMPILER_ID:IAR>:${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/source/TOOLCHAIN_IAR/cy_syslib_iar.s>
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_isolation_s.icf>
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        Device/Config
        Device/Include
        ${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/include
        ${CY_MTB_PDL_CAT1_LIB_PATH}/devices/COMPONENT_CAT1A/include
        ${CY_CORE_LIB_PATH}/include
        Native_Driver/generated_source
        ./CMSIS_Driver/Config
        mailbox
    PRIVATE
        ${CY_MTB_PDL_CAT1_LIB_PATH}/cmsis/include
)

target_sources(platform_s
    PRIVATE
        ./mailbox/platform_multicore.c
        ./mailbox/platform_spe_mailbox.c
        ./Device/Source/system_psoc6_cm0plus.c
        ./Device/Source/psoc6_system_init_cm0p.c
        ./Native_Driver/generated_source/cycfg.c
        ./Native_Driver/generated_source/cycfg_clocks.c
        ./Native_Driver/generated_source/cycfg_clocks.c
        ./Native_Driver/generated_source/cycfg_peripherals.c
        ./Native_Driver/generated_source/cycfg_pins.c
        ./Native_Driver/generated_source/cycfg_routing.c
        ./Native_Driver/generated_source/cycfg_system.c
        ./Native_Driver/generated_source/cycfg_qspi_memslot.c
        ./CMSIS_Driver/Driver_Flash.c
        ./CMSIS_Driver/Driver_USART.c
        ./driver_smpu.c
        ./driver_ppu.c
        ./driver_dap.c
        ./Device/Source/device_definition.c
        ./mem_check_v6m_v7m_hal.c
        ${PLATFORM_DIR}/ext/common/mem_check_v6m_v7m.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_compile_definitions(platform_s
    PRIVATE
        RTE_USART5
)

target_link_libraries(platform_s
    PUBLIC
        ${MTB_PDL_CAT1_LIB_S_TARGET}
        ${P64_UTILS_LIB_TARGET}
)

#========================= ns_agent_mailbox ===================================#

target_sources(tfm_psa_rot_partition_ns_agent_mailbox
    PRIVATE
        tfm_hal_multi_core.c
)

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        ./target_cfg.c
        ./tfm_interrupts.c
        ./tfm_hal_isolation.c
        ./tfm_hal_platform.c
)

include(./install.cmake)
