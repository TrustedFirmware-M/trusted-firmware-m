#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2023, Nuvoton Technology Corp. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(MCUBOOT_IMAGE_NUMBER    2           CACHE STRING    "Whether to combine S and NS into either 1 image, or sign each separately")
set(BL2_TRAILER_SIZE        0x800       CACHE STRING    "Trailer size")
set(MCUBOOT_USE_PSA_CRYPTO  ON          CACHE BOOL      "Enable the cryptographic abstraction layer to use PSA Crypto APIs")
set(MCUBOOT_SIGNATURE_TYPE  "EC-P256"   CACHE STRING    "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]")


# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE          ON )
set(TFM_MULTI_CORE_TOPOLOGY           OFF)
set(NV_ENABLE_ETM                     OFF)
