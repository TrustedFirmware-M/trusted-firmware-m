#-------------------------------------------------------------------------------
# Portions Copyright (C) 2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if(BL1)
    set(FETCHCONTENT_QUIET TRUE)
    set(TESA_TOOLKIT_PATH     "DOWNLOAD"   CACHE PATH      "Path to TESA-Toolkit (or DOWNLOAD to fetch automatically")
    set(TESA_TOOLKIT_VERSION  "v1.0.0"    CACHE STRING    "The version of TESA-Toolkit to use")

    # Fetch TESA-Toolkit repository to sign image and provision device
    fetch_remote_library(
        LIB_NAME                tesa-toolkit
        LIB_SOURCE_PATH_VAR     TESA_TOOLKIT_PATH
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      https://github.com/analogdevicesinc/tesa-toolkit
            GIT_TAG             ${TESA_TOOLKIT_VERSION}
            GIT_PROGRESS        TRUE
    )

    # Set TFM_BL2_SIGNING_KEY_PATH as test key if it is not set
    if(NOT TFM_BL2_SIGNING_KEY_PATH)
        set(TFM_BL2_SIGNING_KEY_PATH  "${TESA_TOOLKIT_PATH}/devices/max32657/keys/bl1_dummy.pem")
    endif()

    #
    # If MAX32657 SecureBoot has been enabled MCUBoot need to be signed
    # to it be validated and executed by BootROM.
    #
    add_custom_target(bl2_signed.bin
        ALL
        DEPENDS $<TARGET_FILE_DIR:bl2>/bl2.bin
        DEPENDS ${TESA_TOOLKIT_PATH}/devices/max32657/scripts/sign/sign_app.py
        COMMAND echo "----------------"
        COMMAND ${Python3_EXECUTABLE} ${TESA_TOOLKIT_PATH}/devices/max32657/scripts/sign/sign_app.py
                        --input_file $<TARGET_FILE_DIR:bl2>/bl2.bin
                        --img_output_file $<TARGET_FILE_DIR:bl2>/bl2_signed.bin
                        --sign_key_file ${TFM_BL2_SIGNING_KEY_PATH}
        COMMAND echo "----------------"
        COMMAND echo "Converting bl2_signed.bin to bl2_signed.hex..."
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../tools/modules/bin2hex.py
        --offset=0x11000000
        $<TARGET_FILE_DIR:bl2>/bl2_signed.bin
        $<TARGET_FILE_DIR:bl2>/bl2_signed.hex
        COMMAND echo "Bin2Hex conversion done."
        COMMAND echo "----------------"
    )
endif()
