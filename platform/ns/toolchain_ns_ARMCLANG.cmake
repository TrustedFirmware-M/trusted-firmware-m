#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

SET(CMAKE_SYSTEM_NAME Generic)

# Detect the compiler ABI without linking a bare-metal executable.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE    arm-none-eabi)
endif()

set(CMAKE_ASM_COMPILER armclang)
set(CMAKE_C_COMPILER   armclang)
set(CMAKE_CXX_COMPILER armclang)

set(CMAKE_C_STANDARD   11)

set(CMAKE_ASM_COMPILER_TARGET arm-${CROSS_COMPILE})
set(CMAKE_C_COMPILER_TARGET   arm-${CROSS_COMPILE})
set(CMAKE_CXX_COMPILER_TARGET arm-${CROSS_COMPILE})

# Manually set --target= due to https://gitlab.kitware.com/cmake/cmake/-/issues/19963
set(CMAKE_ASM_FLAGS "--target=${CMAKE_ASM_COMPILER_TARGET}")

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not initialised at this moment so do it manually
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION)
string(REGEX MATCH "([0-9]+\.[0-9]+)" CMAKE_C_COMPILER_VERSION "${CMAKE_C_COMPILER_VERSION}")
set(CMAKE_C_COMPILER_VERSION ${CMAKE_MATCH_1})

if (CMAKE_C_COMPILER_VERSION VERSION_LESS 6.21)
    message(FATAL_ERROR "Please select newer Arm compiler version 6.21 or later")
endif()

include(mcpu_features)

add_compile_options(
    -Wno-ignored-optimization-argument
    -Wno-unused-command-line-argument
    -Wall
    # Don't error when the MBEDTLS_NULL_ENTROPY warning is shown
    -Wno-error=cpp
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -funsigned-char
    -masm=gnu
    -g
    $<$<BOOL:${CONFIG_TFM_WARNINGS_ARE_ERRORS}>:-Werror>
)

# Translate MCPU features to armlink sysntax
# armlink doesn't support "+nodsp"
string(REGEX REPLACE "\\+nodsp"         ""          TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nofp"          ".no_fp"    TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nomve\\.fp"    ".no_mvefp" TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")
string(REGEX REPLACE "\\+nomve"         ".no_mve"   TFM_SYSTEM_PROCESSOR_FEATURED "${TFM_SYSTEM_PROCESSOR_FEATURED}")

add_link_options(
    --cpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    --info=summarysizes,sizes,totals,unused,veneers
    --strict
    --symbols
    --xref
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

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    add_compile_options(-mfloat-abi=hard)
    if (CONFIG_TFM_ENABLE_FP)
        if (NOT TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
            # setting the -mfpu option disables the floating point mve, generic +fp.dp is used instead
            add_compile_options(-mfpu=${CONFIG_TFM_FP_ARCH})
        endif()
        # armasm and armlink have the same option "--fpu" and are both used to
        # specify the target FPU architecture. So the supported FPU architecture
        # names can be shared by armasm and armlink.
        add_link_options(--fpu=${CONFIG_TFM_FP_ARCH_ASM})
    endif()
else()
    add_compile_options(-mfpu=softvfp)
    add_link_options(--fpu=SoftVFP)
endif()

set(CMAKE_C_FLAGS_MINSIZEREL "-Oz -DNDEBUG")

# Specify the scatter file used to link `target`.
# Behaviour for handling scatter files is so wildly divergent between compilers
# that this macro is required.
#
# Vendor platform can set a scatter file as property INTERFACE_LINK_DEPENDS of platform_ns.
# `target` can fetch the scatter file from platform_ns.
#
# Alternatively, NS build can call target_add_scatter_file() with the install directory of
# scatter files.
#     target_add_scatter_file(target, install_dir)
#
# target_add_scatter_file() fetch a scatter file from the install directory.
macro(target_add_scatter_file target)

    # Try if scatter_file is passed from platform_ns
    get_target_property(scatter_file
                        platform_ns
                        INTERFACE_LINK_DEPENDS
    )

    # If scatter_file is not passed from platform_ns
    # Try if any scatter file is exported in install directory
    # The intall directory is passed as an optinal argument
    if(${scatter_file} STREQUAL "scatter_file-NOTFOUND")
        set(install_dir ${ARGN})
        list(LENGTH install_dir nr_install_dir)

        # If nr_install_dir == 1, search for sct file under install dir
        if(${nr_install_dir} EQUAL 1)
            file(GLOB scatter_file "${install_dir}/*.sct")
        endif()
    endif()

    if(NOT EXISTS ${scatter_file})
        message(FATAL_ERROR "Unable to find NS scatter file ${scatter_file}")
    endif()

    add_library(${target}_scatter OBJECT)
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

    target_link_libraries(${target}_scatter
        PRIVATE
            platform_region_defs
    )

    target_compile_options(${target}_scatter PRIVATE -E -xc)

    target_link_options(${target} PRIVATE --scatter=$<TARGET_OBJECTS:${target}_scatter>)
    add_dependencies(${target} ${target}_scatter)
    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)
endmacro()

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
        COMMAND fromelf --elf         $<TARGET_FILE:${target}> --output=${bin_dir}/${target}.elf
        COMMAND fromelf --i32combined $<TARGET_FILE:${target}> --output=${bin_dir}/${target}.hex
    )

    add_imported_target(${target}_hex ${target}_bin "${bin_dir}/${target}.hex")
endmacro()
