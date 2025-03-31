#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

set(CMAKE_SYSTEM_NAME Generic)

# Specify the cross compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_ASM_COMPILER_FORCED TRUE)

if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE    arm-none-eabi CACHE STRING "Cross-compiler prefix")
endif()
set(CMAKE_C_COMPILER_TARGET ${CROSS_COMPILE})
set(CMAKE_ASM_COMPILER_TARGET ${CROSS_COMPILE})

set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/set_extensions.cmake)

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
    if(TFM_SYSTEM_DSP)
        string(APPEND TFM_SYSTEM_ARCHITECTURE "+dsp")
    endif()
    set(CMAKE_C_FLAGS        "-march=${TFM_SYSTEM_ARCHITECTURE}")
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
set(BL1_LINKER_CP_OPTION -mfloat-abi=soft)

set(BL2_COMPILER_CP_FLAG -mfloat-abi=soft)
set(BL2_LINKER_CP_OPTION -mfloat-abi=soft)

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
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
    LINKER:--print-memory-usage
    LINKER:-lcrt0 -ldummyhost
    LINKER:--Map=bin/tfm_ns.map
)

#add_compile_definitions($<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8.1-m.main>:__ARM_ARCH_8_1M_MAIN__=1>)

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
        KEEP_EXTENSION True # Avoid *.o extension for the preprocessed file
    )

    target_link_libraries(${target}_scatter PRIVATE platform_region_defs)

    target_compile_options(${target}_scatter PRIVATE -E -xc)

    target_link_options(${target} PRIVATE -T $<TARGET_OBJECTS:${target}_scatter>)

    add_dependencies(${target} ${target}_scatter)
    set_target_properties(${target} PROPERTIES LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

endmacro()

# Macro for converting the output *.axf file to finary files: bin, elf, hex
macro(add_convert_to_bin_target target)
    get_target_property(bin_dir ${target} RUNTIME_OUTPUT_DIRECTORY)

    add_custom_target(${target}_bin
        SOURCES ${bin_dir}/${target}.bin
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.bin
        DEPENDS ${target}
        COMMAND ${CMAKE_OBJCOPY}
            -O binary $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.bin
    )

    add_custom_target(${target}_elf
        SOURCES ${bin_dir}/${target}.elf
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.elf
        DEPENDS ${target}
        COMMAND ${CMAKE_OBJCOPY}
            -O elf32-littlearm $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.elf
    )

    add_custom_target(${target}_hex
        SOURCES ${bin_dir}/${target}.hex
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND ${CMAKE_OBJCOPY}
            -O ihex $<TARGET_FILE:${target}>
            ${bin_dir}/${target}.hex
    )

    add_custom_target(${target}_binaries
        ALL
        DEPENDS ${target}_bin
        DEPENDS ${target}_elf
        DEPENDS ${target}_hex
    )
endmacro()
