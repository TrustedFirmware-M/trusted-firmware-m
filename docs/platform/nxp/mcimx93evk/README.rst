##########
i.MX93 EVK
##########

The i.MX 93 EVK (MCIMX93EVK)  provides a platform for comprehensive evaluation of the i.MX 93
applications processors. It is composed of one cluster of 2x Cortex®-A55 cores and a single
Cortex®-M33 core.

You can find more information about the `i.MX93 EVK on the official NXP product page`_.

****************
1. Building TF-M
****************

Prepare the tf-m-tests repository inside the TF-M base folder.

.. code-block:: bash

    cd <TF-M base folder>
    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git

MCIMX93EVK will only support builds without secondary bootloader (BL2).
u-boot running on Cortex-A core acts as the bootloader responsible for authenticating and loading
TF-M on memory for Cortex-M core.

1.1 Building TF-M demo
======================
To build S and NS application image, run the following commands:

* Build with secure binary on TCM and non secure binary on OCRAM:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake \
    -S spe \
    -B build_spe -DTFM_PLATFORM=nxp/mcimx93evk \
    -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m \
    -G"Unix Makefiles" \
    -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . \
    -B build_test -G"Unix Makefiles" \
    -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

* Build with secure and non secure binary on TCM:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe \
    -B build_spe \
    -DTFM_PLATFORM=nxp/mcimx93evk \
    -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m -G"Unix Makefiles" \
    -DBL2=OFF \
    -DNS_PARTITION_ON_OCRAM=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" \
    -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

1.2 Building TF-M regression tests
==================================

To build the S and NS regression tests, run the following commands:

* Profile Medium:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe \
    -B build_spe \
    -DTFM_PLATFORM=nxp/mcimx93evk \
    -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m -G"Unix Makefiles" \
    -DTFM_PROFILE=profile_medium \
    -DTEST_S=ON \
    -DTEST_NS=ON \
    -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" \
    -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

* Profile Small:

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg
    cmake -S spe -B build_spe_small \
    -DTFM_PLATFORM=nxp/mcimx93evk \
    -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m \
    -G"Unix Makefiles" \
    -DBL2=OFF \
    -DTFM_PROFILE=profile_small \
    -DTEST_S=ON   -DTEST_NS=ON  \
    -DTEST_S_CRYPTO=ON   -DTEST_NS_CRYPTO=ON  \
    -DTEST_S_ATTESTATION=OFF  \
    -DTEST_S_STORAGE=OFF  \
    -DTEST_S_PLATFORM=OFF  \
    -DTEST_NS_ATTESTATION=OFF \
    -DTEST_NS_STORAGE=OFF -DTEST_NS_PLATFORM=OFF \
    -DTEST_S_PLATFORM=OFF \
    -DTEST_NS_SFN_BACKEND=OFF \
    -DTEST_S_SFN_BACKEND=OFF
    cmake --build build_spe_small -- install
    cmake -S . -B build_test_small -G"Unix Makefiles" \
    -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe_small/api_ns
    cmake --build build_test_small

S and NS images are compiled to be loaded to TCM and OCRAM respectively.
To compile both images for TCM, please note that the combined size of S and NS binaries can't exceed
128K if being compiled for TCM. Even if the size fits in 128K, you may beed to adjust the partition
sizes in flash_layout.h.in file based on the partition sizes. In default build, regression test
binaries don't fit in the TCM.

***********************************
2. Loading TF-M from u-boot
***********************************

#. Copy the compiled tfm binaries to the first FAT partition of the SD card and plug the SD card
   into the board.
#. Power it up and stop the u-boot execution at prompt.
#. Use U-Boot to load the TFM binaries to memory.
   The TFM secure binary should be loaded to TCM and non secure binary to OCRAM.
#. Kick the Cortx-M33 core to start from u-boot prompt.

* Boot with secure binary on TCM and non secure binary on OCRAM:

.. code-block:: console

    fatload mmc 1 0x80000000 tfm_s.bin;
    cp.b 0x80000000 0x201e0000 0x20000
    fatload mmc 1 0x80020000 tfm_ns.bin;
    cp.b 0x80020000 0x20480000 0x18000;
    dcache flush;
    bootaux 0x1ffe0000 0

* Boot with secure and non secure binary on TCM:

#. Total TCM available for code is only 128K on this platform.
#. To shift both secure and non secure binaries to TCM, the code sizes of both binaries should not
   be more than 128K.
#. To enable both partitions to be on TCM, compile with config option NS_PARTITION_ON_OCRAM turned
   off i.e -DNS_PARTITION_ON_OCRAM=OFF. By default the option is enabled in platform's config.cmake.
#. Default size chosen for Secure and Non secure partition when NS_PARTITION_ON_OCRAM is turned off
   is 96K (IMAGE_S_CODE_SIZE) and 32K(IMAGE_NS_CODE_SIZE). You can change the MACROS based on your
   usecase and binary sizes in platform/ext/target/nxp/mcimx93evk/parttion/flash_layout.in file.
   The sizes should be on 4K boundry.

.. code-block:: console

    fatload mmc 1 0x80000000 tfm_s.bin
    fatload mmc 1 0x80018000 tfm_ns.bin
    cp.b 0x80000000 0x201e0000 0x20000;
    bootaux 0x1ffe0000 0


.. _i.MX93 EVK on the official NXP product page : https://www.nxp.com/design/design-center/development-boards-and-designs/i.MX93EVK

--------------

*Copyright 2025 NXP*
*SPDX-License-Identifier: BSD-3-Clause*
