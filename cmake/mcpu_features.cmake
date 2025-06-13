#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Check if the MCPU supports security extension (CMSE)
set(CMSE_SUPPORTED_MCUS "cortex-m23" "cortex-m33" "cortex-m35p" "cortex-m55" "cortex-m52" "cortex-m85")
list(FIND CMSE_SUPPORTED_MCUS ${TFM_SYSTEM_PROCESSOR} ITEM_INDEX)
if(NOT ITEM_INDEX EQUAL -1)
    set(COMPILER_CMSE_FLAG -mcmse -mfix-cmse-cve-2021-35465)
endif()

# ===================== Set toolchain CPU and Arch =============================
set(TFM_SYSTEM_PROCESSOR_FEATURED ${TFM_SYSTEM_PROCESSOR})

set(FEATURE_SUPPORTED_MCUS "cortex-m33" "cortex-m35p" "cortex-m55" "cortex-m52" "cortex-m85")
list(FIND FEATURE_SUPPORTED_MCUS ${TFM_SYSTEM_PROCESSOR} ITEM_INDEX)
if(NOT ITEM_INDEX EQUAL -1)
    # Hardware DSP is currently not supported in TF-M
    string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nodsp")

    if(NOT CONFIG_TFM_ENABLE_FP)
        string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nofp")
    endif()

    if(TFM_SYSTEM_ARCHITECTURE STREQUAL "armv8.1-m.main")
        # For GNU Arm Embedded Toolchain doesn't emit __ARM_ARCH_8_1M_MAIN__, adding this macro manually.
        add_compile_definitions(__ARM_ARCH_8_1M_MAIN__=1)

        if(NOT CONFIG_TFM_ENABLE_MVE)
            string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nomve")
        endif()

        if(NOT CONFIG_TFM_ENABLE_MVE_FP)
            string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nomve.fp")
        endif()
    endif()
else()
    set(NOFP_SUPPORTED_MCUS "cortex-m7" "cortex-m4")
    list(FIND NOFP_SUPPORTED_MCUS ${TFM_SYSTEM_PROCESSOR} ITEM_INDEX)
    if(NOT ITEM_INDEX EQUAL -1)
        if(NOT CONFIG_TFM_ENABLE_FP)
            string(APPEND TFM_SYSTEM_PROCESSOR_FEATURED "+nofp")
        endif()
    endif()
endif()
add_compile_options(-mcpu=${TFM_SYSTEM_PROCESSOR_FEATURED})
