#-------------------------------------------------------------------------------
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## Dependencies ################################
set(TFM_PLATFORM_NXP_HAL_FILE_PATH         "LOCAL"          CACHE STRING     "Path to the NXP SDK hal")

############################ Platform ##########################################
set(CONFIG_TFM_USE_TRUSTZONE            ON         CACHE BOOL      "Use TrustZone")
set(TFM_MULTI_CORE_TOPOLOGY             OFF        CACHE BOOL      "Platform has multi core")
set(PLATFORM_RAM_FS                     ON         CACHE BOOL      "Enables the use of RAM instead of the persistent storage device to store the FS in Secure Storage services")
set(OTP_NV_COUNTERS_RAM_EMULATION       ON         CACHE BOOL      "Enable OTP/NV_COUNTERS emulation in RAM. Has no effect on non-default implementations of the OTP and NV_COUNTERS")

############################ Platform features ##########################################
set(USE_TFM_LPUART_FEATURE              ON           CACHE BOOL      "LPUART enabled")
set(CONFIG_BUILD_WITH_TFM				ON)
set(NS_PARTITION_ON_OCRAM				ON			 CACHE BOOL	     "The NS binary would be built wiTH OCRAM address if this option is selected. If not selcted the NS CODE and Data are located on TCM which is limited in size. See partition folder for more details on size of partition")

################################## LOG LEVEL #############################################################
set(TFM_SPM_LOG_LEVEL             LOG_LEVEL_INFO       CACHE STRING     "Set default SPM log level as INFO level" FORCE)
set(TFM_PARTITION_LOG_LEVEL       LOG_LEVEL_INFO       CACHE STRING     "Set default Secure Partition log level as INFO level" FORCE)
