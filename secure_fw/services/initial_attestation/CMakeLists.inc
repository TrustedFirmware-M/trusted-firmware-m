#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#Definitions to compile the "initial_attestation" module.
#This file assumes it will be included from a project specific cmakefile, and
#will not create a library or executable.
#Inputs:
#	MBEDTLS_INSTALL_DIR - directory where mbedtls headers and libraries can be found.
#	TFM_ROOT_DIR        - root directory of the TF-M repository.
#Outputs:
#	Will modify include directories to make the source compile.
#	ALL_SRC_C: C source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	ALL_SRC_CXX: C++ source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	ALL_SRC_ASM: assembly source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	Include directories will be modified by using the include_directories() commands as needed.

#Get the current directory where this file is located.
set(INITIAL_ATTESTATION_DIR ${CMAKE_CURRENT_LIST_DIR})

#Check input variables
if (NOT DEFINED ENABLE_INITIAL_ATTESTATION)
	message(FATAL_ERROR "Incomplete build configuration: ENABLE_INITIAL_ATTESTATION is undefined. ")
endif()

if (ENABLE_INITIAL_ATTESTATION)
	if (NOT DEFINED TFM_ROOT_DIR)
		message(FATAL_ERROR "Please set TFM_ROOT_DIR before including this file.")
	endif()

	#Append all our source files to global lists.
	list(APPEND ALL_SRC_C
		"${INITIAL_ATTESTATION_DIR}/tfm_attestation_secure_api.c"
		"${INITIAL_ATTESTATION_DIR}/tfm_attestation.c"
		"${INITIAL_ATTESTATION_DIR}/tfm_attestation_req_mngr.c"
		"${INITIAL_ATTESTATION_DIR}/attestation_core.c"
		"${INITIAL_ATTESTATION_DIR}/attestation_key.c"
		"${INITIAL_ATTESTATION_DIR}/attest_token.c"
		)

	#Setting include directories
	embedded_include_directories(PATH ${TFM_ROOT_DIR} ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/interface/include ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/platform/ext/common ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/platform/include ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/bl2/include ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/secure_fw/core/include ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/secure_fw/spm ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/lib/ext/qcbor/inc ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/lib/t_cose/inc ABSOLUTE)
	embedded_include_directories(PATH ${TFM_ROOT_DIR}/lib/t_cose/src ABSOLUTE)
	embedded_include_directories(PATH ${INITIAL_ATTESTATION_DIR} ABSOLUTE)

	set(BUILD_CMSIS_CORE Off)
	set(BUILD_RETARGET Off)
	set(BUILD_NATIVE_DRIVERS Off)
	set(BUILD_STARTUP Off)
	set(BUILD_TARGET_CFG Off)
	set(BUILD_TARGET_HARDWARE_KEYS Off)
	set(BUILD_TARGET_NV_COUNTERS Off)
	set(BUILD_CMSIS_DRIVERS Off)
	set(BUILD_TIME Off)
	set(BUILD_UART_STDOUT Off)
	set(BUILD_FLASH Off)
	set(BUILD_BOOT_SEED On)
	set(BUILD_DEVICE_ID On)
	set(BUILD_PLAT_TEST Off)
	if(NOT DEFINED PLATFORM_CMAKE_FILE)
		message (FATAL_ERROR "Platform specific CMake is not defined. Please set PLATFORM_CMAKE_FILE.")
	elseif(NOT EXISTS ${PLATFORM_CMAKE_FILE})
		message (FATAL_ERROR "Platform specific CMake \"${PLATFORM_CMAKE_FILE}\" file does not exist. Please fix value of PLATFORM_CMAKE_FILE.")
	else()
		include(${PLATFORM_CMAKE_FILE})
	endif()

else()
	message(FATAL_ERROR "Build system currently doesn't support selectively disabling of a service.")
endif()

