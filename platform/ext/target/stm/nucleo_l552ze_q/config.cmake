#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

########################## BL2 #################################################

set(MCUBOOT_IMAGE_NUMBER                2           CACHE STRING    "Whether to combine S and NS into either 1 image, or sign each seperately")
set(BL2_TRAILER_SIZE                    0x2000      CACHE STRING    "Trailer size")
set(MCUBOOT_USE_PSA_CRYPTO              ON          CACHE BOOL      "Enable the cryptographic abstraction layer to use PSA Crypto APIs")

################################## Dependencies ################################
set(CRYPTO_HW_ACCELERATOR               ON          CACHE BOOL      "Whether to enable the crypto hardware accelerator on supported platforms")
set(TF_PSA_CRYPTO_BUILD_TYPE            minsizerel  CACHE STRING "Build type of TF-PSA-Crypto library")

# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE            ON)
set(TFM_MULTI_CORE_TOPOLOGY             OFF)
