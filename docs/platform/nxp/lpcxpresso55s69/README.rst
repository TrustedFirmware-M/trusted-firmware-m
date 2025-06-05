###############
LPCXpresso55S69
###############

****************
1. Building TF-M
****************

Prepare the tf-m-tests repository inside the TF-M base folder.

.. code-block:: bash

    cd <TF-M base folder>
    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git

There are two options for the TF-M build - with or without secondary bootloader (BL2).

1.1 Building TF-M demo without BL2
==================================
To build S and NS application image without a BL2, run the following commands:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=nxp/lpcxpresso55s69 -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m -G"Unix Makefiles" -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

1.2 Building TF-M demo with BL2
===============================

To build S and NS application along with a BL2, run the following commands:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=nxp/lpcxpresso55s69 -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m -G"Unix Makefiles" -DBL2=ON
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

1.3 Building TF-M regression tests
==================================

To build the S and NS regression tests without BL2, run the following commands:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=nxp/lpcxpresso55s69 -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m -G"Unix Makefiles" -DTEST_S=ON -DTEST_NS=ON -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

***************************
2. Flashing TF-M with PyOCD
***************************

PyOCD is an open source Python package for programming and debugging Arm Cortex-M microcontrollers using multiple supported types of USB debug probes.
See: `PyOCD <https://pypi.org/project/pyocd/>`_

If you built TF-M with the BL2 secondary bootloader, use the following commands:

::

    pyocd erase --mass -t LPC55S69
    pyocd flash build_spe/bin/bl2.hex -t LPC55S69
    pyocd flash build_test/tfm_s_ns_signed.bin --base-address 0x8000 -t LPC55S69

When BL2 is disabled, flash the generated hex secure and non-secure images:

::

    pyocd erase --mass -t LPC55S69
    pyocd flash build_spe/bin/tfm_s.hex build_test/bin/tfm_ns.hex -t LPC55S69

.. Note::

    There is sometimes a stability issue with the pyocd flash erasing, it is needed to rerun the pyocd erase command again.

--------------

*Copyright (c) 2020, Linaro. All rights reserved.*
*Copyright (c) 2020-2021, Arm Limited. All rights reserved.*
*Copyright 2020-2024 NXP. All rights reserved.
*SPDX-License-Identifier: BSD-3-Clause*
