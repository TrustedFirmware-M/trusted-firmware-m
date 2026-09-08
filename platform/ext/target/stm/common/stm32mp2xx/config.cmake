#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# set devicetree config
if (EXISTS ${STM_DEVICETREE_DIR}/config.cmake)
	include(${STM_DEVICETREE_DIR}/config.cmake)
endif()

#========================= Dependencies =======================================#
set(TF_PSA_CRYPTO_BUILD_TYPE            minsizerel           CACHE STRING   "Build type of TF-PSA-Crypto library")

#========================= STM32 ==============================================#
# devicetree
set(DTS_SOC_DIR                ${DT_DTS_DIR}/soc/stm32mp2    CACHE STRING   "Define soc device tree source path" FORCE)

# stm32 flag
set(STM32_BOARD_MODEL                   "stm32mp2"	         CACHE STRING   "Define board model name")
set(STM32_M33TDCID                      ON                   CACHE BOOL     "Define M33 like Trusted Domain Compartiment ID")
set(STM32_CACHE_ENABLED                 ON                   CACHE BOOL     "Enable cache")
set(STM32_HEADER_MAJOR_VER              2                    CACHE STRING   "Define stm32 header major version: 2")
set(STM32_HEADER_MINOR_VER              2                    CACHE STRING   "Define stm32 header minor version: 0,2")

# debug
set(CONFIG_TFM_BACKTRACE_ON_CORE_PANIC  ON                   CACHE BOOL     "On fatal errors in secure firmware, log backtrace and then halt" FORCE)
set(TFM_EXCEPTION_INFO_DUMP             ON                   CACHE BOOL     "On fatal errors in the secure firmware, capture info about the exception. Print the info if the SPM log level is sufficient." FORCE)
set(TFM_BL2_LOG_LEVEL                   LOG_LEVEL_INFO       CACHE STRING   "Set mcuboot log level (OFF ERROR WARNING INFO DEBUG)" FORCE)
set(TFM_EXCEPTION_DUMP_LVL              LOG_LEVEL_INFO       CACHE STRING   "Set default exception dump log level as SPM_LOG_LEVEL_DEBUG level." FORCE)
set(TFM_PARTITION_LOG_LEVEL             LOG_LEVEL_INFO       CACHE STRING   "Set debug SP log level as Debug level" FORCE)
set(TFM_SPM_LOG_LEVEL                   LOG_LEVEL_INFO       CACHE STRING   "Set default SPM log level as INFO level" FORCE)

# platform
set(CONFIG_TFM_USE_TRUSTZONE            ON                   CACHE BOOL     "Enable use of TrustZone to transition between NSPE and SPE")
set(CONFIG_TFM_INCLUDE_STDLIBC          ON                   CACHE BOOL     "Include standard C libraries and startup code")
set(PLATFORM_DEFAULT_ATTEST_HAL         OFF                  CACHE BOOL     "Use default attest hal implementation.")
set(STM32_PROFILE_DEFINITION            "stm32mp2"           CACHE STRING   "Add custom information at platform profile definition (tag:<STM32_PROFILE_DEFINITION>:<TFM_PROFILE>:tfm")
set(PLATFORM_DEFAULT_UART_STDOUT        OFF                  CACHE BOOL     "Use default uart stdout implementation.")
set(PLATFORM_DEFAULT_CRYPTO_KEYS        OFF                  CACHE BOOL     "Use default crypto keys implementation.")
set(PLATFORM_DEFAULT_NV_COUNTERS        OFF                  CACHE BOOL     "Use default nv counter implementation.")
set(PLATFORM_DEFAULT_OTP_WRITEABLE      OFF                  CACHE BOOL     "Use on chip flash with write support")
set(PLATFORM_DEFAULT_OTP                OFF                  CACHE BOOL     "Use trusted on-chip flash to implement OTP memory")
set(PLATFORM_DEFAULT_PROVISIONING       OFF                  CACHE BOOL     "Use default provisioning implementation")
set(TFM_DUMMY_PROVISIONING              ON                   CACHE BOOL     "Provision with dummy values. NOT to be used in production")
set(STM32_OVERRIDE_OTP                  OFF                  CACHE BOOL     "Override the OTP key with dummy values if TFM_DUMMY_PROVISIONING is ON")
set(CRYPTO_HW_ACCELERATOR               ON                   CACHE BOOL     "Whether to enable the crypto hardware accelerator on supported platforms")
set(TFM_PARTITION_PLATFORM              ON                   CACHE BOOL     "Enable the TF-M Platform partition")
set(PLATFORM_DEFAULT_SYSTEM_RESET_HALT  OFF                  CACHE BOOL     "Use default system reset/halt implementation")
set(TFM_NS_INDEPENDENT_SIG              OFF                  CACHE BOOL     "Indicate if S and NS must be signed independently or not" FORCE)

if (STM32_M33TDCID)
	set(BL2                             ON                   CACHE BOOL     "Whether to build BL2" FORCE)
	set(MCUBOOT_UPGRADE_STRATEGY        "RAM_LOAD"           CACHE STRING   "Upgrade strategy when multiple boot images are loaded [OVERWRITE_ONLY, SWAP, DIRECT_XIP, RAM_LOAD]" FORCE)
	set(MCUBOOT_DIRECT_XIP_REVERT       OFF                  CACHE BOOL     "Enable the revert mechanism in direct-xip mode")
	set(MCUBOOT_RAM_LOAD_REVERT         ON                   CACHE BOOL	    "Enable the revert mechanism in ram-load mode")
	set(MCUBOOT_CONFIRM_IMAGE           ON                   CACHE BOOL     "Whether to confirm the image if REVERT is supported in MCUboot")
	set(MCUBOOT_IMAGE_NUMBER            2                    CACHE STRING   "Number of images to be handled by MCUBoot" FORCE)
	set(STM32_BOOT_DEV                  "ospi"               CACHE STRING   "Set boot device [ospi, sdmmc1, sdmmc2]")
	set(BL2_HEADER_SIZE                 0x800                CACHE STRING   "Header size to aligned vector table")
	set(STM32_DDR_PHY_FILE              "ddr4_pmu_train.bin" CACHE STRING   "Set ddr phy binary name need for your board")
	set(DDRFW_SECURITY_COUNTER_S        "1"                  CACHE STRING   "Security counter for ddr-fw.")
	set(MUCBOOT_KEY_DDRFW               ""                   CACHE FILEPATH "Path to key with which to sign ddr firwmare. if not set, MCUBOOT_KEY_NS is used")
	set(DEFAULT_MCUBOOT_FLASH_MAP       OFF                  CACHE BOOL     "Whether to use the default flash map defined by TF-M project" FORCE)
	set(MCUBOOT_SIGNATURE_TYPE          "EC-P256"            CACHE STRING   "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]" FORCE)
	set(MCUBOOT_USE_PSA_CRYPTO          ON                   CACHE BOOL     "Enable the cryptographic abstraction layer to use PSA Crypto APIs")
	set(PLATFORM_HAS_BOOTDATA           ON                   CACHE BOOL     "Use a platform bootdata section in MCUBOOT_DATA_SHARING")
	set(MCUBOOT_DATA_SHARING            ON                   CACHE BOOL     "Enable Data Sharing")
else()
	set(BL2                             OFF                  CACHE BOOL     "Whether to build BL2" FORCE)
endif()

if (TFM_PARTITION_PLATFORM)
	set(TFM_PLATFORM_WDT_API            ON                   CACHE BOOL     "Enable platform watchdog support")
endif()

# DT
if (STM32_M33TDCID)
	string(APPEND STM32_DTS_BOARD_BASENAME "-cm33tdcid")
endif()

string(APPEND STM32_DTS_BOARD_BASENAME "-${STM32_BOOT_DEV}")

set(DTS_BOARD_BL2	"${STM32_DTS_BOARD_BASENAME}-bl2.dts"    CACHE STRING   "set bl2 board devicetree file")
set(DTS_BOARD_S		"${STM32_DTS_BOARD_BASENAME}-s.dts"      CACHE STRING   "set s board devicetree file")
set(DTS_BOARD_NS	"${STM32_DTS_BOARD_BASENAME}-ns.dts"     CACHE STRING   "set ns board devicetree file")

