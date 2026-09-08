#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(DEVICETREE_DIR                 ${CMAKE_CURRENT_LIST_DIR})
set(DT_DTS_DIR                     ${CMAKE_CURRENT_LIST_DIR}/dts)

set(DTS_SOC_DIR                    ${DT_DTS_DIR}/soc                                 CACHE STRING "Define soc device tree source path")
set(DTS_BOARDS_DIR                 ${DT_DTS_DIR}/boards                              CACHE STRING "Define board device tree source path")
set(DTS_EXT_DIR                    ""                                                CACHE STRING "Define external device tree source directory (optional)")
set(DT_BINDINGS_DIR                ${CMAKE_CURRENT_LIST_DIR}/bindings                CACHE STRING "Define bindings (yaml files) path")
set(DT_INCLUDE_DIR                 ${CMAKE_CURRENT_LIST_DIR}/include                 CACHE STRING "Define device tree include path")
set(DT_PYTHON_DEVICETREE_SRC       ${CMAKE_CURRENT_LIST_DIR}/python-devicetree/src   CACHE STRING "Define python device tree path")
