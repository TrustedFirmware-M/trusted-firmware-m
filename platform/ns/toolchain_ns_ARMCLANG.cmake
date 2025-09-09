#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

SET(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE    arm-none-eabi CACHE STRING "Cross-compiler prefix")
endif()

set(CMAKE_C_COMPILER armclang)
set(CMAKE_CXX_COMPILER armclang)
set(CMAKE_ASM_COMPILER armclang)

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not guaranteed to be defined.
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE ARMCLANG_VERSION )
string(REGEX MATCH "([0-9]+\.[0-9]+)" ARMCLANG_VERSION "${ARMCLANG_VERSION}")
set(ARMCLANG_VERSION ${CMAKE_MATCH_1})

if(NOT DEFINED CMAKE_OBJCOPY)
    set(CMAKE_OBJCOPY ${CROSS_COMPILE}-objcopy CACHE FILEPATH "Path to objcopy")
endif()

# Set compiler ID explicitly as it's not detected at this moment
set(CMAKE_C_COMPILER_ID ARMClang)

set(MEMORY_USAGE_FLAG --info=summarysizes,sizes,totals,unused,veneers)

if (DEFINED TFM_SYSTEM_PROCESSOR)
    set(CMAKE_SYSTEM_PROCESSOR       ${TFM_SYSTEM_PROCESSOR})

    if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
        if(NOT CONFIG_TFM_ENABLE_MVE)
            string(APPEND CMAKE_SYSTEM_PROCESSOR "+nomve")
        endif()
        if((TFM_SYSTEM_PROCESSOR STREQUAL "cortex-m55")
            AND (NOT CONFIG_TFM_ENABLE_MVE_FP)
            AND CONFIG_TFM_ENABLE_MVE
            AND CONFIG_TFM_ENABLE_FP)
                # With integer Helium, scalar FPU
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

# This flag is used to check if toolchain has fixed VLLDM vulnerability
# Check command will fail if C flags consist of keyword other than cpu/arch type.
set(CP_CHECK_C_FLAGS ${CMAKE_C_FLAGS})

if (CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(COMPILER_CP_C_FLAG "-mfloat-abi=hard")
    if (CONFIG_TFM_ENABLE_FP)
        if (TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
            # setting the -mfpu option disables the floating point mve, generic +fp.dp is used instead
            set(COMPILER_CP_C_FLAG "-mfloat-abi=hard")
            set(COMPILER_CP_ASM_FLAG "-mfloat-abi=hard")
        else()
            set(COMPILER_CP_C_FLAG "-mfloat-abi=hard -mfpu=${CONFIG_TFM_FP_ARCH}")
            set(COMPILER_CP_ASM_FLAG "-mfloat-abi=hard -mfpu=${CONFIG_TFM_FP_ARCH}")
        endif()
        # armasm and armlink have the same option "--fpu" and are both used to
        # specify the target FPU architecture. So the supported FPU architecture
        # names can be shared by armasm and armlink.
        set(LINKER_CP_OPTION "--fpu=${CONFIG_TFM_FP_ARCH_ASM}")
    endif()
else()
    set(COMPILER_CP_C_FLAG   "-mfpu=softvfp")
    set(COMPILER_CP_ASM_FLAG "-mfpu=softvfp")
    set(LINKER_CP_OPTION     "--fpu=SoftVFP")
endif()

string(APPEND CMAKE_C_FLAGS " " ${COMPILER_CP_C_FLAG})
string(APPEND CMAKE_CXX_FLAGS " " ${COMPILER_CP_C_FLAG})
string(APPEND CMAKE_ASM_FLAGS " " ${COMPILER_CP_ASM_FLAG})
string(APPEND CMAKE_C_LINK_FLAGS " " ${LINKER_CP_OPTION})
string(APPEND CMAKE_CXX_LINK_FLAGS " " ${LINKER_CP_OPTION})
string(APPEND CMAKE_ASM_LINK_FLAGS " " ${LINKER_CP_OPTION})

set(CMAKE_C_FLAGS_MINSIZEREL "-Oz -DNDEBUG")

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

    add_custom_target(${target}_hex
        SOURCES ${bin_dir}/${target}.hex
    )
    add_custom_command(OUTPUT ${bin_dir}/${target}.hex
        DEPENDS ${target}
        COMMAND fromelf
            --i32combined $<TARGET_FILE:${target}>
            --output=${bin_dir}/${target}.hex
    )

    add_custom_target(${target}_binaries
        ALL
        DEPENDS ${target}_bin
        DEPENDS ${target}_elf
        DEPENDS ${target}_hex
    )
endmacro()

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

    target_link_options(${target}
        PRIVATE
            --scatter=$<TARGET_OBJECTS:${target}_scatter>
    )

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        PRIVATE
            platform_region_defs
    )

    target_compile_options(${target}_scatter
        PRIVATE
            -E
            -xc
    )

    add_dependencies(${target} ${target}_scatter)

endmacro()
