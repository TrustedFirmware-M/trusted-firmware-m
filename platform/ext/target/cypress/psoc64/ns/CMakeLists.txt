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

set(MTB_PDL_CAT1_LIB_NS_TARGET mtb-pdl-cat1_lib_ns)
add_subdirectory(libs/mtb-pdl-cat1/mtb-pdl-cat1_ns_lib)

#========================= Platform common defs ===============================#

add_library(platform_ns)

target_sources(platform_ns
    INTERFACE
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/armclang/startup_psoc64_ns.s>
        $<$<C_COMPILER_ID:ARMClang>:${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/source/TOOLCHAIN_ARM/cy_syslib_mdk.s>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/startup_psoc64_ns.S>
        $<$<C_COMPILER_ID:GNU>:${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_gcc.S>
        $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/iar/startup_psoc64_ns.s>
        $<$<C_COMPILER_ID:IAR>:${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/source/TOOLCHAIN_IAR/cy_syslib_iar.s>
)

target_sources(platform_ns
    PRIVATE
        ./../interface/src/multi_core/platform_ns_mailbox.c
        ./Device/Source/system_psoc6_cm4.c
        ./Device/Source/psoc6_system_init_cm4.c
        ./Native_Driver/generated_source/cycfg.c
        ./Native_Driver/generated_source/cycfg_clocks.c
        ./Native_Driver/generated_source/cycfg_clocks.c
        ./Native_Driver/generated_source/cycfg_peripherals.c
        ./Native_Driver/generated_source/cycfg_pins.c
        ./Native_Driver/generated_source/cycfg_routing.c
        ./Native_Driver/generated_source/cycfg_system.c
        ./Native_Driver/generated_source/cycfg_qspi_memslot.c
        ./../interface/src/multi_core/platform_multicore.c
        ./CMSIS_Driver/Driver_USART.c
        ./Device/Source/device_definition.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
)

target_include_directories(platform_ns
    PUBLIC
        .
        ./include
        ./partition
        Device/Config
        Device/Include
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        ext/common
        ${CY_MTB_PDL_CAT1_LIB_PATH}/drivers/include
        ${CY_MTB_PDL_CAT1_LIB_PATH}/devices/COMPONENT_CAT1A/include
        ${CY_CORE_LIB_PATH}/include
        Native_Driver/generated_source
        CMSIS_Driver/Config
    PRIVATE
        ${CY_MTB_PDL_CAT1_LIB_PATH}/cmsis/include
)

target_compile_definitions(platform_ns
    PUBLIC
        RTE_USART5
)

target_link_libraries(platform_ns
    PRIVATE
        ${MTB_PDL_CAT1_LIB_NS_TARGET}
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
)

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    target_link_libraries(tfm_api_ns_mailbox PUBLIC platform_ns)
endif()
