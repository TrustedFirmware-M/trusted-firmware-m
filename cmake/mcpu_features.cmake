#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(TFM_SYSTEM_PROCESSOR_FEATURED ${TFM_SYSTEM_PROCESSOR})
set(CMAKE_SYSTEM_PROCESSOR ${TFM_SYSTEM_PROCESSOR})

string(FIND ${TFM_SYSTEM_ARCHITECTURE} armv8 _v8m_arch)
if(NOT _v8m_arch EQUAL -1)

    # Adjust features for armv8-m or later
    set(COMPILER_CMSE_FLAG -mcmse -mfix-cmse-cve-2021-35465)

    if(NOT TFM_SYSTEM_DSP AND NOT TFM_SYSTEM_PROCESSOR MATCHES cortex-m23)
        string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nodsp")
    endif()

    string(FIND ${TFM_SYSTEM_ARCHITECTURE} armv8.1-m _v81m_arch)
    if(NOT _v81m_arch EQUAL -1)
        # Adjust armv8.1-m features
        # For GNU Arm Embedded Toolchain doesn't emit __ARM_ARCH_8_1M_MAIN__, adding this macro manually.
        add_compile_definitions(__ARM_ARCH_8_1M_MAIN__=1)

        if(CONFIG_TFM_ENABLE_MVE)
            if(NOT CONFIG_TFM_ENABLE_MVE_FP)
                string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nomve.fp") # disables MVE FP only, keeps MVE int
            endif()
        else()
            string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nomve")
        endif()
    else()
        # Adjust armv8-m features
        if(CONFIG_TFM_ENABLE_MVE OR CONFIG_TFM_ENABLE_MVE_FP)
            message(FATAL_ERROR "${TFM_SYSTEM_PROCESSOR} does not support MVE/MVE-FP; disable CONFIG_TFM_ENABLE_MVE and CONFIG_TFM_ENABLE_MVE_FP")
        endif()
    endif()

    # .nofp shall be the last armlink acc
    if(NOT CONFIG_TFM_ENABLE_FP AND NOT TFM_SYSTEM_PROCESSOR MATCHES cortex-m23)
        string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nofp")
    endif()
endif()
add_compile_options(-mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED})
