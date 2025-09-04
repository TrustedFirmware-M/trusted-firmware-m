#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED TFM_UNITTESTS_PATHS)
    message(FATAL_ERROR "Please provide absolute paths to the unittests using -DTFM_UNITTESTS_PATHS=<path1;path2;...>")
endif()

if (NOT DEFINED TFM_ROOT_DIR)
    message(FATAL_ERROR "Please provide absolute paths to the TF-M root directory using -DTFM_ROOT_DIR=<path>")
endif()

list(APPEND CMAKE_MODULE_PATH ${TFM_ROOT_DIR}/cmake)
include(remote_library)

project(
    "Unit Tests"
    VERSION 1.0.0
    LANGUAGES C
)

enable_testing()
include(CTest)

find_package(Ruby)
find_program(LCOV lcov REQUIRED)
find_program(GENHTML genhtml REQUIRED)

add_subdirectory(framework/cmock)
add_subdirectory(framework/unity)
add_subdirectory(framework/cmsis)

set_target_properties(cmock PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
set_target_properties(unity PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
set_target_properties(cmsis PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")

function(generate_test UNIT_NAME UNIT_PATH)
        include(${UNIT_PATH}/utcfg.cmake)

        # Generate runner for the test
        add_custom_command(
            OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/unittests/${UNIT_NAME}/test_runner.c
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/unittests/${UNIT_NAME}
            COMMAND ${Ruby_EXECUTABLE}
                ${UNITY_PATH}/auto/generate_test_runner.rb
                ${CMAKE_CURRENT_LIST_DIR}/framework/unity/cfg.yml
                ${UNIT_TEST_SUITE}
                ${CMAKE_CURRENT_BINARY_DIR}/unittests/${UNIT_NAME}/test_runner.c
            COMMENT "Generating test runner for ${UNIT_NAME}"
        )

        # test_<unit-name> is the runner for <unit-name>
        add_executable(test_${UNIT_NAME} ${UNIT_UNDER_TEST}
            ${UNIT_TEST_SUITE}
            ${CMAKE_CURRENT_BINARY_DIR}/unittests/${UNIT_NAME}/test_runner.c
            ${UNIT_TEST_DEPS}
        )

        set_target_properties(test_${UNIT_NAME} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")

        # Enable debug syms & coverage support while compiling
        target_compile_options(test_${UNIT_NAME}
            PUBLIC
                -g3
                -fprofile-arcs
                -ftest-coverage
        )

        target_link_libraries(test_${UNIT_NAME}
            PRIVATE cmsis
            PRIVATE cmock
            PRIVATE unity
            PRIVATE gcov
            ${UNIT_TEST_LINK_LIBS}
        )

        target_include_directories(test_${UNIT_NAME}
            PUBLIC
                ${UNIT_TEST_INCLUDE_DIRS}
        )

        # UNIT_TEST must always be defined, each unit test may define more
        target_compile_definitions(test_${UNIT_NAME}
            PUBLIC
                UNIT_TEST
                ${UNIT_TEST_COMPILE_DEFS}
        )

        # For every <unit> in, we build test_<unit>
        add_test(
            NAME ${UNIT_NAME}
            COMMAND test_${UNIT_NAME}
        )

        # OPTIONAL: labels allow selective grouping of tests
        set_tests_properties(${UNIT_NAME}
            PROPERTIES
                LABELS "${UNIT_TEST__LABELS}"
        )

        # Generate mocks
        foreach(FILEPATH_TO_MOCK ${MOCK_HEADERS})
            get_filename_component(FILENAME_TO_MOCK ${FILEPATH_TO_MOCK} NAME_WE)
            set(MOCK_TARGET ${UNIT_NAME}_mock_${FILENAME_TO_MOCK})

            # Invoke CMock to generate mock_<filename>
            add_custom_command(
                OUTPUT
                    ${CMAKE_BINARY_DIR}/unittests/${UNIT_NAME}/mock_${FILENAME_TO_MOCK}.c
                COMMAND ${CMAKE_COMMAND} -E env
                    UNITY_DIR=${UNITY_PATH}
                    ${Ruby_EXECUTABLE}
                        ${CMOCK_PATH}/lib/cmock.rb
                        -o${CMAKE_CURRENT_LIST_DIR}/framework/cmock/cfg.yml
                        ${FILEPATH_TO_MOCK}
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/unittests/${UNIT_NAME}
                DEPENDS ${FILEPATH_TO_MOCK}
                COMMENT "Mocking ${FILEPATH_TO_MOCK} for ${UNIT_NAME}"
            )

            target_sources(
                test_${UNIT_NAME} PRIVATE
                ${CMAKE_BINARY_DIR}/unittests/${UNIT_NAME}/mock_${FILENAME_TO_MOCK}.c
            )

            target_include_directories(
                test_${UNIT_NAME} PRIVATE
                ${CMAKE_BINARY_DIR}/unittests/${UNIT_NAME}
            )
        endforeach()
endfunction()

# unittests target
# Depends on
#   - All tests detected
# Performs
#   - Execute all tests
#   - Generate and filter coverage info
#   - Convert report into browsable html
add_custom_target(unittests)

add_custom_command(
    TARGET unittests
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND}
        ARGS
            --output-on-failure
    COMMAND ${LCOV}
        ARGS
            --capture
            --directory ${CMAKE_CURRENT_BINARY_DIR}
            --output-file raw_test_coverage.info
            > lcov.log 2>&1
    COMMAND ${LCOV}
        ARGS
            --remove raw_test_coverage.info
            -o test_coverage.info
            '/usr/*'
            '${CMAKE_BINARY_DIR}/*'
            '*tests*'
            >> lcov.log 2>&1
    COMMAND ${GENHTML}
        ARGS
            test_coverage.info
            --output-directory ${CMAKE_BINARY_DIR}/coverage_report
            >> lcov.log 2>&1
    COMMAND ${CMAKE_COMMAND}
        ARGS
            -E echo "Coverage Report: file://${CMAKE_BINARY_DIR}/coverage_report/index.html"
)

foreach(TFM_UNITTESTS_PATH ${TFM_UNITTESTS_PATHS})
    if (NOT EXISTS ${TFM_UNITTESTS_PATH})
        message(FATAL_ERROR "Path ${TFM_UNITTESTS_PATH} does not exist.")
    endif()

    file(GLOB_RECURSE UNIT_PATHS LIST_DIRECTORIES TRUE "${TFM_UNITTESTS_PATH}/*")
    foreach(UNIT_PATH ${UNIT_PATHS})
        # Only for directories that contain a utcfg.cmake
        if(IS_DIRECTORY ${UNIT_PATH} AND EXISTS ${UNIT_PATH}/utcfg.cmake)
            get_filename_component(UNIT_NAME ${UNIT_PATH} NAME)
            message(STATUS "Found ${UNIT_NAME}")
            generate_test(${UNIT_NAME} ${UNIT_PATH})
            add_dependencies(unittests test_${UNIT_NAME})
        endif()
    endforeach()
endforeach()
