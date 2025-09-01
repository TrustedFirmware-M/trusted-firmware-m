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

# Specify the cross compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_C_STANDARD 99)

set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_FORCED TRUE)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_CXX_STANDARD 11)

if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE    arm-none-eabi CACHE STRING "Cross-compiler prefix")
endif()
set(CMAKE_C_COMPILER_TARGET ${CROSS_COMPILE})
set(CMAKE_ASM_COMPILER_TARGET ${CROSS_COMPILE})

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not initialised at this moment so do it manually
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION )
if (CMAKE_C_COMPILER_VERSION VERSION_LESS 18.1.3)
    message(FATAL_ERROR "Please use newer ATfE toolchain version starting from 18.1.3")
elseif(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 21.0.0)
    message(FATAL_ERROR "ATfE compiler versions 21.0.0 and above are no supported yet")
endif()

# ===================== Set toolchain CPU and Arch =============================

include(mcpu_features)

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
    # Strip /workspace/
    -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
    # Strip /workspace/trusted-firmware-m
    -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
)

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

add_link_options(
    -mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
    LINKER:--print-memory-usage
    LINKER:-ldummyhost
    LINKER:--Map=bin/tfm_ns.map
)

if (CONFIG_TFM_FLOAT_ABI)
    add_compile_options(-mfloat-abi=${CONFIG_TFM_FLOAT_ABI})
    add_link_options(-mfloat-abi=${CONFIG_TFM_FLOAT_ABI})
endif()

if (CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE_FP)
    add_compile_options(-mfpu=${CONFIG_TFM_FP_ARCH})
    add_link_options(-mfpu=${CONFIG_TFM_FP_ARCH})
else()
    add_compile_options(-mfpu=none)
    add_link_options(-mfpu=none)
endif()

if (CMAKE_C_COMPILER_VERSION VERSION_LESS 20.0.0)
    add_link_options(LINKER:-lcrt0)
endif()

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
            file(GLOB scatter_file "${install_dir}/*.ldc")
        endif()
    endif()

    if(NOT EXISTS ${scatter_file})
        message(FATAL_ERROR "Unable to find NS scatter file ${scatter_file}")
    endif()

    add_library(${target}_scatter OBJECT)
    target_sources(${target}_scatter PRIVATE ${scatter_file})

    # Cmake cannot use generator expressions in the
    # set_source_file_properties command, so instead we just parse the regex
    # for the filename and set the property on all files, regardless of if
    # the generator expression would evaluate to true or not.
    string(REGEX REPLACE ".*>:(.*)>$" "\\1" SCATTER_FILE_PATH "${scatter_file}")
    set_source_files_properties(${SCATTER_FILE_PATH}
        PROPERTIES
        LANGUAGE C
        KEEP_EXTENSION True # Avoid *.o extension for the preprocessed file
    )

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter PRIVATE platform_region_defs)

    target_compile_options(${target}_scatter PRIVATE -E -xc)

    target_link_options(${target} PRIVATE -T $<TARGET_OBJECTS:${target}_scatter>)

    add_dependencies(${target} ${target}_scatter)

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
