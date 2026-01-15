#
# Copyright (c) 2023, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# cpuarch.cmake is used to set things that related to the platform that are both
# immutable and global, which is to say they should apply to any kind of project
# that uses this platform. In practice this is normally compiler definitions and
# variables related to hardware.

# Set architecture and CPU
set(TFM_SYSTEM_PROCESSOR cortex-m33)
set(TFM_SYSTEM_ARCHITECTURE armv8-m.main)
set(CONFIG_TFM_FP_ARCH "fpv5-sp-d16")

add_compile_definitions(
  NRF54LV10A_XXAA
  NRF54L_SERIES
  NRF_APPLICATION
  # SKIP configuring the SAU from the MDK as it does not fit TF-M's needs
  NRF_SKIP_SAU_CONFIGURATION
  NRF_SKIP_FICR_NS_COPY_TO_RAM
)
