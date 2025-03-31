#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

set(CMAKE_SYSTEM_NAME Generic)

# Specify the cross compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${CROSS_COMPILE})

set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${CROSS_COMPILE})

set(LINKER_VENEER_OUTPUT_FLAG -Wl,--cmse-implib,--out-implib=)
set(COMPILER_CMSE_FLAG -mcmse -mfix-cmse-cve-2021-35465)

set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/cmake/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not guaranteed to be defined.
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE LLVM_VERSION )
if (LLVM_VERSION VERSION_LESS 18.1.3)
    message(FATAL_ERROR "Please use newer LLVM compiler version starting from 18.1.3")
endif()

# ===================== Set toolchain CPU and Arch =============================
# -mcpu gives better optimisation than -march so -mcpu shall be in preference

if (TFM_SYSTEM_PROCESSOR)
    if(TFM_SYSTEM_DSP)
        string(APPEND TFM_SYSTEM_PROCESSOR "+dsp")
    else()
        string(APPEND TFM_SYSTEM_PROCESSOR "+nodsp")
    endif()
    if(CONFIG_TFM_ENABLE_FP)
        string(APPEND TFM_SYSTEM_PROCESSOR "+fp")
    else()
        string(APPEND TFM_SYSTEM_PROCESSOR "+nofp")
    endif()

    set(CMAKE_C_FLAGS        "-mcpu=${TFM_SYSTEM_PROCESSOR}")
    set(CMAKE_ASM_FLAGS      "-mcpu=${TFM_SYSTEM_PROCESSOR}")
else()
    if(CONFIG_TFM_ENABLE_FP)
        string(APPEND TFM_SYSTEM_ARCHITECTURE "+fp")
    endif()
    if(NOT TFM_SYSTEM_DSP)
        string(APPEND TFM_SYSTEM_ARCHITECTURE "+nodsp")
    endif()
    set(CMAKE_C_FLAGS        "-march=${TFM_SYSTEM_ARCHITECTURE}")
    set(CMAKE_CXX_FLAGS      "-march=${TFM_SYSTEM_ARCHITECTURE}")
    set(CMAKE_ASM_FLAGS      "-march=${TFM_SYSTEM_ARCHITECTURE}")
    set(CMAKE_ASM_CPU_FLAG  ${TFM_SYSTEM_ARCHITECTURE})
endif()

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(COMPILER_CP_FLAG -mfloat-abi=hard)
    set(LINKER_CP_OPTION -mfloat-abi=hard)
    if (CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE_FP)
        set(COMPILER_CP_FLAG -mfloat-abi=hard -mfpu=${CONFIG_TFM_FP_ARCH})
        set(LINKER_CP_OPTION -mfloat-abi=hard -mfpu=${CONFIG_TFM_FP_ARCH})
    endif()
else()
    set(COMPILER_CP_FLAG -mfloat-abi=soft)
    set(LINKER_CP_OPTION -mfloat-abi=soft)
endif()

set(BL1_COMPILER_CP_FLAG -mfloat-abi=soft)
set(BL1_LINKER_CP_OPTION -mfloat-abi=soft -lcrt0 -ldummyhost)

set(BL2_COMPILER_CP_FLAG -mfloat-abi=soft)
set(BL2_LINKER_CP_OPTION -mfloat-abi=soft -lcrt0 -ldummyhost)

file(REAL_PATH "${CMAKE_SOURCE_DIR}/../" TOP_LEVEL_PROJECT_DIR)

add_compile_options(
     -Wno-ignored-optimization-argument
     -Wno-unused-command-line-argument
     -Wall
     -Wno-error=cpp
     -c
     -fdata-sections
     -ffunction-sections
     -fno-builtin
     -fshort-enums
     -fshort-wchar
     -funsigned-char
     # Strip /workspace/
     -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
     # Strip /workspace/trusted-firmware-m
     -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
     -std=c99
)

# Pointer Authentication Code and Branch Target Identification (PACBTI) Options
# Not currently supported for LLVM.
if(NOT ${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_DISABLED)
    message(FATAL_ERROR "BRANCH_PROTECTION NOT supported for LLVM")
endif()

add_link_options(
    -lclang_rt.builtins   # needed for  __aeabi_memclr4(), __aeabi_memclr8(), __aeabi_memcpy4()
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
)

if(NOT CONFIG_TFM_MEMORY_USAGE_QUIET)
    add_link_options(LINKER:--print-memory-usage)
endif()

# Macro for adding scatter files. Supports multiple files
macro(target_add_scatter_file target)
    target_link_options(${target} PRIVATE -T $<TARGET_OBJECTS:${target}_scatter>)

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
            KEEP_EXTENSION True # Don't use .o extension for the preprocessed file
        )
    endforeach()

    add_dependencies(${target} ${target}_scatter)

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        platform_region_defs
        psa_interface
        tfm_config
    )

    target_compile_options(${target}_scatter PRIVATE -E -P -xc)
endmacro()

# Macro for converting the output *.axf file to finary files: bin, elf, hex
macro(add_convert_to_bin_target target)
    get_target_property(bin_dir ${target} RUNTIME_OUTPUT_DIRECTORY)
    add_custom_target(${target}_bin
        ALL DEPENDS ${target}
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${target}> ${bin_dir}/${target}.bin
        COMMAND ${CMAKE_OBJCOPY} -O elf32-littlearm $<TARGET_FILE:${target}> ${bin_dir}/${target}.elf
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${target}> ${bin_dir}/${target}.hex
    )
endmacro()

# Set of macrots for sharing code between BL2 and RunTime, targeted for sharing MbedTLS library
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

    set(STRIP_SYMBOL_KEEP_LIST ${KEEP_SYMBOL_LIST})

    # Force the target to not remove the symbols if they're unused.
    list(TRANSFORM KEEP_SYMBOL_LIST PREPEND "-Wl,--undefined=")
    target_link_options(${target}
        PRIVATE
            ${KEEP_SYMBOL_LIST}
    )

    list(TRANSFORM STRIP_SYMBOL_KEEP_LIST PREPEND  --keep-symbol=)
    # strip all the symbols except those proveded as arguments
    add_custom_target(${target}_shared_symbols
        COMMAND ${CMAKE_OBJCOPY}
            $<TARGET_FILE:${target}>
            --wildcard ${STRIP_SYMBOL_KEEP_LIST}
            --strip-all
            $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
    )

    # Ensure ${target} is built before $<TARGET_FILE:${target}> is used to generate ${target}_shared_symbols
    add_dependencies(${target}_shared_symbols ${target})
    # Allow the global clean target to rm the ${target}_shared_symbols created
    set_target_properties(${target}_shared_symbols PROPERTIES
        ADDITIONAL_CLEAN_FILES $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
    )
endmacro()

macro(target_link_shared_code target)
    foreach(symbol_provider ${ARGN})
        if (TARGET ${symbol_provider})
            get_target_property(SYMBOL_PROVIDER_TYPE ${symbol_provider} TYPE)
            if (NOT SYMBOL_PROVIDER_TYPE STREQUAL "EXECUTABLE")
                message(FATAL_ERROR "${symbol_provider} is not an executable. Symbols cannot be shared from libraries.")
            endif()
        endif()

        # Ensure ${symbol_provider}_shared_symbols is built before ${target}
        add_dependencies(${target} ${symbol_provider}_shared_symbols)
        # ${symbol_provider}_shared_symbols - a custom target is always considered out-of-date
        # To only link when necessary, depend on ${symbol_provider} instead
        set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${symbol_provider}>)
        target_link_options(${target} PRIVATE LINKER:--just-symbols $<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX})
    endforeach()
endmacro()

macro(target_strip_symbols target)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --strip-symbol=)

    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${target}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${target}>
    )
endmacro()

macro(target_strip_symbols_from_dependency target dependency)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --strip-symbol=)

    add_custom_command(
        TARGET ${target}
        PRE_LINK
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${dependency}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${dependency}>
    )
endmacro()

macro(target_weaken_symbols target)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --weaken-symbol=)

    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${target}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${target}>
    )
endmacro()

macro(target_weaken_symbols_from_dependency target dependency)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --weaken-symbol=)

    add_custom_command(
        TARGET ${target}
        PRE_LINK
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${dependency}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${dependency}>
    )
endmacro()
