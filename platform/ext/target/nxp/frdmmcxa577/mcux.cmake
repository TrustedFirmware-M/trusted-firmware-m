# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.tfm.s.board)
    mcux_add_macro(
        CC "-DUSE_SGI_HUK\
        "
    )
    mcux_add_source(
        SOURCES
        ./common/crypto_key/sgi_based/crypto_keys.c
        ./frdmmcxa577/target_cfg.c
        ./frdmmcxa577/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxa577
    )
endif()
if (CONFIG_MCUX_COMPONENT_middleware.tfm.ns.board)
    mcux_add_source(
        SOURCES
        ./frdmmcxa577/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxa577
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
        ./frdmmcxa577/platform_psa_hw_accel.h
        ./frdmmcxa577/config_tfm_target.h
        ./frdmmcxa577/target_cfg.h
        ./frdmmcxa577/tfm_peripherals_def.h
        ./frdmmcxa577/Device/Include/platform_base_address.h
        ./frdmmcxa577/partition/region_defs.h
        ./frdmmcxa577/partition/flash_layout.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxa577
    )
    mcux_add_include(
        INCLUDES
        ./common/
        ./frdmmcxa577/
        ./frdmmcxa577/partition
        ./frdmmcxa577/Device/Include/
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxa577
    )
endif()