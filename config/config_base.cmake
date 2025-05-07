#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

####################################################################################################
# These configurations below are not included in Kconfig configuration system.

set(TFM_TOOLCHAIN_FILE                  ${CMAKE_SOURCE_DIR}/toolchain_GNUARM.cmake CACHE FILEPATH    "Path to TFM compiler toolchain file")
set(TFM_PLATFORM                        ""          CACHE STRING    "Platform to build TF-M for. Must be either a relative path from [TF-M]/platform/ext/target, or an absolute path.")
set(CROSS_COMPILE                       arm-none-eabi CACHE STRING  "Cross-compilation triplet")

set(CMAKE_INSTALL_PREFIX                ${CMAKE_BINARY_DIR}/api_ns CACHE PATH "Install prefix")

set(INTERFACE_INC_DIR                   ${CMAKE_SOURCE_DIR}/interface/include)
set(INTERFACE_SRC_DIR                   ${CMAKE_SOURCE_DIR}/interface/src)

set(INSTALL_INTERFACE_INC_DIR           ${CMAKE_INSTALL_PREFIX}/interface/include)
set(INSTALL_INTERFACE_SRC_DIR           ${CMAKE_INSTALL_PREFIX}/interface/src)
set(INSTALL_INTERFACE_LIB_DIR           ${CMAKE_INSTALL_PREFIX}/interface/lib)
set(INSTALL_IMAGE_SIGNING_DIR           ${CMAKE_INSTALL_PREFIX}/image_signing)
set(INSTALL_CMAKE_DIR                   ${CMAKE_INSTALL_PREFIX}/cmake)
set(INSTALL_CONFIG_DIR                  ${CMAKE_INSTALL_PREFIX}/config)
set(INSTALL_PLATFORM_NS_DIR             ${CMAKE_INSTALL_PREFIX}/platform)

set(TFM_DEBUG_SYMBOLS                   ON          CACHE BOOL      "Add debug symbols. Note that setting CMAKE_BUILD_TYPE to Debug or RelWithDebInfo will also add debug symbols.")
set(TFM_DEBUG_OPTIMISATION              OFF         CACHE BOOL      "Add basic -Og optimisation when CMAKE_BUILD_TYPE is Debug. Note that non Debug builds specify their own optimisation")
set(TFM_CODE_COVERAGE                   OFF         CACHE BOOL      "Whether to build the binary for lcov tools")

set(TFM_TESTS_REVISION_CHECKS           ON          CACHE BOOL      "Whether to perform checks on the tf-m-tests repository revision.")

set(PROJECT_CONFIG_HEADER_FILE          ""          CACHE FILEPATH  "User defined header file for TF-M config")

# External libraries source and version
set(MBEDCRYPTO_PATH                     "DOWNLOAD"  CACHE PATH      "Path to Mbed Crypto (or DOWNLOAD to fetch automatically")
set(MBEDCRYPTO_FORCE_PATCH              OFF         CACHE BOOL      "Always apply MBed Crypto patches")
set(MBEDCRYPTO_VERSION                  "mbedtls-3.6.3" CACHE STRING "The version of Mbed Crypto to use")
set(MBEDCRYPTO_GIT_REMOTE               "https://github.com/Mbed-TLS/mbedtls.git" CACHE STRING "The URL (or path) to retrieve MbedTLS from.")

set(MCUBOOT_PATH                        "DOWNLOAD"  CACHE PATH      "Path to MCUboot (or DOWNLOAD to fetch automatically")
set(MCUBOOT_VERSION                     "v2.2.0-rc1" CACHE STRING   "The version of MCUboot to use")

set(TFM_EXTRAS_REPO_PATH                "DOWNLOAD"  CACHE PATH      "Path to tf-m-extras repo (or DOWNLOAD to fetch automatically")
set(TFM_EXTRAS_REPO_VERSION             "8679c4c"   CACHE STRING    "The version of tf-m-extras to use")

set(PLATFORM_PSA_ADAC_SECURE_DEBUG      FALSE       CACHE BOOL      "Whether to use psa-adac secure debug.")
set(PLATFORM_PSA_ADAC_SOURCE_PATH       "DOWNLOAD"  CACHE PATH      "Path to source dir of psa-adac.")
set(PLATFORM_PSA_ADAC_VERSION           "819a254"   CACHE STRING    "The version of psa-adac to use.")
set(PLATFORM_RAM_FS                     OFF         CACHE BOOL      "Enables the use of RAM instead of the persistent storage device to store the FS in Secure Storage services")

set(PLATFORM_IS_FVP                     FALSE       CACHE BOOL      "Whether to enable FVP or FPGA build of the platform.")

set(CODE_SHARING_OUTPUT_FILE_SUFFIX     "_shared_symbols.axf" CACHE STRING "Suffix to use for code-sharing output files")
set(CODE_SHARING_INPUT_FILE_SUFFIX      "_shared_symbols.axf" CACHE STRING "Suffix to use for code-sharing input files")

set(CONFIG_TFM_WARNINGS_ARE_ERRORS      OFF         CACHE BOOL      "Whether to treat warnings as errors")

####################################################################################################
# These configurations below are also referred by Kconfig configuration system,
# together with TF-M Header File Config System options.

set(BL1                                 OFF         CACHE BOOL      "Whether to build BL1")
set(BL2                                 ON          CACHE BOOL      "Whether to build BL2")
set(NS_EVALUATION_APP_PATH              ""          CACHE PATH      "Path to TFM NS Evaluation Application")

set(TFM_ISOLATION_LEVEL                 1           CACHE STRING    "Isolation level")
set(PSA_FRAMEWORK_HAS_MM_IOVEC          OFF         CACHE BOOL      "Enable MM-IOVEC")
set(TFM_PROFILE                         ""          CACHE STRING    "Profile to use")
set(TFM_FIH_PROFILE                     OFF         CACHE STRING    "Fault injection hardening profile [OFF, LOW, MEDIUM, HIGH]")
set(CONFIG_TFM_SPM_BACKEND              "SFN"       CACHE STRING    "The SPM backend [IPC, SFN]")

# An NSPE client_id is provided by the NSPE OS via the SPM or directly by the SPM.
# When `TFM_NS_MANAGE_NSID` is `ON`, TF-M supports NSPE OS providing NSPE client_id.
set(TFM_NS_MANAGE_NSID                  OFF         CACHE BOOL      "Support NSPE OS providing NSPE client_id")

set(TFM_EXTRA_CONFIG_PATH               ""          CACHE PATH      "Path to extra cmake config file")

set(TFM_MANIFEST_LIST                   ${CMAKE_SOURCE_DIR}/tools/tfm_manifest_list.yaml CACHE FILEPATH "TF-M native Secure Partition manifests list file")

set(TFM_CODE_SHARING                    OFF         CACHE PATH      "Enable code sharing between MCUboot and secure firmware")
set(CONFIG_TFM_BOOT_STORE_MEASUREMENTS  ON          CACHE BOOL      "Store measurement values from all the boot stages. Used for initial attestation token.")
set(CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS  ON  CACHE BOOL      "Enable storing of encoded measurements in boot.")

set(TFM_PXN_ENABLE                      OFF         CACHE BOOL      "Use Privileged execute never (PXN)")

set(TFM_EXCEPTION_INFO_DUMP             OFF         CACHE BOOL      "On fatal errors in the secure firmware, capture info about the exception. Print the info if the SPM log level is sufficient.")
set(TFM_LOG_FATAL_ERRORS                OFF         CACHE BOOL      "Log fatal errors when they occur to aid debugging")
set(TFM_LOG_NONFATAL_ERRORS             OFF         CACHE BOOL      "Log non-fatal errors when they occur to aid debugging")
set(TFM_HALT_ON_FATAL_ERRORS            OFF         CACHE BOOL      "On fatal errors in the secure firmware, halt immediately to allow debugging")
set(TFM_LOG_ERR_FILE_AND_LINE           OFF         CACHE BOOL      "Log file name and line numbers of fatal and non-fatal errors")

set(CONFIG_TFM_HALT_ON_CORE_PANIC       OFF         CACHE BOOL       "On fatal errors in the secure firmware, halt instead of rebooting.")
set(CONFIG_TFM_BACKTRACE_ON_CORE_PANIC  OFF         CACHE BOOL       "On fatal errors in secure firmware, log backtrace and then halt")

set(CONFIG_TFM_STACK_WATERMARKS         OFF         CACHE BOOL      "Whether to pre-fill partition stacks with a set value to help determine stack usage")

set(CONFIG_TFM_BRANCH_PROTECTION_FEAT   BRANCH_PROTECTION_DISABLED   CACHE STRING    "Set default branch protection usage to disabled")

############################ Platform ##########################################

set(NUM_MAILBOX_QUEUE_SLOT              1           CACHE BOOL      "Number of mailbox queue slots")
set(TFM_PLAT_SPECIFIC_MULTI_CORE_COMM   OFF         CACHE BOOL      "Whether to use a platform specific inter-core communication instead of mailbox in dual-cpu topology")

set(DEBUG_AUTHENTICATION                CHIP_DEFAULT CACHE STRING   "Debug authentication setting. [CHIP_DEFAULT, NONE, NS_ONLY, FULL")
set(SECURE_UART1                        OFF         CACHE BOOL      "Enable secure UART1")

set(CRYPTO_HW_ACCELERATOR               OFF         CACHE BOOL      "Whether to enable the crypto hardware accelerator on supported platforms")

set(OTP_NV_COUNTERS_RAM_EMULATION       OFF         CACHE BOOL      "Enable OTP/NV_COUNTERS emulation in RAM. Has no effect on non-default implementations of the OTP and NV_COUNTERS")
set(TFM_NS_NV_COUNTER_AMOUNT            0           CACHE STRING    "How many NS NV counters are enabled")

set(PLATFORM_ERROR_CODES                OFF         CACHE BOOL      "Whether to use platform-specific error codes.")

set(PLATFORM_DEFAULT_BL1                ON          CACHE STRING    "Whether to use default BL1 or platform-specific one")
set(PLATFORM_DEFAULT_ATTEST_HAL         ON          CACHE BOOL      "Use default attest hal implementation.")
set(PLATFORM_DEFAULT_ITS_HAL            ON          CACHE BOOL      "Use default ITS HAL implementation.")
set(PLATFORM_DEFAULT_PS_HAL             ON          CACHE BOOL      "Use default Protected Storage HAL implementation.")
set(PLATFORM_DEFAULT_NV_COUNTERS        ON          CACHE BOOL      "Use default nv counter implementation.")
set(PLATFORM_DEFAULT_CRYPTO_KEYS        ON          CACHE BOOL      "Use default crypto keys implementation.")
set(PLATFORM_DEFAULT_ROTPK              ON          CACHE BOOL      "Use default root of trust public key.")
set(PLATFORM_DEFAULT_IAK                ON          CACHE BOOL      "Use default initial attestation_key.")
set(PLATFORM_DEFAULT_UART_STDOUT        ON          CACHE BOOL      "Use default uart stdout implementation.")
set(PLATFORM_DEFAULT_NV_SEED            ON          CACHE BOOL      "Use default NV seed implementation.")
set(PLATFORM_DEFAULT_SHARED_MEASUREMENT_DATA ON     CACHE BOOL      "Use default shared measurement data location")
set(PLATFORM_DEFAULT_OTP                ON          CACHE BOOL      "Use trusted on-chip flash to implement OTP memory")
set(PLATFORM_DEFAULT_OTP_WRITEABLE      ON          CACHE BOOL      "Use OTP memory with write support")
set(PLATFORM_DEFAULT_PROVISIONING       ON          CACHE BOOL      "Use default provisioning implementation")
set(PLATFORM_DEFAULT_SYSTEM_RESET_HALT  ON          CACHE BOOL      "Use default system reset/halt implementation")
set(PLATFORM_DEFAULT_IMAGE_SIGNING      ON          CACHE BOOL      "Use default image signing implementation")
set(PLATFORM_DEFAULT_PROV_LINKER_SCRIPT ON          CACHE BOOL      "Use default provisioning linker script")

set(TFM_DUMMY_PROVISIONING              ON          CACHE BOOL      "Provision with dummy values. NOT to be used in production")

set(BL2_HEADER_SIZE                     0x000       CACHE STRING    "BL2 Header size")
set(BL2_TRAILER_SIZE                    0x000       CACHE STRING    "BL2 Trailer size")

############################ Partitions ########################################
set(TFM_PARTITION_PROTECTED_STORAGE     OFF         CACHE BOOL      "Enable Protected Storage partition")
set(PS_ENCRYPTION                       ON          CACHE BOOL      "Enable encryption for Protected Storage partition")
set(PS_ROLLBACK_PROTECTION              ON          CACHE BOOL      "Enable rollback protection for Protected Storage partition")
set(PS_SUPPORT_FORMAT_TRANSITION        OFF         CACHE BOOL      "Enable reading the older format of Protected Storage data")
set(PS_CRYPTO_AEAD_ALG                  PSA_ALG_GCM CACHE STRING    "The AEAD algorithm to use for authenticated encryption in Protected Storage")
set(PS_AES_KEY_USAGE_LIMIT              0           CACHE STRING    "Number of blocks to use a key for before changing it. 0 for no limit")

set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE OFF      CACHE BOOL      "Enable Internal Trusted Storage partition")
set(ITS_ENCRYPTION                   OFF         CACHE BOOL      "Enable authenticated encryption of ITS files using platform specific APIs")

set(TFM_PARTITION_CRYPTO                OFF         CACHE BOOL      "Enable Crypto partition")
set(CRYPTO_TFM_BUILTIN_KEYS_DRIVER      ON          CACHE BOOL      "Whether to allow crypto service to store builtin keys. Without this, ALL builtin keys must be stored in a platform-specific location")

set(TFM_PARTITION_INITIAL_ATTESTATION   OFF         CACHE BOOL      "Enable Initial Attestation partition")
set(SYMMETRIC_INITIAL_ATTESTATION       OFF         CACHE BOOL      "Use symmetric crypto for inital attestation")
set(ATTEST_KEY_BITS                     256         CACHE STRING    "The size of the initial attestation key in bits")
set(PSA_INITIAL_ATTEST_MAX_TOKEN_SIZE   0x250       CACHE STRING    "The maximum possible size of a token")

set(TFM_PARTITION_PLATFORM              OFF         CACHE BOOL      "Enable Platform partition")

############################ Mbedcrypto configurations #########################

set(MBEDCRYPTO_BUILD_TYPE               "${CMAKE_BUILD_TYPE}" CACHE STRING "Build type of Mbed Crypto library")
set(TFM_MBEDCRYPTO_CONFIG_PATH
  "${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/tfm_mbedcrypto_config_default.h" CACHE PATH
  "Config to use for Mbed Crypto. For increased flexibility when pointing to a file, set the type \
of this setting to 'STRING' by passing the :<type> portion when specifying the setting value in \
the command line. E.g. '-DTFM_MBEDCRYPTO_CONFIG_PATH:STRING=some_file_which_is_generated.h' \
This can be useful if the config file is generated and placed inside a directory already added \
to the include path of Mbed TLS.")
set(TFM_MBEDCRYPTO_CONFIG_CLIENT_PATH         "${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/tfm_mbedcrypto_config_client.h" CACHE PATH "Bare minimum config required on the client side.")
set(TFM_MBEDCRYPTO_PSA_CRYPTO_CONFIG_PATH     "${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/crypto_config_default.h" CACHE PATH "Config to use PSA Crypto setting for Mbed Crypto.")
set(TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH ""    CACHE PATH      "Config to append to standard Mbed Crypto config, used by platforms to configure feature support")

########################## TF-M performance ####################################

set(CONFIG_TFM_ENABLE_PROFILING OFF CACHE BOOL "Enable profiling for TF-M")

########################## MCUBoot signing #####################################

if (CONFIG_TFM_BOOT_STORE_MEASUREMENTS AND CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS)
    set(MCUBOOT_MEASURED_BOOT ON)
else()
    set(MCUBOOT_MEASURED_BOOT OFF)
endif()

########################## TF-M Runtime Sanitization ###########################

set(BL1_1_SANITIZE                      OFF         CACHE STRING    "Enable a runtime sanitizer for BL1_1")
set(BL1_2_SANITIZE                      OFF         CACHE STRING    "Enable a runtime sanitizer for BL1_2")
set(BL2_SANITIZE                        OFF         CACHE STRING    "Enable a runtime sanitizer for BL2")
set(TFM_SANITIZE                        OFF         CACHE STRING    "Enable a runtime sanitizer for the TF-M runtime")

################################################################################

# Specifying the accepted values for certain configuration options to facilitate
# their later validation.

########################## FIH #################################################

set_property(CACHE TFM_FIH_PROFILE PROPERTY STRINGS "OFF;LOW;MEDIUM;HIGH")

########################## TF-M Runtime Sanitization ###########################

set(SANITIZE_OPTIONS "undefined;shift;shift-exponent;shift-base; integer-divide-by-zero;unreachable;vla-bound; null;return;signed-integer-overflow;bounds; bounds-strict;alignment;object-size; float-divide-by-zero;float-cast-overflow; nonnull-attribute;returns-nonnull-attribute; bool;enum;vptr;pointer-overflow;builtin")

set_property(CACHE BL1_1_SANITIZE PROPERTY STRINGS ${SANITIZE_OPTIONS})
set_property(CACHE BL1_2_SANITIZE PROPERTY STRINGS ${SANITIZE_OPTIONS})
set_property(CACHE BL2_SANITIZE   PROPERTY STRINGS ${SANITIZE_OPTIONS})
set_property(CACHE TFM_SANITIZE   PROPERTY STRINGS ${SANITIZE_OPTIONS})
