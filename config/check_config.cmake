#-------------------------------------------------------------------------------
# Copyright (c) 2021-2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set (VALID_ISOLATION_LEVELS 1 2 3)

tfm_invalid_config(NOT TFM_ISOLATION_LEVEL IN_LIST VALID_ISOLATION_LEVELS)
tfm_invalid_config(TFM_ISOLATION_LEVEL EQUAL 3 AND NOT PLATFORM_HAS_ISOLATION_L3_SUPPORT)
tfm_invalid_config(TFM_ISOLATION_LEVEL GREATER 1 AND PSA_FRAMEWORK_HAS_MM_IOVEC)

tfm_invalid_config(TFM_MULTI_CORE_TOPOLOGY AND TFM_NS_MANAGE_NSID)
tfm_invalid_config(TFM_PLAT_SPECIFIC_MULTI_CORE_COMM AND NOT TFM_MULTI_CORE_TOPOLOGY)
tfm_invalid_config(TFM_HYBRID_PLATFORM_API_BROKER AND NOT TFM_MULTI_CORE_TOPOLOGY)

tfm_invalid_config(TFM_ISOLATION_LEVEL EQUAL 3 AND CONFIG_TFM_STACK_WATERMARKS)

########################## BL1 #################################################

tfm_invalid_config(TFM_BL1_2_IN_OTP AND TFM_BL1_2_IN_FLASH)

tfm_invalid_config(TFM_DUMMY_PROVISIONING AND TFM_GENERATE_BL1_2_CM_SIGNING_KEY)
tfm_invalid_config(TFM_DUMMY_PROVISIONING AND TFM_GENERATE_BL1_2_DM_SIGNING_KEY)

########################## BL2 #################################################

get_property(MCUBOOT_STRATEGY_LIST CACHE MCUBOOT_UPGRADE_STRATEGY PROPERTY STRINGS)
tfm_invalid_config(BL2 AND (NOT MCUBOOT_UPGRADE_STRATEGY IN_LIST MCUBOOT_STRATEGY_LIST) AND NOT USE_KCONFIG_TOOL)
tfm_invalid_config(BL2 AND (NOT MCUBOOT_UPGRADE_STRATEGY STREQUAL "DIRECT_XIP" AND MCUBOOT_DIRECT_XIP_REVERT))

# Maximum number of MCUBoot images supported by TF-M NV counters and ROTPKs
tfm_invalid_config(MCUBOOT_IMAGE_NUMBER GREATER 9)

tfm_invalid_config(MCUBOOT_SIGNATURE_TYPE STREQUAL "EC-P256" AND NOT MCUBOOT_USE_PSA_CRYPTO)
tfm_invalid_config(MCUBOOT_SIGNATURE_TYPE STREQUAL "EC-P384" AND NOT MCUBOOT_USE_PSA_CRYPTO)
tfm_invalid_config(MCUBOOT_SIGNATURE_TYPE STREQUAL "RSA-2048" AND MCUBOOT_BUILTIN_KEY)
tfm_invalid_config(MCUBOOT_SIGNATURE_TYPE STREQUAL "RSA-3072" AND MCUBOOT_BUILTIN_KEY)

tfm_invalid_config((BL2 AND CONFIG_TFM_BOOT_STORE_MEASUREMENTS AND NOT CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS) AND NOT MCUBOOT_DATA_SHARING)
tfm_invalid_config((NOT (TFM_PARTITION_FIRMWARE_UPDATE OR CONFIG_TFM_BOOT_STORE_MEASUREMENTS)) AND MCUBOOT_DATA_SHARING)

get_property(MCUBOOT_ALIGN_VAL_LIST CACHE MCUBOOT_ALIGN_VAL PROPERTY STRINGS)
tfm_invalid_config(BL2 AND (NOT MCUBOOT_ALIGN_VAL IN_LIST MCUBOOT_ALIGN_VAL_LIST) AND NOT USE_KCONFIG_TOOL)

tfm_invalid_config(TFM_DUMMY_PROVISIONING AND MCUBOOT_GENERATE_SIGNING_KEYPAIR)

tfm_invalid_config(MCUBOOT_HW_KEY AND MCUBOOT_BUILTIN_KEY)

####################### Code sharing ###########################################

set(TFM_CODE_SHARING_PLATFORM_LISTS arm/mps2/an521 arm/musca_b1) # Without crypto hw acceleration
tfm_invalid_config(NOT TFM_CODE_SHARING STREQUAL "OFF" AND NOT TFM_PLATFORM IN_LIST TFM_CODE_SHARING_PLATFORM_LISTS)
tfm_invalid_config(NOT TFM_CODE_SHARING STREQUAL "OFF" AND CRYPTO_HW_ACCELERATOR)
tfm_invalid_config(NOT TFM_CODE_SHARING STREQUAL "OFF" AND NOT C_COMPILER_ID:IAR)

########################## Platform ############################################

tfm_invalid_config(OTP_NV_COUNTERS_RAM_EMULATION AND NOT (PLATFORM_DEFAULT_OTP OR PLATFORM_DEFAULT_NV_COUNTERS))
tfm_invalid_config(PLATFORM_DEFAULT_NV_COUNTERS AND  NOT PLATFORM_DEFAULT_OTP_WRITEABLE)
tfm_invalid_config(TFM_DUMMY_PROVISIONING AND (PLATFORM_DEFAULT_OTP AND NOT PLATFORM_DEFAULT_OTP_WRITEABLE))
tfm_invalid_config(TFM_NS_NV_COUNTER_AMOUNT GREATER 3)

####################### Firmware Update Partition ###############################

tfm_invalid_config(NOT PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT AND TFM_PARTITION_FIRMWARE_UPDATE)
tfm_invalid_config(TFM_PARTITION_FIRMWARE_UPDATE AND NOT TFM_PARTITION_PLATFORM)
tfm_invalid_config((MCUBOOT_UPGRADE_STRATEGY STREQUAL "DIRECT_XIP" OR MCUBOOT_UPGRADE_STRATEGY STREQUAL "RAM_LOAD") AND TFM_PARTITION_FIRMWARE_UPDATE AND TFM_FWU_BOOTLOADER_LIB STREQUAL "mcuboot")
tfm_invalid_config(TFM_PARTITION_FIRMWARE_UPDATE AND NOT MCUBOOT_DATA_SHARING)

####################### Internal Trusted Storage Partition ########################

tfm_invalid_config(ITS_ENCRYPTION AND PSA_FRAMEWORK_HAS_MM_IOVEC )

####################### Protected Storage Partition ###############################

# PS only uses the platform partition when PS_ROLLBACK_PROTECTION is ON, but
# the dependency in the manifest file means the dependency is unconditional
tfm_invalid_config(TFM_PARTITION_PROTECTED_STORAGE AND NOT TFM_PARTITION_PLATFORM)
tfm_invalid_config(PS_SUPPORT_FORMAT_TRANSITION AND NOT PS_ENCRYPTION)

########################## FIH #################################################

get_property(TFM_FIH_PROFILE_LIST CACHE TFM_FIH_PROFILE PROPERTY STRINGS)
tfm_invalid_config(NOT TFM_FIH_PROFILE IN_LIST TFM_FIH_PROFILE_LIST)

######################## TF-M Profile config check #############################

tfm_invalid_config(TFM_PROFILE STREQUAL "profile_small" AND CONFIG_TFM_SPM_BACKEND_IPC)

######################## TF-M Arch config check ################################

tfm_invalid_config(TFM_PXN_ENABLE AND NOT TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")

######################## Sanitization checks ###################################

tfm_invalid_config(BL1_1_SANITIZE AND C_COMPILER_ID:IAR)
tfm_invalid_config(BL1_2_SANITIZE AND C_COMPILER_ID:IAR)
tfm_invalid_config(BL2_SANITIZE   AND C_COMPILER_ID:IAR)
tfm_invalid_config(TFM_SANITIZE   AND C_COMPILER_ID:IAR)

get_property(BL1_1_SANITIZER_ALLOWED_VALUES CACHE BL1_1_SANITIZE PROPERTY STRINGS)
tfm_invalid_config(BL1_1_SANITIZE AND NOT BL1_1_SANITIZE IN_LIST BL1_1_SANITIZER_ALLOWED_VALUES)

get_property(BL1_2_SANITIZER_ALLOWED_VALUES CACHE BL1_2_SANITIZE PROPERTY STRINGS)
tfm_invalid_config(BL1_2_SANITIZE AND NOT BL1_2_SANITIZE IN_LIST BL1_2_SANITIZER_ALLOWED_VALUES)

get_property(BL2_SANITIZER_ALLOWED_VALUES CACHE BL2_SANITIZE PROPERTY STRINGS)
tfm_invalid_config(BL2_SANITIZE AND NOT BL2_SANITIZE IN_LIST BL2_SANITIZER_ALLOWED_VALUES)

get_property(TFM_SANITIZER_ALLOWED_VALUES CACHE TFM_SANITIZE PROPERTY STRINGS)
tfm_invalid_config(TFM_SANITIZE AND NOT TFM_SANITIZE IN_LIST TFM_SANITIZER_ALLOWED_VALUES)

###################### Compiler check for FP support ###########################

include(config/cp_check.cmake)

###################### Compiler bugs ###########################################

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    execute_process(
        COMMAND ${CMAKE_C_COMPILER} --version
        OUTPUT_VARIABLE _COMPILER_VERSION
    )

    get_filename_component(COMPILER_BASENAME ${CMAKE_C_COMPILER} NAME_WE)
    string(REGEX MATCH "${COMPILER_BASENAME}[^\n]*" GCC_VERSION_DETAILED ${_COMPILER_VERSION})

    tfm_invalid_config(GCC_VERSION_DETAILED STREQUAL "arm-none-eabi-gcc (15:13.2.rel1-2) 13.2.1 20231009")
endif()

###################### Platform-specific checks ################################

include(${TARGET_PLATFORM_PATH}/check_config.cmake OPTIONAL)
