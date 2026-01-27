#-------------------------------------------------------------------------------
# Copyright (c) 2020, IAR Systems AB. All rights reserved.
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0115 NEW)

SET(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR       ${TFM_SYSTEM_PROCESSOR})

if(CROSS_COMPILE)
    set(CMAKE_C_COMPILER_TARGET      arm-${CROSS_COMPILE})
    set(CMAKE_ASM_COMPILER_TARGET    arm-${CROSS_COMPILE})
else()
    set(CMAKE_C_COMPILER_TARGET      arm-arm-none-eabi)
    set(CMAKE_ASM_COMPILER_TARGET    arm-arm-none-eabi)
endif()

set(CMAKE_C_COMPILER iccarm)
set(CMAKE_CXX_COMPILER iccarm)
set(CMAKE_ASM_COMPILER iasmarm)

set(LINKER_VENEER_OUTPUT_FLAG --import_cmse_lib_out= )
set(COMPILER_CMSE_FLAG --cmse)

set(CMAKE_C_FLAGS_DEBUG "-r -On")

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/cmake/set_extensions.cmake)

macro(tfm_toolchain_reset_compiler_flags)
    set_property(DIRECTORY PROPERTY COMPILE_OPTIONS "")

    add_compile_options(
        $<$<COMPILE_LANGUAGE:C,CXX>:-e>
        $<$<COMPILE_LANGUAGE:C,CXX>:--dlib_config=full>
        $<$<COMPILE_LANGUAGE:C,CXX>:--silent>
        $<$<COMPILE_LANGUAGE:C,CXX>:-DNO_TYPEOF>
        $<$<COMPILE_LANGUAGE:C,CXX>:-D_NO_DEFINITIONS_IN_HEADER_FILES>
        $<$<COMPILE_LANGUAGE:C,CXX>:--diag_suppress=Pe546,Pe940,Pa082,Pa084>
        $<$<COMPILE_LANGUAGE:C,CXX>:--no_path_in_file_macros>
        $<$<AND:$<COMPILE_LANGUAGE:C,CXX,ASM>,$<BOOL:${TFM_DEBUG_SYMBOLS}>,$<CONFIG:Release,MinSizeRel>>:-r>
    )
endmacro()

macro(tfm_toolchain_reset_linker_flags)
    set_property(DIRECTORY PROPERTY LINK_OPTIONS "")

    add_link_options(
      --silent
      --semihosting
      --redirect __write=__write_buffered
      --diag_suppress=lp005,Lp023
    )
endmacro()

macro(tfm_toolchain_set_processor_arch)
    if(${TFM_SYSTEM_PROCESSOR} STREQUAL "cortex-m0plus")
      set(CMAKE_SYSTEM_PROCESSOR Cortex-M0+)
    else()
      set(CMAKE_SYSTEM_PROCESSOR ${TFM_SYSTEM_PROCESSOR})
    endif()

    if (DEFINED TFM_SYSTEM_DSP)
        if(NOT TFM_SYSTEM_DSP)
            string(APPEND CMAKE_SYSTEM_PROCESSOR ".no_dsp")
        endif()
    endif()
endmacro()

macro(tfm_toolchain_reload_compiler)
    tfm_toolchain_set_processor_arch()
    tfm_toolchain_reset_compiler_flags()
    tfm_toolchain_reset_linker_flags()

    unset(CMAKE_C_FLAGS_INIT)
    unset(CMAKE_C_LINK_FLAGS)
    unset(CMAKE_ASM_FLAGS_INIT)
    unset(CMAKE_ASM_LINK_FLAGS)

    set(CMAKE_C_FLAGS_INIT "--cpu ${CMAKE_SYSTEM_PROCESSOR}")
    set(CMAKE_ASM_FLAGS_INIT "--cpu ${CMAKE_SYSTEM_PROCESSOR}")
    set(CMAKE_C_LINK_FLAGS "--cpu ${CMAKE_SYSTEM_PROCESSOR}")
    set(CMAKE_ASM_LINK_FLAGS "--cpu ${CMAKE_SYSTEM_PROCESSOR}")

    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS_INIT})
    set(CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS_INIT})

    # Can't use the highest optimization with IAR on v8.1m arch because of the
    # compilation bug in mbedcrypto
    if ((CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL "9.20") AND
        (CMAKE_C_COMPILER_VERSION VERSION_LESS_EQUAL "9.32.1") AND
        ((TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m85") OR
         (TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m55")) AND
        (NOT (CMAKE_BUILD_TYPE STREQUAL "Debug")))
        message(FATAL_ERROR "Only debug build available for M55 and M85"
                " cores with IAR version between 9.20 and 9.32.1")
    endif()

    set(BL2_COMPILER_CP_FLAG
        $<$<COMPILE_LANGUAGE:C>:--fpu=none>
        $<$<COMPILE_LANGUAGE:ASM>:--fpu=none>
    )
    # As BL2 does not use hardware FPU, specify '--fpu=none' explicitly to use software
    # library functions for BL2 to override any implicit FPU option, such as '--cpu' option.
    # Because the implicit hardware FPU option enforces BL2 to initialize FPU but hardware FPU
    # is not actually enabled in BL2, it will cause BL2 runtime fault.
    set(BL2_LINKER_CP_OPTION --fpu=none)

    set(BL1_COMPILER_CP_FLAG
        $<$<COMPILE_LANGUAGE:C>:--fpu=none>
        $<$<COMPILE_LANGUAGE:ASM>:--fpu=none>
    )
    set(BL1_LINKER_CP_OPTION --fpu=none)

    if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
        set(COMPILER_CP_FLAG
            $<$<COMPILE_LANGUAGE:C>:-mfloat-abi=hard>
        )

        if (CONFIG_TFM_ENABLE_FP)
            set(COMPILER_CP_FLAG
                $<$<COMPILE_LANGUAGE:C>:--fpu=${CONFIG_TFM_FP_ARCH_ASM}>
                $<$<COMPILE_LANGUAGE:ASM>:--fpu=${CONFIG_TFM_FP_ARCH_ASM}>
            )
            # armasm and armlink have the same option "--fpu" and are both used to
            # specify the target FPU architecture. So the supported FPU architecture
            # names can be shared by armasm and armlink.
            set(LINKER_CP_OPTION --fpu=${CONFIG_TFM_FP_ARCH_ASM})
        endif()
    else()
        set(COMPILER_CP_FLAG
            $<$<COMPILE_LANGUAGE:C>:--fpu=none>
            $<$<COMPILE_LANGUAGE:ASM>:--fpu=none>
        )
        set(LINKER_CP_OPTION --fpu=none)
    endif()

    add_compile_definitions(
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv6-m>:__ARM_ARCH_6M__=1>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv7-m>:__ARM_ARCH_7M__=1>
        $<$<AND:$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv7-m>,$<BOOL:__ARM_FEATURE_DSP>>:__ARM_ARCH_7EM__=1>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.base>:__ARM_ARCH_8M_BASE__=1>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.main>:__ARM_ARCH_8M_MAIN__=1>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8.1-m.main>:__ARM_ARCH_8_1M_MAIN__=1>
    )
endmacro()

# Configure environment for the compiler setup run by cmake at the first
# `project` call in <tfm_root>/CMakeLists.txt. After this mandatory setup is
# done, all further compiler setup is done via tfm_toolchain_reload_compiler()
tfm_toolchain_reload_compiler()

# tfm_s specific compile and link options
add_library(tfm_s_build_flags INTERFACE)

# BL2 specific compile and link options
add_library(bl2_build_flags INTERFACE)

# BL1 specific compile and link options
add_library(bl1_build_flags INTERFACE)

# Behaviour for handling scatter files is so wildly divergent between compilers
# that this macro is required.
macro(target_add_scatter_file target)
    target_link_options(${target}
        PRIVATE
        --config $<TARGET_OBJECTS:${target}_scatter>
    )

    add_library(${target}_scatter OBJECT)
    foreach(scatter_file ${ARGN})
        target_sources(${target}_scatter
            PRIVATE
                ${scatter_file}
        )
        # Cmake cannot use generator expressions in the
        # set_source_file_properties command, so instead we just parse the regex
        # for the filename and set the property on all files, regardless of if
        # the generator expression would evaluate to true or not.
        string(REGEX REPLACE ".*>:(.*)>$" "\\1" SCATTER_FILE_PATH "${scatter_file}")
        set_source_files_properties(${SCATTER_FILE_PATH}
            PROPERTIES
            LANGUAGE C
        )
    endforeach()

    add_dependencies(${target}
        ${target}_scatter
    )

    set_target_properties(${target} PROPERTIES LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        platform_region_defs
        psa_interface
        tfm_config
    )

    target_compile_options(${target}_scatter
        PRIVATE
            --preprocess=sn $<TARGET_OBJECTS:${target}_scatter>
    )
endmacro()

macro(add_convert_to_bin_target target)
    get_target_property(bin_dir ${target} RUNTIME_OUTPUT_DIRECTORY)

    add_custom_target(${target}_bin
        SOURCES ${bin_dir}/${target}.bin
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.bin
        DEPENDS ${target}
        COMMAND ielftool
            --silent
            --bin $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.bin
    )

    add_custom_target(${target}_elf
        SOURCES ${bin_dir}/${target}.elf
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.elf
        DEPENDS ${target}
        COMMAND ielftool
            --silent
            $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.elf
    )

    add_custom_target(${target}_hex
        SOURCES ${bin_dir}/${target}.hex
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND ielftool
            --silent
            --ihex $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.hex
    )

    add_custom_target(${target}_binaries
        ALL
        DEPENDS ${target}_bin
        DEPENDS ${target}_elf
        DEPENDS ${target}_hex
    )
endmacro()

macro(target_share_symbols target)
    get_target_property(TARGET_TYPE ${target} TYPE)
    if (NOT TARGET_TYPE STREQUAL "EXECUTABLE")
        message(FATAL_ERROR "${target} is not an executable. Symbols cannot be shared from libraries.")
    endif()

    foreach(symbol_file ${ARGN})
        FILE(STRINGS ${symbol_file} SYMBOLS
            LENGTH_MINIMUM 1
        )
        list(APPEND KEEP_SYMBOL_LIST ${SYMBOLS})
    endforeach()

    set(IAR_STEERING_FILE ${KEEP_SYMBOL_LIST})

    list(TRANSFORM IAR_STEERING_FILE PREPEND "show ")
    list(TRANSFORM IAR_STEERING_FILE APPEND " \n")
    list(INSERT IAR_STEERING_FILE 0 "hide *\n")
    string(REPLACE ";" "" IAR_STEERING_FILE ${IAR_STEERING_FILE})
    file( GENERATE OUTPUT "$<TARGET_FILE_DIR:${target}>/iar_steering_file" CONTENT "${IAR_STEERING_FILE}")

    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_IAR_SYMEXPORT}
        ARGS --edit $<TARGET_FILE_DIR:${target}>/iar_steering_file $<TARGET_FILE:${target}> $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
    )

    # Force the target to not remove the symbols if they're unused.
    list(TRANSFORM KEEP_SYMBOL_LIST PREPEND --keep=)
    target_link_options(${target}
        PRIVATE
            ${KEEP_SYMBOL_LIST}
    )
endmacro()

macro(target_link_shared_code target)
    get_target_property(TARGET_SOURCE_DIR ${target} SOURCE_DIR)

    foreach(symbol_provider ${ARGN})
        if (TARGET ${symbol_provider})
            get_target_property(SYMBOL_PROVIDER_TYPE ${symbol_provider} TYPE)
            if (NOT SYMBOL_PROVIDER_TYPE STREQUAL "EXECUTABLE")
                message(FATAL_ERROR "${symbol_provider} is not an executable. Symbols cannot be shared from libraries.")
            endif()
        endif()

        add_dependencies(${target} ${symbol_provider})
        target_link_options(${target} PRIVATE LINKER:$<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX})
    endforeach()
endmacro()

macro(compiler_create_shared_code TARGET SHARED_SYMBOL_TEMPLATE)
    message(FATAL_ERROR "Code sharing support is not implemented by IAR.")
endmacro()

macro(compiler_link_shared_code TARGET SHARED_CODE_PATH ORIG_TARGET LIB_LIST)
    message(FATAL_ERROR "Code sharing support is not implemented by IAR.")
endmacro()
