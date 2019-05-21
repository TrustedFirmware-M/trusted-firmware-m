#------------------------------------------------------------------------------
# Copyright (c) 2017-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

set(TFM_BUILD_IN_SPE ON)

#Tell cmake where our modules can be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../cmake)

#Set variables to appropriate path
set(MCUBOOT_DIR ${CMAKE_CURRENT_LIST_DIR})
get_filename_component(TFM_ROOT_DIR "${MCUBOOT_DIR}/../../.." ABSOLUTE)

#Include common stuff to control cmake.
include("Common/BuildSys")

#Start an embedded project.
embedded_project_start(CONFIG "${TFM_ROOT_DIR}/configs/ConfigDefault.cmake")
project(mcuboot LANGUAGES ASM C)
embedded_project_fixup()

#Check input variables
if (NOT DEFINED BL2)
   message(FATAL ERROR "Incomplete build configuration: BL2 is undefined.")
elseif(NOT BL2)
    #If mcuboot is not need to be built then stop further processing.
    return()
endif()

if (NOT DEFINED MBEDTLS_C_FLAGS_BL2)
	message(FATAL_ERROR "Incomplete build configuration: MBEDTLS_C_FLAGS_BL2 is undefined.")
endif()

set(BUILD_CMSIS_CORE On)
set(BUILD_RETARGET On)
set(BUILD_NATIVE_DRIVERS On)
set(BUILD_STARTUP On)
set(BUILD_TARGET_CFG Off)
set(BUILD_TARGET_HARDWARE_KEYS Off)
set(BUILD_TARGET_NV_COUNTERS On)
set(BUILD_CMSIS_DRIVERS On)
set(BUILD_TIME Off)
set(BUILD_UART_STDOUT On)
set(BUILD_FLASH On)
if(NOT DEFINED PLATFORM_CMAKE_FILE)
	message (FATAL_ERROR "Platform specific CMake is not defined. Please set PLATFORM_CMAKE_FILE.")
elseif(NOT EXISTS ${PLATFORM_CMAKE_FILE})
	message (FATAL_ERROR "Platform specific CMake \"${PLATFORM_CMAKE_FILE}\" file does not exist. Please fix value of PLATFORM_CMAKE_FILE.")
else()
	include(${PLATFORM_CMAKE_FILE})
endif()

#Add platform specific definitions in SPE
if (DEFINED TFM_PLATFORM_SECURE_DEFS)
	embedded_set_target_compile_defines(TARGET ${PROJECT_NAME} LANGUAGE C DEFINES ${TFM_PLATFORM_SECURE_DEFS} APPEND)
	embedded_set_target_compile_defines(TARGET ${PROJECT_NAME} LANGUAGE ASM DEFINES ${TFM_PLATFORM_SECURE_DEFS} APPEND)
endif()

#Append all our source files to global lists.
list(APPEND ALL_SRC_C
		"${MCUBOOT_DIR}/bl2_main.c"
		"${MCUBOOT_DIR}/flash_map.c"
		"${MCUBOOT_DIR}/keys.c"
		"${MCUBOOT_DIR}/bootutil/src/loader.c"
		"${MCUBOOT_DIR}/bootutil/src/bootutil_misc.c"
		"${MCUBOOT_DIR}/bootutil/src/image_validate.c"
		"${MCUBOOT_DIR}/bootutil/src/image_rsa.c"
		"${MCUBOOT_DIR}/bootutil/src/caps.c"
		"${TFM_ROOT_DIR}/bl2/src/boot_record.c"
		"${TFM_ROOT_DIR}/bl2/src/security_cnt.c"
	)

#Define location of mbedtls source, build, and installation directory.
get_filename_component(MBEDTLS_SOURCE_DIR "${TFM_ROOT_DIR}/../mbedtls" ABSOLUTE)
if(NOT EXISTS ${MBEDTLS_SOURCE_DIR})
	message(FATAL_ERROR "Missing mbedtls. Please clone the mbedtls repo to directory \"${MBEDTLS_SOURCE_DIR}\".")
endif()
set (MBEDTLS_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/mbedtls")
set (MBEDTLS_INSTALL_DIR ${MBEDTLS_BINARY_DIR}/mbedtls_install)

#Build mbedtls as external project.
#This ensures mbedtls is built with exactly defined settings.
#mbedtls will be used from is't install location
set(MBEDTLS_C_FLAGS ${MBEDTLS_C_FLAGS_BL2})
set(MBEDTLS_TARGET_NAME "mbedtls_mcuboot_lib")
include(${TFM_ROOT_DIR}/BuildMbedtls.cmake)

#Setting include directories
embedded_target_include_directories(TARGET ${PROJECT_NAME} PATH ${TFM_ROOT_DIR} ABSOLUTE APPEND)
embedded_target_include_directories(TARGET ${PROJECT_NAME} PATH ${TFM_ROOT_DIR}/bl2/include ABSOLUTE APPEND)
embedded_target_include_directories(TARGET ${PROJECT_NAME} PATH ${TFM_ROOT_DIR}/bl2/ext/mcuboot/include ABSOLUTE APPEND)
embedded_target_include_directories(TARGET ${PROJECT_NAME} PATH ${TFM_ROOT_DIR}/bl2/ext/mcuboot/bootutil/include/ ABSOLUTE APPEND)
embedded_target_include_directories(TARGET ${PROJECT_NAME} PATH ${MBEDTLS_INSTALL_DIR}/include ABSOLUTE APPEND)

#Define linker file
if(NOT DEFINED BL2_LINKER_CONFIG)
	message(FATAL_ERROR "ERROR: Incomplete Configuration: BL2_LINKER_CONFIG is not defined.")
endif()
embedded_set_target_linker_file(TARGET ${PROJECT_NAME} PATH "${BL2_LINKER_CONFIG}")

if(NOT DEFINED PLATFORM_LINK_INCLUDES)
	message(FATAL_ERROR "ERROR: Incomplete Configuration: PLATFORM_LINK_INCLUDES is not defined.")
endif()
embedded_set_target_link_includes(TARGET ${PROJECT_NAME} INCLUDES "${PLATFORM_LINK_INCLUDES}")

add_executable(${PROJECT_NAME} ${ALL_SRC_ASM} ${ALL_SRC_C_BL2} ${ALL_SRC_ASM_BL2} ${ALL_SRC_C} ${ALL_SRC_CXX})

#Set common compiler and linker flags
config_setting_shared_compiler_flags(${PROJECT_NAME})
config_setting_shared_linker_flags(${PROJECT_NAME})

#Add BL2 define to linker to resolve symbols in region_defs.h
embedded_set_target_link_defines(TARGET ${PROJECT_NAME} DEFINES "BL2")

if(NOT DEFINED TEST_FRAMEWORK_S)
	message(FATAL_ERROR "Incomplete build configuration: TEST_FRAMEWORK_S is undefined.")
elseif(TEST_FRAMEWORK_S)
	embedded_set_target_link_defines(TARGET ${PROJECT_NAME} DEFINES "TEST_FRAMEWORK_S")
endif()

if(NOT DEFINED TEST_FRAMEWORK_NS)
	message(FATAL_ERROR "Incomplete build configuration: TEST_FRAMEWORK_NS is undefined.")
elseif(TEST_FRAMEWORK_NS)
	embedded_set_target_link_defines(TARGET ${PROJECT_NAME} DEFINES "TEST_FRAMEWORK_NS")
endif()

#Link mbedcrypto library to project
target_link_libraries(${PROJECT_NAME} "${MBEDTLS_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX_C}mbedcrypto${CMAKE_STATIC_LIBRARY_SUFFIX_C}")
add_dependencies(${PROJECT_NAME} ${MBEDTLS_TARGET_NAME}_install)

#Generate binary file from axf
compiler_generate_binary_output(${PROJECT_NAME})

#Set macro definitions for the project.
target_compile_definitions(${PROJECT_NAME} PRIVATE
							MCUBOOT_VALIDATE_SLOT0
							MCUBOOT_USE_FLASH_AREA_GET_SECTORS
							MBEDTLS_CONFIG_FILE="config-boot.h"
							MCUBOOT_TARGET_CONFIG="flash_layout.h")

if (MCUBOOT_SIGNATURE_TYPE STREQUAL "RSA-3072")
	target_compile_definitions(${PROJECT_NAME} PRIVATE MCUBOOT_SIGN_RSA MCUBOOT_SIGN_RSA_LEN=3072)
elseif(MCUBOOT_SIGNATURE_TYPE STREQUAL "RSA-2048")
	target_compile_definitions(${PROJECT_NAME} PRIVATE MCUBOOT_SIGN_RSA MCUBOOT_SIGN_RSA_LEN=2048)
else()
	message(FATAL_ERROR "${MCUBOOT_SIGNATURE_TYPE} is not supported as firmware signing algorithm")
endif()

if (${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "OVERWRITE_ONLY")
	target_compile_definitions(${PROJECT_NAME} PRIVATE MCUBOOT_OVERWRITE_ONLY)
elseif (${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "NO_SWAP")
	target_compile_definitions(${PROJECT_NAME} PRIVATE MCUBOOT_NO_SWAP)
elseif (${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "RAM_LOADING")
	target_compile_definitions(${PROJECT_NAME} PRIVATE MCUBOOT_RAM_LOADING)
elseif (${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "SWAP")
	#No compile definition needs to be specified for this upgrade strategy
else()
	message(FATAL_ERROR "ERROR: MCUBoot supports OVERWRITE_ONLY, SWAP, NO_SWAP and RAM_LOADING upgrade strategies only.")
endif()

#Set install location. Keep original value to avoid overriding command line settings.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Default install location for MCUBoot." FORCE)
endif()

#Collect executables to common location: build/install/outputs/
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.axf
			  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin
		DESTINATION outputs/${TARGET_PLATFORM}/)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.axf
			  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin
		DESTINATION outputs/fvp/)

#Finally let cmake system apply changes after the whole project is defined.
embedded_project_end(${PROJECT_NAME})
