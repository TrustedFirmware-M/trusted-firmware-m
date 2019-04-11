#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

#Tell cmake where our modules can be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../cmake)

#Include common stuff to control cmake.
include("Common/BuildSys")

#Start an embedded project.
embedded_project_start(CONFIG "${CMAKE_CURRENT_LIST_DIR}/../../../ConfigDefault.cmake")
project(tfm_audit LANGUAGES ASM C)
embedded_project_fixup()

###Some project global settings
set (AUDIT_LOGGING_DIR "${CMAKE_CURRENT_LIST_DIR}")
get_filename_component(TFM_ROOT_DIR "${AUDIT_LOGGING_DIR}/../../.." ABSOLUTE)

#Do not build Mbed TLS for the time being to save compile time
set (AUDIT_LOG_BUILD_MBEDTLS OFF)

#Define location of mbedtls source, build, and installation directory.
if (AUDIT_LOG_BUILD_MBEDTLS)
	get_filename_component(MBEDTLS_SOURCE_DIR "${TFM_ROOT_DIR}/../mbedtls" ABSOLUTE)
	set (MBEDTLS_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/mbedtls")
	set (MBEDTLS_INSTALL_DIR ${MBEDTLS_BINARY_DIR}/mbedtls_install)
	set (MBEDTLS_TARGET_NAME "mbedtls_log_lib")

	#Set mbedTLS compiler flags
	set(MBEDTLS_C_FLAGS ${MBEDTLS_C_FLAGS_SERVICES})
endif()

###Get the definition of what files we need to build
set (ENABLE_AUDIT_LOGGING ON)
include(CMakeLists.inc)

if (NOT DEFINED TFM_LVL)
	message(FATAL_ERROR "Incomplete build configuration: TFM_LVL is undefined. ")
endif()

if (AUDIT_LOG_BUILD_MBEDTLS)
	#Set preinclude header options for mbedtls
	set(MBEDTLS_PREINCLUDE_PREFIX __tfm_audit__)
	set(MBEDTLS_PREINCLUDE_HEADER ${AUDIT_LOGGING_DIR}/mbedtls_global_symbols.h)

	#Build mbedtls as external project.
	#This ensures mbedtls is built with exactly defined settings.
	#mbedtls will be used from its install location
	include(${TFM_ROOT_DIR}/BuildMbedtls.cmake)
endif()

#Specify what we build (for the audit logging service, build as a static library)
add_library(tfm_audit STATIC ${ALL_SRC_ASM} ${ALL_SRC_C})
embedded_set_target_compile_defines(TARGET tfm_audit LANGUAGE C DEFINES  __thumb2__ TFM_LVL=${TFM_LVL})

if (AUDIT_LOG_BUILD_MBEDTLS)
	#Add a dependency on the mbed_tls_lib_install target.
	add_dependencies(tfm_audit ${MBEDTLS_TARGET_NAME}_install)
	#Ask the compiler to merge the mbedtls and the audit logging libraries.
	compiler_merge_library(DEST tfm_audit LIBS "${MBEDTLS_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX_C}mbedcrypto${CMAKE_STATIC_LIBRARY_SUFFIX_C}")
endif()
#Set common compiler and linker flags
config_setting_shared_compiler_flags(tfm_audit)
config_setting_shared_linker_flags(tfm_audit)

embedded_project_end(tfm_audit)
