################################################################################
# \file PSE84-EPC4.mk
# \version 1.0
#
# \brief
# Trusted Firmware-M (TF-M) configuration for PSE84 EPC4
#
################################################################################
# \copyright
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

# Platform
TFM_CONFIGURE_OPTIONS+= -DTFM_PLATFORM:STRING=infineon/pse84 -DIFX_EPC=epc4

ifneq ($(DEVICE_MODE),SECURE)
# TF-M non-secure interface
DEFINES+=MBEDTLS_PSA_CRYPTO_PLATFORM_FILE=\"tfm_mbedtls_psa_crypto_platform.h\"
endif

# Use TFM linker files from project imports
TFM_CONFIGURE_OPTIONS+= -DTFM_LINKER_FILES_BASE_PATH:PATH=$(call TFM_PATH_MIXED,$(abspath $(MTB_TOOLS__PRJ_DIR)/imports/ifx-tf-m-pse84epc4/linker_scripts))
