###########
Build Tests
###########

The tests is a TF-M application which verifies TF-M functionality on both SPE and NSPE sides.
Thus, tests require an extension of SPE side with test code and extra functionality
for some Non-Secure test cases. To inject that test code into SPE the
``CONFIG_TFM_TEST_DIR`` option is used. When SPE build system sees this option
it adds the corresponding folder via ``add_subdirectory(${CONFIG_TFM_TEST_DIR} tf-m-test)``
and includes it to SPE binary.
Also, test configurations should be passed to SPE build to include building Secure Tests.

To hide these complexities to developers, TF-M implements a wrapper CMake in **tf-m-tests**
repository to build the SPE for testing rather than building it from the TF-M repository.

The recommended tf-m-tests repo commit to verify TF-M can be found at
``<TF-M source dir>/lib/ext/tf-m-tests/version.txt``.
It does not support auto-downloading as builds start from it.
You need to download it manually before building any tests.

Regression Tests
================
For instructions on configuring, building and executing the regression tests
please refer to the documentation in **tf-m-tests** repository (to be added).
The regression test application is located under **/tests_reg** folder.
It is recommended to build both SPE and NSPE from that folder.

The basic commands for building the regression tests will be:

.. code-block:: bash

    cd </tf-m-tests/tests_reg>
    cmake -S spe -B build_spe -DTFM_PLATFORM=arm/mps2/an521 -DCONFIG_TFM_SOURCE_PATH=<TF-M source dir>
          -DTEST_S=ON -DTEST_NS=ON
    cmake --build build_spe -- install

    cmake -S . -B build_test -DCONFIG_SPE_PATH=<Absolute path to>/build_spe/api_ns
    cmake --build build_test

Instead of enable all the supported Secure (``TEST_S``) and NS (``TEST_NS`` tests, you can also
enable individual test suites by using ``-DTEST_S_<SUITE>=ON`` or ``-DTEST_NS_<SUITE>=ON``.
For the available test suites, refer to the ``default_s_test_config.cmake`` and
``default_ns_test_config.cmake`` files in tf-m-tests repo.

PSA API tests
=============
PSA API tests from https://github.com/ARM-software/psa-arch-tests use the same
mechanism for SPE extension as the regression tests above utilising ``CONFIG_TFM_TEST_DIR`` option.
PSA API tests are selected by the TEST_PSA_API variable. Enabling both regression tests and
PSA API tests simultaneously is **not** supported.

TF-M implements a wrapper CMake for PSA API tests as well.
The PSA API test codes are located under **/tests_psa_arch** folder.

Here is a brief description of the basic flow:
There are 5 different TEST_PSA_API test suites to be run.

.. code-block:: bash

    -DTEST_PSA_API=INTERNAL_TRUSTED_STORAGE
    -DTEST_PSA_API=PROTECTED_STORAGE
    -DTEST_PSA_API=STORAGE
    -DTEST_PSA_API=CRYPTO
    -DTEST_PSA_API=INITIAL_ATTESTATION

Respectively for the corresponding service. For example, to enable the PSA API
tests for the Crypto service:

.. code-block:: bash

    cd </tf-m-tests/tests_psa_arch folder>
    cmake -S spe -B build_spe -DTFM_PLATFORM=arm/mps2/an521 -DCONFIG_TFM_SOURCE_PATH=<TF-M source dir>
          -DTEST_PSA_API=CRYPTO
    cmake --build build_spe -- install

    cmake -S . -B build_test -DCONFIG_SPE_PATH=<Absolute path to>/build_spe/api_ns
    cmake --build build_test

--------------

*Copyright (c) 2017-2023, Arm Limited. All rights reserved.*
*Copyright (c) 2022, Cypress Semiconductor Corporation. All rights reserved.*