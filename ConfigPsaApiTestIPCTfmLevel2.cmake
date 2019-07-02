#-------------------------------------------------------------------------------
# Copyright (c) 2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

message(WARNING "Please use the configs available in the ./config sub-directory.")

if(NOT DEFINED TFM_ROOT_DIR)
	message(FATAL_ERROR "Variable TFM_ROOT_DIR is not set!")
endif()

include ("${TFM_ROOT_DIR}/configs/ConfigPsaApiTestIPCTfmLevel2.cmake")
