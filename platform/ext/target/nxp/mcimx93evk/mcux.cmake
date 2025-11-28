# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.tfm.s.board)
    mcux_add_source(
        SOURCES
        ./mcimx93evk/target_cfg.c
        ./mcimx93evk/drivers/trdc/imx_trdc.c
        ./mcimx93evk/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
endif()
if (CONFIG_MCUX_COMPONENT_middleware.tfm.ns.board)
    mcux_add_source(
        SOURCES
        ./mcimx93evk/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.tfm.board_headers)
    mcux_add_macro(
        CC "-DTARGET_CONFIG_HEADER_FILE=\\\"config_tfm_target.h\\\"\
        "
    )
    mcux_add_source(
        SOURCES
        ./common/target_cfg_common.h
        ./mcimx93evk/config_tfm_target.h
        ./mcimx93evk/target_cfg.h
        ./mcimx93evk/trdc_config.h
        ./mcimx93evk/tfm_peripherals_def.h
        ./mcimx93evk/drivers/trdc/imx_trdc.h
        ./mcimx93evk/Device/Include/platform_base_address.h
        ./mcimx93evk/partition/flash_layout.h
        ./mcimx93evk/partition/region_defs.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
    mcux_add_include(
        INCLUDES
		./common/
		./mcimx93evk/
		./mcimx93evk/drivers/trdc
        ./mcimx93evk/partition/
		./mcimx93evk/Device/Include/
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.tfm.ocram_flash_layout)
    mcux_add_source(
        SOURCES
        ./mcimx93evk/partition/generated/ocram/flash_layout.h
        ./mcimx93evk/partition/generated/ocram/region_defs.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
    mcux_add_include(
        INCLUDES
        ./mcimx93evk/partition/generated/ocram
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.tfm.tcm_flash_layout)
    mcux_add_source(
        SOURCES
        ./mcimx93evk/partition/generated/tcm/flash_layout.h
        ./mcimx93evk/partition/generated/tcm/region_defs.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
    mcux_add_include(
        INCLUDES
        ./mcimx93evk/partition/generated/tcm
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
		BOARDS mcimx93evk
    )
endif()
