#############
Corstone-1000
#############

************
Introduction
************

The ARM's Corstone-1000 platform is a reference implementation of PSA FF-M
architecture where NSPE and SPE environments are partitioned/isolated into
Cortex-A35 and Cortex-M0+ respectively.

Cortex-M0+ acting as Secure Enclave is the Root-of-trust of SoC. Its
software comprises of two boot loading stages, i.e. Bl1 and Bl2 (based on
mcuboot) and TF-M as run time software. Cortex-A35, also referred as host,
is treated as non-secure from the Secure Enclave perspective.
The Cortex-A35 is brought out of rest by Secure Enclave in aarch64 bit mode,
and boots the software ecosystem based on linux, u-boot, UEFI run time
services, TF-A, Secure Partitions and Optee.

The communication between NSPE and SPE is based on PSA IPC protocol running on
top of the RSE communication protocol. The Corstone-1000 supports only the
`Embed protocol`, and the ATU support is removed.

The secure enclave subsystem has ARM's CC-312 (Crypto Cell) hardware to
accelerate cryptographic operations. Additionally, platform supports Secure Debug
using SDC-600 as the communication interface between host debugger and platform
target. The platform has the build option to enable secure debug protocol to
unlock debug ports during boot time. The protocol is based on ARM's ADAC
(Authenticated Debug Access Control) standard.


***********
System boot
***********

- The SoC reset brings Secure Enclave (SE), that is Cortex-M0+, out of rest.
- SE executes the BL1_1 ROM code which handles the hardware initialization. On
  the first boot, it handles the provisioning and the hashes of the keys used
  for image verification are saved in the OTP memory. The BL1_2 binary is also
  saved in the OTP.
- BL1_1 loads BL1_2 from OTP, verifies and transfers the execution to it.
- BL1_2 loads, verifies and transfers the execution to BL2 which is based on
  MCUBoot.
- BL2 loads and verifies TF-M and the host's initial boot loader image.
- BL2 transfers the execution to the TF-M.
- During TF-M initialization, the host is taken out of rest.

.. note::

  In the current implementation the provisioning bundle, that is used by the BL1_1,
  is also stored in ROM.


*****
Build
*****

Platform solution
=================

The platform binaries are build using Yocto. Below is the user guide:

`Arm Corstone-1000 User Guide`_


Building TF-M
-------------

Follow the instructions in :doc:`Building instructions </building/tfm_build_instruction>`.


Build instructions for the FVP
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``-DTFM_PLATFORM=arm/corstone1000 -DPLATFORM_IS_FVP=TRUE``

Build instructions for the FPGA
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``-DTFM_PLATFORM=arm/corstone1000``

Secure Test
===========

This section can be used to test the secure enclave software independently from
the host. The below configuration builds the secure enclave binaries with regression test
frame integrated. On boot, secure enclave software stack is brought up, and
regression tests starts executing at the end of the initialization process. In the
below configuration, host software support is disabled, and meant only
to test/verify the secure enclave software.

Follow the instructions in :doc:`Building instructions </building/tests_build_instruction>`.

In the case of Corstone-1000 the build and run commands are the following.

FVP
---

- Download Corstone-1000 FVP from : `Arm Ecosystem FVPs`_
- Install FVP by running the shell script.
- Running of the binary will boot secure enclave software stack and then the enabled
  regression tests from tf-m-tests are executed. (See `Enabled tests`_)

.. code-block:: bash

    cd <tf-m-tests-root>/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=arm/corstone1000 \
        -DCONFIG_TFM_SOURCE_PATH=<tf-m-root> \
        -DTFM_TOOLCHAIN_FILE=<tf-m-root>/toolchain_GNUARM.cmake \
        -DTEST_S=ON   \
        -DCMAKE_BUILD_TYPE=Debug  \
        -DTEST_PSA_API=OFF  \
        -DTEST_S_PS=OFF  \
        -DTEST_S_ITS=OFF  \
        -DTEST_S_IPC=OFF  \
        -DPLATFORM_IS_FVP=True
    cmake --build build_spe -- install
    dd conv=notrunc bs=1 if=build_spe/bin/bl1_1.bin of=build_spe/bin/bl1.bin seek=0
    dd conv=notrunc bs=1 if=build_spe/bin/bl1_provisioning_bundle.bin of=build_spe/bin/bl1.bin seek=51200
    ./<tf-m-root>/platform/ext/target/arm/corstone1000/create-flash-image.sh build_spe/bin cs1000.bin

    <path-to-FVP-installation>/models/Linux64_GCC-9.3/FVP_Corstone-1000 \
          -C se.trustedBootROMloader.fname="build_spe/bin/bl1.bin"  \
          -C board.flashloader0.fname="none"  \
          -C board.xnvm_size=64  \
          -C se.trustedSRAM_config=6  \
          -C se.BootROM_config="3"  \
          -C board.smsc_91c111.enabled=0  \
          -C board.hostbridge.userNetworking=true \
          --data board.flash0=build_spe/bin/cs1000.bin@0x68000000  \
          -C diagnostics=4  \
          -C disable_visualisation=true  \
          -C board.se_flash_size=8192  \
          -C se.secenc_terminal.start_telnet=1  \
          -C se.cryptocell.USER_OTP_FILTERING_DISABLE=1

.. note::

   The nvm_image.bin has to be deleted in-between the FVP runs in order to start
   from a clean state.

FPGA
----

- Follow the above pointed platform user guide to setup the FPGA board.
- Use the BL1 generated from the below commands to place it inside FPGA board SD Card.
- Use the cs1000.bin created from the below commands to place it inside FPGA board SD Card.

.. code-block:: bash

    cd <tf-m-tests-root>/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=arm/corstone1000 \
        -DCONFIG_TFM_SOURCE_PATH=<tf-m-root> \
        -DTFM_TOOLCHAIN_FILE=<tf-m-root>/toolchain_GNUARM.cmake \
        -DTEST_S=ON   \
        -DCMAKE_BUILD_TYPE=Debug  \
        -DTEST_PSA_API=OFF  \
        -DTEST_S_PS=OFF  \
        -DTEST_S_ITS=OFF  \
        -DTEST_S_IPC=OFF
    cmake --build build_spe -- install
    dd conv=notrunc bs=1 if=build_spe/bin/bl1_1.bin of=build_spe/bin/bl1.bin seek=0
    dd conv=notrunc bs=1 if=build_spe/bin/bl1_provisioning_bundle.bin of=build_spe/bin/bl1.bin seek=51200
    ./<tf-m-root>/platform/ext/target/arm/corstone1000/create-flash-image.sh build_spe/bin cs1000.bin
    cp build_spe/bin/bl1.bin <path-to-FPGA-SD-CARD>/SOFTWARE/
    cp build_spe/bin/cs1000.bin <path-to-FPGA-SD-CARD>/SOFTWARE/

.. note::

   .. _Enabled tests:

   Enabled Tests: Some of the regression tests have to be disabled as adding all
   of them would exceed the available RAM size. So there is a need to select few
   tests but not all. Other test configurations can be found in the
   :doc:`Test Configuration </configuration/test_configuration>`.


*Copyright (c) 2021-2025, Arm Limited. All rights reserved.*

.. _Arm Ecosystem FVPs: https://developer.arm.com/documentation/100966/1128/Arm--Corstone-1000-FVP?lang=en
.. _Arm Corstone-1000 User Guide: https://corstone1000.docs.arm.com/en/latest/user-guide.html
