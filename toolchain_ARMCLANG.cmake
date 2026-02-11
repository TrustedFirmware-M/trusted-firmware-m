#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

SET(CMAKE_SYSTEM_NAME Generic)

# C++ support is not quaranted. This settings is to compile with RPi Pico SDK.
set(CMAKE_ASM_COMPILER armclang)
set(CMAKE_C_COMPILER   armclang)
set(CMAKE_CXX_COMPILER armclang)

set(CMAKE_C_STANDARD   11)

set(CMAKE_ASM_COMPILER_FORCED TRUE)
set(CMAKE_C_COMPILER_FORCED   TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

set(CMAKE_ASM_COMPILER_TARGET arm-${CROSS_COMPILE})
set(CMAKE_C_COMPILER_TARGET   arm-${CROSS_COMPILE})
set(CMAKE_CXX_COMPILER_TARGET arm-${CROSS_COMPILE})

set(LINKER_VENEER_OUTPUT_FLAG --import_cmse_lib_out=)

# Manually set --target= due to https://gitlab.kitware.com/cmake/cmake/-/issues/19963
set(CMAKE_ASM_FLAGS "--target=${CMAKE_ASM_COMPILER_TARGET}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(imported_target)

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/cmake/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not initialised at this moment so do it manually
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION)
string(REGEX MATCH "([0-9]+\.[0-9]+)" CMAKE_C_COMPILER_VERSION "${CMAKE_C_COMPILER_VERSION}")
set(CMAKE_C_COMPILER_VERSION ${CMAKE_MATCH_1})

if (CMAKE_C_COMPILER_VERSION VERSION_LESS 6.21)
    message(FATAL_ERROR "Please select newer Arm compiler version 6.21 or later")
endif()

if(NOT DEFINED CMAKE_OBJCOPY)
    set(CMAKE_OBJCOPY ${CROSS_COMPILE}-objcopy CACHE FILEPATH "Path to objcopy")
endif()

function(min_toolchain_version mcpu tool-version)
    if (${TFM_SYSTEM_PROCESSOR} MATCHES ${mcpu} AND
        ${CMAKE_C_COMPILER_VERSION} VERSION_LESS ${tool-version})
        message(FATAL_ERROR "-mcpu=${mcpu} is supported in ArmClang version ${tool-version} and later.\n"
                "Please upgrade your toolchain to a supported version from: "
                "https://developer.arm.com/products/software-development-tools/compilers/arm-compiler/downloads/version-6")
    endif()
endfunction()

# the lowest supported toolchian version for a specific cpu
min_toolchain_version("cortex-m52" "6.22.0")

include(mcpu_features)

add_compile_options(
    -Wall
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -fshort-enums
    -funsigned-char
    -nostdlib
    -masm=gnu
    # Strip /workspace/
    -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
    # Strip /workspace/trusted-firmware-m
    -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
    -g
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<BOOL:${CONFIG_TFM_WARNINGS_ARE_ERRORS}>>:-Werror>
)

# Translate MCPU features to armlink sysntax
# armlink doesn't support "+nodsp"
string(REGEX REPLACE "\\+nodsp"         ""          TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nofp"          ".no_fp"    TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nomve\\.fp"    ".no_mvefp" TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nomve"         ".no_mve"   TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")

add_link_options(
    --cpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    --strict
    --symbols
    --xref
    $<$<NOT:$<BOOL:${CONFIG_TFM_MEMORY_USAGE_QUIET}>>:--info=summarysizes,sizes,totals,unused,veneers>
    $<$<AND:$<VERSION_GREATER:${TFM_ISOLATION_LEVEL},1>,$<STREQUAL:"${TEST_PSA_API}","IPC">>:--no-merge>
    # Suppress link warnings that are consistant (and therefore hopefully harmless)
    # https://developer.arm.com/documentation/100074/0608/linker-errors-and-warnings/list-of-the-armlink-error-and-warning-messages
    # Empty region description
    --diag_suppress=6312
    # Ns section matches pattern
    --diag_suppress=6314
    # Duplicate input files
    --diag_suppress=6304
    # Pattern only matches removed unused sections.
    --diag_suppress=6329
)

# As BL2 does not use hardware FPU, specify '--fpu=SoftVFP' explicitly to use software
# library functions for BL2 to override any implicit FPU option, such as '--cpu' option.
# Because the implicit hardware FPU option enforces BL2 to initialize FPU but hardware FPU
# is not actually enabled in BL2, it will cause BL2 runtime fault.
set(BL2_COMPILER_CP_FLAG -mfpu=softvfp)
set(BL2_LINKER_CP_OPTION --fpu=SoftVFP)

set(BL1_COMPILER_CP_FLAG -mfpu=softvfp)
set(BL1_LINKER_CP_OPTION --fpu=SoftVFP)

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(COMPILER_CP_FLAG -mfloat-abi=hard)
    if (CONFIG_TFM_ENABLE_FP)
        if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
            # setting the -mfpu option disables the floating point mve, generic +fp.dp is used instead
            set(COMPILER_CP_FLAG -mfloat-abi=hard)
        else()
            set(COMPILER_CP_FLAG -mfpu=${CONFIG_TFM_FP_ARCH};-mfloat-abi=hard)
        endif()
        # armasm and armlink have the same option "--fpu" and are both used to
        # specify the target FPU architecture. So the supported FPU architecture
        # names can be shared by armasm and armlink.
        set(LINKER_CP_OPTION --fpu=${CONFIG_TFM_FP_ARCH_ASM})
    endif()
else()
    set(COMPILER_CP_FLAG -mfpu=softvfp)
    set(LINKER_CP_OPTION --fpu=SoftVFP)
endif()

set(CMAKE_C_FLAGS_MINSIZEREL "-Oz -DNDEBUG")

#
# Pointer Authentication Code and Branch Target Identification (PACBTI) Options
#
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
    if((TFM_SYSTEM_PROCESSOR MATCHES "cortex-m85") AND
        (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main"))
        message(NOTICE "BRANCH_PROTECTION enabled with: ${BRANCH_PROTECTION_OPTIONS}")

        string(APPEND CMAKE_C_FLAGS " -mbranch-protection=${BRANCH_PROTECTION_OPTIONS}")

        add_link_options(--library_security=pacbti-m)
    else()
        message(FATAL_ERROR "Your architecture does not support BRANCH_PROTECTION")
    endif()
endif()

# tfm_s specific compile and link options
add_library(tfm_s_build_flags INTERFACE)

# BL2 specific compile and link options
add_library(bl2_build_flags INTERFACE)

# BL1 specific compile and link options
add_library(bl1_build_flags INTERFACE)

# Macro for adding scatter files. Supports multiple files
macro(target_add_scatter_file target)
    target_link_options(${target} PRIVATE --scatter=$<TARGET_OBJECTS:${target}_scatter>)

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
        ALL
        SOURCES ${bin_dir}/${target}.bin
        SOURCES ${bin_dir}/${target}.elf
        SOURCES ${bin_dir}/${target}.hex
    )

    add_custom_command(
        OUTPUT ${bin_dir}/${target}.bin
        OUTPUT ${bin_dir}/${target}.elf
        OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND fromelf --bincombined $<TARGET_FILE:${target}> --output=${bin_dir}/${target}.bin
        COMMAND fromelf --elf $<TARGET_FILE:${target}> --output=${bin_dir}/${target}.elf
        COMMAND fromelf --i32combined $<TARGET_FILE:${target}> --output=${bin_dir}/${target}.hex
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

        # Force the target to not remove the symbols if they're unused.
        foreach(symbol ${SYMBOLS})
            target_link_options(${target} PRIVATE LINKER:--undefined=${symbol})
        endforeach()
    endforeach()

    # This is needed because the symbol file can contain functions that are not
    # defined in every build configuration so break the build.
    # The L6474E is: "Symbol referenced by --undefined or --undefined_and_export
    # switch could not be resolved by a static library."
    target_link_options(${target} PRIVATE --diag_warning 6474)

    # strip all the symbols except those provided as arguments
    add_custom_target(${target}_shared_symbols
        VERBATIM
        COMMAND fromelf --text -s $<TARGET_FILE:${target}> --output $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
        COMMAND tfm_gen_armclang_shared_symbols
            $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
            $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
            ${KEEP_SYMBOL_LIST}
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
        target_link_options(${target} PRIVATE LINKER:$<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX})
    endforeach()
endmacro()

# TODO we assume that arm-none-eabi-objcopy is available - since we're using
# armclang this isn't necessarily true here and below.
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
