#-------------------------------------------------------------------------------
# Copyright (c) 2020-2021, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_custom_target(docs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Sphinx)
find_package(Doxygen 1.8.0)
find_package(LATEX COMPONENTS PDFLATEX)

################################## ENV #########################################

project("Trusted Firmware M. Documentation" LANGUAGES)

set(SPHINXCFG_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(SPHINXCFG_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(SPHINXCFG_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/user_guide)

set(DOXYCFG_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/reference_manual)
set(DOXYCFG_DOXYGEN_CFG_DIR ${CMAKE_SOURCE_DIR}/doxygen)

# Enable to request the interface to build the doxygen documentation as well
set(DOXYCFG_DOXYGEN_BUILD False)

################################## SPHINX ######################################

file(GLOB_RECURSE SPHINXCFG_DOC_FILES ${SPHINXCFG_SOURCE_PATH}/*.rst ${SPHINXCFG_SOURCE_PATH}/*.md)

add_custom_target(tfm_docs_userguide_html ALL
    COMMAND "${SPHINX_EXECUTABLE}" -W -b html -j 1 -c ${SPHINXCFG_CONFIG_PATH} ${SPHINXCFG_SOURCE_PATH} "${SPHINXCFG_OUTPUT_PATH}/html"
    WORKING_DIRECTORY ${SPHINXCFG_SOURCE_PATH}
    DEPENDS ${SPHINXCFG_DOC_FILES}
)
add_dependencies(docs tfm_docs_userguide_html)

add_custom_target(tfm_docs_userguide_pdf ALL
    COMMAND "${SPHINX_EXECUTABLE}" -W -b latex -j 1 -c ${SPHINXCFG_CONFIG_PATH} ${SPHINXCFG_SOURCE_PATH} "${SPHINXCFG_OUTPUT_PATH}/latex"
    COMMAND ${PDFLATEX_COMPILER} -output-directory "${SPHINXCFG_OUTPUT_PATH}/latex" TF-M.tex
    COMMAND ${CMAKE_COMMAND} -E copy "${SPHINXCFG_OUTPUT_PATH}/latex/TF-M.pdf" "${SPHINXCFG_OUTPUT_PATH}/tf-m_user_guide.pdf"
    WORKING_DIRECTORY ${SPHINXCFG_SOURCE_PATH}
    DEPENDS ${SPHINXCFG_DOC_FILES}
)
add_dependencies(docs tfm_docs_userguide_pdf)

################################## DOXYGEN #####################################

configure_file(${CMAKE_SOURCE_DIR}/doxygen/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
file(GLOB_RECURSE DOXYCFG_DOC_FILES ${CMAKE_SOURCE_DIR}/*.c ${CMAKE_SOURCE_DIR}/*.h)

add_custom_command(OUTPUT ${DOXYCFG_OUTPUT_PATH}/html
    OUTPUT ${DOXYCFG_OUTPUT_PATH}/latex
    OUTPUT ${DOXYCFG_OUTPUT_PATH}/latex/refman.tex
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${DOXYCFG_DOC_FILES}
)
add_custom_target(tfm_docs_refman_html ALL
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${DOXYCFG_OUTPUT_PATH}/html
)
add_dependencies(docs tfm_docs_refman_html)

add_custom_command(OUTPUT ${DOXYCFG_OUTPUT_PATH}/latex/refman.pdf
    COMMAND ${PDFLATEX_COMPILER} refman.tex
    COMMAND ${CMAKE_COMMAND} -E copy refman.pdf ${DOXYCFG_OUTPUT_PATH}/tf-m_reference_manual.pdf
    WORKING_DIRECTORY ${DOXYCFG_OUTPUT_PATH}/latex
    DEPENDS ${DOXYCFG_OUTPUT_PATH}/latex/refman.tex
    VERBATIM
)
add_custom_target(tfm_docs_refman_pdf
    DEPENDS ${DOXYCFG_OUTPUT_PATH}/latex/refman.pdf
)
add_dependencies(docs tfm_docs_refman_pdf)

