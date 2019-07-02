#-------------------------------------------------------------------------------
# Copyright (c) 2017-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

#Tell cmake where our modules can be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../cmake)

#Tell TFM Root before calling sub cmake
get_filename_component(TFM_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

#Include common stuff to control cmake.
include("Common/BuildSys")

#Start an embedded project.
embedded_project_start(CONFIG "${TFM_ROOT_DIR}/configs/ConfigDefault.cmake")
project(tfm_tests LANGUAGES ASM C)
embedded_project_fixup()

#Check incoming configuration options
if (NOT DEFINED SERVICES_TEST_ENABLED)
	message(FATAL_ERROR "Incomplete build configuration: SERVICES_TEST_ENABLED is undefined. ")
endif()

if (NOT DEFINED CORE_TEST_INTERACTIVE)
	message(FATAL_ERROR "Incomplete build configuration: CORE_TEST_INTERACTIVE is undefined. ")
endif()

if (NOT DEFINED CORE_TEST_POSITIVE)
	message(FATAL_ERROR "Incomplete build configuration: CORE_TEST_POSITIVE is undefined. ")
endif()

if (NOT DEFINED TFM_LVL)
	message(FATAL_ERROR "Incomplete build configuration: TFM_LVL is undefined. ")
endif()

if (NOT DEFINED TFM_PARTITION_AUDIT_LOG)
	message(FATAL_ERROR "Incomplete build configuration: TFM_PARTITION_AUDIT_LOG is undefined.")
endif()

#Configure our options as needed.
if (CORE_TEST_INTERACTIVE OR CORE_TEST_POSITIVE)
	set(ENABLE_CORE_TESTS True)
	set(ENABLE_CORE_TESTS_2 True)
else()
	set(ENABLE_CORE_TESTS False)
	set(ENABLE_CORE_TESTS_2 False)
endif()

set(ENABLE_SECURE_STORAGE_SERVICE_TESTS TRUE)
set(ENABLE_AUDIT_LOGGING_SERVICE_TESTS TRUE)
set(ENABLE_CRYPTO_SERVICE_TESTS TRUE)
set(ENABLE_INVERT_SERVICE_TESTS TRUE)
set(ENABLE_ATTESTATION_SERVICE_TESTS TRUE)
set(ENABLE_QCBOR_TESTS TRUE)

if (NOT TFM_PARTITION_AUDIT_LOG)
	set(ENABLE_AUDIT_LOGGING_SERVICE_TESTS FALSE)
endif()

if (ENABLE_AUDIT_LOGGING_SERVICE_TESTS)
	set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS ENABLE_AUDIT_LOGGING_SERVICE_TESTS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/CMakeLists.inc)

if (NOT TARGET tfm_t_cose_verify)
	add_subdirectory(${TFM_ROOT_DIR}/lib/t_cose ${CMAKE_CURRENT_BINARY_DIR}/t_cose)
endif()

if (NOT TARGET tfm_qcbor)
	add_subdirectory(${TFM_ROOT_DIR}/lib/ext/qcbor ${CMAKE_CURRENT_BINARY_DIR}/qcbor)
endif()

#Build the secure library. Even though secure tests files depend on tfm_qcbor,
#this is not expressed here as the tfm_attest library is expected to hold the
#compiled tfm_qcbor files.
add_library(tfm_secure_tests STATIC ${ALL_SRC_C} ${ALL_SRC_C_S} $<TARGET_OBJECTS:tfm_t_cose_verify>)

#Set common compiler and linker flags
config_setting_shared_compiler_flags(tfm_secure_tests)
config_setting_shared_linker_flags(tfm_secure_tests)

embedded_set_target_compile_defines(TARGET tfm_secure_tests LANGUAGE C DEFINES __thumb2__  TFM_LVL=${TFM_LVL} APPEND)


#Build the non-secure library
set(CMAKE_STATIC_LIBRARY_PREFIX_C "lib")
add_library(tfm_non_secure_tests STATIC ${ALL_SRC_C} ${ALL_SRC_C_NS} $<TARGET_OBJECTS:tfm_t_cose_verify> $<TARGET_OBJECTS:tfm_qcbor>)

#Set common compiler and linker flags
config_setting_shared_compiler_flags(tfm_non_secure_tests)
config_setting_shared_linker_flags(tfm_non_secure_tests)

embedded_set_target_compile_defines(TARGET tfm_non_secure_tests LANGUAGE C DEFINES __thumb2__  __DOMAIN_NS=1 TFM_LVL=${TFM_LVL} APPEND)
#__DOMAIN_NS=1

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Default install location for tfm_storage." FORCE)
endif()

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/framework/test_framework_integ_test.h
				${CMAKE_CURRENT_SOURCE_DIR}/suites/sst/non_secure/os_wrapper.h
				${CMAKE_CURRENT_SOURCE_DIR}/test_services/tfm_secure_client_service/tfm_secure_client_service_api.h
		DESTINATION export/tfm/test/inc)

install(TARGETS tfm_non_secure_tests
		DESTINATION export/tfm/test/lib
		PUBLIC_HEADER DESTINATION export/tfm/test/inc)

embedded_project_end(tfm_non_secure_tests)
embedded_project_end(tfm_secure_tests)
