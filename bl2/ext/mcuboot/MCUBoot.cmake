#-------------------------------------------------------------------------------
# Copyright (c) 2018, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

function(mcuboot_create_boot_payload)
	set( _OPTIONS_ARGS)                                          #Option (on/off) arguments (e.g. IGNORE_CASE)
	set( _ONE_VALUE_ARGS S_BIN NS_BIN FULL_BIN SIGN_BIN POSTFIX) #Single option arguments (e.g. PATH "./foo/bar")
	set( _MULTI_VALUE_ARGS)                                      #List arguments (e.g. LANGUAGES C ASM CXX)
	cmake_parse_arguments(_MY_PARAMS "${_OPTIONS_ARGS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN})

	if (NOT DEFINED _MY_PARAMS_S_BIN)
		message(FATAL_ERROR "mcuboot_create_boot_payload(): mandatory parameter 'S_BIN' missing.")
	endif()

	if (NOT DEFINED _MY_PARAMS_NS_BIN)
		message(FATAL_ERROR "mcuboot_create_boot_payload(): mandatory parameter 'NS_BIN' missing.")
	endif()

	if (NOT DEFINED _MY_PARAMS_FULL_BIN)
		message(FATAL_ERROR "mcuboot_create_boot_payload(): mandatory parameter 'FULL_BIN' missing.")
	endif()

	if (NOT DEFINED _MY_PARAMS_SIGN_BIN)
		message(FATAL_ERROR "mcuboot_create_boot_payload(): mandatory parameter 'SIGN_BIN' missing.")
	endif()

	if (DEFINED _MY_PARAMS_POSTFIX)
		if (${_MY_PARAMS_POSTFIX} STREQUAL "_0")
			set(MY_POSTFIX "0")
		else()
			set(MY_POSTFIX "1")
		endif()
	endif()

	#Find Python3.x interpreter
	find_package(PythonInterp 3)
	if (NOT PYTHONINTERP_FOUND)
		message(FATAL_ERROR "Failed to find Python3.x interpreter. Pyhton3 must be installed and available on the PATH.")
	endif()

	if(NOT DEFINED FLASH_LAYOUT)
		message(FATAL_ERROR "ERROR: Incomplete Configuration: FLASH_LAYOUT is not defined.")
	endif()

	add_custom_command(TARGET ${_MY_PARAMS_NS_BIN}
						POST_BUILD
						#Create concatenated binary image from the two binary file
						COMMAND ${PYTHON_EXECUTABLE} ${MCUBOOT_DIR}/scripts/assemble.py
						ARGS -l ${FLASH_LAYOUT}
							 -s ${CMAKE_BINARY_DIR}/../cmake_psoc_cm0p/app/secure_fw/${_MY_PARAMS_S_BIN}.bin
							 -n $<TARGET_FILE_DIR:${_MY_PARAMS_NS_BIN}>/${_MY_PARAMS_NS_BIN}.bin
							 -o ${CMAKE_BINARY_DIR}/${_MY_PARAMS_FULL_BIN}.bin

						#Sign concatenated binary image with default public key in mcuboot folder
						COMMAND ${PYTHON_EXECUTABLE} ${MCUBOOT_DIR}/scripts/imgtool.py
						ARGS sign
							 --layout ${FLASH_LAYOUT}
							 -k ${MCUBOOT_DIR}/root-rsa-2048.pem
							 --align 1
							 -v ${IMAGE_VERSION}
							 -H 0x400
							 --pad ${SIGN_BIN_SIZE}
							 ${CMAKE_BINARY_DIR}/${_MY_PARAMS_FULL_BIN}.bin
							 ${CMAKE_BINARY_DIR}/${_MY_PARAMS_SIGN_BIN}.bin)

	#Collect executables to common location: build/install/outputs/
	set(TFM_FULL_NAME tfm_s_ns_concatenated)
	set(TFM_SIGN_NAME tfm_s_ns_signed)

	if (DEFINED MY_POSTFIX)
		install(FILES  ${CMAKE_BINARY_DIR}/${_MY_PARAMS_SIGN_BIN}.bin
				RENAME tfm_sig${MY_POSTFIX}.bin
				DESTINATION outputs/${TARGET_PLATFORM}/)
	else()
		install(FILES ${CMAKE_BINARY_DIR}/${_MY_PARAMS_SIGN_BIN}.bin
				DESTINATION outputs/${TARGET_PLATFORM}/)
	endif()

	install(FILES  ${CMAKE_BINARY_DIR}/${_MY_PARAMS_FULL_BIN}.bin
			DESTINATION outputs/${TARGET_PLATFORM}/)

	install(FILES  ${CMAKE_BINARY_DIR}/${_MY_PARAMS_FULL_BIN}.bin
			RENAME ${TFM_FULL_NAME}${_MY_PARAMS_POSTFIX}.bin
			DESTINATION outputs/fvp/)

	install(FILES  ${CMAKE_BINARY_DIR}/${_MY_PARAMS_SIGN_BIN}.bin
			RENAME ${TFM_SIGN_NAME}${_MY_PARAMS_POSTFIX}.bin
			DESTINATION outputs/fvp/)
endfunction()