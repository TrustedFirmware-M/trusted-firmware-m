#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(CMAKE_SYSTEM_NAME Generic)

find_program(CMAKE_C_COMPILER ${CROSS_COMPILE}-gcc)
if(CMAKE_C_COMPILER STREQUAL "CMAKE_C_COMPILER-NOTFOUND")
    message(FATAL_ERROR "Could not find compiler: '${CROSS_COMPILE}-gcc'")
endif()

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_C_STANDARD 11)

set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})

# C++ support is not quaranted. This settings is to compile with RPi Pico SDK.
find_program(CMAKE_CXX_COMPILER ${CROSS_COMPILE}-g++)
if(CMAKE_CXX_COMPILER STREQUAL "CMAKE_CXX_COMPILER-NOTFOUND")
    message(WARNING "Could not find compiler: '${CROSS_COMPILE}-g++'")
endif()

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
EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION)

if (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 12.2)
    message(FATAL_ERROR "Please use GNU Arm toolchain version 12.2.Rel1 or later")
endif()

function(min_toolchain_version mcpu gnu-version)
    if (${TFM_SYSTEM_PROCESSOR} MATCHES ${mcpu} AND
        ${CMAKE_C_COMPILER_VERSION} VERSION_LESS ${gnu-version})
        message(FATAL_ERROR "-mcpu=${mcpu} is supported in GNU Arm version ${gnu-version} and later.\n"
                "Please upgrade your toolchain to a supported version from: "
                "https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads")
    endif()
endfunction()

# the lowest supported GCC version for a specific cpu
min_toolchain_version("cortex-m85" "13.0.0")
min_toolchain_version("cortex-m52" "14.2.0")

include(mcpu_features)

file(REAL_PATH "${CMAKE_SOURCE_DIR}/../" TOP_LEVEL_PROJECT_DIR)

add_compile_options(
    -Wall
    -Wno-format
    -Warray-parameter
    -Wno-unused-but-set-variable
    -Wnull-dereference
    -Wno-error=incompatible-pointer-types
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -funsigned-char
    # Strip /workspace/
    -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
    # Strip /workspace/trusted-firmware-m
    -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
    -mthumb
    # Always enable debug symbols — this should not affect the final binary files
    -g
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<BOOL:${TFM_DEBUG_OPTIMISATION}>,$<CONFIG:Debug>>:-Og>
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<BOOL:${CONFIG_TFM_WARNINGS_ARE_ERRORS}>>:-Werror>
)

# Pointer Authentication Code and Branch Target Identification (PACBTI) Options
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

if(NOT ${CONFIG_TFM_BRANCH_PROTECTION_FEAT} STREQUAL BRANCH_PROTECTION_DISABLED)
    if(${CMAKE_C_COMPILER_VERSION} VERSION_LESS "15.3")
        message(FATAL_ERROR "Your compiler ${CMAKE_C_COMPILER_VERSION} does not support BRANCH_PROTECTION")
    else()
        if(((TFM_SYSTEM_PROCESSOR MATCHES "cortex-m52") OR
            (TFM_SYSTEM_PROCESSOR MATCHES "cortex-m85")) AND
            (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main"))

            message(NOTICE "BRANCH_PROTECTION enabled with: ${BRANCH_PROTECTION_OPTIONS}")
            add_compile_options(-mbranch-protection=${BRANCH_PROTECTION_OPTIONS})
            add_link_options(-mbranch-protection=${BRANCH_PROTECTION_OPTIONS})
        else()
            message(FATAL_ERROR "Your architecture does not support BRANCH_PROTECTION")
        endif()
   endif()
endif()

# Workaround to add diagnostics color while using Ninja generator.
# For reference: https://github.com/ninja-build/ninja/issues/174
if (CMAKE_GENERATOR STREQUAL "Ninja")
    add_compile_options(-fdiagnostics-color=always)
endif()

add_link_options(
    -mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
    LINKER:--no-wchar-size-warning
)

set(LINKER_VENEER_OUTPUT_FLAG -Wl,--cmse-implib,--out-implib=)

if(NOT CONFIG_TFM_MEMORY_USAGE_QUIET)
    add_link_options(LINKER:--print-memory-usage)
endif()

set(BL2_COMPILER_CP_FLAG -mfloat-abi=soft)
set(BL2_LINKER_CP_OPTION -mfloat-abi=soft)

set(BL1_COMPILER_CP_FLAG -mfloat-abi=soft)
set(BL1_LINKER_CP_OPTION -mfloat-abi=soft)

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

# tfm_s specific compile and link options
add_library(tfm_s_build_flags INTERFACE)

# BL2 specific compile and link options
add_library(bl2_build_flags INTERFACE)

# BL1 specific compile and link options
add_library(bl1_build_flags INTERFACE)

if (CONFIG_TFM_INCLUDE_STDLIBC)
    # newlib-nano (nano.specs) is the standard arm-none-eabi C library. A
    # picolibc-based GCC (e.g. the Zephyr SDK's arm-zephyr-eabi) has no
    # nano.specs and links its default C library (picolibc) on its own, so
    # only request nano.specs when the compiler actually provides it.
    execute_process(
        COMMAND ${CMAKE_C_COMPILER} -print-file-name=nano.specs
        OUTPUT_VARIABLE NANO_SPECS_PATH
        OUTPUT_STRIP_TRAILING_WHITESPACE)
    if (NOT NANO_SPECS_PATH STREQUAL "nano.specs")
        add_link_options(-specs=nano.specs -specs=nosys.specs)
    endif()
    add_compile_definitions(CONFIG_TFM_INCLUDE_STDLIBC)
else()
    add_link_options(-nostdlib)
    target_link_libraries(tfm_s_build_flags INTERFACE gcc)
    target_link_libraries(bl2_build_flags INTERFACE gcc)
    target_link_libraries(bl1_build_flags INTERFACE gcc)
endif()

# include the common toolchain file for common macros
include(toolchain_common)
include(toolchain_symbol_helpers)

# Function for adding scatter files. Supports multiple files
function(target_add_scatter_file target)
    target_link_options(${target} PRIVATE -T $<TARGET_OBJECTS:${target}_scatter>)

    _target_add_scatter_file(${target} ${ARGN})

    target_compile_options(${target}_scatter PRIVATE -E -P -xc)
endfunction()

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

function(target_link_shared_code target)
    _target_link_shared_code(${target} TRUE ${ARGN})
endfunction()
