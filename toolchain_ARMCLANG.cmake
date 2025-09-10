#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

SET(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER armclang)
set(CMAKE_CXX_COMPILER armclang)
set(CMAKE_ASM_COMPILER armclang)

set(LINKER_VENEER_OUTPUT_FLAG --import_cmse_lib_out=)
set(COMPILER_CMSE_FLAG $<$<COMPILE_LANGUAGE:C>:-mcmse>)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(imported_target)

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/cmake/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not guaranteed to be defined.
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE ARMCLANG_VERSION )
string(REGEX MATCH "([0-9]+\.[0-9]+)" ARMCLANG_VERSION "${ARMCLANG_VERSION}")
set(ARMCLANG_VERSION ${CMAKE_MATCH_1})

if(NOT DEFINED CMAKE_OBJCOPY)
    set(CMAKE_OBJCOPY ${CROSS_COMPILE}-objcopy CACHE FILEPATH "Path to objcopy")
endif()

if (DEFINED TFM_SYSTEM_PROCESSOR)
    set(CMAKE_SYSTEM_PROCESSOR       ${TFM_SYSTEM_PROCESSOR})

    if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
        if(NOT CONFIG_TFM_ENABLE_MVE)
            string(APPEND CMAKE_SYSTEM_PROCESSOR "+nomve")
        endif()
        if((NOT TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m85")
            AND (NOT CONFIG_TFM_ENABLE_MVE_FP)
            AND CONFIG_TFM_ENABLE_MVE
            AND CONFIG_TFM_ENABLE_FP)
                string(APPEND CMAKE_SYSTEM_PROCESSOR "+nomve.fp")
        endif()
    endif()

    if (DEFINED TFM_SYSTEM_DSP)
        if(NOT TFM_SYSTEM_DSP)
            string(APPEND CMAKE_SYSTEM_PROCESSOR "+nodsp")
        endif()
    endif()

    # ARMCLANG specifies that '+nofp' is available on following M-profile cpus:
    # 'cortex-m4', 'cortex-m7', 'cortex-m33', 'cortex-m35p', 'cortex-m55' and 'cortex-m85'.
    # Build fails if other M-profile cpu, such as 'cortex-m23', is added with '+nofp'.
    # Explicitly list those cpu to align with ARMCLANG description.
    if (NOT CONFIG_TFM_ENABLE_FP AND
        (TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m4"
        OR TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m7"
        OR TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m33"
        OR TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m35p"
        OR TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m55"
        OR TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m85"))
            string(APPEND CMAKE_SYSTEM_PROCESSOR "+nofp")
    endif()
endif()

# CMAKE_SYSTEM_ARCH is an ARMCLANG CMAKE internal variable, used to set
# compile and linker flags up until CMake 3.21 where CMP0123 was introduced:
# https://cmake.org/cmake/help/latest/policy/CMP0123.html
# Another use of this variable is to statisfy a requirement for ARMCLANG to
# set either the target CPU or the Architecture. This variable needs to be
# set to allow targeting architectures without a specific CPU.
set(CMAKE_SYSTEM_ARCH            ${TFM_SYSTEM_ARCHITECTURE})

set(CMAKE_C_COMPILER_TARGET      arm-${CROSS_COMPILE})
set(CMAKE_CXX_COMPILER_TARGET    arm-${CROSS_COMPILE})
set(CMAKE_ASM_COMPILER_TARGET    arm-${CROSS_COMPILE})

if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
    # These three feature options are the only ones armlink accepts
    if(CONFIG_TFM_ENABLE_MVE_FP)
        string(APPEND CMAKE_SYSTEM_ARCH "+mve.fp")
    elseif(CONFIG_TFM_ENABLE_MVE)
        string(APPEND CMAKE_SYSTEM_ARCH "+mve")
    elseif(TFM_SYSTEM_DSP)
        string(APPEND CMAKE_SYSTEM_ARCH "+dsp")
    endif()

    # Generic fp extension names to be used instead of -mfpu
    # +fp/fpv5-sp-d16 is not handled as it is the default
    if(CONFIG_TFM_ENABLE_FP)
        if (CONFIG_TFM_FP_ARCH STREQUAL "fpv5-d16")
            string(APPEND CMAKE_SYSTEM_ARCH "+fp.dp")
        endif()
    else()
        string(APPEND CMAKE_SYSTEM_ARCH "+nofp")
    endif()
endif()

if(TFM_SYSTEM_DSP AND (NOT TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main"))
    string(APPEND CMAKE_SYSTEM_ARCH "+dsp")
endif()

# Cmake's ARMClang support has several issues with compiler validation. To
# avoid these, we set the list of supported -mcpu and -march variables to
# the ones we intend to use so that the validation will never fail.
include(Compiler/ARMClang)
set(CMAKE_C_COMPILER_PROCESSOR_LIST ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_C_COMPILER_ARCH_LIST ${CMAKE_SYSTEM_ARCH})
set(CMAKE_CXX_COMPILER_PROCESSOR_LIST ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_CXX_COMPILER_ARCH_LIST ${CMAKE_SYSTEM_ARCH})
set(CMAKE_ASM_COMPILER_PROCESSOR_LIST ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_ASM_COMPILER_ARCH_LIST ${CMAKE_SYSTEM_ARCH})

add_compile_options(
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wno-ignored-optimization-argument>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wno-unused-command-line-argument>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wall>
    # Don't error when the MBEDTLS_NULL_ENTROPY warning is shown
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wno-error=cpp>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-c>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fdata-sections>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-ffunction-sections>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fno-builtin>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fshort-enums>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fshort-wchar>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-funsigned-char>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-masm=auto>
    $<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-nostdlib>
    $<$<COMPILE_LANGUAGE:C>:-std=c99>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>
    $<$<COMPILE_LANGUAGE:ASM>:-masm=armasm>
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<BOOL:${TFM_DEBUG_SYMBOLS}>>:-g>
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<BOOL:${TFM_DEBUG_SYMBOLS}>>:-g>
    $<$<AND:$<COMPILE_LANGUAGE:C,CXX>,$<BOOL:${CONFIG_TFM_WARNINGS_ARE_ERRORS}>>:-Werror>
)

add_link_options(
    ${MEMORY_USAGE_FLAG}
    --strict
    --symbols
    --xref
    $<$<AND:$<VERSION_GREATER:${TFM_ISOLATION_LEVEL},1>,$<STREQUAL:"${TEST_PSA_API}","IPC">>:--no-merge>
    # Suppress link warnings that are consistant (and therefore hopefully
    # harmless)
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

if(CONFIG_TFM_MEMORY_USAGE_QUIET)
    set(MEMORY_USAGE_FLAG "")
else()
    set(MEMORY_USAGE_FLAG --info=summarysizes,sizes,totals,unused,veneers)
endif()

if (ARMCLANG_VERSION VERSION_LESS 6.13)
    message(FATAL_ERROR "Please select newer Arm compiler version starting from 6.13.")
endif()

if (ARMCLANG_VERSION VERSION_GREATER_EQUAL 6.15 AND
    ARMCLANG_VERSION VERSION_LESS 6.18)
    message(FATAL_ERROR "Armclang 6.15~6.17 may cause MemManage fault."
                        " This defect has been fixed since Armclang 6.18."
                        " See [SDCOMP-59788] in Armclang 6.18 release note for details."
                        " Please use other Armclang versions instead.")
endif()

if (CMAKE_SYSTEM_PROCESSOR)
    set(CMAKE_C_FLAGS "-mcpu=${CMAKE_SYSTEM_PROCESSOR}")
    set(CMAKE_CXX_FLAGS "-mcpu=${CMAKE_SYSTEM_PROCESSOR}")
    set(CMAKE_ASM_FLAGS "--target=${CMAKE_ASM_COMPILER_TARGET} -mcpu=${CMAKE_SYSTEM_PROCESSOR}")

    set(ARMLINK_MAPPED_OPTION "--cpu=${CMAKE_SYSTEM_PROCESSOR}")
    # But armlink doesn't support this +dsp syntax
    string(REGEX REPLACE "\\+nodsp"         ""          ARMLINK_MAPPED_OPTION "${ARMLINK_MAPPED_OPTION}")
    # And uses different syntax for +nofp, +nomve.fp, nomve
    string(REGEX REPLACE "\\+nofp"          ".no_fp"    ARMLINK_MAPPED_OPTION "${ARMLINK_MAPPED_OPTION}")
    string(REGEX REPLACE "\\+nomve\\.fp"    ".no_mvefp" ARMLINK_MAPPED_OPTION "${ARMLINK_MAPPED_OPTION}")
    string(REGEX REPLACE "\\+nomve"         ".no_mve"   ARMLINK_MAPPED_OPTION "${ARMLINK_MAPPED_OPTION}")

    set(CMAKE_C_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
    set(CMAKE_CXX_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
    set(CMAKE_ASM_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
else()
    set(CMAKE_C_FLAGS "-march=${CMAKE_SYSTEM_ARCH}")
    set(CMAKE_CXX_FLAGS "-march=${CMAKE_SYSTEM_ARCH}")
    set(CMAKE_ASM_FLAGS "--target=${CMAKE_ASM_COMPILER_TARGET} -march=${CMAKE_SYSTEM_ARCH}")

    set(ARMLINK_MAPPED_OPTION "--cpu=${CMAKE_SYSTEM_ARCH}")
    # Mapping the architecture name
    string(REGEX REPLACE "armv"         ""      ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")
    # Armlink uses --fpu option instead of the generic extension names
    string(REGEX REPLACE "\\+fp\\.dp"   ""      ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")
    string(REGEX REPLACE "\\+nofp"      ""      ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")
    # And different syntax for these features
    string(REGEX REPLACE "\\+mve\\.fp"  ".mve.fp" ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")
    string(REGEX REPLACE "\\+mve"       ".mve"  ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")
    string(REGEX REPLACE "\\+dsp"       ".dsp"  ARMLINK_MAPPED_OPTION   "${ARMLINK_MAPPED_OPTION}")

    set(CMAKE_C_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
    set(CMAKE_CXX_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
    set(CMAKE_ASM_LINK_FLAGS ${ARMLINK_MAPPED_OPTION})
endif()

set(BL2_COMPILER_CP_FLAG
    -mfpu=softvfp
)
# As BL2 does not use hardware FPU, specify '--fpu=SoftVFP' explicitly to use software
# library functions for BL2 to override any implicit FPU option, such as '--cpu' option.
# Because the implicit hardware FPU option enforces BL2 to initialize FPU but hardware FPU
# is not actually enabled in BL2, it will cause BL2 runtime fault.
set(BL2_LINKER_CP_OPTION --fpu=SoftVFP)

set(BL1_COMPILER_CP_FLAG
    -mfpu=softvfp
)
set(BL1_LINKER_CP_OPTION --fpu=SoftVFP)

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(COMPILER_CP_FLAG
        $<$<COMPILE_LANGUAGE:C>:-mfloat-abi=hard>
    )
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
    set(COMPILER_CP_FLAG
        -mfpu=softvfp
    )
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
    if(ARMCLANG_VERSION VERSION_LESS 6.18)
        message(FATAL_ERROR "Your compiler does not support BRANCH_PROTECTION")
    else()
        if((TFM_SYSTEM_PROCESSOR MATCHES "cortex-m85") AND
            (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main"))
            message(NOTICE "BRANCH_PROTECTION enabled with: ${BRANCH_PROTECTION_OPTIONS}")

            string(APPEND CMAKE_C_FLAGS " -mbranch-protection=${BRANCH_PROTECTION_OPTIONS}")
            string(APPEND CMAKE_CXX_FLAGS " -mbranch-protection=${BRANCH_PROTECTION_OPTIONS}")

            add_link_options(--library_security=pacbti-m)
        else()
            message(FATAL_ERROR "Your architecture does not support BRANCH_PROTECTION")
        endif()
    endif()
endif()

# Behaviour for handling scatter files is so wildly divergent between compilers
# that this macro is required.
macro(target_add_scatter_file target)
    target_link_options(${target}
        PRIVATE
        --scatter=$<TARGET_OBJECTS:${target}_scatter>
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
            KEEP_EXTENSION True # Don't use .o extension for the preprocessed file
        )
    endforeach()

    add_dependencies(${target}
        ${target}_scatter
    )

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        platform_region_defs
        psa_interface
        tfm_config
    )

    target_compile_options(${target}_scatter
        PRIVATE
            -E
            -xc
    )
endmacro()

macro(add_convert_to_bin_target target)
    get_target_property(bin_dir ${target} RUNTIME_OUTPUT_DIRECTORY)

    add_custom_target(${target}_bin
        SOURCES ${bin_dir}/${target}.bin
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.bin
        DEPENDS ${target}
        COMMAND fromelf
            --bincombined $<TARGET_FILE:${target}>
            --output=${bin_dir}/${target}.bin
    )

    add_custom_target(${target}_elf
        SOURCES ${bin_dir}/${target}.elf
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.elf
        DEPENDS ${target}
        COMMAND fromelf
            --elf $<TARGET_FILE:${target}>
            --output=${bin_dir}/${target}.elf
    )

    add_custom_target(${target}_hex_build
        SOURCES ${bin_dir}/${target}.hex
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND fromelf
            --i32combined $<TARGET_FILE:${target}>
            --output=${bin_dir}/${target}.hex
    )

    add_imported_target(${target}_hex ${target}_hex_build "${bin_dir}/${target}.hex")

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

    find_package(Python3)

    # strip all the symbols except those provided as arguments
    add_custom_target(${target}_shared_symbols
        VERBATIM
        COMMAND fromelf --text -s $<TARGET_FILE:${target}> --output $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
        COMMAND tfm_gen_armclang_shared_symbols
            $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
            $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
            ${KEEP_SYMBOL_LIST}
    )

    # Ensure ${target} is build before $<TARGET_FILE:${target}> is used to generate ${target}_shared_symbols
    add_dependencies(${target}_shared_symbols ${target})
    # Allow the global clean target to rm the ${target}_shared_symbols created
    set_target_properties(${target}_shared_symbols PROPERTIES
        ADDITIONAL_CLEAN_FILES $<TARGET_FILE_DIR:${target}>/${target}${CODE_SHARING_OUTPUT_FILE_SUFFIX}
    )

    # Force the target to not remove the symbols if they're unused.
    list(TRANSFORM KEEP_SYMBOL_LIST PREPEND --undefined=)
    target_link_options(${target}
        PRIVATE
            ${KEEP_SYMBOL_LIST}
            # This is needed because the symbol file can contain functions
            # that are not defined in every build configuration.
            # The L6474E is:
            # "Symbol referenced by --undefined or --undefined_and_export
            # switch could not be resolved by a static library."
            --diag_warning 6474
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

        # Ensure ${symbol_provider}_shared_symbols is built before ${target}
        add_dependencies(${target} ${symbol_provider}_shared_symbols)
        # ${symbol_provider}_shared_symbols - a custom target is always considered out-of-date
        # To only link when necessary, depend on ${symbol_provider} instead
        set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${symbol_provider}>)
        target_link_options(${target} PRIVATE LINKER:$<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX})
    endforeach()
endmacro()

macro(target_strip_symbols target)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --strip-symbol=)

    # TODO we assume that arm-none-eabi-objcopy is available - since we're using
    # armclang this isn't necessarily true.
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

    # TODO we assume that arm-none-eabi-objcopy is available - since we're using
    # armclang this isn't necessarily true.
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

    # TODO we assume that arm-none-eabi-objcopy is available - since we're using
    # armclang this isn't necessarily true.
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

    # TODO we assume that arm-none-eabi-objcopy is available - since we're using
    # armclang this isn't necessarily true.
    add_custom_command(
        TARGET ${target}
        PRE_LINK
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${dependency}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${dependency}>
    )
endmacro()
