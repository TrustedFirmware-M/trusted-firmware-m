#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
# SPDX-License-Identifier: BSD-3-Clause
#-------------------------------------------------------------------------------
# Post-config for LP_MSPM33C321A.
#
# Registers the platform-specific linker script template that adds ALIGN(16)
# inside .TFM_SP_LOAD_LIST. This generates a platform-specific output at
# platform/ext/target/ti/LP_MSPM33C321A/gcc/tfm_isolation_s.ld (does not
# override the common linker script).
#
# Required: MSPM33C321A flash word width is 128 bits (16 bytes); all flash
# program addresses must be 16-byte aligned (dl_flashctl.h, line 931).

list(APPEND TFM_EXTRA_GENERATED_FILE_LIST_PATH
    "${CMAKE_CURRENT_LIST_DIR}/generated_file_list.yaml"
)
