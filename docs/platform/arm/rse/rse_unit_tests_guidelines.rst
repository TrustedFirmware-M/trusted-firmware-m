#####################
Unit Tests Guidelines
#####################

Purpose
=======

This document defines the requirements for unit testing within RSE ROM
development process. Additionally, this document includes a user guide for writing
unit tests, which provides detailed instructions on creating, running, and
managing unit tests effectively.

Scope
=====

This policy is applicable to all developers and contributors engaged in the
development, review, and maintenance of RSE ROM.

Policy Statement
================

1. Unit Test Requirement
------------------------

- All new RSE ROM code should be accompanied by relevant unit tests.

2. Updating Unit Tests
----------------------

- When modifying existing functionality, developers must update the
  corresponding unit tests to ensure they accurately test the new behavior.
- Deprecated or obsolete unit tests must be removed or refactored to maintain
  the relevance and efficiency of the unit test suite.

Introduction
============

Documentation is available at `Unity`_ and `CMock`_ to get started with the
test and mocking frameworks.

.. note:: Test runners are compiled for the host system.

Required Tools
--------------

The following tools are required for writing and running unit tests:

- **LCOV**: A graphical front-end for GCC's coverage testing tool gcov.
   LCOV is used to generate test coverage reports.
- **genhtml**: A tool to convert LCOV output files into HTML reports for
   easy viewing of code coverage.

Terminology
-----------

- **Unit Test**: A test that verifies the functionality of a small,
   isolated piece of code.
- **Unit Under Test**: A unit under test (UUT) is the object that is
   being tested.
- **Mock**: A simulated object that mimics the behavior of real objects
   in controlled ways.
- **Assertion**: A statement that checks if a condition is true.

Building all available tests
----------------------------

.. code:: sh

       $ cmake -GNinja -S unittests -B <build-dir> \
                       -DTFM_ROOT_DIR=<tfm-root-dir> \
                       -DTFM_UNITTESTS_PATHS=<path1;path2;...>
       $ cmake --build <build-dir>

e.g. ::

        path1 = <absolute-path>/platform/ext/target/arm/rse/common/unittests
        path2 = <absolute-path-to-new-unittests>
        ...

Executing tests
---------------

Every unit covered by tests has at least one test suite with one or more
tests. A test runner is generated for every test suite that executes all
tests in the suite.

Individual test suites can be executed by directly invoking the test
runner executable.

.. code:: sh

       $ ./<build-dir>/test_dummy
       test_dummy.c:19:test_dummy_ALWAYS_OK:PASS

       -----------------------
       1 Tests 0 Failures 0 Ignored
       OK

Or using `CTest`_ for finer control (e.g. categorization using labels, match
name by regex etc)

.. code:: sh

       $ ctest --test-dir <build-dir> -R dummy
       Start 1: dummy
       1/1 Test #1: dummy ......................   Passed    0.00 sec

       100% tests passed, 0 tests failed out of 1

       Total Test time (real) =   0.01 sec

To run a single test from a specific unit

.. code:: sh

       $ ./<build-dir>/test_dummy -f ALWAYS_OK
       # Run all tests with name containing 'ALWAYS_OK'

Creating a new unit test
------------------------

The build system checks each subdirectory in TFM_UNITTESTS_PATHS for a “valid”
unit test directory. A “valid” unit test directory must contain:

1. ``utcfg.cmake``
2. One or more source/header files

Unit test configuration
-----------------------

The unit test configuration *must set* the following

1. ``UNIT_UNDER_TEST``: File implementing the unit under test.
2. ``UNIT_TEST_SUITE``: File containing tests for the UUT
3. ``UNIT_TEST_DEPS``: List of files that the UUT depend on.
4. ``UNIT_TEST_INCLUDE_DIRS``: List of directories to be included in the build.
5. ``MOCK_HEADERS``: List of headers that contain interfaces to be
   mocked.

The unit test configuration *may also set* the following
1. ``UNIT_TEST_LABELS``: List of labels for the test suite.
2. ``UNIT_TEST_COMPILE_DEFS``: Macros to build the unit test

Debugging unit tests
--------------------

For each valid unit test directory, the corresponding unit test runners
are available at the root of the ``<build-dir>``.

.. note:: All unit test runners are built with ``-g3``.

To debug a segfaulting test case in a unit, e.g. ``critical_system``

.. code:: sh

       $ gdb <build-dir>/test_critical_system
       (gdb) r
       ... <segfault> ...
       (gdb) bt
       ... <backtrace> ...


.. note:: A common reason for segfaults in test runners is an invalid memory
   access on the host system. GDB populates
   ``$_siginfo._sifields._sigfault.si_addr`` with the offending address.

Components
==========

::

     platform/ext/target/arm/rse/common/unittests
     ├── CMakeLists.txt
     ├── framework
     │   ├── cmock
     │   │   ├── <patch-files>
     │   │   ├── cfg.yml
     │   │   └── CMakeLists.txt
     │   ├── cmsis
     │   │   └── CMakeLists.txt
     │   └── unity
     │       ├── <patch-files>
     │       ├── cfg.yml
     │       └── CMakeLists.txt
     ├── <dir1>
     │   ├── <unit1-tests>
     │   │    ├── test_unit1.c
     │   │    └── utcfg.cmake
     │   └── <unit2-tests>
     │        ├── test_unit2.c
     │        └── utcfg.cmake
     └── <dir2>
         └── <unit3-tests>
              ├── test_unit3.c
              └── utcfg.cmake

-  Framework & dependencies are downloaded into the build tree directly.
-  ``cmock/cfg.yml``: CMock configuration for mocking interfaces.
-  ``unity/cfg.yml``: Unity configuration for the framework features.
-  ``include``: Mocked headers common to all unit tests.

Writing Unit Tests
------------------

As an example, a simple test is implemented for  ``tfm_plat_provisioning_is_required``
in ``platform/ext/target/arm/rse/common/provisioning/bl1_provisioning.c``

.. code:: c

   static void gpio_set(enum rse_gpio_val_t val)
   {
       volatile uint32_t *gretreg =
           &((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->gretreg;

       *gretreg &= ~0b1111;
       *gretreg |= val & 0b1111;
   }

   enum tfm_plat_err_t tfm_plat_provisioning_is_required(bool *provisioning_required)
   {
       enum lcm_error_t err;
       enum lcm_lcs_t lcs;

       if (provisioning_required == NULL) {
           return TFM_PLAT_ERR_INVALID_INPUT;
       }

       err = lcm_get_lcs(&LCM_DEV_S, &lcs);
       if (err != LCM_ERROR_NONE) {
           return err;
       }

       *provisioning_required = (lcs == LCM_LCS_CM || lcs == LCM_LCS_DM);
       if (!*provisioning_required) {
           if (lcs == LCM_LCS_RMA) {
               gpio_set(RSE_GPIO_STATE_RMA_IDLE);
           } else if (lcs == LCM_LCS_SE) {
               gpio_set(RSE_GPIO_STATE_SE_ROM_BOOT);
           }
       }

       return TFM_PLAT_ERR_SUCCESS;
   }

To have a good unit test, we need to cover all possible paths that can lead to
different outputs or function calls. Some of the possible execution paths are

1. The return value of ``lcm_get_lcs`` is not ``LCM_ERROR_NONE``
2. The return value of ``lcm_get_lcs`` is ``LCM_ERROR_NONE`` with
   provisioning required.
3. The return value of ``lcm_get_lcs`` is ``LCM_ERROR_NONE`` with
   provisioning not required amd ``lcs = LCM_LCS_RMA``.
4. The return value of ``lcm_get_lcs`` is ``LCM_ERROR_NONE with``
   provisioning not required amd ``lcs = LCM_LCS_SE``.

Each path will return a value and may set a ``gretreg`` value.

Before writing the test, we need to mock all the external interfaces used by the
UUT (``tfm_plat_provisioning_is_required``). External interfaces are all APIs
and variables out of the C file. In this case ``lcm_get_lcs`` is external
function from ``lcm_drv.c``. `CMock`_ generates a mocked version of the function
which the unit test can use to inject values into the UUT.

.. code:: c

   #include "unity.h"

   #include "platform_regs.h"
   #include "mock_lcm_drv.h"

   static struct rse_sysctrl_t mock_sysctrl;
   volatile struct rse_sysctrl_t * RSE_SYSCTRL_BASE_S = &mock_sysctrl;

   void test_bl1_provisionig_IsRequired_FalseRMA(void)
   {
       int ret;
       enum lcm_lcs_t expected_lcs = LCM_LCS_RMA;

       /* Prepare */

       /* Mocked function return 0 (LCM_ERROR_NONE) */
       lcm_get_lcs_ExpectAnyArgsAndReturn(0);

       /* Mocked function return through the argument
        * pointer the value LCM_LCS_CM
        */
       lcm_get_lcs_ReturnThruPtr_lcs(&expected_lcs);

       /* Act */
       ret = tfm_plat_provisioning_is_required();

       /* Assert */
       TEST_ASSERT_EQUAL(0, ret);
       TEST_ASSERT_EQUAL((RSE_SYSCTRL_BASE_S->gretreg & 0x000F),
                           RSE_GPIO_STATE_RMA_IDLE);
   }

The test now covers one of the possible execution paths, and we can add test
cases for the other paths in the same way.

Setting the expectations from the external interfaces is important for writing
a good test case. Please refer to the `CMock`_ documentation.

Registers and memory accesses
-----------------------------

In the example above, the UUT writes values to the ``gretreg`` register directly.
The memory address defined in the software for the target may be invalid on the host.

For the test, the UUT would need to include a dummy ``platform_base_address.h`` with

.. code:: c

   extern volatile struct rse_sysctrl_t * RSE_SYSCTRL_BASE_S;

And in the unit test file

.. code:: c

   static struct rse_sysctrl_t mock_sysctrl;
   volatile struct rse_sysctrl_t * RSE_SYSCTRL_BASE_S = &mock_sysctrl;

This will use the address of ``mock_sysctrl`` from the unit test, where test cases
can assert expectations or set initial values of the ``mock_sysctrl`` registers.

Unittest Style Guide
====================

For additions and changes in unit tests, it is preferable to follow the
guidelines outlined below:

#. The format for the test names is ``test_`` followed by the function being
   tested and a pass or fail expectation, for example:
   ``test_function_being_tested_init_success``.
#. Each test case should cover one scenario. For example, if testing one case
   for a function, have a test function for that case only.
#. Name the test functions according to the test being performed.

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*

.. _Unity: https://github.com/ThrowTheSwitch/Unity
.. _CMock: https://github.com/ThrowTheSwitch/CMock
.. _CTest: https://cmake.org/cmake/help/latest/manual/ctest.1.html
