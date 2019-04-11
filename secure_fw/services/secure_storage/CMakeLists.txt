#-------------------------------------------------------------------------------
# Copyright (c) 2017-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

# Tell cmake where our modules can be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../cmake)

#Include common stuff to control cmake.
include("Common/BuildSys")

#Start an embedded project.
embedded_project_start(CONFIG "${CMAKE_CURRENT_LIST_DIR}/../../../ConfigDefault.cmake")
project(tfm_storage LANGUAGES ASM C)
embedded_project_fixup()

###Some project global settings
set (SECURE_STORAGE_DIR "${CMAKE_CURRENT_LIST_DIR}")
get_filename_component(TFM_ROOT_DIR "${SECURE_STORAGE_DIR}/../../.." ABSOLUTE)
#Define location of mbedtls source, build, and installation directory.
get_filename_component(MBEDTLS_SOURCE_DIR "${TFM_ROOT_DIR}/../mbedtls" ABSOLUTE)
set (MBEDTLS_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/mbedtls")
set (MBEDTLS_INSTALL_DIR ${MBEDTLS_BINARY_DIR}/mbedtls_install)
set (MBEDTLS_TARGET_NAME "mbedtls_sst_lib")

#Set mbedTLS compiler flags
set(MBEDTLS_C_FLAGS ${MBEDTLS_C_FLAGS_SERVICES})

###Get the definition of what files we need to build
include(CMakeLists.inc)

if (NOT DEFINED TFM_LVL)
	message(FATAL_ERROR "Incomplete build configuration: TFM_LVL is undefined. ")
endif()

#Set preinclude header options for mbedtls
set(MBEDTLS_PREINCLUDE_PREFIX __tfm_storage__)
set(MBEDTLS_PREINCLUDE_HEADER ${SECURE_STORAGE_DIR}/crypto/mbedtls_global_symbols.h)

#Build mbedtls as external project.
#This ensures mbedtls is built with exactly defined settings.
#mbedtls will be used from its install location
include(${TFM_ROOT_DIR}/BuildMbedtls.cmake)

# Specify what we build (for the secure storage service, build as a static library)
add_library(tfm_storage STATIC ${ALL_SRC_ASM} ${ALL_SRC_C})

#Set common compiler and linker flags
config_setting_shared_compiler_flags(tfm_storage)
config_setting_shared_linker_flags(tfm_storage)

embedded_set_target_compile_defines(TARGET tfm_storage LANGUAGE C DEFINES  __thumb2__ TFM_LVL=${TFM_LVL})
#Add a dependency on the mbed_tls_lib_install target.
add_dependencies(tfm_storage ${MBEDTLS_TARGET_NAME}_install)
#Ask the compiler to merge the mbedtls and the secure storage libraries.
compiler_merge_library(DEST tfm_storage LIBS "${MBEDTLS_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX_C}mbedcrypto${CMAKE_STATIC_LIBRARY_SUFFIX_C}")

embedded_project_end(tfm_storage)
