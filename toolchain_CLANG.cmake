#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
#
# CMake toolchain file for "Arm Toolchain for Embedded"
# Download page: https://github.com/arm/arm-toolchain/releases
#
set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER_TARGET ${CROSS_COMPILE})

set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_FORCED TRUE)
set(CMAKE_ASM_COMPILER_TARGET ${CROSS_COMPILE})

# C++ support is not quaranted. This settings is to compile with RPi Pico SDK.
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(imported_target)

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/cmake/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not initialised at this moment so do it manually
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION )
if (CMAKE_C_COMPILER_VERSION VERSION_LESS 18.1.3)
    message(FATAL_ERROR "Please use newer ATfE toolchain version starting from 18.1.3")
elseif(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 21.0.0)
    message(FATAL_ERROR "ATfE compiler versions 21.0.0 and above are no supported yet")
endif()

include(mcpu_features)

# Compiler and linker optoins common to all modules

file(REAL_PATH "${CMAKE_SOURCE_DIR}/../" TOP_LEVEL_PROJECT_DIR)

add_compile_options(
    -fdiagnostics-color=always
    -Wno-ignored-optimization-argument
    -Wno-unused-command-line-argument
    -Wall
    -Wno-error=cpp
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -fshort-enums
    -fshort-wchar
    -funsigned-char
    -fno-exceptions
    -fno-rtti
    # Strip /workspace/
    -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
    # Strip /workspace/trusted-firmware-m
    -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
)

add_link_options(
    -mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
)

set(LINKER_VENEER_OUTPUT_FLAG -Wl,--cmse-implib,--out-implib=)

if(NOT CONFIG_TFM_MEMORY_USAGE_QUIET)
    add_link_options(LINKER:--print-memory-usage)
endif()

# A module (BL1, BL2, CP) specific addional compiler and linker optoins

set(BL1_COMPILER_CP_FLAG -mfloat-abi=soft -mfpu=none)
set(BL1_LINKER_CP_OPTION -mfpu=none)

set(BL2_COMPILER_CP_FLAG -mfloat-abi=soft -mfpu=none)
set(BL2_LINKER_CP_OPTION -mfpu=none)

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(COMPILER_CP_FLAG -mfloat-abi=hard)
    if (CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE_FP)
        set(COMPILER_CP_FLAG -mfloat-abi=hard -mfpu=${CONFIG_TFM_FP_ARCH})
    else()
        set(COMPILER_CP_FLAG -mfloat-abi=soft -mfpu=none)
    endif()
endif()

set(LINKER_CP_OPTION -lclang_rt.builtins -nostdlib)

if (CMAKE_C_COMPILER_VERSION VERSION_LESS 20.0.0)
   list(APPEND BL1_LINKER_CP_OPTION -lcrt0 -ldummyhost)
   list(APPEND BL2_LINKER_CP_OPTION -lcrt0 -ldummyhost)
else()
   list(APPEND BL1_LINKER_CP_OPTION -ldummyhost)
endif()

if(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 19.0.0)
   list(APPEND COMPILER_CP_FLAG -nostartfiles)
endif()

#
# Pointer Authentication Code and Branch Target Identification (PACBTI) Options
#
if(NOT ${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_DISABLED)
    if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
        if (${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_NONE)
            set(BRANCH_PROTECTION_OPTIONS "none")
        elseif(${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_STANDARD)
            set(BRANCH_PROTECTION_OPTIONS "standard")
        elseif(${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_PACRET)
            set(BRANCH_PROTECTION_OPTIONS "pac-ret")
        elseif(${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_PACRET_LEAF)
            set(BRANCH_PROTECTION_OPTIONS "pac-ret+leaf")
        elseif(${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_BTI)
            set(BRANCH_PROTECTION_OPTIONS "bti")
        endif()
        add_compile_options(-mbranch-protection=${BRANCH_PROTECTION_OPTIONS})
        message(NOTICE "BRANCH_PROTECTION enabled with: ${BRANCH_PROTECTION_OPTIONS}")
    else()
        message(FATAL_ERROR "Your architecture does not support BRANCH_PROTECTION")
    endif()
endif()

# Macro for adding scatter files. Supports multiple files
macro(target_add_scatter_file target)
    target_link_options(${target} PRIVATE -T $<TARGET_OBJECTS:${target}_scatter>)

    add_library(${target}_scatter OBJECT)
    foreach(scatter_file ${ARGN})
        target_sources(${target}_scatter PRIVATE ${scatter_file}
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
        ALL SOURCES ${bin_dir}/${target}.bin
        SOURCES ${bin_dir}/${target}.elf
        SOURCES ${bin_dir}/${target}.hex
    )

    add_custom_command(OUTPUT ${bin_dir}/${target}.bin
        OUTPUT ${bin_dir}/${target}.elf
        OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${target}> ${bin_dir}/${target}.bin
        COMMAND ${CMAKE_OBJCOPY} -O elf32-littlearm $<TARGET_FILE:${target}> ${bin_dir}/${target}.elf
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${target}> ${bin_dir}/${target}.hex
    )

    add_imported_target(${target}_hex ${target}_bin "${bin_dir}/${target}.hex")
endmacro()

# Set of macrots for sharing code between BL2 and RunTime, targeted for sharing MbedTLS library
macro(target_share_symbols target)
    get_target_property(TARGET_TYPE ${target} TYPE)
    if (NOT TARGET_TYPE STREQUAL "EXECUTABLE")
        message(FATAL_ERROR "${target} is not an executable. Symbols cannot be shared from libraries.")
    endif()

    foreach(symbol_file ${ARGN})
        FILE(STRINGS ${symbol_file} SYMBOLS LENGTH_MINIMUM 1)
        list(APPEND KEEP_SYMBOL_LIST ${SYMBOLS})
    endforeach()

    set(STRIP_SYMBOL_KEEP_LIST ${KEEP_SYMBOL_LIST})

    # Force the target to not remove the symbols if they're unused.
    list(TRANSFORM KEEP_SYMBOL_LIST PREPEND "-Wl,--undefined=")
    target_link_options(${target} PRIVATE ${KEEP_SYMBOL_LIST})

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
    list(TRANSFORM SYMBOL_LIST PREPEND --strip-symbol=)

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
