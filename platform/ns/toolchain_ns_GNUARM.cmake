#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(CMAKE_SYSTEM_NAME Generic)

if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE    "arm-none-eabi" CACHE STRING "Cross-compiler prefix")
endif()

set(CMAKE_C_COMPILER ${CROSS_COMPILE}-gcc)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_C_STANDARD 99)

set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})

set(CMAKE_CXX_COMPILER ${CROSS_COMPILE}-g++)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_CXX_STANDARD 11)

# This variable name is a bit of a misnomer. The file it is set to is included
# at a particular step in the compiler initialisation. It is used here to
# configure the extensions for object files. Despite the name, it also works
# with the Ninja generator.
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_LIST_DIR}/set_extensions.cmake)

# CMAKE_C_COMPILER_VERSION is not guaranteed to be defined.
EXECUTE_PROCESS( COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION)

if (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 10.3.1)
    message(FATAL_ERROR "Please use GNU Arm toolchain version 10.3.1 or later")
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

# GNU Arm compiler version greater equal than *11.3.Rel1*
# has a linker issue that required system calls are missing,
# such as _read and _write. Add stub functions of required
# system calls to solve this issue.
#
# READONLY linker script attribute is not supported in older
# GNU Arm compilers. For these version the preprocessor will
# remove the READONLY string from the linker scripts.
if (CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 11.3.1)
    set(CONFIG_GNU_SYSCALL_STUB_ENABLED TRUE)
    set(CONFIG_GNU_LINKER_READONLY_ATTRIBUTE TRUE)
endif()

if(CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    add_compile_options(-mfloat-abi=hard)
    add_link_options(-mfloat-abi=hard)
    if(CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE_FP)
        add_compile_options(-mfpu=${CONFIG_TFM_FP_ARCH})
        add_link_options(-mfpu=${CONFIG_TFM_FP_ARCH})
    endif()
else()
    add_compile_options(-mfloat-abi=soft)
    add_link_options(-mfloat-abi=soft)
endif()

include(mcpu_features)

file(REAL_PATH "${CMAKE_SOURCE_DIR}/../" TOP_LEVEL_PROJECT_DIR)

add_compile_options(
    -Wall
    -Wno-format
    -Wno-unused-but-set-variable
    -Wnull-dereference
    -Wno-error=incompatible-pointer-types
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -fshort-enums
    -funsigned-char
    # Strip /workspace/
    -fmacro-prefix-map=${TOP_LEVEL_PROJECT_DIR}/=
    # Strip /workspace/trusted-firmware-m
    -fmacro-prefix-map=${CMAKE_SOURCE_DIR}/=
    -mthumb
    $<$<AND:$<COMPILE_LANGUAGE:C,CXX>,$<BOOL:${TFM_DEBUG_SYMBOLS}>>:-g>
    $<$<AND:$<COMPILE_LANGUAGE:C,CXX>,$<BOOL:${TFM_DEBUG_OPTIMISATION}>,$<CONFIG:Debug>>:-Og>
    $<$<AND:$<COMPILE_LANGUAGE:C,CXX>,$<BOOL:${CONFIG_TFM_WARNINGS_ARE_ERRORS}>>:-Werror>
)

add_link_options(
    -mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED}
    -specs=nano.specs
    -specs=nosys.specs
    LINKER:-check-sections
    LINKER:-fatal-warnings
    LINKER:--gc-sections
    LINKER:--no-wchar-size-warning
    LINKER:--print-memory-usage
)

# Specify the linker script used to link `target`.
# Behaviour for handling linker scripts is so wildly divergent between compilers
# that this macro is required.
#
# Vendor platform can set a linker script as property INTERFACE_LINK_DEPENDS of platform_ns.
# `target` can fetch the linker script from platform_ns.
#
# Alternatively, NS build can call target_add_scatter_file() with the install directory of
# linker script.
#     target_add_scatter_file(target, install_dir)
#
# target_add_scatter_file() fetch a linker script from the install directory.
macro(target_add_scatter_file target)

    get_target_property(scatter_file
                        platform_ns
                        INTERFACE_LINK_DEPENDS
    )

    # If scatter_file is not passed from platform_ns
    # Try if any linker script is exported in install directory
    # The intall directory is passed as an optinal argument
    if(${scatter_file} STREQUAL "scatter_file-NOTFOUND")
        set(install_dir ${ARGN})
        list(LENGTH install_dir nr_install_dir)

        # If nr_install_dir == 1, search for sct file under install dir
        if(${nr_install_dir} EQUAL 1)
            file(GLOB scatter_file "${install_dir}/*.ld")
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

    set_source_files_properties(${scatter_file} PROPERTIES
        LANGUAGE C
        KEEP_EXTENSION True # Don't use .o extension for the preprocessed file
    )

    target_compile_options(${target}_scatter
        PRIVATE
            -E
            -P
            -xc
    )

    target_compile_definitions(${target}_scatter
        PRIVATE
            $<$<NOT:$<BOOL:${CONFIG_GNU_LINKER_READONLY_ATTRIBUTE}>>:READONLY=>
    )

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        PRIVATE
            platform_region_defs
    )

    add_dependencies(${target} ${target}_scatter)

    target_link_options(${target}
        PRIVATE
            -T $<TARGET_OBJECTS:${target}_scatter>
    )

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
