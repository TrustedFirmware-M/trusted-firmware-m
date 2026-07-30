#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(cmake/version.cmake)

set(CMAKE_PROJECT_VERSION ${TFM_VERSION_MANUAL})
set(DOXYCFG_OUTPUT_PATH reference_manual)

configure_file(docs/doxygen/Doxyfile.in Doxyfile @ONLY)
