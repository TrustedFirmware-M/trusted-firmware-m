#-------------------------------------------------------------------------------
# Copyright (c) 2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.7)

#Tell cmake where our modules can be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../cmake)

#Some project global settings
set(T_COSE_DIR "${CMAKE_CURRENT_LIST_DIR}")
get_filename_component(TFM_ROOT_DIR "${T_COSE_DIR}/../.." ABSOLUTE)

#Include common stuff to control cmake.
include("Common/BuildSys")

#Start an embedded project.
embedded_project_start(CONFIG "${TFM_ROOT_DIR}/configs/ConfigDefault.cmake")
project(tfm_t_cose_sign   LANGUAGES C)
project(tfm_t_cose_verify LANGUAGES C)
embedded_project_fixup()

#Append all our source files to global lists.
list(APPEND ALL_SRC_C_SIGN
	"${T_COSE_DIR}/src/t_cose_sign1_sign.c"
	"${T_COSE_DIR}/src/t_cose_util.c"
	"${T_COSE_DIR}/src/t_cose_psa_crypto_hash.c"
	"${T_COSE_DIR}/src/t_cose_psa_crypto_sign.c"
	)

list(APPEND ALL_SRC_C_VERIFY
	"${T_COSE_DIR}/src/t_cose_sign1_verify.c"
	"${T_COSE_DIR}/src/t_cose_util.c"
	"${T_COSE_DIR}/src/t_cose_psa_crypto_hash.c"
	"${T_COSE_DIR}/src/t_cose_psa_crypto_verify.c"
	)

#Setting include directories
embedded_include_directories(PATH ${T_COSE_DIR}/inc ABSOLUTE)
embedded_target_include_directories(TARGET tfm_t_cose_verify PATH ${TFM_ROOT_DIR}/lib/ext/qcbor/util ABSOLUTE APPEND)
embedded_target_include_directories(TARGET tfm_t_cose_verify PATH ${TFM_ROOT_DIR}/test/suites/attestation ABSOLUTE APPEND)
embedded_target_include_directories(TARGET tfm_t_cose_sign   PATH ${TFM_ROOT_DIR}/platform/include ABSOLUTE APPEND)

#Specify what we build (t_cose_sign and t_cose_verify build as an object library)
add_library(tfm_t_cose_sign   OBJECT ${ALL_SRC_C_SIGN})
add_library(tfm_t_cose_verify OBJECT ${ALL_SRC_C_VERIFY})

#Set common compiler flags
config_setting_shared_compiler_flags(tfm_t_cose_sign)
config_setting_shared_compiler_flags(tfm_t_cose_verify)

embedded_project_end(tfm_t_cose_sign)
embedded_project_end(tfm_t_cose_verify)
