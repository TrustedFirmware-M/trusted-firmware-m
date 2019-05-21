#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if(NOT DEFINED REGRESSION)
	message(FATAL_ERROR "ERROR: Incomplete Configuration: REGRESSION not defined, Include this file from a Config*.cmake")
elseif(NOT DEFINED CORE_TEST)
	message(FATAL_ERROR "ERROR: Incomplete Configuration: CORE_TEST not defined, Include this file from a Config*.cmake")
elseif(NOT DEFINED TFM_LVL)
	message(FATAL_ERROR "ERROR: Incomplete Configuration: TFM_LVL not defined, Include this file from a Config*.cmake")
endif()

if(NOT DEFINED COMPILER)
	message(FATAL_ERROR "ERROR: COMPILER is not set in command line")
elseif((NOT ${COMPILER} STREQUAL "ARMCLANG") AND (NOT ${COMPILER} STREQUAL "GNUARM"))
	message(FATAL_ERROR "ERROR: Compiler \"${COMPILER}\" is not supported.")
endif()

#BL2 bootloader (MCUBoot) related settings
if(NOT DEFINED BL2)
	set(BL2 True CACHE BOOL "Configure TF-M to use BL2 and enable building BL2")
endif()
if (BL2)
	if (NOT DEFINED MCUBOOT_UPGRADE_STRATEGY)
		set (MCUBOOT_UPGRADE_STRATEGY "OVERWRITE_ONLY" CACHE STRING "Configure BL2 which upgrade strategy to use")
		set_property(CACHE MCUBOOT_UPGRADE_STRATEGY PROPERTY STRINGS "OVERWRITE_ONLY;SWAP;NO_SWAP;RAM_LOADING")
	endif()
endif()

set(BUILD_CMSIS_CORE Off)
set(BUILD_RETARGET Off)
set(BUILD_NATIVE_DRIVERS Off)
set(BUILD_TIME Off)
set(BUILD_STARTUP Off)
set(BUILD_TARGET_CFG Off)
set(BUILD_TARGET_HARDWARE_KEYS Off)
set(BUILD_TARGET_NV_COUNTERS Off)
set(BUILD_CMSIS_DRIVERS Off)
set(BUILD_UART_STDOUT Off)
set(BUILD_FLASH Off)
set(BUILD_BOOT_SEED Off)
set(BUILD_DEVICE_ID Off)
if(NOT DEFINED PLATFORM_CMAKE_FILE)
	message (FATAL_ERROR "Platform specific CMake is not defined. Please set PLATFORM_CMAKE_FILE.")
elseif(NOT EXISTS ${PLATFORM_CMAKE_FILE})
	message (FATAL_ERROR "Platform specific CMake \"${PLATFORM_CMAKE_FILE}\" file does not exist. Please fix value of PLATFORM_CMAKE_FILE.")
else()
	include(${PLATFORM_CMAKE_FILE})
endif()

if (NOT DEFINED IMAGE_VERSION)
	set(IMAGE_VERSION 0.0.0+0)
endif()

if (DEFINED TFM_MULTI_CORE_TOPOLOGY AND TFM_MULTI_CORE_TOPOLOGY)
	# CMSE is unnecessary in multi-core scenarios.
	# TODO: Need further discussion about if CMSE is required when an Armv8-M
	# core acts as secure core in multi-core scenario.
	set (CMSE_FLAGS "")
	set (ARM_FEATURE_CMSE 0)
else ()
	set (CMSE_FLAGS "-mcmse")
	set (ARM_FEATURE_CMSE 3)
endif ()

if(${COMPILER} STREQUAL "ARMCLANG")
	#Use any ARMCLANG version found on PATH. Note: Only versions supported by the
	#build system will work. A file cmake/Common/CompilerArmClangXY.cmake
	#must be present with a matching version.
	include("Common/FindArmClang")
	include("Common/${ARMCLANG_MODULE}")

	set (COMMON_COMPILE_FLAGS -fshort-enums -fshort-wchar -funsigned-char -mfpu=none ${CMSE_FLAGS})
	##Shared compiler settings.
	function(config_setting_shared_compiler_flags tgt)
		embedded_set_target_compile_flags(TARGET ${tgt} LANGUAGE C FLAGS -xc -std=c99 ${COMMON_COMPILE_FLAGS} -Wall -Werror)
	endfunction()

	##Shared linker settings.
	function(config_setting_shared_linker_flags tgt)
		embedded_set_target_link_flags(TARGET ${tgt} FLAGS --strict --map --symbols --xref --entry=Reset_Handler --info=summarysizes,sizes,totals,unused,veneers)
	endfunction()
elseif(${COMPILER} STREQUAL "GNUARM")
	#Use any GNUARM version found on PATH. Note: Only versions supported by the
	#build system will work. A file cmake/Common/CompilerGNUARMXY.cmake
	#must be present with a matching version.
	include("Common/FindGNUARM")
	include("Common/${GNUARM_MODULE}")

	set (COMMON_COMPILE_FLAGS -fshort-enums -fshort-wchar -funsigned-char -msoft-float -ffunction-sections -fdata-sections --specs=nano.specs ${CMSE_FLAGS})
	##Shared compiler and linker settings.
	function(config_setting_shared_compiler_flags tgt)
		embedded_set_target_compile_flags(TARGET ${tgt} LANGUAGE C FLAGS -xc -std=c99 ${COMMON_COMPILE_FLAGS} -Wall -Werror -Wno-format -Wno-return-type -Wno-unused-but-set-variable)
	endfunction()

	##Shared linker settings.
	function(config_setting_shared_linker_flags tgt)
		#--no-wchar-size-warning flag is added because TF-M sources are compiled
		#with short wchars, however the standard library is compiled with normal
		#wchar, and this generates linker time warnings. TF-M code does not use
		#wchar, so the warning can be suppressed.
		embedded_set_target_link_flags(TARGET ${tgt} FLAGS -Xlinker -check-sections -Xlinker -fatal-warnings --entry=Reset_Handler --specs=nano.specs
						-Wl,--no-wchar-size-warning,--print-memory-usage,--gc-sections)
	endfunction()
endif()

#Create a string from the compile flags list, so that it can be used later
#in this file to set mbedtls and BL2 flags
list_to_string(COMMON_COMPILE_FLAGS_STR ${COMMON_COMPILE_FLAGS})

#Settings which shall be set for all projects the same way based
# on the variables above.
set (TFM_PARTITION_TEST_CORE OFF)
set (TFM_PARTITION_TEST_CORE_IPC OFF)
set (CORE_TEST_POSITIVE OFF)
set (CORE_TEST_INTERACTIVE OFF)
set (REFERENCE_PLATFORM OFF)
set (TFM_PARTITION_TEST_SECURE_SERVICES OFF)
set (SERVICES_TEST_ENABLED OFF)
set (TEST_FRAMEWORK_S  OFF)
set (TEST_FRAMEWORK_NS OFF)
set (TFM_PSA_API OFF)
set (TFM_LEGACY_API ON)
set (CORE_TEST_IPC OFF)

option(TFM_PARTITION_AUDIT_LOG "Enable the TF-M Audit Log partition" ON)
option(TFM_PARTITION_PLATFORM "Enable the TF-M Platform partition" ON)

if(${TARGET_PLATFORM} STREQUAL "AN521" OR ${TARGET_PLATFORM} STREQUAL "AN519")
	set (REFERENCE_PLATFORM ON)
endif()

# Option to demonstrate usage of secure-only peripheral
set (SECURE_UART1 OFF)

if (REGRESSION)
	set(SERVICES_TEST_ENABLED ON)
endif()

if (CORE_IPC)
	set(TFM_PSA_API ON)
endif()

if (TFM_PSA_API)
	if (DEFINED TFM_MULTI_CORE_TOPOLOGY AND TFM_MULTI_CORE_TOPOLOGY)
		add_definitions(-DTFM_MULTI_CORE_TOPOLOGY=1)
	endif()

	add_definitions(-DTFM_PSA_API)
endif()

if (TFM_LEGACY_API)
	add_definitions(-DTFM_LEGACY_API)
endif()

if (SERVICES_TEST_ENABLED)
	set(SERVICE_TEST_S ON)
	set(SERVICE_TEST_NS ON)
	if (CORE_IPC)
		set(CORE_TEST_IPC ON)
	elseif (REFERENCE_PLATFORM)
		set(CORE_TEST_POSITIVE ON)
	endif()
endif()

if (CORE_TEST)
	if (CORE_IPC)
		set(CORE_TEST_IPC ON)
	elseif (REFERENCE_PLATFORM)
		set(CORE_TEST_POSITIVE ON)
		set(CORE_TEST_INTERACTIVE OFF)
	endif()
endif()

if (CORE_TEST_INTERACTIVE)
	add_definitions(-DCORE_TEST_INTERACTIVE)
	set(TEST_FRAMEWORK_NS ON)
	set(TFM_PARTITION_TEST_CORE ON)
endif()

if (CORE_TEST_POSITIVE)
	add_definitions(-DCORE_TEST_POSITIVE)
	set(TEST_FRAMEWORK_NS ON)
	set(TFM_PARTITION_TEST_CORE ON)
endif()

if (CORE_TEST_IPC)
	add_definitions(-DCORE_TEST_IPC)
	set(TEST_FRAMEWORK_NS ON)
	set(TFM_PARTITION_TEST_CORE_IPC ON)
elseif (CORE_IPC AND (NOT PSA_API_TEST) AND (TFM_LVL EQUAL 1))
	# FIXME: Running the Core IPC tests in this config is deprecated and will
	# be removed in the future.
	set(CORE_TEST_IPC ON)
	add_definitions(-DCORE_TEST_IPC)
	set(TEST_FRAMEWORK_NS ON)
endif()

if (SERVICE_TEST_S)
	add_definitions(-DSERVICES_TEST_S)
	set(TEST_FRAMEWORK_S ON)
endif()

if (SERVICE_TEST_NS)
	add_definitions(-DSERVICES_TEST_NS)
	set(TEST_FRAMEWORK_NS ON)
endif()

if (TEST_FRAMEWORK_S)
	add_definitions(-DTEST_FRAMEWORK_S)
	# The secure client partition is required to run secure tests
	set(TFM_PARTITION_TEST_SECURE_SERVICES ON)
endif()

if (TEST_FRAMEWORK_NS)
	add_definitions(-DTEST_FRAMEWORK_NS)
endif()

if (CORE_IPC)
	set(TFM_PARTITION_AUDIT_LOG OFF)
	set(TFM_PARTITION_PLATFORM OFF)
endif()

if (TFM_PARTITION_AUDIT_LOG)
	add_definitions(-DTFM_PARTITION_AUDIT_LOG)
endif()

if (TFM_PARTITION_PLATFORM)
	add_definitions(-DTFM_PARTITION_PLATFORM)
endif()

if (TFM_PARTITION_TEST_CORE)
	add_definitions(-DTFM_PARTITION_TEST_CORE)
endif()

if (TFM_PARTITION_TEST_CORE_IPC)
	add_definitions(-DTFM_PARTITION_TEST_CORE_IPC)
endif()

if (TFM_PARTITION_TEST_SECURE_SERVICES)
	add_definitions(-DTFM_PARTITION_TEST_SECURE_SERVICES)
endif()

if (PSA_API_TEST)
	add_definitions(-DPSA_API_TEST_NS)
	set(PSA_API_TEST_NS ON)
	if (NOT DEFINED PSA_API_TEST_CRYPTO)
		set(PSA_API_TEST_CRYPTO OFF)
	endif()
	if (NOT DEFINED PSA_API_TEST_SECURE_STORAGE)
		set(PSA_API_TEST_SECURE_STORAGE OFF)
	endif()
	if (NOT DEFINED PSA_API_TEST_ATTESTATION)
		set(PSA_API_TEST_ATTESTATION OFF)
	endif()
endif()

# This flag indicates if the non-secure OS is capable of identify the non-secure clients
# which call the secure services
if (NOT DEFINED TFM_NS_CLIENT_IDENTIFICATION)
	set (TFM_NS_CLIENT_IDENTIFICATION ON)
endif()

if (BL2)
	add_definitions(-DBL2)
	if (NOT ${MCUBOOT_SIGNATURE_TYPE} STREQUAL "RSA-2048" AND NOT ${MCUBOOT_SIGNATURE_TYPE} STREQUAL "RSA-3072")
		message(FATAL_ERROR "MCUBoot only supports RSA-2048 and RSA-3072 signature")
	endif()
	if (NOT DEFINED MCUBOOT_SIGNATURE_TYPE)
		set(MCUBOOT_SIGNATURE_TYPE "RSA-3072")
	endif()
	if (NOT ${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "OVERWRITE_ONLY" AND
		NOT ${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "SWAP" AND
		NOT ${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "NO_SWAP" AND
		NOT ${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "RAM_LOADING")
		message(FATAL_ERROR "ERROR: MCUBoot supports OVERWRITE_ONLY, SWAP, NO_SWAP and RAM_LOADING upgrade strategies only.")
	endif()
	if (${MCUBOOT_UPGRADE_STRATEGY} STREQUAL "NO_SWAP")
		set(LINK_TO_BOTH_MEMORY_REGION ON)
	endif()
else() #BL2 is turned off
	if (DEFINED MCUBOOT_UPGRADE_STRATEGY)
		message (WARNING "Ignoring value of MCUBOOT_UPGRADE_STRATEGY as BL2 option is set to False.")
		unset (MCUBOOT_UPGRADE_STRATEGY)
	endif()
endif()

##Set Mbed TLS compiler flags and variables for audit log and crypto
set(MBEDTLS_C_FLAGS_SERVICES "-D__ARM_FEATURE_CMSE=${ARM_FEATURE_CMSE} -D__thumb2__ ${COMMON_COMPILE_FLAGS_STR} -I${CMAKE_CURRENT_LIST_DIR}/platform/ext/common")

#Default TF-M secure storage flags.
#These flags values can be overwritten by setting them in platform/ext/<TARGET_NAME>.cmake
#Documentation about these flags can be found in docs/user_guides/services/tfm_sst_integration_guide.md
if (NOT DEFINED SST_ENCRYPTION)
	set (SST_ENCRYPTION ON)
endif()

if (NOT DEFINED SST_ROLLBACK_PROTECTION)
	set (SST_ROLLBACK_PROTECTION OFF)
endif()

if (NOT DEFINED SST_CREATE_FLASH_LAYOUT)
	set (SST_CREATE_FLASH_LAYOUT OFF)
endif()

if (NOT DEFINED SST_VALIDATE_METADATA_FROM_FLASH)
	set (SST_VALIDATE_METADATA_FROM_FLASH ON)
endif()

if (NOT DEFINED SST_RAM_FS)
	if (REGRESSION)
		set (SST_RAM_FS ON)
	else()
		set (SST_RAM_FS OFF)
	endif()
endif()

if (NOT DEFINED SST_TEST_NV_COUNTERS)
	if (REGRESSION AND (TFM_LVL EQUAL 1))
		set(SST_TEST_NV_COUNTERS ON)
	else()
		set(SST_TEST_NV_COUNTERS OFF)
	endif()
endif()

if (NOT DEFINED MBEDTLS_DEBUG)
	set(MBEDTLS_DEBUG OFF)
endif()

##Set mbedTLS compiler flags for BL2 bootloader
set(MBEDTLS_C_FLAGS_BL2 "-D__ARM_FEATURE_CMSE=${ARM_FEATURE_CMSE} -D__thumb2__ ${COMMON_COMPILE_FLAGS_STR} -DMBEDTLS_CONFIG_FILE=\\\\\\\"config-boot.h\\\\\\\" -I${CMAKE_CURRENT_LIST_DIR}/bl2/ext/mcuboot/include")
if (MCUBOOT_SIGNATURE_TYPE STREQUAL "RSA-3072")
	string(APPEND MBEDTLS_C_FLAGS_BL2 " -DMCUBOOT_SIGN_RSA_LEN=3072")
endif()
